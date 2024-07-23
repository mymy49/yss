/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(LTDC) && defined(STM32F4) || defined(STM32F7)

#include <drv/Ltdc.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Ltdc::Ltdc(const Drv::setup_t drvConfig) : Drv(drvConfig)
{
}

error_t Ltdc::initialize(const Ltdc::specification_t *spec)
{
	unsigned short v, h, pitch;
	unsigned char pixelFormat = spec->pixelFormat;
	mSpec = spec;
	Color color;
	
	v = spec->vsyncWidth - 1;
	h = spec->hsyncWidth - 1;
	setTwoFieldData(LTDC->SSCR, 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vbp;
	h += spec->hbp;
	setTwoFieldData(LTDC->BPCR, 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->height;
	h += spec->width;
	setTwoFieldData(LTDC->AWCR, 0xFFF << 16, h, 16, 0xFFF, v, 0);
	v += spec->vfp;
	h += spec->hfp;
	setTwoFieldData(LTDC->TWCR, 0xFFF << 16, h, 16, 0xFFF, v, 0);

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
	LTDC_Layer1->WHPCR = ((spec->hsyncWidth + spec->hbp + spec->width - 1) & 0xFFF) << 16 | ((spec->hsyncWidth + spec->hbp) & 0xFFF);
	LTDC_Layer1->WVPCR = ((spec->vsyncWidth + spec->vbp + spec->height- 1) & 0xFFF) << 16 | ((spec->vsyncWidth + spec->vbp) & 0xFFF);
	LTDC_Layer1->PFCR = pixelFormat & 0x7;
	LTDC_Layer1->BFCR = 4 << LTDC_LxBFCR_BF1_Pos | 5 << LTDC_LxBFCR_BF2_Pos;
	LTDC_Layer1->CFBLR = (pitch << 16) | (pitch + 3);

	LTDC_Layer1->CFBLNR = spec->height;
	LTDC->SRCR |= LTDC_SRCR_IMR_Msk;	// reload
	
	LTDC_Layer1->CR |= LTDC_LxCR_LEN_Msk;
	LTDC->SRCR |= LTDC_SRCR_IMR_Msk;	// reload
	
	LTDC->GCR |= LTDC_GCR_DEN_Msk;
	LTDC->GCR |= LTDC_GCR_LTDCEN_Msk;

	color.setLittleEndian(true);
	color.setReverseRgbOrder(true);

	return error_t::ERROR_NONE;
}

void Ltdc::setFrameBuffer(void *frame)
{
	LTDC_Layer1->CFBAR = (unsigned int)frame;
	LTDC->SRCR |= LTDC_SRCR_IMR_Msk;	// reload
}

//void Ltdc::setFrameBuffer(FrameBuffer &obj)
//{
//	Size_t size = obj.getSize();
//	uint32_t frame = (uint32_t)obj.getFrameBuffer();

//	if (mSpec->width == size.width && mSpec->height == size.height)
//	{
//		LTDC_Layer1->CFBAR = (unsigned int)frame;
//		LTDC->SRCR |= LTDC_SRCR_IMR_Msk;	// reload
//	}
//}

//void Ltdc::setFrameBuffer(FrameBuffer *obj)
//{
//	setFrameBuffer(*obj);
//}

Size_t Ltdc::getLcdSize(void)
{
	return Size_t{mSpec->width, mSpec->height};
}

#endif
