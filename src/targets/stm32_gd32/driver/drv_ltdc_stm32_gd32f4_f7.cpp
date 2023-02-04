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

#include <drv/peripheral.h>

#if defined(LTDC) && (defined(GD32F4) || defined(STM32F4) || defined(STM32F7))

#include <drv/peripheral.h>
#include <drv/Ltdc.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/ltdc_stm32_gd32f4_f7.h>

Ltdc::Ltdc(const Drv::Config drvConfig) : Drv(drvConfig)
{
}

bool Ltdc::init(const Ltdc::Specification *spec)
{
	unsigned short v, h, pitch;
	unsigned char pixelFormat = spec->pixelFormat;
	mSpec = spec;
	
	v = spec->vsyncWidth - 1;
	h = spec->hsyncWidth - 1;
	setTwoFieldData(LTDC[LTDC_REG::SSCR], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vbp;
	h += spec->hbp;
	setTwoFieldData(LTDC[LTDC_REG::BPCR], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->height;
	h += spec->width;
	setTwoFieldData(LTDC[LTDC_REG::AWCR], 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vfp;
	h += spec->hfp;
	setTwoFieldData(LTDC[LTDC_REG::TWCR], 0xFFF << 16, h, 16, 0xFFF, v, 0);

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
	LTDC_Layer1[LTDC_LAYER_REG::WHPCR] = ((spec->hsyncWidth + spec->hbp + spec->width - 1) & 0xFFF) << 16 | ((spec->hsyncWidth + spec->hbp) & 0xFFF);
	LTDC_Layer1[LTDC_LAYER_REG::WVPCR] = ((spec->vsyncWidth + spec->vbp + spec->height- 1) & 0xFFF) << 16 | ((spec->vsyncWidth + spec->vbp) & 0xFFF);
	LTDC_Layer1[LTDC_LAYER_REG::PFCR] = pixelFormat & 0x7;
	LTDC_Layer1[LTDC_LAYER_REG::BFCR] = 4 << LTDC_LxBFCR_BF1_Pos | 5 << LTDC_LxBFCR_BF2_Pos;
	LTDC_Layer1[LTDC_LAYER_REG::CFBLR] = pitch << 16 | pitch + 3;

	LTDC_Layer1[LTDC_LAYER_REG::CFBLNR] = spec->height;
	LTDC[LTDC_REG::SRCR] |= LTDC_SRCR_IMR_Msk;	// reload
	
	LTDC_Layer1[LTDC_LAYER_REG::CR] |= LTDC_LxCR_LEN_Msk;
	LTDC[LTDC_REG::SRCR] |= LTDC_SRCR_IMR_Msk;	// reload
	
	LTDC[LTDC_REG::GCR] |= LTDC_GCR_DEN_Msk;
	LTDC[LTDC_REG::GCR] |= LTDC_GCR_LTDCEN_Msk;

	return true;
}

void Ltdc::setFrameBuffer(void *frame)
{
	LTDC_Layer1[LTDC_LAYER_REG::CFBAR] = (unsigned int)frame;
	LTDC[LTDC_REG::SRCR] |= LTDC_SRCR_IMR_Msk;	// reload
}

void Ltdc::setFrameBuffer(FrameBuffer &obj)
{
	Size size = obj.getSize();
	unsigned long frame = (unsigned long)obj.getFrameBuffer();

	if (mSpec->width == size.width && mSpec->height == size.height)
	{
		LTDC_Layer1[LTDC_LAYER_REG::CFBAR] = (unsigned int)frame;
		LTDC[LTDC_REG::SRCR] |= LTDC_SRCR_IMR_Msk;	// reload
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
