/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/Gpio.h>
#include <yss/reg.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_gpio.h>
#include <targets/siliconlabs/efm32pg22_gpio_port.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_gpio.h>
#include <targets/siliconlabs/efr32bg22_gpio_port.h>
#endif

Gpio::Gpio(const Drv::setup_t drvSetup, const Setup setup) : GpioBase(drvSetup)
{
	mDev = setup.dev;
	mPort = setup.port;
	mPinCount = setup.pinCount;
}

error Gpio::setAsOutput(uint8_t pin, uint8_t otype)
{
	if(pin >= mPinCount)
		return error::WRONG_CONFIG;
	
	if(pin < 7)
	{
		pin *= 4;
		setFieldData(mDev->P[mPort].MODEL, _GPIO_P_MODEL_MODE0_MASK << pin, otype, pin);
	}
	else
	{
		pin *= 4;
		setFieldData(mDev->P[mPort].MODEH, _GPIO_P_MODEH_MODE0_MASK << pin, otype, pin);
	}

	return error::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	setBitData(mDev->P[mPort].DOUT, data, pin);
}

#define _GPIO_PIN_MASK		_GPIO_USART_RXROUTE_PIN_MASK
#define _GPIO_PIN_SHIFT		_GPIO_USART_RXROUTE_PIN_SHIFT
#define _GPIO_PORT_MASK		_GPIO_USART_RXROUTE_PORT_MASK
#define _GPIO_PORT_SHIFT	_GPIO_USART_RXROUTE_PORT_SHIFT

error Gpio::setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t alttype)
{
	using namespace define::gpio;
	volatile uint32_t *des;

	if(pin >= mPinCount)
		return error::WRONG_CONFIG;

	switch(altFunc)
	{
	case altfunc::UART0_RX :
	case altfunc::SPI0_MISO :
		mDev->USARTROUTE[0].ROUTEEN |= _GPIO_USART_ROUTEEN_RXPEN_MASK;
		des = &mDev->USARTROUTE[0].RXROUTE;
		break;

	case altfunc::UART0_TX :
	case altfunc::SPI0_MOSI :
		mDev->USARTROUTE[0].ROUTEEN |= _GPIO_USART_ROUTEEN_TXPEN_MASK;
		des = &mDev->USARTROUTE[0].TXROUTE;
		break;

	case altfunc::SPI0_SCK :
		mDev->USARTROUTE[0].ROUTEEN |= _GPIO_USART_ROUTEEN_CLKPEN_MASK;
		des = &mDev->USARTROUTE[0].CLKROUTE;
		break;

	case altfunc::UART1_RX :
	case altfunc::SPI1_MISO :
		mDev->USARTROUTE[1].ROUTEEN |= _GPIO_USART_ROUTEEN_RXPEN_MASK;
		des = &mDev->USARTROUTE[1].RXROUTE;
		break;

	case altfunc::UART1_TX :
	case altfunc::SPI1_MOSI :
		mDev->USARTROUTE[1].ROUTEEN |= _GPIO_USART_ROUTEEN_TXPEN_MASK;
		des = &mDev->USARTROUTE[1].TXROUTE;
		break;
	
	case altfunc::SPI1_SCK :
		mDev->USARTROUTE[1].ROUTEEN |= _GPIO_USART_ROUTEEN_CLKPEN_MASK;
		des = &mDev->USARTROUTE[1].CLKROUTE;
		break;

	case altfunc::PDM_CLK :
		mDev->PDMROUTE.ROUTEEN |= _GPIO_PDM_ROUTEEN_CLKPEN_MASK;
		des = &mDev->PDMROUTE.CLKROUTE;
		break;

	case altfunc::PDM_DAT0 :
		mDev->PDMROUTE.ROUTEEN |= _GPIO_PDM_DAT0ROUTE_MASK;
		des = &mDev->PDMROUTE.DAT0ROUTE;
		break;

	case altfunc::PDM_DAT1 :
		mDev->PDMROUTE.ROUTEEN |= _GPIO_PDM_DAT1ROUTE_MASK;
		des = &mDev->PDMROUTE.DAT1ROUTE;
		break;

	default :
		return error::WRONG_CONFIG;
	}

	setTwoFieldData(*des,	_GPIO_PIN_MASK, pin, _GPIO_PIN_SHIFT,
							_GPIO_PORT_MASK, mPort, _GPIO_PORT_SHIFT);

	if(pin < 7)
	{
		pin *= 4;
		setFieldData(mDev->P[mPort].MODEL, _GPIO_P_MODEL_MODE0_MASK << pin, alttype, pin);
	}
	else
	{
		pin *= 4;
		setFieldData(mDev->P[mPort].MODEH, _GPIO_P_MODEH_MODE0_MASK << pin, alttype, pin);
	}

	return error::ERROR_NONE;
}

#endif

