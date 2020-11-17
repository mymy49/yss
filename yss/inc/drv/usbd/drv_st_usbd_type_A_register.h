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

#ifndef YSS_DRV_USBD_ST_TYPE_A_REG__H_
#define YSS_DRV_USBD_ST_TYPE_A_REG__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)
//	defined(STM32F103xG) || \

#include <yss/reg.h>

#define setUsbBValidOverrideEn(addr, x)			setRegBit(addr->GOTGCTL, x, 6)
#define setUsbBValidOverrideValue(addr, x)		setRegBit(addr->GOTGCTL, x, 7)

#define setUsbGlobalIntMsk(addr, x)				setRegBit(addr->GAHBCFG, x, 0)
#define setUsbDmaEn(addr, x)					setRegBit(addr->GAHBCFG, x, 5)
#define setUsbTxFifoEmptyLevel(addr, x)			setRegBit(addr->GAHBCFG, x, 7)
#define setUsbPeriodicTxFifoEmptyLevel(addr, x)	setRegBit(addr->GAHBCFG, x, 8)

#define setUsbSerialTransceiverSelect(addr, x)	setRegBit(addr->GUSBCFG, x, 6)
#define setUsbSrpcap(addr, x)					setRegBit(addr->GUSBCFG, x, 8)
#define setUsbHnpcap(addr, x)					setRegBit(addr->GUSBCFG, x, 9)
#define setUsbForceHostMode(addr, x)			setRegBit(addr->GUSBCFG, x, 29)
#define setUsbForceDeviceMode(addr, x)			setRegBit(addr->GUSBCFG, x, 30)
#define setUsbTurnaroundTime(addr, x)			setRegField(addr->GUSBCFG, 0xFUL, x, 10)
#define setUsbTocal(addr, x)					setRegField(addr->GUSBCFG, 0x7UL, x, 0)

#define getUsbAhbIdle(addr)						getRegBit(addr->GRSTCTL, 31)
#define setUsbCoreSoftReset(addr)				setRegBit(addr->GRSTCTL, 1, 0)
#define getUsbCoreSoftReset(addr)				getRegBit(addr->GRSTCTL, 0)
#define getUsbTxFifoFlush(addr)					getRegBit(addr->GRSTCTL, 5)
#define setUsbRxFifoFlush(addr)					setRegBit(addr->GRSTCTL, 1, 4)
#define getUsbRxFifoFlush(addr)					getRegBit(addr->GRSTCTL, 4)

#define getUsbRxFifoNonEmptyInt(addr)			getRegBit(addr->GINTSTS, 4)
#define clearUsbRxFifoNonEmptyInt(addr)			setRegBit(addr->GINTSTS, 1, 4)
#define getUsbSuspendInt(addr)					getRegBit(addr->GINTSTS, 11)
#define clearUsbSuspendInt(addr)				setRegBit(addr->GINTSTS, 1, 11)
#define getUsbResetInt(addr)					getRegBit(addr->GINTSTS, 12)
#define clearUsbResetInt(addr)					setRegBit(addr->GINTSTS, 1, 12)
#define getUsbEnumerationDoneInt(addr)			getRegBit(addr->GINTSTS, 13)
#define clearUsbEnumerationDoneInt(addr)		setRegBit(addr->GINTSTS, 1, 13)
#define getInEpInt(addr)						getRegBit(addr->GINTSTS, 18)
#define clearUsbInEpInt(addr)					setRegBit(addr->GINTSTS, 1, 18)
#define getOutEpInt(addr)						getRegBit(addr->GINTSTS, 19)
#define clearUsbOutEpInt(addr)					setRegBit(addr->GINTSTS, 1, 19)

#define setUsbMmisMsk(addr, x)									setRegBit(addr->GINTMSK, x, 1)
#define setUsbOtgintMsk(addr, x)								setRegBit(addr->GINTMSK, x, 2)
#define setUsbRxFifoNonEmptyIntMsk(addr, x)						setRegBit(addr->GINTMSK, x, 4)
#define setUsbSuspendIntMsk(addr, x)							setRegBit(addr->GINTMSK, x, 11)
#define setUsbResetIntMsk(addr, x)								setRegBit(addr->GINTMSK, x, 12)
#define setUsbEnumerationDoneIntMsk(addr, x)					setRegBit(addr->GINTMSK, x, 13)
#define setUsbInEpIntMsk(addr, x)								setRegBit(addr->GINTMSK, x, 18)
#define setUsbOutEpIntMsk(addr, x)								setRegBit(addr->GINTMSK, x, 19)
#define setUsbIncompleteIsochronousInTransferIntMsk(addr, x)	setRegBit(addr->GINTMSK, x, 20)
#define setUsbIncompleteIsochronousOutTransferIntMsk(addr, x)	setRegBit(addr->GINTMSK, x, 21)
#define setUsbWakeUpIntMsk(addr, x)								setRegBit(addr->GINTMSK, x, 31)

#define setUsbReceiveFifoSize(addr, x)							addr->GRXFSIZ = (unsigned short)x;
#define setUsbTransmitterFifoSize0(addr, offset, size)			addr->DIEPTXF0_HNPTXFSIZ = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize(addr, index, offset, size)	addr->DIEPTXF[index] = (unsigned long)size << 16 | offset;

