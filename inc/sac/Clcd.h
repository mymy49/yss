/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_CLCD__H_
#define YSS_SAC_CLCD__H_

#include <stdint.h>

namespace sac
{
class Clcd
{
  public:
	virtual bool isConnected(void) = 0;
	virtual void setBlackLight(bool en) = 0;
	virtual void write(uint8_t line, uint8_t column, void *src) = 0;
	virtual bool refresh(void) = 0;
};
}

#endif