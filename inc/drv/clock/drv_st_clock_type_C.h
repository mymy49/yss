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


#ifndef	YSS_DRV_CLOCK_ST_TYPE_C__H_
#define	YSS_DRV_CLOCK_ST_TYPE_C__H_

#if	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <yss/mcu.h>
#include <config.h>
#include "drv_st_clock_type_C_ec.h"
#include "drv_st_clock_type_C_define.h"
#include "drv_st_clock_type_C_config.h"

namespace drv
{
	class Mainpll
	{
	public:
		bool enable(unsigned char src, unsigned long vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
		unsigned int getFreq(void);
	};

	class Saipll
	{
	public:
		bool enable(unsigned long vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
		unsigned int getLcdFreq(void);
		unsigned int getSaiFreq(void);
	};

	class Peripheral
	{
	public:

// ################################### AHB1ENR 시작 ########################################
#if	defined(GPIOA)
		void setGpioAEn(bool en);
        void resetGpioA(void);
#endif
#if	defined(GPIOB)
		void setGpioBEn(bool en);
        void resetGpioB(void);
#endif
#if	defined(GPIOC)
		void setGpioCEn(bool en);
        void resetGpioC(void);
#endif
#if	defined(GPIOD)
		void setGpioDEn(bool en);
        void resetGpioD(void);
#endif
#if	defined(GPIOE)
		void setGpioEEn(bool en);
        void resetGpioE(void);
#endif
#if	defined(GPIOF)
		void setGpioFEn(bool en);
        void resetGpioF(void);
#endif
#if	defined(GPIOG)
		void setGpioGEn(bool en);
        void resetGpioG(void);
#endif
#if	defined(GPIOH)
		void setGpioHEn(bool en);
        void resetGpioH(void);
#endif
#if	defined(GPIOI)
		void setGpioIEn(bool en);
        void resetGpioI(void);
#endif
#if	defined(GPIOJ)
		void setGpioJEn(bool en);
        void resetGpioJ(void);
#endif
#if	defined(GPIOK)
		void setGpioKEn(bool en);
        void resetGpioK(void);
#endif
#if defined(CRC)
		void setCrcEn(bool en);
        void resetCrc(void);
#endif
#if defined(BKPSRAM_BASE)
		void setBackupSramEn(bool en);
#endif
#if defined(CCMDATARAM_BASE)
		void setCcmRamEn(bool en);
#endif

#if defined(DMA1)
		void setDmaEn(bool en);
		void resetDma(void);
#endif

#if defined(DMA2D)
		void setDma2d(bool en);
		void resetDma2d(void);
#endif

#if defined(ETH)
		void setEthernetMacEn(bool en);
		void setEthernetRxEn(bool en);
		void setEthernetTxEn(bool en);
		void setEthernetPtpEn(bool en);
		void resetEthernetMac(void);
#endif
#if defined(USB_OTG_HS)
		void setUsbdHsEn(bool en);
		void setUsbdHsUlpiEn(bool en);
		void resetUsbHs(void);
#endif

// ################################### AHB1ENR 끝 ########################################



// ################################### AHB2ENR 시작 ########################################

#if defined(DCMI)
		void setDcmiEn(bool en);
		void resetDcmi(void);
#endif

#if defined(CRYP)
		void setCrypEn(bool en);
		void resetCryp(void);
#endif

#if defined(HASH)
		void setHashEn(bool en);
		void resetHash(void);
#endif

#if defined(RNG)
		void setRngEn(bool en);
		void resetRng(void);
#endif

#if defined(USB_OTG_FS)
		void setUsbdFsEn(bool en);
		void resetUsbFs(void);
#endif

// ################################### AHB2ENR 끝 ########################################



// ################################### AHB3ENR 시작 ########################################

#if defined(FMC_Bank1)
		void setFmcEn(bool en);
		void resetFmc(void);
#endif

// ################################### AHB3ENR 끝 ########################################



// ################################### APB1ENR 시작 ########################################

