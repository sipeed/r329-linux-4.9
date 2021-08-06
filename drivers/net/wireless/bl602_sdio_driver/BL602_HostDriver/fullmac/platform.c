/*
 * platform interfaces for XRadio drivers
 *
 * Copyright (c) 2013, XRadio
 * Author: XRadio
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/version.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/ioport.h>
#include <linux/regulator/consumer.h>
//#include <asm/mach-types.h>
//#include <mach/sys_config.h>
#include "platform.h"
#include <linux/sunxi-gpio.h>
#include <linux/gpio.h>
#include <linux/types.h>
//#include <linux/power/scenelock.h>
#include <linux/power/aw_pm.h>
#define WLAN_WOW_SUPPORT
MODULE_AUTHOR("XRadioTech");
MODULE_DESCRIPTION("XRadioTech WLAN driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("xradio_wlan");

extern void sunxi_wlan_set_power(bool on);
extern int sunxi_wlan_get_bus_index(void);

static int wlan_bus_id;

int xradio_get_syscfg(void)
{
	int wlan_bus_index = 0;
	wlan_bus_index = sunxi_wlan_get_bus_index();
	if (wlan_bus_index < 0)
		return wlan_bus_index;
	else
		wlan_bus_id = wlan_bus_index;
	return wlan_bus_index;
}
/*********************Interfaces called by xradio core. *********************/
int  xradio_plat_init(void)
{
  return 0;
}

void xradio_plat_deinit(void)
{
;
}

int xradio_wlan_power(int on)
{
	int ret = 0;
	if (on) {
	    ret = xradio_get_syscfg();
		if (ret < 0)
			return ret;
	}
	sunxi_wlan_set_power(on);
	mdelay(100);
	return ret;
}

void xradio_sdio_detect(int enable)
{
	MCI_RESCAN_CARD(wlan_bus_id);
	printk(KERN_INFO "%s SDIO card %d\n",
				enable?"Detect":"Remove", wlan_bus_id);
	mdelay(10);
}
