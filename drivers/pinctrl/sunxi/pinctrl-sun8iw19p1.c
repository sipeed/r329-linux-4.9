/*
* Allwinner sun8iw16p1 SoCs pinctrl driver.
*
* Copyright(c) 2016-2020 Allwinnertech Co., Ltd.
* Author: matteo <duanmintao@allwinnertech.com>
*
* This file is licensed under the terms of the GNU General Public
* License version 2.  This program is licensed "as is" without any
* warranty of any kind, whether express or implied.
*/

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-sunxi.h"

static const struct sunxi_desc_pin sun8iw19p1_pins[] = {
	 /* hole */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* DS */
		SUNXI_FUNCTION(0x4, "spi0"),		/* CLK */
		SUNXI_FUNCTION(0x5, "Vdevice"),         /* vdevice */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* RST */
		SUNXI_FUNCTION(0x4, "spi0"),		/* CS0 */
		SUNXI_FUNCTION(0x5, "Vdevice"),         /* vdevice */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* CLE */
		SUNXI_FUNCTION(0x4, "spi0"),		/* MOSI */
		SUNXI_FUNCTION(0x5, "boot_sel2"),		/* BOOT_SEL2 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* CE0 */
		SUNXI_FUNCTION(0x4, "spi0"),		/* MISO */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* CLK */
		SUNXI_FUNCTION(0x4, "spi0"),		/* SPI0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* CMD */
		SUNXI_FUNCTION(0x4, "spi0"),		/* SPI0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* D3 */
		SUNXI_FUNCTION(0x4, "spi0"),		/* SPI0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 6)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 7),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* D4 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 7)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 8),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* D0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 8)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 9),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* D5 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 9)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 10),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* CS1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 10)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(C, 11),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "sdc2"),		/* D1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 0, 11)),

	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D2 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D3 */
		SUNXI_FUNCTION(0x3, "pwm0"),		/* PWM0 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D0 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* RXD1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D4 */
		SUNXI_FUNCTION(0x3, "pwm1"),		/* PWM1 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D1 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* RXD0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D5 */
		SUNXI_FUNCTION(0x3, "pwm2"),		/* PWM2 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D2 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* CRS_DV */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D6 */
		SUNXI_FUNCTION(0x3, "pwm3"),		/* PWM3 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D3 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* RXER */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D7 */
		SUNXI_FUNCTION(0x3, "pwm4"),		/* PWM4 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D4 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* TXD1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D10 */
		SUNXI_FUNCTION(0x3, "pwm5"),		/* PWM5 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D5 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* TXD0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 6)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 7),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D11 */
		SUNXI_FUNCTION(0x3, "pwm6"),		/* PWM6 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D6 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* TXCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 7)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 8),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D12 */
		SUNXI_FUNCTION(0x3, "pwm7"),		/* PWM7 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D7 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* TXEN */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 8)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 9),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D13 */
		SUNXI_FUNCTION(0x3, "pwm8"),		/* PWM8 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 9)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 10),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D14 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* MCLK */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D8 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 10)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 11),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D15 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* BCLK */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D9 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 11)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 12),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D18 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* LRCK */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D10 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 12)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 13),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D19 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* DOUTO */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D11 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 13)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 14),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D20 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* DOUT1 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D12 */
		SUNXI_FUNCTION(0x5, "i2s1"),		/* DIN1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 14)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 15),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D21 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* DOUT2 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D13 */
		SUNXI_FUNCTION(0x5, "i2s1"),		/* DIN2 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 15)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 16),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D22 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* DOUT3 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D14 */
		SUNXI_FUNCTION(0x5, "i2s1"),		/* DIN3 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 16)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 17),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* D23 */
		SUNXI_FUNCTION(0x3, "i2s1"),		/* DIN */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* D15 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 17)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 18),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* CLK */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* CLK */
		SUNXI_FUNCTION(0x5, "ephy"),		/* DIN1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 18)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 19),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* DE */
		SUNXI_FUNCTION(0x2, "pwm9"),		/* pwm9 */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* bt1120*/
		SUNXI_FUNCTION(0x5, "tcon"),		/* DIN1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 19)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 20),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* HSYNC */
		SUNXI_FUNCTION(0x3, "Vdevice"),	/* TCON_TRIG */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* HSYNC */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* MDC */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 20)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 21),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "lcd0"),		/* VSYNC */
		SUNXI_FUNCTION(0x3, "vdevice"),		/* vdevice */
		SUNXI_FUNCTION(0x4, "bt1120"),		/* DIN1 */
		SUNXI_FUNCTION(0x5, "gmac0"),		/* MDIO */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 21)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(D, 22),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm9"),		/* lcd */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 1, 22)),

	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* PCLK */
		SUNXI_FUNCTION(0x3, "rgmii"),			/* RXD3 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi_mclk1"),		/* MASTERCLK1 */
		SUNXI_FUNCTION(0x3, "rgmii"),			/* RXD2 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* HSYNC */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* RXD1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* VSYNC */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* RXD0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D0 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* RXCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D1 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* RXCTL/CRS_DV */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D2 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* CLKIN/RXER */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 6)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 7),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D3 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXD3 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 7)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 8),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D4 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXD2 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 8)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 9),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D5 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXD1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 9)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 10),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D6 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXD0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 10)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 11),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D7 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 11)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 12),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D8 */
		SUNXI_FUNCTION(0x3, "rgmii"),		/* TXCTL */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 12)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 13),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D9 */
		SUNXI_FUNCTION(0x3, "mad"),		/* MDC */
		SUNXI_FUNCTION(0x5, "twi1"),		/* SCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 13)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 14),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D10 */
		SUNXI_FUNCTION(0x3, "mdio"),		/* MDIO */
		SUNXI_FUNCTION(0x5, "twi1"),		/* SDK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 14)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 15),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D11 */
		SUNXI_FUNCTION(0x3, "ephy_25m"),		/* EPHY_25M */
		SUNXI_FUNCTION(0x5, "csi_field"),		/* FIELD */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 15)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 16),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D0 */
		SUNXI_FUNCTION(0x5, "twi0"),		/* SCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 16)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 17),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D1 */
		SUNXI_FUNCTION(0x5, "twi1"),		/* SDA */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 17)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 18),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D12 */
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D8 */
		SUNXI_FUNCTION(0x4, "spi2"),		/* CLK */
		SUNXI_FUNCTION(0x5, "uart2"),		/* TX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 18)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 19),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D13 */
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D9 */
		SUNXI_FUNCTION(0x4, "spi2"),		/* MOSI */
		SUNXI_FUNCTION(0x5, "uart2"),		/* RX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 19)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 20),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D14 */
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D16 */
		SUNXI_FUNCTION(0x4, "spi2"),		/* MISO */
		SUNXI_FUNCTION(0x5, "uart2"),		/* RTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 20)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(E, 21),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi1"),		/* D15 */
		SUNXI_FUNCTION(0x3, "lcd0"),		/* D17 */
		SUNXI_FUNCTION(0x4, "spi2"),		/* CS0 */
		SUNXI_FUNCTION(0x5, "uart2"),		/* CTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 2, 21)),
	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* D1 */
		SUNXI_FUNCTION(0x3, "jtag0"),		/* MS1 */
		SUNXI_FUNCTION(0x5, "bist0"),		/* BIST0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* D0 */
		SUNXI_FUNCTION(0x3, "jtag0"),		/* DI1 */
		SUNXI_FUNCTION(0x5, "bist1"),		/* BIST1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* CLK */
		SUNXI_FUNCTION(0x3, "uart0"),		/* TX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* CMD */
		SUNXI_FUNCTION(0x3, "jtag0"),		/* DO1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* D3 */
		SUNXI_FUNCTION(0x3, "uart0"),		/* RX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc0"),		/* D2 */
		SUNXI_FUNCTION(0x3, "jtag0"),		/* CK1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(F, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 3, 6)),

	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* CLK */
		SUNXI_FUNCTION(0x5, "uart3"),
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* CMD */
		SUNXI_FUNCTION(0x5, "uart3"),
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* D0 */
		SUNXI_FUNCTION(0x5, "uart3"),
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* D1 */
		SUNXI_FUNCTION(0x5, "uart3"),		/* RXD1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* D2 */
		SUNXI_FUNCTION(0x5, "uart1"),		/* RXD0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "sdc1"),		/* D3 */
		SUNXI_FUNCTION(0x5, "uart1"),		/* CRS_DV */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x5, "uart1"),		/* TX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 6)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(G, 7),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x5, "uart1"),		/* RX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 4, 7)),
	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm0"),		/* PWM0 */
		SUNXI_FUNCTION(0x3, "i2s0"),		/* MCLK */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MCLK */
		SUNXI_FUNCTION(0x5, "uart3"),		/* TX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm1"),		/* BCLK */
		SUNXI_FUNCTION(0x3, "i2s0"),		/* BCLK */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MCLK */
		SUNXI_FUNCTION(0x5, "uart3"),		/* RX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm2"),		/* SYNC */
		SUNXI_FUNCTION(0x3, "i2s0"),		/* LRCK */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MCLK */
		SUNXI_FUNCTION(0x5, "uart3"),		/* CTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm3"),		/* DOUT */
		SUNXI_FUNCTION(0x3, "i2s0"),		/* DOUT */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MCLK */
		SUNXI_FUNCTION(0x5, "uart3"),		/* RTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm4"),		/* DIN */
		SUNXI_FUNCTION(0x3, "i2s0"),		/* DIN */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MCLK */
		SUNXI_FUNCTION(0x5, "owc0"),		/* ONEWIRE */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 4)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 5),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm5"),		/* DATA0 */
		SUNXI_FUNCTION(0x3, "rmii"),		/* MS */
		SUNXI_FUNCTION(0x4, "twi2"),		/* MS */
		SUNXI_FUNCTION(0x5, "uart2"),		/* TX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 5)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 6),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm6"),		/* DATA1 */
		SUNXI_FUNCTION(0x3, "rmii"),		/* CK */
		SUNXI_FUNCTION(0x4, "twi2"),		/* MS */
		SUNXI_FUNCTION(0x5, "uart2"),		/* RX */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 6)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 7),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm7"),		/* DATA2 */
		SUNXI_FUNCTION(0x3, "rmii"),		/* TX */
		SUNXI_FUNCTION(0x4, "uart0"),		/* TX */
		SUNXI_FUNCTION(0x5, "uart2"),		/* RTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 7)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 8),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm8"),		/* DATA3 */
		SUNXI_FUNCTION(0x3, "rmii"),		/* RX */
		SUNXI_FUNCTION(0x4, "uart0"),		/* TX */
		SUNXI_FUNCTION(0x5, "uart2"),		/* CTS */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 8)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 9),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "pwm9"),		/* DATA3 */
		SUNXI_FUNCTION(0x3, "rmii"),		/* D0 */
		SUNXI_FUNCTION(0x4, "twi3"),		/* D0 */
		SUNXI_FUNCTION(0x5, "uart0"),		/* SCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 9)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 10),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "rmii"),		/* D1 */
		SUNXI_FUNCTION(0x4, "twi3"),		/* D0 */
		SUNXI_FUNCTION(0x5, "uart0"),		/* SDA */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 10)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 11),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "jtag"),
		SUNXI_FUNCTION(0x3, "rmii"),
		SUNXI_FUNCTION(0x4, "spi1"),		/* CLK */
		SUNXI_FUNCTION(0x5, "twi2"),		/* SCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 11)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 12),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "jtag"),
		SUNXI_FUNCTION(0x3, "rmii"),
		SUNXI_FUNCTION(0x4, "spi1"),		/* MOSI */
		SUNXI_FUNCTION(0x5, "twi2"),		/* SDA */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 12)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 13),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "jtag"),
		SUNXI_FUNCTION(0x3, "mdc"),		/* SCL */
		SUNXI_FUNCTION(0x4, "spi1"),		/* MISO */
		SUNXI_FUNCTION(0x5, "twi3"),		/* SCK */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 13)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 14),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "jtag"),
		SUNXI_FUNCTION(0x3, "mdio"),		/* SDA */
		SUNXI_FUNCTION(0x4, "spi1"),		/* CS0 */
		SUNXI_FUNCTION(0x5, "twi3"),		/* SDA */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 14)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(H, 15),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x3, "ephy_25m"),		/* CEC */
		SUNXI_FUNCTION(0x4, "spi1"),		/* CS1 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 5, 15)),
	/* HOLE */
	SUNXI_PIN(SUNXI_PINCTRL_PIN(I, 0),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi_mclk0"),		/* MASTERCLK0 */
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 6, 0)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(I, 1),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi_sm_hs"),		/* SM_VS*/
		SUNXI_FUNCTION(0x4, "spi2"),		/* SM_VS*/
		SUNXI_FUNCTION(0x5, "twi1"),		/* SDA*/
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 6, 1)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(I, 2),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x2, "csi_sm_vs"),		/* MASTERCLK0*/
		SUNXI_FUNCTION(0x4, "spi2"),		/* SM_VS*/
		SUNXI_FUNCTION(0x5, "twi1"),		/* SDA*/
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 6, 2)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(I, 3),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x4, "spi2"),		/* CLK*/
		SUNXI_FUNCTION(0x5, "twi0"),		/* SCK*/
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 6, 3)),
	SUNXI_PIN(SUNXI_PINCTRL_PIN(I, 4),
		SUNXI_FUNCTION(0x0, "gpio_in"),
		SUNXI_FUNCTION(0x1, "gpio_out"),
		SUNXI_FUNCTION(0x4, "spi2"),		/* MOSI*/
		SUNXI_FUNCTION(0x5, "twi0"),		/* SDA*/
		SUNXI_FUNCTION(0x7, "io_disabled"),
		SUNXI_FUNCTION_IRQ_BANK(0x6, 6, 4)),
};

