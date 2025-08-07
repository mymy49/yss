/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_USBD__H_
#define YSS_DRV_USBD__H_

#include "peripheral.h"

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_SUBFAMILY)

typedef volatile USBD_T				YSS_USB_Device_TypeDef;
#define USBD_MAX_EP					8

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

/*
	USBD를 사용자가 직접 사용하지 않습니다.
	자세한 사항은 /inc/UsbClass 폴더의 내의 정의된 USB Class들을 참고하세요. 
*/
class Usbd : public Drv
{
public :
	struct setup_t
	{
		YSS_USB_Device_TypeDef *dev;
	};

	Usbd(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	error_t initialize(UsbClass &obj) __attribute__((optimize("-O1")));

	error_t send(uint8_t ep, void *src, uint16_t size, bool response = false) __attribute__((optimize("-O1")));

	error_t stall(uint8_t ep) __attribute__((optimize("-O1")));

	void clearFeature(uint8_t ep) __attribute__((optimize("-O1")));

	void flushSetupOutData(void) __attribute__((optimize("-O1")));

	void setAddress(uint8_t address) __attribute__((optimize("-O1")));

	error_t waitUntilRxSetupOutData(uint32_t timeout) __attribute__((optimize("-O1")));

	uint8_t getSetupOutDataSize(void) __attribute__((optimize("-O1")));

	uint8_t* getSetupOutDataPointer(void) __attribute__((optimize("-O1")));

	error_t getOutRxData(uint8_t ep, void* des, uint8_t size) __attribute__((optimize("-O1")));

	uint32_t getOutRxDataSize(uint8_t ep) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	UsbClass *mUsbClass;
	uint8_t mSetupOutData[64], mSetupOutDataSize;
	bool mSetupOutDataFlag;

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_SUBFAMILY)
	YSS_USB_Device_TypeDef *mDev;
	uint8_t *mSetupRxBuffer;
	uint8_t mMaxPayload[USBD_MAX_EP_BUF];
	uint8_t mInEpAllocTable[USBD_MAX_EP];
	uint8_t mOutEpAllocTable[USBD_MAX_EP];
	uint8_t mOutRxSize[USBD_MAX_EP_BUF];
	uint16_t mInSendingSize;
	uint8_t *mInSendingBuffer;
	uint8_t mNewAddress;
	bool mInSendingCompleteFlag;
	bool mNewAddressUpdateFlag;

	void copyBuffer(uint8_t *des, uint8_t *src, uint16_t size) __attribute__((optimize("-O1")));

	void sendRemainingData(uint8_t epBufNum) __attribute__((optimize("-O1")));

#endif
};

#endif

