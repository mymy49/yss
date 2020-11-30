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

extern "C"
{
#define checkError(sr) (sr & 0x0c)
#define checkComplete(sr) (sr & 0x20)

#if defined(DMA1_STREAM0_ENABLE) && defined(DMA1_Stream0)
    void DMA1_Stream0_IRQHandler(void)
    {
        unsigned long sr = getDmaStream0Sr(DMA1);

        clrDmaStream0Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream0.setError();

        if (dma1Stream0.mRemainSize)
        {
            dma1Stream0.mAddr += 0xF000;
            if (dma1Stream0.mRemainSize > 0xF000)
            {
                DMA1_Stream0->NDTR = 0xF000;
                dma1Stream0.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream0->NDTR = dma1Stream0.mRemainSize;
                dma1Stream0.mRemainSize = 0;
            }
            DMA1_Stream0->M0AR = dma1Stream0.mAddr;
            DMA1_Stream0->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream0.setComplete();
    }
#endif
#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1_Stream1)
    void DMA1_Stream1_IRQHandler(void)
    {
        unsigned long sr = getDmaStream1Sr(DMA1);

        clrDmaStream1Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream1.setError();

        if (dma1Stream1.mRemainSize)
        {
            dma1Stream1.mAddr += 0xF000;
            if (dma1Stream1.mRemainSize > 0xF000)
            {
                DMA1_Stream1->NDTR = 0xF000;
                dma1Stream1.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream1->NDTR = dma1Stream1.mRemainSize;
                dma1Stream1.mRemainSize = 0;
            }
            DMA1_Stream1->M0AR = dma1Stream1.mAddr;
            DMA1_Stream1->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream1.setComplete();
    }
#endif
#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1_Stream2)
    void DMA1_Stream2_IRQHandler(void)
    {
        unsigned long sr = getDmaStream2Sr(DMA1);

        clrDmaStream2Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream2.setError();

        if (dma1Stream2.mRemainSize)
        {
            dma1Stream2.mAddr += 0xF000;
            if (dma1Stream2.mRemainSize > 0xF000)
            {
                DMA1_Stream2->NDTR = 0xF000;
                dma1Stream2.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream2->NDTR = dma1Stream2.mRemainSize;
                dma1Stream2.mRemainSize = 0;
            }
            DMA1_Stream2->M0AR = dma1Stream2.mAddr;
            DMA1_Stream2->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream2.setComplete();
    }
#endif
#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1_Stream3)
    void DMA1_Stream3_IRQHandler(void)
    {
        unsigned long sr = getDmaStream3Sr(DMA1);

        clrDmaStream3Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream3.setError();

        if (dma1Stream3.mRemainSize)
        {
            dma1Stream3.mAddr += 0xF000;
            if (dma1Stream3.mRemainSize > 0xF000)
            {
                DMA1_Stream3->NDTR = 0xF000;
                dma1Stream3.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream3->NDTR = dma1Stream3.mRemainSize;
                dma1Stream3.mRemainSize = 0;
            }
            DMA1_Stream3->M0AR = dma1Stream3.mAddr;
            DMA1_Stream3->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream3.setComplete();
    }
#endif
#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1_Stream4)
    void DMA1_Stream4_IRQHandler(void)
    {
        unsigned long sr = getDmaStream4Sr(DMA1);

        clrDmaStream4Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream4.setError();

        if (dma1Stream4.mRemainSize)
        {
            dma1Stream4.mAddr += 0xF000;
            if (dma1Stream4.mRemainSize > 0xF000)
            {
                DMA1_Stream4->NDTR = 0xF000;
                dma1Stream4.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream4->NDTR = dma1Stream4.mRemainSize;
                dma1Stream4.mRemainSize = 0;
            }
            DMA1_Stream4->M0AR = dma1Stream4.mAddr;
            DMA1_Stream4->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream4.setComplete();
    }
#endif
#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1_Stream5)
    void DMA1_Stream5_IRQHandler(void)
    {
        unsigned long sr = getDmaStream5Sr(DMA1);

        clrDmaStream5Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream5.setError();

        if (dma1Stream5.mRemainSize)
        {
            dma1Stream5.mAddr += 0xF000;
            if (dma1Stream5.mRemainSize > 0xF000)
            {
                DMA1_Stream5->NDTR = 0xF000;
                dma1Stream5.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream5->NDTR = dma1Stream5.mRemainSize;
                dma1Stream5.mRemainSize = 0;
            }
            DMA1_Stream5->M0AR = dma1Stream5.mAddr;
            DMA1_Stream5->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream5.setComplete();
    }
#endif
#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1_Stream6)
    void DMA1_Stream6_IRQHandler(void)
    {
        unsigned long sr = getDmaStream6Sr(DMA1);

        clrDmaStream6Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream6.setError();

        if (dma1Stream6.mRemainSize)
        {
            dma1Stream6.mAddr += 0xF000;
            if (dma1Stream6.mRemainSize > 0xF000)
            {
                DMA1_Stream6->NDTR = 0xF000;
                dma1Stream6.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream6->NDTR = dma1Stream6.mRemainSize;
                dma1Stream6.mRemainSize = 0;
            }
            DMA1_Stream6->M0AR = dma1Stream6.mAddr;
            DMA1_Stream6->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream6.setComplete();
    }
#endif
#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1_Stream7)
    void DMA1_Stream7_IRQHandler(void)
    {
        unsigned long sr = getDmaStream7Sr(DMA1);

        clrDmaStream7Sr(DMA1, sr);

        if (checkError(sr))
            dma1Stream7.setError();

        if (dma1Stream7.mRemainSize)
        {
            dma1Stream7.mAddr += 0xF000;
            if (dma1Stream7.mRemainSize > 0xF000)
            {
                DMA1_Stream7->NDTR = 0xF000;
                dma1Stream7.mRemainSize -= 0xF000;
            }
            else
            {
                DMA1_Stream7->NDTR = dma1Stream7.mRemainSize;
                dma1Stream7.mRemainSize = 0;
            }
            DMA1_Stream7->M0AR = dma1Stream7.mAddr;
            DMA1_Stream7->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma1Stream7.setComplete();
    }
#endif
#if defined(DMA2_STREAM0_ENABLE) && defined(DMA2_Stream0)
    void DMA2_Stream0_IRQHandler(void)
    {
        unsigned long sr = getDmaStream0Sr(DMA2);

        clrDmaStream0Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream0.setError();

        if (dma2Stream0.mRemainSize)
        {
            dma2Stream0.mAddr += 0xF000;
            if (dma2Stream0.mRemainSize > 0xF000)
            {
                DMA2_Stream0->NDTR = 0xF000;
                dma2Stream0.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream0->NDTR = dma2Stream0.mRemainSize;
                dma2Stream0.mRemainSize = 0;
            }
            DMA2_Stream0->M0AR = dma2Stream0.mAddr;
            DMA2_Stream0->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream0.setComplete();
    }
#endif
#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2_Stream1)
    void DMA2_Stream1_IRQHandler(void)
    {
        unsigned long sr = getDmaStream1Sr(DMA2);

        clrDmaStream1Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream1.setError();

        if (dma2Stream1.mRemainSize)
        {
            dma2Stream1.mAddr += 0xF000;
            if (dma2Stream1.mRemainSize > 0xF000)
            {
                DMA2_Stream1->NDTR = 0xF000;
                dma2Stream1.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream1->NDTR = dma2Stream1.mRemainSize;
                dma2Stream1.mRemainSize = 0;
            }
            DMA2_Stream1->M0AR = dma2Stream1.mAddr;
            DMA2_Stream1->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream1.setComplete();
    }
#endif
#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2_Stream2)
    void DMA2_Stream2_IRQHandler(void)
    {
        unsigned long sr = getDmaStream2Sr(DMA2);

        clrDmaStream2Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream2.setError();

        if (dma2Stream2.mRemainSize)
        {
            dma2Stream2.mAddr += 0xF000;
            if (dma2Stream2.mRemainSize > 0xF000)
            {
                DMA2_Stream2->NDTR = 0xF000;
                dma2Stream2.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream2->NDTR = dma2Stream2.mRemainSize;
                dma2Stream2.mRemainSize = 0;
            }
            DMA2_Stream2->M0AR = dma2Stream2.mAddr;
            DMA2_Stream2->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream2.setComplete();
    }
#endif
#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2_Stream3)
    void DMA2_Stream3_IRQHandler(void)
    {
        unsigned long sr = getDmaStream3Sr(DMA2);

        clrDmaStream3Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream3.setError();

        if (dma2Stream3.mRemainSize)
        {
            dma2Stream3.mAddr += 0xF000;
            if (dma2Stream3.mRemainSize > 0xF000)
            {
                DMA2_Stream3->NDTR = 0xF000;
                dma2Stream3.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream3->NDTR = dma2Stream3.mRemainSize;
                dma2Stream3.mRemainSize = 0;
            }
            DMA2_Stream3->M0AR = dma2Stream3.mAddr;
            DMA2_Stream3->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream3.setComplete();
    }
#endif
#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Stream4)
    void DMA2_Stream4_IRQHandler(void)
    {
        unsigned long sr = getDmaStream4Sr(DMA2);

        clrDmaStream4Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream4.setError();

        if (dma2Stream4.mRemainSize)
        {
            dma2Stream4.mAddr += 0xF000;
            if (dma2Stream4.mRemainSize > 0xF000)
            {
                DMA2_Stream4->NDTR = 0xF000;
                dma2Stream4.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream4->NDTR = dma2Stream4.mRemainSize;
                dma2Stream4.mRemainSize = 0;
            }
            DMA2_Stream4->M0AR = dma2Stream4.mAddr;
            DMA2_Stream4->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream4.setComplete();
    }
#endif
#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Stream5)
    void DMA2_Stream5_IRQHandler(void)
    {
        unsigned long sr = getDmaStream5Sr(DMA2);

        clrDmaStream5Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream5.setError();

        if (dma2Stream5.mRemainSize)
        {
            dma2Stream5.mAddr += 0xF000;
            if (dma2Stream5.mRemainSize > 0xF000)
            {
                DMA2_Stream5->NDTR = 0xF000;
                dma2Stream5.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream5->NDTR = dma2Stream5.mRemainSize;
                dma2Stream5.mRemainSize = 0;
            }
            DMA2_Stream5->M0AR = dma2Stream5.mAddr;
            DMA2_Stream5->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream5.setComplete();
    }
#endif
#if defined(DMA2_STREAM6_ENABLE) && defined(DMA2_Stream6)
    void DMA2_Stream6_IRQHandler(void)
    {
        unsigned long sr = getDmaStream6Sr(DMA2);

        clrDmaStream6Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream6.setError();

        if (dma2Stream6.mRemainSize)
        {
            dma2Stream6.mAddr += 0xF000;
            if (dma2Stream6.mRemainSize > 0xF000)
            {
                DMA2_Stream6->NDTR = 0xF000;
                dma2Stream6.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream6->NDTR = dma2Stream6.mRemainSize;
                dma2Stream6.mRemainSize = 0;
            }
            DMA2_Stream6->M0AR = dma2Stream6.mAddr;
            DMA2_Stream6->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream6.setComplete();
    }
#endif
#if defined(DMA2_STREAM7_ENABLE) && defined(DMA2_Stream7)
    void DMA2_Stream7_IRQHandler(void)
    {
        unsigned long sr = getDmaStream7Sr(DMA2);

        clrDmaStream7Sr(DMA2, sr);

        if (checkError(sr))
            dma2Stream7.setError();

        if (dma2Stream7.mRemainSize)
        {
            dma2Stream7.mAddr += 0xF000;
            if (dma2Stream7.mRemainSize > 0xF000)
            {
                DMA2_Stream7->NDTR = 0xF000;
                dma2Stream7.mRemainSize -= 0xF000;
            }
            else
            {
                DMA2_Stream7->NDTR = dma2Stream7.mRemainSize;
                dma2Stream7.mRemainSize = 0;
            }
            DMA2_Stream7->M0AR = dma2Stream7.mAddr;
            DMA2_Stream7->CR |= DMA_SxCR_EN_Msk;
        }
        else if (checkComplete(sr))
            dma2Stream7.setComplete();
    }
#endif
}

#endif