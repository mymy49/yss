/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// STM32F429xx 계열에서 유효한 설정이 담긴 참고용 파일이다.
// 해당 파일을 사용자 프로젝트의 include 경로에 복사하고 config.h로 변경한다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
#define HSE_CLOCK_FREQ				8000000

// ####################### lmalloc 설정 #######################

// SDRAM을 이용한 동적할당 메모리의 사용 여부(true, false)
#define	YSS_L_HEAP_USE				true

// SDRAM의 시작 주소 설정
// STM32F4 (Bank1 - 0xC0000000, Bank2 - 0xD0000000)
#define	YSS_SDRAM_ADDR				0xD0000000

// SDRAM의 총 메모리 용량 설정
#define	YSS_L_HEAP_SIZE				(8 * 1024 * 1024)

// lmalloc의	기본 할당 단위
#define	YSS_L_HEAP_CLUSTER_SIZE		(256)

// lmalloc의	최대 할당 개수
#define	YSS_L_MAX_NUM_OF_MALLOC		1024

// ####################### 스케줄러 설정 #######################

// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER			timer6

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
#define NUM_OF_YSS_KEY		4

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 주석 처리를 해제 한다.
//
// 주의 
// 1. TIMER, PWM, CAPTURE는 실제 동일한 장치지만 OS 구조상 별도의 장치로 표현한다. 그러므로 동일한 번호의 TIMER, PWM, CAPTURE는 동시에 활성화 되지 못한다.

// UART 활성화
//#define UART1_ENABLE
//#define UART2_ENABLE
//#define UART3_ENABLE
//#define UART4_ENABLE
//#define UART5_ENABLE
//#define UART6_ENABLE
//#define UART7_ENABLE
//#define UART8_ENABLE

// PWM 활성화
//#define PWM1_ENABLE
//#define PWM2_ENABLE
//#define PWM3_ENABLE
//#define PWM4_ENABLE
//#define PWM5_ENABLE
//#define PWM6_ENABLE
//#define PWM7_ENABLE
//#define PWM8_ENABLE
//#define PWM9_ENABLE
//#define PWM10_ENABLE
//#define PWM11_ENABLE
//#define PWM12_ENABLE
//#define PWM13_ENABLE
//#define PWM14_ENABLE

// TIMER 활성화
//#define TIM1_ENABLE
//#define TIM2_ENABLE
//#define TIM3_ENABLE
//#define TIM4_ENABLE
//#define TIM5_ENABLE
#define TIM6_ENABLE
//#define TIM7_ENABLE
//#define TIM8_ENABLE
//#define TIM9_ENABLE
//#define TIM10_ENABLE
//#define TIM11_ENABLE
//#define TIM12_ENABLE
//#define TIM13_ENABLE
//#define TIM14_ENABLE

// I2C 활성화
//#define I2C1_ENABLE
//#define I2C2_ENABLE
//#define I2C3_ENABLE

// SPI 활성화
//#define SPI1_ENABLE
//#define SPI2_ENABLE
//#define SPI3_ENABLE
//#define SPI4_ENABLE
//#define SPI5_ENABLE
//#define SPI6_ENABLE

// CAN 활성화
//#define CAN1_ENABLE
//#define CAN2_ENABLE

// ADC 활성화
//#define ADC1_ENABLE
//#define ADC2_ENABLE
//#define ADC3_ENABLE

// DAC 활성화
//#define DAC_ENABLE

// I2S 활성화
//#define I2S2_ENABLE
//#define I2S3_ENABLE

// SAI 활성화
//#define SAI1_ENABLE

// SDRAM 활성화
//#define SDRAM_ENABLE

// DMA2D 활성화
//#define DMA2D_ENABLE

// LTDC 활성화
//#define LTDC_ENABLE

#endif