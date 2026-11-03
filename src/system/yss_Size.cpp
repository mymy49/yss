/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Size.h>

Size::Size(void)
{
	mWidth = mHeight = 0;
	mMaxWidth = mMaxHeight = 0xFFFF;
}

Size::Size(uint16_t width, uint16_t height)
{
	mWidth = width;
	mHeight = height;
	mMaxWidth = mMaxHeight = 0xFFFF;
}

void Size::operator+=(Size obj)
{
	setWidth(mWidth + obj.mWidth);
	setHeight(mHeight + obj.mHeight);
}

void Size::operator=(Size obj)
{
	setWidth(obj.mWidth);
	setHeight(obj.mHeight);
}

void Size::add(uint16_t width, uint16_t height)
{
	setWidth(mWidth + width);
	setHeight(mHeight + height);
}

void Size::add(Size obj)
{
	setWidth(mWidth + obj.mWidth);
	setHeight(mHeight + obj.mHeight);
}

uint16_t Size::getWidth(void)
{
	return mWidth;
}

uint16_t Size::getHeight(void)
{
	return mHeight;
}

void Size::setMaxSize(uint16_t width, uint16_t height)
{
	mMaxWidth = width;
	mMaxHeight = height;

	setWidth(mWidth);
	setHeight(mHeight);
}

void Size::setSize(uint16_t width, uint16_t height)
{
	setWidth(width);
	setHeight(height);
}

void Size::setSize(Size obj)
{
	setWidth(obj.mWidth);
	setHeight(obj.mHeight);
}

void Size::sub(uint16_t width, uint16_t height)
{
	if(mWidth > width)
		setWidth(mWidth - width);
	else
		setWidth(0);

	setHeight(mHeight - height);
	if(mHeight > height)
		setHeight(mHeight - height);
	else
		setHeight(0);
}

void Size::sub(Size obj)
{
	if(mWidth > obj.mWidth)
		setWidth(mWidth - obj.mWidth);
	else
		setWidth(0);

	setHeight(mHeight - obj.mHeight);
	if(mHeight > obj.mHeight)
		setHeight(mHeight - obj.mHeight);
	else
		setHeight(0);
}

void Size::operator-=(Size obj)
{
	setWidth(mWidth - obj.mWidth);
	setHeight(mHeight - obj.mHeight);
}

void Size::addWidth(uint16_t width)
{
	setWidth(mWidth + width);
}

void Size::subWidth(uint16_t width)
{
	if(mWidth > width)
		setWidth(mWidth - width);
	else
		setWidth(0);
}

void Size::addHeight(uint16_t height)
{
	setHeight(mHeight + height);
}

void Size::subHeight(uint16_t height)
{
	if(mHeight > height)
		setHeight(mHeight - height);
	else
		setHeight(0);
}

void Size::setWidth(uint16_t width)
{
	if(width > mMaxWidth)
		width = mMaxWidth;

	mWidth = width;
}

void Size::setHeight(uint16_t height)
{
	if(height  > mMaxHeight)
		height = mMaxHeight;

	mHeight = height;
}
