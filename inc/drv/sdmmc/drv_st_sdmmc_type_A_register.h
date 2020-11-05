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

#ifndef YSS_DRV_SDMMC1_ST_TYPE_A_REGISTER__H_
#define YSS_DRV_SDMMC1_ST_TYPE_A_REGISTER__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <yss/reg.h>

#define setSdmmcPowerControl(x)						setRegField(SDMMC1->POWER, 0x3, x, 0)

#define setSdmmcClkDiv(x)							setRegField(SDMMC1->CLKCR, 0xff, x, 0)
#define setSdmmcClkEn(x)							setRegBit(SDMMC1->CLKCR, x, 8)
#define setSdmmcBypass(x)							setRegBit(SDMMC1->CLKCR, x, 10)

#define setSdmmcArgument(x)							SDMMC1->ARG = x

#define resetSdmmcCmd()								SDMMC1->CMD = 0
#define setSdmmcCmd(x)								SDMMC1->CMD = x

#define getSdmmcRespCmd()							SDMMC1->RESPCMD

#define getSdmmcResp1()								SDMMC1->RESP1
#define getSdmmcResp2()								SDMMC1->RESP2
#define getSdmmcResp3()								SDMMC1->RESP3
#define getSdmmcResp4()								SDMMC1->RESP4

#define setSdmmcDtimer(x)							SDMMC1->DTIMER = x

#define getSdmmcSentCmdStatus(x)					getRegField(SDMMC1->STA, 0x3, 6)
#define getSdmmcStatus()							SDMMC1->STA

#define resetSdmmcIcr()								SDMMC1->ICR = 0xffffffff

#define getSdmmc(x)					getRegBit(SDMMC1->STA, 7)

#endif

#endif
