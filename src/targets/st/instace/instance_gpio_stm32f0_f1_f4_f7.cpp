////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(GD32F4) || defined(STM32F4) || defined(STM32L1) || defined (STM32F0)

#if defined(GPIOA)
Gpio gpioA((YSS_GPIO_Peri*)GPIOA, 0, 0, define::gpio::Exti::PORTA);
#endif

#if defined(GPIOB)
Gpio gpioB((YSS_GPIO_Peri*)GPIOB, 0, 0, define::gpio::Exti::PORTB);
#endif

#if defined(GPIOC)
Gpio gpioC((YSS_GPIO_Peri*)GPIOC, 0, 0, define::gpio::Exti::PORTC);
#endif

#if defined(GPIOD)
Gpio gpioD((YSS_GPIO_Peri*)GPIOD, 0, 0, define::gpio::Exti::PORTD);
#endif

#if defined(GPIOE)
Gpio gpioE((YSS_GPIO_Peri*)GPIOE, 0, 0, define::gpio::Exti::PORTE);
#endif

#if defined(GPIOF)
Gpio gpioF((YSS_GPIO_Peri*)GPIOF, 0, 0, define::gpio::Exti::PORTF);
#endif

#if defined(GPIOG)
Gpio gpioG((YSS_GPIO_Peri*)GPIOG, 0, 0, define::gpio::Exti::PORTG);
#endif

#if defined(GPIOH)
Gpio gpioH((YSS_GPIO_Peri*)GPIOH, 0, 0, define::gpio::Exti::PORTH);
#endif

#if defined(GPIOI)
Gpio gpioI((YSS_GPIO_Peri*)GPIOI, 0, 0, define::gpio::Exti::PORTI);
#endif

#elif defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined (STM32F1_N)

using namespace define::gpio;

const static Drv::Setup gDrvSetupGpio =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

#if defined(GPIOA)
const static Gpio::Setup gConfigGpioA =
{
	GPIOA,		//YSS_GPIO_Peri *dev;
	Exti::PORTA	//uint8_t port;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif

#if defined(GPIOB)
const static Gpio::Setup gConfigGpioB =
{
	GPIOB,		//YSS_GPIO_Peri *dev;
	Exti::PORTB	//uint8_t port;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif

#if defined(GPIOC)
const static Gpio::Setup gConfigGpioC =
{
	GPIOC,		//YSS_GPIO_Peri *dev;
	Exti::PORTC	//uint8_t port;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif

#if defined(GPIOD)
const static Gpio::Setup gConfigGpioD =
{
	GPIOD,		//YSS_GPIO_Peri *dev;
	Exti::PORTD	//uint8_t port;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif

#if defined(GPIOE)
const static Gpio::Setup gConfigGpioE =
{
	GPIOE,		//YSS_GPIO_Peri *dev;
	Exti::PORTE	//uint8_t port;
};

Gpio gpioE(gDrvSetupGpio, gConfigGpioE);
#endif

#if defined(GPIOF)
const static Gpio::Setup gConfigGpioF =
{
	GPIOF,		//YSS_GPIO_Peri *dev;
	Exti::PORTF	//uint8_t port;
};

Gpio gpioF(gDrvSetupGpio, gConfigGpioF);
#endif

#if defined(GPIOG)
const static Gpio::Setup gConfigGpioG =
{
	GPIOG,		//YSS_GPIO_Peri *dev;
	Exti::PORTG	//uint8_t port;
};

Gpio gpioG(gDrvSetupGpio, gConfigGpioG);
#endif

#if defined(GPIOH)
const static Gpio::Setup gConfigGpioH =
{
	GPIOH,		//YSS_GPIO_Peri *dev;
	Exti::PORTH	//uint8_t port;
};

Gpio gpioH(gDrvSetupGpio, gConfigGpioH);
#endif

#if defined(GPIOI)
const static Gpio::Setup gConfigGpioI =
{
	GPIOI,		//YSS_GPIO_Peri *dev;
	Exti::PORTI	//uint8_t port;
};

Gpio gpioI(gDrvSetupGpio, gConfigGpioI);
#endif



#if defined(GPIOJ)
const static Gpio::Setup gConfigGpioJ =
{
	GPIOJ,		//YSS_GPIO_Peri *dev;
	Exti::PORTJ	//uint8_t port;
};

Gpio gpioJ(gDrvSetupGpio, gConfigGpioJ);
#endif



#if defined(GPIOK)
const static Drv::Setup gDrvSetupGpioK =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gConfigGpioK =
{
	GPIOK,		//YSS_GPIO_Peri *dev;
	Exti::PORTK	//uint8_t port;
};

Gpio gpioK(gDrvSetupGpioK, gConfigGpioK);
#endif

#endif

