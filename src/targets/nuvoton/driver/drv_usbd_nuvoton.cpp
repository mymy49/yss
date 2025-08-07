/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_SUBFAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <drv/Usbd.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <yss/debug.h>
#include <util/Timeout.h>
#include <string.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M25x_SUBFAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

Usbd::Usbd(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mUsbClass = nullptr;
	mNewAddressUpdateFlag = false;
	mSetupOutDataSize = 0;
	mSetupOutDataFlag = false;

	memset(mMaxPayload, 0x00, sizeof(mMaxPayload));
	memset(mInEpAllocTable, 0xFF, sizeof(mInEpAllocTable));
	memset(mOutEpAllocTable, 0xFF, sizeof(mOutEpAllocTable));
	memset(mOutRxSize, 0x00, sizeof(mOutRxSize));
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
	
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
	SYS->USBPHY &= ~SYS_USBPHY_USBROLE_Msk;
	SYS->USBPHY |= SYS_USBPHY_USBEN_Msk;
#elif defined(__M25x_SUBFAMILY)

#endif

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
	mDev->EP[index].CFG = 2 << USBD_CFG_STATE_Pos | USBD_CFG_CSTALL_Msk;
	mInEpAllocTable[0] = index;
	mMaxPayload[index++] = maxPayload;

	offset += maxPayload;
	maxPayload = 64;
	mDev->EP[index].BUFSEG = offset;
	mDev->EP[index].CFG = 1 << USBD_CFG_STATE_Pos | USBD_CFG_CSTALL_Msk;
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
		maxPayload = epd.wMaxPacketSize;
		mDev->EP[index].BUFSEG = offset;
		if(epd.bEndpointAddress & 0x80)
		{
			mDev->EP[index].CFG = 2 << USBD_CFG_STATE_Pos | ep;
			mInEpAllocTable[ep] = index;
		}
		else
		{
			mDev->EP[index].CFG = 1 << USBD_CFG_STATE_Pos | ep;
			mOutEpAllocTable[ep] = index;
			mDev->EP[index].MXPLD = maxPayload;
		}
		mMaxPayload[index++] = maxPayload;
	}

	if(index < USBD_MAX_EP_BUF)
	{
		offset += maxPayload;
		mDev->EP[index].BUFSEG = offset;
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

error_t Usbd::send(uint8_t ep, void *src, uint16_t size, bool response)
{
	Timeout timeout(200);

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
	
	if(response)
		mDev->EP[ep].CFG |= USBD_CFG_DSQSYNC_Msk;
	
	copyBuffer((uint8_t*)mSetupRxBuffer + mDev->EP[ep].BUFSEG, (uint8_t*)src, size);

	mDev->EP[ep].MXPLD = size;
	
	if(ep == 0) // Setup Packet
	{
		mDev->EP[1].CFG |= USBD_CFG_DSQSYNC_Msk;
		mDev->EP[1].MXPLD = mMaxPayload[1]; // OUT 수신 준비, ACK
	}

	while(!mInSendingCompleteFlag)
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;

		thread::yield();
	}

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

void Usbd::flushSetupOutData(void)
{
	mSetupOutDataSize = 0;
	mSetupOutDataFlag = false;
}

void Usbd::setAddress(uint8_t address)
{
	mDev->FADDR = address;
}

error_t Usbd::waitUntilRxSetupOutData(uint32_t timeout)
{
	Timeout tout(timeout);

	while(mSetupOutDataFlag == false)
	{
		if(tout.isTimeout())
		{
			return error_t::TIMEOUT;
		}
			
		thread::yield();
	}

	return error_t::ERROR_NONE;
}

uint8_t Usbd::getSetupOutDataSize(void)
{
	return mSetupOutDataSize;
}

uint8_t* Usbd::getSetupOutDataPointer(void)
{
	return mSetupOutData;
}

void Usbd::clearFeature(uint8_t ep)
{
	if(ep & 0x80)
		ep = mInEpAllocTable[ep & 0x0F];
	else
		ep = mOutEpAllocTable[ep & 0x0F];

	mDev->EP[ep].CFGP &= ~USBD_CFGP_SSTALL_Msk;
	mDev->EP[ep].CFG &= ~USBD_CFG_DSQSYNC_Msk;
}

void Usbd::sendRemainingData(uint8_t epBufNum)
{
	uint8_t buf;

	if(mInSendingSize > mMaxPayload[epBufNum])
	{
		buf = mMaxPayload[epBufNum];
		mInSendingSize -= mMaxPayload[epBufNum];
	}
	else
	{
		buf = mInSendingSize;
		mInSendingSize = 0;
	}

	copyBuffer((uint8_t*)mSetupRxBuffer + mDev->EP[epBufNum].BUFSEG, mInSendingBuffer, buf);
	mInSendingBuffer += buf;

	mDev->EP[epBufNum].MXPLD = buf;
}

uint32_t Usbd::getOutRxDataSize(uint8_t ep)
{
	if(ep >= USBD_MAX_EP)
		return 0;

	ep = mOutEpAllocTable[ep];

	if(ep >= USBD_MAX_EP_BUF)
		return 0;

	return mOutRxSize[ep];
}

error_t Usbd::getOutRxData(uint8_t ep, void* des, uint8_t size)
{
	if(ep >= USBD_MAX_EP)
		return error_t::UNSUPPORTED_EP;

	ep = mOutEpAllocTable[ep];

	if(ep >= USBD_MAX_EP_BUF)
		return error_t::UNSUPPORTED_EP_BUF;

	copyBuffer((uint8_t*)des, (uint8_t*)mSetupRxBuffer + mDev->EP[ep].BUFSEG, size);
	
	mOutRxSize[ep] = 0;
	mDev->EP[ep].MXPLD = mMaxPayload[ep];

	return error_t::ERROR_NONE;
}

void Usbd::isr(void)
{
	uint32_t intsts = mDev->INTSTS, bus = mDev->ATTR, epsts0, epsts1;
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
		epsts0 = mDev->EPSTS0;
		epsts1 = mDev->EPSTS1;

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

			if(mInSendingSize > 0)
				sendRemainingData(0);
			else
				mInSendingCompleteFlag = true;
		}

		if(intsts & USBD_INTSTS_EPEVT1_Msk) // Control Out
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT1_Msk;

			mSetupOutDataSize = mDev->EP[1].MXPLD;
			copyBuffer(mSetupOutData, (uint8_t*)mSetupRxBuffer + mDev->EP[1].BUFSEG, mSetupOutDataSize);
			mSetupOutDataFlag = true;
		}

		if(intsts & USBD_INTSTS_EPEVT2_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT2_Msk;

			switch((mDev->EPSTS0 >> 8) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(2);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[2] = mDev->EP[2].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT3_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT3_Msk;
			
			switch((epsts0 >> 12) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(3);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[3] = mDev->EP[3].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT4_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT4_Msk;
			
			switch((epsts0 >> 16) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(4);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[4] = mDev->EP[4].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT5_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT5_Msk;
			
			switch((epsts0 >> 20) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(5);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[5] = mDev->EP[5].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT6_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT6_Msk;
			
			switch((epsts0 >> 24) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(6);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[6] = mDev->EP[6].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT7_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT7_Msk;
			
			switch((epsts0 >> 28) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(7);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[7] = mDev->EP[7].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT8_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT8_Msk;
			
			switch((epsts1 >> 0) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(8);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[8] = mDev->EP[8].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT9_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT9_Msk;
			
			switch((epsts1 >> 4) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(9);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[9] = mDev->EP[9].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT10_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT10_Msk;
			
			switch((epsts1 >> 8) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(10);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[10] = mDev->EP[10].MXPLD;
				break;
			}
		}

		if(intsts & USBD_INTSTS_EPEVT11_Msk)
		{
			mDev->INTSTS = USBD_INTSTS_EPEVT11_Msk;
			
			switch((epsts1 >> 12) & 0xF)
			{
			case 0 : // IN ACK
				if(mInSendingSize > 0)
					sendRemainingData(11);
				else
					mInSendingCompleteFlag = true;
				break;
			
			case 1 : // IN NAK

				break;
			
			case 2 : // OutPacket Data0 ACK
			case 6 : // OutPacket Data1 ACK
				mOutRxSize[11] = mDev->EP[11].MXPLD;
				break;
			}
		}
	}
}



#endif

