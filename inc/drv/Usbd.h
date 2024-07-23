/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_USBD__H_
#define YSS_DRV_USBD__H_

#include "peripheral.h"

#if defined(STM32F7)
typedef USB_OTG_GlobalTypeDef		YSS_USB_TypeDef;
typedef USB_OTG_DeviceTypeDef		YSS_USB_Device_TypeDef;
#else
#include <stdint.h>
typedef volatile uint32_t			YSS_USB_TypeDef;
typedef volatile uint32_t			YSS_USB_Device_TypeDef;
#define YSS_DRV_USBD_UNSUPPORTED
#endif

#include "Drv.h"
#include <yss/error.h>
#include <sac/UsbClass.h>

class Usbd : public Drv
{
public :
	struct config_t
	{
		uint16_t ep0RxBuffSize;
	};

	error_t initialize(const config_t confg);

	struct setup_t
	{
		YSS_USB_TypeDef *global;
		YSS_USB_Device_TypeDef *dev;
		uint8_t endpointCount;
	};

	Usbd(const Drv::setup_t drvSetup, const setup_t setup);

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

#if defined(STM32F7)
	YSS_USB_TypeDef *mGlobal;
	YSS_USB_Device_TypeDef *mDev;
	uint8_t mEndpointCount;
#endif

	//void setEpStatusTx(uint8_t ep, uint16_t status);
	//void setEpStatusRx(uint8_t ep, uint16_t status);
	//void setEpType(uint8_t ep, uint16_t type);
	//BufferTable *mBufferTable;
};

#endif

