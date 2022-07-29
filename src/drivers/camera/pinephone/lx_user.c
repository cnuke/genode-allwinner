/*
 * \brief  Post kernel userland activity
 * \author Stefan Kalkowski
 * \date   2021-07-14
 */

/*
 * Copyright (C) 2021 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul/task.h>
#include <lx_user/init.h>
#include <lx_user/io.h>

#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched/task.h>
#include <linux/fs.h>
#include <media/media-devnode.h>
#include <media/v4l2-common.h>
#include <media/v4l2-device.h>
#include <media/v4l2-ioctl.h>
#include <media/v4l2-event.h>
#include <uapi/linux/media.h>

#include "lx_user.h"
#include "gui.h"


struct lx_user_config_t lx_user_config = {
	.width  = MAX_WIDTH,
	.height = MAX_HEIGHT,
	.fps    = MAX_FPS,
	.format = 0,
	.camera = 0,
	.valid  = 0,
};

struct task_struct *capture_task;
void               *capture_task_args;


extern struct cdev *lx_emul_get_cdev(unsigned major, unsigned minor);


static struct file              *_global_v4l_subdev_file;
static struct media_v2_topology  _global_topology;


struct Buffer
{
	unsigned index;

	unsigned char *base;
	size_t         size;

	unsigned vma_flags;
	unsigned vma_pgoff;
};

enum {
	BUFFER_COUNT  = 4,
};

static struct Buffer _global_buffers[BUFFER_COUNT];


/* GPIO is 254 */
enum { MEDIA0_MAJOR = 253, };


static bool wait_for_media_cdev(void)
{
	int i;

	/* wait for 5 seconds and then bail */
	for (i = 0; i < 10; i++) {
		if (lx_emul_get_cdev(MEDIA0_MAJOR, 0))
			return false;

		msleep(500);
	}

	return true;
}


static int alloc_topology(struct media_v2_topology *topology)
{
	gfp_t const flags = GFP_KERNEL | __GFP_ZERO;
	topology->ptr_entities = (u64)
		krealloc_array((void*)topology->ptr_entities,
		               topology->num_entities,
		               sizeof(struct media_v2_entity), flags);
	if (!topology->ptr_entities)
		goto err_entities;

	topology->ptr_interfaces = (u64)
		krealloc_array((void*)topology->ptr_interfaces,
		               topology->num_interfaces,
		               sizeof(struct media_v2_interface), flags);
	if (!topology->ptr_interfaces)
		goto err_interfaces;

	topology->ptr_pads = (u64)
		krealloc_array((void*)topology->ptr_pads,
		               topology->num_pads,
		               sizeof(struct media_v2_pad), flags);
	if (!topology->ptr_pads)
		goto err_pads;

	topology->ptr_links = (u64)
		krealloc_array((void*)topology->ptr_links,
		               topology->num_links,
		               sizeof(struct media_v2_link), flags);
	if (!topology->ptr_links)
		goto err_links;

	return 0;

err_links:
	kfree((void*)topology->ptr_pads);
err_pads:
	kfree((void*)topology->ptr_interfaces);
err_interfaces:
	kfree((void*)topology->ptr_entities);
err_entities:
	return -1;
}


static int query_media_device(struct cdev              *media,
                              struct media_devnode     *mdev,
                              struct media_v2_topology *topology)
{
	struct file media_filp = {
		.private_data = mdev,
	};
	int err;

	err = media->ops->unlocked_ioctl(&media_filp, MEDIA_IOC_G_TOPOLOGY,
	                                  (unsigned long)topology);
	if (err)
		return err;

	if (alloc_topology(topology))
		return -1;

	err = media->ops->unlocked_ioctl(&media_filp, MEDIA_IOC_G_TOPOLOGY,
	                                  (unsigned long)topology);
	if (err)
		return err;

	return 0;
}


