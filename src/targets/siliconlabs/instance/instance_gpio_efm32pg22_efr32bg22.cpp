////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_cmu.h>
#endif

#if defined(GPIO_PA_INDEX)
const static Drv::Setup gDrvSetupGpioA =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioA =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTA,	//uint8_t port;
	GPIO_PA_COUNT	//uint8_t pinCount;
};

Gpio gpioA(gDrvSetupGpioA, gSetupGpioA);
#endif

#if defined(GPIO_PB_INDEX)
const static Drv::Setup gDrvSetupGpioB =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioB =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTB,	//uint8_t port;
	GPIO_PB_COUNT	//uint8_t pinCount;
};

Gpio gpioB(gDrvSetupGpioB, gSetupGpioB);
#endif

#if defined(GPIO_PC_INDEX)
const static Drv::Setup gDrvSetupGpioC =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioC =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTC,	//uint8_t port;
	GPIO_PC_COUNT	//uint8_t pinCount;
};

Gpio gpioC(gDrvSetupGpioC, gSetupGpioC);
#endif

#if defined(GPIO_PD_INDEX)
const static Drv::Setup gDrvSetupGpioD =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioD =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTD,	//uint8_t port;
	GPIO_PD_COUNT	//uint8_t pinCount;
};

Gpio gpioD(gDrvSetupGpioD, gSetupGpioD);
#endif

#endif

