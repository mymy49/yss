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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CLASS_GPIO_NUVOTON__H_
#define YSS_CLASS_GPIO_NUVOTON__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <drv/Drv.h>

class Gpio : public Drv
{
public:
	typedef enum 
	{
		PUSH_PULL = 1,
		OPEN_DRAIN,
		QUASI_BIDIR
	}otype_t;

	typedef enum
	{
		ALTFUNC_GPIO = 0,

		PA8_SPI2_MOSI = 4,

		PA9_SPI2_MISO = 4,

		PA10_SPI2_CLK = 4,

		PA11_SPI2_SS = 4,

		PB12_UART0_RXD = 6,

		PB13_UART0_TXD = 6,

		PC0_SPI1_SS = 7,

		PC1_SPI1_CLK = 7,

		PC2_SPI1_MOSI = 7,
		
		PC3_SPI1_MISO = 7,

		PC4_SPI1_I2SMCLK = 7,

	}altfunc_t;

	// 핀을 출력으로 설정합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정합니다.
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsOutput(uint8_t pin, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	// 핀의 출력 값을 설정합니다.
	// 
	// uint8_t pin
	//		출력을 변경할 핀의 번호를 설정합니다.
	// bool data
	//		출력의 값을 설정합니다.
	void setOutput(uint8_t pin, bool data) __attribute__((optimize("-O1")));

	// 핀을 대체 기능으로 설정합니다
	//
	// uint8_t pin
	//		대체 기능으로 변경할 핀의 번호를 설정합니다.
	// altfunc_t altFunc
	//		핀의 대체 기능을 설정합니다.
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsAltFunc(uint8_t pin, altfunc_t altfunc, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	struct setup_t
	{
		YSS_GPIO_Peri *dev;
		volatile uint32_t *mfp;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

private:
	YSS_GPIO_Peri *mDev;
	volatile uint32_t *mMfp;
};

#endif