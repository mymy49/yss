////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////
/*
#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <util/time.h>
#include <drv/peripherals.h>
#include <drv/usbd/drv_st_usbd_type_A_register.h>

#define	ISR_FS	0
#define	ISR_HS	1

#if defined(USB_OTG_FS)
static config::usbd::Config gUsbdFsConfig =
{
	USB_OTG_FS,
	5,
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x20),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x40),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x60),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x20),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x40),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x60),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	320,		// unsigned short maxFifoSize;
	0x40,		// unsigned short outFifoSize;
	0x40,		// unsigned short inFifoSize[8];
	0x0,
	0x40
};
drv::Usbd usbdFs(gUsbdFsConfig);
#endif

#if defined(USB_OTG_HS)
static config::usbd::Config gUsbdHsConfig =
{
	USB_OTG_HS,
	5,
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x20),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x40),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x60),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x20),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x40),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x60),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	320,		// unsigned short maxFifoSize;
	0x40,		// unsigned short outFifoSize;
	0x40,		// unsigned short inFifoSize[8];
	0x0,
	0x40
};
drv::Usbd usbdHs(gUsbdHsConfig);
#endif

static void (*gIsr[2])(void);
static void isr_handlerFs(void);
static void isr_handlerHs(void);

namespace drv
{
	Usbd::Usbd(config::usbd::Config &config)
	{
		mConfig = &config;
		mDeviceSetupHandlerId = 0;
		mSetupRxSize = 0;

		switch((unsigned long)config.peripheral)
		{
#if defined(USB_OTG_FS)
		case USB_OTG_FS_PERIPH_BASE :
			mPeriId = ISR_FS;
			break;
#endif
#if defined(USB_OTG_HS)
		case USB_OTG_HS_PERIPH_BASE :
			mPeriId = ISR_HS;
			break;
#endif
		}

		for(unsigned char i=0;i<MAX_EP_NUM;i++)
		{
			mOutData[i] = 0;
//			mRxBufferFullFlag[i] = false;
//			mRxBufferLockFlag[i] = false;
		}
	}

	void Usbd::mallocOutEndpoint(unsigned char epNum, unsigned long size)
	{
		if(mOutData[epNum] == 0)
			mOutData[epNum] = new UsbOutData(size);
	}

	bool Usbd::init(void (*handler)(config::usbd::SetupRequest *request))
	{
		USB_OTG_GlobalTypeDef *peri = mConfig->peripheral;
		USB_OTG_DeviceTypeDef *dev = (USB_OTG_DeviceTypeDef*)((unsigned long)peri + (unsigned long)USB_OTG_DEVICE_BASE);
		volatile unsigned long *pcgcctl = (unsigned long*)((unsigned long)peri + (unsigned long)USB_OTG_PCGCCTL_BASE);

		switch(mPeriId)
		{
		case ISR_FS :
			gIsr[mPeriId] = isr_handlerFs;
			break;
		case ISR_HS :
			gIsr[mPeriId] = isr_handlerHs;
			break;
		}

		if(mDeviceSetupHandlerId)
		{
			trigger::remove(mDeviceSetupHandlerId);
		}
		mDeviceSetupHandlerId = trigger::add((void(*)(void*))handler, mSetupRxBuffer, 1024);

//		if(mCheckRecevingBufferFullId)
//		{
//			trigger::remove(mCheckRecevingBufferFullId);
//		}
//		mCheckRecevingBufferFullId = trigger::add(mConfig->handlerCheckRecevingBuffer, 256);

		setUsbSerialTransceiverSelect(peri, true);

		if(resetCore() == false)
			return false;

		setUsbPowerDownControl(peri, true);
		setUsbForceDeviceMode(peri, true);
		thread::delay(50);

		for(unsigned char i=0;i<mConfig->numberOfEndpoint;i++)
		{
			peri->DIEPTXF[i] = 0;
		}

		setUsbBValidOverrideEn(peri, true);
		setUsbBValidOverrideValue(peri, true);

		// Restart the Phy Clock
		*pcgcctl = 0;

		setUsbPeriodicFrameInterval(dev, define::usbd::frameInterval::INTERVAL80);
		setUsbDeviceSpeed(dev, define::usbd::dspd::FULL_SPEED_FULL_INT_PHY);

		// Flush the FIFOs
		if(flushTxFifo(0x10) == false)
			return false;
		if(flushRxFifo() == false)
			return false;

		// Clear all pending Device Interrupts
		dev->DIEPMSK = 0;
		dev->DOEPMSK = 0;
		dev->DAINT = 0xFFFFFFFF;
		dev->DAINTMSK = 0;

		for(unsigned char i=0;i<mConfig->numberOfEndpoint;i++)
			disableEndPoint(i);

		dev->DIEPMSK &= ~(USB_OTG_DIEPMSK_TXFURM);

		// Disable all interrupts.
		peri->GINTMSK = 0;

		// Clear any pending interrupts
		peri->GINTSTS = 0xBFFFFFFF;

		// Enable the common interrupts
		setUsbRxFifoNonEmptyIntMsk(peri, true);
		setUsbResetIntMsk(peri, true);
		setUsbEnumerationDoneIntMsk(peri, true);
		setUsbOutEpIntMsk(peri, true);
		setUsbSuspendIntMsk(peri, true);

		setUsbSoftdisconnect(dev, true);
		initFifo();
		setUsbSoftdisconnect(dev, false);
		setUsbGlobalIntMsk(peri, true);
		thread::delay(50);

		return true;
	}

	bool Usbd::resetCore(void)
	{
		volatile unsigned long timeout;
		USB_OTG_GlobalTypeDef *peri = mConfig->peripheral;

		timeout = time::getRunningMsec() + 100;
		while(getUsbAhbIdle(peri) == false)
		{
			if(timeout < time::getRunningMsec())
				return false;
		}

		setUsbCoreSoftReset(peri);

		timeout = time::getRunningMsec() + 100;
		while(getUsbCoreSoftReset(peri))
		{
			if(timeout < time::getRunningMsec())
				return false;
		}

		return true;
	}

	bool Usbd::flushRxFifo(void)
	{
		volatile unsigned long timeout;

		mConfig->peripheral->GRSTCTL = USB_OTG_GRSTCTL_RXFFLSH;

		timeout = time::getRunningMsec() + 100;
		while(getUsbRxFifoFlush(mConfig->peripheral))
		{
			if(timeout < time::getRunningMsec())
				return false;
		}

		return true;
	}


	bool Usbd::flushTxFifo(unsigned char num)
	{
		volatile unsigned long timeout;

		mConfig->peripheral->GRSTCTL = ( USB_OTG_GRSTCTL_TXFFLSH |(unsigned long)( num << 6));

		timeout = time::getRunningMsec() + 100;
		while(getUsbTxFifoFlush(mConfig->peripheral))
		{
			if(timeout < time::getRunningMsec())
				return false;
		}

		return true;
	}

	void Usbd::disableEndPoint(unsigned char num)
	{
		USB_OTG_INEndpointTypeDef *in = mConfig->inEndpoint[num];
		USB_OTG_OUTEndpointTypeDef *out = mConfig->outEndpoint[num];

		if(getUsbInEpEnable(in))
		{
			setUsbInEpDisable(in);
			setUsbInEpSetNak(in);
		}
		else
		{
			in->DIEPCTL = 0;
		}

		if(getUsbOutEpEnable(out))
		{
			setUsbOutEpDisable(out);
			setUsbOutEpSetNak(out);
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


	void Usbd::setOutEpDataReceive(unsigned char epNum)
	{
		setUsbOutEpPacketCount(mConfig->outEndpoint[epNum], 0x3ff);
		setUsbOutEpTransferSize(mConfig->outEndpoint[epNum], 0x7ffff);
	}

	void Usbd::isr(void)
	{
#define getRxPacketStatus(x)		getRegField(x, 0xFUL, 17)
#define getRxEPNum(x)				getRegField(x, 0x7UL, 0)
#define getRxByteCount(x)			getRegField(x, 0x7FFUL, 4)

		USB_OTG_GlobalTypeDef *peri = mConfig->peripheral;
		USB_OTG_DeviceTypeDef *dev = (USB_OTG_DeviceTypeDef*)((unsigned long)peri + (unsigned long)USB_OTG_DEVICE_BASE);

		if(getUsbRxFifoNonEmptyInt(peri))
		{
			debug_printf("getUsbRxFifoNonEmtyInt\n");
			unsigned short fifoLoop;
			unsigned long buf[16];
			unsigned char *data;
			unsigned long sr = peri->GRXSTSP;
			unsigned char packetStatus = getRxPacketStatus(sr);
			unsigned long *fifo = (unsigned long*)((unsigned long)peri + USB_OTG_FIFO_BASE);
			unsigned short size = getRxByteCount(sr);
			unsigned char epNum;

			switch(packetStatus)
			{
			case 2 : // OUT data packet received
				epNum = getRxEPNum(sr);

				if(size > 0)
				{
					if(mOutData[epNum])
					{
//						if(mOutData[epNum]->getFreeSize() <= mHandle->fifoAllocationSize[0]*4)
//						{
//							setUsbOutEpSetNak(mConfig->outEndpoint[epNum]);
//							mRxBufferFullFlag[epNum] = true;
//							trigger::run(mCheckRecevingBufferFullId);
//						}
						mOutData[epNum]->push(fifo, size);
					}
				}
				break;
			case 6 : // SETUP data packet received
				if(size > 0)
				{
					unsigned long *buf = (unsigned long*)mSetupRxBuffer;

					fifoLoop = (size + 3) >> 2;

					if(size > 64)
						size = 64;

					mSetupRxSize = size;

					for(unsigned char i=0;i<fifoLoop;i++)
						buf[i] = *fifo;
				}
				break;
			}

			setUsbRxFifoNonEmptyIntMsk(peri, true);
		}

		if(getOutEpInt(peri))
		{
			debug_printf("getOutEpInt\n");
			unsigned long deviceIntFlag = dev->DAINT & dev->DAINTMSK;
			unsigned long endpointIntFlag, endpointMask = 0x00010000;

			for(unsigned char i=0;i<mConfig->numberOfEndpoint;i++)
			{
				if(deviceIntFlag & endpointMask)
				{
					endpointIntFlag = mConfig->outEndpoint[i]->DOEPINT;

					if(endpointIntFlag & USB_OTG_DOEPMSK_XFRCM)
					{
						if(i)
						{
							setOutEpDataReceive(i);
							mConfig->outEndpoint[i]->DOEPCTL |= (USB_OTG_DOEPCTL_CNAK | USB_OTG_DOEPCTL_EPENA);
						}

						mConfig->outEndpoint[i]->DOEPINT |= USB_OTG_DOEPMSK_XFRCM;
					}
					if(endpointIntFlag & USB_OTG_DOEPMSK_EPDM)
					{
						mConfig->outEndpoint[i]->DOEPINT |= USB_OTG_DOEPMSK_EPDM;
					}
					if(endpointIntFlag & USB_OTG_DOEPMSK_STUPM)
					{
						trigger::run(mDeviceSetupHandlerId);
						mConfig->outEndpoint[i]->DOEPINT |= USB_OTG_DOEPMSK_STUPM;
					}
					if(endpointIntFlag & USB_OTG_DOEPMSK_OTEPDM)
					{
						mConfig->outEndpoint[i]->DOEPINT |= USB_OTG_DOEPMSK_OTEPDM;
					}
					if(endpointIntFlag & USB_OTG_DOEPMSK_B2BSTUP)
					{
						mConfig->outEndpoint[i]->DOEPINT |= USB_OTG_DOEPMSK_B2BSTUP;
					}
				}
				endpointMask <<= 1;
			}

			clearUsbOutEpInt(peri);
		}

		if(getUsbResetInt(peri))
		{
			debug_printf("getUsbResetInt\n");
			setUsbRemoteWakeupSignaling(dev, false);
			flushTxFifo(0);

			for(unsigned char i=0;i<mConfig->numberOfEndpoint;i++)
			{
				mConfig->inEndpoint[i]->DIEPINT = 0xFF;
				mConfig->outEndpoint[i]->DOEPINT = 0xFF;
			}

			dev->DAINT = 0xFFFFFFFF;
			dev->DAINTMSK |= 0x10001;

			dev->DOEPMSK |= (USB_OTG_DOEPMSK_STUPM | USB_OTG_DOEPMSK_XFRCM | USB_OTG_DOEPMSK_EPDM | USB_OTG_DOEPMSK_OTEPDM);
			dev->DIEPMSK |= (USB_OTG_DIEPMSK_TOM | USB_OTG_DIEPMSK_XFRCM | USB_OTG_DIEPMSK_EPDM);

			// Set Default Address to 0
			setUsbDeviceAddress(dev, 0);

			// setup EP0 to receive SETUP packets
			setUsbOutEp0PacketCount(mConfig->outEndpoint[0], true);
			setUsbOutEp0TransferSize(mConfig->outEndpoint[0], 24);
			setUsbOutEp0SetupPacketCount(mConfig->outEndpoint[0], 3);

			clearUsbResetInt(mConfig->peripheral);
		}

		// Handle Enumeration done Interrupt
		if(getUsbEnumerationDoneInt(peri))
		{
			debug_printf("getUsbEnumerationDoneInt\n");
			unsigned long hclk = clock.getSysClkFreq();
			setUsbInEpMaxPacketSize(mConfig->inEndpoint[0], define::usbd::ep0MaxPacketSize::BYTE_64);
			if((hclk >= 14200000)&&(hclk < 15000000))
			{
				setUsbTurnaroundTime(peri, 0xf);
			}
			else if((hclk >= 15000000)&&(hclk < 16000000))
			{
				setUsbTurnaroundTime(peri, 0xe);
			}
			else if((hclk >= 16000000)&&(hclk < 17200000))
			{
				setUsbTurnaroundTime(peri, 0xd);
			}
			else if((hclk >= 17200000)&&(hclk < 18500000))
			{
				setUsbTurnaroundTime(peri, 0xc);
			}
			else if((hclk >= 18500000)&&(hclk < 20000000))
			{
				setUsbTurnaroundTime(peri, 0xb);
			}
			else if((hclk >= 20000000)&&(hclk < 21800000))
			{
				setUsbTurnaroundTime(peri, 0xa);
			}
			else if((hclk >= 21800000)&&(hclk < 24000000))
			{
				setUsbTurnaroundTime(peri, 0x9);
			}
			else if((hclk >= 24000000)&&(hclk < 27700000))
			{
				setUsbTurnaroundTime(peri, 0x8);
			}
			else if((hclk >= 27700000)&&(hclk < 32000000))
			{
				setUsbTurnaroundTime(peri, 0x7);
			}
			else // if(hclk >= 32000000)
			{
				setUsbTurnaroundTime(peri, 0x6);
			}

			clearUsbEnumerationDoneInt(peri);

		}

		if(getUsbSuspendInt(peri))
		{
			debug_printf("getUsbSuspendInt\n");
			clearUsbSuspendInt(peri);
		}
	}

	void Usbd::writeSetup(unsigned char *data, unsigned long size, unsigned long timeout)
	{
		static Mutex mutex;

		unsigned long *buf = (unsigned long*)data;
		unsigned long sending;
		unsigned long *fifo = (unsigned long*)((unsigned long)mConfig->peripheral + USB_OTG_FIFO_BASE);
		unsigned long long time;

		USB_OTG_INEndpointTypeDef *in = mConfig->inEndpoint[0];
		USB_OTG_OUTEndpointTypeDef *out = mConfig->outEndpoint[0];

		mutex.lock();

		time = time::getRunningMsec() + timeout;

		setUsbInEpPacketCount(in, (size + 0x3f) / 0x40);
		setUsbInEpTransferSize(in, size);

		in->DIEPCTL |= (USB_OTG_DIEPCTL_CNAK | USB_OTG_DIEPCTL_EPENA);
		out->DOEPCTL |= (USB_OTG_DOEPCTL_CNAK | USB_OTG_DOEPCTL_EPENA);
		in->DIEPINT = 0xffffffff;

		clearUsbInEpTransferCompleteInt(in);

		if(size)
		{
			while(size)
			{
				sending = getUsbInEpFifoSpace(in) << 2;
				if(sending > size)
					sending = size;
				size -= sending;
				sending += 3;
				sending >>= 2;

				for(unsigned char i=0;i<sending;i++)
					*fifo = *buf++;

				if(time <= time::getRunningMsec())
				{
					goto error;
				}
				thread::switchContext();
			}
		}

		while(1)
		{
			if(in->DIEPINT & 0x51)
				break;
			thread::switchContext();
		}

		mutex.unlock();
		return;

	error:
		flushTxFifo(0);
		mutex.unlock();
		return;
	}

	void Usbd::write(unsigned char epNum, unsigned char *data, unsigned long size, unsigned long timeout)
	{
		static Mutex mutex;

		unsigned long *buf = (unsigned long*)data;
		unsigned long sending;
		unsigned long *fifo = (unsigned long*)((unsigned long)mConfig->peripheral + USB_OTG_FIFO_BASE + USB_OTG_FIFO_SIZE * epNum);
		unsigned long long time;

		USB_OTG_INEndpointTypeDef *in = mConfig->inEndpoint[epNum];
		USB_OTG_OUTEndpointTypeDef *out = mConfig->outEndpoint[epNum];

		mutex.lock();

		time = time::getRunningMsec() + timeout;

		setUsbInEpPacketCount(in, (size + 0x3f) / 0x40);
		setUsbInEpTransferSize(in, size);

		in->DIEPCTL |= (USB_OTG_DIEPCTL_CNAK | USB_OTG_DIEPCTL_EPENA);
		out->DOEPCTL |= (USB_OTG_DOEPCTL_CNAK | USB_OTG_DOEPCTL_EPENA);
		in->DIEPINT = 0xffffffff;

		clearUsbInEpTransferCompleteInt(in);

		if(size)
		{
			while(size)
			{
				sending = getUsbInEpFifoSpace(in) << 2;
				if(sending > size)
					sending = size;
				size -= sending;
				sending += 3;
				sending >>= 2;

				for(unsigned char i=0;i<sending;i++)
					*fifo = *buf++;

				if(time <= time::getRunningMsec())
				{
					goto error;
				}
				thread::switchContext();
			}

			while(!getUsbInEpTransferCompleteInt(in))
				thread::switchContext();
		}

		while(1)
		{
			if(in->DIEPINT & 0x51)
				break;
			thread::switchContext();
		}

		mutex.unlock();
		return;

	error:
		flushTxFifo(epNum);
		mutex.unlock();
		return;
	}

	void Usbd::stall(unsigned char epNum)
	{
		mMutex[epNum].lock();
		setUsbInEpStall(mConfig->inEndpoint[epNum], true);
		mMutex[epNum].unlock();
	}

	void Usbd::setAddress(unsigned short addr)
	{
		USB_OTG_DeviceTypeDef *dev = (USB_OTG_DeviceTypeDef*)((unsigned long)mConfig->peripheral + (unsigned long)USB_OTG_DEVICE_BASE);
		setUsbDeviceAddress(dev, addr);
	}

	void Usbd::activeOutEndpoint(unsigned char epNum, unsigned char epType, unsigned short size)
	{
		USB_OTG_DeviceTypeDef *dev = (USB_OTG_DeviceTypeDef*)((unsigned long)mConfig->peripheral + (unsigned long)USB_OTG_DEVICE_BASE);
		mConfig->outEndpoint[epNum]->DOEPCTL = USB_OTG_DOEPCTL_USBAEP | USB_OTG_DOEPCTL_SD0PID_SEVNFRM | USB_OTG_DOEPCTL_EPENA | USB_OTG_DOEPCTL_CNAK | (epType << 18) | size;
		setUsbDeviceOutEpIntMsk(dev, epNum, true);
	}

	void Usbd::activeInEndpoint(unsigned char epNum, unsigned char epType, unsigned short size)
	{
		USB_OTG_DeviceTypeDef *dev = (USB_OTG_DeviceTypeDef*)((unsigned long)mConfig->peripheral + (unsigned long)USB_OTG_DEVICE_BASE);
		mConfig->inEndpoint[epNum]->DIEPCTL = USB_OTG_DIEPCTL_USBAEP | USB_OTG_DIEPCTL_SD0PID_SEVNFRM | (epType << 18) | size | epNum << 22;
		setUsbDeviceInEpIntMsk(dev, epNum, true);
	}

	UsbOutData* Usbd::getOutEndpointData(unsigned char epNum)
	{
		return mOutData[epNum];
	}

	bool Usbd::initFifo(void)
	{
		USB_OTG_GlobalTypeDef *peri = mConfig->peripheral;
		unsigned short offset, size;

		setUsbReceiveFifoSize(peri, mConfig->outFifoSize);
		offset = mConfig->outFifoSize;

		setUsbTransmitterFifoSize0(peri, offset, mConfig->inFifoSize[0]);
		offset += mConfig->inFifoSize[0];

		for(unsigned char i=1;i<mConfig->numberOfEndpoint;i++)
		{
			setUsbTransmitterFifoSize(peri, i-1, offset, mConfig->inFifoSize[i]);
			offset += mConfig->inFifoSize[i];
		}

		if(offset > mConfig->maxFifoSize)
			return false;
		else
			return true;
	}
}

static void isr_handlerFs(void)
{
	usbdFs.isr();
}

static void isr_handlerHs(void)
{
	usbdHs.isr();
}

extern "C"
{
	void OTG_FS_IRQHandler(void)
	{
		gIsr[ISR_FS]();
	}

	void OTG_HS_IRQHandler(void)
	{
		gIsr[ISR_HS]();
	}
}

#endif
*/