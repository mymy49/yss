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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

// STM32F767xx 계열에서 유효한 설정이 담긴 참고용 파일이다.
// 해당 파일을 사용자 프로젝트의 include 경로에 복사하고 config.h로 변경한다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
#define HSE_CLOCK_FREQ 12000000

// ####################### lmalloc 설정 #######################
// SDRAM을 이용한 동적할당 메모리의 사용 여부(true, false)
#define YSS_L_HEAP_USE			false

// SDRAM의 시작 주소 설정
// STM32F7 (Bank1 - 0x60000000, Bank2 - 0x70000000)
#define YSS_SDRAM_ADDR			0x60000000

// SDRAM의 총 메모리 용량 설정
#define YSS_L_HEAP_SIZE			(8 * 1024 * 1024)

// lmalloc의	기본 할당 단위
#define YSS_L_HEAP_CLUSTER_SIZE	(256)

// lmalloc의	최대 할당 개수
#define YSS_L_MAX_NUM_OF_MALLOC	1024

// ####################### 스케줄러 설정 #######################
// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER			timer6

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			20

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI							true

// Touch Event Enable (true, false)
#define USE_EVENT						false

// Stack Size of Touch Event handler (Byte)
#define TOUCH_EVENT_HANDLER_STACK_SIZE	4096

// Depth of Touch Event Memory ( 32 ~ 256 )
#define TOUCH_EVENT_MEMORY_DEPTH		128

// Frame Buffer of LCD output (Rgb565, Rgb888, Argb1555)
#define YSS_FRAME_BUFFER				Rgb565

// Frame Buffer of GUI Frame (Rgb565, Rgb888, Argb1555)
#define YSS_GUI_FRAME_BUFFER			Rgb565

// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY 9

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 주석 처리를 해제 한다.
//
// 주의 
// 1. TIMER와 PWM은 실제 동일한 장치지만 OS 구조상 별도의 장치로 표현한다. 그러므로 동일한 번호의 PWM과 TIMER는 동시에 활성화 되지 못한다.

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
//#define I2C4_ENABLE

// Quad SPI 활성화
//#define QUADSPI_ENABLE

// SDMMC 활성화
//#define SDMMC_ENABLE

// SDRAM 활성화
//#define SDRAM_ENABLE

// LTDC 활성화
//#define LTDC_ENABLE

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

#endif