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
#include <yss/thread.h>

class Usbd;

class UsbClass
{
public :
/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
	typedef struct
	{
		uint16_t wRequest;
		uint16_t wValue;
		uint16_t wIndex;
		uint16_t wLength;
	}request_t __attribute__ ((__packed__));

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bcdUSB;
		uint8_t bDeviceClass;
		uint8_t bDeviceSubclass;
		uint8_t bDeviceProtocol;
		uint8_t bMaxPacketSize0;
		uint16_t idVendor;
		uint16_t idProduct;
		uint16_t bcdDevice;
		uint8_t iManufacturer;
		uint8_t iProduct;
		uint8_t iSerialNumber;
		uint8_t bNumConfigurations;
	}devDesc_t __attribute__ ((__packed__));

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bcdUSB;
		uint8_t bDeviceClass;
		uint8_t bDeviceSubclass;
		uint8_t bDeviceProtocol;
		uint8_t bMaxPacketSize0;
		uint8_t bNumConfigurations;
		uint8_t Reserved;
	}devQualifier_t __attribute__ ((__packed__));

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t wTotalLength;
		uint8_t bNumInterfaces;
		uint8_t bConfigurationValue;
		uint8_t bConfiguration;
		uint8_t bmAttributes;
		uint8_t bMaxPower;
	}confignDesc_t __attribute__ ((__packed__));

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bInterfaceNumber;
		uint8_t bAlternateSetting;
		uint8_t bNumEndpoints;
		uint8_t bInterfaceClass;
		uint8_t bInterfaceSubClass;
		uint8_t bInterfaceProtocol;
		uint8_t iInterface;
	}interfaceDesc_t;

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}configurationAttribute_t __attribute__ ((__packed__));

	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}epDesc_t __attribute__ ((__packed__));
#pragma GCC diagnostic pop

	UsbClass(void);

	void handleRxSetupPacket(void *data);

	void setUsbd(Usbd *usbd);

	void process(void);

	uint32_t getRxDataCount(void);

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) = 0;

	virtual uint8_t getUsingEpCount(void) = 0;

	virtual void handleWakeup(void) = 0;

protected :
	typedef enum
	{
		DIR_OUT = 0x00,
		DIR_IN = 0x80
	}epDir_t;

	typedef enum
	{
		TYPE_CONTROL = 0,
		TYPE_ISOCHRONOUS,
		TYPE_BULK,
		TYPE_INTERRUPT,
	}epTransferType_t;

	uint8_t mSetupData[8];
	Usbd *mUsbd;

	void getEmptyEpDescriptor(epDesc_t *des);

	void getEmptyDeviceDescriptor(devDesc_t *des);

	void getEmptyConfigDescriptor(confignDesc_t *des);

	void getEmptyInterfaceDescriptor(interfaceDesc_t *des);

	bool generateStringDescriptor(uint8_t *des, char *src);

	uint32_t getOutRxDataSize(uint8_t ep);

private :
	threadId_t mTriggerId;

	virtual void handleGetDeviceDescriptor(void) = 0;

	virtual void handleGetConfigDescriptor(uint16_t size) = 0;

	virtual void handleGetDeviceQualifierDescriptor(void) = 0;

	virtual void handleGetStringDescriptor(uint8_t index) = 0;

	virtual void handleSetConfiguration(uint16_t value) = 0;

	virtual void handleClassSpecificRequest(void) = 0;
};

#endif

