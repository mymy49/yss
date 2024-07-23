/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_DAC__H_
#define YSS_DRV_DAC__H_

#include "mcu.h"

#if defined (STM32F4) || defined(STM32F7)

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
	struct setup_t
	{
		YSS_DAC_Peri *dev;
	};

	Dac(const Drv::setup_t drvSetup, const setup_t setup);

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

