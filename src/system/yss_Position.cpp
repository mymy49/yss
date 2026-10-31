/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Position.h>

Position::Position(void)
{
	mX = mY = 0;
	mMinX = mMinY = -32768;
	mMaxX = mMaxY = 32767;
}

Position::Position(int16_t x, int16_t y)
{
	mMinX = mMinY = -32768;
	mMaxX = mMaxY = 32767;
	setX(x);
	setY(y);
}

void Position::operator+=(Position obj)
{
	setX(mX + obj.mX);
	setY(mY + obj.mY);
}

void Position::operator-=(Position obj)
{
	sub(obj);
}

void Position::operator=(Position obj)
{
	setX(obj.mX);
	setY(obj.mY);
}

void Position::setMinPosition(int16_t x, int16_t y)
{
	mMinX = x;
	mMinY = y;
	
	setX(mX);
	setY(mY);
}

void Position::setMaxPosition(int16_t x, int16_t y)
{
	mMaxX = x;
	mMaxY = y;

	setX(mX);
	setY(mY);
}

void Position::add(Position obj)
{
	setX(mX + obj.mX);
	setY(mY + obj.mY);
}

void Position::sub(Position obj)
{
	setX(mX - obj.mX);
	setY(mY - obj.mY);
}

int16_t Position::getX(void)
{
	return mX;
}

int16_t Position::getY(void)
{
	return mY;
}

void Position::setPosition(Position obj)
{
	setX(obj.mX);
	setY(obj.mY);
}

void Position::setPosition(int16_t x, int16_t y)
{
	setX(x);
	setY(y);
}

void Position::addX(int16_t x)
{
	setX(mX + x);
}

void Position::subX(int16_t x)
{
	setX(mX - x);
}

void Position::addY(int16_t y)
{
	setY(mY + y);
}

void Position::subY(int16_t y)
{
	setY(mY - y);
}

void Position::setX(int16_t x)
{
	if(mMinX > x)
		x = mMinX;
	else if(mMaxX < x)
		x = mMaxX;
	mX = x;
}

void Position::setY(int16_t y)
{
	if(mMinY > y)
		y = mMinY;
	else if(mMaxY < y)
		y = mMaxY;
	mY = y;
}
