/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/nordic/nrf52840_bitfields.h>

Gpio::Gpio(const Drv::setup_t drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mExti = config.exti;
}

void Gpio::setExti(uint8_t pin)
{
	//uint8_t field = pin % 4 * 4;
	//uint32_t reg = SYSCFG->EXTICR[pin / 4];
	//reg &= 0xF << field;
	//reg |= mExti << field;
	//SYSCFG->EXTICR[pin / 4] = reg;
}

void Gpio::setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t ospeed, uint8_t otype)
{
	using namespace define::gpio::altfunc;
	uint8_t port;

	switch((uint32_t)mPeri)
	{
	case NRF_P0_BASE :
		port = 0;
		break;

	case NRF_P1_BASE :
		port = 1;
		break;

	default :
		return;
	}

	switch(altFunc)
	{
	case UART0_RTS :
		NRF_UART0->PSEL.RTS = (port << 5) | pin;
		break;

	case UART0_TXD :
		NRF_UART0->PSEL.TXD = (port << 5) | pin;
		break;

	case UART0_CTS :
		NRF_UART0->PSEL.CTS = (port << 5) | pin;
		break;

	case UART0_RXD :
		NRF_UART0->PSEL.RXD = (port << 5) | pin;
		break;
	}

	setFieldData(mPeri->PIN_CNF[pin], 0x7 << 8, otype & 0x7, 8);
}

void Gpio::setAsInput(uint8_t pin, uint8_t pullUpDown)
{
	mPeri->DIRCLR = 1 << pin;
	setFieldData(mPeri->PIN_CNF[pin], 0x3 << 2, pullUpDown & 0x3, 2);
}

//void Gpio::setPackageAsAltFunc(altFunc_t *altport, uint8_t numOfPort, uint8_t ospeed, bool otype){}
// 구조적으로 지원 불가

void Gpio::setAsOutput(uint8_t pin, uint8_t ospeed, uint8_t otype)
{
	mPeri->DIRSET = 1 << pin;
	setFieldData(mPeri->PIN_CNF[pin], 0x7 << 8, otype & 0x7, 8);
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if(data)
		mPeri->OUTSET = 1 << pin;
	else
		mPeri->OUTCLR = 1 << pin;
}

void Gpio::setPullUpDown(uint8_t pin, uint8_t pupd)
{
	setFieldData(mPeri->PIN_CNF[pin], 0x3 << 2, pupd & 0x3, 2);
}

// void Gpio::setAsAnalog(uint8_t pin){}
// 아날로그 핀이 없음

bool Gpio::getInputData(uint8_t pin)
{
	return (mPeri->IN >> pin) & 0x01;
}

uint32_t Gpio::getPeripheralAddress(void)
{
	return (uint32_t)mPeri;
}

#endif
