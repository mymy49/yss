/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_RECTANGULAR__H_
#define YSS_GUI_RECTANGULAR__H_

#include "Position.h"
#include "Size.h"

class Area
{
public:
	Area();

	Area(Area &area);

	Area(Position pos, Size size);

	Area(int16_t x, int16_t y, uint16_t width, uint16_t height);

	void operator+=(Position obj);
	
	void operator-=(Position obj);

	void operator=(Position obj);

	void operator+=(Size obj);
	
	void operator-=(Size obj);

	void operator=(Size obj);

	void setRectanglar(Position pos, Size size);

	void setRectanglar(int16_t x, int16_t y, uint16_t width, uint16_t height);

	Size &getSize();

	Position &getPosition();

	void addX(int16_t x);

	void subX(int16_t x);

	void addY(int16_t y);

	void subY(int16_t y);

	void setX(int16_t x);

	void setY(int16_t y);

	void addWidth(uint16_t width);

	void subWidth(uint16_t width);

	void addHeight(uint16_t height);

	void subHeight(uint16_t height);

	void setWidth(uint16_t width);

	void setHeight(uint16_t height);

	int16_t getRightBound();

	int16_t getLeftBound();

	int16_t getTopBound();

	int16_t getBotBound();

	int16_t getX();

	int16_t getY();

	uint16_t getWidth();

	uint16_t getHeight();

private :
	Position mPos;
	Size mSize;
};

#endif

