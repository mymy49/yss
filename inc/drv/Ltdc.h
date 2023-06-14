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

#ifndef YSS_DRV_LTDC__H_
#define YSS_DRV_LTDC__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(LTDC) && defined(STM32F4) || defined(GD32F4) || defined(STM32F7)

#include <targets/st_gigadevice/define_ltdc_stm32_gd32f4_f7.h>
typedef volatile uint32_t	YSS_LTDC_Peri;

#elif defined(LTDC) && defined(STM32F7_N) || defined(STM32F4_N) 

#else

#define YSS_DRV_LTDC_UNSUPPORTED
typedef volatile uint32_t	YSS_LTDC_Peri;

#endif

#include <yss/gui.h>
#include <yss/error.h>
#include "Drv.h"

class Ltdc : public Drv
{
public:
	struct Specification
	{
		uint16_t width;
		uint16_t height;
		uint8_t hsyncWidth;
		uint8_t vsyncWidth;
		uint8_t hbp;
		uint8_t vbp;
		uint8_t hfp;
		uint8_t vfp;
		uint8_t pixelFormat;
	};

	Ltdc(const Drv::Config drvConfig);

	error initialize(const Ltdc::Specification *spec);
	void setFrameBuffer(void *frame);
	void setFrameBuffer(FrameBuffer &obj);
	void setFrameBuffer(FrameBuffer *obj);
	Size getLcdSize(void);

private:
	const Specification *mSpec;
};

#endif

