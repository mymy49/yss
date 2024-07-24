/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7)

#include <yss/instance.h>
#include <yss.h>
#include <config.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#define USB_OTG_FS_DEV				(YSS_USB_Device_TypeDef*)((uint32_t)USB_OTG_FS + (uint32_t)USB_OTG_DEVICE_BASE)
#define USB_OTG_HS_DEV				(YSS_USB_Device_TypeDef*)((uint32_t)USB_OTG_HS + (uint32_t)USB_OTG_DEVICE_BASE)

#if USBD1_ENABLE || defined(USB_OTG_FS)
static uint32_t getUsbFsFrequency(void)
{
	return 0;
}

static void enableUsbFsClock(bool en)
{
	clock.lock();
	clock.enableAhb2Clock(RCC_AHB2ENR_OTGFSEN_Pos, en);
	clock.unlock();
}

static void enableUsbFsInterrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(OTG_FS_IRQn, en);
	nvic.unlock();
}

static void resetUsbFs(void)
{
	clock.lock();
	clock.resetAhb2(RCC_AHB2RSTR_OTGFSRST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvUsbFsSetup
{
	enableUsbFsClock,		//void (*clockFunc)(bool en);
	enableUsbFsInterrupt,	//void (*nvicFunc)(bool en);
	resetUsbFs,				//void (*resetFunc)(void);
	getUsbFsFrequency		//uint32_t (*getClockFunc)(void);
};

static const Usbd::setup_t gUsbFsSetup
{
	USB_OTG_FS,		//YSS_USB_TypeDef *global;
	USB_OTG_FS_DEV,	//YSS_USB_Device_TypeDef *dev;
	5				//uint8_t endpointCount;
};

Usbd usbd1(gDrvUsbFsSetup, gUsbFsSetup);

#endif

#endif

