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

#ifndef YSS_SAC_TFT_LCD_DRIVER__H_
#define YSS_SAC_TFT_LCD_DRIVER__H_

#include <yss/error.h>
#include <stdint.h>
#include <yss/Mutex.h>

// TFT LCD 드라이버가 통신 채널(I2C, SPI 등)을 통해 설정이 가능한 경우
// 이 class를 상속 받고 아래 기능들을 반드시 구현 해야한다.
class TftLcdDriver : public Mutex
{
public:
	virtual error initialize(void) = 0;

	virtual void reset(void) = 0;

	virtual bool getReverseRgbOrder(void);

	virtual bool getReverseEndian(void);

protected:
	virtual void sendCmd(uint8_t cmd) = 0;

	virtual void sendCmd(uint8_t cmd, void *data, uint32_t len) = 0;

	virtual void enable(void) = 0;

	virtual void disable(void) = 0;

private:
};

#endif