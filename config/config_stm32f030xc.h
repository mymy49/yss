////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

// STM32F030xC 시리즈에서 유효한 설정이 담긴 참고용 파일이다.
// 해당 파일을 사용자 프로젝트의 include 경로에 복사하고 config.h로 변경한다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

#define HSE_CLOCK_FREQ		12000000

#define YSS_USE_DEFAULT_MSP	true

// ####################### 스케줄러 설정 #######################

// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER			timer6

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			16

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
// ADC 활성화
//#define ADC1_ENABLE

// UART 활성화
//#define UART1_ENABLE
//#define UART1_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

//#define UART2_ENABLE
//#define UART2_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

//#define UART3_ENABLE
//#define UART3_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

//#define UART4_ENABLE
//#define UART4_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

//#define UART5_ENABLE
//#define UART5_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

//#define UART6_ENABLE
//#define UART6_DMA_TX	DMA_CH2	// DMA_CH2, DMA_CH4 가능

// TIMER 활성화
//#define TIM1_ENABLE
//#define TIM3_ENABLE
#define TIM6_ENABLE
//#define TIM7_ENABLE
//#define TIM14_ENABLE

// I2C 활성화
// I2C의 클럭 설정은 오차를 갖고 있기 때문에 정확한 클럭을 요구할 경우 수정이 필요하다.
//#define I2C1_ENABLE	// DMA_CH2(TX), DMA_CH3(RX) 고정
//#define I2C2_ENABLE	// DMA_CH4(TX), DMA_CH5(RX) 고정

// SPI 활성화
//#define SPI1_ENABLE	// DMA_CH3(TX), DMA_CH2(RX) 고정
//#define SPI2_ENABLE	// DMA_CH5(TX), DMA_CH4(RX) 고정

#endif