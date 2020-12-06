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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.07.01 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/adc/drv_st_adc_type_A_register.h>
#include <yss/malloc.h>

#if defined(ADC1_ENABLE) && defined(ADC1)
void setAdc1ClkEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN_Msk;
}

void setAdc1IntEn(bool en)
{
    nvic.setAdc1En(en);
}

drv::Adc adc1(ADC1, setAdc1ClkEn, setAdc1IntEn);
#endif

#if defined(ADC2_ENABLE) && defined(ADC2)
void setAdc2ClkEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC2EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN_Msk;
}

void setAdc2IntEn(bool en)
{
    nvic.setAdc2En(en);
}

drv::Adc adc2(ADC2, setAdc2ClkEn, setAdc2IntEn);
#endif

#if defined(ADC3_ENABLE) && defined(ADC3)
void setAdc3ClkEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC3EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN_Msk;
}

void setAdc3IntEn(bool en)
{
    nvic.setAdc3En(en);
}

drv::Adc adc3(ADC3, setAdc3ClkEn, setAdc3IntEn);
#endif

namespace drv
{
Adc::Adc(ADC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
    mPeri = peri;
    mIndex = 0;
    mNumOfCh = 0;

    for (int i = 0; i < 18; i++)
    {
        mChannel[i] = 0;
        mResult[i] = 0;
        mLpfLv[i] = define::adc::lpfLv::LV9;
        mBit[i] = define::adc::bit::BIT16;
    }
}

bool Adc::init(void)
{
#if defined(ADC123_COMMON)
    ADC123_COMMON->CCR |= ADC_CCR_ADCPRE_Msk;
#endif
    // ADC on
    mPeri->CR2 |= ADC_CR2_ADON_Msk;

    // 샘플 타임 설정
    mPeri->SMPR1 = ADC_SMPR1_SMP10_Msk | ADC_SMPR1_SMP11_Msk | ADC_SMPR1_SMP12_Msk | ADC_SMPR1_SMP13_Msk | ADC_SMPR1_SMP14_Msk | ADC_SMPR1_SMP15_Msk | ADC_SMPR1_SMP16_Msk | ADC_SMPR1_SMP17_Msk | ADC_SMPR1_SMP18_Msk;
    mPeri->SMPR2 = ADC_SMPR2_SMP0_Msk | ADC_SMPR2_SMP1_Msk | ADC_SMPR2_SMP2_Msk | ADC_SMPR2_SMP3_Msk | ADC_SMPR2_SMP4_Msk | ADC_SMPR2_SMP5_Msk | ADC_SMPR2_SMP6_Msk | ADC_SMPR2_SMP7_Msk | ADC_SMPR2_SMP8_Msk | ADC_SMPR2_SMP9_Msk;

    mPeri->CR1 |= ADC_CR1_EOCIE_Msk;
    mPeri->CR2 |= ADC_CR2_SWSTART_Msk;
    return true;
}

void Adc::isr(void)
{
    signed int dr = mPeri->DR << 19, temp, abs;
    unsigned char index = mChannel[mIndex];

    temp = dr - mResult[index];
    temp >>= mLpfLv[mIndex];
    mResult[index] += temp;

    mIndex++;
    if (mIndex >= mNumOfCh)
        mIndex = 0;

    mPeri->SQR3 &= ~ADC_SQR3_SQ1_Msk;
    mPeri->SQR3 |= mChannel[mIndex];
    mPeri->CR2 |= ADC_CR2_SWSTART_Msk;
}

void Adc::add(unsigned char pin, unsigned char lpfLv, unsigned char bit)
{
    if (mNumOfCh >= 18)
        return;
    mChannel[mNumOfCh] = pin;
    mLpfLv[mNumOfCh] = lpfLv;
    mBit[pin] = bit;
    mNumOfCh++;
}

unsigned short Adc::get(unsigned char pin)
{
    return mResult[pin] >> mBit[pin];
}
}

extern "C"
{
    void ADC_IRQHandler(void)
    {
#if defined(ADC1_ENABLE) && defined(ADC1)
        if (ADC1->CR1 & ADC_CR1_EOCIE_Msk && ADC1->SR & ADC_SR_EOC_Msk)
        {
            ADC1->SR = 0;
            adc1.isr();
        }
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
        if (ADC2->CR1 & ADC_CR1_EOCIE_Msk && ADC2->SR & ADC_SR_EOC_Msk)
        {
            ADC2->SR = 0;
            adc2.isr();
        }
#endif
#if defined(ADC3_ENABLE) && defined(ADC3)
        if (ADC3->CR1 & ADC_CR1_EOCIE_Msk && ADC3->SR & ADC_SR_EOC_Msk)
        {
            ADC3->SR = 0;
            adc3.isr();
        }
#endif
    }
}

#endif