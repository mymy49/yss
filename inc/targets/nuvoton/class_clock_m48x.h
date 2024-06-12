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

#ifndef YSS_CLASS_CLOCK_M48X__H_
#define YSS_CLASS_CLOCK_M48X__H_

#include <yss/error.h>
#include <drv/mcu.h>
#include <yss/Mutex.h>
#include "define_m48x.h"
#include <stdint.h>

class Clock : public Mutex
{
public:
	// External High Speed Crystal Oscilator를 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t hseHz
	//		외부 크리스털의 주파수를 HZ 단위로 입력합니다.
	// useBypass = false
	//		입력이 크리스탈일 경우에는 false로 설정합니다.
	//		입력이 오실레이터일 경우나 클럭 소스를 직접 입력 받을 경우 bypass를 true로 설정합니다.
	error_t enableHxt(uint32_t hseHz) __attribute__((optimize("-O1")));
	
	// Internal High speed Osilator의 주파수를 얻습니다.
	// 
	// 반환
	//		Hirc 오실레이터의 주파수를 반환 합니다.
	uint32_t getHircFrequency(void) __attribute__((optimize("-O1")));

	// External High Speed Crystal Oscilator의 주파수를 얻습니다.
	// 
	// 반환
	//		외부 오실레이터의 주파수를 반환 합니다.
	uint32_t getHxtFrequency(void) __attribute__((optimize("-O1")));

	// PLL의 주파수를 얻습니다.
	// 
	// 반환
	//		PLL의 주파수를 반환 합니다.
	uint32_t getPllFrequency(void) __attribute__((optimize("-O1")));

	// PLL 클럭 소스
	typedef enum
	{
		PLL_SRC_HXT = 0,
		PLL_SRC_HIRC,
	}pllSrc_t;
	
	// PLL을 활성화 합니다. 출력 주파수는 아래의 식과 같습니다.
	// FOUT = FIN x (2 x (fbdiv + 2)) / NO
	// 위 식에서 NO는 아래와 같이 outdiv의 값에 의해 결정 됩니다.
	// outdiv == 0, NO = 1
	// outdiv == 1 또는 outdiv == 2, NO = 2
	// outdiv == 3, NO = 4
	//
	// 반환
	//		에러를 반환합니다.
	// uint8_t indiv
	//		입력 클럭 분주기입니다. (0 ~ 63)
	// uint16_t fbdiv
	//		PLL 배수기입니다. (0 ~ 512)
	// uint8_t outdiv
	//		출력 클럭 분주기 입니다. (0~3)
	error_t enablePll(pllSrc_t src, uint8_t indiv, uint16_t fbdiv, uint8_t outdiv) __attribute__((optimize("-O1")));

	// HCLK 클럭 소스
	typedef enum
	{
		HCLK_SRC_HXT = 0,
		HCLK_SRC_LXT,
		HCLK_SRC_PLL,
		HCLK_SRC_LRIC,
		HCLK_SRC_HIRC,
	}hclkSrc_t;

	// HCLK의 클럭 소스를 선택합니다. 이 함수 내부에서 Flash의 Access Cycle 설정이 자동으로 이뤄집니다. 
	//
	// 반환
	//		에러를 반환합니다.
	// hclkSrc_t src
	//		HCLK의 클럭럭 소스를 설정합니다.
	// uint8_t hclkDiv
	//		HCLK의 분주비를 설정합니다. PLL이 소스일 경우 반드시 0으로 설정해야 합니다. 
	// uint8_t pclk0Div
	//		PCLK0의 분주비를 설정합니다. HCLK의 주파수로 부터 분주됩니다. 
	//		M483에서 주파수가 96MHz를 넘으면 안됩니다.
	// uint8_t pclk1Div
	//		PCLK1의 분주비를 설정합니다. HCLK의 주파수로 부터 분주됩니다.
	//		M483에서 주파수가 96MHz를 넘으면 안됩니다.
	error_t setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv, uint8_t pclk0Div, uint8_t pclk1Div) __attribute__((optimize("-O1")));



private:
};

#endif