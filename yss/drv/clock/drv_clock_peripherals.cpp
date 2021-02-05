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

#include <__cross_studio_io.h>

#include <drv/peripherals.h>

namespace drv
{
extern unsigned char gHseFreq __attribute__((section(".non_init")));
extern unsigned int gPllQFreq __attribute__((section(".non_init")));

#if defined(GPIOA)
void Peripheral::setGpioAEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPAEN_Msk;
#endif
}

void Peripheral::resetGpioA(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPARST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPARST_Msk;
#endif
}
#endif

#if defined(GPIOB)
void Peripheral::setGpioBEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPBEN_Msk;
#endif
}

void Peripheral::resetGpioB(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPBRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPBRST_Msk;
#endif
}
#endif

#if defined(GPIOC)
void Peripheral::setGpioCEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPCEN_Msk;
#endif
}

void Peripheral::resetGpioC(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPCRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPCRST_Msk;
#endif
}
#endif

#if defined(GPIOD)
void Peripheral::setGpioDEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPDEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPDEN_Msk;
#endif
}

void Peripheral::resetGpioD(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPDRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPDRST_Msk;
#endif
}
#endif

#if defined(GPIOE)
void Peripheral::setGpioEEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPEEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPEEN_Msk;
#endif
}

void Peripheral::resetGpioE(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPERST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPERST_Msk;
#endif
}
#endif

#if defined(GPIOF)
void Peripheral::setGpioFEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPFEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPFEN_Msk;
#endif
}

void Peripheral::resetGpioF(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOFRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPFRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPFRST_Msk;
#endif
}
#endif

#if defined(GPIOG)
void Peripheral::setGpioGEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPGEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPGEN_Msk;
#endif
}

void Peripheral::resetGpioG(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOGRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPGRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPGRST_Msk;
#endif
}
#endif

#if defined(GPIOH)
void Peripheral::setGpioHEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPHEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPHEN_Msk;
#endif
}

void Peripheral::resetGpioH(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPHRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPHRST_Msk;
#endif
}
#endif

#if defined(GPIOI)
void Peripheral::setGpioIEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPIEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPIEN_Msk;
#endif
}

void Peripheral::resetGpioI(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOIRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPIRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPIRST_Msk;
#endif
}
#endif

#if defined(GPIOJ)
void Peripheral::setGpioJEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPJEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPJEN_Msk;
#endif
}

void Peripheral::resetGpioJ(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOJRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOJRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPJRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPJRST_Msk;
#endif
}
#endif

#if defined(GPIOK)
void Peripheral::setGpioKEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_IOPKEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_IOPKEN_Msk;
#endif
}

void Peripheral::resetGpioK(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOKRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOKRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_IOPKRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPKRST_Msk;
#endif
}
#endif

#if defined(AFIO)
void Peripheral::setAfioEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_AFIOEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_AFIOEN_Msk;
}

void Peripheral::resetAfio(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_AFIORST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_AFIORST_Msk;
}
#endif

#if defined(CRC)
void Peripheral::setCrcEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_CRCEN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->AHBENR |= RCC_AHBENR_CRCEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_CRCEN_Msk;
#endif
}

void Peripheral::resetCrc(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_CRCRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_CRCRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    // 기능 없음
#endif
}
#endif

#if defined(BKPSRAM_BASE)
void Peripheral::setBackupSramEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_BKPSRAMEN_Msk;
}
#endif

#if defined(CCMDATARAM_BASE)
void Peripheral::setCcmRamEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_CCMDATARAMEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_CCMDATARAMEN_Msk;
}
#endif

#if defined(DMA1)
void Peripheral::setDmaEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN_Msk;
#if defined(DMA2)
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN_Msk;
#endif
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    if (en)
        RCC->AHBENR |= RCC_AHBENR_DMA1EN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_DMA1EN_Msk;
#if defined(DMA2)
    if (en)
        RCC->AHBENR |= RCC_AHBENR_DMA2EN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_DMA2EN_Msk;
#endif
#endif
}

void Peripheral::resetDma(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA1RST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA1RST_Msk;
#if defined(DMA2)
    RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2RST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2RST_Msk;
#endif
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    // 기능 없음
#endif
}
#endif

