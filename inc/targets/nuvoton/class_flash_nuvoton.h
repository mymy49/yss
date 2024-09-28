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

	uint32_t getPageAddress(uint16_t page);

	error_t program(void *des, uint32_t *src, uint32_t count);

	error_t program(uint16_t page, uint32_t *src, uint32_t count);
	
private :
	error_t executeCommand(uint8_t cmd);

	error_t enable(bool en);

	error_t program32bit(uint32_t addr, uint32_t data);
};

#endif

