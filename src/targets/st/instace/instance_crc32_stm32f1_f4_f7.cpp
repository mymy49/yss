/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1)

#include <yss/instance.h>
#include <config.h>
#include <drv/peripheral.h>
#include <targets/st/bitfield.h>

#if defined(CRC) && CRC32_ENABLE
static void setClockEn(bool en)
{
	clock.lock();
#if defined(STM32F4) || defined(STM32F7)
	clock.enableAhb1Clock(RCC_AHB1ENR_CRCEN_Pos);
#elif defined(STM32F1)
	clock.enableAhb1Clock(RCC_AHBENR_CRCEN_Pos);
#endif
	clock.unlock();
}

static const Drv::setup_t gDrvConfig
{
	setClockEn,	//void (*clockFunc)(bool en);
	0,			//void (*nvicFunc)(bool en);
	0,			//void (*resetFunc)(void);
	0			//uint32_t (*getClockFunc)(void);
};

Crc32 crc32((YSS_CRC32_Dev*)CRC, gDrvConfig);
#endif

#endif

