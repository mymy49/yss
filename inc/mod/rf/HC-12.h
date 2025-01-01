/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_RF_HC_12__H_
#define YSS_MOD_RF_HC_12__H_

#include <yss/instance.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

// 일시적으로 지원을 중단합니다.

/*
namespace mod
{
namespace rf
{
class HC_12 : private Mutex
{
  private:
	Uart *mPeri;
	pin_t mSet;

	bool checkOk(int8_t *src, uint8_t len);

  public:
	struct Config
	{
		Uart &peri;
		pin_t set;
	};

	enum
	{
		BAUD_1200,
		BAUD_2400,
		BAUD_4800,
		BAUD_9600,
		BAUD_19200,
		BAUD_38400,
		BAUD_57600,
		BAUD_115200,
	};

	HC_12(void);
	bool initialize(Config config);
	bool send(void *src, uint32_t size);
	int8_t getWaitUntilReceive(void);
	int16_t getRxByte(void);
	bool setBaudrate(uint8_t baud);
	bool setChannel(uint8_t channel);
	bool setFU(uint8_t fu);
	bool setTransmittingPower(uint8_t power);
};
}
}
*/
#endif

#endif
