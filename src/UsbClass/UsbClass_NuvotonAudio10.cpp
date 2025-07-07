/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/NuvotonAudio10.h>
#include <string.h>
#include <drv/Usbd.h>
#include <yss/debug.h>

#define NUVOTON_ORIGINAL		false

#define AUDIO_RATE_48K   48000       /* The audo play sampling rate. The setting is 48KHz */
#define AUDIO_RATE_96K   96000       /* The audo play sampling rate. The setting is 96KHz */
#define AUDIO_RATE_441K  44100       /* The audo play sampling rate. The setting is 44.1KHz */

// 현재 AUDIO_RATE_48K 외에는 정상동작 하지 않음
#define AUDIO_RATE  AUDIO_RATE_48K

extern const uint8_t gNuvotonAudio10ConfigDescriptor[];

NuvotonAudio10::NuvotonAudio10(void)
{
#if NUVOTON_ORIGINAL
	mOutEpNum = gNuvotonAudio10ConfigDescriptor[0xAE + 2] & 0x0F;
	mInEpNum = gNuvotonAudio10ConfigDescriptor[0x7C + 2] & 0x0F;
#else
	mOutEpNum = gNuvotonAudio10ConfigDescriptor[0x5E + 2] & 0x0F;
#endif

	memset(&mConfig, 0x00, sizeof(mConfig));
}

error_t NuvotonAudio10::initialize(const config_t &config)
{
	mConfig = config;

	return error_t::ERROR_NONE;
}

bool NuvotonAudio10::getEpDescriptor(uint8_t index, epDesc_t *des)
{
	switch(index)
	{
#if NUVOTON_ORIGINAL
	case 0 :
		memcpy(des, &gNuvotonAudio10ConfigDescriptor[0x7C], sizeof(epDesc_t));
		return true;

	case 1 :
		memcpy(des, &gNuvotonAudio10ConfigDescriptor[0xAE], sizeof(epDesc_t));
		return true;
#else
	case 0 :
		memcpy(des, &gNuvotonAudio10ConfigDescriptor[0x5E], sizeof(epDesc_t));
		return true;
#endif
	default :
		return false;
	}
	return false;
}

uint8_t NuvotonAudio10::getUsingEpCount(void)
{
#if NUVOTON_ORIGINAL
	return 2;
#else
	return 1;
#endif
}

