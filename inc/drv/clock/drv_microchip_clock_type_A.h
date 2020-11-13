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

#ifndef	YSS_DRV_CLOCK_MICROCHIP_TYPE_A__H_
#define	YSS_DRV_CLOCK_MICROCHIP_TYPE_A__H_

#if	defined (__SAML21E15A__) || defined (__SAML21E15B__) || defined (__SAML21E16A__) || defined (__SAML21E16B__) || \
	defined (__SAML21E17A__) || defined (__SAML21E17B__) || defined (__SAML21E18B__) || defined (__SAML21G16A__) || \
	defined (__SAML21G16B__) || defined (__SAML21G17A__) || defined (__SAML21G17B__) || defined (__SAML21G18A__) || \
	defined (__SAML21G18B__) || defined (__SAML21J16A__) || defined (__SAML21J16B__) || defined (__SAML21J17A__) || \
	defined (__SAML21J17B__) || defined (__SAML21J18A__) || defined (__SAML21J18B__)

#include <yss/mcu.h>
#include <config.h>
#include "drv_microchip_clock_type_A_ec.h"

//#include "drv_st_clock_type_A_define.h"
//#include "drv_st_clock_type_A_config.h"

namespace drv
{
/*

	class MainPll
	{
	public:
		bool enable(config::clock::Pll &config, bool en = true);
		unsigned long getFreq(void);
	};

	class SaiPll
	{
	public:
		bool enable(config::clock::Saipll &config, bool en = true);
	};
*/
	class Peripheral
	{
	public:
        bool setPeripheralClock(unsigned char num, unsigned char gen, bool en, bool lock = false);

#if defined(SERCOM0)
		void setSerCom0En(bool en);
#endif
#if defined(DMA1)
		void setDmaEn(bool en);
		void resetDma(void);
#endif

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
#if	defined(GPIOH)
		void setGpioHEn(bool en);
#endif
#if	defined(GPIOI)
		void setGpioIEn(bool en);
#endif
#if	defined(GPIOJ)
		void setGpioJEn(bool en);
#endif
#if	defined(GPIOK)
		void setGpioKEn(bool en);
#endif

#if defined(TIM1)
		void setTimer1En(bool en);
#endif
#if defined(TIM2)
		void setTimer2En(bool en);
#endif
#if defined(TIM3)
		void setTimer3En(bool en);
#endif
#if defined(TIM4)
		void setTimer4En(bool en);
#endif
#if defined(TIM5)
		void setTimer5En(bool en);
#endif
#if defined(TIM6)
		void setTimer6En(bool en);
#endif
#if defined(TIM7)
		void setTimer7En(bool en);
#endif
#if defined(TIM8)
		void setTimer8En(bool en);
#endif
#if defined(TIM9)
		void setTimer9En(bool en);
#endif
#if defined(TIM10)
		void setTimer10En(bool en);
#endif
#if defined(TIM11)
		void setTimer11En(bool en);
#endif
#if defined(TIM12)
		void setTimer12En(bool en);
#endif
#if defined(TIM13)
		void setTimer13En(bool en);
#endif
#if defined(TIM14)
		void setTimer14En(bool en);
#endif

#if defined(LTDC)
		void setLtdcEn(bool en);
#endif

#if defined(I2C1)
		void setI2c1En(bool en);
#endif
#if defined(I2C2)
		void setI2c2En(bool en);
#endif
#if defined(I2C3)
		void setI2c3En(bool en);
#endif
#if defined(I2C4)
		void setI2c4En(bool en);
#endif

#if defined(FMC_Bank1)
		void setFmcEn(bool en);
#endif

#if defined(SYSCFG)
		void setSyscfgEn(bool en);
#endif

#if defined(QUADSPI)
		void setQuadspi(bool en);
#endif

#if defined(USB_OTG_FS)
		void setUsbdFsEn(bool en);
#endif

#if defined(USB_OTG_HS)
		void setUsbdHsEn(bool en);
#endif

#if defined(USART1)
		void setUart1En(bool en);
#endif

#if defined(USART2)
		void setUart2En(bool en);
        void resetUart2(void);
#endif

#if defined(USART3)
		void setUart3En(bool en);
#endif

#if defined(UART4)
		void setUart4En(bool en);
#endif

#if defined(UART5)
		void setUart5En(bool en);
#endif

#if defined(USART6)
		void setUart6En(bool en);
#endif

#if defined(UART7)
		void setUart7En(bool en);
#endif

#if defined(UART8)
		void setUart8En(bool en);
#endif

#if defined(DMA2D)
		void setDma2d(bool en);
#endif

#if defined(SDMMC1)
		void setSdmmc(bool en);
#endif

#if defined(CAN1)
		void setCan(bool en);
#endif

	};

	class Clock
	{
	public :
		bool enableHse(unsigned char hseMhz);
		bool enableLse(void);
		bool setGenericClock(unsigned char num, bool en, unsigned short div, unsigned char src);
//		MainPll pll;
//		SaiPll saipll;
		Peripheral peripheral;
	};
}

extern drv::Clock clock;

#endif

#endif
