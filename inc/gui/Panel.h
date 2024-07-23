/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_PANEL__H_
#define YSS_GUI_PANEL__H_

#include "Container.h"

class Panel : public Container
{
  public:
	Panel(void);
	void setPosition(Position_t pos);
	void setPosition(int16_t x, int16_t y);
};

#endif

