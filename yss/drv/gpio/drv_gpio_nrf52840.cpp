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

#if defined(NRF52840_XXAA)

#include <drv/Gpio.h>
#include <yss/reg.h>

namespace drv
{
Gpio::Gpio(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mExti = config.exti;
}

void Gpio::setExti(unsigned char pin)
{
	//unsigned char field = pin % 4 * 4;
	//unsigned int reg = SYSCFG->EXTICR[pin / 4];
	//reg &= 0xF << field;
	//reg |= mExti << field;
	//SYSCFG->EXTICR[pin / 4] = reg;
}

void Gpio::setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, unsigned char otype)
{
	using namespace define::gpio::altfunc;
	unsigned char port;

	switch((unsigned int)mPeri)
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
		NRF_UART0->PSEL.RTS = (1 << 31) | (port << 5) | pin;
		break;

	case UART0_TXD :
		NRF_UART0->PSEL.TXD = (1 << 31) | (port << 5) | pin;
		break;

	case UART0_CTS :
		NRF_UART0->PSEL.CTS = (1 << 31) | (port << 5) | pin;
		break;

	case UART0_RXD :
		NRF_UART0->PSEL.RXD = (1 << 31) | (port << 5) | pin;
		break;
	}

	setFieldData(mPeri->PIN_CNF[pin], 0x7 << 8, otype & 0x7, 8);
}

void Gpio::setAsInput(unsigned char pin, unsigned char pullUpDown)
{
	mPeri->DIRCLR = 1 << pin;
	setFieldData(mPeri->PIN_CNF[pin], 0x3 << 2, pullUpDown & 0x3, 2);
}

//void Gpio::setPackageAsAltFunc(AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype){}
// 구조적으로 지원 불가

void Gpio::setAsOutput(unsigned char pin, unsigned char ospeed, unsigned char otype)
{
	mPeri->DIRSET = 1 << pin;
	setFieldData(mPeri->PIN_CNF[pin], 0x7 << 8, otype & 0x7, 8);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
	if(data)
		mPeri->OUTSET = 1 << pin;
	else
		mPeri->OUTCLR = 1 << pin;
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
	setFieldData(mPeri->PIN_CNF[pin], 0x3 << 2, pupd & 0x3, 2);
}

// void Gpio::setAsAnalog(unsigned char pin){}
// 아날로그 핀이 없음

bool Gpio::getData(unsigned char pin)
{
	return (mPeri->IN >> pin) & 0x01;
}
}

#endif
