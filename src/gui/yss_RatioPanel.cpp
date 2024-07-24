/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
	Size_t size = mFrameBuffer->getSize();
	if(mFrameBuffer == 0)
		return;

	int16_t y;
	Position_t p1, p2;

	mFrameBuffer->clear(); 

	if(mText && font != 0)
		y = font->getStringHeight() + 2;
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

	if(mText && font != 0)
	{
		y = font->getStringHeight() / 2 + 2;

		mFrameBuffer->drawString(Position_t{20, 2}, mText);
		mFrameBuffer->drawLine(Position_t{2, y}, Position_t{18, y});
		p1 = Position_t{2, y};
		p2 = Position_t{2, (int16_t)(size.height-3)};
		mFrameBuffer->drawLine(p1, p2);
		p1 = Position_t{(int16_t)(size.width-3), (int16_t)(size.height-3)};
		mFrameBuffer->drawLine(p2, p1);
		p2 = Position_t{(int16_t)(size.width-3), y};
		mFrameBuffer->drawLine(p1, p2);
		p1 = Position_t{(int16_t)(font->getStringWidth(mText)+23), y};
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
	(void)obj;
}

void RadioPanel::add(Object *obj)
{
	(void)obj;
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

	update(obj.getPosition(), obj.getSize());
}

void RadioPanel::add(RadioButton *obj)
{
	add(*obj);
}

void RadioPanel::setChangeEventHandler(void (*handler)(int32_t ))
{
	mPushHandler = handler;
}

Object* RadioPanel::handlerPush(Position_t pos)
{
	Position_t objPos;
	Size_t objSize;
	RadioButton *rb;

	for(int16_t i=mNumOfObj-1;i>=0;i--)
	{
		objPos = mObjArr[i]->getPosition();
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