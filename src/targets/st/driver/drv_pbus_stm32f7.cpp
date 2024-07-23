/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F7)

#include <drv/Pbus.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if defined(FMC_Bank1)

Pbus::Pbus(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	
}

error_t Pbus::initialize(void)
{
	// 장치 활성화
	for(uint8_t i = 0; i < 4; i++)
	{
		FMC_Bank1->BTCR[i*2] |= FMC_BCR1_MBKEN_Msk;
	}

	return error_t::ERROR_NONE;
}

error_t Pbus::setSpecification(const specification_t &spec)
{
	for(uint8_t i = 0; i < 4; i++)
	{
		FMC_Bank1->BTCR[i*2+1] =	((spec.dataLatency - 2) << FMC_BTR1_DATLAT_Pos & FMC_BTR1_DATLAT_Msk) |
								((spec.clockDiv - 1) << FMC_BTR1_CLKDIV_Pos & FMC_BTR1_CLKDIV_Msk) |
								((spec.busTurnaround) << FMC_BTR1_BUSTURN_Pos & FMC_BTR1_BUSTURN_Msk) |
								((spec.data - 1) << FMC_BTR1_DATAST_Pos & FMC_BTR1_DATAST_Msk) |
								((spec.addrHold) << FMC_BTR1_ADDHLD_Pos & FMC_BTR1_ADDHLD_Msk) |
								((spec.addrSetup) << FMC_BTR1_ADDSET_Pos & FMC_BTR1_ADDSET_Msk);
	}

	return error_t::ERROR_NONE;
}

#endif

#endif

