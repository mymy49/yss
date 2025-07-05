/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/*
#include <mod/usbd/MSC.h>

#if !defined(YSS_DRV_USBD_UNSUPPORTED)

uint32_t Msc::getInEndpointFifoSize(uint8_t epNum)
{
#warning "추후에 MSC에서 용량을 Config로 받도록 수정해야 함"
	switch(epNum)
	{
	case 0 :
		return 0x100;
	
	case 1 :
		return 0x100;
	
	case 2 :
		return 0x100;
	
	default :
		return 0x00; 
	}
}

uint32_t Msc::getOutEndpointFifoSize(void)
{
#warning "추후에 MSC에서 용량을 Config로 받도록 수정해야 함"
	return 0x100;
}

uint32_t Msc::getUsingFifoCount(void)
{
	return 3;
}

#endif

*/