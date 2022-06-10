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

#include <__cross_studio_io.h>

#include <yss/instance.h>

#ifndef YSS_DRV_CLOCK_UNSUPPORTED

#include <yss/reg.h>

#if defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
#include "flc_regs.h"
#include "gcr_regs.h"
#include "pwrseq_regs.h"
#endif

namespace drv
{
extern unsigned char gHseFreq __attribute__((section(".non_init")));
extern unsigned int gPllQFreq __attribute__((section(".non_init")));

#if defined(GPIOA)
void Peripheral::setGpioAEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPAEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOAEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPAEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPAEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_GPIOAEN;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 2);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 0);
#endif
}

void Peripheral::resetGpioA(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPARST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPARST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOARST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOARST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPARST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPARST_Msk;
#elif defined(STM32F0)
	RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOARST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 2);
	setBitData(RCC->APB2RCR, false, 2);
#endif
}
#endif

#if defined(GPIOB)
void Peripheral::setGpioBEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPBEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOBEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPBEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPBEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_GPIOBEN;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 3);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 1);
#endif
}

void Peripheral::resetGpioB(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPBRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPBRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOBRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOBRST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPBRST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPBRST_Msk;
#elif defined(STM32F0)
	RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOBRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 3);
	setBitData(RCC->APB2RCR, false, 3);
#endif
}
#endif

#if defined(GPIOC)
void Peripheral::setGpioCEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPCEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOCEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPCEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPCEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_GPIOCEN;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 4);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 2);
#endif
}

void Peripheral::resetGpioC(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPCRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOCRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOCRST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPCRST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPCRST_Msk;
#elif defined(STM32F0)
	RCC->AHBRSTR |= RCC_AHBRSTR_GPIOCRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOCRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 4);
	setBitData(RCC->APB2RCR, false, 4);
#endif
}
#endif

#if defined(GPIOD)
void Peripheral::setGpioDEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPDEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIODEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPDEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPDEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_GPIODEN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_GPIODEN;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 5);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 3);
#endif
}

void Peripheral::resetGpioD(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPDRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPDRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIODRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIODRST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPDRST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPDRST_Msk;
#elif defined(STM32F0)
	RCC->AHBRSTR |= RCC_AHBRSTR_GPIODRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIODRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 5);
	setBitData(RCC->APB2RCR, false, 5);
#endif
}
#endif

#if defined(GPIOE)
void Peripheral::setGpioEEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPEEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPEEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOEEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPEEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPEEN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 6);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 4);
#endif
}

void Peripheral::resetGpioE(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPERST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPERST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOERST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOERST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPERST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPERST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 6);
	setBitData(RCC->APB2RCR, false, 6);
#endif
}
#endif

#if defined(GPIOF)
void Peripheral::setGpioFEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPFEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPFEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOFEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_GPIOFEN;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 7);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 5);
#endif
}

void Peripheral::resetGpioF(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOFRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPFRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPFRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOFRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOFRST_Msk;
#elif defined(STM32F0)
	RCC->AHBRSTR |= RCC_AHBRSTR_GPIOFRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOFRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 7);
	setBitData(RCC->APB2RCR, false, 7);
#endif
}
#endif

#if defined(GPIOG)
void Peripheral::setGpioGEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPGEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPGEN_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOGRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOGRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 8);
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 6);
#endif
}

void Peripheral::resetGpioG(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOGRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPGRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPGRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOGRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOGRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 8);
	setBitData(RCC->APB2RCR, false, 8);
#endif
}
#endif

#if defined(GPIOH)
void Peripheral::setGpioHEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPHEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPHEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->IOPENR |= RCC_IOPENR_IOPHEN_Msk;
	else
		RCC->IOPENR &= ~RCC_IOPENR_IOPHEN_Msk;
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 7);
#endif
}

void Peripheral::resetGpioH(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPHRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPHRST_Msk;
#elif defined(STM32L0)
	RCC->IOPRSTR |= RCC_IOPRSTR_IOPHRST_Msk;
	RCC->IOPRSTR &= ~RCC_IOPRSTR_IOPHRST_Msk;
#endif
}
#endif

