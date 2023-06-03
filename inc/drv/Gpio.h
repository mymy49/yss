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

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(STM32F1)

typedef GPIO_TypeDef			YSS_GPIO_Peri;

#elif defined(STM32F4) || defined(STM32F7)

#include <targets/st_gigadevice/define_gpio_stm32f0_f4_f7_g4.h>

typedef volatile uint32_t		YSS_GPIO_Peri;

#elif defined(STM32L1)

#include "gpio/define_gpio_stm32l1.h"

typedef volatile uint32_t		YSS_GPIO_Peri;

#elif defined(GD32F4)

#include <targets/st_gigadevice/define_gpio_gd32f4.h>

typedef volatile uint32_t		YSS_GPIO_Peri;

#elif defined(NRF52840_XXAA)

#include <targets/nordic/define_gpio_nrf52840.h>

typedef NRF_GPIO_Type			YSS_GPIO_Peri;

#elif defined(EFM32PG22) || defined(EFR32BG22)

typedef GPIO_TypeDef			YSS_GPIO_Peri;
#define GpioTargetHeaderFile	<targets/siliconlabs/class_gpio_efm32pg22_efr32bg22.h>

#elif defined(STM32F7_N) || defined(STM32F1_N) || defined(STM32F4_N) || defined(STM32F0_N) || defined(GD32F1)

typedef GPIO_TypeDef			YSS_GPIO_Peri;
#define GpioTargetHeaderFile	<targets/st/class_gpio_stm32f0_f1_f4_f7.h>

#else

typedef volatile uint32_t		YSS_GPIO_Peri;

#define YSS_DRV_GPIO_UNSUPPORTED

#endif

#include "Drv.h"

#if defined(STM32F1) || defined(STM32F0) || defined(STM32F7) || defined(GD32F4) || defined(STM32F4) || defined(NRF52840_XXAA)
class Gpio : public Drv
{
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

	struct Setup
	{
		YSS_GPIO_Peri *peri;
		uint8_t exti;
	};

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

	Gpio(YSS_GPIO_Peri *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), uint8_t exti);

	Gpio(const Drv::Setup drvConfig, const Setup config);

private :
	YSS_GPIO_Peri *mPeri;
	uint8_t mExti;
};

#elif defined(EFM32PG22) || defined(STM32F4_N) || defined(STM32F1_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined(EFR32BG22) || defined(GD32F1) // 추후 앞으로 이 방식을 사용할 예정

class Gpio;

class GpioBase : public Drv
{
public :
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

	// 아래 멤버 함수들을 상속 받는 곳에서 다시 선언하고 구현해야함

	// 설정된 핀의 출력값을 제어한다.
	// 
	// uint8_t pin
	//		설정할 핀의 번호를 설정한다.
	// bool data
	//		출력할 값을 설정한다. true일 경우 High가 출력된다.
	void setOutput(uint8_t pin, bool data);

	bool getInputData(uint8_t pin);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	GpioBase(const Drv::Setup drvSetup) : Drv(drvSetup) {}
};

#include GpioTargetHeaderFile

#endif

#endif

