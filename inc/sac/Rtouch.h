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

#ifndef	YSS_SAC_RTOUCH__H_
#define	YSS_SAC_RTOUCH__H_

#include "Touch.h"

namespace sac
{
	class Rtouch : public Touch
	{
	public :
		struct CalibrationData
		{
			int32_t p1x;
			int32_t p1y;
			int32_t p2x;
			int32_t p2y;
			int32_t xOffset;
			int32_t yOffset;
			int32_t width;
			int32_t height;
		};

		Rtouch(void);
		void setCalibrationData(const CalibrationData &calibrationData);
		const CalibrationData* getCalibrationData(void);

	private:
		Position calculate(uint32_t x, uint32_t y);
		uint16_t calculateY(uint32_t y);
		uint16_t calculateX(uint32_t x);
		const CalibrationData *mCalibrationData;
	};
}

#endif
