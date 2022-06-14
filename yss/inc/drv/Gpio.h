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

#if defined(STM32F1)

typedef GPIO_TypeDef		YSS_GPIO_Peri;

#include "gpio/config_gpio_stm32f1.h"
#include "gpio/define_gpio_stm32f1.h"

#elif defined(STM32F7) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)

typedef GPIO_TypeDef		YSS_GPIO_Peri;

#include "gpio/config_gpio_stm32f4_f7_g4.h"
#include "gpio/define_gpio_stm32f4_f7_g4.h"

#elif defined(GD32F10X_XD) || defined(GD32F10X_HD)

#include "gpio/config_gpio_gd32f1.h"
#include "gpio/define_gpio_gd32f1.h"

typedef GPIO_TypeDef		YSS_GPIO_Peri;

#elif defined(GD32F450)

#include "gpio/config_gpio_gd32f4.h"
#include "gpio/define_gpio_gd32f4.h"

typedef unsigned int		YSS_GPIO_Peri;

#else

#define YSS_DRV_GPIO_UNSUPPORTED

#endif

#ifndef YSS_DRV_GPIO_UNSUPPORTED

#include <drv/Drv.h>

namespace drv
{
class Gpio : public Drv
{
	YSS_GPIO_Peri *mPeri;
	unsigned char mExti;

  public:
	struct Pin
	{
		drv::Gpio *port;
		unsigned char pin;
	};

	Gpio(YSS_GPIO_Peri *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), unsigned char exti);
	void setExti(unsigned char pin);
	void setAllClock(bool en);
	void setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed = define::gpio::ospeed::MID, bool otype = define::gpio::otype::PUSH_PULL);
	void setPackageAsAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype);
	void setAsOutput(unsigned char pin, unsigned char ospeed = define::gpio::ospeed::MID, unsigned char otype = define::gpio::otype::PUSH_PULL);
	void setAsInput(unsigned char pin, unsigned char pullUpDown = define::gpio::pupd::NONE);
	void setOutput(unsigned char pin, bool data);
	void setPullUpDown(unsigned char pin, unsigned char pupd);
	bool getData(unsigned char pin);
	void setAsAnalog(unsigned char pin);
};
}

#define setToAltFunc setAsAltFunc
#define setToInput setAsInput
#define setToOutput setAsOutput
#define setToAnalog setAsAnalog

namespace config
{
namespace gpio
{
struct Set
{
	drv::Gpio *port;
	unsigned char pin;
};
}
}

#endif

#endif


