/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <drv/Usbd.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Usbd::Usbd(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mUsbClass = nullptr;
}

error_t Usbd::initialize(UsbClass &obj)
{
	uint16_t offset = 0, maxPayload;
	mUsbClass = &obj;

	mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x6D0
	mDev->SE0 |= USBD_SE0_SE0_Msk;

	thread::delay(20);

	mDev->SE0 &= ~USBD_SE0_SE0_Msk;
	mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_DPPUEN_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x7D0
	mDev->INTSTS = USBD_INTSTS_USBIF_Msk | USBD_INTSTS_BUSIF_Msk | USBD_INTSTS_VBDETIF_Msk | USBD_INTSTS_NEVWKIF_Msk;
	mDev->INTEN = USBD_INTEN_USBIEN_Msk | USBD_INTEN_BUSIEN_Msk | USBD_INTEN_VBDETIEN_Msk | USBD_INTEN_WKEN_Msk;

	return error_t::ERROR_NONE;
}

void Usbd::isr(void)
{
	uint32_t intsts = mDev->INTSTS, bus = mDev->ATTR;

	if(intsts & USBD_INTSTS_BUSIF_Msk)
	{
		mDev->INTSTS = USBD_INTSTS_BUSIF_Msk;

		if(bus & USBD_ATTR_USBRST_Msk) // USB Reset
		{
			mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_DPPUEN_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x7D0

			for(uint32_t i = 0; i < USBD_MAX_EP; i++)
			{
				mDev->EP[i].CFG &= ~USBD_CFG_DSQSYNC_Msk;
			}

			mDev->FADDR = 0;
		}
	}
}

#endif

