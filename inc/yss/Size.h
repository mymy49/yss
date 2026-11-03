/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_SIZE__H_
#define YSS_GUI_SIZE__H_

#include <stdint.h>

class Size
{
public:
	Size(void);

	Size(uint16_t width, uint16_t height);

	void setMaxSize(uint16_t width, uint16_t height);
	
	uint16_t getWidth(void);

	uint16_t getHeight(void);

	void operator+=(Size obj);

	void operator=(Size obj);

	void operator-=(Size obj);

	void add(uint16_t width, uint16_t height);

	void add(Size obj);

	void setSize(uint16_t width, uint16_t height);

	void setSize(Size obj);

	void sub(uint16_t width, uint16_t height);

	void sub(Size obj);

	void addWidth(uint16_t width);

	void subWidth(uint16_t width);

	void addHeight(uint16_t height);

	void subHeight(uint16_t height);

	void setWidth(uint16_t width);

	void setHeight(uint16_t height);

private :
	uint16_t mWidth, mHeight, mMaxWidth, mMaxHeight;
};

#endif

