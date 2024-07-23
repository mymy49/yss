/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV__H_
#define YSS_DRV__H_

#include <yss/Mutex.h>
#include <drv/mcu.h>

class Dma;

class Drv : public Mutex
{
  public:
	// 앞으로 Config 대신에 Setup을 사용할 예정
	struct setup_t
	{
		void (*clockFunc)(bool en);
		void (*nvicFunc)(bool en);
		void (*resetFunc)(void);
		uint32_t (*getClockFunc)(void);
	};

	void enableClock(bool en = true);

	void enableInterrupt(bool en = true);

	void reset(void);

	uint32_t getClockFrequency(void);

#if defined(YSS__UART_RX_DMA)
	Dma* getOccupancyDma(void);

	Dma* getIdleDma(void);
#endif
	
	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	Drv(void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void) = 0);

	Drv(const setup_t &setup);

	Drv(void);

private :
	void (*mClockFunc)(bool en);
	void (*mNvicFunc)(bool en);
	void (*mResetFunc)(void);
	uint32_t (*mGetClockFunc)(void);
};

#endif

