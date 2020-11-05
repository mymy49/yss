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

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>

namespace drv
{
	extern unsigned char gHseFreq __attribute__ ((section (".non_init")));
	extern unsigned int gPllPFreq __attribute__ ((section (".non_init")));
	extern unsigned int gPllQFreq __attribute__ ((section (".non_init")));
	extern unsigned int gPllRFreq __attribute__ ((section (".non_init")));
	extern unsigned int gSaiPllFreq __attribute__ ((section (".non_init")));
	extern unsigned int gLcdPllFreq __attribute__ ((section (".non_init")));

// ################################### AHB1ENR 시작 ########################################



// ################################### AHB1ENR 끝 ########################################



// ################################### AHB2ENR 시작 ########################################

#if defined(ADC1)
	void Peripheral::setAdc1En(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
	}
	
	void Peripheral::setAdc1ClkSrc(unsigned char src)
    {
		unsigned int ccipr;
		switch(src)
        {
		case define::clock::adc::src::NO_CLK :
		case define::clock::adc::src::PLL :
		case define::clock::adc::src::SYSCLK:
			ccipr = RCC->CCIPR & ~RCC_CCIPR_ADC12SEL_Msk;
			ccipr |= src << RCC_CCIPR_ADC12SEL_Pos;
            RCC->CCIPR = ccipr;
            break;
        }
    }
#endif
#if defined(ADC2)
	void Peripheral::setAdc2En(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
	}
	
	void Peripheral::setAdc2ClkSrc(unsigned char src)
    {
		unsigned int ccipr;
		switch(src)
        {
		case define::clock::adc::src::NO_CLK :
		case define::clock::adc::src::PLL :
		case define::clock::adc::src::SYSCLK:
			ccipr = RCC->CCIPR & ~RCC_CCIPR_ADC12SEL_Msk;
			ccipr |= src << RCC_CCIPR_ADC12SEL_Pos;
            RCC->CCIPR = ccipr;
            break;
        }
    }
#endif

// ################################### AHB2ENR 끝 ########################################

#if	defined(GPIOA)
	void Peripheral::setGpioAEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOAEN_Msk;
	}
#endif
#if	defined(GPIOB)
	void Peripheral::setGpioBEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOBEN_Msk;
	}
#endif
#if	defined(GPIOC)
	void Peripheral::setGpioCEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOCEN_Msk;
	}
#endif
#if	defined(GPIOD)
	void Peripheral::setGpioDEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIODEN_Msk;
	}
#endif
#if	defined(GPIOE)
	void Peripheral::setGpioEEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOEEN_Msk;
	}
#endif
#if	defined(GPIOF)
	void Peripheral::setGpioFEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOFEN_Msk;
	}
#endif
#if	defined(GPIOG)
	void Peripheral::setGpioGEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOGEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOGEN_Msk;
	}
#endif
#if defined(DAC1)
	void Peripheral::setDac1En(bool en)
	{
		if(en)
			RCC->AHB2ENR |=	RCC_AHB2ENR_DAC1EN_Msk;
		else
			RCC->AHB2ENR &=	~RCC_AHB2ENR_DAC1EN_Msk;
	}
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
	void Peripheral::setTimer2En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM2EN_Msk;
	}
#endif
#if defined(TIM3)
	void Peripheral::setTimer3En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM3EN_Msk;
	}
#endif
#if defined(TIM4)
	void Peripheral::setTimer4En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM4EN_Msk;
	}
#endif
#if defined(TIM6)
	void Peripheral::setTimer6En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM6EN_Msk;
	}
#endif
#if defined(TIM7)
	void Peripheral::setTimer7En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM7EN_Msk;
	}
#endif
#if defined(USART2)
	void Peripheral::setUart2En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART2EN_Msk;
	}
	void Peripheral::resetUart2(void)
	{

	}
#endif

#if defined(USART3)
	void Peripheral::setUart3En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART3EN_Msk;
	}
	void Peripheral::resetUart3(void)
	{

	}
#endif

#if defined(UART4)
	void Peripheral::setUart4En(bool en)
    {
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART4EN_Msk;
    }
	void Peripheral::resetUart4(void)
    {

	}
#endif

#if defined(UART5)
	void Peripheral::setUart5En(bool en)
    {
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_UART5EN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART5EN_Msk;
    }
	void Peripheral::resetUart5(void)
    {

    }
