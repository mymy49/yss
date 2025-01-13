/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/NuvotonDualCdc.h>
#include <string.h>
#include <drv/Usbd.h>

extern const uint8_t gNuvotonDualCdcConfigDescriptor[];


NuvotonDualCdc::NuvotonDualCdc(void)
{
	mIntInEpNum0 = gNuvotonDualCdcConfigDescriptor[47] & 0x0F;
	mBulkInEpNum0 = gNuvotonDualCdcConfigDescriptor[63] & 0x0F;
	mBulkOutEpNum0 = gNuvotonDualCdcConfigDescriptor[70] & 0x0F;

	mIntInEpNum1 = gNuvotonDualCdcConfigDescriptor[113] & 0x0F;
	mBulkInEpNum1 = gNuvotonDualCdcConfigDescriptor[136] & 0x0F;
	mBulkOutEpNum1 = gNuvotonDualCdcConfigDescriptor[129] & 0x0F;
}

error_t NuvotonDualCdc::initialize(const config_t &config)
{
	return DualCdc::initialize(config);
}

bool NuvotonDualCdc::getEpDescriptor(uint8_t index, epDesc_t *des)
{
	getEmptyEpDescriptor(des);

	switch(index)
	{
	case 0 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[47];
		des->bInterval = 0x01;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[49];
		des->bmAttributes = TYPE_INTERRUPT;
		return true;
	
	case 1 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[63];
		des->bInterval = 0x00;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[65];
		des->bmAttributes = TYPE_BULK;
		return true;
	
	case 2 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[70];
		des->bInterval = 0x00;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[72];
		des->bmAttributes = TYPE_BULK;
		return true;

	case 3 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[113];
		des->bInterval = 0x01;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[115];
		des->bmAttributes = TYPE_INTERRUPT;
		return true;
	
	case 4 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[136];
		des->bInterval = 0x00;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[138];
		des->bmAttributes = TYPE_BULK;
		return true;
	
	case 5 :
		des->bEndpointAddress = gNuvotonDualCdcConfigDescriptor[129];
		des->bInterval = 0x00;
		des->wMaxPacketSize = gNuvotonDualCdcConfigDescriptor[131];
		des->bmAttributes = TYPE_BULK;
		return true;

	default :
		return false;
	}
}

void NuvotonDualCdc::handleGetDeviceDescriptor(void)
{
	devDesc_t des;

	getEmptyDeviceDescriptor(&des);

	des.bcdUSB = 0x0110;
	des.bDeviceClass = 0xEF;
	des.bDeviceSubclass = 0x02;
	des.bDeviceProtocol = 0x01;
	des.bMaxPacketSize0 = 64;
	des.idVendor = 0x0416;
	des.idProduct = 0x50A1;
	des.bcdDevice = 0x0003;

	if(mConfig.manufactureString)
		des.iManufacturer = 1;
	else
		des.iManufacturer = 0;

	if(mConfig.productString)
		des.iProduct = 2;
	else
		des.iProduct = 0;
	
	if(mConfig.serialNumberString)
		des.iSerialNumber = 3;
	else
		des.iSerialNumber = 0;

	des.bNumConfigurations = 1;

	mUsbd->lock();
	mUsbd->send(0, &des, des.bLength, true);
	mUsbd->unlock();
}

void NuvotonDualCdc::handleGetConfigDescriptor(uint16_t size)
{
	uint8_t buf[141];

	if(size > 141)
		size = 141;
	
	memcpy(buf, gNuvotonDualCdcConfigDescriptor, size);

	mUsbd->lock();
	mUsbd->send(0, buf, size, true);
	mUsbd->unlock();
}

void NuvotonDualCdc::handleGetStringDescriptor(uint8_t index, uint16_t size)
{
	uint8_t buf[256];
	bool result = false;

	switch(index)
	{
	case 0 :
		*(uint32_t*)buf = 0x04090304;
		result = true;
		break;

	case 1 :
		result = generateStringDescriptor(buf, (char*)mConfig.manufactureString);
		break;
	
	case 2 :
		result = generateStringDescriptor(buf, (char*)mConfig.productString);
		break;

	case 3 :
		result = generateStringDescriptor(buf, (char*)mConfig.serialNumberString);
		break;
	}

	if(size > buf[0])
		size = buf[0];

	mUsbd->lock();
	if(result)
		mUsbd->send(0, buf, size, true);
	else
		mUsbd->stall(0);
	mUsbd->unlock();
}


