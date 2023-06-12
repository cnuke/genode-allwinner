/*
 * \brief  Dummy definitions of Linux Kernel functions - handled manually
 * \author Norman Feske
 * \date   2021-09-24
 */

/*
 * Copyright (C) 2021 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul.h>


#include <linux/prandom.h>

DEFINE_PER_CPU(unsigned long, net_rand_noise);
EXPORT_PER_CPU_SYMBOL(net_rand_noise);


#include <linux/kernfs.h>

struct kernfs_node * kernfs_find_and_get_ns(struct kernfs_node * parent,const char * name,const void * ns)
{
	return NULL;
}


#include <linux/proc_fs.h>

struct proc_dir_entry { int dummy; };

struct proc_dir_entry * proc_create_seq_private(const char * name,umode_t mode,struct proc_dir_entry * parent,const struct seq_operations * ops,unsigned int state_size,void * data)
{
	static struct proc_dir_entry ret;
	lx_emul_trace(__func__);
	return &ret;
}


#include <linux/random.h>

void add_interrupt_randomness(int irq)
{
	lx_emul_trace(__func__);
}


#include <linux/cdev.h>

void cdev_init(struct cdev * cdev,const struct file_operations * fops)
{
	lx_emul_trace(__func__);
}


#include <linux/cdev.h>

int cdev_device_add(struct cdev * cdev,struct device * dev)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/cdev.h>

void cdev_device_del(struct cdev * cdev,struct device * dev)
{
	lx_emul_trace(__func__);
}


struct builtin_fw { unsigned dummy; };

struct builtin_fw __start_builtin_fw[] = { };
struct builtin_fw __end_builtin_fw[]   = { };


#include <linux/reboot.h>

int register_reboot_notifier(struct notifier_block * nb)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/proc_fs.h>

struct proc_dir_entry * proc_mkdir(const char * name,struct proc_dir_entry * parent)
{
	lx_emul_trace(__func__);
	return NULL;
}


#include <linux/input.h>

void input_set_abs_params(struct input_dev * dev,unsigned int axis,int min,int max,int fuzz,int flat)
{
	lx_emul_trace(__func__);
}


#include <linux/firmware.h>

void release_firmware(const struct firmware * fw)
{
	lx_emul_trace(__func__);
}


#include <linux/reset.h>

int reset_control_reset(struct reset_control * rstc)
{
	printk("reset_control_reset called, ignored\n");
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/mm.h>

bool is_vmalloc_addr(const void * x)
{
	lx_emul_trace(__func__);
	return false;
}


struct goodix_ts_data;

extern int goodix_firmware_check(struct goodix_ts_data * ts);
int goodix_firmware_check(struct goodix_ts_data * ts)
{
	lx_emul_trace(__func__);

	/* needs to return the good case, otherwise probing will fail */
	return 0;
}


extern bool goodix_handle_fw_request(struct goodix_ts_data * ts);
bool goodix_handle_fw_request(struct goodix_ts_data * ts)
{
	lx_emul_trace(__func__);
	return false;
}


#include <linux/skbuff.h>

void __init skb_init(void)
{
	lx_emul_trace(__func__);
}


#include <net/net_namespace.h>

void __init net_ns_init(void)
{
	lx_emul_trace(__func__);
}


void rt_mutex_setprio(struct task_struct *p, struct task_struct *pi_task)
{
    lx_emul_trace(__func__);
}


#include <linux/context_tracking_irq.h>

noinstr void ct_irq_enter(void)
{
	lx_emul_trace(__func__);
}


#include <linux/context_tracking_irq.h>

void ct_irq_enter_irqson(void)
{
	lx_emul_trace(__func__);
}


#include <linux/context_tracking_irq.h>

noinstr void ct_irq_exit(void)
{
	lx_emul_trace(__func__);
}


#include <linux/context_tracking_irq.h>

void ct_irq_exit_irqson(void)
{
	lx_emul_trace(__func__);
}


#include <linux/regulator/consumer.h>

int regulator_disable(struct regulator * regulator)
{
	lx_emul_trace(__func__);
	return 0;
}
