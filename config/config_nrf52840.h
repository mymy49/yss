/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// nRF52840에서 유효한 설정이 담긴 참고용 파일이다.
// 해당 파일을 사용자 프로젝트의 include 경로에 복사하고 config.h로 변경한다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
#define HSE_CLOCK_FREQ		32000000

// ####################### 스케줄러 설정 #######################
// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER			timer0

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			10

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI				true

// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY		1

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 주석 처리를 해제 한다.
//
// UART 활성화
//#define UART0_ENABLE
//#define UART1_ENABLE

// TIMER 활성화
#define TIM0_ENABLE
//#define TIM1_ENABLE
//#define TIM2_ENABLE
//#define TIM3_ENABLE
//#define TIM4_ENABLE

// RADIO 활성화
//#define RADIO_ENABLE

#endif

