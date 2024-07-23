/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(MAX32672)

#include <config.h>
#include <yss/reg.h>

#include <yss/instance.h>

void __WEAK initializeSystem(void)
{
	using namespace define::clock;

	// 클록의 내부 값들을 초기화 하기 위해 무조건 호출한다.
	clock.initialize();

	// OVR 설정을 이곳에 추가
	// 이 설정에서 SYS_OSC를 INRO로 변경함
	clock.setOperatingVoltageRange(ovr::V_CORE_0_9V);

	// 외부 크리스탈 활성화 설정
	// 기본적으로 MAX32672는 100MHz가 기본 클럭 소스로 활성화되어 기본 클럭으로 동작중이다.
	// 그러므로 외부 클럭 설정은 옵션이다.
	//clock.enableErfo(ERFO_CLOCK_FREQ);

	// IBRO 클럭 활성화 설정
	clock.enableIbro();

	// ERTCO(32.768 kHz) 클럭 활성화 설정
	clock.enableErtco();
	
	// SYS_OSC 클럭 소스 변경
	// 리셋 후, 기본 클럭 소스가 IPO이다. 
	// 그러나 FLASH WAIT STATE 업데이트를 위해 IPO를 그대로 사용하더라도 한번 호출해줘야 한다.
	clock.setSysclk(sysclk::src::IBRO, sysclk::div::DIV_1);

	// 캐시를 활성화 한다.
	clock.enableCache();
}

void __WEAK initializeDma(void)
{

}

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

#endif