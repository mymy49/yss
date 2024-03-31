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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(W7500)

//using namespace define::gpio;

const static Drv::setup_t gDrvSetupGpio =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

#if defined(GPIOA)
const static int8_t gPortAOutputAf[15] = {0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0};

const static Gpio::setup_t gConfigGpioA =
{
	GPIOA,			//YSS_GPIO_Peri *dev;
	AFC_PA,			//PORTX_TypeDef *afc;
	PADCON_PA,		//PORTX_TypeDef *padcon;
	gPortAOutputAf	//int8_t *outputAf;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif

#if defined(GPIOB)
const static int8_t gPortBOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioB =
{
	GPIOB,			//YSS_GPIO_Peri *dev;
	AFC_PB,			//PORTX_TypeDef *afc;
	PADCON_PB,		//PORTX_TypeDef *padcon;
	gPortBOutputAf	//int8_t *outputAf;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif

#if defined(GPIOC)
const static int8_t gPortCOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioC =
{
	GPIOC,			//YSS_GPIO_Peri *dev;
	AFC_PC,			//PORTX_TypeDef *afc;
	PADCON_PC,		//PORTX_TypeDef *padcon;
	gPortCOutputAf	//int8_t *outputAf;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif

#if defined(GPIOD)
const static int8_t gPortDOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioD =
{
	GPIOD,			//YSS_GPIO_Peri *dev;
	AFC_PD,			//PORTX_TypeDef *afc;
	PADCON_PD,		//PORTX_TypeDef *padcon;
	gPortDOutputAf	//int8_t *outputAf;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif

#endif

