/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_USB_CLASS__H_
#define YSS_SAC_USB_CLASS__H_

#include <stdint.h>
#include <yss/error.h>

class Usbd;

class UsbClass
{
public:
	struct Request_t
	{
		uint16_t wRequest;
		uint16_t wValue;
		uint16_t wIndex;
		uint16_t wLength;
	}__attribute__ ((__packed__));

	struct DeviceDescriptor_t
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
	}__attribute__ ((__packed__));

	struct DeviceQualifier_t
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
	}__attribute__ ((__packed__));

	struct ConfigurationDescriptor_t
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t wTotalLength;
		uint8_t bNumInterfaces;
		uint8_t bConfigurationValue;
		uint8_t bConfiguration;
		uint8_t bmAttributes;
		uint8_t bMaxPower;
	}__attribute__ ((__packed__));

	struct InterfaceDescriptor_t
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
	}__attribute__ ((__packed__));

	struct ConfigurationAttribute_t
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}__attribute__ ((__packed__));

	struct EndpointDescriptor_t
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}__attribute__ ((__packed__));

	error_t handleGetDeviceDescriptor(Request_t *request);

	virtual error_t initialize(Usbd *usb) = 0;

	virtual const DeviceDescriptor_t* getDeviceDescriptor(void) = 0;

	virtual uint32_t getInEndpointFifoSize(uint8_t epNum) = 0;

	virtual uint32_t getOutEndpointFifoSize(void) = 0;

	virtual uint32_t getUsingFifoCount(void) = 0;
};

//class UsbMscClass : public UsbClass
//{
//public :
//	virtual const DeviceDescriptor_t* getDeviceDescriptor(void);	// pure
//};

#endif

