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

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ILI9488_spi_with_Brush_RGB888.h>

static const Spi::Specification gLcdSpec =
{
	define::spi::mode::MODE0,	//uint8_t mode;
	40000000,					//uint32_t maxFreq;
	define::spi::bit::BIT8		//uint8_t bit;
};

ILI9488_spi_with_Brush_RGB888::ILI9488_spi_with_Brush_RGB888(void)
{
	mSpec = &gLcdSpec;
}

void ILI9488_spi_with_Brush_RGB888::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
	mCsPin.port->setOutput(mCsPin.pin, true);
	
	// CS 핀이 10ms 정도 High로 고정될 수 있도록 대기
	thread::delay(10);
}

void ILI9488_spi_with_Brush_RGB888::sendCmd(uint8_t cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9488_spi_with_Brush_RGB888::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((int8_t *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9488_spi_with_Brush_RGB888::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ILI9488_spi_with_Brush_RGB888::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9488_spi_with_Brush_RGB888::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(10);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
		sendCmd(SOFTWARE_RESET);

	thread::delay(200);
}

void ILI9488_spi_with_Brush_RGB888::setSpiSpecification(const Spi::Specification &spec)
{
	mSpec = &spec;
}

#endif

