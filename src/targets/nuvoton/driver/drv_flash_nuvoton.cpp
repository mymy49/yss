/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <drv/Flash.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m48x.h>

error_t Flash::erasePage(uint16_t page)
{
	enable(true);
	
	FMC->ISPCTL |= FMC_ISPCTL_APUEN_Msk;

	FMC->ISPADDR = getPageAddress(page);

	executeCommand(FMC_ISPCMD_FLASH_PAGE_ERASE);

	FMC->ISPCTL &= ~FMC_ISPCTL_APUEN_Msk;

	enable(false);

	return error_t::ERROR_NONE;
}

uint32_t Flash::getPageAddress(uint16_t page)
{
	return (uint32_t)page * 4096;
}

error_t Flash::executeCommand(uint8_t cmd)
{
	FMC->ISPCMD = cmd;
	FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

	return error_t::ERROR_NONE;
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

