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

#include <linux/string.h>

unsigned long __must_check __arch_copy_from_user(void *to, const void __user *from, unsigned long n);
unsigned long __must_check __arch_copy_from_user(void *to, const void __user *from, unsigned long n)
{
	memcpy(to, from, n);
	return 0;
}


unsigned long __must_check __arch_copy_to_user(void __user *to, const void *from, unsigned long n);
unsigned long __must_check __arch_copy_to_user(void __user *to, const void *from, unsigned long n)
{
	memcpy(to, from, n);
	return 0;
}


#include <linux/of_reserved_mem.h>
#include <linux/mod_devicetable.h>

const struct of_device_id __reservedmem_of_table[] = {};


#include <asm-generic/sections.h>

char __start_rodata[] = {};
char __end_rodata[]   = {};


#include <linux/tracepoint-defs.h>

const struct trace_print_flags gfpflag_names[]  = {};
const struct trace_print_flags pageflag_names[] = {};
const struct trace_print_flags vmaflag_names[]  = {};


#include <asm/memory.h>

u64 vabits_actual;


#include <linux/srcutree.h>

void synchronize_srcu(struct srcu_struct * ssp)
{
	lx_emul_trace(__func__);
}


#include <linux/cpuhotplug.h>

int __cpuhp_setup_state(enum cpuhp_state state,const char * name,bool invoke,
                        int (* startup)(unsigned int cpu),
                        int (* teardown)(unsigned int cpu), bool multi_instance)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/timekeeper_internal.h>

void update_vsyscall(struct timekeeper * tk)
{
	lx_emul_trace(__func__);
}


#include <linux/sched/signal.h>

void ignore_signals(struct task_struct * t)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

int sysfs_create_groups(struct kobject * kobj,const struct attribute_group ** groups)
{
	return 0;
}


#include <linux/kernfs.h>

void kernfs_get(struct kernfs_node * kn) { }


#include <linux/kernfs.h>

void kernfs_put(struct kernfs_node * kn) { }


#include <linux/kobject.h>

int kobject_uevent(struct kobject * kobj,enum kobject_action action)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/sysfs.h>

int sysfs_create_bin_file(struct kobject * kobj,const struct bin_attribute * attr)
{
	return 0;
}


#include <linux/proc_fs.h>

struct proc_dir_entry * proc_symlink(const char * name,struct proc_dir_entry * parent,const char * dest)
{
	lx_emul_trace(__func__);
	return NULL;
}


#include <linux/property.h>

int software_node_notify(struct device * dev,unsigned long action)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/sysfs.h>

int sysfs_create_file_ns(struct kobject * kobj,const struct attribute * attr,const void * ns)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/random.h>

struct random_ready_callback;

int add_random_ready_callback(struct random_ready_callback * rdy)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/sysfs.h>

int sysfs_create_link(struct kobject * kobj,struct kobject * target,const char * name)
{
	lx_emul_trace(__func__);
	return 0;
}


int sysfs_emit(char * buf,const char * fmt,...)
{
	lx_emul_trace(__func__);
	return PAGE_SIZE;
}


int sysfs_emit_at(char * buf, int at, const char * fmt,...)
{
	lx_emul_trace(__func__);
	return at > PAGE_SIZE ? PAGE_SIZE : PAGE_SIZE - at;
}


int sysfs_create_group(struct kobject * kobj,const struct attribute_group * grp)
{
	lx_emul_trace(__func__);
	return 0;
}


void sysfs_remove_group(struct kobject * kobj,const struct attribute_group * grp)
{
	lx_emul_trace(__func__);
}


#include <linux/slab.h>
#include <linux/kobject.h>

int sysfs_create_dir_ns(struct kobject * kobj,const void * ns)
{
	if (!kobj)
		return -EINVAL;

	kobj->sd = kzalloc(sizeof(*kobj->sd), GFP_KERNEL);
	return 0;
}


#include <linux/logic_pio.h>

struct logic_pio_hwaddr * find_io_range_by_fwnode(struct fwnode_handle * fwnode)
{
	lx_emul_trace(__func__);
	return NULL;
}


#include <linux/syscore_ops.h>

void register_syscore_ops(struct syscore_ops * ops)
{
	lx_emul_trace(__func__);
}


#include <linux/kernel.h>

bool parse_option_str(const char *str, const char *option)
{
	lx_emul_trace(__func__);
	return false;
}


#include <linux/dma-mapping.h>

void arch_setup_dma_ops(struct device * dev,u64 dma_base,u64 size,const struct iommu_ops * iommu,bool coherent)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

void sysfs_remove_link(struct kobject * kobj,const char * name) { }


#include <linux/kernel_stat.h>

void account_process_tick(struct task_struct * p,int user_tick)
{
	lx_emul_trace(__func__);
}


#include <linux/rcupdate.h>

void rcu_sched_clock_irq(int user)
{
	lx_emul_trace(__func__);
}


bool arm64_use_ng_mappings = false;
EXPORT_SYMBOL(arm64_use_ng_mappings);


#include <linux/sysfs.h>

void sysfs_remove_file_ns(struct kobject * kobj,const struct attribute * attr,const void * ns)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