void NuvotonDualCdc::handleGetDeviceQualifierDescriptor(void)
{
	mUsbd->lock();
	mUsbd->stall(0);
	mUsbd->unlock();
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

/* Define the interrupt In EP number */
#define BULK_IN_EP_NUM      0x01
#define BULK_OUT_EP_NUM     0x02
#define INT_IN_EP_NUM       0x03
#define BULK_IN_EP_NUM_1    0x04
#define BULK_OUT_EP_NUM_1   0x05
#define INT_IN_EP_NUM_1     0x06

#define EP2_MAX_PKT_SIZE    64
#define EP3_MAX_PKT_SIZE    64
#define EP4_MAX_PKT_SIZE    8


 /*!<USB Configure Descriptor */
const uint8_t gNuvotonDualCdcConfigDescriptor[] =
{
	LEN_CONFIG,     /* bLength              */
	DESC_CONFIG,    /* bDescriptorType      */
	0x8D, 0x00,     /* wTotalLength         */
	0x04,           /* bNumInterfaces       */
	0x01,           /* bConfigurationValue  */
	0x00,           /* iConfiguration       */
	0xC0,           /* bmAttributes         */
	0x32,           /* MaxPower             */

	// IAD
	0x08,   // bLength: Interface Descriptor size
	0x0B,   // bDescriptorType: IAD
	0x00,   // bFirstInterface
	0x02,   // bInterfaceCount
	0x02,   // bFunctionClass: CDC
	0x02,   // bFunctionSubClass
	0x01,   // bFunctionProtocol
	0x02,   // iFunction

	/* VCOM - 1 */
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
	(EP_INPUT | INT_IN_EP_NUM),     /* bEndpointAddress */
	EP_INT,                         /* bmAttributes     */
	0x08, 0x00,						/* wMaxPacketSize   */
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
	(EP_INPUT | BULK_IN_EP_NUM),    /* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x40, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	(EP_OUTPUT | BULK_OUT_EP_NUM),  /* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x40, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */

	// IAD
	0x08,   // bLength: Interface Descriptor size
	0x0B,   // bDescriptorType: IAD
	0x02,   // bFirstInterface
	0x02,   // bInterfaceCount
	0x02,   // bFunctionClass: CDC
	0x02,   // bFunctionSubClass
	0x01,   // bFunctionProtocol
	0x02,   // iFunction

	/* VCOM - 2 */
	/* INTERFACE descriptor */
	LEN_INTERFACE,  /* bLength              */
	DESC_INTERFACE, /* bDescriptorType      */
	0x02,           /* bInterfaceNumber     */
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
	0x03,           /* Interface number of data class interface optionally used for call management */

	/* Communication Class Specified INTERFACE descriptor */
	0x04,           /* Size of the descriptor, in bytes */
	0x24,           /* CS_INTERFACE descriptor type */
	0x02,           /* Abstract control management functional descriptor subtype */
	0x00,           /* bmCapabilities       */

	/* Communication Class Specified INTERFACE descriptor */
	0x05,           /* bLength              */
	0x24,           /* bDescriptorType: CS_INTERFACE descriptor type */
	0x06,           /* bDescriptorSubType   */
	0x02,           /* bMasterInterface     */
	0x03,           /* bSlaveInterface0     */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	(EP_INPUT | INT_IN_EP_NUM_1),   /* bEndpointAddress */
	EP_INT,                         /* bmAttributes     */
	0x08, 0x00,						/* wMaxPacketSize   */
	0x01,                           /* bInterval        */

	/* INTERFACE descriptor */
	LEN_INTERFACE,  /* bLength              */
	DESC_INTERFACE, /* bDescriptorType      */
	0x03,           /* bInterfaceNumber     */
	0x00,           /* bAlternateSetting    */
	0x02,           /* bNumEndpoints        */
	0x0A,           /* bInterfaceClass      */
	0x00,           /* bInterfaceSubClass   */
	0x00,           /* bInterfaceProtocol   */
	0x00,           /* iInterface           */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	(EP_OUTPUT | BULK_OUT_EP_NUM_1),/* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x40, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,                   /* bLength          */
	DESC_ENDPOINT,                  /* bDescriptorType  */
	(EP_INPUT | BULK_IN_EP_NUM_1),  /* bEndpointAddress */
	EP_BULK,                        /* bmAttributes     */
	0x40, 0x00,						/* wMaxPacketSize   */
	0x00,                           /* bInterval        */
};