#if defined(DMA2D)
void Peripheral::setDma2d(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_DMA2DEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2DEN_Msk;
}

void Peripheral::resetDma2d(void)
{
    RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2DRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2DRST_Msk;
}
#endif

#if defined(ETH)
void Peripheral::setEthernetMacEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACEN_Msk;
}

void Peripheral::setEthernetRxEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACRXEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACRXEN_Msk;
}

void Peripheral::setEthernetTxEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACTXEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACTXEN_Msk;
}

void Peripheral::setEthernetPtpEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACPTPEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACPTPEN_Msk;
}

void Peripheral::resetEthernetMac(void)
{
    RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST_Msk;
}
#endif

#if defined(USB_OTG_HS)
void Peripheral::setUsbdHsEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSEN_Msk;
}

void Peripheral::setUsbdHsUlpiEn(bool en)
{
    if (en)
        RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPIEN_Msk;
    else
        RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSULPIEN_Msk;
}

void Peripheral::resetUsbHs(void)
{
    RCC->AHB1RSTR |= RCC_AHB1RSTR_OTGHRST_Msk;
    RCC->AHB1RSTR &= ~RCC_AHB1RSTR_OTGHRST_Msk;
}
#endif

#if defined(USB_OTG_FS)
void Peripheral::setUsbdFsEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_OTGFSEN_Msk;
}

void Peripheral::resetUsbFs(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_OTGFSRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_OTGFSRST_Msk;
}
#endif

#if defined(DCMI)
void Peripheral::setDcmiEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_DCMIEN_Msk;
}

void Peripheral::resetDcmi(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_DCMIRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DCMIRST_Msk;
}
#endif

#if defined(CRYP)
void Peripheral::setCrypEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_CRYPEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_CRYPEN_Msk;
}

void Peripheral::resetCryp(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_CRYPRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_CRYPRST_Msk;
}
#endif

#if defined(HASH)
void Peripheral::setHashEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_HASHEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_HASHEN_Msk;
}

void Peripheral::resetHash(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_HASHRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_HASHRST_Msk;
}
#endif

#if defined(RNG)
void Peripheral::setRngEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_RNGEN_Msk;
}

void Peripheral::resetRng(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_RNGRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_RNGRST_Msk;
}
#endif

#if defined(FMC_Bank1)
void Peripheral::setFmcEn(bool en)
{
    if (en)
        RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN_Msk;
    else
        RCC->AHB3ENR &= ~RCC_AHB3ENR_FMCEN_Msk;
}

void Peripheral::resetFmc(void)
{
    RCC->AHB3RSTR |= RCC_AHB3RSTR_FMCRST_Msk;
    RCC->AHB3RSTR &= ~RCC_AHB3RSTR_FMCRST_Msk;
}
#endif

#if defined(TC0)
void Peripheral::setTimer0En(bool en)
{
#if defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[TC0_GCLK_ID].bit.CHEN = en;
#endif
}
#endif

#if defined(TIM1) || defined(TC1)
void Peripheral::setTimer1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[TC1_GCLK_ID].bit.CHEN = en;
#endif
}

void Peripheral::resetTimer1(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(TIM2) || defined(TC2)
void Peripheral::setTimer2En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM2EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[TC2_GCLK_ID].bit.CHEN = en;
#endif
}

void Peripheral::resetTimer2(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM2RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM2RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(TIM3) || defined(TC3)
void Peripheral::setTimer3En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM3EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[TC3_GCLK_ID].bit.CHEN = en;
#endif
}

void Peripheral::resetTimer3(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM3RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM3RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(TIM4) || defined(TC4)
void Peripheral::setTimer4En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM4EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[TC4_GCLK_ID].bit.CHEN = en;
#endif
}

void Peripheral::resetTimer4(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM4RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM4RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(TIM5)
void Peripheral::setTimer5En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM5EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM5EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN_Msk;
#endif
}

void Peripheral::resetTimer5(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM5RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM5RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM5RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM5RST_Msk;
#endif
}
#endif

#if defined(TIM6)
void Peripheral::setTimer6En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM6EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM6EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;
#endif
}

