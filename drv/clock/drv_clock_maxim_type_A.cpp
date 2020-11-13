////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(MAX32660)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include "pwrseq_regs.h"
#include "gcr_regs.h"
#include "flc_regs.h"

drv::Clock clock;

namespace drv
{
	unsigned int gSystemClockFreq __attribute__ ((section (".non_init")));

	void Clock::setSystemClock(unsigned char src, unsigned char vcore, unsigned char psc)
	{
		unsigned int reg, wait;
		bool lve = false;

		reg = MXC_GCR->memckcn;
		reg &= ~MXC_F_GCR_MEMCKCN_FWS;
		reg |= 5 << MXC_F_GCR_MEMCKCN_FWS_POS;
		MXC_GCR->memckcn = reg;

		if(psc > 7)
			psc = 7;

		switch(src)
		{
		case define::clock::src::HFIO :
			switch(vcore)
			{
			case define::clock::vcore::V0_9_24MHZ:
				gSystemClockFreq = 24000000;
				MXC_PWRSEQ->lpcn &= ~(0x3 << 4);
				MXC_FLC->cn |= MXC_F_FLC_CN_LVE;
				lve = true;
				reg = MXC_GCR->clkcn;
				reg &= ~(MXC_F_GCR_CLKCN_CLKSEL | MXC_F_GCR_CLKCN_PSC);
				reg |= psc << MXC_F_GCR_CLKCN_PSC_POS;
				MXC_GCR->clkcn = reg;
				break;
			}
		}

		gSystemClockFreq /= 1 << psc;
		if(lve)
			wait = (gSystemClockFreq + 11999999) / 12000000;
		else
			wait = (gSystemClockFreq + 23999999) / 24000000;

		reg = MXC_GCR->memckcn;
		reg &= ~MXC_F_GCR_MEMCKCN_FWS;
		reg |= wait << MXC_F_GCR_MEMCKCN_FWS_POS;
		MXC_GCR->memckcn = reg;

	}
}

#endif
