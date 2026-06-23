/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// Nuvoton M251 시리즈에서 유효한 설정이 담긴 참고용 파일입니다.
// 해당 파일을 사용자 프로젝트의 include 경로(app/inc)에 복사하고 config.h로 변경해서 사용하는 것을 추천합니다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
// 아래 HSE_CLOCK_FREQ가 정의 되어 있으면 HSE 클럭을 소스로 PLL 설정이 이뤄집니다.
// 정의되어 있지 않으면 HSI 클럭을 소스로 PLL 설정이 이뤄집니다.
// 크리스탈은 반드시 4 MHz의 배수로 사용해야 합니다.
//#define HSE_CLOCK_FREQ 12000000

// ####################### 스케줄러 설정 #######################
// runtime 함수를 지원할 TIMER 장치 설정 (RUNTIME_TIMER0, 1, 2, 3)
#define YSS_TIMER			RUNTIME_TIMER0

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			16

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI				false

// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY		0

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 false -> true로 변경하여 활성화 합니다.
//
// 주의 

// BPWM 활성화
#define BPWM0_ENABLE		false
#define BPWM1_ENABLE		false

// I2C 활성화
#define I2C0_ENABLE			false
#define I2C1_ENABLE			false

// I2S 활성화
#define I2S0_ENABLE			false

// PWM 활성화
#define PWM0_ENABLE			false
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false

// SPI 활성화
#define SPI0_ENABLE			false

// TIMER 활성화
#define TIMER0_ENABLE		false
#define TIMER1_ENABLE		false
#define TIMER2_ENABLE		false
#define TIMER3_ENABLE		false

// UART 활성화
#define UART0_ENABLE		false
#define UART1_ENABLE		false
#define UART2_ENABLE		false

#endif

