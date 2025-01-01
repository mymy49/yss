/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS__H_
#define YSS_USB_CLASS__H_

#include <stdint.h>
#include <yss/error.h>

class Usbd;

class UsbClass
{
public :
	struct
	{
		uint16_t wRequest;
		uint16_t wValue;
		uint16_t wIndex;
		uint16_t wLength;
	}request_t __attribute__ ((__packed__));

	struct
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
	}deviceDescriptor_t __attribute__ ((__packed__));

	struct
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
	}deviceQualifier_t __attribute__ ((__packed__));

	struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t wTotalLength;
		uint8_t bNumInterfaces;
		uint8_t bConfigurationValue;
		uint8_t bConfiguration;
		uint8_t bmAttributes;
		uint8_t bMaxPower;
	}configurationDescriptor_t __attribute__ ((__packed__));

	struct 
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
	}interfaceDescriptor_t;

	struct 
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}configurationAttribute_t __attribute__ ((__packed__));

	struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bEndpointAddress;
		uint8_t bmAttributes;
		uint16_t wMaxPacketSize;
		uint8_t bInterval;
	}endpointDescriptor_t __attribute__ ((__packed__));

	void handleRxSetupPacket(void *data, uint32_t size);

	void setUsbd(Usbd *usbd);

	//virtual const deviceDescriptor_t* getDeviceDescriptor(void) = 0;

	//virtual uint32_t getInEndpointFifoSize(uint8_t epNum) = 0;

	//virtual uint32_t getOutEndpointFifoSize(void) = 0;

	//virtual uint32_t getUsingFifoCount(void) = 0;

	UsbClass(void);

private :
	Usbd *mUsbd;
};

//class UsbMscClass : public UsbClass
//{
//public :
//	virtual const DeviceDescriptor_t* getDeviceDescriptor(void);	// pure
//};

#endif

