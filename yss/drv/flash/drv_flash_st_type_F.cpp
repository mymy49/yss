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

#if defined(STM32L412xx) || defined(STM32L422xx) ||                                                                       \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) || \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                 \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                         \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                         \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#include <config.h>
#include <drv/peripherals.h>

#if defined(FLASH)
drv::Flash flash(0, 0);
#endif

namespace drv
{
Flash::Flash(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}
void Flash::setLatency(unsigned int freq)
{
    unsigned char range = clock.getVosRange();
	unsigned int div, ws, reg;

    switch (range)
    {
    case 1: // range 1
		div = 16000000;
        break;
    case 2: // range 2
		div = 6000000;
        break;
    }
	
	ws = freq / div;
	if(freq % div == 0)
		ws--;
	
	reg = FLASH->ACR;
	reg &= ~FLASH_ACR_LATENCY_Msk;
	reg |= ws << FLASH_ACR_LATENCY_Pos;
	FLASH->ACR = reg;
}

void Flash::setPrefetchEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_PRFTEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_PRFTEN_Msk;
}

void Flash::setICacheEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_ICEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_ICEN_Msk;
}

/*

void Flash::setPreReadEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_PRE_READ_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_PRE_READ_Msk;
}

/*
	void Flash::setHalfCycleAccessEn(bool en)
	{
		setFlashHlfcyaEn(en);
	}

	void Flash::erase(unsigned short sector)
	{
		unsigned int addr;
	
		addr = sector;
#if defined(STM32F10X_XL) || defined(STM32F10X_HD)
		addr *= 2048;
#else
		addr *= 1024;
#endif
		addr += 0x08000000;

#if defined(STM32F10X_XL)
		while(getFlashBusy() || getFlashBusy2())
			thread::yield();
#else
		while(getFlashBusy())
			thread::yield();
#endif

		if(sector < 256)
		{
			if(getFlashLock())
			{
				setFlashKey(0x45670123);
				setFlashKey(0xcdef89ab);
			}

			while(getFlashLock())
				thread::yield();

			setFlashSectorErase(true);
			setFlashSectorNumber(addr);
			setFlashEraseStart();

			__NOP();
			__NOP();
			while(getFlashBusy());

			__NOP();
			__NOP();
			setFlashSectorErase(false);
			setFlashLock();
		}
#if defined(STM32F10X_XL)
		else
		{
			if(getFlashLock2())
			{
				setFlashKey2(0x45670123);
				setFlashKey2(0xcdef89ab);
			}

			while(getFlashLock2())
				thread::yield();

			setFlashSectorErase2(true);
			setFlashSectorNumber2(addr);
			setFlashEraseStart2();

			__NOP();
			__NOP();
			while(getFlashBusy2());

			__NOP();
			__NOP();
			setFlashSectorErase2(false);
			setFlashLock2();
		}
#endif
	}

	void Flash::program(unsigned int sector, void *src, unsigned int size)
	{
		unsigned short *addr;
		unsigned int temp;
	
		temp = sector;
#if defined(STM32F10X_XL) || defined(STM32F10X_HD)
		temp *= 2048;
#else
		temp *= 1024;
#endif
		temp += 0x08000000;

		addr = (unsigned short*)temp;

		size += 1;
		size >>= 1;

#if defined(STM32F10X_XL)
		while(getFlashBusy() || getFlashBusy2())
			thread::yield();
#else
		while(getFlashBusy())
			thread::yield();
#endif

		if(sector < 256)
		{
			if(getFlashLock())
			{
				setFlashKey(0x45670123);
				setFlashKey(0xcdef89ab);
			}

			while(getFlashLock())
				thread::yield();

			setFlashProgramming(true);

			__NOP();
			__NOP();
			for(unsigned long i=0;i<size;i++)
			{
				addr[i] = ((unsigned short*)src)[i];
				__NOP();
				__NOP();
				while(getFlashBusy());
			}

			__NOP();
			__NOP();
			setFlashProgramming(false);
			setFlashLock();
		}
#if defined(STM32F10X_XL)
		else
		{
			if(getFlashLock2())
			{
				setFlashKey2(0x45670123);
				setFlashKey2(0xcdef89ab);
			}

			while(getFlashLock2())
				thread::yield();

			setFlashProgramming2(true);

			__NOP();
			__NOP();
			for(unsigned long i=0;i<size;i++)
			{
				addr[i] = ((unsigned short*)src)[i];
				__NOP();
				__NOP();
				while(getFlashBusy2());
			}

			__NOP();
			__NOP();
			setFlashProgramming2(false);
			setFlashLock2();
		}
#endif
	}
*/
}
#endif