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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.09.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/adc/drv_st_adc_type_A_register.h>
#include <drv/peripherals.h>
#include <yss/malloc.h>

#if defined(ADC1_ENABLE) && defined(ADC1)
void setAdc1ClkEn(bool en)
{
    clock.peripheral.setAdc1En(true);
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
    clock.peripheral.setAdc2En(true);
}

void setAdc2IntEn(bool en)
{
    nvic.setAdc2En(en);
}

drv::Adc adc2(ADC2, setAdc2ClkEn, setAdc2IntEn);
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
    // ADC on
    mPeri->CR &= ~ADC_CR_DEEPPWD_Msk;
    mPeri->CR |= ADC_CR_ADVREGEN_Msk;
    mPeri->ISR = ADC_ISR_ADRDY_Msk;
    mPeri->CR |= ADC_CR_ADEN_Msk;
    while ((mPeri->ISR & ADC_ISR_ADRDY_Msk) == 0)
        thread::yield();
    mPeri->ISR = ADC_ISR_ADRDY_Msk;

    // 샘플 타임 설정
    mPeri->SMPR1 = ADC_SMPR1_SMP0_Msk | ADC_SMPR1_SMP1_Msk | ADC_SMPR1_SMP2_Msk |
                   ADC_SMPR1_SMP3_Msk | ADC_SMPR1_SMP4_Msk | ADC_SMPR1_SMP5_Msk |
                   ADC_SMPR1_SMP6_Msk | ADC_SMPR1_SMP7_Msk | ADC_SMPR1_SMP8_Msk |
                   ADC_SMPR1_SMP9_Msk;

    mPeri->SMPR2 = ADC_SMPR2_SMP10_Msk | ADC_SMPR2_SMP11_Msk | ADC_SMPR2_SMP12_Msk |
                   ADC_SMPR2_SMP13_Msk | ADC_SMPR2_SMP14_Msk | ADC_SMPR2_SMP15_Msk |
                   ADC_SMPR2_SMP16_Msk | ADC_SMPR2_SMP17_Msk | ADC_SMPR2_SMP18_Msk;

    mPeri->IER |= ADC_IER_EOCIE_Msk;
    mPeri->CR |= ADC_CR_ADSTART_Msk;
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

    mPeri->SQR1 &= ~ADC_SQR1_SQ1_Msk;
    mPeri->SQR1 |= mChannel[mIndex] << ADC_SQR1_SQ1_Pos;
    mPeri->CR |= ADC_CR_ADSTART_Msk;
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
    void ADC1_2_IRQHandler(void)
    {
#if defined(ADC1_ENABLE) && defined(ADC1)
        if (ADC1->IER & ADC_IER_EOCIE_Msk && ADC1->ISR & ADC_ISR_EOC_Msk)
        {
            ADC1->ISR = ADC_ISR_EOC_Msk;
            adc1.isr();
        }
#endif
#if defined(ADC1_ENABLE) && defined(ADC1)
        if (ADC2->IER & ADC_IER_EOCIE_Msk && ADC2->ISR & ADC_ISR_EOC_Msk)
        {
            ADC2->ISR = ADC_ISR_EOC_Msk;
            adc2.isr();
        }
#endif
    }
}

#endif