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
#include <string.h>
#include <yss/debug.h>

Usbd::Usbd(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mUsbClass = nullptr;
	mNewAddressUpdateFlag = false;

	memset(mMaxPayload, 0x00, sizeof(mMaxPayload));
	memset(mInEpAllocTable, 0xFF, sizeof(mInEpAllocTable));
	memset(mOutEpAllocTable, 0xFF, sizeof(mOutEpAllocTable));
}

error_t Usbd::initialize(UsbClass &obj)
{
	uint8_t epCount, state, index = 0, ep;
	uint16_t offset = 0, maxPayload, buf;
	mUsbClass = &obj;
	UsbClass::epDesc_t epd;

	// unlock	
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	SYS->USBPHY &= ~SYS_USBPHY_USBROLE_Msk;
	SYS->USBPHY |= SYS_USBPHY_USBEN_Msk;

	// lock
	SYS->REGLCTL = 0x00;

	// USBD Open	
	mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x6D0
	mDev->SE0 |= USBD_SE0_SE0_Msk;

	// EP Setup
	// Setup
	maxPayload = 8;
	mDev->STBUFSEG = offset;
	mSetupRxBuffer = &((uint8_t*)mDev)[0x100 + offset];
	
	offset += maxPayload;
	maxPayload = 64;
	mDev->EP[index].BUFSEG = offset;
	mDev->EP[index].CFG = 2 << USBD_CFG_STATE_Pos | 0;
	mInEpAllocTable[0] = index;
	mMaxPayload[index++] = maxPayload;

	offset += maxPayload;
	maxPayload = 64;
	mDev->EP[index].BUFSEG = offset;
	mDev->EP[index].CFG = 1 << USBD_CFG_STATE_Pos | 0;
	mOutEpAllocTable[0] = index;
	mDev->EP[index].MXPLD = maxPayload; // OUT 수신 준비
	mMaxPayload[index++] = maxPayload;

	epCount = obj.getUsingEpCount();

	for(uint8_t i = 0; i < epCount; i++)
	{
		obj.getEpDescriptor(i, &epd);
		ep = epd.bEndpointAddress & 0xF;

		if(epd.bEndpointAddress & 0x80)
			state = 2;
		else
			state = 1;

		offset += maxPayload;
		maxPayload = 64;
		mDev->EP[index].BUFSEG = offset;
		if(epd.bEndpointAddress & 0x80)
		{
			mDev->EP[index].CFG = 2 << USBD_CFG_STATE_Pos | ep;
			mOutEpAllocTable[ep] = index;
		}
		else
		{
			mDev->EP[index].CFG = 1 << USBD_CFG_STATE_Pos | ep;
			mOutEpAllocTable[ep] = index;
		}
		mMaxPayload[index++] = maxPayload;
	}

	// USBD Start
	mDev->SE0 &= ~USBD_SE0_SE0_Msk;
	mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_DPPUEN_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x7D0
	mDev->INTSTS = USBD_INTSTS_USBIF_Msk | USBD_INTSTS_BUSIF_Msk | USBD_INTSTS_VBDETIF_Msk | USBD_INTSTS_NEVWKIF_Msk;
	mDev->INTEN = USBD_INTEN_USBIEN_Msk | USBD_INTEN_BUSIEN_Msk | USBD_INTEN_WKEN_Msk;

	mUsbClass->setUsbd(this);

	return error_t::ERROR_NONE;
}

void Usbd::copyBuffer(uint8_t *des, uint8_t *src, uint16_t size)
{
	// USB 버퍼에 바이트 단위 접근만 가능함
	while(size)
	{
		if(size >= 16)
		{
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;

			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			size -= 16;
		}

		if(size >= 8)
		{
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			size -= 8;
		}

		if(size >= 4)
		{
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			*des++ = *src++;
			size -= 4;
		}

		if(size >= 2)
		{
			*des++ = *src++;
			*des++ = *src++;
			size -= 2;
		}

		if(size >= 1)
		{
			*des++ = *src++;
			size -= 1;
		}
	}
}

