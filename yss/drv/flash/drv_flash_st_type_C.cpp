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

#if	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <drv/peripherals.h>
#include <drv/flash/drv_st_flash_type_C_register.h>

#if defined(FLASH)
drv::Flash flash;
#endif

struct OptionBytes2
{
	unsigned reserved0 : 16;
	unsigned sprmod : 1;
	unsigned db1m : 1;
	unsigned reserved1 : 2;
	unsigned nwrp : 12;
};

namespace drv
{
	const OptionBytes2 *gOptionByte2 = (OptionBytes2*)(0x1FFFC008);

	void Flash::setLatency(unsigned long freq, unsigned char vcc)
	{
		unsigned long div, wait;

		if(vcc > 27)
		{
			div = 30;
		}
		else if(vcc	> 24)
		{
			div = 24;
		}
		else if(vcc	> 21)
		{
			div = 22;
		}
		else
		{
			div = 20;
		}

		freq /= 1000000;
		wait = freq / div;
		if(!(freq % div))
			wait--;

		setFlashLatency(wait);
	}

	void Flash::setPrefetchEn(bool en)
	{
		setFlashPrefetchEn(en);
	}

	void Flash::setDCacheEn(bool en)
	{
		if(en)
			FLASH->ACR |= FLASH_ACR_DCEN_Msk;
		else
			FLASH->ACR &= ~FLASH_ACR_DCEN_Msk;
	}

	void Flash::setICacheEn(bool en)
	{
		if(en)
			FLASH->ACR |= FLASH_ACR_ICEN_Msk;
		else
			FLASH->ACR &= ~FLASH_ACR_ICEN_Msk;
	}

	static const unsigned int g1MFlashSingleBankAddrTable[12] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x08080000, 0x080A0000,
		0x080C0000, 0x080E0000
	};

	static const unsigned int g1MFlashDualBankAddrTable[20] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x08080000, 0x08084000, 0x08088000, 
		0x0808C000, 0x08090000, 0x080A0000, 0x080C0000, 0x080E0000
	};

	static const unsigned int g2MFlashDualBankAddrTable[24] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x08080000, 0x080A0000,
		0x080C0000, 0x080E0000, 0x08100000, 0x08104000, 0x08108000, 
		0x0810C000, 0x08110000, 0x08120000, 0x08140000, 0x08160000,
		0x08180000, 0x081A0000, 0x081C0000, 0x081E0000
	};

	unsigned int Flash::getAddress(unsigned short sector)
	{
		unsigned short size = *(unsigned short*)FLASHSIZE_BASE / 1024;

		switch(size)
		{
		case 1 :
			if(gOptionByte2->db1m)
			{
				if(sector > 19)
					sector = 19;
				return g1MFlashDualBankAddrTable[sector];
			}
			else
			{
				if(sector > 11)
					sector = 11;
				return g1MFlashSingleBankAddrTable[sector];
			}
			break;
		case 2 :
			if(sector > 23)
				sector = 23;
			return g2MFlashDualBankAddrTable[sector];
			break;
		}
	
		return 0;
	}

	void Flash::erase(unsigned short sector)
	{
		unsigned int cr;		

		if(sector >= 12)
		{
			sector -= 12;
			sector |= 0x10;
		}

		FLASH->SR = 0XFFFF;

		while(FLASH->SR & FLASH_SR_BSY_Msk)
			thread::yield();

		FLASH->KEYR = 0x45670123;
		FLASH->KEYR = 0xCDEF89AB;

		while(FLASH->CR & FLASH_CR_LOCK_Msk)
			thread::yield();

		FLASH->CR = FLASH_CR_SER_Msk | FLASH_CR_STRT_Msk | (sector << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk;

		__NOP();
		__NOP();
		while(FLASH->SR & FLASH_SR_BSY_Msk && (FLASH->SR & ~FLASH_SR_BSY_Msk == 0))
			thread::yield();

		FLASH->CR = FLASH_CR_LOCK_Msk;
	}

	void* Flash::program(unsigned int sector, void *src, unsigned int size)
	{
		unsigned char *cdes = (unsigned char*)getAddress(sector), *csrc = (unsigned char*)src;
		FLASH->SR = 0XFFFF;

		while(FLASH->SR & FLASH_SR_BSY_Msk)
			thread::yield();

		FLASH->KEYR = 0x45670123;
		FLASH->KEYR = 0xCDEF89AB;

		while(FLASH->CR & FLASH_CR_LOCK_Msk)
			thread::yield();

		FLASH->CR = FLASH_CR_PG_Msk;

		for(unsigned int i=0;i<size;i++)
		{
			__NOP();
			__NOP();
			*cdes++ = *csrc++;
			while(FLASH->SR & FLASH_SR_BSY_Msk)
				thread::yield();

			if(FLASH->SR & ~FLASH_SR_BSY_Msk)
				return (void*)cdes;
		}

		FLASH->CR = FLASH_CR_LOCK_Msk;

		return (void*)cdes;
	}

	void* Flash::program(void *des, void *src, unsigned int size)
	{
		unsigned char *cdes = (unsigned char*)des, *csrc = (unsigned char*)src;
		FLASH->SR = 0XFFFF;

		while(FLASH->SR & FLASH_SR_BSY_Msk)
			thread::yield();

		FLASH->KEYR = 0x45670123;
		FLASH->KEYR = 0xCDEF89AB;

		while(FLASH->CR & FLASH_CR_LOCK_Msk)
			thread::yield();

		FLASH->CR = FLASH_CR_PG_Msk;

		for(unsigned int i=0;i<size;i++)
		{
			__NOP();
			__NOP();
			*cdes++ = *csrc++;
			while(FLASH->SR & FLASH_SR_BSY_Msk)
				thread::yield();

			if(FLASH->SR & ~FLASH_SR_BSY_Msk)
				return (void*)cdes;
		}

		FLASH->CR = FLASH_CR_LOCK_Msk;

		return (void*)cdes;
	}
}
#endif
