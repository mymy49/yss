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

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>
#include <drv/dma/drv_st_dma_type_A_register.h>

#if defined(DMA1)
static void setDmaClockEn(bool en)
{
    clock.peripheral.setDmaEn(en);
}

static void setDmaIntEn(bool en)
{
#if defined(DMA1_STREAM0_ENABLE) && defined(DMA1_Stream0)
    nvic.setDma1Stream0En(en);
#endif
#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1_Stream1)
    nvic.setDma1Stream1En(en);
#endif
#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1_Stream2)
    nvic.setDma1Stream2En(en);
#endif
#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1_Stream3)
    nvic.setDma1Stream3En(en);
#endif
#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1_Stream4)
    nvic.setDma1Stream4En(en);
#endif
#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1_Stream5)
    nvic.setDma1Stream5En(en);
#endif
#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1_Stream6)
    nvic.setDma1Stream6En(en);
#endif
#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1_Stream7)
    nvic.setDma1Stream7En(en);
#endif

#if defined(DMA2_STREAM0_ENABLE) && defined(DMA2_Stream0)
    nvic.setDma2Stream0En(en);
#endif
#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2_Stream1)
    nvic.setDma2Stream1En(en);
#endif
#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2_Stream2)
    nvic.setDma2Stream2En(en);
#endif
#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2_Stream3)
    nvic.setDma2Stream3En(en);
#endif
#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Stream4)
    nvic.setDma2Stream4En(en);
#endif
#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Stream5)
    nvic.setDma2Stream5En(en);
#endif
#if defined(DMA2_STREAM6_ENABLE) && defined(DMA2_Stream6)
    nvic.setDma2Stream6En(en);
#endif
#if defined(DMA2_STREAM7_ENABLE) && defined(DMA2_Stream7)
    nvic.setDma2Stream7En(en);
#endif
}

drv::Dma dma(setDmaClockEn, setDmaIntEn);
#endif

#if defined(DMA1_STREAM0_ENABLE) && defined(DMA1_Stream0)
static void setDma1Stream0IntEn(bool en)
{
    nvic.setDma1Stream0En(en);
}

drv::Stream dma1Stream0(DMA1_Stream0, 0, setDma1Stream0IntEn);
#endif

#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1_Stream1)
static void setDma1Stream1IntEn(bool en)
{
    nvic.setDma1Stream1En(en);
}

drv::Stream dma1Stream1(DMA1_Stream1, 0, setDma1Stream1IntEn);
#endif

#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1_Stream2)
static void setDma1Stream2IntEn(bool en)
{
    nvic.setDma1Stream2En(en);
}

drv::Stream dma1Stream2(DMA1_Stream2, 0, setDma1Stream2IntEn);
#endif

#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1_Stream3)
static void setDma1Stream3IntEn(bool en)
{
    nvic.setDma1Stream3En(en);
}

drv::Stream dma1Stream3(DMA1_Stream3, 0, setDma1Stream3IntEn);
#endif

#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1_Stream4)
static void setDma1Stream4IntEn(bool en)
{
    nvic.setDma1Stream4En(en);
}

drv::Stream dma1Stream4(DMA1_Stream4, 0, setDma1Stream4IntEn);
#endif

#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1_Stream5)
static void setDma1Stream5IntEn(bool en)
{
    nvic.setDma1Stream5En(en);
}

drv::Stream dma1Stream5(DMA1_Stream5, 0, setDma1Stream5IntEn);
#endif

#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1_Stream6)
static void setDma1Stream6IntEn(bool en)
{
    nvic.setDma1Stream6En(en);
}

drv::Stream dma1Stream6(DMA1_Stream6, 0, setDma1Stream6IntEn);
#endif

#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1_Stream7)
static void setDma1Stream7IntEn(bool en)
{
    nvic.setDma1Stream7En(en);
}

drv::Stream dma1Stream7(DMA1_Stream7, 0, setDma1Stream7IntEn);
#endif

#if defined(DMA2_STREAM0_ENABLE) && defined(DMA2_Stream0)
static void setDma2Stream0IntEn(bool en)
{
    nvic.setDma2Stream0En(en);
}

drv::Stream dma2Stream0(DMA2_Stream0, 0, setDma2Stream0IntEn);
#endif

#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2_Stream1)
static void setDma2Stream1IntEn(bool en)
{
    nvic.setDma2Stream1En(en);
}

drv::Stream dma2Stream1(DMA2_Stream1, 0, setDma2Stream1IntEn);
#endif

#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2_Stream2)
static void setDma2Stream2IntEn(bool en)
{
    nvic.setDma2Stream2En(en);
}

drv::Stream dma2Stream2(DMA2_Stream2, 0, setDma2Stream2IntEn);
#endif

#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2_Stream3)
static void setDma2Stream3IntEn(bool en)
{
    nvic.setDma2Stream3En(en);
}

drv::Stream dma2Stream3(DMA2_Stream3, 0, setDma2Stream3IntEn);
#endif

#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Stream4)
static void setDma2Stream4IntEn(bool en)
{
    nvic.setDma2Stream4En(en);
}

drv::Stream dma2Stream4(DMA2_Stream4, 0, setDma2Stream4IntEn);
#endif

#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Stream5)
static void setDma2Stream5IntEn(bool en)
{
    nvic.setDma2Stream5En(en);
}

drv::Stream dma2Stream5(DMA2_Stream5, 0, setDma2Stream5IntEn);
#endif

#if defined(DMA2_STREAM6_ENABLE) && defined(DMA2_Stream6)
static void setDma2Stream6IntEn(bool en)
{
    nvic.setDma2Stream6En(en);
}

drv::Stream dma2Stream6(DMA2_Stream6, 0, setDma2Stream6IntEn);
#endif

#if defined(DMA2_STREAM7_ENABLE) && defined(DMA2_Stream7)
static void setDma2Stream7IntEn(bool en)
{
    nvic.setDma2Stream7En(en);
}

drv::Stream dma2Stream7(DMA2_Stream7, 0, setDma2Stream7IntEn);
#endif

drv::Dma::Dma(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

void drv::Dma::init(void)
{
#if defined(DMA1_STREAM0_ENABLE) && defined(DMA1_Stream0)
    dma1Stream0.init();
#endif

#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1_Stream1)
    dma1Stream1.init();
#endif

#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1_Stream2)
    dma1Stream2.init();
#endif

#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1_Stream3)
    dma1Stream3.init();
#endif

#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1_Stream4)
    dma1Stream4.init();
#endif

#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1_Stream5)
    dma1Stream5.init();
#endif

#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1_Stream6)
    dma1Stream6.init();
#endif

#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1_Stream7)
    dma1Stream7.init();
#endif

#if defined(DMA2_STREAM0_ENABLE) && defined(DMA2_Stream0)
    dma2Stream0.init();
#endif

#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2_Stream1)
    dma2Stream1.init();
#endif

#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2_Stream2)
    dma2Stream2.init();
#endif

#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2_Stream3)
    dma2Stream3.init();
#endif

#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Stream4)
    dma2Stream4.init();
#endif

#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Stream5)
    dma2Stream5.init();
#endif

#if defined(DMA2_STREAM6_ENABLE) && defined(DMA2_Stream6)
    dma2Stream6.init();
#endif

#if defined(DMA2_STREAM7_ENABLE) && defined(DMA2_Stream7)
    dma2Stream7.init();
#endif
}

#endif