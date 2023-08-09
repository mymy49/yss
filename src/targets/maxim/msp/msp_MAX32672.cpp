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