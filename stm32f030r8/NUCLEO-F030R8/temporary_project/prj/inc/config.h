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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

#define HSE_CLOCK_FREQ 8

// ####################### 스케줄러 설정 #######################

// 내부 ms 를 만들 시계의 타이머 설정 (timer1 ~ timer14)
#define YSS_TIMER timer3

// ###################### 주변 장치 활성화 ######################
// UART 활성화
//#define UART1_ENABLE
#define UART2_ENABLE
//#define UART3_ENABLE
//#define UART4_ENABLE
//#define UART5_ENABLE
//#define UART6_ENABLE
//#define UART7_ENABLE
//#define UART8_ENABLE

//// DMA 활성화
//#define DMA1_STREAM0_ENABLE
//#define DMA1_STREAM1_ENABLE
//#define DMA1_STREAM2_ENABLE
//#define DMA1_STREAM3_ENABLE
//#define DMA1_STREAM4_ENABLE
//#define DMA1_STREAM5_ENABLE
//#define DMA1_STREAM6_ENABLE
//#define DMA1_STREAM7_ENABLE

//#define DMA2_STREAM0_ENABLE
//#define DMA2_STREAM1_ENABLE
//#define DMA2_STREAM2_ENABLE
//#define DMA2_STREAM3_ENABLE
//#define DMA2_STREAM4_ENABLE
//#define DMA2_STREAM5_ENABLE
//#define DMA2_STREAM6_ENABLE
//#define DMA2_STREAM7_ENABLE

//// TIMER 활성화
//#define TIM1_ENABLE
//#define TIM2_ENABLE
#define TIM3_ENABLE
//#define TIM4_ENABLE
//#define TIM5_ENABLE
//#define TIM6_ENABLE
//#define TIM7_ENABLE
//#define TIM8_ENABLE
//#define TIM9_ENABLE
//#define TIM10_ENABLE
//#define TIM11_ENABLE
//#define TIM12_ENABLE
//#define TIM13_ENABLE
//#define TIM14_ENABLE

//// I2C 활성화
#define I2C1_ENABLE
//#define I2C2_ENABLE
//#define I2C3_ENABLE
//#define I2C4_ENABLE

//// Quad SPI 활성화
//#define QUADSPI_ENABLE

//// SDMMC 활성화
//#define SDMMC_ENABLE

//// SDRAM 활성화
//#define SDRAM_ENABLE

//// LTDC 활성화
//#define LTDC_ENABLE

//// SPI 활성화
//#define SPI1_ENABLE
//#define SPI2_ENABLE
//#define SPI3_ENABLE
//#define SPI4_ENABLE
//#define SPI5_ENABLE
//#define SPI6_ENABLE

//// CAN 활성화
//#define CAN1_ENABLE
//#define CAN2_ENABLE

//// SPI 활성화
//#define SPI1_ENABLE
//#define SPI2_ENABLE
//#define SPI3_ENABLE
//#define SPI4_ENABLE
//#define SPI5_ENABLE
//#define SPI6_ENABLE

//// LTDC 활성화
//#define LTDC_ENABLE

//// ADC 활성화
//#define ADC1_ENABLE
//#define ADC2_ENABLE
//#define ADC3_ENABLE

//// DAC 활성화
//#define DAC_ENABLE

//// RTC 활성화
//#define RTC_ENABLE

#endif