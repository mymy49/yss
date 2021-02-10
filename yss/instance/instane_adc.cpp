#include <instance/instance_adc.h>
#include <instance/instance_clock.h>

#include <config.h>
#include <yss/yss.h>

#if defined(ADC1_ENABLE) && defined(ADC1)
static void setAdc1ClkEn(bool en)
{
	clock.peripheral.setAdc1En(en);
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
	clock.peripheral.setAdc2En(en);
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

#if defined(ADC3_ENABLE) && defined(ADC3)
void setAdc3ClkEn(bool en)
{
	clock.peripheral.setAdc3En(en);
}

void setAdc3IntEn(bool en)
{
    nvic.setAdc3En(en);
}

static void resetAdc3(void)
{
	clock.peripheral.resetAdc3();
}

drv::Adc adc3(ADC3, setAdc3ClkEn, setAdc3IntEn, resetAdc3);
#endif

extern "C"
{
#if defined(YSS_DRV_ADC_ST_TYPE_A__H_)
    void ADC_IRQHandler(void)
#elif defined(YSS_DRV_ADC_ST_TYPE_B__H_)
    void ADC1_2_IRQHandler(void)
#endif
    {
#if defined(ADC1_ENABLE) && defined(ADC1)
        adc1.isr();
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
        adc2.isr();
#endif
    }
}