void Peripheral::resetTimer6(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM6RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM6RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST_Msk;
#endif
}
#endif

#if defined(TIM7)
void Peripheral::setTimer7En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM7EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM7EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN_Msk;
#endif
}

void Peripheral::resetTimer7(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM7RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM7RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST_Msk;
#endif
}
#endif

#if defined(TIM8)
void Peripheral::setTimer8En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM8EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN_Msk;
}

void Peripheral::resetTimer8(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST_Msk;
}
#endif

#if defined(TIM9)
void Peripheral::setTimer9En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM9EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN_Msk;
}

void Peripheral::resetTimer9(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM9RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM9RST_Msk;
}
#endif

#if defined(TIM10)
void Peripheral::setTimer10En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM10EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN_Msk;
}

void Peripheral::resetTimer10(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM10RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM10RST_Msk;
}
#endif

#if defined(TIM11)
void Peripheral::setTimer11En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM11EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN_Msk;
}

void Peripheral::resetTimer11(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM11RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM11RST_Msk;
}
#endif

#if defined(TIM12)
void Peripheral::setTimer12En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM12EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN_Msk;
}

void Peripheral::resetTimer12(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM12RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM12RST_Msk;
}
#endif

#if defined(TIM13)
void Peripheral::setTimer13En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM13EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN_Msk;
}

void Peripheral::resetTimer13(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM13RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM13RST_Msk;
}
#endif

#if defined(TIM14)
void Peripheral::setTimer14En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM14EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN_Msk;
}

void Peripheral::resetTimer14(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM14RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM14RST_Msk;
}
#endif

#if defined(TIM15)
void Peripheral::setTimer15En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM15EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM15EN_Msk;
}

void Peripheral::resetTimer15(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM15RST_Msk;
}
#endif

#if defined(TIM16)
void Peripheral::setTimer16En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM16EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM16EN_Msk;
}

void Peripheral::resetTimer16(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM16RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM16RST_Msk;
}
#endif

#if defined(TIM17)
void Peripheral::setTimer17En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM17EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM17EN_Msk;
}

void Peripheral::resetTimer17(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM17RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM17RST_Msk;
}
#endif

#if defined(WWDG)
void Peripheral::setWindowWatchdogEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_WWDGEN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_WWDGEN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_WWDGEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN_Msk;
#endif
}

void Peripheral::resetWindowWatchdog(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    // 기능 없음
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_WWDGRST_Msk;
#endif
}
#endif

#if defined(SERCOM0)
void Peripheral::setSpi0En(bool en)
{
#if defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi0(void)
{
#if defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI1) || defined(SERCOM1)
void Peripheral::setSpi1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SPI1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi1(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI2) || defined(SERCOM2)
void Peripheral::setSpi2En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_SPI2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_SPI2EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI2EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi2(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI2RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI2RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI3) || defined(SERCOM3)
void Peripheral::setSpi3En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_SPI3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_SPI3EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI3EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi3(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI3RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI3RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI4) || defined(SERCOM4)
void Peripheral::setSpi4En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SPI4EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi4(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB2RSTR |= RCC_APB2RSTR_SPI4RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI4RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI5) || defined(SERCOM5)
void Peripheral::setSpi5En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SPI5EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SPI5EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetSpi5(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB2RSTR |= RCC_APB2RSTR_SPI5RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI5RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(SPI6)
void Peripheral::setSpi6En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SPI6EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SPI6EN_Msk;
}

void Peripheral::resetSpi6(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SPI6RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI6RST_Msk;
}
#endif

#if defined(USART0) || defined(SERCOM0)
void Peripheral::setUart0En(bool en)
{
#if defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart0(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)

#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(USART1) || defined(SERCOM1)
void Peripheral::setUart1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart1(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C) || defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(USART2) || defined(SERCOM2)
void Peripheral::setUart2En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART2EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart2(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART2RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART2RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(USART3) || defined(SERCOM3)
void Peripheral::setUart3En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART3EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart3(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART3RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART3RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(UART4) || defined(SERCOM4)
void Peripheral::setUart4En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART4EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart4(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART4RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART4RST_Msk;
#else

#endif
}
#endif

#if defined(UART5) || defined(SERCOM5)
void Peripheral::setUart5En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART5EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_UART5EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART5EN_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)
    GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void Peripheral::resetUart5(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A) || defined(YSS_DRV_CLOCK_ST_TYPE_B) || defined(YSS_DRV_CLOCK_ST_TYPE_C)
    RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART5RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART5RST_Msk;
#elif defined(YSS_DRV_CLOCK_MICROCHIP_TYPE_A)

#endif
}
#endif

#if defined(USART6)
void Peripheral::setUart6En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN_Msk;
}

void Peripheral::resetUart6(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST_Msk;
}
#endif

#if defined(UART7)
void Peripheral::setUart7En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART7EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART7EN_Msk;
}

void Peripheral::resetUart7(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_UART7RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART7RST_Msk;
}
#endif

#if defined(UART8)
void Peripheral::setUart8En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART8EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART8EN_Msk;
}

