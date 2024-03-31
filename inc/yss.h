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

#ifndef YSS_SYSTEM__H_
#define YSS_SYSTEM__H_

#include "yss/gui.h"
#include "yss/instance.h"
#include "yss/thread.h"
#include "std_ext/malloc.h"

#define YSS_VERSION		2404

// ##### 문맥전환을 유발하는 함수 #####
// 1. thread::yield() 함수는 기본적으로 문맥전환을 유발합니다.
// 2. SPI, I2C, I2S 등의 주변장치의 데이터 전송 관련 함수는 내부에서 유휴 시간에 thread::yield() 함수를 호출합니다.
// 3. Mutex::lock(), Mutex::unlock() 함수는 내부에서 유휴 시간에 thread::yield() 함수를 호출합니다.
// 4. 그외 함수가 내부에서 처리중에 유휴 시간마다 yield() 함수를 호출하는 함수.

// ##### 이순신 OS에서 ISR과 Callback의 구분 #####
// 1. ISR은 인터럽트 벡터에서 직접 호출합니다.
// 2. ISR 내에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
// 3. Callback은 일반 쓰레드 레벨에서 이벤트가 발생시 호출하는 경우 등록되는 함수 입니다.
// 4. Callback 내에서는 문맥전환을 유발하는 모든 함수의 호출이 가능합니다.
// 5. Callback은 해당 Callback을 호출하는 쓰레드의 Stack의 크기를 주의해서 지역 변수를 사용해야 합니다.
// 6. ISR은 MSP에 할당된 Stack의 크기를 주의해서 지역 변수를 사용해야 합니다.


class TftLcdDriver;

// 이순신 OS의 스케줄러, 뮤텍스와 MCU의 DMA, 외부 인터럽트 등을 활성화 합니다.
void initializeYss(void);

// 프로젝트에서 사용하는 TFT LCD를 등록합니다.
void setSystemTftLcd(TftLcdDriver &lcd);

// 프로젝트에서 사용하는 TFT LCD의 포인터를 얻는데 사용합니다.
//
// 반환
//		프로젝트에 등록된 TFT LCD의 포인터
TftLcdDriver* getSystemTftLcd(void);

#if defined(DMA2D) && USE_EVENT == true
void setEvent(Position_t pos, uint8_t event);
#endif

#if USE_GUI == true && YSS_L_HEAP_USE == true
void setActiveFrame(Frame *obj);

void clearActiveFrame(void);
#endif

#endif
