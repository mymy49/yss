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
	error_t erasePage(uint16_t page) __attribute__((optimize("-O1")));

	uint32_t getPageAddress(uint16_t page) __attribute__((optimize("-O1")));

	error_t program(void *des, uint32_t *src, uint32_t count) __attribute__((optimize("-O1")));

	error_t program(uint16_t page, uint32_t *src, uint32_t count) __attribute__((optimize("-O1")));
	
	error_t read4Xbytes(uint16_t page, uint16_t sector, uint16_t count, uint32_t *dataReg);				//page : 페이지 , sector : 페이지 내 위치(4byte 단위), count : 읽어올 바이트 수 (1 입력 시 4바이트 리드), dataReg : 읽은 데이터 기록할 주소 
	
private :
	error_t executeCommand(uint8_t cmd) __attribute__((optimize("-O1")));

	error_t enable(bool en) __attribute__((optimize("-O1")));

	error_t program32bit(uint32_t addr, uint32_t data) __attribute__((optimize("-O1")));

	error_t read32bit(uint32_t addr, uint32_t* data) __attribute__((optimize("-O1")));
};

#endif

