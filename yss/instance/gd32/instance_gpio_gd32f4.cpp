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

#include <yss/instance.h>

#if defined(GD32F4)

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PAEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PAEN;
}

static void resetGpioA(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PARST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PARST;
}

Gpio gpioA((YSS_GPIO_Peri*)GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#endif



#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PBEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PBEN;
}

static void resetGpioB(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PBRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PBRST;
}

Gpio gpioB((YSS_GPIO_Peri*)GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#endif



#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PCEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PCEN;
}

static void resetGpioC(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PCRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PCRST;
}

Gpio gpioC((YSS_GPIO_Peri*)GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif



#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PDEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PDEN;
}

static void resetGpioD(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PDRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PDRST;
}

Gpio gpioD((YSS_GPIO_Peri*)GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
#endif



#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PEEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PEEN;
}

static void resetGpioE(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PERST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PERST;
}

Gpio gpioE((YSS_GPIO_Peri*)GPIOE, setGpioEClockEn, resetGpioE, define::gpio::exti::PORTE);
#endif



#if defined(GPIOF)
static void setGpioFClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PFEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PFEN;
}

static void resetGpioF(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PFRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PFRST;
}

Gpio gpioF((YSS_GPIO_Peri*)GPIOF, setGpioFClockEn, resetGpioF, define::gpio::exti::PORTF);
#endif



#if defined(GPIOG)
static void setGpioGClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PGEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PGEN;
}

static void resetGpioG(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PGRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PGRST;
}

Gpio gpioG((YSS_GPIO_Peri*)GPIOG, setGpioGClockEn, resetGpioG, define::gpio::exti::PORTG);
#endif



#if defined(GPIOH)
static void setGpioHClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PHEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PHEN;
}

static void resetGpioH(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PHRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PHRST;
}

Gpio gpioH((YSS_GPIO_Peri*)GPIOH, setGpioHClockEn, resetGpioH, define::gpio::exti::PORTH);
#endif



#if defined(GPIOI)
static void setGpioIClockEn(bool en)
{
	if(en)
		RCU_AHB1EN |= RCU_AHB1EN_PIEN;
	else
		RCU_AHB1EN &= ~RCU_AHB1EN_PIEN;
}

static void resetGpioI(void)
{
	RCU_AHB1RST |= RCU_AHB1RST_PIRST;
	RCU_AHB1RST &= ~RCU_AHB1RST_PIRST;
}

Gpio gpioI((YSS_GPIO_Peri*)GPIOI, setGpioIClockEn, resetGpioI, define::gpio::exti::PORTI);
#endif

#endif