static void dump_topology(struct media_v2_topology *t) __attribute__((unused));
static void dump_topology(struct media_v2_topology *t)
{
	unsigned i;
	struct media_v2_entity *pent;
	struct media_v2_interface *pintf;
	struct media_v2_pad *ppad;
	struct media_v2_link *plin;

	printk("topology_version: %llu\n", t->topology_version);

	printk("num_entities: %u\n", t->num_entities);
	pent = (struct media_v2_entity*)t->ptr_entities;
	for (i = 0; i < t->num_entities; i++) {
		struct media_v2_entity *p = &pent[i];
		printk("[%u] id: 0x%x name: '%s' function: %u flags: 0x%x\n",
		       i, p->id, p->name, p->function, p->flags);
	}
	printk("num_interfaces: %u\n", t->num_interfaces);
	pintf = (struct media_v2_interface*)t->ptr_interfaces;
	for (i = 0; i < t->num_interfaces; i++) {
		struct media_v2_interface *p = &pintf[i];
		printk("[%u] id: 0x%x intf_type: %u flags: 0x%x\n",
		       i, p->id, p->intf_type, p->flags);
	}
	printk("num_pads: %u\n", t->num_pads);
	ppad = (struct media_v2_pad*)t->ptr_pads;
	for (i = 0; i < t->num_pads; i++) {
		struct media_v2_pad *p = &ppad[i];
		printk("[%u] id: 0x%x entity_id: 0x%x flags: 0x%x index: %u\n",
		       i, p->id, p->entity_id, p->flags, p->index);
	}
	printk("num_links: %u\n", t->num_links);
	plin = (struct media_v2_link*)t->ptr_links;
	for (i = 0; i < t->num_links; i++) {
		struct media_v2_link *p = &plin[i];
		printk("[%u] id: 0x%x source_id: 0x%x sink_id: 0x%x flags: 0x%x\n",
		       i, p->id, p->source_id, p->sink_id, p->flags);
	}
}


static int setup_link(struct cdev              *media,
                      struct media_devnode     *mdev,
                      struct media_v2_topology *topology,
                      bool                      front_camera)
{
	struct media_v2_pad *pads = (struct media_v2_pad*)topology->ptr_pads;
	struct file media_filp = {
		.private_data = mdev,
	};
	struct media_link_desc arg;
	int err;

	/* rear camera */
	memset(&arg, 0, sizeof (arg));
	arg.flags = front_camera ? 0 : MEDIA_LNK_FL_ENABLED;
	arg.source.entity = pads[1].entity_id;
	arg.source.index  = pads[1].index;
	arg.sink.entity   = pads[0].entity_id;
	arg.sink.index    = pads[0].index;
	err = media->ops->unlocked_ioctl(&media_filp, MEDIA_IOC_SETUP_LINK,
	                                  (unsigned long)&arg);
	if (err)
		return err;

	/* front camera */
	memset(&arg, 0, sizeof (arg));
	arg.flags = front_camera ? MEDIA_LNK_FL_ENABLED : 0;
	arg.source.entity = pads[2].entity_id;
	arg.source.index  = pads[2].index;
	arg.sink.entity   = pads[0].entity_id;
	arg.sink.index    = pads[0].index;
	err = media->ops->unlocked_ioctl(&media_filp, MEDIA_IOC_SETUP_LINK,
	                                  (unsigned long)&arg);
	if (err)
		return err;

	return 0;
}


static int setup_subdev_fmt(struct cdev *video,
                            struct cdev *video_subdev)
{
	struct file *filp;
	struct inode *f_inode;
	int err;

	/* only setup sub-device once */
	if (_global_v4l_subdev_file)
		return -1;

	f_inode = kzalloc(sizeof(struct inode), GFP_KERNEL);
	if (!f_inode)
		return -1;
	f_inode->i_rdev = video_subdev->dev;

	filp = kzalloc(sizeof(struct file), GFP_KERNEL);
	if (!filp)
		goto err_file;

	filp->f_inode = f_inode;

	_global_v4l_subdev_file = filp;

	err = video_subdev->ops->open(NULL, filp);
	if (err) {
		printk("Could not open sub-device: %d\n", err);
		return err;
	}

	/* set frame rate */
	{
		struct v4l2_subdev_frame_interval arg;
		memset(&arg, 0, sizeof(arg));
		arg.pad = 0;
		arg.interval.numerator   = 1;
		arg.interval.denominator = lx_user_config.fps;

		err = video_subdev->ops->unlocked_ioctl(filp, VIDIOC_SUBDEV_S_FRAME_INTERVAL,
		                                 (unsigned long)&arg);
		if (err) {
			printk("Could not set frame interval: %d\n", err);
			return err;
		}
	}

