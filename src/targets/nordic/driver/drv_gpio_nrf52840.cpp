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

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/nordic/nrf52840_bitfields.h>

Gpio::Gpio(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
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

//void Gpio::setPackageAsAltFunc(AltFunc *altport, uint8_t numOfPort, uint8_t ospeed, bool otype){}
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
