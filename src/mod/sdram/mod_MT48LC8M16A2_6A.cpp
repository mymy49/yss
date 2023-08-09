////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/sdram/MT48LC8M16A2_6A.h>

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

const Sdram::Specification MT48LC8M16A2_6A =
{
	define::sdram::columnAddress::BIT9,		//	uint8_t columnAddress;
	define::sdram::rowAddress::BIT12,		//	uint8_t rowAddress;
	define::sdram::dbusWidth::BIT16,		//	uint8_t dbusWidth;
	define::sdram::internalBank::FOUR,		//	uint8_t internalBank;
	define::sdram::casLatency::TWO,			//	uint8_t casLatency;
	167000000,								//	uint32_t maxFrequency;
	12000,									//	uint32_t tMrd;
	67000,									//	uint32_t tXsr;
	42000,									//	uint32_t tRas;
	60000,									//	uint32_t tRc;
	18000,									//	uint32_t tWr;
	18000,									//	uint32_t tRp;
	18000,									//	uint32_t tRcd;
	3000,									//	uint32_t tOh;
	7500,									//	uint32_t tAc;
	64000,									//	uint32_t tRefresh;
	4096,									//	uint16_t numOfRow;
	false,									//	bool writeProtection;
	false,									//	bool burstRead;
	MODE_BURST_LENGTH_1						//	uint16_t mode;
	| MODE_BURST_TYPE_SEQUENTIAL
	| MODE_CAS_LATENCY_2
	| MODE_WRITEBURST_MODE_PROGRAMMED
};

#endif