	{
		struct v4l2_subdev_format arg;
		memset(&arg, 0, sizeof(arg));
		arg.pad   = 0;
		arg.which = V4L2_SUBDEV_FORMAT_ACTIVE;
		arg.format.width  = lx_user_config.width;
		arg.format.height = lx_user_config.height;
		arg.format.code   = lx_user_config.format ? MEDIA_BUS_FMT_SBGGR8_1X8
		                                          : MEDIA_BUS_FMT_UYVY8_2X8;
		arg.format.field  = V4L2_FIELD_ANY;

		err = video->ops->unlocked_ioctl(filp, VIDIOC_SUBDEV_S_FMT,
		                                 (unsigned long)&arg);
		if (err) {
			printk("Could not set sub-device format: %d\n", err);
			return err;
		}
	}

	// second time around like MP
	{
		struct v4l2_subdev_frame_interval arg;
		memset(&arg, 0, sizeof(arg));
		arg.pad = 0;
		arg.interval.numerator   = 1;
		arg.interval.denominator = lx_user_config.fps;

		err = video_subdev->ops->unlocked_ioctl(filp, VIDIOC_SUBDEV_S_FRAME_INTERVAL,
		                                 (unsigned long)&arg);
		if (err) {
			printk("Could not set frame interval: %d\n", err);
			return err;
		}
	}

	return 0;

err_file:
	kfree(f_inode);
	return -ENOMEM;
}


static int open_video_device(struct cdev *video)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};

	int err;

	err = video->ops->open(NULL, &filp);
	return err;
}


static int query_video_device(struct cdev *video)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};

	struct v4l2_capability arg;
	int err;

	memset(&arg, 0, sizeof(arg));
	err = video->ops->unlocked_ioctl(&filp, VIDIOC_QUERYCAP,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not query video device: %d\n", err);
		return err;
	}

	return 0;
}


static int setup_video_fmt(struct cdev *video)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	struct v4l2_format arg;
	int err;

	memset(&arg, 0, sizeof(arg));
	arg.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	arg.fmt.pix.width       = lx_user_config.width;
	arg.fmt.pix.height      = lx_user_config.height;
	arg.fmt.pix.pixelformat = lx_user_config.format ? V4L2_PIX_FMT_SBGGR8
	                                                : V4L2_PIX_FMT_YUV420;
	arg.fmt.pix.field       = V4L2_FIELD_ANY;

	err = video->ops->unlocked_ioctl(&filp, VIDIOC_S_FMT,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not query video device: %d\n", err);
		return err;
	}

	return 0;
}


static int request_buffers(struct cdev *video, struct Buffer *buffers)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	struct v4l2_requestbuffers arg;
	int err;
	unsigned i;

	memset(&arg, 0, sizeof(arg));
	arg.count  = BUFFER_COUNT; // suni6-csi wants at least 3 buffers
	arg.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	arg.memory = V4L2_MEMORY_MMAP;

	err = video->ops->unlocked_ioctl(&filp, VIDIOC_REQBUFS,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not request buffers: %d\n", err);
		return err;
	}

	if (arg.count < 2 || arg.count != BUFFER_COUNT) {
		printk("Insufficient buffer memory, count: %u\n", arg.count);
		return -ENOMEM;
	}

	for (i = 0; i < arg.count; i++) {
		struct v4l2_buffer arg = {
			.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE,
			.memory = V4L2_MEMORY_MMAP,
			.index  = i,
		};
		struct vm_area_struct vma;

		err = video->ops->unlocked_ioctl(&filp, VIDIOC_QUERYBUF,
		                                 (unsigned long)&arg);
		if (err) {
			printk("Could not query buffer %u: %d\n", i, err);
			return err;
		}

		memset(&vma, 0, sizeof(vma));
		vma.vm_pgoff = arg.m.offset >> PAGE_SHIFT;
		vma.vm_flags = VM_SHARED | VM_READ;

		err = video->ops->mmap(&filp, &vma);
		if (err) {
			printk("Could not mmap buffer %u\n", i);
			return err;
		}

		buffers[i].index = i;
		buffers[i].base = (unsigned char*)vma.vm_start;
		buffers[i].size = vma.vm_end - vma.vm_start;
		buffers[i].vma_flags = vma.vm_flags;
		buffers[i].vma_pgoff = vma.vm_pgoff;
	}

	return 0;
}


