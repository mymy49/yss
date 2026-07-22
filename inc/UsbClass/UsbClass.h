/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS__H_
#define YSS_USB_CLASS__H_

#include <stdint.h>
#include <yss/error.h>
#include <yss/scheduler.h>

class Usbd;

/**
 * @file UsbClass.h
 * @brief Base USB Class driver header file.
 */

/**
 * @class UsbClass
 * @brief Base class for implementing USB device classes (e.g. CDC, Audio, Mass Storage).
 *
 * @details
 * This class provides standard USB descriptor definitions, packet parse functions, and virtual
 * callback interfaces to implement specific USB device protocols.
 */
class UsbClass
{
public :
/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
	/**
	 * @brief USB Setup Packet Request structure.
	 */
	typedef struct
	{
		uint16_t wRequest;   ///< Request type and request code.
		uint16_t wValue;     ///< Request value parameter.
		uint16_t wIndex;     ///< Request index/offset parameter.
		uint16_t wLength;    ///< Data stage transfer length.
	}request_t __attribute__ ((__packed__));

	/**
	 * @brief USB Device Descriptor structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor in bytes.
		uint8_t bDescriptorType;     ///< Device descriptor type (0x01).
		uint16_t bcdUSB;             ///< USB specification release number in BCD.
		uint8_t bDeviceClass;        ///< Class code.
		uint8_t bDeviceSubclass;     ///< Subclass code.
		uint8_t bDeviceProtocol;     ///< Protocol code.
		uint8_t bMaxPacketSize0;     ///< Maximum packet size for Endpoint 0.
		uint16_t idVendor;           ///< Vendor ID.
		uint16_t idProduct;          ///< Product ID.
		uint16_t bcdDevice;          ///< Device release number in BCD.
		uint8_t iManufacturer;       ///< Index of manufacturer string descriptor.
		uint8_t iProduct;            ///< Index of product string descriptor.
		uint8_t iSerialNumber;       ///< Index of serial number string descriptor.
		uint8_t bNumConfigurations;  ///< Number of possible configurations.
	}devDesc_t __attribute__ ((__packed__));

	/**
	 * @brief USB Device Qualifier Descriptor structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor in bytes.
		uint8_t bDescriptorType;     ///< Device Qualifier descriptor type (0x06).
		uint16_t bcdUSB;             ///< USB specification release number in BCD.
		uint8_t bDeviceClass;        ///< Class code.
		uint8_t bDeviceSubclass;     ///< Subclass code.
		uint8_t bDeviceProtocol;     ///< Protocol code.
		uint8_t bMaxPacketSize0;     ///< Maximum packet size for EP0.
		uint8_t bNumConfigurations;  ///< Number of configurations.
		uint8_t Reserved;            ///< Reserved (must be zero).
	}devQualifier_t __attribute__ ((__packed__));

	/**
	 * @brief USB Configuration Descriptor structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor in bytes.
		uint8_t bDescriptorType;     ///< Configuration descriptor type (0x02).
		uint16_t wTotalLength;       ///< Total length of data returned for this configuration.
		uint8_t bNumInterfaces;      ///< Number of interfaces supported by this configuration.
		uint8_t bConfigurationValue; ///< Value to use as an argument to Set Configuration.
		uint8_t bConfiguration;      ///< Index of string descriptor describing this configuration.
		uint8_t bmAttributes;        ///< Configuration characteristics.
		uint8_t bMaxPower;           ///< Maximum power consumption in 2mA units.
	}confignDesc_t __attribute__ ((__packed__));

	/**
	 * @brief USB Interface Descriptor structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor in bytes.
		uint8_t bDescriptorType;     ///< Interface descriptor type (0x04).
		uint8_t bInterfaceNumber;    ///< Number of this interface.
		uint8_t bAlternateSetting;   ///< Value used to select alternate setting.
		uint8_t bNumEndpoints;       ///< Number of endpoints used by this interface (excluding EP0).
		uint8_t bInterfaceClass;     ///< Class code.
		uint8_t bInterfaceSubClass;  ///< Subclass code.
		uint8_t bInterfaceProtocol;  ///< Protocol code.
		uint8_t iInterface;          ///< Index of string descriptor describing this interface.
	}interfaceDesc_t;

	/**
	 * @brief USB Configuration Attribute structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor.
		uint8_t bDescriptorType;     ///< Descriptor type.
		uint8_t bEndpointAddress;    ///< Endpoint address and direction.
		uint8_t bmAttributes;        ///< Endpoint attributes.
		uint16_t wMaxPacketSize;     ///< Maximum packet size.
		uint8_t bInterval;           ///< Interval for polling.
	}configurationAttribute_t __attribute__ ((__packed__));

	/**
	 * @brief USB Endpoint Descriptor structure.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of descriptor in bytes.
		uint8_t bDescriptorType;     ///< Endpoint descriptor type (0x05).
		uint8_t bEndpointAddress;    ///< Endpoint address and direction.
		uint8_t bmAttributes;        ///< Endpoint attributes.
		uint16_t wMaxPacketSize;     ///< Maximum packet size.
		uint8_t bInterval;           ///< Polling interval.
	}epDesc_t __attribute__ ((__packed__));
#pragma GCC diagnostic pop

	UsbClass(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Handles receiving a USB Setup packet.
	 *
	 * @param[in] data Pointer to the setup packet buffer (8 bytes).
	 */
	void handleRxSetupPacket(void *data) __attribute__((optimize("-O1")));

