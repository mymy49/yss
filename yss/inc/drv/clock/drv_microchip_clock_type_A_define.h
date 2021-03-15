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


#ifndef	YSS_DRV_CLOCK_MICROCHIP_TYPE_A_DEFINE__H_
#define	YSS_DRV_CLOCK_MICROCHIP_TYPE_A_DEFINE__H_

#if	defined (__SAML21E15A__) || defined (__SAML21E15B__) || defined (__SAML21E16A__) || defined (__SAML21E16B__) || \
	defined (__SAML21E17A__) || defined (__SAML21E17B__) || defined (__SAML21E18B__) || defined (__SAML21G16A__) || \
	defined (__SAML21G16B__) || defined (__SAML21G17A__) || defined (__SAML21G17B__) || defined (__SAML21G18A__) || \
	defined (__SAML21G18B__) || defined (__SAML21J16A__) || defined (__SAML21J16B__) || defined (__SAML21J17A__) || \
	defined (__SAML21J17B__) || defined (__SAML21J18A__) || defined (__SAML21J18B__)

namespace define
{
namespace clock
{

namespace gclk
{
namespace src
{
	enum
	{
		_XOSC = 0,
		_GCLK_IN = 1,
		_GCLK_GEN1 = 2,
		_OSCULP32K = 3,
		_OSC32K = 4,
		_XOSC32K = 5,
		_OSC16 = 6,
		_DFLL48M = 7,
		_DPLL96M = 8
	};
}
}

namespace dpll
{
namespace src
{
	enum
	{
		_XOSC32K = 0,
		_XOSC = 1,
		_GCLK = 2
	};
}
}

}
}

#endif

#endif
