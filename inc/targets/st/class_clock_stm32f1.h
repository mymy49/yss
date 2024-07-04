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

#ifndef YSS_CLASS_CLOCK_STM32F1__H_
#define YSS_CLASS_CLOCK_STM32F1__H_

#include <yss/error.h>
#include <drv/mcu.h>
#include <yss/Mutex.h>

#if defined(STM32F1)

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
	error_t enableHse(uint32_t hseHz, bool useBypass = false);

	typedef enum
	{
		PLL_SRC_HSI_DIV2 = 0,
		PLL_SRC_HSE = 1
	}pllSrc_t;

	typedef enum
	{
		PLL_XTPRE_DIV1 = 0,
		PLL_XTPRE_DIV2 = 1
	}pllXtpre_t;

	// 주 PLL을 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// pllSrc_t src
	//		PLL 입력 클럭의 소스를 설정합니다. 
	// pllXtpre_t xtpre
	//		PLL 입력 클럭의 분주비를 설정합니다. 
	// uint8_t mul
	//		PLL 클럭의 증폭 배율을 설정합니다. (0 ~ 14) 
	error_t enableMainPll(pllSrc_t src, pllXtpre_t xtpre, uint8_t mul);

	// AHB 버스 장치의 클럭을 활성화 합니다.
	//
	// uint32_t position
	//		AHB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhbClock(uint32_t position, bool en = true);

	// SysClk의 클럭 소스와 AHB, APB의 분주비를 설정합니다.
	// 
	// 반환
	//		발생한 에러를 반환합니다.
	// uint8_t sysclkSrc
	//		SysClk의 클럭 소스를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::ahb"를 참고하세요. 
	// uint8_t ahbDiv
	//		AHB의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::ahbDiv"를 참고하세요. 
	// uint8_t apb1Div
	//		APB1의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::apbDiv"를 참고하세요. 
	// uint8_t apb2Div
	//		APB2의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::apbDiv"를 참고하세요. 
	// uint8_t vcc
	//		VCC 전압을 설정합니다. 전원 전압의 곱하기 10을 한 값이 사용됩니다.
	//		3.3V의 경우 33입니다.
	error_t setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2);

	// APB1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb1Clock(uint32_t position, bool en = true);

	// APB2 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB2 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB2 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb2Clock(uint32_t position, bool en = true);

	// AHB 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		AHB 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetAhb(uint32_t position);

	// APB1 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB1 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb1(uint32_t position);

	// APB2 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB2 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb2(uint32_t position);
	
	// SYSCLK 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		SYSCLK 클럭의 주파수를 반환합니다.
	uint32_t getSysclkFrequency(void);

	// PLL 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		PLL 클럭의 주파수를 반환합니다.
	uint32_t getMainPllFrequency(void);

	// AHB 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		AHB 클럭의 주파수를 반환합니다.
	uint32_t getAhbClockFrequency(void);

	// APB1 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		APB1 클럭의 주파수를 반환합니다.
	uint32_t getApb1ClockFrequency(void);

	// APB2 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		APB2 클럭의 주파수를 반환합니다.
	uint32_t getApb2ClockFrequency(void);

private:
};

#endif

#endif

