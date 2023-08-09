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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <std_ext/malloc.h>

RadioPanel::RadioPanel()
{
	mText = 0;
	mObjectStartPos = 0;
	mLastNumOfObj = 0;
	mPushHandler = 0;
	mLastIndex = 0;
}

void RadioPanel::paint(void)
{
	Font *font = mFrameBuffer->getFont();
	Size size = mFrameBuffer->getSize();
	if(mFrameBuffer == 0)
		return;

	int16_t y;
	Position p1, p2;

	mFrameBuffer->clear(); 

	if(mText && font->isAble())
		y = font->getStringHeight(mText) + 2;
	else
		y = 4;

	if(mObjectStartPos != y || mLastNumOfObj != mNumOfObj)
	{
		mObjectStartPos = y;
		p1.x = 4;
		p1.y = mObjectStartPos;
		mLastNumOfObj = mNumOfObj;
	
		for(int32_t  i=0;i<mNumOfObj;i++)
		{
			mObjArr[i]->setPosition(p1);
			p1.y += mObjArr[i]->getSize().height + 2;
		}
	}

	Container::paint();

	if(mText && font->isAble())
	{
		y = font->getStringHeight(mText) / 2 + 2;

		mFrameBuffer->drawString(Position{20, 2}, mText);
		mFrameBuffer->drawLine(Position{2, y}, Position{18, y});
		p1 = Position{2, y};
		p2 = Position{2, (int16_t)(size.height-3)};
		mFrameBuffer->drawLine(p1, p2);
		p1 = Position{(int16_t)(size.width-3), (int16_t)(size.height-3)};
		mFrameBuffer->drawLine(p2, p1);
		p2 = Position{(int16_t)(size.width-3), y};
		mFrameBuffer->drawLine(p1, p2);
		p1 = Position{(int16_t)(font->getStringWidth(mText)+23), y};
		mFrameBuffer->drawLine(p1, p2);
	}
}

void RadioPanel::setText(const char *text)
{
	mText = text;
	paint();
	update();
}

void RadioPanel::add(Object &obj)
{

}

void RadioPanel::add(Object *obj)
{

}

void RadioPanel::add(RadioButton &obj)
{
	if(mNumOfObj+1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setParent(this);

	if(mNumOfObj == 1)
		obj.select(true);
	else
		obj.select(false);

	update(obj.getPos(), obj.getSize());
}

void RadioPanel::add(RadioButton *obj)
{
	add(*obj);
}

void RadioPanel::setChangeEventHandler(void (*handler)(int32_t ))
{
	mPushHandler = handler;
}

Object* RadioPanel::handlerPush(Position pos)
{
	Position objPos;
	Size objSize;
	Position calculatedPos;
	Object *rt;
	RadioButton *rb;

	for(int16_t i=mNumOfObj-1;i>=0;i--)
	{
		objPos = mObjArr[i]->getPos();
		objSize = mObjArr[i]->getSize();

		if(mObjArr[i]->isVisible() && objPos.x < pos.x && objPos.y < pos.y && objPos.x + objSize.width > pos.x && objPos.y + objSize.height > pos.y && mLastIndex != i)
		{
			rb = (RadioButton*)mObjArr[i];
			rb->select(true);
			mLastIndex = i;

			for(int32_t  j=0;j<mNumOfObj;j++)
			{
				if(i != j)
				{
					rb = (RadioButton*)mObjArr[j];
					rb->select(false);
				}
			}

			if(mPushHandler)
				mPushHandler(i);
		}
	}

	return 0;
}

#endif