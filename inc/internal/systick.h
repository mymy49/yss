/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INTERNAL_SYSTICK__H_
#define YSS_INTERNAL_SYSTICK__H_

#define setSystickLoad(x)	SysTick->LOAD = x
#define startSystick()		SysTick->CTRL = (1 << SysTick_CTRL_CLKSOURCE_Pos) | ( 1 << SysTick_CTRL_TICKINT_Pos) | ( 1 << SysTick_CTRL_ENABLE_Pos);
#define stopSystick()		SysTick->CTRL = 0;

#endif
