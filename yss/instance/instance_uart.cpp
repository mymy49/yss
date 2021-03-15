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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.10 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

static unsigned int getApb2ClkFreq(void)
{
    return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
    return clock.getApb1ClkFreq();
}

#if defined(USART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
    clock.peripheral.setUart1En(en);
}

static void setUart1IntEn(bool en)
{
    nvic.setUart1En(en);
}

static void resetUart1(void)
{
    clock.peripheral.resetUart1();
}

drv::Uart uart1(USART1, setUart1ClockEn, setUart1IntEn, resetUart1, YSS_DMA_MAP_UART1_TX_STREAM, YSS_DMA_MAP_UART1_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);

extern "C"
{
    void USART1_IRQHandler(void)
    {
        uart1.isr();
    }
}
#endif

#if defined(USART2) && defined(UART2_ENABLE)
static void setUart2ClockEn(bool en)
{
    clock.peripheral.setUart2En(en);
}

static void setUart2IntEn(bool en)
{
    nvic.setUart2En(en);
}

static void resetUart2(void)
{
    clock.peripheral.resetUart2();
}

drv::Uart uart2(USART2, setUart2ClockEn, setUart2IntEn, resetUart2, YSS_DMA_MAP_UART2_TX_STREAM, YSS_DMA_MAP_UART2_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void USART2_IRQHandler(void)
    {
        uart2.isr();
    }
}

#endif

#if defined(USART3) && defined(UART3_ENABLE)
static void setUart3ClockEn(bool en)
{
    clock.peripheral.setUart3En(en);
}

static void setUart3IntEn(bool en)
{
    nvic.setUart3En(en);
}

static void resetUart3(void)
{
    clock.peripheral.resetUart3();
}

drv::Uart uart3(USART3, setUart3ClockEn, setUart3IntEn, resetUart3, YSS_DMA_MAP_UART3_TX_STREAM, YSS_DMA_MAP_UART3_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void USART3_IRQHandler(void)
    {
        uart3.isr();
    }
}

#endif

#if defined(UART4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
    clock.peripheral.setUart4En(en);
}

static void setUart4IntEn(bool en)
{
    nvic.setUart4En(en);
}

static void resetUart4(void)
{
    clock.peripheral.resetUart4();
}

drv::Uart uart4(UART4, setUart4ClockEn, setUart4IntEn, resetUart4, YSS_DMA_MAP_UART4_TX_STREAM, YSS_DMA_MAP_UART4_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void UART4_IRQHandler(void)
    {
        uart4.isr();
    }
}
#endif

#if defined(UART5) && defined(UART5_ENABLE)
static void setUart5ClockEn(bool en)
{
    clock.peripheral.setUart5En(en);
}

static void setUart5IntEn(bool en)
{
    nvic.setUart5En(en);
}

static void resetUart5(void)
{
    clock.peripheral.resetUart5();
}

drv::Uart uart5(UART5, setUart5ClockEn, setUart5IntEn, resetUart5, YSS_DMA_MAP_UART5_TX_STREAM, YSS_DMA_MAP_UART5_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void UART5_IRQHandler(void)
    {
        uart5.isr();
    }
}

#endif

#if defined(USART6) && defined(UART6_ENABLE)
static void setUart6ClockEn(bool en)
{
    clock.peripheral.setUart6En(en);
}

static void setUart6IntEn(bool en)
{
    nvic.setUart6En(en);
}

static void resetUart6(void)
{
    clock.peripheral.resetUart6();
}

drv::Uart uart6(USART6, setUart6ClockEn, setUart6IntEn, resetUart6, YSS_DMA_MAP_UART6_TX_STREAM, YSS_DMA_MAP_UART6_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);

extern "C"
{
    void USART6_IRQHandler(void)
    {
        uart6.isr();
    }
}

#endif

#if defined(UART7) && defined(UART7_ENABLE)
static void setUart7ClockEn(bool en)
{
    clock.peripheral.setUart7En(en);
}

static void setUart7IntEn(bool en)
{
    nvic.setUart7En(en);
}

static void resetUart7(void)
{
    clock.peripheral.resetUart7();
}

drv::Uart uart7(UART7, setUart7ClockEn, setUart7IntEn, resetUart7, YSS_DMA_MAP_UART7_TX_STREAM, YSS_DMA_MAP_UART7_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void UART7_IRQHandler(void)
    {
        uart7.isr();
    }
}

#endif

#if defined(UART8) && defined(UART8_ENABLE)
static void setUart8ClockEn(bool en)
{
    clock.peripheral.setUart8En(en);
}

static void setUart8IntEn(bool en)
{
    nvic.setUart8En(en);
}

static void resetUart8(void)
{
    clock.peripheral.resetUart8();
}

drv::Uart uart8(UART8, setUart8ClockEn, setUart8IntEn, resetUart8, YSS_DMA_MAP_UART8_TX_STREAM, YSS_DMA_MAP_UART8_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void UART8_IRQHandler(void)
    {
        uart8.isr();
    }
}

#endif
