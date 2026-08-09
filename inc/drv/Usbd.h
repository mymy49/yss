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

	/**
	 * @brief Constructor for the Usbd class.
	 *
	 * @param[in] drvSetup Base driver setup configuration (clock, NVIC function pointers).
	 * @param[in] setup    USBD-specific hardware setup (pointer to the USB device peripheral).
	 */
	Usbd(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	/**
	 * @brief Initializes the USB Device peripheral and links it to a USB class handler.
	 *
	 * @details
	 * Configures the USB Device hardware (endpoint 0, interrupt masks, device address 0)
	 * and registers the `UsbClass` object that will handle all USB setup and data
	 * transactions (control, bulk, interrupt endpoints).
	 *
	 * @param[in] obj Reference to the `UsbClass` object implementing the USB protocol class.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(UsbClass &obj) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits data on the specified USB IN endpoint.
	 *
	 * @details
	 * Queues the data buffer for transmission on the given endpoint number.
	 * If `response` is true, the function waits until the host acknowledges
	 * the data packet (useful for control endpoint zero-length status stage).
	 *
	 * @param[in] ep       Endpoint number (IN direction).
	 * @param[in] src      Pointer to the data payload buffer to transmit.
	 * @param[in] size     Number of bytes to transmit.
	 * @param[in] response If true, waits for the host ACK before returning.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t send(uint8_t ep, void *src, uint16_t size, bool response = false) __attribute__((optimize("-O1")));

	/**
	 * @brief Stalls (halts) the specified endpoint.
	 *
	 * @details
	 * Sets the STALL condition on the given endpoint, causing the USB hardware
	 * to respond with a STALL handshake to the next host transaction on that
	 * endpoint. Typically used to signal an unsupported request to the host.
	 *
	 * @param[in] ep Endpoint number to stall.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t stall(uint8_t ep) __attribute__((optimize("-O1")));

	/**
	 * @brief Clears the STALL (halt) condition on the specified endpoint.
	 *
	 * @details
	 * Removes the STALL handshake from the given endpoint, restoring normal
	 * operation. This is called in response to a `ClearFeature(ENDPOINT_HALT)`
	 * control request from the host.
	 *
	 * @param[in] ep Endpoint number to clear the STALL condition on.
	 */
	void clearFeature(uint8_t ep) __attribute__((optimize("-O1")));

	/**
	 * @brief Flushes (discards) pending OUT setup data received on endpoint 0.
	 *
	 * @details
	 * Clears the internal setup OUT data buffer and resets the associated flag.
	 * Called after consuming the setup OUT payload to prepare for the next
	 * control transaction.
	 */
	void flushSetupOutData(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the USB device address assigned by the host.
	 *
	 * @details
	 * Programs the USB device address register with the address assigned by
	 * the host during the SET_ADDRESS control request. Must be called after
	 * the status stage of the SET_ADDRESS transaction completes.
	 *
	 * @param[in] address The USB device address assigned by the host (1–127).
	 */
	void setAddress(uint8_t address) __attribute__((optimize("-O1")));

	/**
	 * @brief Blocks until OUT setup data is received on endpoint 0 or timeout occurs.
	 *
	 * @details
	 * Waits (yielding the current thread) until the host sends OUT data on
	 * the control endpoint, or until the specified timeout elapses. Used to
	 * implement blocking control transfer data-stage reads.
	 *
	 * @param[in] timeout Timeout duration in milliseconds.
	 * @return error_t Returns ERROR_NONE if data was received, or an error code on timeout.
	 */
	error_t waitUntilRxSetupOutData(uint32_t timeout) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of the last received setup OUT data payload.
	 *
	 * @return uint8_t Number of bytes in the received setup OUT data buffer.
	 */
	uint8_t getSetupOutDataSize(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets a pointer to the internal setup OUT data buffer.
	 *
	 * @details
	 * Returns a pointer to the raw setup OUT data bytes received from the host.
	 * The valid byte count is given by `getSetupOutDataSize()`.
	 * After processing, call `flushSetupOutData()` to reset the buffer.
	 *
	 * @return uint8_t* Pointer to the setup OUT data buffer.
	 */
	uint8_t* getSetupOutDataPointer(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Reads OUT data received from the host on the specified endpoint.
	 *
	 * @details
	 * Copies up to `size` bytes of OUT endpoint data from the hardware FIFO or
	 * internal buffer into the destination buffer `des`.
	 *
	 * @param[in]  ep   Endpoint number (OUT direction).
	 * @param[out] des  Pointer to the destination buffer.
	 * @param[in]  size Maximum number of bytes to read.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t getOutRxData(uint8_t ep, void* des, uint8_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the number of bytes received on the specified OUT endpoint.
	 *
	 * @param[in] ep Endpoint number (OUT direction).
	 * @return uint32_t Number of bytes available in the OUT endpoint receive buffer.
	 */
	uint32_t getOutRxDataSize(uint8_t ep) __attribute__((optimize("-O1")));

	/**
	 * @brief USB Device interrupt service routine handler.
	 *
	 * @details
	 * Processes all pending USB interrupt flags (reset, setup, data transfer,
	 * SOF, etc.) and dispatches events to the registered `UsbClass` handler.
	 * Must be called from the hardware USB ISR vector. Do NOT call directly
	 * from user application code.
	 */
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

