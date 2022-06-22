////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/sdram/MT48LC8M16A2_6A.h>

#if defined(FMC_Bank5_6) || defined(EXMC)

#define	MODE_BURST_LENGTH_1				((unsigned short)0x0000)
#define	MODE_BURST_LENGTH_2				((unsigned short)0x0001)
#define	MODE_BURST_LENGTH_4				((unsigned short)0x0002)
#define	MODE_BURST_LENGTH_8				((unsigned short)0x0004)
#define	MODE_BURST_TYPE_SEQUENTIAL		((unsigned short)0x0000)
#define	MODE_BURST_TYPE_INTERLEAVED		((unsigned short)0x0008)
#define	MODE_CAS_LATENCY_2				((unsigned short)0x0020)
#define	MODE_CAS_LATENCY_3				((unsigned short)0x0030)
#define	MODE_OPERATING_MODE_STANDARD	((unsigned short)0x0000)
#define	MODE_WRITEBURST_MODE_PROGRAMMED	((unsigned short)0x0000)
#define	MODE_WRITEBURST_MODE_SINGLE		((unsigned short)0x0200)

drv::Sdram::Specification MT48LC16M16A2_6A =
{
	define::sdram::columnAddress::BIT9,		//	unsigned char columnAddress;
	define::sdram::rowAddress::BIT13,		//	unsigned char rowAddress;
	define::sdram::dbusWidth::BIT16,		//	unsigned char dbusWidth;
	define::sdram::internalBank::FOUR,		//	unsigned char internalBank;
	define::sdram::casLatency::TWO,			//	unsigned char casLatency;
	167000000,								//	unsigned long maxFrequency;
	12000,									//	unsigned long tMrd;
	67000,									//	unsigned long tXsr;
	42000,									//	unsigned long tRas;
	60000,									//	unsigned long tRc;
	18000,									//	unsigned long tWr;
	18000,									//	unsigned long tRp;
	18000,									//	unsigned long tRcd;
	3000,									//	unsigned long tOh;
	7500,									//	unsigned long tAc;
	64000,									//	unsigned long tRefresh;
	4096,									//	unsigned short numOfRow;
	false,									//	bool writeProtection;
	false,									//	bool burstRead;
	MODE_BURST_LENGTH_1						//	unsigned short mode;
	| MODE_BURST_TYPE_SEQUENTIAL
	| MODE_CAS_LATENCY_2
	| MODE_WRITEBURST_MODE_PROGRAMMED
};

#endif
