////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <gui/RadioButton.h>
#include <yss/instance.h>

RadioButton::RadioButton(void)
{
	mState = true;
	mText = 0;

	mFrameBuffer->setBrushColor(0x00, 0x00, 0x00);
}

void RadioButton::setText(const int8_t *text)
{
	mText = text;
	paint();
	update();
}

void RadioButton::select(bool en)
{
	mState = en;
	paint();
	update();
}

void RadioButton::paint(void)
{
	if (mFrameBuffer == 0)
		return;
	
	Size_t size = mFrameBuffer->getSize();
	Font *font = mFrameBuffer->getFont();

	mFrameBuffer->clear();
	
	int16_t height = size.height;
	int16_t half = height / 2;
	Position_t pos = Position_t{half, half};
	mFrameBuffer->drawCircle(pos, half - 2);
	pos.x -= height / 4 - 1;
	pos.y -= height / 4 - 1;
	if (mState)
		mFrameBuffer->fillRect(pos, Size_t{(uint16_t)(half - 3), (uint16_t)(half - 3)});

	if (mText && font != 0)
	{
		mFrameBuffer->drawString(Position_t{(int16_t)(height + 2), (int16_t)(half - font->getStringHeight() / 2)}, (char *)mText);
	}
}

#endif