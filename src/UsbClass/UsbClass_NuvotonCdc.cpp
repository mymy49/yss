/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/NuvotonCdc.h>
#include <string.h>

extern const uint8_t gu8ConfigDescriptor[];


NuvotonCdc::NuvotonCdc(void)
{
	mConfig = nullptr;
}

bool NuvotonCdc::getEpDescriptor(uint8_t index, epDesc_t *des)
{
	getEmptyEpDescriptor(des);

	switch(index)
	{
	case 0 :
		des->bEndpointAddress = mConfig->ctlEpNum | DIR_IN;
		des->bInterval = 0x01;
		des->wMaxPacketSize = mConfig->ctlEpMaxPacketSize;
		des->bmAttributes = TYPE_INTERRUPT;
		return true;
	
	case 1 :
		des->bEndpointAddress = mConfig->inEpNum | DIR_IN;
		des->bInterval = 0x00;
		des->wMaxPacketSize = mConfig->inEpMaxPacketSize;
		des->bmAttributes = TYPE_BULK;
		return true;
	
	case 2 :
		des->bEndpointAddress = mConfig->outEpNum | DIR_OUT;
		des->bInterval = 0x00;
		des->wMaxPacketSize = mConfig->outEpMaxPacketSize;
		des->bmAttributes = TYPE_BULK;
		return true;

	default :
		return false;
	}
}

bool NuvotonCdc::getDeviceDescriptor(devDesc_t *des)
{
	getEmptyDeviceDescriptor(des);
	uint16_t max;

	if(mConfig->inEpMaxPacketSize > mConfig->outEpMaxPacketSize)
		max = mConfig->inEpMaxPacketSize;
	else
		max = mConfig->outEpMaxPacketSize;

	if(max > 64)
		max = 64;
	
	des->bcdUSB = 0x0110;
	des->bDeviceClass = 0x02;
	des->bDeviceSubclass = 0x00;
	des->bDeviceProtocol = 0x00;
	des->bMaxPacketSize0 = max;
	des->idVendor = 0x0416;
	des->idProduct = 0x50A1;
	des->bcdDevice = 0x0003;
	des->iManufacturer = 1;
	des->iProduct = 2;
	des->iSerialNumber = 3;
	des->bNumConfigurations = 1;

	return true;
}

bool NuvotonCdc::getConfigDescriptor(confignDesc_t *des, uint8_t size)
{
	uint8_t *cdes = (uint8_t*)des;
	
	memcpy(des, gu8ConfigDescriptor, size);
	cdes[0] = size;

	// IN Interrupt bEndpointAddress
	cdes[39] = (mConfig->ctlEpNum & 0x0F) | 0x80;

	// IN Interrupt wMaxPacketSize
	cdes[41] = mConfig->ctlEpMaxPacketSize;
	
	// IN Bulk bEndpointAddress
	cdes[55] = (mConfig->inEpNum & 0x0F) | 0x80;

	// IN Bulk wMaxPacketSize
	cdes[57] = mConfig->inEpMaxPacketSize;

	// OUT Bulk bEndpointAddress
	cdes[62] = (mConfig->outEpNum & 0x0F);

	// OUT Bulk wMaxPacketSize
	cdes[64] = mConfig->outEpMaxPacketSize;

	return true;
}

bool NuvotonCdc::getDeviceQualifierDescriptor(devQualifier_t *des)
{
	return false;
}

/***************************************************************************//**
 * @file     descriptors.c
 * @brief    M433 series USBD driver source file
 * @version  2.0.0
 *
 * Apache License 2.0
 * @copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
/* USB Descriptor Length */
#define LEN_DEVICE          18ul
#define LEN_QUALIFIER       10ul
#define LEN_CONFIG          9ul
#define LEN_INTERFACE       9ul
#define LEN_ENDPOINT        7ul
#define LEN_OTG             5ul
#define LEN_BOS             5ul
#define LEN_HID             9ul
#define LEN_CCID            0x36ul
#define LEN_BOSCAP          7ul

