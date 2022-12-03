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

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1)

#include <targets/st_gigadevice/define_gpio_gd32f1.h>

typedef volatile uint32_t	YSS_GPIO_Peri;

#elif defined(STM32F4) || defined(STM32F7)

#include <targets/st_gigadevice/define_gpio_stm32f4_f7_g4.h>

typedef volatile uint32_t	YSS_GPIO_Peri;

#elif defined(STM32L1)

#include "gpio/define_gpio_stm32l1.h"

typedef volatile uint32_t	YSS_GPIO_Peri;

#elif defined(STM32F0)

#include <targets/st_gigadevice/define_gpio_stm32f0.h>

typedef volatile uint32_t	YSS_GPIO_Peri;

#elif defined(GD32F4)

#include <targets/st_gigadevice/define_gpio_gd32f4.h>

typedef uint32_t		YSS_GPIO_Peri;

#elif defined(NRF52840_XXAA)

#include <targets/nordic/define_gpio_nrf52840.h>

typedef NRF_GPIO_Type		YSS_GPIO_Peri;

#else

#define YSS_DRV_GPIO_UNSUPPORTED

#endif

#include "Drv.h"

class Gpio : public Drv
{
	YSS_GPIO_Peri *mPeri;
	uint8_t mExti;

  public:
	struct AltFunc
	{
		YSS_GPIO_Peri *port;
		uint8_t pin;
		uint8_t func;
	};

	struct Pin
	{
		Gpio *port;
		uint8_t pin;
	};

	struct Config
	{
		YSS_GPIO_Peri *peri;
		uint8_t exti;
	};

	Gpio(YSS_GPIO_Peri *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), uint8_t exti);
	Gpio(const Drv::Config drvConfig, const Config config);

	void setExti(uint8_t pin);
	void setAllClock(bool en);
	void setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t ospeed = define::gpio::ospeed::MID, uint8_t otype = define::gpio::otype::PUSH_PULL);
	void setPackageAsAltFunc(AltFunc *altport, uint8_t numOfPort, uint8_t ospeed, uint8_t otype);
	void setAsOutput(uint8_t pin, uint8_t ospeed = define::gpio::ospeed::MID, uint8_t otype = define::gpio::otype::PUSH_PULL);
	void setAsInput(uint8_t pin, uint8_t pullUpDown = define::gpio::pupd::NONE);
	void setOutput(uint8_t pin, bool data);
	void setPullUpDown(uint8_t pin, uint8_t pupd);
	bool getInputData(uint8_t pin);
	void setAsAnalog(uint8_t pin);

	uint32_t getPeripheralAddress(void);
};

#endif