	/**
	 * @brief Associates the USB Class driver with a target USBD controller stack.
	 *
	 * @param[in] usbd Pointer to the Usbd controller.
	 */
	void setUsbd(Usbd *usbd) __attribute__((optimize("-O1")));

	/**
	 * @brief Main processing loop execution method.
	 */
	void process(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of received data currently available.
	 *
	 * @return uint32_t Number of bytes received.
	 */
	uint32_t getRxDataCount(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the endpoint descriptor structure for the endpoint at the specified index.
	 *
	 * @param[in] index Index of the endpoint.
	 * @param[out] des Pointer to the structure to copy the endpoint descriptor.
	 * @return bool True if successful, false otherwise.
	 */
	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Gets the number of endpoints currently used by this USB class.
	 *
	 * @return uint8_t Number of active endpoints.
	 */
	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Callback executed when the USB device wakes up from suspend.
	 */
	virtual void handleWakeup(void) __attribute__((optimize("-O1"))) = 0;

protected :
	/**
	 * @brief USB Endpoint Direction enumeration.
	 */
	typedef enum
	{
		DIR_OUT = 0x00,              ///< Out endpoint (Host to Device).
		DIR_IN = 0x80                ///< In endpoint (Device to Host).
	}epDir_t;

	/**
	 * @brief USB Endpoint Transfer Type enumeration.
	 */
	typedef enum
	{
		TYPE_CONTROL = 0,            ///< Control transfer type.
		TYPE_ISOCHRONOUS,            ///< Isochronous transfer type.
		TYPE_BULK,                   ///< Bulk transfer type.
		TYPE_INTERRUPT,              ///< Interrupt transfer type.
	}epTransferType_t;

	uint8_t mSetupData[8];
	Usbd *mUsbd;

	/**
	 * @brief Utility helper function to initialize an endpoint descriptor to defaults.
	 *
	 * @param[out] des Pointer to the endpoint descriptor.
	 */
	void getEmptyEpDescriptor(epDesc_t *des) __attribute__((optimize("-O1")));

	/**
	 * @brief Utility helper function to initialize a device descriptor to defaults.
	 *
	 * @param[out] des Pointer to the device descriptor.
	 */
	void getEmptyDeviceDescriptor(devDesc_t *des) __attribute__((optimize("-O1")));

	/**
	 * @brief Utility helper function to initialize a configuration descriptor to defaults.
	 *
	 * @param[out] des Pointer to the configuration descriptor.
	 */
	void getEmptyConfigDescriptor(confignDesc_t *des) __attribute__((optimize("-O1")));

	/**
	 * @brief Utility helper function to initialize an interface descriptor to defaults.
	 *
	 * @param[out] des Pointer to the interface descriptor.
	 */
	void getEmptyInterfaceDescriptor(interfaceDesc_t *des) __attribute__((optimize("-O1")));

	/**
	 * @brief Utility helper function to generate a Unicode string descriptor from a standard C string.
	 *
	 * @param[out] des Pointer to the target destination buffer.
	 * @param[in] src Pointer to the source null-terminated C string.
	 * @return bool True if successful, false otherwise.
	 */
	bool generateStringDescriptor(uint8_t *des, char *src) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the received data size of the specified OUT endpoint.
	 *
	 * @param[in] ep Endpoint number.
	 * @return uint32_t Number of bytes received.
	 */
	uint32_t getOutRxDataSize(uint8_t ep) __attribute__((optimize("-O1")));

private :
	threadId_t mTriggerId;

	virtual void handleGetDeviceDescriptor(void) __attribute__((optimize("-O1"))) = 0;

	virtual void handleGetConfigDescriptor(uint16_t size) __attribute__((optimize("-O1"))) = 0;

	virtual void handleGetDeviceQualifierDescriptor(void) __attribute__((optimize("-O1"))) = 0;

	virtual void handleGetStringDescriptor(uint8_t index, uint16_t size) __attribute__((optimize("-O1"))) = 0;

	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1"))) = 0;

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1"))) = 0;
};

#endif


