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

#include <drv/peripheral.h>

#if false

#include <drv/Ltdc.h>
#include <drv/ltdc/register_ltdc_stm32f4_f7.h>

inline void setLtdcLayerWhpcr(LTDC_Layer_TypeDef *addr, uint16_t start, uint16_t stop)
{
	uint32_t buf = (uint32_t)((stop & 0xfff) << 16) | (start & 0xfff);
	addr->WHPCR = buf;
}

inline void setLtdcLayerWvpcr(LTDC_Layer_TypeDef *addr, uint16_t start, uint16_t stop)
{
	uint32_t buf = (uint32_t)((stop & 0x7ff) << 16) | (start & 0x7ff);
	addr->WVPCR = buf;
}

inline void setLtdcLayerDccr(LTDC_Layer_TypeDef *addr, uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
	uint32_t buf = (uint32_t)((alpha & 0xff) << 24) | ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff);
	addr->DCCR = buf;
}

inline void setLtdcLayerBfcr(LTDC_Layer_TypeDef *addr, uint8_t bf1, uint8_t bf2)
{
	uint32_t buf = (uint32_t)((bf1 & 0x7) << 8) | (bf2 & 0x7);
	addr->BFCR = buf;
}

inline void setLtdcLayerCfblr(LTDC_Layer_TypeDef *addr, uint16_t cfbp, uint16_t cfbll)
{
	uint32_t buf = (uint32_t)((cfbp & 0x1fff) << 16) | (cfbll & 0x1fff);
	addr->CFBLR = buf;
}

Ltdc::Ltdc(LTDC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

bool Ltdc::init(const Ltdc::Specification *spec)
{
	uint16_t vsyncWidth = spec->vsyncWidth;
	uint16_t vbp = spec->vbp;
	uint16_t height = spec->height;
	uint16_t vfp = spec->vfp;
	uint16_t hsyncWidth = spec->hsyncWidth;
	uint16_t hbp = spec->hbp;
	uint16_t width = spec->width;
	uint16_t hfp = spec->hfp;
	uint8_t pixelFormat = spec->pixelFormat;

	mSpec = spec;

	if (vsyncWidth > 0)
		setLtdcHsw(vsyncWidth - 1);
	else
		setLtdcHsw(0);

	if (hsyncWidth > 0)
		setLtdcVsh(hsyncWidth - 1);
	else
		setLtdcVsh(0);

	setLtdcAhbp(hsyncWidth + hbp - 1);
	setLtdcAvbp(vsyncWidth + vbp - 1);
	setLtdcAaw(hsyncWidth + hbp + width - 1);
	setLtdcAah(vsyncWidth + vbp + height - 1);
	setLtdcTotalw(hsyncWidth + hbp + width + hfp - 1);
	setLtdcTotalh(vsyncWidth + vbp + height + vfp - 1);

	setLtdcHspol(false);
	setLtdcVspol(false);
	setLtdcDepol(false);
	setLtdcPcpol(false);

	setLtdcBcRed(0);
	setLtdcBcGreen(0);
	setLtdcBcBlue(0);

	uint16_t pitch;
	switch (pixelFormat)
	{
	case define::ltdc::format::RGB565:
		pitch = 2;
		break;
	case define::ltdc::format::RGB888:
		pitch = 3;
		break;
	}

	pitch *= width;

	setLtdcLayerWhpcr(LTDC_Layer1, hsyncWidth + hbp, hsyncWidth + hbp + width - 1);
	setLtdcLayerWvpcr(LTDC_Layer1, vsyncWidth + vbp, vsyncWidth + vbp + height - 1);
	setLtdcLayerPixelFormat(LTDC_Layer1, pixelFormat);
	setLtdcLayerDccr(LTDC_Layer1, 0, 0, 0, 0);
	setLtdcLayerConstAlpha(LTDC_Layer1, 0xff);
	setLtdcLayerBfcr(LTDC_Layer1, 4, 5);
	setLtdcLayerCfblr(LTDC_Layer1, pitch, pitch + 3);
	setLtdcLayerFrameBufferLineNumber(LTDC_Layer1, height);
	setLtdcImediateReload();

	setLtdcLayerEn(LTDC_Layer1, true);
	setLtdcImediateReload();

	setLtdcDitherEn(true);
	setLtdcEnable(true);
	return true;
}

void Ltdc::setFrameBuffer(void *frame)
{
	setLtdcLayerFrameBuffer(LTDC_Layer1, (uint32_t)frame);
	setLtdcImediateReload();
}

void Ltdc::setFrameBuffer(FrameBuffer &obj)
{
	Size size = obj.getSize();
	uint32_t frame = (uint32_t)obj.getFrameBuffer();

	if (mSpec->width == size.width && mSpec->height == size.height)
	{
		setLtdcLayerFrameBuffer(LTDC_Layer1, (uint32_t)frame);
		setLtdcImediateReload();
	}
}

void Ltdc::setFrameBuffer(FrameBuffer *obj)
{
	setFrameBuffer(*obj);
}

Size Ltdc::getLcdSize(void)
{
	return Size{mSpec->width, mSpec->height};
}

#endif