#define setUsbTransmitterFifoSize1(addr, offset, size)			addr->DIEPTXF[0] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize2(addr, offset, size)			addr->DIEPTXF[1] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize3(addr, offset, size)			addr->DIEPTXF[2] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize4(addr, offset, size)			addr->DIEPTXF[3] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize5(addr, offset, size)			addr->DIEPTXF[4] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize6(addr, offset, size)			addr->DIEPTXF[5] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize7(addr, offset, size)			addr->DIEPTXF[6] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize8(addr, offset, size)			addr->DIEPTXF[7] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize9(addr, offset, size)			addr->DIEPTXF[8] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize10(addr, offset, size)			addr->DIEPTXF[9] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize11(addr, offset, size)			addr->DIEPTXF[10] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize12(addr, offset, size)			addr->DIEPTXF[11] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize13(addr, offset, size)			addr->DIEPTXF[12] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize14(addr, offset, size)			addr->DIEPTXF[13] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize15(addr, offset, size)			addr->DIEPTXF[14] = (unsigned long)size << 16 | offset;
#define setUsbTransmitterFifoSize16(addr, offset, size)			addr->DIEPTXF[15] = (unsigned long)size << 16 | offset;

#define setUsbPowerDownControl(addr, x)							setRegBit(addr->GCCFG, x, 16)


// device

#define setUsbDeviceSpeed(addr, x)				setRegField(addr->DCFG, 0x3UL, x, 0)
#define setUsbNzlsohsk(addr, x)					setRegBit(addr->DCFG, x, 2)
#define setUsbDeviceAddress(addr, x)			setRegField(addr->DCFG, 0x7FUL, x, 4)
#define setUsbPeriodicFrameInterval(addr, x)	setRegField(addr->DCFG, 0x3UL, x, 11)

#define setUsbSoftdisconnect(addr, x)			setRegBit(addr->DCTL, x, 1)
#define setUsbRemoteWakeupSignaling(addr, x)	setRegBit(addr->DCTL, x, 0)

#define setUsbDeviceOutEpIntMsk(addr, bit, x)	setRegBit(addr->DAINTMSK, x, bit + 16)
#define setUsbDeviceInEpIntMsk(addr, bit, x)	setRegBit(addr->DAINTMSK, x, bit)


// in endpoint
#define setUsbInEpMaxPacketSize(addr, x)		setRegField(addr->DIEPCTL, 0x3UL, x, 0)
#define setUsbInEpStall(addr, x)				setRegBit(addr->DIEPCTL, x, 21)
#define setUsbInEpSetNak(addr)					setRegBit(addr->DIEPCTL, 1, 27)
#define setUsbInEpDisable(addr)					setRegBit(addr->DIEPCTL, 1, 30)
#define getUsbInEpEnable(addr)					getRegBit(addr->DIEPCTL, 31)

#define setUsbInEpTransferMultiCount(addr, x)	setRegField(addr->DIEPTSIZ, 0x3UL, x, 29)
#define setUsbInEpPacketCount(addr, x)			setRegField(addr->DIEPTSIZ, 0x3FFUL, x, 19)
#define setUsbInEpTransferSize(addr, x)			setRegField(addr->DIEPTSIZ, 0x7FFFFUL, x, 0)

#define setUsbInEpFifoInt(dev, ep, en)			setRegBit(dev->DIEPEMPMSK, en, ep)
#define getUsbInEpFifoInt(dev, ep)				getRegBit(dev->DIEPEMPMSK, ep)

#define getUsbInEpFifoSpace(addr)				(unsigned short)addr->DTXFSTS

// out endpoint
#define setUsbOutEp0MaxPacketSize(addr, x)		setRegField(addr->DOEPCTL, 0x3UL, x, 0)
#define setUsbOutEpxMaxPacketSize(addr, x)		setRegField(addr->DOEPCTL, 0x7FFUL, x, 0)
#define setUsbOutEpActive(addr, x)				setRegBit(addr->DOEPCTL, x, 15)
#define setUsbOutEpType(addr, x)				setRegField(addr->DOEPCTL, 0x3UL, x, 18)
#define setUsbOutEpClearNak(addr)				setRegBit(addr->DOEPCTL, 1, 26)
#define setUsbOutEpSetNak(addr)					setRegBit(addr->DOEPCTL, 1, 27)
#define setUsbOutEpData0Pid(addr, x)			setRegBit(addr->DOEPCTL, x, 28)
#define setUsbOutEpDisable(addr)				setRegBit(addr->DOEPCTL, 1, 30)
#define setUsbOutEpEnable(addr, x)				setRegBit(addr->DOEPCTL, x, 31)
#define getUsbOutEpEnable(addr)					getRegBit(addr->DOEPCTL, 31)

#define getUsbInEpItxfe(addr)					getRegBit(addr->DIEPINT, 4)
#define getUsbInEpInpene(addr)					getRegBit(addr->DIEPINT, 6)
#define getUsbInEpTransmitFifoEmpty(addr)		getRegBit(addr->DIEPINT, 7)
#define getUsbInEpTransferCompleteInt(addr)		getRegBit(addr->DIEPINT, 0)
#define clearUsbInEpTransferCompleteInt(addr)	setRegBit(addr->DIEPINT, 1, 0)

#define setUsbOutEp0TransferSize(addr, x)		setRegField(addr->DOEPTSIZ, 0x7FUL, x, 0)
#define setUsbOutEp0PacketCount(addr, x)		setRegBit(addr->DOEPTSIZ, x, 19)
#define setUsbOutEp0SetupPacketCount(addr, x)	setRegField(addr->DOEPTSIZ, 0x3UL, x, 29)

#define setUsbOutEpTransferSize(addr, x)		setRegField(addr->DOEPTSIZ, 0x7FFFFUL, x, 0)
#define setUsbOutEpPacketCount(addr, x)			setRegField(addr->DOEPTSIZ, 0x3FFUL, x, 19)

#endif

#endif
