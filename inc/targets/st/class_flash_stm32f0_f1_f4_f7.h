////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CLASS_FLASH_STM32F1_F4_F7__H_
#define YSS_CLASS_FLASH_STM32F1_F4_F7__H_

#include <yss/error.h>
#include <drv/mcu.h>

class Flash : public FlashBase
{
public:

	void erase(uint16_t sector);

	void *program(void *des, void *src, uint32_t size);

	void *program(uint32_t sector, void *src, uint32_t size);

	uint32_t getAddress(uint16_t sector);

	void enablePrefetch(bool en = true);

#if defined(STM32F4_N) || defined(STM32F7_N)
	void setLatency(uint32_t frequency, uint8_t vcc);

	void enableDataCache(bool en = true);

	void enableInstructionCache(bool en = true);
#elif defined(STM32F1_N) || defined(STM32F0_N) || defined(GD32F1)
	void setLatency(uint32_t frequency);

	void setPrefetchEn(bool en);

	void setHalfCycleAccessEn(bool en);
#elif defined(STM32F0_N)
	void setLatency(uint32_t frequency);

	void setPrefetchEn(bool en);
#endif

#if defined(STM32F767xx)
	void setBank(uint8_t bank);
#endif

#if defined(STM32F7_N)
	void enableArtAccelerator(bool en = true);
#endif
};

#endif