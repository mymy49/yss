/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/Flash.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>
#include <util/Timeout.h>
#include <yss/thread.h>

error_t Flash::erasePage(uint16_t page)
{
	error_t result;

	enable(true);
	
	FMC->ISPADDR = getPageAddress(page);

	result = executeCommand(FMC_ISPCMD_FLASH_PAGE_ERASE);

	enable(false);

	if(result == error_t::ISPFF_FLAG)
		return error_t::LOCK_MODE;
	else
		return result;
}

error_t Flash::program(void *des, uint32_t *src, uint32_t count)
{
	uint32_t addr = (uint32_t)des;
	error_t result;

	for(uint32_t i = 0; i < count; i++)
	{
		result = program32bit(addr, *src++);
		if(result != error_t::ERROR_NONE)
			return result;
		addr += 4;
	}

	return error_t::ERROR_NONE;
}

error_t Flash::program(uint16_t page, uint32_t *src, uint32_t count)
{
	uint32_t addr = getPageAddress(page);
	error_t result;

	for(uint32_t i = 0; i < count; i++)
	{
		result = program32bit(addr, *src++);
		if(result != error_t::ERROR_NONE)
			return result;
		addr += 4;
	}

	return error_t::ERROR_NONE;
}

error_t Flash::read4Xbytes(uint16_t page, uint16_t sector, uint16_t count, uint32_t *dataReg)  //최대 4Kb 읽기, 1섹터당 4byte, 1카운트 당 4byte, dataReg 크기는 4byte당 1
{
	uint32_t addr = getPageAddress(page) + sector;
	error_t result;

	for(uint16_t i = 0; i < count; i++)
	{
		result = read32bit(addr,dataReg++);
		if(result != error_t::ERROR_NONE)
			return result;
		addr = addr + 4;
	}

	return result;
}

uint32_t Flash::getPageAddress(uint16_t page)
{
	return (uint32_t)page * 4096;
}

error_t Flash::program32bit(uint32_t addr, uint32_t data)
{
	error_t result;

	enable(true);
	
	FMC->ISPADDR = addr;
	FMC->MPDAT0 = data;

	result = executeCommand(FMC_ISPCMD_FLASH_32BIT_PROGRAM);

	enable(false);

	if(result == error_t::ISPFF_FLAG)
		return error_t::BROWN_OUT_DETECTED;
	else if(FMC->ISPSTS & FMC_ISPSTS_PGFF_Msk)
		return error_t::FAILED_FLASH_PROGRAM;
	else
		return result;
}

error_t Flash::read32bit(uint32_t addr, uint32_t* data)
{
	error_t result;

	enable(true);

	FMC->ISPADDR = addr;
	
	result = executeCommand(FMC_ISPCMD_FLASH_READ);

	if(result == error_t::ERROR_NONE)
		data[0] = FMC->ISPDAT;
	
	return result;	
}

error_t Flash::executeCommand(uint8_t cmd)
{
	error_t result;
	Timeout timeout(1000);

	FMC->ISPCTL |= FMC_ISPCTL_APUEN_Msk;
	FMC->ISPCMD = cmd;
	FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
	
	while(1)
	{
		if(~FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)
		{
			result = error_t::ERROR_NONE;
			break;
		}

		if(FMC->ISPSTS & FMC_ISPSTS_ISPFF_Msk)
		{
			result = error_t::ISPFF_FLAG;
			break;
		}
		
		if(timeout.isTimeout())
		{
			result = error_t::TIMEOUT;
			break;
		}

		thread::yield();
	}

	FMC->ISPCTL &= ~FMC_ISPCTL_APUEN_Msk;

	return result;
}

error_t Flash::enable(bool en)
{
	if(en)
	{
		// unlock	
		SYS->REGLCTL = 0x59;
		SYS->REGLCTL = 0x16;
		SYS->REGLCTL = 0x88;
		
		// ISP enable	
		FMC->ISPCTL |= FMC_ISPCTL_ISPEN_Msk;
	}
	else
	{
		// ISP disable	
		FMC->ISPCTL &= ~FMC_ISPCTL_ISPEN_Msk;

		// lock
		SYS->REGLCTL = 0x00;
	}

	return error_t::ERROR_NONE;
}

#endif