#if defined(GPIOI)
void Peripheral::setGpioIEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPIEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPIEN_Msk;
#elif defined(GD32F450)
	setBitData(RCU_AHB1EN, en, 8);
#endif
}

void Peripheral::resetGpioI(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOIRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPIRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPIRST_Msk;
#endif
}
#endif

#if defined(GPIOJ)
void Peripheral::setGpioJEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPJEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPJEN_Msk;
#endif
}

void Peripheral::resetGpioJ(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOJRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOJRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPJRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPJRST_Msk;
#endif
}
#endif

#if defined(GPIOK)
void Peripheral::setGpioKEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_IOPKEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_IOPKEN_Msk;
#endif
}

void Peripheral::resetGpioK(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOKRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOKRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_IOPKRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPKRST_Msk;
#endif
}
#endif

#if defined(AFIO)
void Peripheral::setAfioEn(bool en)
{
#if defined(STM32F1)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_AFIOEN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 0);
#endif
}

void Peripheral::resetAfio(void)
{
#if defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_AFIORST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_AFIORST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 0);
	setBitData(RCC->APB2RCR, false, 0);
#endif
}
#endif

#if defined(CRC)
void Peripheral::setCrcEn(bool en)
{
#if defined(STM32F7) || defined(STM32G4) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_CRCEN_Msk;
#elif defined(STM32F1) || defined(STM32L0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_CRCEN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_CRCEN_Msk;

#endif
}

void Peripheral::resetCrc(void)
{
#if defined(STM32F7) || defined(STM32G4) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_CRCRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_CRCRST_Msk;
#elif defined(STM32F1)
	// 기능 없음
#elif defined(STM32L0)
	RCC->AHBRSTR |= RCC_AHBRSTR_CRCRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_CRCRST_Msk;
#endif
}
#endif

#if defined(BKPSRAM_BASE)
void Peripheral::setBackupSramEn(bool en)
{
#if defined(GD32F450)

#else
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_BKPSRAMEN_Msk;
#endif
}
#endif

#if defined(CCMDATARAM_BASE)
void Peripheral::setCcmRamEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_CCMDATARAMEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_CCMDATARAMEN_Msk;
}
#endif

#if defined(DMA1)
void Peripheral::setDmaEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN_Msk;
#if defined(DMA2)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN_Msk;
#endif
#elif defined(STM32F1)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMA1EN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMA1EN_Msk;
#if defined(DMA2)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMA2EN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMA2EN_Msk;
#endif
#elif defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMAEN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMAEN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->AHBCCR, en, 0);
	setBitData(RCC->AHBCCR, en, 1);
#endif
}

void Peripheral::resetDma(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA1RST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA1RST_Msk;
#if defined(DMA2)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2RST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2RST_Msk;
#endif
#elif defined(STM32F1)
	// 기능 없음
#endif
}
#endif

#if defined(DMA2D)
void Peripheral::setDma2d(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA2DEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2DEN_Msk;
}

void Peripheral::resetDma2d(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2DRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2DRST_Msk;
}
#endif

#if defined(ETH)
void Peripheral::setEthernetMacEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACEN_Msk;
}

void Peripheral::setEthernetRxEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACRXEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACRXEN_Msk;
}

void Peripheral::setEthernetTxEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACTXEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACTXEN_Msk;
}

void Peripheral::setEthernetPtpEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACPTPEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACPTPEN_Msk;
}

void Peripheral::resetEthernetMac(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST_Msk;
}
#endif

#if defined(USB_OTG_HS)
void Peripheral::setUsbdHsEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSEN_Msk;
}

void Peripheral::setUsbdHsUlpiEn(bool en)
{
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPIEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSULPIEN_Msk;
}

void Peripheral::resetUsbHs(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_OTGHRST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_OTGHRST_Msk;
}
#endif

#if defined(USB_OTG_FS)
void Peripheral::setUsbdFsEn(bool en)
{
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_OTGFSEN_Msk;
}

