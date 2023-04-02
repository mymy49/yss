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

#include <drv/mcu.h>

#if defined(STM32L0)

#include <config.h>

#include <instance/instance_clock.h>
#include <instance/instance_flash.h>

void __WEAK initializeSystem(void)
{
	int32_t hseFreq = HSE_CLOCK_FREQ, mul = -1, div = -1, freq;
	const int32_t  mulTable[9] = {3, 4, 6, 8, 12, 16, 24, 32, 48};
	const int32_t  divTable[3] = {1, 2, 3};

	using namespace define::clock;

	clock.setVosRange(vos::RANGE1);

	clock.enableHsi();

	clock.enableHse(HSE_CLOCK_FREQ);

	for (int32_t  i = 0; i < 9; i++)
	{
		freq = hseFreq * mulTable[i];

		if (freq == ec::clock::sysclk::MAX_FREQ / 1000000 * 2)
		{
			mul = i;
			div = 1;
			break;
		}
		else if (freq == ec::clock::sysclk::MAX_FREQ / 1000000 * 3)
		{
			mul = i;
			div = 2;
			break;
		}
	}

	if (mul >= 0 && div >= 0)
	{
		clock.pll.enable(
			define::clock::pll::src::HSE, // uint8_t src;
			mul,                          // uint8_t mul;
			div                           // uint8_t div;
		);

		clock.setSysclk(
			define::clock::sysclk::src::PLL,       // uint8_t sysclkSrc;
			define::clock::divFactor::ahb::NO_DIV, // uint8_t ahb;
			define::clock::divFactor::apb::NO_DIV, // uint8_t apb1;
			define::clock::divFactor::apb::NO_DIV  // uint8_t apb2;
		);
	}

	flash.setPrefetchEn(true);
	flash.setPreReadEn(true);

#if defined(GPIOA)
	clock.peripheral.setGpioAEn(true);
#endif
#if defined(GPIOB)
	clock.peripheral.setGpioBEn(true);
#endif
#if defined(GPIOC)
	clock.peripheral.setGpioCEn(true);
#endif
#if defined(GPIOD)
	clock.peripheral.setGpioDEn(true);
#endif
#if defined(GPIOE)
	clock.peripheral.setGpioEEn(true);
#endif
#if defined(GPIOH)
	clock.peripheral.setGpioHEn(true);
#endif
}

#endif