void sysfs_delete_link(struct kobject * kobj,struct kobject * targ,const char * name)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

void sysfs_remove_groups(struct kobject * kobj,const struct attribute_group ** groups)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

void sysfs_remove_dir(struct kobject * kobj)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

int sysfs_create_link_nowarn(struct kobject * kobj,struct kobject * target,const char * name)
{
	lx_emul_trace(__func__);
	return 0;
}


extern void register_irq_proc(unsigned int irq,struct irq_desc * desc);
void register_irq_proc(unsigned int irq,struct irq_desc * desc)
{
	lx_emul_trace(__func__);
}


extern void register_handler_proc(unsigned int irq,struct irqaction * action);
void register_handler_proc(unsigned int irq,struct irqaction * action)
{
	lx_emul_trace(__func__);
}


#include <linux/blkdev.h>

struct device_type part_type;


extern void software_node_notify_remove(struct device * dev);
void software_node_notify_remove(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/sysctl.h>

struct ctl_table_header * register_sysctl(const char * path,struct ctl_table * table)
{
	lx_emul_trace(__func__);
	return NULL;
}


void __init __register_sysctl_init(const char * path,struct ctl_table * table,const char * table_name)
{
	lx_emul_trace(__func__);
}


#include <linux/sysfs.h>

int sysfs_add_file_to_group(struct kobject * kobj,const struct attribute * attr,const char * group)
{
	lx_emul_trace(__func__);
	return 0;
}


/*
 * Power-management related dummies that became needed because the
 * the sun6i-csi driver requires the PM option. Since they are not
 * required by the other drivers, implement them all here.
 *
 * FIXME eventually extended 'lx_emul/shadow/drivers/base/power/runtime.c'
 *       and make use of the compilation unit.
 */

#include <linux/pm_runtime.h>

void __pm_runtime_disable(struct device * dev,bool check_resume)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

int __pm_runtime_idle(struct device * dev,int rpmflags)
{
	lx_emul_trace(__func__);
	return -ENOSYS;
}


#include <linux/pm_runtime.h>

int __pm_runtime_resume(struct device * dev,int rpmflags)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

int __pm_runtime_set_status(struct device * dev,unsigned int status)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

int __pm_runtime_suspend(struct device * dev,int rpmflags)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

void __pm_runtime_use_autosuspend(struct device * dev,bool use)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_domain.h>

int dev_pm_domain_attach(struct device * dev,bool power_on)
{
	lx_emul_trace(__func__);
	return 0;
}

#include <linux/pm_domain.h>

void dev_pm_domain_detach(struct device * dev,bool power_off)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_qos.h>

int dev_pm_qos_add_request(struct device * dev,struct dev_pm_qos_request * req,enum dev_pm_qos_req_type type,s32 value)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_qos.h>

int dev_pm_qos_expose_flags(struct device * dev,s32 val)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_qos.h>

enum pm_qos_flags_status dev_pm_qos_flags(struct device * dev,s32 mask)
{
	lx_emul_trace(__func__);
	return PM_QOS_FLAGS_UNDEFINED;
}


#include <linux/pm_qos.h>

int dev_pm_qos_remove_request(struct dev_pm_qos_request * req)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_wakeirq.h>

void dev_pm_clear_wake_irq(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_wakeirq.h>

int dev_pm_set_dedicated_wake_irq(struct device *dev, int irq)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_wakeirq.h>

int dev_pm_set_wake_irq(struct device *dev, int irq)
{
	lx_emul_trace(__func__);
	return 0;
}


extern int dpm_sysfs_add(struct device * dev);
int dpm_sysfs_add(struct device * dev)
{
	lx_emul_trace(__func__);
	return 0;
}


extern void dpm_sysfs_remove(struct device * dev);
void dpm_sysfs_remove(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

int pm_generic_runtime_resume(struct device * dev)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

int pm_generic_runtime_suspend(struct device * dev)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

void pm_runtime_allow(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

int pm_runtime_barrier(struct device * dev)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/pm_runtime.h>

void pm_runtime_drop_link(struct device_link * link)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_enable(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_forbid(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_get_suppliers(struct device * dev)
{
	lx_emul_trace(__func__);
}


extern void pm_runtime_init(struct device * dev);
void pm_runtime_init(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_new_link(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_no_callbacks(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_put_suppliers(struct device * dev)
{
	lx_emul_trace(__func__);
}


extern void pm_runtime_reinit(struct device * dev);
void pm_runtime_reinit(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_release_supplier(struct device_link * link)
{
	lx_emul_trace(__func__);
}


extern void pm_runtime_remove(struct device * dev);
void pm_runtime_remove(struct device * dev)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_set_autosuspend_delay(struct device * dev,int delay)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

void pm_runtime_set_memalloc_noio(struct device *dev, bool enable)
{
	lx_emul_trace(__func__);
}


#include <linux/pm_runtime.h>

int pm_runtime_get_if_active(struct device *dev, bool ign_usage_count)
{
	lx_emul_trace(__func__);
	return 0;
}


#include <linux/sysfs.h>

int sysfs_merge_group(struct kobject * kobj,const struct attribute_group * grp)
{
	lx_emul_trace(__func__);
	return 0;
}