error_t Usbd::send(uint8_t ep, void *src, uint16_t size)
{
	if(ep >= USBD_MAX_EP)
		return error_t::UNSUPPORTED_EP;

	ep = mInEpAllocTable[ep];

	if(ep >= USBD_MAX_EP_BUF)
		return error_t::UNSUPPORTED_EP_BUF;
	
	if(size >= mMaxPayload[ep])
	{
		mInSendingSize = size - mMaxPayload[ep];
		size = mMaxPayload[ep];
		mInSendingBuffer = (uint8_t*)src;
		mInSendingBuffer +=  mMaxPayload[ep];
	}
	else
	{
		mInSendingSize = 0;
	}

	mInSendingCompleteFlag = false;

	mDev->EP[ep].CFG |= USBD_CFG_DSQSYNC_Msk;
	
	copyBuffer((uint8_t*)mSetupRxBuffer + mDev->EP[ep].BUFSEG, (uint8_t*)src, size);

	mDev->EP[ep].MXPLD = size;
	
	if(ep == 0) // Setup Packet
	{
		mDev->EP[1].CFG |= USBD_CFG_DSQSYNC_Msk;
		mDev->EP[1].MXPLD = mMaxPayload[1]; // OUT 수신 준비, ACK
	}

	while(!mInSendingCompleteFlag)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t Usbd::stall(uint8_t ep)
{
	if(ep >= USBD_MAX_EP)
		return error_t::UNSUPPORTED_EP;
	
	if(ep == 0)	
	{
		mDev->EP[0].CFGP |= USBD_CFGP_SSTALL_Msk;
		mDev->EP[1].CFGP |= USBD_CFGP_SSTALL_Msk;
	}
	else
	{
		if(ep >= USBD_MAX_EP_BUF)
			return error_t::UNSUPPORTED_EP_BUF;

		if(mInEpAllocTable[ep] > 0)
			mDev->EP[mInEpAllocTable[ep]].CFGP |= USBD_CFGP_SSTALL_Msk;

		if(mOutEpAllocTable[ep] > 0)
			mDev->EP[mOutEpAllocTable[ep]].CFGP |= USBD_CFGP_SSTALL_Msk;
	}

	return error_t::ERROR_NONE;
}

void Usbd::setAddress(uint8_t address)
{
	mDev->FADDR = address;
}

void Usbd::isr(void)
{
	uint32_t intsts = mDev->INTSTS, bus = mDev->ATTR;
	uint8_t setup[8], buf;

	if(intsts & USBD_INTSTS_BUSIF_Msk)
	{
		mDev->INTSTS = USBD_INTSTS_BUSIF_Msk;

		if(bus & USBD_ATTR_USBRST_Msk) // USB Reset
		{
			mDev->ATTR = USBD_ATTR_BYTEM_Msk | USBD_ATTR_DPPUEN_Msk | USBD_ATTR_PWRDN_Msk | USBD_ATTR_USBEN_Msk | USBD_ATTR_PHYEN_Msk; // 0x7D0

			for(uint32_t i = 0; i < USBD_MAX_EP_BUF; i++)
			{
				mDev->EP[i].CFG &= ~USBD_CFG_DSQSYNC_Msk;
			}

			mDev->FADDR = 0;
		}

		if(bus & USBD_ATTR_SUSPEND_Msk) // Suspend
		{
			mDev->ATTR &= ~USBD_ATTR_PHYEN_Msk;
		}

		if(bus & USBD_ATTR_RESUME_Msk) // Resume
		{
			mDev->ATTR |= USBD_ATTR_PHYEN_Msk;
		}
	}

	if(intsts & USBD_INTSTS_NEVWKIF_Msk) // Wake up
	{
		mDev->INTSTS = USBD_INTSTS_NEVWKIF_Msk;

		mUsbClass->handleWakeup();
	}

	if(intsts & USBD_INTSTS_USBIF_Msk)
	{
		if(intsts & USBD_INTSTS_SETUP_Msk) // Setup Packet
		{
			mDev->INTSTS = USBD_INTSTS_SETUP_Msk;
			mDev->EP[0].CFGP = USBD_CFGP_CLRRDY_Msk;
			mDev->EP[1].CFGP = USBD_CFGP_CLRRDY_Msk;

			copyBuffer(setup, mSetupRxBuffer, 8);
			mUsbClass->handleRxSetupPacket(setup);
		}

		if(intsts & USBD_INTSTS_EPEVT0_Msk) // Control In
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT0_Msk;

			switch(mDev->EPSTS0 & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
				{
					if(mInSendingSize > mMaxPayload[0])
					{
						buf = mMaxPayload[0];
						mInSendingSize -= mMaxPayload[0];
					}
					else
					{
						buf = mInSendingSize;
						mInSendingSize = 0;
					}

					mDev->EP[0].CFG |= USBD_CFG_DSQSYNC_Msk;
	
					copyBuffer((uint8_t*)mSetupRxBuffer + mDev->EP[0].BUFSEG, mInSendingBuffer, buf);
					mInSendingBuffer[0] += buf;

					mDev->EP[0].MXPLD = buf;
				}
				else
				{
					mInSendingCompleteFlag = true;
				}
				break;
			
			case 1 : // IN NAK
				break;
			
			case 2 : // OutPacket Data0 ACK
				
				break;
			
			case 3 : // OutPacket Data0 ACK

				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT1_Msk) // Control Out
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT1_Msk;
		}
	}
}



#endif

