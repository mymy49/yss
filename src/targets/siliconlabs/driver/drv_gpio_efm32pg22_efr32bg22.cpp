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

Gpio::Gpio(const Drv::Setup drvSetup, const Setup setup) : GpioBase(drvSetup)
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

