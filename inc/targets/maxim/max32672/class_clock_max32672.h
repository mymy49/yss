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

#ifndef YSS_CLASS_CLOCK_MAX32672__H_
#define YSS_CLASS_CLOCK_MAX32672__H_

#include <yss/error.h>

class Clock : public ClockBase
{
public:

	// External RF Oscillator(ERFO)를 활성화한다.
	// 
	// 반환
	//		error를 반환한다.
	// uint32_t clkFreq
	//		ERFO의 클록 주파수를 설정한다.
	// bool en
	//		활성화를 설정한다. (true - 활성화, false - 비활성화)
	error enableErfo(uint32_t clkFreq, bool en = true);

	// Internal Baud Rate Oscillator(IBRO)를 활성화한다.
	// 
	// 반환
	//		error를 반환한다.
	// bool en
	//		활성화를 설정한다. (true - 활성화, false - 비활성화)
	error enableIbro(bool en = true);

	// External Real-Time Clock Oscillator(ERTCO)를 활성화한다.
	// 32.768 kHz RTC 소스 클럭이다.
	// 
	// 반환
	//		error를 반환한다.
	// bool en
	//		활성화를 설정한다. (true - 활성화, false - 비활성화)
	error enableErtco(bool en = true);
	
	// SYS_OSC 클록 소스를 설정한다.
	// 클록 소스와 동시에 주변장치 클럭의 분주비 설정을 함께 한다.
	//
	// 반환
	//		error를 반환한다.
	// uint8_t sysclkSrc
	//		시스템 클럭(SYS_OSC) 소스를 설정한다. (define::clock::sysclk::src 중에서 설정한다.)
	// uint8_t sysclkDiv
	//		시스템 클럭(SYS_OSC)의 분주비를 설정한다. (define::clock::sysclk::div 중에서 설정한다.)
	error setSysclk(uint8_t sysclkSrc, uint8_t sysclkDiv);
	
	// 내부 LDO를 통해 코어에 공급되는 전압을 변경한다.
	// 전압이 낮아지면 소비 전류가 감소하고 최대 동작 주파수도 감소한다.
	// LDO의 출력이 바뀌면 IPO의 출력 주파수도 바뀐다.
	//
	// 반환
	//		error를 반환한다.
	//	uint8_t ovr
	//		내장 LDO의 출력 전압을 설정한다. (define::clock::ovr 중에서 설정한다.)
	error setOperatingVoltageRange(uint8_t ovr);

	// 캐시의 ID를 얻는다.
	//
	// 반환
	//		캐시의 ID를 반환한다.
	uint8_t getCacheId(void);

	// 캐시의 부품 번호를 얻는다.
	//
	// 반환
	//		캐시의 부품번호를 반환한다.
	uint8_t getCachePartNumber(void);

	// 캐시의 릴리즈 번호를 얻는다.
	//
	// 반환
	//		캐시의 릴리즈 번호를 반환한다.
	uint8_t getCacheReleaseNumber(void);
	
	// 캐시를 활성화/비활성화 시킨다.
	//
	//	bool en
	//		활성화를 설정한다. (true - 활성화, false - 비활성화)
	void enableCache(bool en = true);

	// 캐시를 무효화 한다.
	void invalidateCache(void);

	// 캐시 제어기가 주소 지정 가능한 메모리의 크기를 얻는다.
	// 
	// 반환
	//		캐시 제어기가 주소 지정 가능한 메모리의 크기를 kB 단위로 반환한다.
	uint32_t getCacheAddressAbleMemorySize(void);
	
	// 캐시 램의 크기를 얻는다.
	//
	// 반환
	//		캐시 램의 크기를 kB 단위로 반환한다.
	uint16_t getCacheSize(void);

	// Clock
	virtual uint32_t getCoreClockFrequency(void); // virtual 0

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	void initialize(void);

private:
	static uint32_t mErfoFrequency;
};

#endif