void Peripheral::resetUsbFs(void)
{
	RCC->AHB2RSTR |= RCC_AHB2RSTR_OTGFSRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_OTGFSRST_Msk;
}
#endif

#if defined(DCMI)
void Peripheral::setDcmiEn(bool en)
{
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_DCMIEN_Msk;
}

void Peripheral::resetDcmi(void)
{
	RCC->AHB2RSTR |= RCC_AHB2RSTR_DCMIRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DCMIRST_Msk;
}
#endif

#if defined(CRYP)
void Peripheral::setCrypEn(bool en)
{
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_CRYPEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_CRYPEN_Msk;
}

void Peripheral::resetCryp(void)
{
	RCC->AHB2RSTR |= RCC_AHB2RSTR_CRYPRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_CRYPRST_Msk;
}
#endif

#if defined(HASH)
void Peripheral::setHashEn(bool en)
{
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_HASHEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_HASHEN_Msk;
}

void Peripheral::resetHash(void)
{
	RCC->AHB2RSTR |= RCC_AHB2RSTR_HASHRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_HASHRST_Msk;
}
#endif

#if defined(RNG)
void Peripheral::setRngEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_RNGEN_Msk;
#elif defined(STM32L0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_RNGEN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_RNGEN_Msk;
#endif
}

void Peripheral::resetRng(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_RNGRST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_RNGRST_Msk;
#elif defined(STM32L0)
	RCC->AHBRSTR |= RCC_AHBRSTR_RNGRST_Msk;
	RCC->AHBRSTR &= ~RCC_AHBRSTR_RNGRST_Msk;
#endif
}
#endif

#if defined(FMC_Bank1)
void Peripheral::setFmcEn(bool en)
{
	if (en)
		RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN_Msk;
	else
		RCC->AHB3ENR &= ~RCC_AHB3ENR_FMCEN_Msk;
}

void Peripheral::resetFmc(void)
{
	RCC->AHB3RSTR |= RCC_AHB3RSTR_FMCRST_Msk;
	RCC->AHB3RSTR &= ~RCC_AHB3RSTR_FMCRST_Msk;
}
#endif

#if defined(TC0) || defined(MXC_TMR0)
void Peripheral::setTimer0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC0_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T0D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T0D;
#endif
}
#endif

#if defined(SAI1)
void Peripheral::setSai1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setBitData(RCC->APB2ENR, en, RCC_APB2ENR_SAI1EN_Pos);
#endif
}

void Peripheral::resetSai1(void)
{
#if defined(STM32F4) || defined(STM32F7)
	setBitData(RCC->APB2RSTR, true, RCC_APB2RSTR_SAI1RST_Pos);
#endif
}
#endif

#if defined(SAI2)
void Peripheral::setSai2En(bool en)
{
#if defined(STM32F7)
	setBitData(RCC->APB2ENR, en, RCC_APB2ENR_SAI2EN_Pos);
#endif
}

void Peripheral::resetSai2(void)
{
}
#endif


#if defined(TIM1) || defined(TC1) || defined(MXC_TMR1) || defined(TIMER1)
void Peripheral::setTimer1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC1_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T1D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T1D;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 11);
#endif
}

void Peripheral::resetTimer1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 11);
	setBitData(RCC->APB2RCR, false, 11);
#endif
}
#endif

#if defined(TIM2) || defined(TC2) || defined(MXC_TMR2) || defined(TIMER2)
void Peripheral::setTimer2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC2_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T2D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T2D;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 0);
#endif
}

void Peripheral::resetTimer2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 0);
	setBitData(RCC->APB1RCR, false, 0);
#endif
}
#endif

#if defined(TIM3) || defined(TC3) || defined(TIMER3)
void Peripheral::setTimer3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC3_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 1);
#endif
}

void Peripheral::resetTimer3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 1);
	setBitData(RCC->APB1RCR, false, 1);
#endif
}
#endif

#if defined(TIM4) || defined(TC4) || defined(TIMER4)
void Peripheral::setTimer4En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC4_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 2);
#endif
}