/* USB Descriptor Type */
#define DESC_DEVICE         0x01ul
#define DESC_CONFIG         0x02ul
#define DESC_STRING         0x03ul
#define DESC_INTERFACE      0x04ul
#define DESC_ENDPOINT       0x05ul
#define DESC_QUALIFIER      0x06ul
#define DESC_OTHERSPEED     0x07ul
#define DESC_IFPOWER        0x08ul
#define DESC_OTG            0x09ul
#define DESC_BOS            0x0Ful
#define DESC_CAPABILITY     0x10ul

/* USB Endpoint Type */
#define EP_ISO              0x01
#define EP_BULK             0x02
#define EP_INT              0x03

#define EP_INPUT            0x80
#define EP_OUTPUT           0x00

 /*!<USB Configure Descriptor */
const uint8_t gu8ConfigDescriptor[] =
{
	LEN_CONFIG,     /* bLength              */
	DESC_CONFIG,    /* bDescriptorType      */
	0x43, 0x00,     /* wTotalLength         */
	0x02,           /* bNumInterfaces       */
	0x01,           /* bConfigurationValue  */
	0x00,           /* iConfiguration       */
	0xC0,           /* bmAttributes         */
	0x32,           /* MaxPower             */

    /* INTERFACE descriptor */
    LEN_INTERFACE,  /* bLength              */
    DESC_INTERFACE, /* bDescriptorType      */
    0x00,           /* bInterfaceNumber     */
    0x00,           /* bAlternateSetting    */
    0x01,           /* bNumEndpoints        */
    0x02,           /* bInterfaceClass      */
    0x02,           /* bInterfaceSubClass   */
    0x01,           /* bInterfaceProtocol   */
    0x00,           /* iInterface           */

	/* Communication Class Specified INTERFACE descriptor */
	0x05,           /* Size of the descriptor, in bytes */
	0x24,           /* CS_INTERFACE descriptor type */
	0x00,           /* Header functional descriptor subtype */
	0x10, 0x01,     /* Communication device compliant to the communication spec. ver. 1.10 */

	/* Communication Class Specified INTERFACE descriptor */
	0x05,           /* Size of the descriptor, in bytes */
	0x24,           /* CS_INTERFACE descriptor type */
	0x01,           /* Call management functional descriptor */
	0x00,           /* BIT0: Whether device handle call management itself. */
	/* BIT1: Whether device can send/receive call management information over a Data Class Interface 0 */
	0x01,           /* Interface number of data class interface optionally used for call management */

	/* Communication Class Specified INTERFACE descriptor */
	0x04,           /* Size of the descriptor, in bytes */
	0x24,           /* CS_INTERFACE descriptor type */
	0x02,           /* Abstract control management functional descriptor subtype */
	0x00,           /* bmCapabilities       */

	/* Communication Class Specified INTERFACE descriptor */
	0x05,           /* bLength              */
	0x24,           /* bDescriptorType: CS_INTERFACE descriptor type */
	0x06,           /* bDescriptorSubType   */
	0x00,           /* bMasterInterface     */
	0x01,           /* bSlaveInterface0     */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	0,								/* bEndpointAddress */
	0,								/* bmAttributes     */
	0x00, 0x00,						/* wMaxPacketSize   */
	0x01,                           /* bInterval        */

	/* INTERFACE descriptor */
	LEN_INTERFACE,  /* bLength              */
	DESC_INTERFACE, /* bDescriptorType      */
	0x01,           /* bInterfaceNumber     */
	0x00,           /* bAlternateSetting    */
	0x02,           /* bNumEndpoints        */
	0x0A,           /* bInterfaceClass      */
	0x00,           /* bInterfaceSubClass   */
	0x00,           /* bInterfaceProtocol   */
	0x00,           /* iInterface           */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	0x00,							/* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x00, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	0x00,							/* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x00, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */
};

