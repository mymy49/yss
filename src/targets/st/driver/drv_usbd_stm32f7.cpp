/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7)

#include <drv/peripheral.h>
#include <drv/Usbd.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>
#include <util/Timeout.h>

namespace FRAME_INTERVAL
{
	enum
	{
		INTERVAL80 = 0x0,
		INTERVAL85 = 0x1,
		INTERVAL90 = 0x2,
		INTERVAL95 = 0x3,
	};
}

namespace DSPD
{
	enum
	{
		FULL_SPEED_HIGH = 0x0,
		FULL_SPEED_FULL_EXT_PHY = 0x1,
		FULL_SPEED_FULL_INT_PHY = 0x3
	};
}

error_t flushTxFifo(YSS_USB_TypeDef *dev, unsigned char num)
{
	Timeout timeout;

	dev->GRSTCTL = ( USB_OTG_GRSTCTL_TXFFLSH_Msk | (uint32_t)(num << 6));

	timeout.reset(100);
	while(getBitData(dev->GRSTCTL, USB_OTG_GRSTCTL_TXFFLSH_Pos))
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
	}

	return error_t::ERROR_NONE;
}

error_t flushRxFifo(YSS_USB_TypeDef *dev)
{
	Timeout timeout;

	dev->GRSTCTL = USB_OTG_GRSTCTL_RXFFLSH_Msk;

	timeout.reset(100);
	while(getBitData(dev->GRSTCTL, USB_OTG_GRSTCTL_RXFFLSH_Pos))
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
	}

	return error_t::ERROR_NONE;
}

void disableEndPoint(YSS_USB_TypeDef *dev, uint32_t num)
{
	USB_OTG_INEndpointTypeDef *in = (USB_OTG_INEndpointTypeDef*)((uint32_t)dev + USB_OTG_IN_ENDPOINT_BASE + num * 0x20);
	USB_OTG_OUTEndpointTypeDef *out = (USB_OTG_OUTEndpointTypeDef*)((uint32_t)dev + USB_OTG_OUT_ENDPOINT_BASE + num * 0x20);

	if(getBitData(in->DIEPCTL, USB_OTG_DIEPCTL_EPENA_Pos))
	{
		setBitData(in->DIEPCTL, true, USB_OTG_DIEPCTL_EPDIS_Pos);
		setBitData(in->DIEPCTL, true, USB_OTG_DIEPCTL_SNAK_Pos);
	}
	else
	{
		in->DIEPCTL = 0;
	}

	if(getBitData(out->DOEPCTL, USB_OTG_DOEPCTL_EPENA_Pos))
	{
		setBitData(out->DOEPCTL, true, USB_OTG_DOEPCTL_EPDIS_Pos);
		setBitData(out->DOEPCTL, true, USB_OTG_DOEPCTL_SNAK_Pos);
	}
	else
	{
		out->DOEPCTL = 0;
	}

	in->DIEPTSIZ = 0;
	in->DIEPINT = 0xff;
	out->DOEPTSIZ = 0;
	out->DOEPINT = 0xff;
}

//error_t initalizeFifo(

Usbd::Usbd(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mGlobal = setup.global;
	mDev = setup.dev;
	mEndpointCount = setup.endpointCount;
}

error_t Usbd::initialize(const config_t confg)
{
	error_t result;
	Timeout timeout;
	uint32_t size, offset;
	volatile uint32_t *pcgcctl = (uint32_t*)((uint32_t)mDev + (uint32_t)USB_OTG_PCGCCTL_BASE);

	// USB 트랜시버를 내장으로 선택
	setBitData(mGlobal->GUSBCFG, true, USB_OTG_GUSBCFG_PHYSEL_Pos);
	
	timeout.reset(100);
	while(!getBitData(mGlobal->GRSTCTL, USB_OTG_GRSTCTL_AHBIDL_Pos))
	{
		if(timeout.isTimeout())
			return error_t::BUSY;
	}

	// USB CORE Soft 리셋
	setBitData(mGlobal->GRSTCTL, true, USB_OTG_GRSTCTL_CSRST_Pos);

	timeout.reset(100);
	while(!getBitData(mGlobal->GRSTCTL, USB_OTG_GRSTCTL_AHBIDL_Pos))
	{
		if(timeout.isTimeout())
			return error_t::BUSY;
	}

	// USB PowerDown 제어
	setBitData(mGlobal->GCCFG, true, USB_OTG_GCCFG_PWRDWN_Pos);

	// USB Device Mode로 설정
	setBitData(mGlobal->GUSBCFG, true, USB_OTG_GUSBCFG_FDMOD_Pos);

	thread::delay(50);
	
	// Tx EP FIFO 설정값 리셋
	for(uint8_t i = 0; i < mEndpointCount; i++)
	{
		mGlobal->DIEPTXF[i] = 0;
	}
	
	// 강제로 USB-B 타입 정의
	setBitData(mGlobal->GOTGCTL, true, USB_OTG_GOTGCTL_BVALOEN_Pos);
	setBitData(mGlobal->GOTGCTL, true, USB_OTG_GOTGCTL_BVALOVAL_Pos);

	// PHY Clock 재시작
	*pcgcctl = 0;
	
	setFieldData(mDev->DCFG, USB_OTG_DCFG_PFIVL_Msk, FRAME_INTERVAL::INTERVAL80, USB_OTG_DCFG_PFIVL_Pos);
	setFieldData(mDev->DCFG, USB_OTG_DCFG_DSPD_Msk, DSPD::FULL_SPEED_FULL_INT_PHY, USB_OTG_DCFG_DSPD_Pos);

	// Flush the FIFOs
	result = flushTxFifo(mGlobal, 0x10);
	if(result != error_t::ERROR_NONE)
		return result;
	
	result = flushRxFifo(mGlobal);
	if(result != error_t::ERROR_NONE)
		return result;

	// Clear all pending Device Interrupts
	mDev->DIEPMSK = 0;
	mDev->DOEPMSK = 0;
	mDev->DAINT = 0xFFFFFFFF;
	mDev->DAINTMSK = 0;

	for(uint32_t i = 0; i < mEndpointCount; i++)
		disableEndPoint(mGlobal, i);

	mDev->DIEPMSK &= ~(USB_OTG_DIEPMSK_TXFURM);
	
	// Disable all interrupts.
	mGlobal->GINTMSK = 0;

	// Clear any pending interrupts
	mGlobal->GINTSTS = 0xBFFFFFFF;

	// Enable the common interrupts
	mGlobal->GINTMSK |= USB_OTG_GINTMSK_RXFLVLM_Msk | 
						USB_OTG_GINTMSK_USBRST_Msk | 
						USB_OTG_GINTMSK_ENUMDNEM_Msk | 
						USB_OTG_GINTMSK_OEPINT_Msk | 
						USB_OTG_GINTMSK_IEPINT_Msk | 
						USB_OTG_GINTMSK_USBSUSPM_Msk;
	
	setBitData(mDev->DCTL, true, USB_OTG_DCTL_SDIS_Pos);

	// FIFO 버퍼 설정


	return error_t::ERROR_NONE;
}

#endif

