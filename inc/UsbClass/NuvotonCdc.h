/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_NUVOTON_CDC__H_
#define YSS_USB_CLASS_NUVOTON_CDC__H_

#include "Cdc.h"

class NuvotonCdc : public Cdc
{
public :
	NuvotonCdc(void);

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des); // pure

	virtual bool getDeviceDescriptor(devDesc_t *des); // pure

	virtual bool getConfigDescriptor(confignDesc_t *des, uint8_t size); // pure

	virtual bool getDeviceQualifierDescriptor(devQualifier_t *des); // pure

private :
};

#endif

