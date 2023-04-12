/*
 * linux/arch/arm/mach-tegra/include/mach/pinmux-t11.h
 *
 * Copyright (C) 2010 Google, Inc.
 * Copyright (C) 2011-2013 NVIDIA CORPORATION.  All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MACH_TEGRA_PINMUX_T11_H
#define __MACH_TEGRA_PINMUX_T11_H

#include <mach/pinmux.h>

#define DEFAULT_DRIVE(_name)					\
	{							\
		.pingroup = TEGRA_DRIVE_PINGROUP_##_name,	\
		.hsm = TEGRA_HSM_DISABLE,			\
		.schmitt = TEGRA_SCHMITT_ENABLE,		\
		.drive = TEGRA_DRIVE_DIV_1,			\
		.pull_down = TEGRA_PULL_31,			\
		.pull_up = TEGRA_PULL_31,			\
		.slew_rising = TEGRA_SLEW_SLOWEST,		\
		.slew_falling = TEGRA_SLEW_SLOWEST,		\
	}
/* Setting the drive strength of pins
 * hsm: Enable High speed mode (ENABLE/DISABLE)
 * Schimit: Enable/disable schimit (ENABLE/DISABLE)
 * drive: low power mode (DIV_1, DIV_2, DIV_4, DIV_8)
 * pulldn_drive - drive down (falling edge) - Driver Output Pull-Down drive
 *                strength code. Value from 0 to 31.
 * pullup_drive - drive up (rising edge)  - Driver Output Pull-Up drive
 *                strength code. Value from 0 to 31.
 * pulldn_slew -  Driver Output Pull-Up slew control code  - 2bit code
 *                code 11 is least slewing of signal. code 00 is highest
 *                slewing of the signal.
 *                Value - FASTEST, FAST, SLOW, SLOWEST
 * pullup_slew -  Driver Output Pull-Down slew control code -
 *                code 11 is least slewing of signal. code 00 is highest
 *                slewing of the signal.
 *                Value - FASTEST, FAST, SLOW, SLOWEST
 */
#define SET_DRIVE(_name, _hsm, _schmitt, _drive, _pulldn_drive, _pullup_drive, _pulldn_slew, _pullup_slew) \
	{                                               \
		.pingroup = TEGRA_DRIVE_PINGROUP_##_name,   \
		.hsm = TEGRA_HSM_##_hsm,                    \
		.schmitt = TEGRA_SCHMITT_##_schmitt,        \
		.drive = TEGRA_DRIVE_##_drive,              \
		.pull_down = TEGRA_PULL_##_pulldn_drive,    \
		.pull_up = TEGRA_PULL_##_pullup_drive,		\
		.slew_rising = TEGRA_SLEW_##_pulldn_slew,   \
		.slew_falling = TEGRA_SLEW_##_pullup_slew,	\
	}

/* Setting the drive strength of pins
 * hsm: Enable High speed mode (ENABLE/DISABLE)
 * Schimit: Enable/disable schimit (ENABLE/DISABLE)
 * drive: low power mode (DIV_1, DIV_2, DIV_4, DIV_8)
 * pulldn_drive - drive down (falling edge) - Driver Output Pull-Down drive
 *                strength code. Value from 0 to 31.
 * pullup_drive - drive up (rising edge)  - Driver Output Pull-Up drive
 *                strength code. Value from 0 to 31.
 * pulldn_slew -  Driver Output Pull-Up slew control code  - 2bit code
 *                code 11 is least slewing of signal. code 00 is highest
 *                slewing of the signal.
 *                Value - FASTEST, FAST, SLOW, SLOWEST
 * pullup_slew -  Driver Output Pull-Down slew control code -
 *                code 11 is least slewing of signal. code 00 is highest
 *                slewing of the signal.
 *                Value - FASTEST, FAST, SLOW, SLOWEST
 * drive_type - Drive type to be used depending on the resistors.
 */

