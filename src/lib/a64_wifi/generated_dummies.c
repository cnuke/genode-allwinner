/*
 * \brief  Dummy definitions of Linux Kernel functions
 * \author Automatically generated file - do no edit
 * \date   2023-02-15
 */

#include <lx_emul.h>


#include <linux/proc_fs.h>

void * PDE_DATA(const struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ratelimit_types.h>

int ___ratelimit(struct ratelimit_state * rs,const char * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/clk-provider.h>

const char * __clk_get_name(const struct clk * clk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ethtool.h>

int __ethtool_get_link_ksettings(struct net_device * dev,struct ethtool_link_ksettings * link_ksettings)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/gen_stats.h>

void __gnet_stats_copy_basic(const seqcount_t * running,struct gnet_stats_basic_packed * bstats,struct gnet_stats_basic_cpu __percpu * cpu,struct gnet_stats_basic_packed * b)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/gen_stats.h>

void __gnet_stats_copy_queue(struct gnet_stats_queue * qstats,const struct gnet_stats_queue __percpu * cpu,const struct gnet_stats_queue * q,__u32 qlen)
{
	lx_emul_trace_and_stop(__func__);
}


#include <asm-generic/percpu.h>

unsigned long __per_cpu_offset[NR_CPUS] = {};


#include <linux/cred.h>

void __put_cred(struct cred * cred)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/task.h>

void __put_task_struct(struct task_struct * tsk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

void __scm_destroy(struct scm_cookie * scm)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

int __scm_send(struct socket * sock,struct msghdr * msg,struct scm_cookie * p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/skbuff.h>

u32 __skb_get_hash_symmetric(const struct sk_buff * skb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/vmalloc.h>

void * __vmalloc_node(unsigned long size,unsigned long align,gfp_t gfp_mask,int node,const void * caller)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kobject.h>

int add_uevent_var(struct kobj_uevent_env * env,const char * format,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/async.h>

async_cookie_t async_schedule_node(async_func_t func,void * data,int node)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/async.h>

void async_synchronize_full(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int bpf_prog_create_from_user(struct bpf_prog ** pfp,struct sock_fprog * fprog,bpf_aux_classic_check_t trans,bool save_orig)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

void bpf_prog_destroy(struct bpf_prog * fp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

void bpf_warn_invalid_xdp_action(u32 act)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kernel.h>

void bust_spinlocks(int yes)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/console.h>

void console_flush_on_panic(enum con_flush_mode mode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int console_printk[] = {};


#include <linux/console.h>

void console_unblank(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int copy_bpf_fprog_from_user(struct sock_fprog * dst,sockptr_t src,int len)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

size_t copy_page_from_iter(struct page * page,size_t offset,size_t bytes,struct iov_iter * i)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/ip6_checksum.h>

__sum16 csum_ipv6_magic(const struct in6_addr * saddr,const struct in6_addr * daddr,__u32 len,__u8 proto,__wsum csum)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/netdevice.h>

int dev_ifconf(struct net * net,struct ifconf * ifc,int size)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/semaphore.h>

int down_interruptible(struct semaphore * sem)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/dst.h>

void dst_release(struct dst_entry * dst)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/dcache.h>

char * dynamic_dname(struct dentry * dentry,char * buffer,int buflen,const char * fmt,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

void emergency_restart(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ethtool.h>

u32 ethtool_op_get_link(struct net_device * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ethtool.h>

int ethtool_op_get_ts_info(struct net_device * dev,struct ethtool_ts_info * info)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

pid_t f_getown(struct file * filp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int f_setown(struct file * filp,unsigned long arg,int force)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int fasync_helper(int fd,struct file * filp,int on,struct fasync_struct ** fapp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

struct task_struct * find_task_by_vpid(pid_t vnr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pid.h>

struct pid * find_vpid(int nr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/flow_dissector.h>

struct flow_dissector flow_keys_basic_dissector;


extern void flush_dcache_page(struct page * page);
void flush_dcache_page(struct page * page)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/signal.h>

void flush_signals(struct task_struct * t)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/user.h>

void free_uid(struct user_struct * up)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/property.h>

struct fwnode_handle * fwnode_create_software_node(const struct property_entry * properties,const struct fwnode_handle * parent)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/property.h>

void fwnode_remove_software_node(struct fwnode_handle * fwnode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/gen_stats.h>

void gen_kill_estimator(struct net_rate_estimator __rcu ** rate_est)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

ssize_t generic_file_splice_read(struct file * in,loff_t * ppos,struct pipe_inode_info * pipe,size_t len,unsigned int flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

ssize_t generic_splice_sendpage(struct pipe_inode_info * pipe,struct file * out,loff_t * ppos,size_t len,unsigned int flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/gfp.h>

bool gfp_pfmemalloc_allowed(gfp_t gfp_mask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/gen_stats.h>

int gnet_stats_copy_basic(const seqcount_t * running,struct gnet_dump * d,struct gnet_stats_basic_cpu __percpu * cpu,struct gnet_stats_basic_packed * b)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/gen_stats.h>

int gnet_stats_copy_queue(struct gnet_dump * d,struct gnet_stats_queue __percpu * cpu_q,struct gnet_stats_queue * q,__u32 qlen)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uuid.h>

const u8 guid_index[16] = {};


#include <net/inet_common.h>

const struct proto_ops inet_dgram_ops;


#include <linux/utsname.h>

struct user_namespace init_user_ns;


#include <linux/init.h>

bool initcall_debug;


#include <linux/fs.h>

void inode_init_once(struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

void io_schedule_finish(int token)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

int io_schedule_prepare(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

long __sched io_schedule_timeout(long timeout)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

void iov_iter_kvec(struct iov_iter * i,unsigned int direction,const struct kvec * kvec,unsigned long nr_segs,size_t count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

void iov_iter_revert(struct iov_iter * i,size_t unroll)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/ip.h>

struct sk_buff * ip_check_defrag(struct net * net,struct sk_buff * skb,u32 user)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_irq.h>

unsigned int irq_of_parse_and_map(struct device_node * dev,int index)
{
	lx_emul_trace_and_stop(__func__);
}


extern bool irq_wait_for_poll(struct irq_desc * desc);
bool irq_wait_for_poll(struct irq_desc * desc)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/irq_work.h>

void irq_work_tick(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/property.h>

bool is_software_node(const struct fwnode_handle * fwnode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/iw_handler.h>

char * iwe_stream_add_event(struct iw_request_info * info,char * stream,char * ends,struct iw_event * iwe,int event_len)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/iw_handler.h>

char * iwe_stream_add_point(struct iw_request_info * info,char * stream,char * ends,struct iw_event * iwe,char * extra)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kobject.h>

struct kobject *kernel_kobj;


#include <linux/signal.h>

void kernel_sigaction(int sig,__sighandler_t action)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kernfs.h>

void kernfs_put(struct kernfs_node * kn)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/key.h>

key_ref_t key_create_or_update(key_ref_t keyring_ref,const char * type,const char * description,const void * payload,size_t plen,key_perm_t perm,unsigned long flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/key.h>

void key_put(struct key * key)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

void kick_process(struct task_struct * p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

void kill_anon_super(struct super_block * sb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

void kill_fasync(struct fasync_struct ** fp,int sig,int band)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/signal.h>

int kill_pid(struct pid * pid,int sig,int priv)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/slab.h>

int kmem_cache_alloc_bulk(struct kmem_cache * s,gfp_t flags,size_t size,void ** p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/slab.h>

void kmem_cache_destroy(struct kmem_cache * s)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kmsg_dump.h>

void kmsg_dump(enum kmsg_dump_reason reason)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kobject.h>

int kobject_synth_uevent(struct kobject * kobj,const char * buf,size_t count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/delay.h>

unsigned long lpj_fine;


#include <linux/preempt.h>

void migrate_disable(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/preempt.h>

void migrate_enable(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/neighbour.h>

const struct nla_policy nda_policy[] = {};


#include <linux/irq.h>

struct irq_chip no_irq_chip;


#include <linux/fs.h>

loff_t no_llseek(struct file * file,loff_t offset,int whence)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/irq.h>

void note_interrupt(struct irq_desc * desc,irqreturn_t action_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/clk/clk-conf.h>

int of_clk_set_defaults(struct device_node * node,bool clk_supplier)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_device.h>

ssize_t of_device_modalias(struct device * dev,char * str,ssize_t len)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_device.h>

void of_device_uevent(struct device * dev,struct kobj_uevent_env * env)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_device.h>

int of_device_uevent_modalias(struct device * dev,struct kobj_uevent_env * env)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_device.h>

int of_dma_configure_id(struct device * dev,struct device_node * np,bool force_dma,const u32 * id)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of.h>

struct property * of_find_property(const struct device_node * np,const char * name,int * lenp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of.h>

const struct fwnode_operations of_fwnode_ops;


#include <linux/of.h>

const void * of_get_property(const struct device_node * np,const char * name,int * lenp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of_device.h>

const struct of_device_id * of_match_device(const struct of_device_id * matches,const struct device * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of.h>

const char * of_prop_next_string(struct property * prop,const char * cur)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/of.h>

int of_property_read_string(const struct device_node * np,const char * propname,const char ** out_string)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

int open_related_ns(struct ns_common * ns,struct ns_common * (* get_ns)(struct ns_common * ns))
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/page_pool.h>

void page_pool_destroy(struct page_pool * pool)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/page_pool.h>

bool page_pool_return_skb_page(struct page * page)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

enum reboot_mode panic_reboot_mode;


#include <linux/moduleparam.h>

const struct kernel_param_ops param_ops_int;


#include <linux/moduleparam.h>

const struct kernel_param_ops param_ops_uint;


#include <linux/genhd.h>

struct device_type part_type;


#include <linux/pinctrl/devinfo.h>

int pinctrl_bind_pins(struct device * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pinctrl/devinfo.h>

int pinctrl_init_done(struct device * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int printk_deferred(const char * fmt,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

void printk_safe_flush_on_panic(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

struct proc_dir_entry * proc_create_data(const char * name,umode_t mode,struct proc_dir_entry * parent,const struct proc_ops * proc_ops,void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_ns.h>

void proc_free_inum(unsigned int inum)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

void * proc_get_parent_data(const struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

struct proc_dir_entry * proc_mkdir_data(const char * name,umode_t mode,struct proc_dir_entry * parent,void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/socket.h>

int put_cmsg(struct msghdr * msg,int level,int type,int len,void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/socket.h>

void put_cmsg_scm_timestamping(struct msghdr * msg,struct scm_timestamping_internal * tss_internal)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/socket.h>

void put_cmsg_scm_timestamping64(struct msghdr * msg,struct scm_timestamping_internal * tss_internal)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rcutree.h>

void rcu_irq_enter_irqson(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rcutree.h>

void rcu_irq_exit_irqson(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

enum reboot_mode reboot_mode;


#include <net/addrconf.h>

int register_inet6addr_notifier(struct notifier_block * nb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/inetdevice.h>

int register_inetaddr_notifier(struct notifier_block * nb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

void remove_proc_entry(const char * name,struct proc_dir_entry * parent)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock_reuseport.h>

int reuseport_detach_prog(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock_reuseport.h>

void reuseport_detach_sock(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

void scm_detach_fds(struct msghdr * msg,struct scm_cookie * scm)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

void sdio_claim_host(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_claim_irq(struct sdio_func * func,sdio_irq_handler_t * handler)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_disable_func(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_enable_func(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

unsigned char sdio_f0_readb(struct sdio_func * func,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

void sdio_f0_writeb(struct sdio_func * func,unsigned char b,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

mmc_pm_flag_t sdio_get_host_pm_caps(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_memcpy_fromio(struct sdio_func * func,void * dst,unsigned int addr,int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_memcpy_toio(struct sdio_func * func,unsigned int addr,void * src,int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

u8 sdio_readb(struct sdio_func * func,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

u32 sdio_readl(struct sdio_func * func,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_readsb(struct sdio_func * func,void * dst,unsigned int addr,int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_register_driver(struct sdio_driver * drv)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

void sdio_release_host(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_release_irq(struct sdio_func * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_set_block_size(struct sdio_func * func,unsigned blksz)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_set_host_pm_flags(struct sdio_func * func,mmc_pm_flag_t flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

void sdio_writeb(struct sdio_func * func,u8 b,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

void sdio_writel(struct sdio_func * func,u32 b,unsigned int addr,int * err_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mmc/sdio_func.h>

int sdio_writesb(struct sdio_func * func,unsigned int addr,void * src,int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct hlist_node * seq_hlist_next_rcu(void * v,struct hlist_head * head,loff_t * ppos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct hlist_node * seq_hlist_start_head_rcu(struct hlist_head * head,loff_t pos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct list_head * seq_list_next(void * v,struct list_head * head,loff_t * ppos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct list_head * seq_list_start(struct list_head * head,loff_t pos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct list_head * seq_list_start_head(struct list_head * head,loff_t pos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

loff_t seq_lseek(struct file * file,loff_t offset,int whence)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

int seq_open(struct file * file,const struct seq_operations * op)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_printf(struct seq_file * m,const char * f,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_putc(struct seq_file * m,char c)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_puts(struct seq_file * m,const char * s)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

ssize_t seq_read(struct file * file,char __user * buf,size_t size,loff_t * ppos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

int seq_release(struct inode * inode,struct file * file)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_vprintf(struct seq_file * m,const char * f,va_list args)
{
	lx_emul_trace_and_stop(__func__);
}


#include <crypto/sha2.h>

void sha224_final(struct sha256_state * sctx,u8 * out)
{
	lx_emul_trace_and_stop(__func__);
}


#include <crypto/sha2.h>

void sha256_final(struct sha256_state * sctx,u8 * out)
{
	lx_emul_trace_and_stop(__func__);
}


#include <crypto/sha2.h>

void sha256_update(struct sha256_state * sctx,const u8 * data,unsigned int len)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mm.h>

void show_mem(unsigned int filter,nodemask_t * nodemask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/debug.h>

void show_state_filter(unsigned int state_filter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int simple_setattr(struct user_namespace * mnt_userns,struct dentry * dentry,struct iattr * iattr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int simple_statfs(struct dentry * dentry,struct kstatfs * buf)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

int single_open(struct file * file,int (* show)(struct seq_file *,void *),void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

int single_open_size(struct file * file,int (* show)(struct seq_file *,void *),void * data,size_t size)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

int single_release(struct inode * inode,struct file * file)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int sk_attach_bpf(u32 ufd,struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int sk_attach_filter(struct sock_fprog * fprog,struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int sk_detach_filter(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

void sk_filter_uncharge(struct sock * sk,struct sk_filter * fp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int sk_reuseport_attach_bpf(u32 ufd,struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int sk_reuseport_attach_filter(struct sock_fprog * fprog,struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/smp.h>

int smp_call_function_single(int cpu,smp_call_func_t func,void * info,int wait)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/smp.h>

int smp_call_function_single_async(int cpu,struct __call_single_data * csd)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/smp.h>

void smp_send_stop(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sock_diag.h>

void sock_diag_broadcast_destroy(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock.h>

void sock_edemux(struct sk_buff * skb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/jump_label.h>

bool static_key_initialized;


#include <linux/fs.h>

int stream_open(struct inode * inode,struct file * filp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/string_helpers.h>

int string_escape_mem(const char * src,size_t isz,char * dst,size_t osz,unsigned int flags,const char * only)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int suppress_printk;


#include <linux/sysfs.h>

int sysfs_rename_dir_ns(struct kobject * kobj,const char * new_name,const void * new_ns)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sysfs.h>

int sysfs_rename_link_ns(struct kobject * kobj,struct kobject * targ,const char * old,const char * new,const void * new_ns)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/tcp.h>

struct sk_buff * tcp_get_timestamping_opt_stats(const struct sock * sk,const struct sk_buff * orig_skb,const struct sk_buff * ack_skb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/clockchips.h>

void tick_broadcast(const struct cpumask * mask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/vt_kern.h>

void unblank_screen(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int unregister_filesystem(struct file_system_type * fs)
{
	lx_emul_trace_and_stop(__func__);
}


extern void unregister_handler_proc(unsigned int irq,struct irqaction * action);
void unregister_handler_proc(unsigned int irq,struct irqaction * action)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/addrconf.h>

int unregister_inet6addr_notifier(struct notifier_block * nb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/inetdevice.h>

int unregister_inetaddr_notifier(struct notifier_block * nb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/semaphore.h>

void up(struct semaphore * sem)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uuid.h>

const u8 uuid_index[16] = {};


#include <linux/mm.h>

int vm_insert_page(struct vm_area_struct * vma,unsigned long addr,struct page * page)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mm.h>

struct page * vmalloc_to_page(const void * vmalloc_addr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/wake_q.h>

void wake_q_add_safe(struct wake_q_head * head,struct task_struct * task)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/wext.h>

int wext_handle_ioctl(struct net * net,unsigned int cmd,void __user * arg)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/iw_handler.h>

void wireless_nlevent_flush(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

int xdp_do_generic_redirect(struct net_device * dev,struct sk_buff * skb,struct xdp_buff * xdp,struct bpf_prog * xdp_prog)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

void __sched yield(void)
{
	lx_emul_trace_and_stop(__func__);
}

