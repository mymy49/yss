/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_MONO_LCD__H_
#define YSS_SAC_MONO_LCD__H_

#include <config.h>

#if USE_GUI

#include <gui/MonoBrush.h>
#include <yss/Mutex.h>

namespace sac
{
class MonoLcd : public MonoBrush, public Mutex
{
  protected:
	uint16_t mWidth, mHeight;
	uint32_t mBufferSize;
	uint8_t *mFrameBuffer;

	void setSize(uint16_t width, uint16_t height);

  public:
	MonoLcd(void);

	virtual void drawDot(uint16_t x, uint16_t y, bool data = true) = 0;
	virtual void refresh(void) = 0;
};
}

#endif

#endif

