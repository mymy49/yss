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

#ifndef YSS_DRV_CLOCK_PERIPHERALS__H_
#define YSS_DRV_CLOCK_PERIPHERALS__H_

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) || \
    defined(STM32F407xx) || defined(STM32F417xx) || \
    defined(STM32F427xx) || defined(STM32F437xx) || \
    defined(STM32F429xx) || defined(STM32F439xx)

#define YSS_DRV_CLOCK_ST_TYPE_A

#elif defined(STM32F100xB) || defined(STM32F100xE) ||                                               \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#define YSS_DRV_CLOCK_ST_TYPE_B

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#define YSS_DRV_CLOCK_ST_TYPE_D

#elif defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
    defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) || \
    defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) || \
    defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) || \
    defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#define YSS_DRV_CLOCK_MICROCHIP_TYPE_A

#endif

#include <yss/mcu.h>

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

#if defined(TC0)
    void setTimer0En(bool en);
    void resetTimer0(void);
#endif

#if defined(TIM1) || defined(TC1)
    void setTimer1En(bool en);
    void resetTimer1(void);
#endif

#if defined(TIM2) || defined(TC2)
    void setTimer2En(bool en);
    void resetTimer2(void);
#endif

#if defined(TIM3) || defined(TC3)
    void setTimer3En(bool en);
    void resetTimer3(void);
#endif

#if defined(TIM4) || defined(TC4)
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

#if defined(TIM8)
    void setTimer8En(bool en);
    void resetTimer8(void);
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

#if defined(TIM15)
    void setTimer15En(bool en);
    void resetTimer15(void);
#endif

#if defined(TIM16)
    void setTimer16En(bool en);
    void resetTimer16(void);
#endif

#if defined(TIM17)
    void setTimer17En(bool en);
    void resetTimer17(void);
#endif

#if defined(WWDG)
    void setWindowWatchdogEn(bool en);
    void resetWindowWatchdog(void);
#endif

#if defined(SPI1)
    void setSpi1En(bool en);
    void resetSpi1(void);
#endif

#if defined(SPI2)
    void setSpi2En(bool en);
    void resetSpi2(void);
#endif

#if defined(SPI3)
    void setSpi3En(bool en);
    void resetSpi3(void);
#endif

#if defined(SPI4)
    void setSpi4En(bool en);
    void resetSpi4(void);
#endif

#if defined(SPI5)
    void setSpi5En(bool en);
    void resetSpi5(void);
#endif

#if defined(SPI6)
    void setSpi6En(bool en);
    void resetSpi6(void);
#endif

#if defined(USART1)
    void setUart1En(bool en);
    void resetUart1(void);
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
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
	bool setI2c1ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C2)
    void setI2c2En(bool en);
    void resetI2c2(void);
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
	bool setI2c2ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C3)
    void setI2c3En(bool en);
    void resetI2c3(void);
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
	bool setI2c3ClkSrc(unsigned char src);
#endif
#endif

#if defined(I2C4)
    void setI2c4En(bool en);
    void resetI2c4(void);
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
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

#if defined(DAC1)
    void setDac1En(bool en);
    void resetDac1(void);
#endif

#if defined(DAC2)
    void setDac2En(bool en);
    void resetDac2(void);
#endif

#if defined(ADC1)
    void setAdc1En(bool en);
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    void resetAdc(void);
#else
    void resetAdc1(void);
#endif
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    void setAdc12ClkSrc(unsigned char src);
#endif
#endif

#if defined(ADC2)
    void setAdc2En(bool en);

#if defined(YSS_DRV_CLOCK_ST_TYPE_B)
    void resetAdc2(void);
#endif
#endif

#if defined(ADC3)
    void setAdc3En(bool en);
#endif

#if defined(SDIO)
    void setSdioEn(bool en);
    void resetSdio(void);
#endif

#if defined(SYSCFG)
    void setSyscfgEn(bool en);
    void resetSyscfg(void);
#endif

#if defined(SAI1)
    void setSai1En(bool en);
    void resetSai1(void);
#endif

#if defined(LTDC)
    void setLtdcEn(bool en);
    void resetLtdc(void);
#endif

#if defined(SDMMC1)
    void setSdmmcEn(bool en);
    void resetSdmmc(void);
#endif
};
}

#endif