void Peripheral::resetTimer4(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM4RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM4RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 2);
	setBitData(RCC->APB1RCR, false, 2);

#endif
}
#endif

#if defined(TIM5) || defined(TIMER5)
void Peripheral::setTimer5En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM5EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM5EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 3);
#endif
}

void Peripheral::resetTimer5(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM5RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM5RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM5RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM5RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 3);
	setBitData(RCC->APB1RCR, false, 3);
#endif
}
#endif

#if defined(TIM6) || defined(TIMER6)
void Peripheral::setTimer6En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM6EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM6EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 4);
#endif
}

void Peripheral::resetTimer6(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM6RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM6RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 4);
	setBitData(RCC->APB1RCR, false, 4);
#endif
}
#endif

#if defined(TIM7) || defined(TIMER7)
void Peripheral::setTimer7En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM7EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM7EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 5);
#endif
}

void Peripheral::resetTimer7(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM7RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM7RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 5);
	setBitData(RCC->APB1RCR, false, 5);
#endif
}
#endif

#if defined(TIM8) || defined(TIMER8)
void Peripheral::setTimer8En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM8EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 13);
#endif
}

void Peripheral::resetTimer8(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 13);
	setBitData(RCC->APB2RCR, false, 13);
#endif
}
#endif

#if defined(TIM9) || defined(TIMER9)
void Peripheral::setTimer9En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM9EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN_Msk;
#endif
}

void Peripheral::resetTimer9(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM9RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM9RST_Msk;
#endif
}
#endif

#if defined(TIM10) || defined(TIMER10)
void Peripheral::setTimer10En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM10EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN_Msk;
#endif
}

void Peripheral::resetTimer10(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM10RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM10RST_Msk;
#endif
}
#endif

#if defined(TIM11) || defined(TIMER11)
void Peripheral::setTimer11En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM11EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN_Msk;
#endif
}

void Peripheral::resetTimer11(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM11RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM11RST_Msk;
#endif
}
#endif

#if defined(TIM12) || defined(TIMER12)
void Peripheral::setTimer12En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM12EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN_Msk;
#endif
}

void Peripheral::resetTimer12(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM12RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM12RST_Msk;
#endif
}
#endif

#if defined(TIM13) || defined(TIMER13)
void Peripheral::setTimer13En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM13EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN_Msk;
#endif
}

void Peripheral::resetTimer13(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM13RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM13RST_Msk;
#endif
}
#endif

#if defined(TIM14) || defined(TIMER14)
void Peripheral::setTimer14En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM14EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN_Msk;
#endif
}

void Peripheral::resetTimer14(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_TIM14RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM14RST_Msk;
#endif
}
#endif

#if defined(TIM15) || defined(TIMER15)
void Peripheral::setTimer15En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM15EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM15EN_Msk;
#endif
}

void Peripheral::resetTimer15(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM15RST_Msk;
#endif
}
#endif

#if defined(TIM16) || defined(TIMER16)
void Peripheral::setTimer16En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM16EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM16EN_Msk;
#endif
}

void Peripheral::resetTimer16(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM16RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM16RST_Msk;
#endif
}
#endif

#if defined(TIM17) || defined(TIMER17)
void Peripheral::setTimer17En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM17EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM17EN_Msk;
#endif
}

void Peripheral::resetTimer17(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM17RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM17RST_Msk;
#endif
}
#endif

#if defined(WWDG)
void Peripheral::setWindowWatchdogEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_WWDGEN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_WWDGEN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_WWDGEN_Msk;
#endif
}

void Peripheral::resetWindowWatchdog(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_WWDGRST_Msk;
#elif defined(STM32G4)
	// 기능 없음
#endif
}
#endif

#if defined(SERCOM0)
void Peripheral::setSpi0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi0(void)
{
#if defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI1) || defined(SERCOM1)
void Peripheral::setSpi1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 12);
#endif
}

void Peripheral::resetSpi1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 12);
	setBitData(RCC->APB2RCR, false, 12);
