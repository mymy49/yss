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

#include <drv/mcu.h>

#if defined(GD32F10X_XD)

#include <drv/peripheral.h>
#include <drv/Flash.h>
#include <yss/thread.h>
#include <yss/reg.h>

namespace drv
{
Flash::Flash(void) : Drv(0, 0)
{
}

void Flash::setLatency(unsigned int freq)
{
}

void Flash::setPrefetchEn(bool en)
{
}

void Flash::setHalfCycleAccessEn(bool en)
{
}

#define FLASHSIZE_BASE 0x1FFFF7E0UL

unsigned int Flash::getAddress(unsigned short sector)
{
	unsigned int size;
	unsigned int addr = (unsigned int)FLASH_BASE;
	
#if defined(GD32F10X_MD)
	if(sector > = max)
		return 0;
	addr += sector * 1024;
#elif defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
//	max = FLASH_BASE + max * 1024;
	if(sector >= 256)
	{
		addr += 256 * 2048;
		sector -= 256;
		addr += sector * 4096;
	}
	else
	{
		addr += sector * 2048;
	}
#else
	return 0;
#endif
	return addr;
}

void Flash::erase(unsigned short sector)
{
	unsigned int addr = getAddress(sector);

#if defined(GD32F10X_MD)
	while (getFlashBusy())
		thread::yield();
#elif defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	while (getBitData(FMC->CSR, 0) || getBitData(FMC->CSR2, 0))
		thread::yield();
#endif

	if (sector < 256)
	{
		if (getRegBit(FMC->CMR, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR = 0x45670123;
			FMC->UKEYR = 0xCDEF89AB;
		}
		
		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR, 7))
			thread::yield();
		
		// 지우기
		setBitData(FMC->CMR, true, 1);
		FMC->AR = addr;
		setBitData(FMC->CMR, true, 6);

		__NOP();
		__NOP();
		while (getBitData(FMC->CSR, 0))
			;

		__NOP();
		__NOP();
		setBitData(FMC->CMR, false, 1);	// 지우기 해제
		setBitData(FMC->CMR, false, 7);	// 잠금
	}
#if defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	else
	{
		if (getRegBit(FMC->CMR2, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR2 = 0x45670123;
			FMC->UKEYR2 = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR2, 7))
			thread::yield();

		// 지우기
		setBitData(FMC->CMR2, true, 1);
		FMC->AR2 = addr;
		setBitData(FMC->CMR2, true, 6);

		__NOP();
		__NOP();
		while (getBitData(FMC->CSR2, 0))
			;

		__NOP();
		__NOP();
		setBitData(FMC->CMR2, false, 1);	// 지우기 해제
		setBitData(FMC->CMR2, false, 7);	// 잠금
	}
#endif
}

void *Flash::program(unsigned int sector, void *src, unsigned int size)
{
	unsigned short *addr = (unsigned short*)getAddress(sector);
	unsigned int temp;

	size += 1;
	size >>= 1;

#if defined(GD32F10X_MD)
	while (getBitData(FMC->CSR, 0))
		thread::yield();
#elif defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	while (getBitData(FMC->CSR, 0) || getBitData(FMC->CSR2, 0))
		thread::yield();
#endif

	if (sector < 256)
	{
		if (getRegBit(FMC->CMR, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR = 0x45670123;
			FMC->UKEYR = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR, 7))
			thread::yield();

		setBitData(FMC->CMR, true, 0);	// 쓰기 설정

		__NOP();
		__NOP();
		for (unsigned int i = 0; i < size; i++)
		{
			addr[i] = ((unsigned short *)src)[i];
			__NOP();
			__NOP();
			while (getBitData(FMC->CSR, 0))
				;
		}

		__NOP();
		__NOP();
		setBitData(FMC->CMR, false, 0);	// 쓰기 해제
		setBitData(FMC->CMR, false, 7);	// 잠금
	}
#if defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	else
	{
		if (getRegBit(FMC->CMR2, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR2 = 0x45670123;
			FMC->UKEYR2 = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR2, 7))
			thread::yield();

		setBitData(FMC->CMR2, true, 0);	// 쓰기 설정

		__NOP();
		__NOP();
		for (unsigned int i = 0; i < size; i++)
		{
			addr[i] = ((unsigned short *)src)[i];
			__NOP();
			__NOP();
			while (getBitData(FMC->CSR2, 0))
				;
		}

		__NOP();
		__NOP();
		setBitData(FMC->CMR2, false, 0);	// 쓰기 해제
		setBitData(FMC->CMR2, false, 7);	// 잠금
	}
#endif
	return &addr[size];
}

void *Flash::program(void *des, void *src, unsigned int size)
{
	unsigned short *addr = (unsigned short *)des;

	size += 1;
	size >>= 1;

#if defined(GD32F10X_MD)
	while (getBitData(FMC->CSR, 0))
		thread::yield();
#elif defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	while (getBitData(FMC->CSR, 0) || getBitData(FMC->CSR2, 0))
		thread::yield();
#endif

	if ((int)des < 0x08080000)
	{
		if (getRegBit(FMC->CMR, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR = 0x45670123;
			FMC->UKEYR = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR, 7))
			thread::yield();

		setBitData(FMC->CMR, true, 0);	// 쓰기 설정

		__NOP();
		__NOP();
		for (unsigned int i = 0; i < size; i++)
		{
			addr[i] = ((unsigned short *)src)[i];
			__NOP();
			__NOP();
			while (getBitData(FMC->CSR, 0))
				;
		}

		__NOP();
		__NOP();
		setBitData(FMC->CMR, false, 0);	// 쓰기 해제
		setBitData(FMC->CMR, false, 7);	// 잠금
	}
#if defined(GD32F10X_XD) || defined(GD32F10X_CL) || defined(GD32F10X_HD)
	else
	{
		if (getRegBit(FMC->CMR2, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FMC->UKEYR2 = 0x45670123;
			FMC->UKEYR2 = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(FMC->CMR2, 7))
			thread::yield();

		setBitData(FMC->CMR2, true, 0);	// 쓰기 설정

		__NOP();
		__NOP();
		for (unsigned int i = 0; i < size; i++)
		{
			addr[i] = ((unsigned short *)src)[i];
			__NOP();
			__NOP();
			while (getBitData(FMC->CSR2, 0))
				;
		}

		__NOP();
		__NOP();
		setBitData(FMC->CMR2, false, 0);	// 쓰기 해제
		setBitData(FMC->CMR2, false, 7);	// 잠금
	}
#endif
	return &addr[size];
}
}
#endif