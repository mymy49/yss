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
//	이전 주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 2020.04.26
//  주담당자 : 맨틀코어 (tttwwuu@naver.com) 2020.04.26 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////


#ifndef	YSS_DRV_CLOCK_ST_TYPE_D__H_
#define	YSS_DRV_CLOCK_ST_TYPE_D__H_

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

#include <yss/mcu.h>
#include "drv_st_clock_type_D_ec.h"
#include "drv_st_clock_type_D_define.h"
#include "drv_st_clock_type_D_config.h"

namespace drv
{
	class Mainpll
	{
	public:
		bool enable(unsigned char src, unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
		unsigned long getFreq(void);
        void setPEn(bool en);
        void setQEn(bool en);
        void setREn(bool en);
	};

	class Peripheral
	{
	public:
		unsigned long getTimerApb1ClkFreq(void);
		unsigned long getTimerApb2ClkFreq(void);

// ################################### AHB1ENR 시작 ########################################



// ################################### AHB1ENR 끝 ########################################



// ################################### AHB2ENR 시작 ########################################

#if defined(ADC1)
		void setAdc1En(bool en);
		void setAdc1ClkSrc(unsigned char src);
#endif
#if defined(ADC2)
		void setAdc2En(bool en);
		void setAdc2ClkSrc(unsigned char src);
#endif

// ################################### AHB2ENR 끝 ########################################

#if	defined(GPIOA)
		void setGpioAEn(bool en);
#endif
#if	defined(GPIOB)
		void setGpioBEn(bool en);
#endif
#if	defined(GPIOC)
		void setGpioCEn(bool en);
#endif
#if	defined(GPIOD)
		void setGpioDEn(bool en);
#endif
#if	defined(GPIOE)
		void setGpioEEn(bool en);
#endif
#if	defined(GPIOF)
		void setGpioFEn(bool en);
#endif
#if	defined(GPIOG)
		void setGpioGEn(bool en);
#endif
#if defined(DAC1)
		void setDac1En(bool en);
#endif
#if defined(DAC2)
		void setDac2En(bool en);
#endif
#if defined(DAC3)
		void setDac3En(bool en);
#endif
#if defined(DAC4)
		void setDac4En(bool en);
#endif

// ################################### AHB3ENR 시작 ########################################



// ################################### AHB3ENR 끝 ########################################



// ################################### APB1ENR1 시작 ########################################

#if defined(TIM2)
		void setTimer2En(bool en);
#endif
#if defined(TIM3)
		void setTimer3En(bool en);
#endif
#if defined(TIM4)
		void setTimer4En(bool en);
#endif
#if defined(TIM6)
		void setTimer6En(bool en);
#endif
#if defined(TIM7)
		void setTimer7En(bool en);
#endif
#if defined(USART2)
		void setUart2En(bool en);
		void resetUart2(void);
#endif

#if defined(USART3)
		void setUart3En(bool en);
		void resetUart3(void);
#endif

#if defined(UART4)
		void setUart4En(bool en);
		void resetUart4(void);
#endif

#if defined(UART5)
		void setUart5En(bool en);
		void resetUart5(void);
#endif
#if defined(I2C1)
		void setI2c1En(bool en);
		void resetI2c1(void);
		bool setI2c1ClkSrc(unsigned char src);
#endif
#if defined(I2C2)
		void setI2c2En(bool en);
		void resetI2c2(void);
		bool setI2c2ClkSrc(unsigned char src);
#endif
#if defined(FDCAN1)
		void setCan1En(bool en);
        unsigned int getCan1ClkFreq(void);
        bool setCan1ClkSrc(unsigned char src);
#endif
#if defined(FDCAN2)
		void setCan2En(bool en);
#endif
#if defined(I2C3)
		void setI2c3En(bool en);
		void resetI2c3(void);
		bool setI2c3ClkSrc(unsigned char src);
#endif

// ################################### APB1ENR1 끝 ########################################



// ################################### APB1ENR2 시작 ########################################



// ################################### APB1ENR2 끝 ########################################



// ################################### APB2ENR 시작 ########################################

#if defined(SYSCFG)
		void setSyscfgEn(bool en);
#endif
#if defined(TIM1)
		void setTimer1En(bool en);
#endif
#if defined(TIM8)
		void setTimer8En(bool en);
#endif
#if defined(USART1)
		void setUart1En(bool en);
		void resetUart1(void);
#endif
#if defined(TIM15)
		void setTimer15En(bool en);
#endif
#if defined(TIM16)
		void setTimer16En(bool en);
#endif
#if defined(TIM17)
		void setTimer17En(bool en);
#endif

// ################################### APB2ENR 끝 ########################################

/*
		void setLtdcEn(bool en);

#if defined(DMA1)
		void setDmaEn(bool en);
#endif


//		void setFmcEn(bool en);





#if defined(SPI1)
		void setSpi1En(bool en);
#endif

#if defined(SPI2)
		void setSpi2En(bool en);
#endif

#if defined(SPI3)
		void setSpi3En(bool en);
#endif

#if defined(SPI4)
		void setSpi4En(bool en);
#endif

#if defined(SPI5)
		void setSpi5En(bool en);
#endif

#if defined(SPI6)
		void setSpi6En(bool en);
#endif


		void setUart1En(bool en);
		void setUart2En(bool en);
		void setUart3En(bool en);
		void setUart4En(bool en);
		void setUart5En(bool en);
		void setUart6En(bool en);
		void setUart7En(bool en);
		void setUart8En(bool en);

		void setDma2d(bool en);

		void setUsbdFsEn(bool en);
		void setUsbdHsEn(bool en);

		void setQuadspi(bool en);
*/
	};

	class Clock
	{
	public :
		bool enableHse(unsigned char hseMhz);
        bool setVoltageScale(unsigned char range);
		unsigned char getVoltageScale(void);
        unsigned char getAhbPrescale(void);
        void setAhbPrescale(unsigned char ahb);
		bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc);
		
		unsigned int getSysClkFreq(void);
		unsigned int getApb1ClkFreq(void);
		unsigned int getApb2ClkFreq(void);
		unsigned int getTimerApb1ClkFreq(void);
		unsigned int getTimerApb2ClkFreq(void);

/*
		bool enableLsi(bool en = true);
		bool enableLse(bool en = true);
		bool setUsbClkSrc(unsigned char src);
		Saipll saipll;
*/
		Peripheral peripheral;
		Mainpll pll;
	};
}

#if	defined(RCC)
extern drv::Clock clock;
#endif

#endif

#endif