#endif
}
#endif

#if defined(SPI2) || defined(SERCOM2)
void Peripheral::setSpi2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_SPI2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 14);
#endif
}

void Peripheral::resetSpi2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 14);
	setBitData(RCC->APB1RCR, false, 14);
#endif
}
#endif

#if defined(SPI3) || defined(SERCOM3)
void Peripheral::setSpi3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_SPI3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_SPI3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 15);
#endif
}

void Peripheral::resetSpi3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 15);
	setBitData(RCC->APB1RCR, false, 15);
#endif
}
#endif

#if defined(SPI4) || defined(SERCOM4)
void Peripheral::setSpi4En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI4EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi4(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI4RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI4RST_Msk;
#elif defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI5) || defined(SERCOM5)
void Peripheral::setSpi5En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI5EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI5EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi5(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI5RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI5RST_Msk;
#elif defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI6)
void Peripheral::setSpi6En(bool en)
{
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI6EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI6EN_Msk;
}

void Peripheral::resetSpi6(void)
{
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI6RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI6RST_Msk;
}
#endif

#if defined(USART0) || defined(SERCOM0) || defined(MXC_UART0)
void Peripheral::setUart0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_UART0D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_UART0D;
#endif
}

void Peripheral::resetUart0(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)

#elif defined(__SAM_L_FAMILY)

#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)

#endif
}
#endif

#if defined(USART1) || defined(SERCOM1) || defined(MXC_UART1)
void Peripheral::setUart1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_UART1D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_UART1D;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 14);
#endif
}

void Peripheral::resetUart1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 14);
	setBitData(RCC->APB2RCR, false, 14);
#endif
}
#endif

#if defined(USART2) || defined(SERCOM2)
void Peripheral::setUart2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 17);
#endif
}

void Peripheral::resetUart2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 17);
	setBitData(RCC->APB1RCR, false, 17);

#endif
}
#endif

#if defined(USART3) || defined(SERCOM3)
void Peripheral::setUart3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USART3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 18);
#endif
}

void Peripheral::resetUart3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 18);
	setBitData(RCC->APB1RCR, false, 18);

#endif
}
#endif

#if defined(UART4) || defined(SERCOM4)
void Peripheral::setUart4En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART4EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 19);
#endif
}

void Peripheral::resetUart4(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART4RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART4RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 19);
	setBitData(RCC->APB1RCR, false, 19);
#endif
}
#endif

#if defined(UART5) || defined(SERCOM5)
void Peripheral::setUart5En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART5EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_UART5EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART5EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 20);
#endif
}

void Peripheral::resetUart5(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART5RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART5RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 20);
	setBitData(RCC->APB1RCR, false, 20);

#endif

}
#endif

#if defined(USART6)
void Peripheral::setUart6En(bool en)
{
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_USART6EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN_Msk;
}

void Peripheral::resetUart6(void)
{
	RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST_Msk;
}
#endif

#if defined(UART7)
void Peripheral::setUart7En(bool en)
{
#if defined(GD32F450)

#else
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART7EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART7EN_Msk;
#endif
}

void Peripheral::resetUart7(void)
{
#if defined(GD32F450)

#else
	RCC->APB1RSTR |= RCC_APB1RSTR_UART7RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART7RST_Msk;
#endif
}
#endif

#if defined(UART8)
void Peripheral::setUart8En(bool en)
{
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART8EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART8EN_Msk;
}

void Peripheral::resetUart8(void)
{
	RCC->APB1RSTR |= RCC_APB1RSTR_UART8RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART8RST_Msk;
}
#endif

#if defined(I2C1)
void Peripheral::setI2c1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C1EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 21);
#endif
}

void Peripheral::resetI2c1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C1RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C1RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 21);
	setBitData(RCC->APB1RCR, false, 21);
#endif
}

#if defined(STM32G4)
bool Peripheral::setI2c1ClkSrc(unsigned char src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C1SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C1SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C2)
void Peripheral::setI2c2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C2EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 22);
#endif
}

