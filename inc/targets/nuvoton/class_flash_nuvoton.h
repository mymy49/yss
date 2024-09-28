/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_FLASH_NUVOTON__H_
#define YSS_CLASS_FLASH_NUVOTON__H_

#include <yss/error.h>
#include <drv/mcu.h>

class Flash
{
public :
	error_t erasePage(uint16_t page);

private :
	error_t executeCommand(uint8_t cmd);

	error_t enable(bool en);

	uint32_t getPageAddress(uint16_t page);
};

#endif

