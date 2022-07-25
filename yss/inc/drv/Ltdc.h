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

#ifndef YSS_DRV_LTDC__H_
#define YSS_DRV_LTDC__H_

#include <drv/peripheral.h>

#if defined(LTDC)

#include "ltdc/define_ltdc_stm32f4_f7.h"

typedef LTDC_TypeDef		YSS_LTDC_Peri;

#elif defined(TLI) && defined(GD32F4)

#include "ltdc/define_ltdc_gd32f4.h"

typedef unsigned int		YSS_LTDC_Peri;

#else

#define YSS_DRV_LTDC_UNSUPPORTED

#endif

#if !defined(YSS_DRV_LTDC_UNSUPPORTED)

#include <yss/gui.h>
#include <drv/Drv.h>

class Ltdc : public Drv
{
  public:
	struct Specification
	{
		unsigned short width;
		unsigned short height;
		unsigned char hsyncWidth;
		unsigned char vsyncWidth;
		unsigned char hbp;
		unsigned char vbp;
		unsigned char hfp;
		unsigned char vfp;
		unsigned char pixelFormat;
	};

	Ltdc(YSS_LTDC_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	Ltdc(const Drv::Config drvConfig);

	bool init(const Ltdc::Specification *spec);
	void setFrameBuffer(void *frame);
	void setFrameBuffer(FrameBuffer &obj);
	void setFrameBuffer(FrameBuffer *obj);
	Size getLcdSize(void);

  private:
	const Specification *mSpec;
};

#endif

#endif

