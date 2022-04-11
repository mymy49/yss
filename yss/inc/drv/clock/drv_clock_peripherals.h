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

#ifndef YSS_DRV_CLOCK_PERIPHERALS__H_
#define YSS_DRV_CLOCK_PERIPHERALS__H_

#include <drv/peripheral.h>

namespace drv
{
class Peripheral
{
  public:
	unsigned int getTimerApb1ClkFreq(void);
	unsigned int getTimerApb2ClkFreq(void);

#if defined(GPIOA)
	void setGpioAEn(bool en);
	void resetGpioA(void);
#endif

#if defined(GPIOB)
	void setGpioBEn(bool en);
	void resetGpioB(void);
#endif

#if defined(GPIOC)
	void setGpioCEn(bool en);
	void resetGpioC(void);
#endif

#if defined(GPIOD)
	void setGpioDEn(bool en);
	void resetGpioD(void);
#endif
#if defined(GPIOE)
	void setGpioEEn(bool en);
	void resetGpioE(void);
#endif

#if defined(GPIOF)
	void setGpioFEn(bool en);
	void resetGpioF(void);
#endif

#if defined(GPIOG)
	void setGpioGEn(bool en);
	void resetGpioG(void);
#endif

#if defined(GPIOH)
	void setGpioHEn(bool en);
	void resetGpioH(void);
#endif

#if defined(GPIOI)
	void setGpioIEn(bool en);
	void resetGpioI(void);
#endif

#if defined(GPIOJ)
	void setGpioJEn(bool en);
	void resetGpioJ(void);
#endif

#if defined(GPIOK)
	void setGpioKEn(bool en);
	void resetGpioK(void);
#endif

#if defined(AFIO)
	void setAfioEn(bool en);
	void resetAfio(void);
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

#if defined(USB_OTG_FS)
	void setUsbdFsEn(bool en);
	void resetUsbFs(void);
#endif

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

#if defined(FMC_Bank1)
	void setFmcEn(bool en);
	void resetFmc(void);
#endif

#if defined(TC0) || defined(MXC_TMR0) 
	void setTimer0En(bool en);
	void resetTimer0(void);
#endif

#if defined(TIM1) || defined(TC1) || defined(MXC_TMR1) || defined(TIMER1)
	void setTimer1En(bool en);
	void resetTimer1(void);
#endif

#if defined(TIM2) || defined(TC2) || defined(MXC_TMR2) || defined(TIMER2)
	void setTimer2En(bool en);
	void resetTimer2(void);
#endif

#if defined(TIM3) || defined(TC3) || defined(TIMER3)
	void setTimer3En(bool en);
	void resetTimer3(void);
#endif

#if defined(TIM4) || defined(TC4) || defined(TIMER4)
	void setTimer4En(bool en);
	void resetTimer4(void);
#endif

#if defined(TIM5) || defined(TIMER5)
	void setTimer5En(bool en);
	void resetTimer5(void);
#endif

#if defined(TIM6) || defined(TIMER6)
	void setTimer6En(bool en);
	void resetTimer6(void);
#endif

#if defined(TIM7) || defined(TIMER7)
	void setTimer7En(bool en);
	void resetTimer7(void);
#endif

#if defined(TIM8) || defined(TIMER8)
	void setTimer8En(bool en);
	void resetTimer8(void);
#endif

#if defined(TIM9) || defined(TIMER9)
	void setTimer9En(bool en);
	void resetTimer9(void);
#endif

#if defined(TIM10) || defined(TIMER10)
	void setTimer10En(bool en);
	void resetTimer10(void);
#endif

#if defined(TIM11) || defined(TIMER11)
	void setTimer11En(bool en);
	void resetTimer11(void);
#endif

#if defined(TIM12) || defined(TIMER12)
	void setTimer12En(bool en);
	void resetTimer12(void);
#endif

#if defined(TIM13) || defined(TIMER13)
	void setTimer13En(bool en);
	void resetTimer13(void);
#endif

#if defined(TIM14) || defined(TIMER14)
	void setTimer14En(bool en);
	void resetTimer14(void);
#endif

#if defined(TIM15) || defined(TIMER15)
	void setTimer15En(bool en);
	void resetTimer15(void);
#endif

#if defined(TIM16) || defined(TIMER16)
	void setTimer16En(bool en);
	void resetTimer16(void);
#endif

#if defined(TIM17) || defined(TIMER17)
	void setTimer17En(bool en);
	void resetTimer17(void);
#endif

#if defined(WWDG)
	void setWindowWatchdogEn(bool en);
	void resetWindowWatchdog(void);
#endif


#if defined(SAI1)
	void setSai1En(bool en);
	void resetSai1(void);
#endif

#if defined(SAI2)
	void setSai2En(bool en);
	void resetSai2(void);
#endif


#if defined(SERCOM0)
	void setSpi0En(bool en);
	void resetSpi0(void);
#endif

#if defined(SPI1) || defined(SERCOM1)
	void setSpi1En(bool en);
	void resetSpi1(void);
#endif

#if defined(SPI2) || defined(SERCOM2)
	void setSpi2En(bool en);
	void resetSpi2(void);
#endif

#if defined(SPI3) || defined(SERCOM3)
	void setSpi3En(bool en);
	void resetSpi3(void);
#endif

#if defined(SPI4) || defined(SERCOM4)
	void setSpi4En(bool en);
	void resetSpi4(void);
#endif

#if defined(SPI5) || defined(SERCOM5)
	void setSpi5En(bool en);
	void resetSpi5(void);
#endif

#if defined(SPI6)
	void setSpi6En(bool en);
	void resetSpi6(void);
#endif

#if defined(SERCOM0) || defined(MXC_UART0)
	void setUart0En(bool en);
	void resetUart0(void);
#endif

#if defined(USART1) || defined(SERCOM1) || defined(MXC_UART1)
	void setUart1En(bool en);
	void resetUart1(void);
#endif

#if defined(USART2) || defined(SERCOM2)
	void setUart2En(bool en);
	void resetUart2(void);
#endif

#if defined(USART3) || defined(SERCOM3)
	void setUart3En(bool en);
	void resetUart3(void);
#endif

#if defined(UART4) || defined(SERCOM4)
	void setUart4En(bool en);
	void resetUart4(void);
#endif

#if defined(UART5) || defined(SERCOM5)
	void setUart5En(bool en);
	void resetUart5(void);
#endif

#if defined(USART6)
	void setUart6En(bool en);
	void resetUart6(void);
#endif

#if defined(UART7)
	void setUart7En(bool en);
	void resetUart7(void);
#endif

#if defined(UART8)
	void setUart8En(bool en);
	void resetUart8(void);
#endif

#if defined(I2C1)
	void setI2c1En(bool en);
	void resetI2c1(void);
#if defined(STM32G4)
	bool setI2c1ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C2)
	void setI2c2En(bool en);
	void resetI2c2(void);
#if defined(STM32G4)
	bool setI2c2ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C3)
	void setI2c3En(bool en);
	void resetI2c3(void);
