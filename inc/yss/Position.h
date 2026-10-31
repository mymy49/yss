/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_POSITION__H_
#define YSS_GUI_POSITION__H_

#include <stdint.h>

class Position
{
public:
	Position(void);

	Position(int16_t x, int16_t y);
	
	int16_t getX(void);

	int16_t getY(void);

	void operator+=(Position obj);

	void operator-=(Position obj);

	void operator=(Position obj);

	void setMinPosition(int16_t x, int16_t y);

	void setMaxPosition(int16_t x, int16_t y);

	void add(Position obj);

	void sub(Position obj);

	void setPosition(Position obj);

	void setPosition(int16_t x, int16_t y);

	void addX(int16_t x);

	void subX(int16_t x);

	void addY(int16_t y);

	void subY(int16_t y);

	void setX(int16_t x);

	void setY(int16_t y);

private :
	int16_t mX, mY, mMinX, mMinY, mMaxX, mMaxY;
};

#endif

