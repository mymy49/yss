/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <targets/siliconlabs/efm32pg22_cmu.h>
#include <targets/siliconlabs/efm32pg22_dcdc.h>

#if defined(EFM32PG22)

#include <config.h>
#include <yss/reg.h>
#include <drv/peripheral.h>
#include <yss/instance.h>

// EFM32PG22 시리즈는 yss OS에서 micro second 관련 기능에 관해 정상적으로 사용하기 위해
// 외부 크리스탈을 100 kHz 단위 이상되는 제품을 사용해야 한다.
// 예를 들어 38.4 MHz는 사용 가능하지만, 12.34 MHz는 10kHz 단위의 숫자를 갖고 있기 때문에 사용 불가능하다.
void __WEAK initializeSystem(void)
{
	clock.initialize();
	
	// DCDC 컨버터를 사용하도록 회로가 구성된 경우 사용
	clock.enableApb0Clock(_CMU_CLKEN0_DCDC_SHIFT, true);
	DCDC->EN_SET = _DCDC_EN_EN_MASK;
	DCDC->CTRL_SET = _DCDC_CTRL_MODE_DCDCREGULATION;

	// 외부 크리스탈 활성화
	clock.enableApb0Clock(_CMU_CLKEN0_HFXO0_SHIFT, true);
	clock.enableHfxo(11000, 160, HSE_CLOCK_FREQ);

	// DPLL 활성화
	// n/10 MHz의 동작 주파수가 설정된다.
	// 반드시 MHz 단위의 사용 주파수가 설정되야 한다.
	clock.enableDpll(Clock::DPLLREF::HFXO, 760, HSE_CLOCK_FREQ/100000); 
	
	// SYSCLK 변경
	clock.setSysclk(Clock::SYSCLK_SRC::HFRCODPLL_SRC, 1, 1);

	// GPIO 활성화
	clock.enableApb0Clock(_CMU_CLKEN0_GPIO_SHIFT, true);
}

void initializeDma(void)
{
	dmaChannel1.enableClock();
	dmaChannel1.initialize();
	dmaChannel1.enableInterrupt();
}

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

#endif