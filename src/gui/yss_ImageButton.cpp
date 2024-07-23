/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/ImageButton.h>
#include <string.h>

#if USE_GUI && YSS_L_HEAP_USE

ImageButton::ImageButton(const Bitmap_t *normal, const Bitmap_t *push)
{
	uint16_t width = 0, height = 0;

	mNormalImage = normal;
	mPushImage = push;
	mState = false;

	// 프레임 버퍼 크기를 상대적으로 큰 쪽으로 설정하기
	if(normal && push)
	{
		if(normal->width > push->width)
			width = normal->width;
		else
			width = push->width;

		if(normal->height > push->height)
			height = normal->height;
		else
			height = push->height;
	}
	else if(normal)
	{
		width = normal->width;
		height = normal->height;
	}
	else if(push)
	{
		width = push->width;
		height = push->height;
	}

	setSize(width, height);
	mFrameBuffer->setBackgroundColor(0xFF, 0xFF, 0xFF, 0x00);
}

ImageButton::~ImageButton(void)
{

}

void ImageButton::paint(void)
{
	Position_t pos;
	Size_t size = getSize();

	if (mFrameBuffer == 0)
		return;

	if (mState)
	{
		if(mPushImage)
		{
			pos.x = (size.width - mPushImage->width) / 2;
			pos.y = (size.height - mPushImage->height) / 2;
			
			mFrameBuffer->clear();
			mFrameBuffer->drawBitmap(pos, mPushImage);
		}
	}
	else
	{
		if(mNormalImage)
		{
			pos.x = (size.width - mNormalImage->width) / 2;
			pos.y = (size.height - mNormalImage->height) / 2;

			mFrameBuffer->clear();
			mFrameBuffer->drawBitmap(pos, mNormalImage);
		}
	}
}

void ImageButton::setPushEventHandler(void (*handler)(void))
{
	mPushHandler = handler;
}

void ImageButton::setUpEventHandler(void (*handler)(void))
{
	mUpHandler = handler;
}

Object *ImageButton::handlerPush(Position_t pos)
{
	(void)pos;

	mState = true;
	paint();
	update();
	if (mPushHandler)
		mPushHandler();
	return this;
}

Object *ImageButton::handlerUp(void)
{
	mState = false;
	paint();
	update();
	if (mUpHandler)
		mUpHandler();
	return this;
}

#endif