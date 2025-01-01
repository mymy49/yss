/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_USBD__H_
#define YSS_DRV_USBD__H_

#include "peripheral.h"

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

typedef volatile USBD_T				YSS_USB_Device_TypeDef;

#else

#include <stdint.h>
typedef volatile uint32_t			YSS_USB_TypeDef;
typedef volatile uint32_t			YSS_USB_Device_TypeDef;
#define YSS_DRV_USBD_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>
#include <UsbClass/UsbClass.h>

class Usbd : public Drv
{
public :
	error_t initialize(UsbClass &obj);

	struct setup_t
	{
		YSS_USB_Device_TypeDef *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	Usbd(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void);

private :
	//struct BufferInfo
	//{
	//	uint16_t addr;
	//	uint16_t rsvd0;
	//	uint16_t cnt;
	//	uint16_t rsvd1;
	//}__attribute__ ((__packed__));

	//struct BufferTable
	//{
	//	BufferInfo tx0;
	//	BufferInfo rx0;
	//	BufferInfo tx1;
	//	BufferInfo rx1;
	//	BufferInfo tx2;
	//	BufferInfo rx2;
	//	BufferInfo tx3;
	//	BufferInfo rx3;
	//}__attribute__ ((__packed__));
	UsbClass *mUsbClass;

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
	YSS_USB_Device_TypeDef *mDev;
	Dma::dmaInfo_t mTxDmaInfo;
	Dma::dmaInfo_t mRxDmaInfo;
#endif

	//void setEpStatusTx(uint8_t ep, uint16_t status);
	//void setEpStatusRx(uint8_t ep, uint16_t status);
	//void setEpType(uint8_t ep, uint16_t type);
	//BufferTable *mBufferTable;
};

#endif

