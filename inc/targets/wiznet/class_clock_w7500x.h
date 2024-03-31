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

#ifndef YSS_CLASS_CLOCK_W7500__H_
#define YSS_CLASS_CLOCK_W7500__H_

#include <yss/error.h>
#include <drv/mcu.h>
#include <yss/Mutex.h>
#include "define_w7500x.h"

class Clock : public Mutex
{
public:
	// 외부 HSE 크리스탈을 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t hseHz
	//		외부 크리스털의 주파수를 HZ 단위로 입력합니다.
	// useBypass = false
	//		입력이 크리스탈일 경우에는 false로 설정합니다.
	//		입력이 오실레이터일 경우나 클럭 소스를 직접 입력 받을 경우 bypass를 true로 설정합니다.
	error_t enableOsc(uint32_t hseHz) __attribute__((optimize("-O1")));
	
	// 내부 RC 오실레이터의 주파수를 얻습니다.
	// 
	// 반환
	//		RC 오실레이터의 주파수를 반환 합니다.
	uint32_t getRclkFrequency(void) __attribute__((optimize("-O1")));

	// 외부 오실레이터의 주파수를 얻습니다.
	// 
	// 반환
	//		외부 오실레이터의 주파수를 반환 합니다.
	uint32_t getOclkFrequency(void) __attribute__((optimize("-O1")));

	// PLL의 출력 주파수(MCLK)를 얻습니다.
	// 
	// 반환
	//		MCLK 주파수를 반환 합니다.
	uint32_t getMclkFrequency(void) __attribute__((optimize("-O1")));

	// System Clock 주파수(FCLK)를 얻습니다.
	// 
	// 반환
	//		FCLK 주파수를 반환 합니다.
	uint32_t getFclkFrequency(void) __attribute__((optimize("-O1")));

	// 
	typedef enum
	{
		PLL_SRC_RCLK = 0,
		PLL_SRC_OCLK,
	}pllSrc_t;

	error_t setPllFrequency(pllSrc_t src, uint8_t m, uint8_t n, uint8_t od) __attribute__((optimize("-O1")));

private:
};

#endif