/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/UsbClass.h>
#include <drv/Usbd.h>
#include <yss/debug.h>
#include <string.h>

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

uint32_t UsbClass::getOutRxDataSize(uint8_t ep)
{
	return mUsbd->getOutRxDataSize(ep);
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

	switch(mSetupData[0] & 0x60)
	{
	case 0x00 : // Standard Device Requests
		if(mSetupData[0] & 0x80) // Device to Host
		{
			switch(mSetupData[1])
			{
			case 0x06 : // Get Descriptor
				switch(mSetupData[3])
				{
				case 0x01 : // Device Descriptor
					handleGetDeviceDescriptor();
					break;

				case 0x02 : // Configuration Descriptor
					handleGetConfigDescriptor(request->wLength);
					break;

				case 0x06 : // Device Qualifier Descriptor
					handleGetDeviceQualifierDescriptor();
					break;

				case 0x03 : // String Descriptor
					handleGetStringDescriptor(mSetupData[2], request->wLength);
					break;
					
				default :
					mUsbd->lock();
					mUsbd->stall(0);
					mUsbd->unlock();
					break;
				}
				break;

			default :
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
		}
		else // Host to Device
		{
			switch(mSetupData[1])
			{
			case 0x01 : // Clear Feature
				mUsbd->lock();
				mUsbd->clearFeature(mSetupData[4]);
				mUsbd->send(0, 0, 0, true);
				mUsbd->unlock();
				break;

			case 0x05 : // Set Address
				mUsbd->lock();
				mUsbd->send(0, 0, 0, true);
				mUsbd->unlock();
				mUsbd->setAddress(request->wValue);
				break;

			case 0x09 : // Set Configuration
				handleSetConfiguration(request->wValue);
				break;

			case 0x0B : // Set Interface
				mUsbd->lock();
				mUsbd->send(0, 0, 0, true);
				mUsbd->unlock();
				break;

			default :
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
		}
		break;

	case 0x20 : // Class-specific Requests 
		handleClassSpecificRequest();
		break;
	}
}

bool UsbClass::generateStringDescriptor(uint8_t *des, char *src)
{
	uint8_t len = strlen(src);
	
	if(len > 0 && len < 126)
	{
		len *= 2;
		des[0] = len + 2;	// uint8_t bLength;
		des[1] = 0x03;		// uint8_t bDescriptorType;

		for(uint8_t i = 0; i < len; i+= 2)
		{
			des[2 + i] = *src++;
			des[3 + i] = 0;
		}

		return true;
	}
	else
	{
		return false;
	}
}
