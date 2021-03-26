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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2021.03.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_INSTANCE_TIMER__H_
#define YSS_INSTANCE_TIMER__H_

#include <drv/drv_Timer.h>

#if defined(TIM1)
extern drv::Timer timer1;
#endif

#if defined(TIM2)
extern drv::Timer timer2;
#endif

#if defined(TIM3)
extern drv::Timer timer3;
#endif

#if defined(TIM4)
extern drv::Timer timer4;
#endif

#if defined(TIM5)
extern drv::Timer timer5;
#endif

#if defined(TIM6)
extern drv::Timer timer6;
#endif

#if defined(TIM7)
extern drv::Timer timer7;
#endif

#if defined(TIM8)
extern drv::Timer timer8;
#endif

#if defined(TIM9)
extern drv::Timer timer9;
#endif

#if defined(TIM10)
extern drv::Timer timer10;
#endif

#if defined(TIM11)
extern drv::Timer timer11;
#endif

#if defined(TIM12)
extern drv::Timer timer12;
#endif

#if defined(TIM13)
extern drv::Timer timer13;
#endif

#if defined(TIM14)
extern drv::Timer timer14;
#endif

#if defined(TIM15)
extern drv::Timer timer15;
#endif

#if defined(TIM16)
extern drv::Timer timer16;
#endif

#if defined(TIM17)
extern drv::Timer timer17;
#endif

#endif
