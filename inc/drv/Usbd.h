/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_USBD__H_
#define YSS_DRV_USBD__H_

#include "peripheral.h"

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY)

typedef volatile USBD_T				YSS_USB_Device_TypeDef;
#define USBD_MAX_EP_COUNT			8

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

/**
 * @file Usbd.h
 * @brief USB Device (USBD) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure target pins (VBUS, D-, D+, ID) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Construct/configure a class extending `UsbClass` (e.g. `UsbClass_NuvotonCdc` or custom class).
 * 4. Initialize the USBD peripheral using `initialize()` passing the `UsbClass` reference.
 * 5. Enable USBD interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for USB device
 * gpioA.setAsAltFunc(12, Gpio::PA12_USB_VBUS); // VBUS
 * gpioA.setAsAltFunc(13, Gpio::PA13_USBD_DN);   // D-
 * gpioA.setAsAltFunc(14, Gpio::PA14_USBD_DP);   // D+
 * gpioA.setAsAltFunc(15, Gpio::PA15_USB_OTG_ID);// ID
 * 
 * usbd.enableClock(); // Supply clock
 * 
 * // Configure UsbClass (e.g. Nuvoton CDC subclass)
 * UsbClass_NuvotonCdc cdc;
 * cdc.initialize(cdcConfig);
 * 
 * usbd.initialize(cdc); // Connect middleware class to the USBD driver
 * usbd.enableInterrupt(); // Enable interrupts
 * @endcode
 *
 * ### Middleware Architecture
 * - The driver acts as a low-level transceiver. It handles packet reception, transmission, endpoint stalling, and addresses.
 * - Higher-level USB protocols (CDC, Audio, MSC, HID) are implemented as classes deriving from `UsbClass`. The driver routes setup packets and endpoint requests directly to the registered `UsbClass` instance.
 */

/**
 * @class Usbd
 * @brief USB Device (USBD) driver class.
 * 
 * @warning The USBD driver is not intended to be used directly by the user application.
 *          Refer to the USB Classes defined in the /inc/UsbClass folder for details.
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

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY)
	YSS_USB_Device_TypeDef *mDev;
	uint8_t *mSetupRxBuffer;
	uint8_t mMaxPayload[USBD_MAX_EP];
	uint8_t mInEpAllocTable[USBD_MAX_EP_COUNT];
	uint8_t mOutEpAllocTable[USBD_MAX_EP_COUNT];
	uint8_t mOutRxSize[USBD_MAX_EP];
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

