/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F030XX__H_
#define YSS_DEFINE_STM32F030XX__H_

namespace define
{
	namespace gpio
	{
		namespace analog
		{
			enum
			{
				PA0_ADC_IN0 = 0,
				PA1_ADC_IN1 = 1,
				PA2_ADC_IN2 = 2,
				PA3_ADC_IN3 = 3,
				PA4_ADC_IN4 = 4,
				PA5_ADC_IN5 = 5,
				PA6_ADC_IN6 = 6,
				PA7_ADC_IN7 = 7,
				PB0_ADC_IN8 = 8,
				PB1_ADC_IN9 = 9,
				PC0_ADC_IN10 = 10,
				PC1_ADC_IN11 = 11,
				PC2_ADC_IN12 = 12,
				PC3_ADC_IN13 = 13,
			};
		}
	}
}

// 사용 가능한 DMA 채널 정의
#define DMA_CH1			0
#define DMA_CH2			1
#define DMA_CH3			2
#define DMA_CH4			3
#define DMA_CH5			4

#endif


