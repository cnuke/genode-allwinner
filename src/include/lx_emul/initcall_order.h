/*
 * \brief  Array defining order of Linux Kernel initcalls
 * \author Automatically generated file - do no edit
 * \date   2022-10-17
 */

#pragma once

static const char * lx_emul_initcall_order[] = {
	"__initcall_asids_initearly",
	"__initcall_start",
	"__initcall_spawn_ksoftirqdearly",
	"__initcall_migration_initearly",
	"__initcall_srcu_bootup_announceearly",
	"__initcall_rcu_spawn_gp_kthreadearly",
	"__initcall_check_cpu_stall_initearly",
	"__initcall_rcu_sysrq_initearly",
	"__initcall_cpu_stop_initearly",
	"__initcall_init_zero_pfnearly",
	"__initcall_its_pmsi_initearly",
	"__initcall_dummy_timer_registerearly",
	"__initcall_initialize_ptr_randomearly",
	"__initcall_init_mmap_min_addr0",
	"__initcall_net_ns_init0",
	"__initcall_inet_frag_wq_init0",
	"__initcall_fpsimd_init1",
	"__initcall_enable_mrs_emulation1",
	"__initcall_init_amu_fie1",
	"__initcall_wq_sysfs_init1",
	"__initcall_ksysfs_init1",
	"__initcall_rcu_set_runtime_mode1",
	"__initcall_dma_init_reserved_memory1",
	"__initcall_init_jiffies_clocksource1",
	"__initcall_cma_init_reserved_areas1",
	"__initcall_init_elf_binfmt1",
	"__initcall_prandom_init_early1",
	"__initcall_pinctrl_init1",
	"__initcall_gpiolib_dev_init1",
	"__initcall_regulator_init1",
	"__initcall_free_raw_capacity1",
	"__initcall_sock_init1",
	"__initcall_net_inuse_init1",
	"__initcall_net_defaults_init1",
	"__initcall_init_default_flow_dissectors1",
	"__initcall_netlink_proto_init1",
	"__initcall_genl_init1",
	"__initcall_debug_monitors_init2",
	"__initcall_irq_sysfs_init2",
	"__initcall_dma_atomic_pool_init2",
	"__initcall_bdi_class_init2",
	"__initcall_mm_sysfs_init2",
	"__initcall_init_per_zone_wmark_min2",
	"__initcall_backlight_class_init2",
	"__initcall_amba_init2",
	"__initcall_tty_class_init2",
	"__initcall_vtconsole_class_init2",
	"__initcall_mipi_dsi_bus_init2",
	"__initcall_devlink_class_init2",
	"__initcall_software_node_init2",
	"__initcall_regmap_initcall2",
	"__initcall_syscon_init2",
	"__initcall_i2c_init2",
	"__initcall_kobject_uevent_init2",
	"__initcall_reserve_memblock_reserved_regions3",
	"__initcall_vdso_init3",
	"__initcall_asids_update_limit3",
	"__initcall_kcmp_cookies_init3",
	"__initcall_sunxi_mbus_init3",
	"__initcall_of_platform_default_populate_init3s",
	"__initcall_topology_init4",
	"__initcall_uid_cache_init4",
	"__initcall_param_sysfs_init4",
	"__initcall_user_namespace_sysctl_init4",
	"__initcall_oom_init4",
	"__initcall_default_bdi_init4",
	"__initcall_percpu_enable_async4",
	"__initcall_init_user_reserve4",
	"__initcall_init_admin_reserve4",
	"__initcall_init_reserve_notifier4",
	"__initcall_swap_init_sysfs4",
	"__initcall_swapfile_init4",
	"__initcall_init_bio4",
	"__initcall_blk_ioc_init4",
	"__initcall_blk_mq_init4",
	"__initcall_genhd_device_init4",
	"__initcall_pwm_sysfs_init4",
	"__initcall_fbmem_init4",
	"__initcall_misc_init4",
	"__initcall_register_cpu_capacity_sysctl4",
	"__initcall_dma_buf_init4",
	"__initcall_phy_init4",
	"__initcall_usb_common_init4",
	"__initcall_usb_init4",
	"__initcall_usb_roles_init4",
	"__initcall_serio_init4",
	"__initcall_input_init4",
	"__initcall_power_supply_class_init4",
	"__initcall_mmc_init4",
	"__initcall_devfreq_init4",
	"__initcall_devfreq_simple_ondemand_init4",
	"__initcall_proto_init4",
	"__initcall_net_dev_init4",
	"__initcall_neigh_init4",
	"__initcall_fib_notifier_init4",
	"__initcall_ethnl_init4",
	"__initcall_nexthop_init4",
	"__initcall_init_32bit_el0_mask4s",
	"__initcall_create_debug_debugfs_entry5",
	"__initcall_iomem_init_inode5",
	"__initcall_clocksource_done_booting5",
	"__initcall_init_pipe_fs5",
	"__initcall_anon_inode_init5",
	"__initcall_proc_cmdline_init5",
	"__initcall_proc_consoles_init5",
	"__initcall_proc_cpuinfo_init5",
	"__initcall_proc_devices_init5",
	"__initcall_proc_interrupts_init5",
	"__initcall_proc_loadavg_init5",
	"__initcall_proc_meminfo_init5",
	"__initcall_proc_stat_init5",
	"__initcall_proc_uptime_init5",
	"__initcall_proc_version_init5",
	"__initcall_proc_softirqs_init5",
	"__initcall_proc_kmsg_init5",
	"__initcall_proc_page_init5",
	"__initcall_init_ramfs_fs5",
	"__initcall_blk_scsi_ioctl_init5",
	"__initcall_chr_dev_init5",
	"__initcall_firmware_class_init5",
	"__initcall_sysctl_core_init5",
	"__initcall_eth_offload_init5",
	"__initcall_ipv4_offload_init5",
	"__initcall_inet_init5",
	"__initcall_ipv6_offload_init5",
	"__initcall_populate_rootfsrootfs",
	"__initcall_register_arm64_panic_block6",
	"__initcall_cpuinfo_regs_init6",
	"__initcall_proc_execdomains_init6",
	"__initcall_ioresources_init6",
	"__initcall_irq_gc_init_ops6",
	"__initcall_timekeeping_init_ops6",
	"__initcall_init_clocksource_sysfs6",
	"__initcall_init_timer_list_procfs6",
	"__initcall_alarmtimer_init6",
	"__initcall_clockevents_init_sysfs6",
	"__initcall_sched_clock_syscore_init6",
	"__initcall_utsname_sysctl_init6",
	"__initcall_kswapd_init6",
	"__initcall_mm_compute_batch_init6",
	"__initcall_workingset_init6",
	"__initcall_proc_vmalloc_init6",
	"__initcall_procswaps_init6",
	"__initcall_fcntl_init6",
	"__initcall_proc_filesystems_init6",
	"__initcall_start_dirtytime_writeback6",
	"__initcall_blkdev_init6",
	"__initcall_dio_init6",
	"__initcall_init_devpts_fs6",
	"__initcall_proc_genhd_init6",
	"__initcall_bsg_init6",
	"__initcall_deadline_init6",
	"__initcall_kyber_init6",
	"__initcall_percpu_counter_startup6",
	"__initcall_sun50i_de2_bus_driver_init6",
	"__initcall_sunxi_rsb_init6",
	"__initcall_phy_core_init6",
	"__initcall_sun4i_usb_phy_driver_init6",
	"__initcall_sun6i_dphy_platform_driver_init6",
	"__initcall_a64_pinctrl_driver_init6",
	"__initcall_sun50i_a64_r_pinctrl_driver_init6",
	"__initcall_a100_pinctrl_driver_init6",
	"__initcall_a100_r_pinctrl_driver_init6",
	"__initcall_sun8i_h3_r_pinctrl_driver_init6",
	"__initcall_sun50i_h5_pinctrl_driver_init6",
	"__initcall_h6_pinctrl_driver_init6",
	"__initcall_sun50i_h6_r_pinctrl_driver_init6",
	"__initcall_h616_pinctrl_driver_init6",
	"__initcall_sun50i_h616_r_pinctrl_driver_init6",
	"__initcall_sun4i_pwm_driver_init6",
	"__initcall_pwm_backlight_driver_init6",
	"__initcall_of_fixed_factor_clk_driver_init6",
	"__initcall_of_fixed_clk_driver_init6",
	"__initcall_gpio_clk_driver_init6",
	"__initcall_sun4i_a10_mod0_clk_driver_init6",
	"__initcall_sun9i_a80_mmc_config_clk_driver_init6",
	"__initcall_sun8i_a23_apb0_clk_driver_init6",
	"__initcall_sun6i_a31_apb0_clk_driver_init6",
	"__initcall_sun6i_a31_apb0_gates_clk_driver_init6",
	"__initcall_sun6i_a31_ar100_clk_driver_init6",
	"__initcall_sun50i_a64_ccu_driver_init6",
	"__initcall_sun50i_a100_ccu_driver_init6",
	"__initcall_sun50i_a100_r_ccu_driver_init6",
	"__initcall_sun50i_h6_ccu_driver_init6",
	"__initcall_sunxi_de2_clk_driver_init6",
	"__initcall_sunxi_sram_driver_init6",
	"__initcall_axp20x_regulator_driver_init6",
	"__initcall_reset_simple_driver_init6",
	"__initcall_n_null_init6",
	"__initcall_pty_init6",
	"__initcall_serial8250_init6",
	"__initcall_dw8250_platform_driver_init6",
	"__initcall_of_platform_serial_driver_init6",
	"__initcall_drm_kms_helper_init6",
	"__initcall_drm_core_init6",
	"__initcall_drm_sched_fence_slab_init6",
	"__initcall_sun4i_drv_platform_driver_init6",
	"__initcall_sun4i_tcon_platform_driver_init6",
	"__initcall_sun4i_tv_platform_driver_init6",
	"__initcall_sun6i_drc_platform_driver_init6",
	"__initcall_sun4i_backend_platform_driver_init6",
	"__initcall_sun4i_frontend_driver_init6",
	"__initcall_sun4i_hdmi_driver_init6",
	"__initcall_sun6i_dsi_platform_driver_init6",
	"__initcall_sun8i_dw_hdmi_init6",
	"__initcall_sun8i_mixer_platform_driver_init6",
	"__initcall_sun8i_tcon_top_platform_driver_init6",
	"__initcall_st7703_driver_init6",
	"__initcall_lima_platform_driver_init6",
	"__initcall_topology_sysfs_init6",
	"__initcall_cacheinfo_sysfs_init6",
	"__initcall_sun6i_prcm_driver_init6",
	"__initcall_axp20x_rsb_driver_init6",
	"__initcall_net_olddevs_init6",
	"__initcall_blackhole_netdev_init6",
	"__initcall_fixed_mdio_bus_init6",
	"__initcall_phy_module_init6",
	"__initcall_stmmac_init6",
	"__initcall_sun7i_dwmac_driver_init6",
	"__initcall_sun8i_dwmac_driver_init6",
	"__initcall_dwmac_generic_driver_init6",
	"__initcall_ehci_hcd_init6",
	"__initcall_ehci_platform_init6",
	"__initcall_serport_init6",
	"__initcall_atkbd_init6",
	"__initcall_psmouse_init6",
	"__initcall_goodix_ts_driver_init6",
	"__initcall_mv64xxx_i2c_driver_init6",
	"__initcall_mmc_pwrseq_simple_driver_init6",
	"__initcall_mmc_pwrseq_emmc_driver_init6",
	"__initcall_mmc_blk_init6",
	"__initcall_sunxi_mmc_driver_init6",
	"__initcall_hid_init6",
	"__initcall_hid_generic_init6",
	"__initcall_extcon_class_init6",
	"__initcall_sock_diag_init6",
	"__initcall_gre_offload_init6",
	"__initcall_sysctl_ipv4_init6",
	"__initcall_tunnel4_init6",
	"__initcall_inet_diag_init6",
	"__initcall_tcp_diag_init6",
	"__initcall_cubictcp_register6",
	"__initcall_inet6_init6",
	"__initcall_sit_init6",
	"__initcall_usbnet_init6",
	"__initcall_init_oops_id7",
	"__initcall_reboot_ksysfs_init7",
	"__initcall_sched_init_debug7",
	"__initcall_printk_late_init7",
	"__initcall_max_swapfiles_check7",
	"__initcall_check_early_ioremap_leak7",
	"__initcall_blk_timeout_init7",
	"__initcall_prandom_init_late7",
	"__initcall_amba_deferred_retry7",
	"__initcall_sync_state_resume_initcall7",
	"__initcall_deferred_probe_initcall7",
	"__initcall_of_fdt_raw_init7",
	"__initcall_tcp_congestion_default7",
	"__initcall_ip_auto_config7",
	"__initcall_fb_logo_late_init7s",
	"__initcall_clk_disable_unused7s",
	"__initcall_regulator_init_complete7s",
	"__initcall_of_platform_sync_state_init7s",
	"__initcall_con_initcon",
	"__initcall_end",
	"__initcall_univ8250_console_initcon",
	"END_OF_INITCALL_ORDER_ARRAY_DUMMY_ENTRY"
};
