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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC) ||                                                                         \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>
#include <drv/uart/drv_st_uart_type_B_register.h>
#include <instance/instance_clock.h>
#include <instance/instance_dma.h>
#include <instance/instance_nvic.h>

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

drv::Uart uart1(USART1, setUart1ClockEn, setUart1IntEn, resetUart1, YSS_DMA_MAP_UART1_TX_STREAM, 0, YSS_DMA_MAP_UART1_TX_CHANNEL, 0, define::dma::priorityLevel::LOW, getApb2ClkFreq);

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

drv::Uart uart2(USART2, setUart2ClockEn, setUart2IntEn, resetUart2, YSS_DMA_MAP_UART2_TX_STREAM, 0, YSS_DMA_MAP_UART2_TX_CHANNEL, 0, define::dma::priorityLevel::LOW, getApb1ClkFreq);

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

drv::Uart uart3(USART3, setUart3ClockEn, setUart3IntEn, resetUart3, YSS_DMA_MAP_UART3_TX_STREAM, 0, YSS_DMA_MAP_UART3_TX_CHANNEL, 0, define::dma::priorityLevel::LOW, getApb1ClkFreq);

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

drv::Uart uart4(UART4, setUart4ClockEn, setUart4IntEn, resetUart4, YSS_DMA_MAP_UART4_TX_STREAM, 0, YSS_DMA_MAP_UART4_TX_CHANNEL, 0, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
    void UART4_IRQHandler(void)
    {
        uart4.isr();
    }
}
#endif

namespace drv
{
Uart::Uart(USART_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned short priority, unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
    this->set(txChannel, rxChannel, (void *)&(peri->DR), (void *)&(peri->DR), priority);

    mGetClockFreq = getClockFreq;
    mStream = txStream;
    mPeri = peri;
    mRcvBuf = 0;
    mTail = 0;
    mHead = 0;
}

bool Uart::init(unsigned int baud, unsigned int receiveBufferSize)
{
    unsigned int man, fra, buf;
    unsigned int clk = mGetClockFreq() >> 4;

    if (mRcvBuf)
        delete mRcvBuf;
    mRcvBuf = new unsigned char[receiveBufferSize];

    if (mRcvBuf == 0)
        return false;

    mRcvBufSize = receiveBufferSize;

    man = clk / baud;
    man &= 0xfff;
    fra = 16 * (clk % baud) / baud;
    fra &= 0xf;

    setUsartOver8(mPeri, false);
    setUsartBrr(mPeri, man, fra);

    setUsartTxEn(mPeri, true);
    setUsartRxEn(mPeri, true);
    setUsartDmaTxEn(mPeri, true);
    setUsartRxneiEn(mPeri, true);
    setUsartEn(mPeri, true);

    return true;
}

bool Uart::send(void *src, unsigned int size, unsigned int timeout)
{
    if (mStream)
        return mStream->send(this, src, size, timeout);
    else
        return false;
}

bool Uart::send(const void *src, unsigned int size, unsigned int timeout)
{
    if (mStream)
        return mStream->send(this, (void *)src, size, timeout);
    else
        return false;
}

void Uart::push(char data)
{
    if (mRcvBuf)
    {
        mRcvBuf[mHead++] = data;
        if (mHead >= mRcvBufSize)
            mHead = 0;
    }
}

void Uart::isr(void)
{
    unsigned int sr = mPeri->SR;

    push(mPeri->DR);

    if (sr & (1 << 3))
    {
        flush();
    }
}

void Uart::flush(void)
{
    mHead = mTail = 0;
}

signed short Uart::get(void)
{
    signed short buf = -1;

    if (mHead != mTail)
    {
        buf = (unsigned char)mRcvBuf[mTail++];
        if (mTail >= mRcvBufSize)
            mTail = 0;
    }

    return buf;
}

char Uart::getWaitUntilReceive(void)
{
    signed short data;

    while (1)
    {
        data = get();
        if (data >= 0)
            return (char)data;
        thread::switchContext();
    }
}
}
#endif