void Peripheral::resetI2c2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C2RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 22);
	setBitData(RCC->APB1RCR, false, 22);
#endif
}

#if defined(STM32G4)
bool Peripheral::setI2c2ClkSrc(unsigned char src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C2SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C2SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C3)
void Peripheral::setI2c3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C3EN_Msk;
#endif
}

void Peripheral::resetI2c3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C3RST_Msk;
#endif
}

#if defined(STM32G4)
bool Peripheral::setI2c3ClkSrc(unsigned char src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C3SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C3SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C4)
void Peripheral::setI2c4En(bool en)
{
#if defined(STM32G4)
	if (en)
		RCC->APB1ENR2 |= RCC_APB1ENR2_I2C4EN_Msk;
	else
		RCC->APB1ENR2 &= ~RCC_APB1ENR2_I2C4EN_Msk;
#else
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C4EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C4EN_Msk;
#endif
}

void Peripheral::resetI2c4(void)
{
#if defined(STM32G4)
	RCC->APB1RSTR2 |= RCC_APB1RSTR2_I2C4RST_Msk;
	RCC->APB1RSTR2 &= ~RCC_APB1RSTR2_I2C4RST_Msk;
#else
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C4RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C4RST_Msk;
#endif
}
#endif

#if defined(CAN1) || defined(FDCAN1)
void Peripheral::setCan1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_CAN1EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_FDCANEN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_FDCANEN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 25);
#endif
}

void Peripheral::resetCan1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_FDCANRST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_FDCANRST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 25);
	setBitData(RCC->APB1RCR, false, 25);
#endif
}

#if defined(STM32G4)
unsigned int Peripheral::getCan1ClkFreq(void)
{
	unsigned int src = (RCC->CCIPR & RCC_CCIPR_FDCANSEL_Msk) >> RCC_CCIPR_FDCANSEL_Pos;

	switch (src)
	{
	case 0: // HSE
		return (unsigned int)gHseFreq * 1000000;
	case 1: // PLLQ
		return gPllQFreq;
	case 2: // PCLK1
		return clock.getApb1ClkFreq();
	default:
		return 0;
	}
}

bool Peripheral::setCan1ClkSrc(unsigned char src)
{
	if (src > 2)
		return false;
	unsigned int ccipr = RCC->CCIPR;

	ccipr &= ~RCC_CCIPR_FDCANSEL_Msk;
	ccipr |= src << RCC_CCIPR_FDCANSEL_Pos;
	RCC->CCIPR = ccipr;

	return true;
}
#endif
#endif

#if defined(CAN2)
void Peripheral::setCan2En(bool en)
{
#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_CAN2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 26);
#endif
}

void Peripheral::resetCan2(void)
{
#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
	RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 26);
	setBitData(RCC->APB1RCR, false, 26);
#endif
}
#endif

#if defined(PWR) || defined(PMU)
void Peripheral::setPwrEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_PWREN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_PWREN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	if (en)
		RCC->APB1CCR |= RCC_APB1CCR_PWREN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_PWREN;
#elif defined(GD32F450)
	if(en)
		RCU_APB1EN |= RCU_APB1EN_PMUEN;
	else
		RCU_APB1EN &= ~RCU_APB1EN_PMUEN;
#endif
}

void Peripheral::resetPwr(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_PWRRST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_PWRRST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_PWRRST_Msk;
#endif
}
#endif

#if defined(DAC1) || defined(DAC)
void Peripheral::setDac1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_DACEN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_DACEN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_DAC1EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_DAC1EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1CCR, en, 29);
#endif
}

void Peripheral::resetDac1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_DACRST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_DACRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_DAC1RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DAC1RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB1RCR, true, 29);
	setBitData(RCC->APB1RCR, false, 29);
#endif
}
#endif

#if defined(ADC1) || defined(ADC)
void Peripheral::setAdc1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#elif defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADCEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADCEN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[ADC_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 9);
#endif
}

