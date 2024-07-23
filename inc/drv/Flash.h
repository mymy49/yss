/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_FLASH__H_
#define YSS_DRV_FLASH__H_

#include "mcu.h"

#if defined(STM32F4) || defined(STM32F1) || defined(STM32F7) || defined (STM32F0) || defined(GD32F1)

#define FlashTargetHeaderFile	<targets/st/class_flash_stm32f0_f1_f4_f7.h>

#elif defined(STM32G4)

class Flash
{
public:
#if defined(STM32G4)
	// 데이터 캐쉬를 활성화 합니다.
	//
	// bool en
	//		데이터 캐쉬 활성화 상태 설정 (true 활성화/false 비활성화)
	void enableDataCache(bool en = true);
#endif	

#if defined(STM32G4)
	// 코드 캐쉬를 활성화 합니다.
	//
	// bool en
	//		코드 캐쉬 활성화 상태 설정 (true 활성화/false 비활성화)
	void enableInstructionCache(bool en = true);
#endif	

#if defined(STM32G4)
	// Prefetch를 활성화 합니다.
	//
	// bool en
	//		Prefetch 활성화 상태 설정 (true 활성화/false 비활성화)
	void enablePrefetch(bool en = true);
#endif		
};

#else

#define YSS_DRV_FLASH_UNSUPPORTED

#endif

#include "Drv.h"

#if !defined(STM32G4)
class FlashBase : public Drv
{
  public:
	// 아래 멤버 함수들을 상속 받는 곳에서 다시 선언하고 구현해야함

	void erase(uint16_t sector);

	void *program(void *des, void *src, uint32_t size);

	void *program(uint32_t sector, void *src, uint32_t size);

	uint32_t getAddress(uint16_t sector);
};

#if !defined(YSS_DRV_FLASH_UNSUPPORTED)
#include FlashTargetHeaderFile
#endif
#endif

#endif

