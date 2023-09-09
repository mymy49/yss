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

#ifndef YSS_DRV_DAC__H_
#define YSS_DRV_DAC__H_

#include "mcu.h"

#if defined (STM32F4_N)

typedef DAC_TypeDef				YSS_DAC_Peri;

#else

#define YSS_DRV_DAC_UNSUPPORTED
typedef volatile uint32_t		YSS_DAC_Peri;

#endif

#include "Drv.h"

class Dac : public Drv
{
public:
	// DAC 장치를 초기화 한다. 초기화만 했을 뿐, 장치는 정상적인 활성화 되어 있지 않다.
	// 개별 채널에 대해 별도의 활성화가 필요하다.
	// 
	// 반환
	//		에러를 반환한다.
	void initialize(void);

	// DAC 채널1을 활성화/비활성화 한다.
	// 
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enableChannel1(bool en = true);

	// DAC 채널2를 활성화/비활성화 한다.
	// 
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enableChannel2(bool en = true);
	
	// DAC 채널1의 출력 값을 설정한다.
	//
	// uint16_t value
	//		DAC 출력 값을 설정한다.
	void setOutputChannel1(uint16_t value);

	// DAC 채널2의 출력 값을 설정한다.
	//
	// uint16_t value
	//		DAC 출력 값을 설정한다.
	void setOutputChannel2(uint16_t value);

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	struct Setup
	{
		YSS_DAC_Peri *dev;
	};

	Dac(const Drv::Setup drvSetup, const Setup setup);

private:
	YSS_DAC_Peri *mDev;
};

#endif

// 초기화 방법
//		- GPIO의 setAsAnalog()함수를 사용해 관련된 포트를 아날로그 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치의 설정을 초기화 한다.
//		- enableChannel1() 또는 enableChannel2() 함수를 사용해 채널의 출력을 활성화 한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다. (실제로 enableInterrupt() 함수는 기능이 유효하지 않음)

// ##### 초기화 예시 #####
/*
	gpioA.setAsAnalog(4); // GPIOA_4번 핀을 아닐로그 핀으로 설정
	
	dac1.enableClock();
	dac1.initialize();
	dac1.enableChannel1();
	dac1.enableInterrupt();
*/

// 사용 방법
//		- setOutputChannel1() 또는 setOutputChannel2() 함수를 사용하여 DAC 출력 값을 설정한다.

// ##### 사용 예시 #####
/*
	dac1.setOutputChannel1(123);
*/