void Peripheral::resetAdc1(void)
{
#if defined(STM32F7)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC1RST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC12RST_Pos;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC12RST_Pos;
#elif defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Pos;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Pos;
#elif defined(__SAM_L_FAMILY)

#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 9);
	setBitData(RCC->APB2RCR, false, 9);
#endif
}

#if defined(STM32G4)
void Peripheral::setAdc12ClkSrc(unsigned char src)
{
	unsigned int ccipr;
	switch (src)
	{
	case define::clock::adc::src::NO_CLK:
	case define::clock::adc::src::PLL:
	case define::clock::adc::src::SYSCLK:
		ccipr = RCC->CCIPR & ~RCC_CCIPR_ADC12SEL_Msk;
		ccipr |= src << RCC_CCIPR_ADC12SEL_Pos;
		RCC->CCIPR = ccipr;
		break;
	}
}
#endif
#endif

#if defined(ADC2)
void Peripheral::setAdc2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 10);
#endif
}

void Peripheral::resetAdc2(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC2RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC2RST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC12RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC12RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 10);
	setBitData(RCC->APB2RCR, false, 10);
#endif
}
#endif

#if defined(ADC3)
void Peripheral::setAdc3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC3EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC345EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC345EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2CCR, en, 15);
#endif
}

void Peripheral::resetAdc3(void)
{
#if defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC3RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC3RST_Msk;
#elif defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC345RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC345RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	setBitData(RCC->APB2RCR, true, 15);
	setBitData(RCC->APB2RCR, false, 15);
#endif
}
#endif

#if defined(SDIO)
void Peripheral::setSdioEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SDIOEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SDIOEN_Msk;
#elif defined(STM32F1)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_SDIOEN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_SDIOEN_Msk;
#endif
}

void Peripheral::resetSdio(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SDIORST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SDIORST_Msk;
#elif defined(STM32F1)
	// 기능 없음
#endif
}
#endif

#if defined(SDMMC1) || defined(SDIO)
void Peripheral::setSdmmcEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SDMMC1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SDMMC1EN_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
	if (en)
		RCC->AHBCCR |= RCC_AHBCCR_SDIOEN;
	else
		RCC->AHBCCR &= ~RCC_AHBCCR_SDIOEN;
#endif
}

void Peripheral::resetSdmmc(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SDMMC1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SDMMC1RST_Msk;
#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)
#endif
}
#endif

#if defined(SYSCFG)
void Peripheral::setSyscfgEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGCOMPEN_Msk;
#endif
}

void Peripheral::resetSyscfg(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST_Msk;
#endif
}
#endif


#if defined(LTDC)
void Peripheral::setLtdcEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_LTDCEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_LTDCEN_Msk;
#endif
}

void Peripheral::resetLtdc(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_LTDCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_LTDCRST_Msk;
#endif
}
#endif

#if defined(RTC)

void Peripheral::setRtcEn(bool en)
{
#if defined(STM32F1)
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
#endif
}

void Peripheral::resetRtc(void)
{
#if defined(STM32F7)
	PWR->CR1 |= PWR_CR1_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	__NOP();
	__NOP();
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR1 &= ~PWR_CR1_DBP_Msk;
#elif defined(STM32F4)
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	__NOP();
	__NOP();
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
#elif defined(STM32L0)
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->CSR |= RCC_CSR_RTCRST_Msk;
	__NOP();
	__NOP();
	RCC->CSR &= ~RCC_CSR_RTCRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
#endif
}
#endif

#if defined(EIC)

void Peripheral::setExtiEn(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[EIC_GCLK_ID].bit.CHEN = en;
#endif
}

void Peripheral::resetExti(void)
{
#if defined(__SAM_L_FAMILY)
#endif
}
#endif

#if defined(USB)

void Peripheral::setUsb1En(bool en)
{
#if defined(STM32F1)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USBEN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USBEN_Msk;
#endif
}

void Peripheral::resetUsb1(void)
{
#if defined(STM32F1)
	RCC->APB1RSTR |= RCC_APB1RSTR_USBRST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USBRST_Msk;
#endif
}
#endif

}

#endif
