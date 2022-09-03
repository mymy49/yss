////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef	YSS_SAC_RTOUCH__H_
#define	YSS_SAC_RTOUCH__H_

#include <gui/util.h>

namespace sac
{
	class Rtouch
	{
		Position calculate(uint16_t x, uint16_t y);
	protected :
		int32_t mP1X, mP1Y, mP2X, mP2Y, mWidth, mHeight;
		bool mInitFlag;
	public :
		Rtouch(void);
		void setCalibration(int32_t p1X, int32_t p1y, int32_t p2x, int32_t p2y);
		void getCalibration(int32_t *p1X, int32_t *p1y, int32_t *p2x, int32_t *p2y);
		void setSize(int32_t width, signed height);
		void set(uint16_t x, uint16_t y, uint8_t event);
		void trigger(void);
	};
}

#endif
