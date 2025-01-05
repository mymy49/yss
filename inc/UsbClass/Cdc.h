/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_CDC__H_
#define YSS_USB_CLASS_CDC__H_

#include "UsbClass.h"
#include <yss/error.h>

class Cdc : public UsbClass
{
	static const uint8_t mUsingEpCount = 3;

public :
/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bDescriptorSubtype;
		uint16_t bcdCDC;
	}csInterfaceDesc_t __attribute__ ((__packed__));
#pragma GCC diagnostic pop

	typedef struct 
	{
		uint8_t inEpNum;
		uint16_t inEpMaxPacketSize;
		uint8_t outEpNum;
		uint16_t outEpMaxPacketSize;
		uint8_t ctlEpNum;
		uint16_t ctlEpMaxPacketSize;
	}config_t;

	Cdc(void);

	error_t initialize(const config_t &config);

	virtual uint8_t getUsingEpCount(void); // pure

	virtual void handleWakeup(void); // pure

protected :
	const config_t *mConfig;

	void getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des);

private :
};

#endif