static int queue_buffers(struct cdev *video, struct Buffer *buffers)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	int err;
	int i;

	for (i = 0; i < BUFFER_COUNT; i++) {
		struct v4l2_buffer arg = {
			.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE,
			.memory = V4L2_MEMORY_MMAP,
			.index  = buffers[i].index,
		};

		err = video->ops->unlocked_ioctl(&filp, VIDIOC_QBUF,
		                                 (unsigned long)&arg);
		if (err) {
			printk("Could not queue buffer %u: %d\n", i, err);
			return err;
		}
	}

	return 0;
}


static struct Buffer *get_buffer(struct cdev *video)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	struct v4l2_buffer arg;
	int err;

	memset(&arg, 0, sizeof(arg));
	arg.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	arg.memory = V4L2_MEMORY_MMAP;

	// filp.f_flags |= O_NONBLOCK;

	err = video->ops->unlocked_ioctl(&filp, VIDIOC_DQBUF,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not get buffer: %d\n", err);
		return NULL;
	}

	return &_global_buffers[arg.index];
}


static int put_buffer(struct cdev *video, struct Buffer *b)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	struct v4l2_buffer arg;
	int err;

	memset(&arg, 0, sizeof(arg));
	arg.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	arg.memory = V4L2_MEMORY_MMAP;
	arg.index  = b->index;

	// printk("%s: index: %d\n", __func__, arg.index);
	err = video->ops->unlocked_ioctl(&filp, VIDIOC_QBUF,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not put buffer: %d\n", err);
		return err;
	}

	return 0;
}


static int control_capture(struct cdev *video, bool start)
{
	struct inode f_inode = {
		.i_rdev = video->dev,
	};
	struct file filp = {
		.f_inode = &f_inode,
	};
	enum v4l2_buf_type const arg = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	int err;

	err = video->ops->unlocked_ioctl(&filp,
	                                 start ? VIDIOC_STREAMON
	                                       : VIDIOC_STREAMOFF,
	                                 (unsigned long)&arg);
	if (err) {
		printk("Could not %s capturing: %d\n", start ? "start" : "stop", err);
		return err;
	}
	return 0;
}


static int configure_capture(struct cdev *media0,
                             struct cdev *video0,
                             struct cdev *v4l_subdev_gc2145,
                             struct cdev *v4l_subdev_ov5640)
{
	bool const front_camera = lx_user_config.camera == 0;

	struct media_devnode *media0_devnode =
		container_of(media0, struct media_devnode, cdev);
	int err;

	memset(&_global_topology, 0, sizeof (_global_topology));
	err = query_media_device(media0, media0_devnode, &_global_topology);
	if (err) {
		printk("Could not query topology\n");
		return err;
	}

	err = setup_link(media0, media0_devnode, &_global_topology,
	                 front_camera);
	if (err) {
		printk("Could not enable %s camera: %d\n",
				front_camera ? "front" : "rear", err);
		return err;
	}

	/* after rear -> front switch open */
	err = open_video_device(video0);
	if (err) {
		printk("Could not open video device: %d\n", err);
		return err;
	}

	err = query_video_device(video0);
	if (err) {
		printk("Could not query video device: %d\n", err);
		return err;
	}

	err = setup_subdev_fmt(video0, front_camera ? v4l_subdev_gc2145
	                                            : v4l_subdev_ov5640);
	if (err) {
		printk("Could not set sensor format: %d\n", err);
		return err;
	}

	err = setup_video_fmt(video0);
	if (err) {
		printk("Could not set video format: %d\n", err);
		return err;
	}

	return 0;
}


static void sleep_forever(void)
{
	__set_current_state(TASK_DEAD);
	schedule();
	BUG();
}


static struct genode_gui *_global_gui;


static bool const rotate = true;


