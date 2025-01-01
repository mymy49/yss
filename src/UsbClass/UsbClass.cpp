/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/UsbClass.h>

UsbClass::UsbClass(void)
{
	mUsbd = nullptr;
}

void UsbClass::setUsbd(Usbd *usbd)
{
	mUsbd = usbd;
}

void UsbClass::handleRxSetupPacket(void *data, uint32_t size)
{
	
}