#if defined(STM32G4)
	bool setI2c3ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C4)
	void setI2c4En(bool en);
	void resetI2c4(void);
#if defined(STM32G4)
	bool setI2c4ClkSrc(unsigned char src);
#endif
#endif

#if defined(CAN1)
	void setCan1En(bool en);
	void resetCan1(void);
#endif

#if defined(CAN2)
	void setCan2En(bool en);
	void resetCan2(void);
#endif

#if defined(FDCAN1)
	void setCan1En(bool en);
	unsigned int getCan1ClkFreq(void);
	bool setCan1ClkSrc(unsigned char src);
	void resetCan1(void);
#endif

#if defined(FDCAN2)
	void setCan2En(bool en);
	unsigned int getCan2ClkFreq(void);
	bool setCan2ClkSrc(unsigned char src);
	void resetCan2(void);
#endif

#if defined(PWR)
	void setPwrEn(bool en);
	void resetPwr(void);
#endif

#if defined(DAC1) || defined(DAC)
	void setDac1En(bool en);
	void resetDac1(void);
#endif

#if defined(DAC2)
	void setDac2En(bool en);
	void resetDac2(void);
#endif

#if defined(ADC1) || defined(ADC)
	void setAdc1En(bool en);
	void resetAdc1(void);
#if defined(STM32G4)
	void setAdc12ClkSrc(unsigned char src);
#endif
#endif

#if defined(ADC2)
	void setAdc2En(bool en);
	void resetAdc2(void);
#endif

#if defined(ADC3)
	void setAdc3En(bool en);
	void resetAdc3(void);
#endif

#if defined(SDIO)
	void setSdioEn(bool en);
	void resetSdio(void);
#endif

#if defined(SYSCFG)
	void setSyscfgEn(bool en);
	void resetSyscfg(void);
#endif


#if defined(LTDC)
	void setLtdcEn(bool en);
	void resetLtdc(void);
#endif

#if defined(SDMMC1) || defined(SDIO)
	void setSdmmcEn(bool en);
	void resetSdmmc(void);
#endif

#if defined(RTC)
	void setRtcEn(bool en);
	void resetRtc(void);
#endif

#if defined(EIC)
	void setExtiEn(bool en);
	void resetExti(void);
#endif

#if defined(USB)
	void setUsb1En(bool en);
	void resetUsb1(void);
#endif
};
}

#endif