/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_FLASH_STM32F1_F4_F7__H_
#define YSS_CLASS_FLASH_STM32F1_F4_F7__H_

#include <yss/error.h>
#include <drv/mcu.h>

class Flash
{
public:

	void erase(uint16_t sector);

	void *program(void *des, void *src, uint32_t size);

	void *program(uint32_t sector, void *src, uint32_t size);

	uint32_t getAddress(uint16_t sector);

	void enablePrefetch(bool en = true);

#if defined(STM32F4) || defined(STM32F7)
	void setLatency(uint32_t frequency, uint8_t vcc);

	void enableDataCache(bool en = true);

	void enableInstructionCache(bool en = true);
#elif defined(STM32F1) || defined(STM32F0) || defined(GD32F1)
	void setLatency(uint32_t frequency);

	void setPrefetchEn(bool en);

	void setHalfCycleAccessEn(bool en);
#elif defined(STM32F0)
	void setLatency(uint32_t frequency);

	void setPrefetchEn(bool en);
#endif

#if defined(STM32F767xx)
	void setBank(uint8_t bank);
#endif

#if defined(STM32F7)
	void enableArtAccelerator(bool en = true);
#endif
};

#endif