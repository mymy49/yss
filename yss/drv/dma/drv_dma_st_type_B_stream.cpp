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
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <drv/dma/drv_st_dma_type_B.h>
#include <drv/dma/drv_st_dma_type_B_register.h>
#include <util/time.h>

namespace drv
{
Stream::Stream(DMA_TypeDef *dma, DMA_Channel_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char ch) : Drv(clockFunc, nvicFunc)
{
    mDma = dma;
    mPeri = peri;
}

void Stream::init(void)
{
    setDmaStreamTcie(mPeri, true);
    setDmaStreamTeie(mPeri, true);
}

bool Stream::send(sac::Comm *obj, void *src, unsigned long size, unsigned long timeout)
{
    unsigned long long endTime;

    mMutex.lock();
    mCompleteFlag = false;
    mErrorFlag = false;

    sac::DmaInfo *info = obj->getDmaInfo();

    setDmaStreamPar(mPeri, (unsigned long)(info->txDr));
    setDmaStreamDir(mPeri, define::dma::dir::MEM_TO_PERI);
    setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
    setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
    setDmaStreamMsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPriorityLevel(mPeri, info->priority);
    setDmaStreamMar(mPeri, (unsigned long)src);
    setDmaStreamNdtr(mPeri, size);
    setDmaStreamEn(mPeri, true);

    endTime = time::getRunningMsec() + timeout;
    while (!mCompleteFlag && !mErrorFlag)
    {
        if (endTime <= time::getRunningMsec())
        {
            setDmaStreamEn(mPeri, false);
            mMutex.unlock();
            return false;
        }
        thread::switchContext();
    }

    setDmaStreamEn(mPeri, false);
    mMutex.unlock();

    if (mErrorFlag)
        return false;
    else
        return true;
}

void Stream::pendTx(sac::Comm *obj, void *src, unsigned long size)
{
    mMutex.lock();
    mCompleteFlag = false;
    mErrorFlag = false;

    sac::DmaInfo *info = obj->getDmaInfo();

    setDmaStreamPar(mPeri, (unsigned long)(info->txDr));
    setDmaStreamDir(mPeri, define::dma::dir::MEM_TO_PERI);
    setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
    setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
    setDmaStreamMsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPriorityLevel(mPeri, info->priority);
    setDmaStreamMar(mPeri, (unsigned long)src);
    setDmaStreamNdtr(mPeri, size);
    setDmaStreamEn(mPeri, true);
}

void Stream::pendRx(sac::Comm *obj, void *des, unsigned long size)
{
    mMutex.lock();
    mCompleteFlag = false;
    mErrorFlag = false;

    sac::DmaInfo *info = obj->getDmaInfo();

    setDmaStreamPar(mPeri, (unsigned long)(info->rxDr));
    setDmaStreamDir(mPeri, define::dma::dir::PERI_TO_MEM);
    setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
    setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
    setDmaStreamMsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPriorityLevel(mPeri, info->priority);
    setDmaStreamMar(mPeri, (unsigned long)des);
    setDmaStreamNdtr(mPeri, size);
    setDmaStreamEn(mPeri, true);
}

void Stream::stop(void)
{
    setDmaStreamEn(mPeri, false);
    mMutex.unlock();
}

bool Stream::wait(unsigned long long timeout)
{
    unsigned long long endTime = time::getRunningMsec() + timeout;
    while (!mCompleteFlag && !mErrorFlag)
    {
        if (endTime <= time::getRunningMsec())
        {
            setDmaStreamEn(mPeri, false);
            mMutex.unlock();
            return false;
        }
        thread::switchContext();
    }

    setDmaStreamEn(mPeri, false);
    mMutex.unlock();

    if (mErrorFlag)
        return false;
    else
        return true;
}

bool Stream::receive(sac::Comm *obj, void *des, unsigned long size, unsigned long timeout)
{
    unsigned long long endTime;

    mMutex.lock();
    mCompleteFlag = false;
    mErrorFlag = false;

    sac::DmaInfo *info = obj->getDmaInfo();

    setDmaStreamPar(mPeri, (unsigned long)(info->rxDr));
    setDmaStreamDir(mPeri, define::dma::dir::PERI_TO_MEM);
    setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
    setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
    setDmaStreamMsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPsize(mPeri, define::dma::size::BYTE);
    setDmaStreamPriorityLevel(mPeri, info->priority);
    setDmaStreamMar(mPeri, (unsigned long)des);
    setDmaStreamNdtr(mPeri, size);
    setDmaStreamEn(mPeri, true);

    endTime = time::getRunningMsec() + timeout;
    while (!mCompleteFlag && !mErrorFlag)
    {
        if (endTime <= time::getRunningMsec())
        {
            setDmaStreamEn(mPeri, false);
            mMutex.unlock();
            return false;
        }
        thread::switchContext();
    }

    mMutex.unlock();
    return true;
}

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

void Stream::isr1(void)
{
    unsigned long sr = getDmaStream1Sr(mDma);
    clrDmaStream1Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr2(void)
{
    unsigned long sr = getDmaStream2Sr(mDma);
    clrDmaStream2Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr3(void)
{
    unsigned long sr = getDmaStream3Sr(mDma);
    clrDmaStream3Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr4(void)
{
    unsigned long sr = getDmaStream4Sr(mDma);
    clrDmaStream4Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr5(void)
{
    unsigned long sr = getDmaStream5Sr(mDma);
    clrDmaStream5Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr6(void)
{
    unsigned long sr = getDmaStream6Sr(mDma);
    clrDmaStream6Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

void Stream::isr7(void)
{
    unsigned long sr = getDmaStream7Sr(mDma);
    clrDmaStream7Sr(mDma, sr);
    if (checkError(sr))
        mErrorFlag = true;
    if (checkComplete(sr))
        mCompleteFlag = true;
}

}

#endif