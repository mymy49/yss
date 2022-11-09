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
#include <yss/reg.h>

enum
{
	SPSZ = 2, BPSZ, ASZ, TSZ, CTL, RL = 9, BGC, INTEN = 13, INTF, INTC, LM, CPPOS, STAT, 
	L0CTL = 33, L0HPOS, L0VPOS, L0CKEY, L0PPF, L0SA, L0DC, L0BLEND, L0FBADDR = 43, L0FLLEN, L0FTLN, L0LUT = 49,
	L1CTL = 65, L1HPOS, L1VPOS, L1CKEY, L1PPF, L1SA, L1DC, L1BLEND, L1FBADDR = 75, L1FLLEN, L1FTLN, L1LUT = 81
};

Ltdc::Ltdc(const Drv::Config drvConfig) : Drv(drvConfig)
{
}

bool Ltdc::init(const Ltdc::Specification *spec)
{
	uint16_t v, h, pitch;
	uint8_t pixelFormat = spec->pixelFormat;
	YSS_LTDC_Peri *peri = (YSS_LTDC_Peri*)TLI;
	mSpec = spec;
	
	v = spec->vsyncWidth - 1;
	h = spec->hsyncWidth - 1;
	setTwoFieldData(peri[SPSZ], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vbp;
	h += spec->vbp;
	setTwoFieldData(peri[BPSZ], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->height;
	h += spec->width;
	setTwoFieldData(peri[ASZ], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vfp;
	h += spec->hfp;
	setTwoFieldData(peri[TSZ], 0xFFF << 16, h, 16, 0xFFF, v, 0);

	switch (spec->pixelFormat)
	{
	case define::ltdc::format::RGB565:
		pitch = 2;
		break;
	case define::ltdc::format::RGB888:
		pitch = 3;
		break;
	}

	pitch *= spec->width;
	peri[L0HPOS] = ((spec->hsyncWidth + spec->hbp + spec->width - 1) & 0xFFF) << 16 | ((spec->hsyncWidth + spec->hbp) & 0xFFF);
	peri[L0VPOS] = ((spec->vsyncWidth + spec->vbp + spec->height- 1) & 0xFFF) << 16 | ((spec->vsyncWidth + spec->vbp) & 0xFFF);
	peri[L0PPF] = pixelFormat & 0x7;
	peri[L0FLLEN] = pitch << 16 | pitch + 3;
	peri[L0FTLN] = spec->height;
	peri[RL] |= TLI_RL_RQR;	// reload
	
	peri[L0CTL] |= TLI_LxCTL_LEN;
	peri[RL] |= TLI_RL_RQR;	// reload
	
	peri[CTL] |= TLI_CTL_DFEN;
	peri[CTL] |= TLI_CTL_TLIEN;

	return true;
}

void Ltdc::setFrameBuffer(void *frame)
{
	YSS_LTDC_Peri *peri = (YSS_LTDC_Peri*)TLI;
	
	peri[L0FBADDR] = (uint32_t)frame;
	peri[RL] |= TLI_RL_RQR;	// reload
}

void Ltdc::setFrameBuffer(FrameBuffer &obj)
{
	YSS_LTDC_Peri *peri = (YSS_LTDC_Peri*)TLI;
	Size size = obj.getSize();
	uint32_t frame = (uint32_t)obj.getFrameBuffer();

	if (mSpec->width == size.width && mSpec->height == size.height)
	{
		peri[L0FBADDR] = (uint32_t)frame;
		peri[RL] |= TLI_RL_RQR;	// reload
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
