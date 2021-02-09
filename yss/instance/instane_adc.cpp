#include <instance/instance_adc.h>

#include <config.h>
#include <yss/yss.h>

#if defined(ADC1_ENABLE) && defined(ADC1)
static void setAdc1ClkEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN_Msk;
}

static void setAdc1IntEn(bool en)
{
    nvic.setAdc1En(en);
}

static void resetAdc1(void)
{
	clock.peripheral.resetAdc1();
}

drv::Adc adc1(ADC1, setAdc1ClkEn, setAdc1IntEn, resetAdc1);
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

static void resetAdc2(void)
{
	clock.peripheral.resetAdc2();
}

drv::Adc adc2(ADC2, setAdc2ClkEn, setAdc2IntEn, resetAdc2);
#endif

extern "C"
{
    void ADC1_2_IRQHandler(void)
    {
#if defined(ADC1_ENABLE) && defined(ADC1)
        if (ADC1->CR1 & ADC_CR1_EOSIE_Msk && ADC1->SR & ADC_SR_EOS_Msk)
        {
            ADC1->SR = 0;
            adc1.isr();
        }
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
        if (ADC2->CR1 & ADC_CR1_EOSIE_Msk && ADC2->SR & ADC_SR_EOS_Msk)
        {
            ADC2->SR = 0;
            adc2.isr();
        }
#endif
    }
}
