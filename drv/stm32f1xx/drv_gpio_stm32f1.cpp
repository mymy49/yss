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

#include <drv/peripheral.h>
/*
#if defined(STM32F1)

#include <drv/Gpio.h>
#include <drv/gpio/register_gpio_stm32f1.h>

Gpio::Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), uint8_t exti) : Drv(clockFunc, 0, resetFunc)
{
	mPeri = peri;
	mExti = exti;
}

void Gpio::setExti(uint8_t pin)
{
	setGpioExti(pin, mExti);
}

void Gpio::setPackageAsAltFunc(AltFunc *altport, uint8_t numOfPort, uint8_t ospeed, uint8_t otype)
{
	GPIO_TypeDef *port;
	uint8_t pin;
	uint8_t func;

	for (uint8_t i = 0; i < numOfPort; i++)
	{
		port = altport[i].port;
		pin = altport[i].pin;
		func = altport[i].func;
	}
}

void Gpio::setAsInput(uint8_t pin, uint8_t pullUpDown)
{
	using namespace define::gpio::pupd;

	switch(pullUpDown)
	{
	case NONE :
		setGpioMode(mPeri, pin, 0);
		setGpioConfig(mPeri, pin, 1);
		return;
	case PULL_UP :
		mPeri->BSRR = 1 << pin;
		break;
	case PULL_DOWN :
		mPeri->BRR = 1 << pin;
		break;
	}

	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 2);
}

void Gpio::setAsOutput(uint8_t pin, uint8_t ospeed, uint8_t otype)
{
	setGpioConfig(mPeri, pin, otype);
	setGpioMode(mPeri, pin, ospeed);
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if (data)
		mPeri->BSRR = GPIO_BSRR_BS0 << pin;
	else
		mPeri->BSRR = GPIO_BSRR_BR0 << pin;
}

void Gpio::setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t ospeed, uint8_t otype)
{
	setGpioConfig(mPeri, pin, otype | 0x2);
	setGpioMode(mPeri, pin, ospeed);

	using namespace define::gpio::altfunc;

	switch (altFunc)
	{
	case PB8_I2C1_SCL:
	case PB9_I2C1_SDA:
		setAfioRemapI2c1(true);
		break;
	case PB3_SPI1_SCK:
	case PB4_SPI1_MISO:
	case PB5_SPI1_MOSI:
		setAfioRemapSpi1(true);
		break;
	case PB9_CAN_TX:
	case PB8_CAN_RX:
		AFIO->MAPR &= ~AFIO_MAPR_CAN_REMAP;
		AFIO->MAPR |= 2 << 13;
		break;
	case PA11_CAN_RX:
	case PA12_CAN_TX:
		AFIO->MAPR &= ~AFIO_MAPR_CAN_REMAP;
		break;
	case PA15_TIM2_CH1_ETR:
	case PB3_TIM2_CH2:
		AFIO->MAPR |= AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1;
		break;
	case PB10_TIM2_CH3:
	case PB11_TIM2_CH4:
		AFIO->MAPR |= AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2;
		break;
	case PC6_TIM3_CH1:
	case PC7_TIM3_CH2:
	case PC8_TIM3_CH3:
	case PC9_TIM3_CH4:
		AFIO->MAPR |= AFIO_MAPR_TIM3_REMAP_FULLREMAP;
		break;
	case PA6_TIM3_CH1:
	case PA7_TIM3_CH2:
		AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_FULLREMAP;
		break;
	case PB4_TIM3_CH1:
	case PB5_TIM3_CH2:
		AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_FULLREMAP;
		AFIO->MAPR |= AFIO_MAPR_TIM3_REMAP_1;
		break;
	case PB0_TIM3_CH3:
	case PB1_TIM3_CH4:
		AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_0;
		break;
#if defined(USART3)
	case PB10_USART3_TX:
	case PB11_USART3_RX:
		AFIO->MAPR &= ~AFIO_MAPR_USART3_REMAP_FULLREMAP;
		break;
#endif
	case PB6_USART1_TX:
	case PB7_USART1_RX:
		AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;
		break;
	case PA9_USART1_TX:
	case PA10_USART1_RX:
		AFIO->MAPR &= ~AFIO_MAPR_USART1_REMAP;
		break;
	}
}

bool Gpio::getData(uint8_t pin)
{
	return getGpioInputData(mPeri, pin);
}

void Gpio::setAsAnalog(uint8_t pin)
{
	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 0);
}

void Gpio::setPullUpDown(uint8_t pin, uint8_t pupd)
{
	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 2);

	if (pupd == define::gpio::pupd::PULL_DOWN)
		mPeri->BRR = 1 << pin;
	else
		mPeri->BSRR = 1 << pin;
}
#endif

*/