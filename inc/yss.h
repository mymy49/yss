/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SYSTEM__H_
#define YSS_SYSTEM__H_

#include "yss/gui.h"
#include "yss/instance.h"
#include "yss/thread.h"
#include "yss/Thread.h"
#include "yss/Trigger.h"
#include "std_ext/malloc.h"
#include "drv/mcu.h"

#define YSS_VERSION		2404

/*
	##### 문맥전환을 유발하는 함수 #####
	1. thread::yield() 함수는 기본적으로 문맥전환을 유발합니다.
	2. SPI, I2C, I2S 등의 주변장치의 데이터 전송 관련 함수는 내부에서 유휴 시간에 thread::yield() 함수를 호출합니다.
	3. Mutex::lock(), Mutex::unlock() 함수는 내부에서 유휴 시간에 thread::yield() 함수를 호출합니다.
	4. 그외 함수가 내부에서 처리중에 유휴 시간마다 yield() 함수를 호출하는 함수.

	##### 이순신 OS에서 ISR과 Callback의 구분 #####
	1. ISR은 인터럽트 벡터에서 직접 호출합니다.
	2. ISR 내에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
	3. Callback은 일반 쓰레드 레벨에서 이벤트가 발생시 호출하는 경우 등록되는 함수 입니다.
	4. Callback 내에서는 문맥전환을 유발하는 모든 함수의 호출이 가능합니다.
	5. Callback은 해당 Callback을 호출하는 쓰레드의 Stack의 크기를 주의해서 지역 변수를 사용해야 합니다.
	6. ISR은 MSP에 할당된 Stack의 크기를 주의해서 지역 변수를 사용해야 합니다.
*/

class TftLcdDriver;

class Dma;

/*
	이순신 OS의 스케줄러, 뮤텍스와 MCU의 DMA, 외부 인터럽트 등을 활성화 합니다.
*/
void initializeYss(void);

/*
	프로젝트에서 사용하는 TFT LCD를 등록합니다.
*/
void setSystemTftLcd(TftLcdDriver &lcd);

/*
	프로젝트에서 사용하는 TFT LCD의 포인터를 얻는데 사용합니다.
	.
	@ return : 프로젝트에 등록된 TFT LCD의 포인터를 반환합니다.
*/
TftLcdDriver* getSystemTftLcd(void);

#if defined(YSS__DMA_ALLOCATION)
/*
	DMA를 점유할 수 있도록 할당 받습니다.
	현재 사용 목적은 특정 장치가 한번 할당 받으면 끝까지 사용하도록 하여	반납 기능이 없습니다.
	.
	@ return : 점유 가능한 DMA의 포인터를 반환합니다. 만약 유효한 DMA가 없을 경우 nullptr을 반환 합니다.
*/
Dma *allocateDma(void);
#endif

#if defined(DMA2D) && USE_EVENT == true
void setEvent(Position_t pos, uint8_t event);
#endif

#if USE_GUI == true && YSS_L_HEAP_USE == true
void setActiveFrame(Frame *obj);

void clearActiveFrame(void);
#endif

#endif