void Peripheral::resetUart8(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_UART8RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART8RST_Msk;
}
#endif

#if defined(I2C1)
void Peripheral::setI2c1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C1EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_Msk;
#endif
}

void Peripheral::resetI2c1(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C1RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C1RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST_Msk;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
bool Peripheral::setI2c1ClkSrc(unsigned char src)
{
    switch (src)
    {
    case define::clock::i2c::src::PCLK1:
    case define::clock::i2c::src::SYSCLK:
    case define::clock::i2c::src::HSI16:
        RCC->CCIPR &= ~RCC_CCIPR_I2C1SEL_Msk;
        RCC->CCIPR |= src <<= RCC_CCIPR_I2C1SEL_Pos;
        return true;
    default:
        return false;
    }
}
#endif
#endif

#if defined(I2C2)
void Peripheral::setI2c2En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_I2C2EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C2EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_Msk;
#endif
}

void Peripheral::resetI2c2(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C2RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C2RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST_Msk;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
bool Peripheral::setI2c2ClkSrc(unsigned char src)
{
    switch (src)
    {
    case define::clock::i2c::src::PCLK1:
    case define::clock::i2c::src::SYSCLK:
    case define::clock::i2c::src::HSI16:
        RCC->CCIPR &= ~RCC_CCIPR_I2C2SEL_Msk;
        RCC->CCIPR |= src <<= RCC_CCIPR_I2C2SEL_Pos;
        return true;
    default:
        return false;
    }
}
#endif
#endif

#if defined(I2C3)
void Peripheral::setI2c3En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_I2C3EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C3EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_Msk;
#endif
}

void Peripheral::resetI2c3(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C3RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C3RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST_Msk;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
bool Peripheral::setI2c3ClkSrc(unsigned char src)
{
    switch (src)
    {
    case define::clock::i2c::src::PCLK1:
    case define::clock::i2c::src::SYSCLK:
    case define::clock::i2c::src::HSI16:
        RCC->CCIPR &= ~RCC_CCIPR_I2C3SEL_Msk;
        RCC->CCIPR |= src <<= RCC_CCIPR_I2C3SEL_Pos;
        return true;
    default:
        return false;
    }
}
#endif
#endif

#if defined(I2C4)
void Peripheral::setI2c4En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR2 |= RCC_APB1ENR2_I2C4EN_Msk;
    else
        RCC->APB1ENR2 &= ~RCC_APB1ENR2_I2C4EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C4EN_Msk;
#endif
}

void Peripheral::resetI2c4(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR2 |= RCC_APB1RSTR2_I2C4RST_Msk;
    RCC->APB1RSTR2 &= ~RCC_APB1RSTR2_I2C4RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C4RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C4RST_Msk;
#endif
}
#endif

#if defined(CAN1)
void Peripheral::setCan1En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_CAN1EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN_Msk;
}

void Peripheral::resetCan1(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST_Msk;
}
#endif

#if defined(CAN2)
void Peripheral::setCan2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_CAN2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN_Msk;
}

void Peripheral::resetCan2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST_Msk;
}
#endif

#if defined(FDCAN1)
void Peripheral::setCan1En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_FDCANEN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_FDCANEN_Msk;
}