void NuvotonAudio10::handleGetDeviceDescriptor(void)
{
	devDesc_t des;

	getEmptyDeviceDescriptor(&des);

	des.bcdUSB = 0x0110;
	des.bDeviceClass = 0x00;
	des.bDeviceSubclass = 0x00;
	des.bDeviceProtocol = 0x00;
	des.bMaxPacketSize0 = 64;
	des.idVendor = 0x0416;
	des.idProduct = 0x1286;
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

void NuvotonAudio10::handleGetConfigDescriptor(uint16_t size)
{
	uint8_t buf[0xBE];

	if(size > 0xBE)
		size = 0xBE;
	
	memcpy(buf, gNuvotonAudio10ConfigDescriptor, size);

	mUsbd->lock();
	mUsbd->send(0, buf, size, true);
	mUsbd->unlock();
}

void NuvotonAudio10::handleGetStringDescriptor(uint8_t index, uint16_t size)
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


void NuvotonAudio10::handleGetDeviceQualifierDescriptor(void)
{
	mUsbd->lock();
	mUsbd->stall(0);
	mUsbd->unlock();
}

uint32_t NuvotonAudio10::getSampleRate(void)
{
	return AUDIO_RATE;
}

void NuvotonAudio10::handleSetConfiguration(uint16_t value)
{
	mUsbd->lock();
	mUsbd->send(0, 0, 0, true);
	mUsbd->unlock();
}

void NuvotonAudio10::handleClassSpecificRequest(void)
{
	uint8_t rcvSize, bufU8;
	uint32_t bufU32;
	uint16_t bufU16;

	if(mSetupData[0] & 0x80) // Device to Host
	{
		switch(mSetupData[1])
		{
		case 0x81 : // 
			if((mSetupData[0] & 0x0F) == 0x02)
			{
				mUsbd->lock();
				bufU32 = AUDIO_RATE;
				mUsbd->send(0, &bufU32, mSetupData[6], true);
				mUsbd->unlock();
			}
			else
			{
				switch(mSetupData[3])
				{
				case 0x01 : // Mute Control
					if(mSetupData[5] == 0x05) // Rec
					{
						mUsbd->lock();
						bufU8 = 1;
						mUsbd->send(0, &bufU8, 1, true);
						mUsbd->unlock();
					}
					else if(mSetupData[5] == 0x06) // Play
					{
						mUsbd->lock();

						if(mConfig.callback_getPlayMute)
							bufU8 = mConfig.callback_getPlayMute();
						else
							bufU8 = 1;

						mUsbd->send(0, &bufU8, 0, true);
						mUsbd->unlock();
					}
					break;
				
				case 0x02 : // Volume Control
					if(mSetupData[5] == 0x05) // Rec
					{
						mUsbd->lock();
						bufU16 = 0x1000;
						mUsbd->send(0, &bufU16, 2, true);
						mUsbd->unlock();
					}
					else if(mSetupData[5] == 0x06) // Play
					{
						mUsbd->lock();
						if(mConfig.callback_getPlayVolume)
							bufU16 = mConfig.callback_getPlayVolume();
						else
							bufU16 = 0x1000;
						mUsbd->send(0, &bufU16, 2, true);
						mUsbd->unlock();
					}
					break;

				default:
					mUsbd->lock();
					mUsbd->stall(0);
					mUsbd->unlock();
					break;
				}
			}
			break;

		case 0x82 : // Get Min
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x8000;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					if(mConfig.callback_getPlayVolumeMin)
						bufU16 = mConfig.callback_getPlayVolumeMin();
					else
						bufU16 = 0x8000;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
			break;
		
		case 0x83 : // Get Max
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x7FFF;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					if(mConfig.callback_getPlayVolumeMax)
						bufU16 = mConfig.callback_getPlayVolumeMax();
					else
						bufU16 = 0x7FFF;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
			break;

		case 0x84 : // Get Resolution
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x0400;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					if(mConfig.callback_getPlayVolumeResolution)
						bufU16 = mConfig.callback_getPlayVolumeResolution();
					else
						bufU16 = 0x0400;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
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
	else
	{
		switch(mSetupData[1])
		{
		case 0x01 : // Mute Control
			if(mSetupData[5] == 0x05) // Rec
			{
				
			}
			else if(mSetupData[5] == 0x06) // Play
			{
				//if(mConfig.callback_setPlayMute(
			}

			mUsbd->lock();
			mUsbd->send(0, 0, 0, true);
			mUsbd->unlock();
			break;
			
		case 0x02 : // Volume
			if(mSetupData[5] == 0x05) // Rec
			{
				
			}
			else if(mSetupData[5] == 0x06) // Play
			{
				//if(mConfig.callback_setPlayMute(
			}

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
}	 





/**************************************************************************//**
 * @file     descriptors.c
 * @version  V1.00
 * @brief    M480 HSUSBD driver source file
 *
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

/*!<Define Audio information */
#define PLAY_CHANNELS   2
#define PLAY_BIT_RATE   0x10    /* 16-bit data rate */

#define REC_CHANNELS    2
#define REC_BIT_RATE    0x10    /* 16-bit data rate */

#define REC_FEATURE_UNITID      0x05
#define PLAY_FEATURE_UNITID     0x06

#define BUFF_LEN    800

/* Define the interrupt In EP number */
#define ISO_IN_EP_NUM    0x01
#define ISO_OUT_EP_NUM   0x02

/* Define EP maximum packet size */
#define EP0_MAX_PKT_SIZE    64
#define EP1_MAX_PKT_SIZE    EP0_MAX_PKT_SIZE
#define EP2_MAX_PKT_SIZE    (AUDIO_RATE*4/1000) //(AUDIO_RATE*REC_CHANNELS*2/1000)
#define EP3_MAX_PKT_SIZE    (AUDIO_RATE*4/1000) //(AUDIO_RATE*PLAY_CHANNELS*2/1000)

#if NUVOTON_ORIGINAL
/*!<USB Configure Descriptor */
const uint8_t gNuvotonAudio10ConfigDescriptor[0xBE] =
{

    LEN_CONFIG,     /* bLength */
    DESC_CONFIG,    /* bDescriptorType */
    0xBE, 0x00,         /* wTotalLength */
                        /*
                           Configuration Descriptor                    (0x09)
                           Interface Descriptor (Audio Class)          (0x09)
                           Audio Control Interface Header Descriptor   (0x0A)
                           Microphone - Audio Control
                             Audio Control Input Terminal Descriptor   (0x0C)
                             Audio Control Feature Unit Descriptor     (0x08)
                             Audio Control Output Terminal Descriptor  (0x09)
                           Speaker - Audio Control
                             Audio Control Input Terminal Descriptor   (0x0C)
                             Audio Control Feature Unit Descriptor     (0x0A)
                             Audio Control Output Terminal Descriptor  (0x09)
                           Microphone - Interface alternate 0
                             Standard AS interface                     (0x09)
                           Microphone - Interface alternate 1~6
                             Standard AS interface                                         (0x09)
                             Audio Streaming Class Specific Interface Descriptor           (0x07)
                             Audio Streaming Format Type Descriptor                        (0x0E)
                             Endpoint Descriptor                                           (0x07)
                             Audio Streaming Class Specific Audio Data Endpoint Descriptor (0x07)
                             *Each Interface alternate Summary                             (0x2C)
                           Speaker - Interface alternate 0
                             Standard AS interface                     (0x09)
                           Speaker - Interface alternate 1~4
                             Standard AS interface                                         (0x09)
                             Audio Streaming Class Specific Interface Descriptor           (0x07)
                             Audio Streaming Format Type Descriptor                        (0x0E)
                             Endpoint Descriptor                                           (0x09)
                             Audio Streaming Class Specific Audio Data Endpoint Descriptor (0x07)
                             *Each Interface alternate Summary                             (0x2E)

                           0x09 + 0x09 + 0x0A + (0x0C + 0x08 + 0x09) + (0x0C + 0x0A + 0x09) +
                           0x09 + 0x2C
                           0x09 + 0x2E = 0xC4
                        */
    0x03,               /* bNumInterfaces - Interface 0, Interface 1 (Microphone), Interface 2 (Speaker) */
    0x01,               /* bConfigurationValue */
    0x00,               /* iConfiguration */
    0x80,               /* bmAttributes */
    0x20,               /* Max power */

    /* Interface Descriptor (Audio Class) */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x00,               /* bInterfaceNumber */
    0x00,               /* bAlternateSetting */
    0x00,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x01,               /* bInterfaceSubClass:AUDIOCONTROL */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Audio Control Interface Header Descriptor */
    0x0A,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x01,               /* bDescriptorSubType:HEADER */
    0x00, 0x01,         /* bcdADC:1.0 */
    0x46, 0x00,         /* wTotalLength
                           Audio Control Interface Header Descriptor  (0x0A)
                           Microphone - Audio Control
                             Audio Control Input Terminal Descriptor  (0x0C)
                             Audio Control Feature Unit Descriptor    (0x08)
                             Audio Control Output Terminal Descriptor (0x09)
                           Speaker - Audio Control
                             Audio Control Input Terminal Descriptor  (0x0C)
                             Audio Control Feature Unit Descriptor    (0x0A)
                             Audio Control Output Terminal Descriptor (0x09)

                             0x0A + (0x0C + 0x08 + 0x09) + (0x0C + 0x0A + 0x09) = 0x46
                        */
    0x02,               /* bInCollection */
    0x01,               /* baInterfaceNr(1) - Microphone */
    0x02,               /* baInterfaceNr(2) - Speaker */

    /* Audio Control Input Terminal Descriptor - Microphone (Terminal ID 4) */
    0x0C,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:INPUT_TERMINAL*/
    0x04,               /* bTerminalID*/
    0x02,0x04,          /* wTerminalType: Headset */
    0x00,               /* bAssocTerminal*/
    0x02,               /* bNrChannels : a number that specifies how many logical audio channels are present in the cluster */
    0x03, 0x00,         /* wChannelConfig: a bit field that indicates which spatial locations are present in the cluster.
                           The bit allocations are as follows:
                             D0: Left Front (L)
                             D1: Right Front (R)
                             D2: Center Front (C)
                             D3: Low Frequency Enhancement (LFE)
                             D4: Left Surround (LS)
                             D5: Right Surround (RS)
                             D6: Left of Center (LC)
                             D7: Right of Center (RC)
                             D8: Surround (S)
                             D9: Side Left (SL)
                             D10: Side Right (SR)
                             D11: Top (T)
                             D15..12: Reserved
                        */
    0x00,               /* iChannelNames*/
    0x00,               /* iTerminal*/

    /* Audio Control Feature Unit Descriptor - Microphone (UNIT ID 5 - Source 4) */
    0x08,               /* bLength */
    0x24,               /* bDescriptorType */
    0x06,               /* bDescriptorSubType */
    REC_FEATURE_UNITID, /* bUnitID */
    0x04,               /* bSourceID */
    0x01,               /* bControlSize - Size, in bytes, of the bmControls field: n */
    0x03,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x00,               /* iFeature */

    /* Audio Control Output Terminal Descriptor - Microphone (Terminal ID 2 - Source ID 5) */
    0x09,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x03,               /* bDescriptorSubType:OUTPUT_TERMINAL */
    0x02,               /* bTerminalID */
    0x01,0x01,          /* wTerminalType: 0x0101 usb streaming */
    0x00,               /* bAssocTerminal */
    REC_FEATURE_UNITID, /* bSourceID */
    0x00,               /* iTerminal */

    /* Audio Control Input Terminal Descriptor - Speaker (Terminal ID 1) */
    0x0C,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:INPUT_TERMINAL */
    0x01,               /* bTerminalID */
    0x01,0x01,          /* wTerminalType: USB streaming */
    0x00,               /* bAssocTerminal */
    0x02,               /* bNrChannels : a number that specifies how many logical audio channels are present in the cluster */
    0x03,0x00,          /* wChannelConfig: a bit field that indicates which spatial locations are present in the cluster.
                           The bit allocations are as follows:
                             D0: Left Front (L)
                             D1: Right Front (R)
                             D2: Center Front (C)
                             D3: Low Frequency Enhancement (LFE)
                             D4: Left Surround (LS)
                             D5: Right Surround (RS)
                             D6: Left of Center (LC)
                             D7: Right of Center (RC)
                             D8: Surround (S)
                             D9: Side Left (SL)
                             D10: Side Right (SR)
                             D11: Top (T)
                             D15..12: Reserved
                        */
    0x00,               /* iChannelNames */
    0x00,               /* iTerminal */

    /* Audio Control Feature Unit Descriptor - Speaker (UNIT ID 6 - Source ID 1) */
    0x0A,               /* bLength */
    0x24,               /* bDescriptorType */
    0x06,               /* bDescriptorSubType */
    PLAY_FEATURE_UNITID,/* bUnitID */
    0x01,               /* bSourceID */
    0x01,               /* bControlSize - Size, in bytes, of the bmControls field: n */
    0x01,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x02,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x02,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x00,               /* iFeature */

    /* Audio Control Output Terminal Descriptor - Speaker (UNIT ID 3 - Source ID 5) */
    0x09,               /* bLength*/
    0x24,               /* bDescriptorType:CS_INTERFACE*/
    0x03,               /* bDescriptorSubType:OUTPUT_TERMINAL*/
    0x03,               /* bTerminalID*/
    0x02,0x04,          /* wTerminalType: Headset */
    0x00,               /* bAssocTerminal*/
    PLAY_FEATURE_UNITID,/* bSourceID*/
    0x00,               /* iTerminal*/

    /* Interface Descriptor - Interface 1, alternate 0 */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x01,               /* bInterfaceNumber */
    0x00,               /* bAlternateSetting */
    0x00,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Interface Descriptor - Interface 1, alternate 1 */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x01,               /* bInterfaceNumber */
    0x01,               /* bAlternateSetting */
    0x01,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Audio Streaming Class Specific Interface Descriptor (this interface's endpoint connect to Terminal ID 0x02 - Microphoe) */
    0x07,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x01,               /* bDescriptorSubType:AS_GENERAL */
    0x02,               /* bTernimalLink */
    0x01,               /* bDelay */
    0x01,0x00,          /* wFormatTag:0x0001 PCM */

    /* Audio Streaming Format Type Descriptor */
    0x0B,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:FORMAT_TYPE */
    0x01,               /* bFormatType:FORMAT_TYPE_I */
                        /* Standard AS interface 1, alternate 1 */
    0x02,               /* bNrChannels    :  2 Channels */
    0x02,               /* bSubFrameSize  :  2 bytes per sample */
    0x10,               /* bBitResolution : 16 bits  per sample */
    0x01,               /* bSamFreqType :
                           0 Continuous sampling frequency
                           1 The number of discrete sampling frequencies */
    /* bSamFreqType  */
    (AUDIO_RATE & 0xFF),
    ((AUDIO_RATE >> 8) & 0xFF),
    ((AUDIO_RATE >> 16) & 0xFF),

    /* Endpoint Descriptor (ISO IN Audio Data Endpoint - alternate 1) */
    0x07,                             /* bLength */
    0x05,                             /* bDescriptorType */
    ISO_IN_EP_NUM | EP_INPUT,         /* bEndpointAddress */
    0x05,                             /* bmAttributes */
    /* wMaxPacketSize note */
    EP2_MAX_PKT_SIZE & 0x00FF,
    ((EP2_MAX_PKT_SIZE & 0xFF00) >> 8),
    0x01,                             /* bInterval*/

    /* Audio Streaming Class Specific Audio Data Endpoint Descriptor */
    0x07,               /* bLength */
    0x25,               /* bDescriptorType:CS_ENDPOINT */
    0x01,               /* bDescriptorSubType:EP_GENERAL */
    0x01,               /* bmAttributes, Bit 0: Sampling Frequency */
    0x00,               /* bLockDelayUnits */
    0x00, 0x00,         /* wLockDelay */

    /* Interface Descriptor - Interface 2, alternate 0
        Interface 2 for Speaker & Microphone
    */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x02,               /* bInterfaceNumber */
    0x00,               /* bAlternateSetting */
    0x00,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Interface Descriptor - Interface 2, alternate 1
        Interface 2 for Speaker & Microphone
    */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x02,               /* bInterfaceNumber */
    0x01,               /* bAlternateSetting */
    0x01,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Audio Streaming Class Specific Interface Descriptor (this interface's endpoint connect to Terminal ID 0x01 - Speaker) */
    0x07,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x01,               /* bDescriptorSubType:AS_GENERAL */
    0x01,               /* bTernimalLink (Speaker) */
    0x01,               /* bDelay */
    0x01,0x00,          /* wFormatTag:0x0001 PCM */

    /* Audio Streaming Format Type Descriptor */
    0x0B,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:FORMAT_TYPE */
    0x01,               /* bFormatType:FORMAT_TYPE_I */
                        /* Standard AS interface 2, alternate 1 */
    0x02,               /* bNrChannels    :  2 Channels */
    0x02,               /* bSubFrameSize  :  2 bytes per sample */
    0x10,               /* bBitResolution : 16 bits  per sample */
    0x01,               /* bSamFreqType :
                           0 Continuous sampling frequency
                           1 The number of discrete sampling frequencies */
    /* bSamFreqType  */
    (AUDIO_RATE & 0xFF),
    ((AUDIO_RATE >> 8) & 0xFF),
    ((AUDIO_RATE >> 16) & 0xFF),

    /* Endpoint Descriptor (ISO OUT Audio Data Endpoint - alternate 1) */
    0x09,                             /* bLength */
    0x05,                             /* bDescriptorType */
    ISO_OUT_EP_NUM | EP_OUTPUT,       /* bEndpointAddress */
    0x09,                             /* bmAttributes */
    /* wMaxPacketSize note */
    EP3_MAX_PKT_SIZE & 0x00FF,
    ((EP3_MAX_PKT_SIZE & 0xFF00) >> 8),
    0x01,                             /* bInterval */
    0x00,                             /* bRefresh */
    0x00,                             /* bSynchAddress */

    /* Audio Streaming Class Specific Audio Data Endpoint Descriptor */
    0x07,               /* bLength */
    0x25,               /* bDescriptorType:CS_ENDPOINT */
    0x01,               /* bDescriptorSubType:EP_GENERAL */
    0x01,               /* bmAttributes, Bit 7: MaxPacketsOnly, Bit 0: Sampling Frequency */
    0x01,               /* bLockDelayUnits */
    0x01, 0x00,         /* wLockDelay */
};
#else
 /*!<USB Configure Descriptor */
const uint8_t gNuvotonAudio10ConfigDescriptor[0x6E] =
{
    LEN_CONFIG,     /* bLength */
    DESC_CONFIG,    /* bDescriptorType */
    0x6E, 0x00,         /* wTotalLength */
                        /*
                           Configuration Descriptor                    (0x09)
                           Interface Descriptor (Audio Class)          (0x09)
                           Audio Control Interface Header Descriptor   (0x09)
                           Speaker - Audio Control
                             Audio Control Input Terminal Descriptor   (0x0C)
                             Audio Control Feature Unit Descriptor     (0x0A)
                             Audio Control Output Terminal Descriptor  (0x09)
                           Speaker - Interface alternate 0
                             Standard AS interface                     (0x09)
                           Speaker - Interface alternate 1~4
                             Standard AS interface                                         (0x09)
                             Audio Streaming Class Specific Interface Descriptor           (0x07)
                             Audio Streaming Format Type Descriptor                        (0x0B)
                             Endpoint Descriptor                                           (0x09)
                             Audio Streaming Class Specific Audio Data Endpoint Descriptor (0x07)
                        */
    0x02,               /* bNumInterfaces - Interface 0, Interface 1 (Speaker) */
    0x01,               /* bConfigurationValue */
    0x00,               /* iConfiguration */
    0x80,               /* bmAttributes */
    0x20,               /* Max power */

    /* Interface Descriptor (Audio Class) */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x00,               /* bInterfaceNumber */
    0x00,               /* bAlternateSetting */
    0x00,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x01,               /* bInterfaceSubClass:AUDIOCONTROL */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Audio Control Interface Header Descriptor */
    0x09,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x01,               /* bDescriptorSubType:HEADER */
    0x00, 0x01,         /* bcdADC:1.0 */
    0x28, 0x00,         /* wTotalLength
                           Audio Control Interface Header Descriptor  (0x09)
                           Speaker - Audio Control
                             Audio Control Input Terminal Descriptor  (0x0C)
                             Audio Control Feature Unit Descriptor    (0x0A)
                             Audio Control Output Terminal Descriptor (0x09)

                             0x09 + (0x0C + 0x08 + 0x09) = 0x28
                        */
    0x01,               /* bInCollection */
    0x01,               /* baInterfaceNr(1) - Speaker */

    /* Audio Control Input Terminal Descriptor - Speaker (Terminal ID 1) */
    0x0C,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:INPUT_TERMINAL */
    0x01,               /* bTerminalID */
    0x01,0x01,          /* wTerminalType: USB streaming */
    0x00,               /* bAssocTerminal */
    0x02,               /* bNrChannels : a number that specifies how many logical audio channels are present in the cluster */
    0x03,0x00,          /* wChannelConfig: a bit field that indicates which spatial locations are present in the cluster.
                           The bit allocations are as follows:
                             D0: Left Front (L)
                             D1: Right Front (R)
                             D2: Center Front (C)
                             D3: Low Frequency Enhancement (LFE)
                             D4: Left Surround (LS)
                             D5: Right Surround (RS)
                             D6: Left of Center (LC)
                             D7: Right of Center (RC)
                             D8: Surround (S)
                             D9: Side Left (SL)
                             D10: Side Right (SR)
                             D11: Top (T)
                             D15..12: Reserved
                        */
    0x00,               /* iChannelNames */
    0x00,               /* iTerminal */

    /* Audio Control Feature Unit Descriptor - Speaker (UNIT ID 6 - Source ID 1) */
    0x0A,               /* bLength */
    0x24,               /* bDescriptorType */
    0x06,               /* bDescriptorSubType */
    PLAY_FEATURE_UNITID,/* bUnitID */
    0x01,               /* bSourceID */
    0x01,               /* bControlSize - Size, in bytes, of the bmControls field: n */
    0x01,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x02,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x02,               /* bmaControls(0) */
                        /* A bit set to 1 indicates that the mentioned
                           Control is supported for master channel
                           0:
                           D0: Mute
                           D1: Volume
                           D2: Bass
                           D3: Mid
                           D4: Treble
                           D5: Graphic Equalizer
                           D6: Automatic Gain
                           D7: Delay
                           D8: Bass Boost
                           D9: Loudness
                           D10..(n*8-1): Reserved
                        */
    0x00,               /* iFeature */

    /* Audio Control Output Terminal Descriptor - Speaker (UNIT ID 3 - Source ID 5) */
    0x09,               /* bLength*/
    0x24,               /* bDescriptorType:CS_INTERFACE*/
    0x03,               /* bDescriptorSubType:OUTPUT_TERMINAL*/
    0x02,               /* bTerminalID*/
    0x02,0x04,          /* wTerminalType: Headset */
    0x00,               /* bAssocTerminal*/
    PLAY_FEATURE_UNITID,/* bSourceID*/
    0x00,               /* iTerminal*/

    /* Interface Descriptor - Interface 2, alternate 0
        Interface 2 for Speaker & Microphone
    */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x01,               /* bInterfaceNumber */
    0x00,               /* bAlternateSetting */
    0x00,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Interface Descriptor - Interface 2, alternate 1
        Interface 2 for Speaker & Microphone
    */
    0x09,               /* bLength */
    0x04,               /* bDescriptorType */
    0x01,               /* bInterfaceNumber */
    0x01,               /* bAlternateSetting */
    0x01,               /* bNumEndpoints */
    0x01,               /* bInterfaceClass:AUDIO */
    0x02,               /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,               /* bInterfaceProtocol */
    0x00,               /* iInterface */

    /* Audio Streaming Class Specific Interface Descriptor (this interface's endpoint connect to Terminal ID 0x01 - Speaker) */
    0x07,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x01,               /* bDescriptorSubType:AS_GENERAL */
    0x01,               /* bTernimalLink (Speaker) */
    0x01,               /* bDelay */
    0x01,0x00,          /* wFormatTag:0x0001 PCM */

    /* Audio Streaming Format Type Descriptor */
    0x0B,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:FORMAT_TYPE */
    0x01,               /* bFormatType:FORMAT_TYPE_I */
                        /* Standard AS interface 2, alternate 1 */
    0x02,               /* bNrChannels    :  2 Channels */
    0x02,               /* bSubFrameSize  :  2 bytes per sample */
    0x10,               /* bBitResolution : 16 bits  per sample */
    0x01,               /* bSamFreqType :
                           0 Continuous sampling frequency
                           1 The number of discrete sampling frequencies */
    /* bSamFreqType  */
    (AUDIO_RATE & 0xFF),
    ((AUDIO_RATE >> 8) & 0xFF),
    ((AUDIO_RATE >> 16) & 0xFF),

    /* Endpoint Descriptor (ISO OUT Audio Data Endpoint - alternate 1) */
    0x09,                             /* bLength */
    0x05,                             /* bDescriptorType */
    ISO_OUT_EP_NUM | EP_OUTPUT,       /* bEndpointAddress */
    0x09,                             /* bmAttributes */
    /* wMaxPacketSize note */
    EP3_MAX_PKT_SIZE & 0x00FF,
    ((EP3_MAX_PKT_SIZE & 0xFF00) >> 8),
    0x01,                             /* bInterval */
    0x00,                             /* bRefresh */
    0x00,                             /* bSynchAddress */

    /* Audio Streaming Class Specific Audio Data Endpoint Descriptor */
    0x07,               /* bLength */
    0x25,               /* bDescriptorType:CS_ENDPOINT */
    0x01,               /* bDescriptorSubType:EP_GENERAL */
    0x01,               /* bmAttributes, Bit 7: MaxPacketsOnly, Bit 0: Sampling Frequency */
    0x01,               /* bLockDelayUnits */
    0x01, 0x00,         /* wLockDelay */
};

#endif

