////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CLASS_CLOCK_EFM32PG22__H_
#define YSS_CLASS_CLOCK_EFM32PG22__H_

#include <yss/error.h>

class Clock : public ClockBase
{
public:
	enum DPLLREF
	{
		DISABLED = 0,
		HFXO,
		LFXO_,
		CLKIN0
	};

	enum SYSCLK_SRC
	{
		FSRCO_SRC = 1,
		HFRCODPLL_SRC,
		HFXO_SRC,
		CLKIN0_SRC
	};
	
	// Clock의 기본 값을 초기화 하는 함수이다.
	// SystemInit() 함수에서 반드시 한번 호출해야 한다.
	// MSP에서 기본적으로 호출을 해주고 있다.
	void initialize(void);
	
	// HFXO(외부 고속 크리스탈) 클럭을 활성화 시킨다.
	// HFXO 장치는 바이패스 콘덴서를 내부에서 생성한다. 바이패스 콘덴서의 용량 설정은 capacitorValue를 사용한다. 
	// 
	// 반환
	//		발생한 에러를 반환한다.
	// uint16_t capacitorValue
	//		바이패스 콘덴서의 용량 값을 설정한다. 용량은 
	error enableHfxo(uint16_t capacitorValue, uint16_t biasCurrent, uint32_t frequency);

	void enableApb0Clock(uint32_t position, bool enable = true);

	bool getApb0ClockEnabled(uint32_t position);

	uint32_t getApb0Frequency(void);

	void enableApb1Clock(uint32_t position, bool enable = true);

	bool getApb1ClockEnabled(uint32_t position);

	uint32_t getApb1Frequency(void);
	
	// DPLL을 활성화 한다.
	// 
	//	반환
	//		발생한 에러를 반환한다.
	// uint8_t dpllref
	//		enum DPLLREF에 정의된 항목에서 DPLL의 클럭 소스를 설정한다.
	// uint16_t n
	//		dpllref에서 선택된 클럭 소스에 대한 곱하기 배율을 설정한다. "n = 1" 일때는 1배율이다.
	//		설정가능한 배율은 300 ~ 4096이다.
	// uint16_t m
	//		dpllref에서 선택된 클럭 소스에 대한 분주 비율을 설정한다. "m = 1" 일때는 분주비는 1이다.
	//		설정가능한 분주 비율은 1 ~ 4096이다.
	error enableDpll(uint8_t dpllref, uint16_t n, uint16_t m);
	
	// SYSCLK 클럭 소스를 변경한다.
	// 변경하고자 하는 클럭 소스에 대해 미리 활성화가 되어 있어야 한다.
	//
	// 반환
	//		발생한 에러를 반환한다.
	// uint8_t sysclkSrc
	//		enum SYSCLK_SRC에 정의된 항목에서 클럭 소스를 설정한다.
	// uint8_t hclkDiv
	//		HCLK(코어 클럭)의 분주 비율을 설정한다. 설정된 값이 1 일때는 분주비는 1이다.
	//		설정 가능한 분주 비율은 1~16이다.
	// uint8_t pclkDiv
	//		PCLK(코어 클럭)의 분주 비율을 설정한다. 설정된 값이 1 일때는 분주비는 1이다.
	//		설정 가능한 분주 비율은 1~2이다. 이 설정은 HCLK를 대상으로 분주한다.
	error setSysclk(uint8_t sysclkSrc, uint8_t hclkDiv, uint8_t pclkDiv);
	
	// Clock
	virtual uint32_t getCoreClockFrequency(void); // virtual 0

private:
	uint32_t mHfxoFrequency;
};

#endif