unsigned int Peripheral::getCan1ClkFreq(void)
{
    unsigned int src = (RCC->CCIPR & RCC_CCIPR_FDCANSEL_Msk) >> RCC_CCIPR_FDCANSEL_Pos;

    switch (src)
    {
    case 0: // HSE
        return (unsigned int)gHseFreq * 1000000;
    case 1: // PLLQ
        return gPllQFreq;
    case 2: // PCLK1
        return clock.getApb1ClkFreq();
    default:
        return 0;
    }
}

bool Peripheral::setCan1ClkSrc(unsigned char src)
{
    if (src > 2)
        return false;
    unsigned int ccipr = RCC->CCIPR;

    ccipr &= ~RCC_CCIPR_FDCANSEL_Msk;
    ccipr |= src << RCC_CCIPR_FDCANSEL_Pos;
    RCC->CCIPR = ccipr;

    return true;
}
#endif

#if defined(PWR)
void Peripheral::setPwrEn(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_PWREN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN_Msk;
#endif
}

void Peripheral::resetPwr(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_PWRRST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_PWRRST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_PWRRST_Msk;
#endif
}
#endif

#if defined(DAC1)
void Peripheral::setDac1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_DAC1EN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_DAC1EN_Msk;
#else
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_DACEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_DACEN_Msk;
#endif
}

void Peripheral::resetDac1(void)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->AHB2RSTR |= RCC_AHB2RSTR_DAC1RST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DAC1RST_Msk;
#else
    RCC->APB1RSTR |= RCC_APB1RSTR_DACRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_DACRST_Msk;
#endif
}
#endif

#if defined(ADC1)
void Peripheral::setAdc1En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#else
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN_Msk;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
void Peripheral::resetAdc(void)
#else
void Peripheral::resetAdc1(void)
#endif
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_A)
    RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_B)
    RCC->APB2RSTR |= RCC_APB2RSTR_ADC1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC1RST_Msk;
#elif defined(YSS_DRV_CLOCK_ST_TYPE_D)
    RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC12RST_Pos;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC12RST_Pos;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
void Peripheral::setAdc12ClkSrc(unsigned char src)
{
    unsigned int ccipr;
    switch (src)
    {
    case define::clock::adc::src::NO_CLK:
    case define::clock::adc::src::PLL:
    case define::clock::adc::src::SYSCLK:
        ccipr = RCC->CCIPR & ~RCC_CCIPR_ADC12SEL_Msk;
        ccipr |= src << RCC_CCIPR_ADC12SEL_Pos;
        RCC->CCIPR = ccipr;
        break;
    }
}
#endif
#endif

#if defined(ADC2)
void Peripheral::setAdc2En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#else
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC2EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN_Msk;
#endif
}

#if defined(YSS_DRV_CLOCK_ST_TYPE_B)
void Peripheral::resetAdc2(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_ADC2RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC2RST_Msk;
}
#endif
#endif

#if defined(ADC3)
void Peripheral::setAdc3En(bool en)
{
#if defined(YSS_DRV_CLOCK_ST_TYPE_D)
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_ADC345EN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC345EN_Msk;
#else
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC3EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN_Msk;
#endif
}
#endif

#if defined(SDIO)
void Peripheral::setSdioEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SDIOEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SDIOEN_Msk;
}

void Peripheral::resetSdio(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SDIORST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SDIORST_Msk;
}
#endif

#if defined(SDMMC1)
void Peripheral::setSdmmcEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SDMMC1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SDMMC1EN_Msk;
}

void Peripheral::resetSdmmc(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SDMMC1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SDMMC1RST_Msk;
}
#endif

#if defined(SYSCFG)
void Peripheral::setSyscfgEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
}

void Peripheral::resetSyscfg(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST_Msk;
}
#endif

#if defined(SAI1)
void setSai1En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SAI1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SAI1EN_Msk;
}

void Peripheral::resetSai1(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SAI1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SAI1RST_Msk;
}
#endif

#if defined(LTDC)
void Peripheral::setLtdcEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_LTDCEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_LTDCEN_Msk;
}

void Peripheral::resetLtdc(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_LTDCRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_LTDCRST_Msk;
}
#endif
}