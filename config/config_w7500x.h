/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */


// WIZnet iMCU W7500x에서 유효한 설정이 담긴 참고용 파일입니다.
// 해당 파일을 사용자 프로젝트의 include 경로(app/inc)에 복사하고 config.h로 변경해서 사용하는 것을 추천합니다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
// 아래 HSE_CLOCK_FREQ가 정의 되어 있으면 HSE 클럭을 소스로 PLL 설정이 이뤄집니다.
// 정의되어 있지 않으면 HSI 클럭을 소스로 PLL 설정이 이뤄집니다.
// OSC 클럭은 8MHz의 배수를 권장합니다.
//#define OSC_CLOCK_FREQ		8000000

#if defined(OSC_CLOCK_FREQ) && (48000000 % OSC_CLOCK_FREQ)
#error "아래 사항을 따르세요."
// 1. /yss/src/targets/wiznet/msp/msp_w7500x.cpp 파일에서 initializeSystem() 함수를 사용자의 소스코드 파일로 복사합니다.
// 2. 사용자 코드로 복사한 initializeSystem() 함수에서 __WEAK 예약어를 없앱니다.
// 3. W7500의 데이터시트를 보고 요구에 맞는 클럭 설정을 합니다.
// 4. 본 에러 코드는 주석처리를 해서 error가 발생하지 않도록 합니다.
#endif

// ####################### 스케줄러 설정 #######################

// runtime 함수를 지원할 PWM 장치 설정 (RUNTIME_PWM0 ~ RUNTIME_PWM7)
#define YSS_TIMER			RUNTIME_PWM0

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			16

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ####################### DMA 복사 설정 #######################
// DMA를 사용하는 copy() 함수가 사용할 DMA를 지정한다. (dmaChannel1 ~ dmaChannel6)
// dmaChannel5, dmaChannel6의 사용을 권장합니다.
#define COPY_DMA			dmaChannel5

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI				false

// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY		0

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 false -> true로 변경하여 활성화합니다.
//
// 주의 
// 1. TIMER, PWM, CAPTURE는 실제 동일한 장치지만 OS 구조상 별도의 장치로 표현합니다. 그러므로 동일한 번호의 TIMER, PWM, CAPTURE는 동시에 활성화 되지 못합니다.

// PWM 활성화
#define PWM0_ENABLE			false
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false
#define PWM4_ENABLE			false
#define PWM5_ENABLE			false
#define PWM6_ENABLE			false
#define PWM7_ENABLE			false

// TIMER 활성화
#define TIMER0_ENABLE		false
#define TIMER1_ENABLE		false
#define TIMER2_ENABLE		false
#define TIMER3_ENABLE		false
#define TIMER4_ENABLE		false
#define TIMER5_ENABLE		false
#define TIMER6_ENABLE		false
#define TIMER7_ENABLE		false

// UART 활성화
// 현재 W7500x에서는 UART2는 지원하지 않습니다.
#define USART1_ENABLE		false	
#define USART2_ENABLE		false



#endif

