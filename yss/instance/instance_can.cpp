#include <instance/instance_can.h>
#include <instance/instance_clock.h>

#include <config.h>
#include <yss/yss.h>

static unsigned int getClockFreq(void)
{
    return clock.getApb1ClkFreq();
}

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && (defined(CAN1) || defined(FDCAN1))

static void setCan1ClockEn(bool en)
{
    clock.peripheral.setCan1En(en);
}

static void setCan1IntEn(bool en)
{
    nvic.setCan1En(en);
}

static void resetCan1(void)
{
    clock.peripheral.resetCan1();
}

#if defined(YSS_DRV_CAN_ST_TYPE_A__H_)
drv::Can can1(CAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getClockFreq);
#elif defined(YSS_DRV_CAN_ST_TYPE_B__H_)
drv::Can can1(FDCAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getClockFreq);
#endif
extern "C"
{
#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)
    void USB_LP_CAN1_RX0_IRQHandler(void)
#elif defined(STM32F405xx) || defined(STM32F415xx) || \
    defined(STM32F407xx) || defined(STM32F417xx) ||   \
    defined(STM32F427xx) || defined(STM32F437xx) ||   \
    defined(STM32F429xx) || defined(STM32F439xx) ||   \
    defined(STM32F746xx) || defined(STM32F745xx) ||   \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)
    void CAN1_RX0_IRQHandler(void)
#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)
    void FDCAN1_IT0_IRQHandler(void)
#endif
    {
        can1.isr();
    }
}

#endif

//********** can2 구성 설정 및 변수 선언 **********
#if defined(CAN2_ENABLE) && defined(CAN2)

static void setCan2ClockEn(bool en)
{
    clock.peripheral.setCan2En(en);
}

static void setCan2IntEn(bool en)
{
    nvic.setCan2En(en);
}

static void resetCan2(void)
{
    clock.peripheral.resetCan2();
}

drv::Can can2(CAN2, setCan2ClockEn, setCan2IntEn, resetCan2, getClockFreq);

extern "C"
{
    void CAN2_RX0_IRQHandler(void)
    {
        can2.isr();
    }
}
#endif