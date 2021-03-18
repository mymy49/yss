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

#if defined(STM32F746xx) || defined(STM32F745xx) || \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)

#include <drv/flash/drv_st_flash_type_A.h>
#include <drv/flash/drv_st_flash_type_A_register.h>
#include <yss/thread.h>

namespace drv
{
Flash::Flash(void) : Drv(0, 0)
{
}

void Flash::setPrefetchEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_PRFTEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_PRFTEN_Msk;
}

void Flash::setArtEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_ARTEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_ARTEN_Msk;
}

static const unsigned int gFlashAddrTable[8] =
    {
        0x08000000, 0x08008000, 0x08010000, 0x08018000, 0x08020000,
        0x08040000, 0x08080000, 0x080C0000};

unsigned int Flash::getAddress(unsigned short sector)
{
    return gFlashAddrTable[sector];
}

void Flash::erase(unsigned char sector)
{
    while (getFlashBusy())
        ;

    if (getFlashLock())
    {
        setFlashKey(0x45670123);
        setFlashKey(0xcdef89ab);
    }

    while (getFlashLock())
        ;

    setFlashSectorErase(true);
    setFlashSectorNumber(sector);
    setFlashEraseStart();

    __NOP();
    __NOP();
    while (getFlashBusy())
        ;

    setFlashSectorErase(false);
    setFlashLock();
}

void Flash::program(void *des, void *src, unsigned int size)
{
    unsigned int *cdes = (unsigned int *)des, *csrc = (unsigned int *)src;

    size += 3;
    size >>= 2;

    while (getFlashBusy())
        thread::yield();

    if (getFlashLock())
    {
        setFlashKey(0x45670123);
        setFlashKey(0xcdef89ab);
    }

    while (getFlashLock())
        thread::yield();

    setFlashProgramSize(2);
    setFlashProgramming(true);

    for (unsigned int i = 0; i < size; i++)
    {
        __NOP();
        __NOP();
        cdes[i] = csrc[i];
        thread::yield();
        while (getFlashBusy())
            ;
    }

    setFlashProgramming(false);
    setFlashLock();
}

void Flash::program(unsigned int sector, unsigned int *src, unsigned int size)
{
    program((void *)getAddress(sector), src, size);
}
}
#endif