static const unsigned sun8iw19p1_irq_bank_base[] = {
	SUNXI_PIO_BANK_BASE(PC_BASE, 0),
	SUNXI_PIO_BANK_BASE(PD_BASE, 1),
	SUNXI_PIO_BANK_BASE(PE_BASE, 2),
	SUNXI_PIO_BANK_BASE(PF_BASE, 3),
	SUNXI_PIO_BANK_BASE(PG_BASE, 4),
	SUNXI_PIO_BANK_BASE(PH_BASE, 5),
	SUNXI_PIO_BANK_BASE(PI_BASE, 6),
};

static const unsigned sun8iw19p1_bank_base[] = {
	SUNXI_PIO_BANK_BASE(PB_BASE, 0),
	SUNXI_PIO_BANK_BASE(PC_BASE, 1),
	SUNXI_PIO_BANK_BASE(PD_BASE, 2),
	SUNXI_PIO_BANK_BASE(PE_BASE, 3),
	SUNXI_PIO_BANK_BASE(PF_BASE, 4),
	SUNXI_PIO_BANK_BASE(PG_BASE, 5),
	SUNXI_PIO_BANK_BASE(PH_BASE, 6),
	SUNXI_PIO_BANK_BASE(PI_BASE, 7),
};

static const struct sunxi_pinctrl_desc sun8iw19p1_pinctrl_data = {
	.pins = sun8iw19p1_pins,
	.npins = ARRAY_SIZE(sun8iw19p1_pins),
	.pin_base = 0,
	.banks = ARRAY_SIZE(sun8iw19p1_bank_base),
	.bank_base = sun8iw19p1_bank_base,
	.irq_banks = ARRAY_SIZE(sun8iw19p1_irq_bank_base),
	.irq_bank_base = sun8iw19p1_irq_bank_base,
};

