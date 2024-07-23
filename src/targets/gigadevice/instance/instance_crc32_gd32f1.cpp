/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>
#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f1.h>

#if defined(CRC) && defined(CRC32_ENABLE)
static void setClockEn(bool en)
{
	clock.lock();
	clock.enableAhb1Clock(RCC_AHBENR_CRCEN_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvConfig
{
	setClockEn,	//void (*clockFunc)(bool en);
	0,			//void (*nvicFunc)(bool en);
	0,			//void (*resetFunc)(void);
	0			//uint32_t (*getClockFunc)(void);
};

Crc32 crc32((YSS_CRC32_Peri*)CRC, gDrvConfig);
#endif

#endif

