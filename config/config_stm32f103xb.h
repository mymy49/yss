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

// STM32F103xb 계열에서 유효한 설정이 담긴 참고용 파일이다.
// 해당 파일을 사용자 프로젝트의 include 경로에 복사하고 config.h로 변경한다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
#define HSE_CLOCK_FREQ		8000000

// ####################### 스케줄러 설정 #######################

// runtime 함수를 지원할 PWM 장치 설정 (RUNTIME_TIM1 ~ RUNTIME_TIM4)
#define YSS_TIMER			RUNTIME_TIM4

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
// 활성화 시킬 장치에 대해 false -> true로 변경하여 활성화 한다.
//
// 주의 
// 1. TIMER, PWM, CAPTURE는 실제 동일한 장치지만 OS 구조상 별도의 장치로 표현한다. 그러므로 동일한 번호의 TIMER, PWM, CAPTURE는 동시에 활성화 되지 못한다.

// ADC 활성화
#define ADC1_ENABLE			false
#define ADC2_ENABLE			false

// CAN 활성화
#define CAN1_ENABLE			false

// CAPTURE 활성화
#define CAPTURE1_ENABLE		false
#define CAPTURE2_ENABLE		false
#define CAPTURE3_ENABLE		false
#define CAPTURE4_ENABLE		false

// CRC32 활성화
#define CRC32_ENABLE		false

// I2C 활성화
#define I2C1_ENABLE			false
#define I2C2_ENABLE			false

// PWM 활성화
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false
#define PWM4_ENABLE			false

// SPI 활성화
#define SPI1_ENABLE			false
#define SPI2_ENABLE			false
#define SPI3_ENABLE			false

// TIMER 활성화
#define TIM1_ENABLE			false
#define TIM2_ENABLE			false
#define TIM3_ENABLE			false
#define TIM4_ENABLE			true

// UART 활성화
#define USART1_ENABLE		false
#define USART2_ENABLE		false
#define USART3_ENABLE		false

#endif