		unsigned int getTimerApb1ClkFreq(void);

#if defined(TIM2)
		void setTimer2En(bool en);
		void resetTimer2(void);
#endif

#if defined(TIM3)
		void setTimer3En(bool en);
		void resetTimer3(void);
#endif

#if defined(TIM4)
		void setTimer4En(bool en);
		void resetTimer4(void);
#endif

#if defined(TIM5)
		void setTimer5En(bool en);
		void resetTimer5(void);
#endif

#if defined(TIM6)
		void setTimer6En(bool en);
		void resetTimer6(void);
#endif

#if defined(TIM7)
		void setTimer7En(bool en);
		void resetTimer7(void);
#endif

#if defined(TIM12)
		void setTimer12En(bool en);
		void resetTimer12(void);
#endif

#if defined(TIM13)
		void setTimer13En(bool en);
		void resetTimer13(void);
#endif

#if defined(TIM14)
		void setTimer14En(bool en);
		void resetTimer14(void);
#endif

#if defined(WWDG)
		void setWindowWatchdogEn(bool en);
		void resetWindowWatchdog(void);
#endif

#if defined(SPI2)
		void setSpi2En(bool en);
		void resetSpi2(void);
#endif

#if defined(SPI3)
		void setSpi3En(bool en);
		void resetSpi3(void);
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
#endif

#if defined(I2C2)
		void setI2c2En(bool en);
		void resetI2c2(void);
#endif

#if defined(I2C3)
		void setI2c3En(bool en);
		void resetI2c3(void);
#endif

#if defined(CAN1)
		void setCan1En(bool en);
		void resetCan1(void);
#endif

#if defined(CAN2)
		void setCan2En(bool en);
		void resetCan2(void);
#endif

#if defined(PWR)
		void setPwrEn(bool en);
		void resetPwr(void);
#endif

#if defined(DAC1)
		void setDacEn(bool en);
		void resetDac(void);
#endif

#if defined(UART7)
		void setUart7En(bool en);
		void resetUart7(void);
#endif

#if defined(UART8)
		void setUart8En(bool en);
		void resetUart8(void);
#endif

// ################################### APB1ENR 끝 ########################################



// ################################### APB2ENR 시작 ########################################

		unsigned int getTimerApb2ClkFreq(void);

#if defined(TIM1)
		void setTimer1En(bool en);
		void resetTimer1(void);
#endif

#if defined(TIM8)
		void setTimer8En(bool en);
		void resetTimer8(void);
#endif

#if defined(USART1)
		void setUart1En(bool en);
		void resetUart1(void);
#endif

#if defined(USART6)
		void setUart6En(bool en);
		void resetUart6(void);
#endif

#if defined(ADC1)
		void setAdc1En(bool en);
		void resetAdc(void);
#endif

#if defined(ADC2)
		void setAdc2En(bool en);
#endif

#if defined(ADC3)
		void setAdc3En(bool en);
#endif

#if defined(SDIO)
	void setSdioEn(bool en);
	void resetSdio(void);
#endif

#if defined(SPI1)
		void setSpi1En(bool en);
		void resetSpi1(void);
#endif

#if defined(SPI4)
		void setSpi4En(bool en);
		void resetSpi4(void);
#endif

#if defined(SYSCFG)
		void setSyscfgEn(bool en);
		void resetSyscfg(void);
#endif

#if defined(TIM9)
		void setTimer9En(bool en);
		void resetTimer9(void);
#endif

#if defined(TIM10)
		void setTimer10En(bool en);
		void resetTimer10(void);
#endif

#if defined(TIM11)
		void setTimer11En(bool en);
		void resetTimer11(void);
#endif

#if defined(SPI5)
		void setSpi5En(bool en);
		void resetSpi5(void);
#endif

#if defined(SPI6)
		void setSpi6En(bool en);
		void resetSpi6(void);
#endif

#if defined(SAI1)
		void setSai1En(bool en);
		void resetSai1(void);
#endif

#if defined(LTDC)
		void setLtdcEn(bool en);
		void resetLtdc(void);
#endif

// ################################### APB1ENR 끝 ########################################
	};

	class Clock
	{
	public :
		bool enableHse(unsigned char hseMhz);
		bool enableLsi(bool en = true);
		bool enableLse(bool en = true);
		bool setUsbClkSrc(unsigned char src);
		bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc);
		unsigned long getSysClkFreq(void);
		unsigned long getApb1ClkFreq(void);
		unsigned long getApb2ClkFreq(void);
		unsigned long getTimerApb1ClkFreq(void);
		unsigned long getTimerApb2ClkFreq(void);
		Mainpll pll;
		Saipll saipll;
		Peripheral peripheral;
	};
}

#if	defined(RCC)
extern drv::Clock clock;
#endif

#endif

#endif
