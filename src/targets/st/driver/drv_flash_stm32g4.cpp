/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Flash.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

void Flash::enableDataCache(bool en)
{
	setBitData(FLASH->ACR, en, FLASH_ACR_DCEN_Pos);
}

void Flash::enableInstructionCache(bool en)
{
	setBitData(FLASH->ACR, en, FLASH_ACR_ICEN_Pos);
}

void Flash::enablePrefetch(bool en)
{
	setBitData(FLASH->ACR, en, FLASH_ACR_PRFTEN_Pos);
}

#endif