#define SET_DRIVE_WITH_TYPE(_name, _hsm, _schmitt, _drive, _pulldn_drive,\
		_pullup_drive, _pulldn_slew, _pullup_slew, _drive_type)	\
	{								\
		.pingroup = TEGRA_DRIVE_PINGROUP_##_name,		\
		.hsm = TEGRA_HSM_##_hsm,				\
		.schmitt = TEGRA_SCHMITT_##_schmitt,			\
		.drive = TEGRA_DRIVE_##_drive,				\
		.pull_down = TEGRA_PULL_##_pulldn_drive,		\
		.pull_up = TEGRA_PULL_##_pullup_drive,			\
		.slew_rising = TEGRA_SLEW_##_pulldn_slew,		\
		.slew_falling = TEGRA_SLEW_##_pullup_slew,		\
		.drive_type = TEGRA_DRIVE_TYPE_##_drive_type,		\
	}

#define DEFAULT_PINMUX(_pingroup, _mux, _pupd, _tri, _io)	\
	{							\
		.pingroup	= TEGRA_PINGROUP_##_pingroup,	\
		.func		= TEGRA_MUX_##_mux,		\
		.pupd		= TEGRA_PUPD_##_pupd,		\
		.tristate	= TEGRA_TRI_##_tri,		\
		.io		= TEGRA_PIN_##_io,		\
		.lock		= TEGRA_PIN_LOCK_DEFAULT,	\
		.od		= TEGRA_PIN_OD_DEFAULT,		\
		.ioreset	= TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define I2C_PINMUX(_pingroup, _mux, _pupd, _tri, _io, _lock, _od) \
	{							\
		.pingroup	= TEGRA_PINGROUP_##_pingroup,	\
		.func		= TEGRA_MUX_##_mux,		\
		.pupd		= TEGRA_PUPD_##_pupd,		\
		.tristate	= TEGRA_TRI_##_tri,		\
		.io		= TEGRA_PIN_##_io,		\
		.lock		= TEGRA_PIN_LOCK_##_lock,	\
		.od		= TEGRA_PIN_OD_##_od,		\
		.ioreset	= TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define DDC_PINMUX(_pingroup, _mux, _pupd, _tri, _io, _lock, _rcv_sel) \
	{							\
		.pingroup	= TEGRA_PINGROUP_##_pingroup,	\
		.func		= TEGRA_MUX_##_mux,		\
		.pupd		= TEGRA_PUPD_##_pupd,		\
		.tristate	= TEGRA_TRI_##_tri,		\
		.io		= TEGRA_PIN_##_io,		\
		.lock		= TEGRA_PIN_LOCK_##_lock,	\
		.rcv_sel	= TEGRA_PIN_RCV_SEL_##_rcv_sel,		\
		.ioreset	= TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define VI_PINMUX(_pingroup, _mux, _pupd, _tri, _io, _lock, _ioreset) \
	{							\
		.pingroup	= TEGRA_PINGROUP_##_pingroup,	\
		.func		= TEGRA_MUX_##_mux,		\
		.pupd		= TEGRA_PUPD_##_pupd,		\
		.tristate	= TEGRA_TRI_##_tri,		\
		.io		= TEGRA_PIN_##_io,		\
		.lock		= TEGRA_PIN_LOCK_##_lock,	\
		.od		= TEGRA_PIN_OD_DEFAULT,		\
		.ioreset	= TEGRA_PIN_IO_RESET_##_ioreset	\
	}

#define CEC_PINMUX(_pingroup, _mux, _pupd, _tri, _io, _lock, _od)   \
	{							\
		.pingroup   = TEGRA_PINGROUP_##_pingroup,	\
		.func       = TEGRA_MUX_##_mux,			\
		.pupd       = TEGRA_PUPD_##_pupd,		\
		.tristate   = TEGRA_TRI_##_tri,			\
		.io         = TEGRA_PIN_##_io,			\
		.lock       = TEGRA_PIN_LOCK_##_lock,		\
		.od         = TEGRA_PIN_OD_##_od,		\
		.ioreset    = TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define GPIO_PINMUX(_pingroup, _pupd, _tri, _io, _od)	\
	{							\
		.pingroup   = TEGRA_PINGROUP_##_pingroup,	\
		.func       = TEGRA_MUX_SAFE,			\
		.pupd       = TEGRA_PUPD_##_pupd,		\
		.tristate   = TEGRA_TRI_##_tri,			\
		.io         = TEGRA_PIN_##_io,			\
		.lock       = TEGRA_PIN_LOCK_DEFAULT,		\
		.od         = TEGRA_PIN_OD_##_od,		\
		.ioreset    = TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define UNUSED_PINMUX(_pingroup)	\
	{							\
		.pingroup   = TEGRA_PINGROUP_##_pingroup,	\
		.func       = TEGRA_MUX_SAFE,			\
		.pupd       = TEGRA_PUPD_PULL_DOWN,		\
		.tristate   = TEGRA_TRI_TRISTATE,		\
		.io         = TEGRA_PIN_OUTPUT,			\
		.lock       = TEGRA_PIN_LOCK_DEFAULT,		\
		.od         = TEGRA_PIN_OD_DEFAULT,		\
		.ioreset    = TEGRA_PIN_IO_RESET_DEFAULT,	\
	}

#define USB_PINMUX CEC_PINMUX

#define GPIO_INIT_PIN_MODE(_gpio, _is_input, _value)	\
	{					\
		.gpio_nr	= _gpio,	\
		.is_input	= _is_input,	\
		.value		= _value,	\
	}

void tegra11x_default_pinmux(void);

enum tegra_pingroup {
	TEGRA_PINGROUP_ULPI_DATA0,
	TEGRA_PINGROUP_ULPI_DATA1,
	TEGRA_PINGROUP_ULPI_DATA2,
	TEGRA_PINGROUP_ULPI_DATA3,
	TEGRA_PINGROUP_ULPI_DATA4,
	TEGRA_PINGROUP_ULPI_DATA5,
	TEGRA_PINGROUP_ULPI_DATA6,
	TEGRA_PINGROUP_ULPI_DATA7,
	TEGRA_PINGROUP_ULPI_CLK,
	TEGRA_PINGROUP_ULPI_DIR,
	TEGRA_PINGROUP_ULPI_NXT,
	TEGRA_PINGROUP_ULPI_STP,
	TEGRA_PINGROUP_DAP3_FS,
	TEGRA_PINGROUP_DAP3_DIN,
	TEGRA_PINGROUP_DAP3_DOUT,
	TEGRA_PINGROUP_DAP3_SCLK,
	TEGRA_PINGROUP_GPIO_PV0,
	TEGRA_PINGROUP_GPIO_PV1,
	TEGRA_PINGROUP_SDMMC1_CLK,
	TEGRA_PINGROUP_SDMMC1_CMD,
	TEGRA_PINGROUP_SDMMC1_DAT3,
	TEGRA_PINGROUP_SDMMC1_DAT2,
	TEGRA_PINGROUP_SDMMC1_DAT1,
	TEGRA_PINGROUP_SDMMC1_DAT0,
	TEGRA_PINGROUP_CLK2_OUT,
	TEGRA_PINGROUP_CLK2_REQ,
	TEGRA_PINGROUP_HDMI_INT,
	TEGRA_PINGROUP_DDC_SCL,
	TEGRA_PINGROUP_DDC_SDA,
	TEGRA_PINGROUP_UART2_RXD,
	TEGRA_PINGROUP_UART2_TXD,
	TEGRA_PINGROUP_UART2_RTS_N,
	TEGRA_PINGROUP_UART2_CTS_N,
	TEGRA_PINGROUP_UART3_TXD,
	TEGRA_PINGROUP_UART3_RXD,
	TEGRA_PINGROUP_UART3_CTS_N,
	TEGRA_PINGROUP_UART3_RTS_N,
	TEGRA_PINGROUP_GPIO_PU0,
	TEGRA_PINGROUP_GPIO_PU1,
	TEGRA_PINGROUP_GPIO_PU2,
	TEGRA_PINGROUP_GPIO_PU3,
	TEGRA_PINGROUP_GPIO_PU4,
	TEGRA_PINGROUP_GPIO_PU5,
	TEGRA_PINGROUP_GPIO_PU6,
	TEGRA_PINGROUP_GEN1_I2C_SDA,
	TEGRA_PINGROUP_GEN1_I2C_SCL,
	TEGRA_PINGROUP_DAP4_FS,
	TEGRA_PINGROUP_DAP4_DIN,
	TEGRA_PINGROUP_DAP4_DOUT,
	TEGRA_PINGROUP_DAP4_SCLK,
	TEGRA_PINGROUP_CLK3_OUT,
	TEGRA_PINGROUP_CLK3_REQ,
	TEGRA_PINGROUP_GMI_WP_N,
	TEGRA_PINGROUP_GMI_IORDY,
	TEGRA_PINGROUP_GMI_WAIT,
	TEGRA_PINGROUP_GMI_ADV_N,
	TEGRA_PINGROUP_GMI_CLK,
	TEGRA_PINGROUP_GMI_CS0_N,
	TEGRA_PINGROUP_GMI_CS1_N,
	TEGRA_PINGROUP_GMI_CS2_N,
	TEGRA_PINGROUP_GMI_CS3_N,
	TEGRA_PINGROUP_GMI_CS4_N,
	TEGRA_PINGROUP_GMI_CS6_N,
	TEGRA_PINGROUP_GMI_CS7_N,
	TEGRA_PINGROUP_GMI_AD0,
	TEGRA_PINGROUP_GMI_AD1,
	TEGRA_PINGROUP_GMI_AD2,
	TEGRA_PINGROUP_GMI_AD3,
	TEGRA_PINGROUP_GMI_AD4,
	TEGRA_PINGROUP_GMI_AD5,
	TEGRA_PINGROUP_GMI_AD6,
	TEGRA_PINGROUP_GMI_AD7,
	TEGRA_PINGROUP_GMI_AD8,
	TEGRA_PINGROUP_GMI_AD9,
	TEGRA_PINGROUP_GMI_AD10,
	TEGRA_PINGROUP_GMI_AD11,
	TEGRA_PINGROUP_GMI_AD12,
	TEGRA_PINGROUP_GMI_AD13,
	TEGRA_PINGROUP_GMI_AD14,
	TEGRA_PINGROUP_GMI_AD15,
	TEGRA_PINGROUP_GMI_A16,
	TEGRA_PINGROUP_GMI_A17,
	TEGRA_PINGROUP_GMI_A18,
	TEGRA_PINGROUP_GMI_A19,
	TEGRA_PINGROUP_GMI_WR_N,
	TEGRA_PINGROUP_GMI_OE_N,
	TEGRA_PINGROUP_GMI_DQS_P,
	TEGRA_PINGROUP_GMI_DQS = TEGRA_PINGROUP_GMI_DQS_P,
	TEGRA_PINGROUP_GMI_RST_N,
	TEGRA_PINGROUP_GEN2_I2C_SCL,
	TEGRA_PINGROUP_GEN2_I2C_SDA,
	TEGRA_PINGROUP_SDMMC4_CLK,
	TEGRA_PINGROUP_SDMMC4_CMD,
	TEGRA_PINGROUP_SDMMC4_DAT0,
	TEGRA_PINGROUP_SDMMC4_DAT1,
	TEGRA_PINGROUP_SDMMC4_DAT2,
	TEGRA_PINGROUP_SDMMC4_DAT3,
	TEGRA_PINGROUP_SDMMC4_DAT4,
	TEGRA_PINGROUP_SDMMC4_DAT5,
	TEGRA_PINGROUP_SDMMC4_DAT6,
	TEGRA_PINGROUP_SDMMC4_DAT7,
	TEGRA_PINGROUP_CAM_MCLK,
	TEGRA_PINGROUP_GPIO_PCC1,
	TEGRA_PINGROUP_GPIO_PBB0,
	TEGRA_PINGROUP_CAM_I2C_SCL,
	TEGRA_PINGROUP_CAM_I2C_SDA,
	TEGRA_PINGROUP_GPIO_PBB3,
	TEGRA_PINGROUP_GPIO_PBB4,
	TEGRA_PINGROUP_GPIO_PBB5,
	TEGRA_PINGROUP_GPIO_PBB6,
	TEGRA_PINGROUP_GPIO_PBB7,
	TEGRA_PINGROUP_GPIO_PCC2,
	TEGRA_PINGROUP_JTAG_RTCK,
	TEGRA_PINGROUP_PWR_I2C_SCL,
	TEGRA_PINGROUP_PWR_I2C_SDA,
	TEGRA_PINGROUP_KB_ROW0,
	TEGRA_PINGROUP_KB_ROW1,
	TEGRA_PINGROUP_KB_ROW2,
	TEGRA_PINGROUP_KB_ROW3,
	TEGRA_PINGROUP_KB_ROW4,
	TEGRA_PINGROUP_KB_ROW5,
	TEGRA_PINGROUP_KB_ROW6,
	TEGRA_PINGROUP_KB_ROW7,
	TEGRA_PINGROUP_KB_ROW8,
	TEGRA_PINGROUP_KB_ROW9,
	TEGRA_PINGROUP_KB_ROW10,
	TEGRA_PINGROUP_KB_COL0,
	TEGRA_PINGROUP_KB_COL1,
	TEGRA_PINGROUP_KB_COL2,
	TEGRA_PINGROUP_KB_COL3,
	TEGRA_PINGROUP_KB_COL4,
	TEGRA_PINGROUP_KB_COL5,
	TEGRA_PINGROUP_KB_COL6,
	TEGRA_PINGROUP_KB_COL7,
	TEGRA_PINGROUP_CLK_32K_OUT,
	TEGRA_PINGROUP_SYS_CLK_REQ,
	TEGRA_PINGROUP_CORE_PWR_REQ,
	TEGRA_PINGROUP_CPU_PWR_REQ,
	TEGRA_PINGROUP_PWR_INT_N,
	TEGRA_PINGROUP_CLK_32K_IN,
	TEGRA_PINGROUP_OWR,
	TEGRA_PINGROUP_DAP1_FS,
	TEGRA_PINGROUP_DAP1_DIN,
	TEGRA_PINGROUP_DAP1_DOUT,
	TEGRA_PINGROUP_DAP1_SCLK,
	TEGRA_PINGROUP_CLK1_REQ,
	TEGRA_PINGROUP_CLK1_OUT,
	TEGRA_PINGROUP_SPDIF_IN,
	TEGRA_PINGROUP_SPDIF_OUT,
	TEGRA_PINGROUP_DAP2_FS,
	TEGRA_PINGROUP_DAP2_DIN,
	TEGRA_PINGROUP_DAP2_DOUT,
	TEGRA_PINGROUP_DAP2_SCLK,
	TEGRA_PINGROUP_DVFS_PWM,
	TEGRA_PINGROUP_GPIO_X1_AUD,
	TEGRA_PINGROUP_GPIO_X3_AUD,
	TEGRA_PINGROUP_DVFS_CLK,
	TEGRA_PINGROUP_GPIO_X4_AUD,
	TEGRA_PINGROUP_GPIO_X5_AUD,
	TEGRA_PINGROUP_GPIO_X6_AUD,
	TEGRA_PINGROUP_GPIO_X7_AUD,
	TEGRA_PINGROUP_SDMMC3_CLK,
	TEGRA_PINGROUP_SDMMC3_CMD,
	TEGRA_PINGROUP_SDMMC3_DAT0,
	TEGRA_PINGROUP_SDMMC3_DAT1,
	TEGRA_PINGROUP_SDMMC3_DAT2,
	TEGRA_PINGROUP_SDMMC3_DAT3,
	TEGRA_PINGROUP_HDMI_CEC,
	TEGRA_PINGROUP_SDMMC1_WP_N,
	TEGRA_PINGROUP_SDMMC3_CD_N,
	TEGRA_PINGROUP_GPIO_W2_AUD,
	TEGRA_PINGROUP_GPIO_W3_AUD,
	TEGRA_PINGROUP_USB_VBUS_EN0,
	TEGRA_PINGROUP_USB_VBUS_EN1,
	TEGRA_PINGROUP_SDMMC3_CLK_LB_IN,
	TEGRA_PINGROUP_SDMMC3_CLK_LB_OUT,
	TEGRA_PINGROUP_NAND_GMI_CLK_LB,
	TEGRA_PINGROUP_RESET_OUT_N,
	TEGRA_MAX_PINGROUP,
};

enum tegra_drive_pingroup {
	TEGRA_DRIVE_PINGROUP_AO1 = 0,
	TEGRA_DRIVE_PINGROUP_AO2,
	TEGRA_DRIVE_PINGROUP_AT1,
	TEGRA_DRIVE_PINGROUP_AT2,
	TEGRA_DRIVE_PINGROUP_AT3,
	TEGRA_DRIVE_PINGROUP_AT4,
	TEGRA_DRIVE_PINGROUP_AT5,
	TEGRA_DRIVE_PINGROUP_CDEV1,
	TEGRA_DRIVE_PINGROUP_CDEV2,
	TEGRA_DRIVE_PINGROUP_DAP1,
	TEGRA_DRIVE_PINGROUP_DAP2,
	TEGRA_DRIVE_PINGROUP_DAP3,
	TEGRA_DRIVE_PINGROUP_DAP4,
	TEGRA_DRIVE_PINGROUP_DBG,
	TEGRA_DRIVE_PINGROUP_SDIO3,
	TEGRA_DRIVE_PINGROUP_SPI,
	TEGRA_DRIVE_PINGROUP_UAA,
	TEGRA_DRIVE_PINGROUP_UAB,
	TEGRA_DRIVE_PINGROUP_UART2,
	TEGRA_DRIVE_PINGROUP_UART3,
	TEGRA_DRIVE_PINGROUP_SDIO1,
	TEGRA_DRIVE_PINGROUP_DDC,
	TEGRA_DRIVE_PINGROUP_GMA,
	TEGRA_DRIVE_PINGROUP_GME,
	TEGRA_DRIVE_PINGROUP_GMF,
	TEGRA_DRIVE_PINGROUP_GMG,
	TEGRA_DRIVE_PINGROUP_GMH,
	TEGRA_DRIVE_PINGROUP_OWR,
	TEGRA_DRIVE_PINGROUP_UAD,
	TEGRA_DRIVE_PINGROUP_DEV3,
	TEGRA_DRIVE_PINGROUP_CEC,
	TEGRA_DRIVE_PINGROUP_AT6,
	TEGRA_DRIVE_PINGROUP_DAP5,
	TEGRA_DRIVE_PINGROUP_VBUS,
	TEGRA_MAX_DRIVE_PINGROUP,
};

#ifdef CONFIG_PM_SLEEP
void tegra11x_set_sleep_pinmux(struct tegra_pingroup_config *config, int size);
#else
static inline void
tegra11x_set_sleep_pinmux(struct tegra_pingroup_config *config, int size) {}
#endif
#endif