static int sun8iw19p1_pinctrl_probe(struct platform_device *pdev)
{
	return sunxi_pinctrl_init(pdev, &sun8iw19p1_pinctrl_data);
}

static struct of_device_id sun8iw19p1_pinctrl_match[] = {
	{ .compatible = "allwinner,sun8iw19p1-pinctrl", },
	{}
};
MODULE_DEVICE_TABLE(of, sun8iw19p1_pinctrl_match);

static struct platform_driver sun8iw19p1_pinctrl_driver = {
	.probe	= sun8iw19p1_pinctrl_probe,
	.driver	= {
		.name		= "sun8iw19p1-pinctrl",
		.owner		= THIS_MODULE,
		.of_match_table	= sun8iw19p1_pinctrl_match,
		.pm		= &sunxi_pinctrl_pm_ops,
	},
};

static int __init sun8iw19p1_pio_init(void)
{
	int ret;
	ret = platform_driver_register(&sun8iw19p1_pinctrl_driver);
	if (IS_ERR_VALUE(ret)) {
		pr_err("register sun8iw19p1 pio controller failed\n");
		return -EINVAL;
	}
	return 0;
}
postcore_initcall(sun8iw19p1_pio_init);

MODULE_AUTHOR("Huanghuafeng<huafenghuang@allwinnertech.com>");
MODULE_DESCRIPTION("Allwinner sun8iw19p1 pio pinctrl driver");
MODULE_LICENSE("GPL");
