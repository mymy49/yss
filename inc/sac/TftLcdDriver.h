/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_TFT_LCD_DRIVER__H_
#define YSS_SAC_TFT_LCD_DRIVER__H_

#include <yss/error.h>
#include <stdint.h>
#include <yss/Mutex.h>
#include <gui/util.h>

// TFT LCD 드라이버가 통신 채널(I2C, SPI 등)을 통해 설정이 가능한 경우
// 이 class를 상속 받고 아래 기능들을 반드시 구현 해야한다.
class TftLcdDriver : public Mutex
{
public:
	virtual error_t initialize(void) = 0;

	virtual void reset(void) = 0;

	virtual Size_t getLcdSize(void) = 0;

	virtual void updateLcdSize(void) = 0;

	virtual bool getReverseRgbOrder(void);

	virtual bool getReverseEndian(void);

protected:
	virtual void sendCmd(uint8_t cmd) = 0;

	virtual void sendCmd(uint8_t cmd, uint8_t data) = 0;

	virtual void sendCmd(uint8_t cmd, void *data, uint32_t len) = 0;

	virtual void enable(void) = 0;

	virtual void disable(void) = 0;

private:
};

#endif