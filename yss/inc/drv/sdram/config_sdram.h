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

#ifndef	YSS_DRV_SDRAM_ST_CONFIG__H_
#define	YSS_DRV_SDRAM_ST_CONFIG__H_

namespace config
{
namespace sdram
{
	struct Config_
	{
		unsigned char columnAddress;
		unsigned char rowAddress;
		unsigned char dbusWidth;
		unsigned char internalBank;
		unsigned char casLatency;
		unsigned long maxFrequency;
		unsigned long tMrd;
		unsigned long tXsr;
		unsigned long tRas;
		unsigned long tRc;
		unsigned long tWr;
		unsigned long tRp;
		unsigned long tRcd;
		unsigned long tOh;
		unsigned long tAc;
		unsigned long tRefresh;
		unsigned short numOfRow;
		bool writeProtection;
		bool burstRead;
		unsigned short mode;
	};

	typedef	const Config_ Config;
}

namespace sdram
{
	struct Sdcr
	{
		unsigned nc	: 2;
		unsigned nr	: 2;
		unsigned mwid :	2;
		unsigned nb	: 1;
		unsigned cas : 2;
		unsigned wp	: 1;
		unsigned sdclk : 2;
		unsigned rburst	: 1;
		unsigned rpipe : 2;
		unsigned rsv : 16;
	};
}
}

#endif
