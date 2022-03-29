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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

#include <drv/Gpio.h>
#include <drv/gpio/register_gpio_gd32f1.h>

namespace drv
{
inline void setGpioConfig(GPIO_TypeDef *port, unsigned char pin, unsigned char val)
{
	unsigned int *reg = (unsigned int *)port;
	unsigned char index = pin / 8;
	pin = (pin % 8 << 2) + 2;
	setFieldData(reg[index], 0x3UL << pin, val, pin);
}

inline void setGpioMode(GPIO_TypeDef *port, unsigned char pin, unsigned char val)
{
	unsigned int *reg = (unsigned int *)port;
	unsigned char index = pin / 8;
	pin %= 8;
	setRegField(reg[index], 0x3UL, val, pin << 2);
}

Gpio::Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), unsigned char exti) : Drv(clockFunc, 0, resetFunc)
{
	mPeri = peri;
	mExti = exti;
}

void Gpio::setExti(unsigned char pin)
{
	unsigned char index = pin / 4;
	pin %= 4;
//	setFieldData(AFIO->EXTICR[index], 0xfUL, exti, pin * 4);
}

void Gpio::setPackageAsAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype)
{
	GPIO_TypeDef *port;
	unsigned char pin;
	unsigned char func;

	for (unsigned char i = 0; i < numOfPort; i++)
	{
		port = altport[i].port;
		pin = altport[i].pin;
		func = altport[i].func;
	}
}

void Gpio::setAsInput(unsigned char pin, unsigned char pullUpDown)
{
	using namespace define::gpio::pupd;

	switch(pullUpDown)
	{
	case NONE :
		setGpioMode(mPeri, pin, 0);
		setGpioConfig(mPeri, pin, 1);
		return;
	case PULL_UP :
		mPeri->BOR = 0x0001 << pin;
		break;
	case PULL_DOWN :
		mPeri->BCR = 0x0001 << pin;
		break;
	}

	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 2);
}

void Gpio::setAsOutput(unsigned char pin, unsigned char ospeed, unsigned char otype)
{
	setGpioConfig(mPeri, pin, otype);
	setGpioMode(mPeri, pin, ospeed);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
	if (data)
		mPeri->BOR = 0x0001 << pin;
	else
		mPeri->BCR = 0x0001 << pin;
}

void Gpio::setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
{
	setGpioConfig(mPeri, pin, otype | 0x2);
	setGpioMode(mPeri, pin, ospeed);

	using namespace define::gpio::altfunc;

	switch (altFunc)
	{
	case PB8_I2C1_SCL:
	case PB9_I2C1_SDA:
		setBitData(AFIO->AFIO_PCFR1, true, 1);
		break;
	case PB3_SPI1_SCK:
	case PB4_SPI1_MISO:
	case PB5_SPI1_MOSI:
		setBitData(AFIO->AFIO_PCFR1, true, 0);
		break;
	case PB9_CAN_TX:
	case PB8_CAN_RX:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 13, 2, 13);
		break;
	case PA11_CAN_RX:
	case PA12_CAN_TX:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 13, 0, 13);
		break;
	case PA15_TIM2_CH1_ETR:
	case PB3_TIM2_CH2:
		setBitData(AFIO->AFIO_PCFR1, true, 8);
		break;
	case PB10_TIM2_CH3:
	case PB11_TIM2_CH4:
		setBitData(AFIO->AFIO_PCFR1, true, 9);
		break;
	case PC6_TIM3_CH1:
	case PC7_TIM3_CH2:
	case PC8_TIM3_CH3:
	case PC9_TIM3_CH4:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 10, 3, 10);
		break;
	case PA6_TIM3_CH1:
	case PA7_TIM3_CH2:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 10, 0, 10);
		break;
	case PB4_TIM3_CH1:
	case PB5_TIM3_CH2:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 10, 2, 10);
		break;
	case PB0_TIM3_CH3:
	case PB1_TIM3_CH4:
		setBitData(AFIO->AFIO_PCFR1, false, 10);
		break;
	case PB10_USART3_TX:
	case PB11_USART3_RX:
		setFieldData(AFIO->AFIO_PCFR1, 0x3 << 4, 0, 4);
		break;
	case PB6_USART1_TX:
	case PB7_USART1_RX:
		setBitData(AFIO->AFIO_PCFR1, true, 2);
		break;
	case PA9_USART1_TX:
	case PA10_USART1_RX:
		setBitData(AFIO->AFIO_PCFR1, false, 2);
		break;
	}
}

bool Gpio::getData(unsigned char pin)
{
	return getBitData(mPeri->DIR, pin);
}

void Gpio::setAsAnalog(unsigned char pin)
{
	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 0);
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
	setGpioMode(mPeri, pin, 0);
	setGpioConfig(mPeri, pin, 2);

	if (pupd == define::gpio::pupd::PULL_UP)
		mPeri->BOR = 0x0001 << pin;
	else
		mPeri->BCR = 0x0001 << pin;
}
}
#endif