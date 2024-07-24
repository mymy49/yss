/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BITMAP__H_
#define YSS_GUI_BITMAP__H_

#include <stdint.h>
#include "Object.h"

class Bitmap : public Object
{
public :
	Bitmap(void);
	void paint(void); // virtual 0
	void setBmp(const Bitmap_t &obj);
};

#endif

