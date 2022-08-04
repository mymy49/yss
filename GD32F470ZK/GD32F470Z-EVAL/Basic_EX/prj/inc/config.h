////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

#define HSE_CLOCK_FREQ					25000000

#define YSS_USE_DEFAULT_MSP				true

// ####################### lmalloc 설정 #######################

// SDRAM을 이용한 동적할당 메모리의 사용 여부(true, false)
#define	YSS_L_HEAP_USE					true

#if YSS_L_HEAP_USE == true
// SDRAM의 시작 주소 설정
// STM32F7 (Bank1 - 0x60000000, Bank2 - 0x70000000)
// STM32F4 (Bank1 - 0xC0000000, Bank2 - 0xD0000000)
#define	YSS_SDRAM_ADDR					0xC0000000

// SDRAM의 총 메모리 용량 설정
#define	YSS_L_HEAP_SIZE					(8 * 1024 * 1024)

// lmalloc의	기본 할당 단위
#define	YSS_L_HEAP_CLUSTER_SIZE			(256)

// lmalloc의	최대 할당 개수
#define	YSS_L_MAX_NUM_OF_MALLOC			1024
#endif

// ####################### 스케줄러 설정 #######################

// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER						timer1

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK				20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD						64

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI								true

// Touch Event Enable (true, false)
#define USE_EVENT							false

// Stack Size of Touch Event handler (Byte)
#define TOUCH_EVENT_HANDLER_STACK_SIZE		4096

// Depth of Touch Event Memory ( 32 ~ 256 )
#define TOUCH_EVENT_MEMORY_DEPTH			128

// Frame Buffer of LCD output (Rgb565, Rgb888, Argb1555)
#define YSS_FRAME_BUFFER					Rgb565

// Frame Buffer of GUI Frame (Rgb565, Rgb888, Argb1555)
#define YSS_GUI_FRAME_BUFFER				Rgb565



// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY						0



// ###################### 주변 장치 활성화 ######################
// UART 활성화
#define UART0_ENABLE
#define UART1_ENABLE
//#define UART2_ENABLE
//#define UART3_ENABLE
//#define UART4_ENABLE
//#define UART5_ENABLE
//#define UART6_ENABLE
//#define UART7_ENABLE
//#define UART8_ENABLE


// TIMER 활성화
#define TIM1_ENABLE
#define TIM2_ENABLE
#define TIM3_ENABLE
#define TIM4_ENABLE
#define TIM5_ENABLE
#define TIM6_ENABLE
#define TIM7_ENABLE
#define TIM8_ENABLE
#define TIM9_ENABLE
#define TIM10_ENABLE
#define TIM11_ENABLE
#define TIM12_ENABLE
#define TIM13_ENABLE
#define TIM14_ENABLE


// I2C 활성화
#define I2C1_ENABLE
#define I2C2_ENABLE
#define I2C3_ENABLE
#define I2C4_ENABLE


// Quad SPI 활성화
#define QUADSPI_ENABLE


// SDMMC 활성화
#define SDMMC_ENABLE


// SDRAM 활성화
#define SDRAM_ENABLE


// LTDC 활성화
#define LTDC_ENABLE

// SPI 활성화
#define SPI1_ENABLE
#define SPI2_ENABLE
#define SPI3_ENABLE
#define SPI4_ENABLE
#define SPI5_ENABLE
#define SPI6_ENABLE

// CAN 활성화
#define CAN1_ENABLE
#define CAN2_ENABLE

// SPI 활성화
#define SPI0_ENABLE
#define SPI1_ENABLE
#define SPI2_ENABLE
#define SPI3_ENABLE
#define SPI4_ENABLE
#define SPI5_ENABLE
#define SPI6_ENABLE

// LTDC 활성화
#define LTDC_ENABLE

// ADC 활성화
#define ADC1_ENABLE
#define ADC2_ENABLE
#define ADC3_ENABLE

// DAC 활성화
#define DAC1_ENABLE

// RTC 활성화
#define RTC_ENABLE

#endif