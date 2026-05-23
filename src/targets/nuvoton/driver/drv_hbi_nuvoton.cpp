/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M46x_SUBFAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonHbi.h>
#include <yss/scheduler.h>
#include <yss/reg.h>
#include <yss/debug.h>
#include <util/Timeout.h>

error_t NuvotonHbi::initialize(config_t config, uint32_t hbiClkFreq)
{
	uint32_t reg = 0;
	int32_t buf;
	float ns;
	
	mCapacity = 0;

	if(hbiClkFreq == 0 || hbiClkFreq > config.maxFrequency)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	config.tACC_min_ns *= 2.f;
	config.tCSHI_min_ns *= 2.f;
	config.tCSH_min_ns *= 2.f;
	config.tCSM_max_us *= 2.f;
	config.tCSS_min_ns *= 2.f;
		
	ns = 1000000000.f / ((float)hbiClkFreq / 2.f);
	while(HBI->CMD);

	HBI->CMD = 0x1;	// Reset HyperRAM
	while(HBI->CMD);

	HBI->CMD = 0x5;	// Exit From Hybrid Sleep and deep power down
	while(HBI->CMD);

	//CSST
	buf = config.tCSS_min_ns / ns - 0.5f;
	if(buf < 0)
		buf = 0;
	else if(buf > 3)
		return error_t::WRONG_CLOCK_FREQUENCY;
	setFieldData(HBI->CONFIG, HBI_CONFIG_CSST_Msk, buf, HBI_CONFIG_CSST_Pos);

	//ACCT
	buf = config.tACC_min_ns / ns - 2.f;
	if(buf < 0)
		buf = 0;

	switch(buf)
	{
	case 0 : // 3 CK cycles
		buf = 0xE;
		break;

	case 1 : // 4 CK cycles
		buf = 0xF;
		break;

	case 2 : // 5 CK cycles
		buf = 0x0;
		break;

	case 3 : // 6 CK cycles
		buf = 0x1;
		break;

	case 4 : // 7 CK cycles
	case 5 : // 8 CK cycles
		buf = 0x2;
		break;
	
	default :
		return error_t::WRONG_CLOCK_FREQUENCY;
	}
	setFieldData(HBI->CONFIG, HBI_CONFIG_ACCT_Msk, buf, HBI_CONFIG_ACCT_Pos);

	//CSH
	buf = config.tCSH_min_ns / ns + 0.5f;
	if(buf < 0)
		buf = 0;
	else if(buf > 3)
		return error_t::WRONG_CLOCK_FREQUENCY;
	setFieldData(HBI->CONFIG, HBI_CONFIG_CSH_Msk, buf, HBI_CONFIG_CSH_Pos);

	//CSHI
	buf = config.tCSHI_min_ns / ns;
	if(buf < 0)
		buf = 0;
	else if(buf > 15)
		return error_t::WRONG_CLOCK_FREQUENCY;
	setFieldData(HBI->CONFIG, HBI_CONFIG_CSHI_Msk, buf, HBI_CONFIG_CSHI_Pos);
	
	// BGSIZE
	switch(config.bgs)
	{
	case Hbi::BURST_GROUP_SIZE_16BYTES :
		buf = 2;
		break;

	case Hbi::BURST_GROUP_SIZE_32BYTES :
		buf = 3;
		break;

	case Hbi::BURST_GROUP_SIZE_64BYTES :
		buf = 1;
		break;

	case Hbi::BURST_GROUP_SIZE_128BYTES :
		buf = 0;
		break;
	
	default :
		return error_t::WRONG_CONFIG;
	}
	setFieldData(HBI->CONFIG, HBI_CONFIG_BGSIZE_Msk, buf, HBI_CONFIG_BGSIZE_Pos);

	// Endian
	setBitData(HBI->CONFIG, 0, HBI_CONFIG_ENDIAN_Pos);

	//CSMAXLT
	buf = config.tCSM_max_us * 1000.f / ns + 1.0f;
	if(buf < 0)
		buf = 0;
	else if(buf > 2048)
		return error_t::WRONG_CLOCK_FREQUENCY;
	setFieldData(HBI->CONFIG, HBI_CONFIG_CSMAXLT_Msk, buf, HBI_CONFIG_CSMAXLT_Pos);

	HBI->ADR = 0x000;
	HBI->WDATA = 0x10325476;
	
	HBI->INTSTS = 1;
	HBI->CMD = 0xF;	// Write 4 Bytes (Write Data[31:0]) to HyperRAM
	while(HBI->CMD);

	HBI->INTSTS = 1;
	HBI->CMD = 0x9;	// Read 2 words (Read Data[31:0]) from HyperRAM
	while(HBI->CMD);

	if(HBI->RDATA == 0x10325476)
	{
		mCapacity = config.capcacity;
		return error_t::ERROR_NONE;
	}
	else
		return error_t::UNKNOWN;
}

void NuvotonHbi::isr(void)
{

}

#endif

