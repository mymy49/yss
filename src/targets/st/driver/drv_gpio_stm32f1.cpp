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

#include <drv/peripheral.h>

#if defined(GD32F1) || defined(STM32F1_N)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/st/bitfield_stm32f103xx.h>

inline void setGpioConfig(YSS_GPIO_Peri *port, uint8_t pin, uint8_t val)
{
	uint32_t *reg = (uint32_t *)port;
	uint8_t index = pin / 8;
	pin = (pin % 8 << 2) + 2;
	setFieldData(reg[index], 0x3UL << pin, val, pin);
}

inline void setGpioMode(YSS_GPIO_Peri *port, uint8_t pin, uint8_t val)
{
	uint32_t *reg = (uint32_t *)port;
	uint8_t index = pin / 8;
	pin = (pin % 8 << 2);
	setFieldData(reg[index], 0x3UL << pin, val, pin);
}

Gpio::Gpio(const Drv::Setup drvSetup, const Setup setup) : GpioBase(drvSetup)
{
	mDev = setup.dev;
	mExti = setup.exti;
}

void Gpio::setExti(uint8_t pin)
{
	uint8_t index = pin / 4;
	volatile uint32_t *exticr = AFIO->EXTICR;
	pin %= 4;
	setFieldData(exticr[index], 0xfUL, mExti, pin * 4);
}

void Gpio::setPackageAsAltFunc(AltFunc *altport, uint8_t numOfPort, uint8_t ospeed, uint8_t otype)
{
	// 지원 안됨
}

void Gpio::setAsInput(uint8_t pin, uint8_t pullUpDown)
{
	using namespace define::gpio::pupd;

	switch(pullUpDown)
	{
	case NONE :
		setGpioMode(mDev, pin, 0);
		setGpioConfig(mDev, pin, 1);
		return;
	case PULL_UP :
		mDev->BSRR = 0x0001 << pin;
		break;
	case PULL_DOWN :
		mDev->BRR = 0x0001 << pin;
		break;
	}

	setGpioMode(mDev, pin, 0);
	setGpioConfig(mDev, pin, 2);
}

error Gpio::setAsOutput(uint8_t pin, uint8_t ospeed, uint8_t otype)
{
	setGpioConfig(mDev, pin, otype);
	setGpioMode(mDev, pin, ospeed);

	return error::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if (data)
		mDev->BSRR = 0x0001 << pin;
	else
		mDev->BRR = 0x0001 << pin;
}

error Gpio::setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t ospeed, uint8_t otype)
{
	volatile uint32_t *mapr = &AFIO->MAPR;

	setGpioConfig(mDev, pin, otype | 0x2);
	setGpioMode(mDev, pin, ospeed);

	using namespace define::gpio::altfunc;

	switch (altFunc)
	{
	case PB8_I2C1_SCL:
	case PB9_I2C1_SDA:
		setBitData(*mapr, true, 1);
		break;
	case PB3_SPI1_SCK:
	case PB4_SPI1_MISO:
	case PB5_SPI1_MOSI:
		setBitData(*mapr, true, 0);
		break;
	case PB9_CAN_TX:
	case PB8_CAN_RX:
		setFieldData(*mapr, 0x3 << 13, 2, 13);
		break;
	case PA11_CAN_RX:
	case PA12_CAN_TX:
		setFieldData(*mapr, 0x3 << 13, 0, 13);
		break;
	case PA15_TIM2_CH1_ETR:
	case PB3_TIM2_CH2:
		setBitData(*mapr, true, 8);
		break;
	case PB10_TIM2_CH3:
	case PB11_TIM2_CH4:
		setBitData(*mapr, true, 9);
		break;
	case PC6_TIM3_CH1:
	case PC7_TIM3_CH2:
	case PC8_TIM3_CH3:
	case PC9_TIM3_CH4:
		setFieldData(*mapr, 0x3 << 10, 3, 10);
		break;
	case PA6_TIM3_CH1:
	case PA7_TIM3_CH2:
		setFieldData(*mapr, 0x3 << 10, 0, 10);
		break;
	case PB4_TIM3_CH1:
	case PB5_TIM3_CH2:
		setFieldData(*mapr, 0x3 << 10, 2, 10);
		break;
	case PB0_TIM3_CH3:
	case PB1_TIM3_CH4:
		setBitData(*mapr, false, 10);
		break;
	case PB10_USART3_TX:
	case PB11_USART3_RX:
		setFieldData(*mapr, 0x3 << 4, 0, 4);
		break;
	case PB6_USART1_TX:
	case PB7_USART1_RX:
		setBitData(*mapr, true, 2);
		break;
	case PA9_USART1_TX:
	case PA10_USART1_RX:
		setBitData(*mapr, false, 2);
		break;
	}

	return error::ERROR_NONE;
}

bool Gpio::getInputData(uint8_t pin)
{
	return getBitData(mDev->IDR, pin);
}

void Gpio::setAsAnalog(uint8_t pin)
{
	setGpioMode(mDev, pin, 0);
	setGpioConfig(mDev, pin, 0);
}

void Gpio::setPullUpDown(uint8_t pin, uint8_t pupd)
{
	setGpioMode(mDev, pin, 0);
	setGpioConfig(mDev, pin, 2);

	if (pupd == define::gpio::pupd::PULL_UP)
		mDev->BSRR = 0x0001 << pin;
	else
		mDev->BRR = 0x0001 << pin;
}
#endif

