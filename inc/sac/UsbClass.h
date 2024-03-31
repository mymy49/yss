////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