static bool create_gui(void)
{
	struct genode_gui_args const args = {
		.label  = lx_user_config.camera == 0 ? "gc2154" : "ov5640",
		.width  = rotate ? lx_user_config.height : lx_user_config.width,
		.height = rotate ? lx_user_config.width  : lx_user_config.height,
	};

	if (!_global_gui)
		_global_gui = genode_gui_create(&args);

	if (!_global_gui) {
		printk("Could not create Gui session\n");
		return false;
	}

	return true;
}


struct genode_gui_refresh_context
{
	struct Buffer const *buffer;
};


static struct genode_gui_refresh_context _global_gui_refresh_context;


#include "yuv_rgb.h"

static char convert_buffer[MAX_WIDTH*MAX_HEIGHT * 4 /*abgr*/];

static void gui_show(struct genode_gui_refresh_context *ctx,
                     unsigned char *dst, size_t size)
{
	struct Buffer *b = ctx->buffer;

	unsigned int *p = (unsigned int*)dst;
	unsigned const int width  = lx_user_config.width;
	unsigned const int height = lx_user_config.height;
	unsigned const int pixels = width * height;

	unsigned char *y = b->base;
	unsigned char *v = y +  (pixels);
	unsigned char *u = v + ((pixels)/4);
	unsigned const int y_stride  = width;
	unsigned const int uv_stride = width/2;

	lx_emul_mem_cache_invalidate((void*)b->base, b->size);

	yuv420_abgr_std(width, height,
	                y, u, v, y_stride, uv_stride,
	                (unsigned char*)convert_buffer, width * 4,
	                YCBCR_601);

	if (rotate) {
		unsigned int *d = (unsigned int*)p;
		unsigned int *s = (unsigned int*)convert_buffer;

		unsigned h, w;
		for (w = 0; w < width; w++) {
			for (h = 0; h < height; h++) {
				*(d + w * height + h) =
					*(s + (h * width) + (width - w));
			}
		}
	} else
		memcpy(p, convert_buffer, pixels * 4);
}


static void gui_display_image(struct Buffer const *b)
{
	if (!_global_gui)
		return;

	_global_gui_refresh_context.buffer = b;

	genode_gui_refresh(_global_gui, gui_show,
	                   &_global_gui_refresh_context);
}


int capture_task_function(void *p)
{
	struct cdev *media0;
	struct cdev *video0;
	struct cdev *v4l_subdev_gc2145;
	struct cdev *v4l_subdev_ov5640;

	if (wait_for_media_cdev()) {
		printk("Timeout while waiting for '/dev/media0'\n");
		BUG();
	}

	if (!lx_user_config.valid) {
		printk("Camera configuration invalid\n");
		BUG();
	}

	media0            = lx_emul_get_cdev(MEDIA0_MAJOR, 0);
	video0            = lx_emul_get_cdev(VIDEO_MAJOR,  0);
	v4l_subdev_ov5640 = lx_emul_get_cdev(VIDEO_MAJOR,  1);
	v4l_subdev_gc2145 = lx_emul_get_cdev(VIDEO_MAJOR,  2);
	if (!media0 || !video0 || !v4l_subdev_gc2145 || !v4l_subdev_ov5640) {
		printk("Timeout while waiting for '/dev/media0'\n");
		BUG();
	}

	if (!configure_capture(media0, video0,
	                       v4l_subdev_gc2145,
	                       v4l_subdev_ov5640)) {
		if (request_buffers(video0, _global_buffers)) {
			printk("Could not request buffers\n");
		}
	}

	create_gui();

	if (queue_buffers(video0,_global_buffers)) {
		printk("Could not queue buffers\n");
		BUG();
	}

	if (control_capture(video0, true))
		BUG();

	while (true) {
		while (true) {
			struct Buffer *b = get_buffer(video0);
			if (b) {
				gui_display_image(b);
				put_buffer(video0, b);
			} 
		}
	}

	if (control_capture(video0, false))
		BUG();

	sleep_forever();
	return 0;
}


void lx_user_handle_io(void) { }


void lx_user_init(void)
{
	int pid = kernel_thread(capture_task_function, capture_task_args,
	                        CLONE_FS | CLONE_FILES);
	capture_task = find_task_by_pid_ns(pid, NULL);
}