#endif
#if defined(I2C1)
		void Peripheral::setI2c1En(bool en)
		{
			if(en)
				RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_I2C1EN_Pos);
			else
				RCC->APB1ENR1 &= ~(1 << RCC_APB1ENR1_I2C1EN_Pos);
		}

		bool Peripheral::setI2c1ClkSrc(unsigned char src)
		{
			switch(src)
			{
			case define::clock::i2c::src::PCLK1 :
			case define::clock::i2c::src::SYSCLK :
			case define::clock::i2c::src::HSI16 :
				RCC->CCIPR &= ~RCC_CCIPR_I2C1SEL_Msk;
				RCC->CCIPR |= src <<= RCC_CCIPR_I2C1SEL_Pos;
				return true;
			default :
				return false;
			}
		}
#endif
#if defined(I2C2)
	void Peripheral::setI2c2En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_I2C2EN_Pos);
		else
			RCC->APB1ENR1 &= ~(1 << RCC_APB1ENR1_I2C2EN_Pos);
	}

	bool Peripheral::setI2c2ClkSrc(unsigned char src)
	{
		switch(src)
        {
		case define::clock::i2c::src::PCLK1 :
		case define::clock::i2c::src::SYSCLK :
		case define::clock::i2c::src::HSI16 :
			RCC->CCIPR &= ~RCC_CCIPR_I2C2SEL_Msk;
            RCC->CCIPR |= src <<= RCC_CCIPR_I2C2SEL_Pos;
            return true;
		default :
			return false;
        }
	}
#endif
#if defined(FDCAN1)
	void Peripheral::setCan1En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= RCC_APB1ENR1_FDCANEN_Msk;
		else
			RCC->APB1ENR1 &= ~RCC_APB1ENR1_FDCANEN_Msk;
	}

    unsigned int Peripheral::getCan1ClkFreq(void)
    {
		unsigned int src = (RCC->CCIPR & RCC_CCIPR_FDCANSEL_Msk) >> RCC_CCIPR_FDCANSEL_Pos;

        switch(src)
        {
		case 0 : // HSE
			return (unsigned int)gHseFreq*1000000;
		case 1 : // PLLQ
			return gPllQFreq;
		case 2 : // PCLK1
			return clock.getApb1ClkFreq();
		default :
			return 0;
        }
    }

	bool Peripheral::setCan1ClkSrc(unsigned char src)
    {
		if(src > 2)
			return false;
        unsigned int ccipr = RCC->CCIPR;

		ccipr &= ~RCC_CCIPR_FDCANSEL_Msk;
        ccipr |= src << RCC_CCIPR_FDCANSEL_Pos;
		RCC->CCIPR = ccipr;

        return true;
    }
#endif
#if defined(FDCAN2)
	void Peripheral::setCan2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= 1 << RCC_APB1ENR_CAN2EN_Pos;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN_Msk;
	}
#endif
#if defined(I2C3)
	void Peripheral::setI2c3En(bool en)
	{
		if(en)
			RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_I2C3EN_Pos);
		else
			RCC->APB1ENR1 &= ~(1 << RCC_APB1ENR1_I2C3EN_Pos);
	}

	bool Peripheral::setI2c3ClkSrc(unsigned char src)
	{
		switch(src)
        {
		case define::clock::i2c::src::PCLK1 :
		case define::clock::i2c::src::SYSCLK :
		case define::clock::i2c::src::HSI16 :
			RCC->CCIPR &= ~RCC_CCIPR_I2C3SEL_Msk;
            RCC->CCIPR |= src <<= RCC_CCIPR_I2C3SEL_Pos;
            return true;
		default :
			return false;
        }
	}
#endif

// ################################### APB1ENR1 끝 ########################################



// ################################### APB1ENR2 시작 ########################################



// ################################### APB1ENR2 끝 ########################################



// ################################### APB2ENR 시작 ########################################

#if defined(SYSCFG)
	void Peripheral::setSyscfgEn(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
	}
#endif
#if defined(TIM1)
	void Peripheral::setTimer1En(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_TIM1EN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN_Msk;
	}
#endif
#if defined(TIM8)
	void Peripheral::setTimer8En(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_TIM8EN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN_Msk;
	}
#endif
#if defined(USART1)
		void Peripheral::setUart1En(bool en)
        {
			if(en)
				RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;
			else
				RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_Msk;
        }
		void Peripheral::resetUart1(void)
        {

        }
#endif
#if defined(TIM15)
	void Peripheral::setTimer15En(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_TIM15EN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_TIM15EN_Msk;
	}
#endif
#if defined(TIM16)
	void Peripheral::setTimer16En(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_TIM16EN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_TIM16EN_Msk;
	}
#endif
#if defined(TIM17)
	void Peripheral::setTimer17En(bool en)
	{
		if(en)
			RCC->APB2ENR |= RCC_APB2ENR_TIM17EN_Msk;
		else
			RCC->APB2ENR &= ~RCC_APB2ENR_TIM17EN_Msk;
	}
#endif

// ################################### APB2ENR 끝 ########################################
}

#endif
