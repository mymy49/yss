/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/sdram/AS4C16M16SA_7TCN.h>

#if defined(STM32F429xx)
#include <targets/st/define_stm32f429xx.h>
#elif defined(STM32F446xx)
#include <targets/st/define_stm32f446xx.h>
#endif

#ifndef YSS_DRV_SDRAM_UNSUPPORTED

#define	MODE_BURST_LENGTH_1				((uint16_t)0x0000)
#define	MODE_BURST_LENGTH_2				((uint16_t)0x0001)
#define	MODE_BURST_LENGTH_4				((uint16_t)0x0002)
#define	MODE_BURST_LENGTH_8				((uint16_t)0x0004)
#define	MODE_BURST_TYPE_SEQUENTIAL		((uint16_t)0x0000)
#define	MODE_BURST_TYPE_INTERLEAVED		((uint16_t)0x0008)
#define	MODE_CAS_LATENCY_2				((uint16_t)0x0020)
#define	MODE_CAS_LATENCY_3				((uint16_t)0x0030)
#define	MODE_OPERATING_MODE_STANDARD	((uint16_t)0x0000)
#define	MODE_WRITEBURST_MODE_PROGRAMMED	((uint16_t)0x0000)
#define	MODE_WRITEBURST_MODE_SINGLE		((uint16_t)0x0200)

const Sdram::specification_t AS4C16M16SA_7TCN =
{
	define::sdram::columnAddress::BIT9,		//	uint8_t columnAddress;
	define::sdram::rowAddress::BIT13,		//	uint8_t rowAddress;
	define::sdram::dbusWidth::BIT16,		//	uint8_t dbusWidth;
	define::sdram::internalBank::FOUR,		//	uint8_t internalBank;
	define::sdram::casLatency::TWO,			//	uint8_t casLatency;
	143000000,								//	uint32_t maxFrequency;
	14000,									//	float tMrd;
	70000,									//	float tXsr;
	42000,									//	float tRas;
	63000,									//	float tRc;
	14000,									//	float tWr;
	21000,									//	float tRp;
	21000,									//	float tRcd;
	2500,									//	float tOh;
	6000,									//	uint32_t tAc;
	64000,										//	float tRefresh;
	8192,									//	uint16_t numOfRow;
	false,									//	bool writeProtection;
	false,									//	bool burstRead;
	MODE_BURST_LENGTH_1						//	uint16_t mode;
	| MODE_BURST_TYPE_SEQUENTIAL
	| MODE_CAS_LATENCY_2
	| MODE_WRITEBURST_MODE_PROGRAMMED
};

#endif
