/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/UsbClass.h>
#include <drv/Usbd.h>
#include <yss/debug.h>

static void trigger_process(void *var)
{
	UsbClass *obj = (UsbClass*)var;

	obj->process();
}

UsbClass::UsbClass(void)
{
	mUsbd = nullptr;

	mTriggerId = trigger::add(trigger_process, this, 512);
}

void UsbClass::setUsbd(Usbd *usbd)
{
	mUsbd = usbd;
}

void UsbClass::handleRxSetupPacket(void *data)
{
	uint32_t *des = (uint32_t*)mSetupData, *src = (uint32_t*)data;
	
	*des++ = *src++;
	*des++ = *src++;
	
	trigger::run(mTriggerId);
}

void UsbClass::getEmptyEpDescriptor(epDesc_t *des)
{
	*des = 
	{
		0x07,	//uint8_t bLength;
		0x05,	//uint8_t bDescriptorType;
				//uint8_t bEndpointAddress;
				//uint8_t bmAttributes;
				//uint16_t wMaxPacketSize;
				//uint8_t bInterval;
	};
}

void UsbClass::getEmptyDeviceDescriptor(devDesc_t *des)
{
	*des = 
	{
		0x12,		//uint8_t bLength;
		0x01,		//uint8_t bDescriptorType;
		0x0200,		//uint16_t bcdUSB;
					//uint8_t bDeviceClass;
					//uint8_t bDeviceSubclass;
					//uint8_t bDeviceProtocol;
					//uint8_t bMaxPacketSize0;
					//uint16_t idVendor;
					//uint16_t idProduct;
					//uint16_t bcdDevice;
					//uint8_t iManufacturer;
					//uint8_t iProduct;
					//uint8_t iSerialNumber;
					//uint8_t bNumConfigurations;
	};
}

void UsbClass::getEmptyConfigDescriptor(confignDesc_t *des)
{
	*des = 
	{
		0x09,	//uint8_t bLength;
		0x02,	//uint8_t bDescriptorType;
				//uint16_t wTotalLength;
				//uint8_t bNumInterfaces;
				//uint8_t bConfigurationValue;
				//uint8_t bConfiguration;
				//uint8_t bmAttributes;
				//uint8_t bMaxPower;
	};
}

void UsbClass::getEmptyInterfaceDescriptor(interfaceDesc_t *des)
{
	*des = 
	{
		0x09,	//uint8_t bLength;
		0x04,	//uint8_t bDescriptorType;
				//uint8_t bInterfaceNumber;
				//uint8_t bAlternateSetting;
				//uint8_t bNumEndpoints;
				//uint8_t bInterfaceClass;
				//uint8_t bInterfaceSubClass;
				//uint8_t bInterfaceProtocol;
				//uint8_t iInterface;
	};
}

void UsbClass::process(void)
{
	request_t *request = (request_t*)mSetupData;
	uint8_t buf[256];
	bool ableFlag = false;
	bool addrFlag = false;

	switch(request->wRequest)
	{
	case 0x0680 : // Get Descriptor

		switch(request->wValue)
		{
		case 0x0100 : // Device Descriptor
			ableFlag = getDeviceDescriptor((devDesc_t*)buf);
			break;

		case 0x0200 : // Configuration Descriptor
			ableFlag = getConfigDescriptor((confignDesc_t*)buf, request->wLength);
			break;

		case 0x0600 : // Device Qualifier Descriptor
			ableFlag = getDeviceQualifierDescriptor((devQualifier_t*)buf);
			break;

		default :
			ableFlag = false;
			break;
		}		
		break;

	case 0x0500 : // Set Address
		ableFlag = true;
		addrFlag = true;
		*buf = 0;
		break;

	default :
		ableFlag = false;
		break;
	}
	
	mUsbd->lock();

	if(ableFlag)
		mUsbd->send(0, buf, *buf);
	else
		mUsbd->stall(0);

	if(addrFlag)
		mUsbd->setAddress(request->wValue);
		
	mUsbd->unlock();
}

