/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(GD32F1) || defined(STM32F1)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

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

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mExti = setup.exti;
}

void Gpio::setExti(uint8_t pin)
{
	uint8_t index = pin / 4;
	volatile uint32_t *exticr = AFIO->EXTICR;
	pin %= 4;
	setFieldData(exticr[index], 0xfUL << pin * 4, mExti, pin * 4);
}

void Gpio::setPackageAsAltFunc(altFuncPort_t *altport, uint8_t numOfPort, ospeed_t ospeed, otype_t otype)
{
	// 지원 안됨
	(void)altport;
	(void)numOfPort;
	(void)ospeed;
	(void)otype;
}

void Gpio::setAsInput(uint8_t pin, pupd_t pupd)
{
	switch((uint16_t)pupd)
	{
	case PUPD_NONE :
		setGpioMode(mDev, pin, 0);
		setGpioConfig(mDev, pin, 1);
		return;
	case PUPD_PULL_UP :
		mDev->BSRR = 0x0001 << pin;
		break;
	case PUPD_PULL_DOWN :
		mDev->BRR = 0x0001 << pin;
		break;
	}

	setGpioMode(mDev, pin, 0);
	setGpioConfig(mDev, pin, 2);
}

error_t Gpio::setAsOutput(uint8_t pin, ospeed_t ospeed, otype_t otype)
{
	setGpioConfig(mDev, pin, otype);
	setGpioMode(mDev, pin, ospeed);

	return error_t::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if (data)
		mDev->BSRR = 0x0001 << pin;
	else
		mDev->BRR = 0x0001 << pin;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altFunc, ospeed_t ospeed, otype_t otype)
{
	volatile uint32_t *mapr = &AFIO->MAPR;
	
	switch(altFunc)
	{
	case PB7_USART1_RX:
	case PA10_USART1_RX:
	case PA3_USART2_RX:
	case PD6_USART2_RX:
	case PB11_USART3_RX:
	case PC11_USART3_RX:
	case PD9_USART3_RX:
	case PC11_UART4_RX:
	case PA0_CAPTURE5_CH1:
	case PA1_CAPTURE5_CH2:
	case PA1_CAPTURE2_CH2:
	case PA2_CAPTURE5_CH3:
	case PA2_CAPTURE9_CH1:
	case PA2_CAPTURE2_CH3:
	case PA3_CAPTURE5_CH4:
	case PA3_CAPTURE2_CH4:
	case PA3_CAPTURE9_CH2:
	case PA6_CAPTURE3_CH1:
	case PA6_CAPTURE13_CH1:
	case PA7_CAPTURE8_CH1N:
	case PA7_CAPTURE3_CH2:
	case PA7_CAPTURE14_CH1:
	case PA8_CAPTURE1_CH1:
	case PA10_CAPTURE1_CH2:
	case PA10_CAPTURE1_CH3:
	case PA11_CAPTURE1_CH4:
	case PA15_CAPTURE2_CH1:
	case PB0_CAPTURE3_CH3:
	case PB0_CAPTURE8_CH2N:
	case PB0_CAPTURE1_CH2:
	case PB1_CAPTURE3_CH4:
	case PB1_CAPTURE8_CH3N:
	case PB1_CAPTURE1_CH3N:
	case PB3_CAPTURE2_CH2:
	case PB4_CAPTURE3_CH1:
	case PB5_CAPTURE3_CH2:
	case PB6_CAPTURE4_CH1:
	case PB7_CAPTURE4_CH2:
	case PB8_CAPTURE4_CH3:
	case PB8_CAPTURE10_CH1:
	case PB9_CAPTURE4_CH4:
	case PB9_CAPTURE1_CH1:
	case PB10_CAPTURE2_CH3:
	case PB11_CAPTURE2_CH4:
	case PB13_CAPTURE1_CH1N:
	case PB14_CAPTURE1_CH2N:
	case PB14_CAPTURE12_CH1:
	case PB15_CAPTURE1_CH3N:
	case PB15_CAPTURE12_CH2:
	case PC6_CAPTURE8_CH1:
	case PC6_CAPTURE3_CH1:
	case PC7_CAPTURE8_CH2:
	case PC7_CAPTURE3_CH2:
	case PC8_CAPTURE8_CH3:
	case PC8_CAPTURE3_CH3:
	case PC9_CAPTURE3_CH3:
	case PC9_CAPTURE3_CH4:
	case PD12_CAPTURE4_CH1:
	case PD13_CAPTURE4_CH2:
	case PD14_CAPTURE4_CH3:
	case PD15_CAPTURE4_CH4:
	case PE5_CAPTURE9_CH1:
	case PE6_CAPTURE9_CH2:
	case PE8_CAPTURE1_CH1N:
	case PE9_CAPTURE1_CH1:
	case PE10_CAPTURE1_CH2N:
	case PE11_CAPTURE1_CH2:
	case PE12_CAPTURE1_CH3N:
	case PE13_CAPTURE1_CH3:
	case PE14_CAPTURE1_CH4:
	case PF6_CAPTURE10_CH1:
	case PF7_CAPTURE11_CH1:
	case PF8_CAPTURE13_CH1:
	case PF9_CAPTURE14_CH1:
		setGpioMode(mDev, pin, 0);
		setGpioConfig(mDev, pin, 1);
		break;
	default :
		setGpioConfig(mDev, pin, otype | 0x2);
		setGpioMode(mDev, pin, ospeed);
		break;
	}

	switch ((uint16_t)altFunc)
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
	case PA15_CAPTURE2_CH1:
	case PB3_TIM2_CH2:
	case PB3_CAPTURE2_CH2:
		setBitData(*mapr, true, 8);
		break;

	case PB10_TIM2_CH3:
	case PB10_CAPTURE2_CH3:
	case PB11_TIM2_CH4:
	case PB11_CAPTURE2_CH4:
		setBitData(*mapr, true, 9);
		break;

	case PC6_TIM3_CH1:
	case PC6_CAPTURE8_CH1:
	case PC7_TIM3_CH2:
	case PC7_CAPTURE8_CH2:
	case PC8_TIM3_CH3:
	case PC8_CAPTURE3_CH3:
	case PC9_TIM3_CH4:
	case PC9_CAPTURE3_CH4:
		setFieldData(*mapr, 0x3 << 10, 3, 10);
		break;

	case PA6_TIM3_CH1:
	case PA6_CAPTURE3_CH1:
	case PA7_TIM3_CH2:
	case PA7_CAPTURE3_CH2:
		setFieldData(*mapr, 0x3 << 10, 0, 10);
		break;

	case PB4_TIM3_CH1:
	case PB4_CAPTURE3_CH1:
	case PB5_TIM3_CH2:
	case PB5_CAPTURE3_CH2:
		setFieldData(*mapr, 0x3 << 10, 2, 10);
		break;

	case PB0_TIM3_CH3:
	case PB0_CAPTURE3_CH3:
	case PB1_TIM3_CH4:
	case PB1_CAPTURE3_CH4:
		setBitData(*mapr, false, 10);
		break;

	case PB10_USART3_TX:
	case PB11_USART3_RX:
		setFieldData(*mapr, 0x3 << 4, 0, 4);
		break;

	case PC10_USART3_TX :
	case PC11_USART3_RX :
		setFieldData(*mapr, 0x3 << 4, 1, 4);
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

	return error_t::ERROR_NONE;
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

void Gpio::setPullUpDown(uint8_t pin, pupd_t pupd)
{
	setGpioMode(mDev, pin, 0);
	setGpioConfig(mDev, pin, 2);

	if (pupd == PUPD_PULL_UP)
		mDev->BSRR = 0x0001 << pin;
	else
		mDev->BRR = 0x0001 << pin;
}
#endif

