/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_LABEL__H_
#define YSS_GUI_LABEL__H_

#include "Object.h"

class Color;
class Font;

class Label : public Object
{
public:
	Label(void);

	void paint(void);

	void setText(const char *text);

	void setFontColor(Color color);

	void setFontColor(uint8_t red, uint8_t green, uint8_t blue);

	void setFont(Font &font);

	// 브러쉬의 배경색을 설정한다.
	//
	// Color color
	//		배경색을 설정한다.
	void setBackgroundColor(Color color);
	
	// 브러쉬의 배경색을 설정한다.
	//
	// uint8_t red
	//		배경색의 빨간색 농도를 설정한다.
	// uint8_t green
	//		배경색의 녹색 농도를 설정한다.
	// uint8_t blue
	//		배경색의 파랑색 농도를 설정한다.
	void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);

private :
	const char *mText;
};

#endif

