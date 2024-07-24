/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/UsbClass.h>

error_t UsbClass::handleGetDeviceDescriptor(Request_t *request)
{
	(void)request;
	return error_t::ERROR_NONE;
}

//const UsbClass::DeviceDescriptor_t* UsbMscClass::getDeviceDescriptor(void)
//{
//	return 0;
//}

