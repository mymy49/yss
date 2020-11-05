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

#ifndef	YSS_DRV_SYSCFG_ST_TYPE_A_REG__H_
#define	YSS_DRV_SYSCFG_ST_TYPE_A_REG__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx) || \
	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

#include <yss/reg.h>

#define	SYSCFG_EXTI_PORTA	0
#define	SYSCFG_EXTI_PORTB	1
#define	SYSCFG_EXTI_PORTC	2
#define	SYSCFG_EXTI_PORTD	3
#define	SYSCFG_EXTI_PORTE	4
#define	SYSCFG_EXTI_PORTF	5
#define	SYSCFG_EXTI_PORTG	6
#define	SYSCFG_EXTI_PORTH	7
#define	SYSCFG_EXTI_PORTI	8
#define	SYSCFG_EXTI_PORTJ	9
#define	SYSCFG_EXTI_PORTK	10

#define	setSyscfgSwapFmc(x)	setRegField(SYSCFG->MEMRMP,	0x3UL, x, 10)

#define	setSyscfgExti0(x)	setRegField(SYSCFG->EXTICR[0], 0xFUL, x, 0)
#define	setSyscfgExti1(x)	setRegField(SYSCFG->EXTICR[0], 0xFUL, x, 4)
#define	setSyscfgExti2(x)	setRegField(SYSCFG->EXTICR[0], 0xFUL, x, 8)
#define	setSyscfgExti3(x)	setRegField(SYSCFG->EXTICR[0], 0xFUL, x, 12)
#define	setSyscfgExti4(x)	setRegField(SYSCFG->EXTICR[1], 0xFUL, x, 0)
#define	setSyscfgExti5(x)	setRegField(SYSCFG->EXTICR[1], 0xFUL, x, 4)
#define	setSyscfgExti6(x)	setRegField(SYSCFG->EXTICR[1], 0xFUL, x, 8)
#define	setSyscfgExti7(x)	setRegField(SYSCFG->EXTICR[1], 0xFUL, x, 12)
#define	setSyscfgExti8(x)	setRegField(SYSCFG->EXTICR[2], 0xFUL, x, 0)
#define	setSyscfgExti9(x)	setRegField(SYSCFG->EXTICR[2], 0xFUL, x, 4)
#define	setSyscfgExti10(x)	setRegField(SYSCFG->EXTICR[2], 0xFUL, x, 8)
#define	setSyscfgExti11(x)	setRegField(SYSCFG->EXTICR[2], 0xFUL, x, 12)
#define	setSyscfgExti12(x)	setRegField(SYSCFG->EXTICR[3], 0xFUL, x, 0)
#define	setSyscfgExti13(x)	setRegField(SYSCFG->EXTICR[3], 0xFUL, x, 4)
#define	setSyscfgExti14(x)	setRegField(SYSCFG->EXTICR[3], 0xFUL, x, 8)
#define	setSyscfgExti15(x)	setRegField(SYSCFG->EXTICR[3], 0xFUL, x, 12)

#endif

#endif
