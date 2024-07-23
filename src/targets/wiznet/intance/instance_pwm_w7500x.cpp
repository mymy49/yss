/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(W7500)

#include <targets/wiznet/bitfield_w7500x.h>

#if PWM0_ENABLE && defined(PWM0)
#if YSS_TIMER == RUNTIME_PWM0
#error "현재 PWM0는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER0_ENABLE + PWM0_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER0, PWM0, CAPTURE0는 PWM0 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer0Clock(bool en)
{
	clock.lock();
	CRG->PWM0CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer0Interrup(bool en)
{
	PWM->IER |= 1 << 0;
	NVIC_EnableIRQ(PWM0_IRQn);
}

static uint32_t getTimer0ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM0CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM0CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer0Setup = 
{
	enableTimer0Clock,			//void (*clockFunc)(bool en);
	enableTimer0Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer0ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer0Setup = 
{
	PWM0,						//YSS_TIMER_Dev *dev;
	0							//uint8_t index;
};

PwmCh1 pwm0(gDrvTimer0Setup, gTimer0Setup);

#endif


#if PWM1_ENABLE && defined(PWM1)
#if YSS_TIMER == RUNTIME_PWM1
#error "현재 PWM1는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER1_ENABLE + PWM1_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER1, PWM1, CAPTURE1는 PWM1 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer1Clock(bool en)
{
	clock.lock();
	CRG->PWM1CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer1Interrup(bool en)
{
	PWM->IER |= 1 << 1;
	NVIC_EnableIRQ(PWM1_IRQn);
}

static uint32_t getTimer1ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM1CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM1CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer1Setup = 
{
	enableTimer1Clock,			//void (*clockFunc)(bool en);
	enableTimer1Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer1ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer1Setup = 
{
	PWM1,						//YSS_TIMER_Dev *dev;
	1							//uint8_t index;
};

PwmCh1 pwm1(gDrvTimer1Setup, gTimer1Setup);

#endif


#if PWM2_ENABLE && defined(PWM2)
#if YSS_TIMER == RUNTIME_PWM2
#error "현재 PWM2는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER2_ENABLE + PWM2_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER2, PWM2, CAPTURE2는 PWM2 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer2Clock(bool en)
{
	clock.lock();
	CRG->PWM2CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer2Interrup(bool en)
{
	PWM->IER |= 1 << 2;
	NVIC_EnableIRQ(PWM2_IRQn);
}

static uint32_t getTimer2ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM2CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM2CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer2Setup = 
{
	enableTimer2Clock,			//void (*clockFunc)(bool en);
	enableTimer2Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer2ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer2Setup = 
{
	PWM2,						//YSS_TIMER_Dev *dev;
	2							//uint8_t index;
};

PwmCh1 pwm2(gDrvTimer2Setup, gTimer2Setup);

#endif


#if PWM3_ENABLE && defined(PWM3)
#if YSS_TIMER == RUNTIME_PWM3
#error "현재 PWM3는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER3_ENABLE + PWM3_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER3, PWM3, CAPTURE3는 PWM3 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer3Clock(bool en)
{
	clock.lock();
	CRG->PWM3CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer3Interrup(bool en)
{
	PWM->IER |= 1 << 3;
	NVIC_EnableIRQ(PWM3_IRQn);
}

static uint32_t getTimer3ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM3CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM3CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer3Setup = 
{
	enableTimer3Clock,			//void (*clockFunc)(bool en);
	enableTimer3Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer3ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer3Setup = 
{
	PWM3,						//YSS_TIMER_Dev *dev;
	3							//uint8_t index;
};

PwmCh1 pwm3(gDrvTimer3Setup, gTimer3Setup);

#endif


#if PWM4_ENABLE && defined(PWM4)
#if YSS_TIMER == RUNTIME_PWM4
#error "현재 PWM4는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER4_ENABLE + PWM4_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER4, PWM4, CAPTURE4는 PWM4 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer4Clock(bool en)
{
	clock.lock();
	CRG->PWM4CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer4Interrup(bool en)
{
	PWM->IER |= 1 << 4;
	NVIC_EnableIRQ(PWM4_IRQn);
}

static uint32_t getTimer4ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM4CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM4CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer4Setup = 
{
	enableTimer4Clock,			//void (*clockFunc)(bool en);
	enableTimer4Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer4ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer4Setup = 
{
	PWM4,						//YSS_TIMER_Dev *dev;
	4							//uint8_t index;
};

PwmCh1 pwm4(gDrvTimer4Setup, gTimer4Setup);

#endif


#if PWM5_ENABLE && defined(PWM5)
#if YSS_TIMER == RUNTIME_PWM5
#error "현재 PWM5는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER5_ENABLE + PWM5_ENABLE)
#error "W7500에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7500에서 TIMER5, PWM5, CAPTURE5는 PWM5 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer5Clock(bool en)
{
	clock.lock();
	CRG->PWM5CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer5Interrup(bool en)
{
	PWM->IER |= 1 << 5;
	NVIC_EnableIRQ(PWM5_IRQn);
}

static uint32_t getTimer5ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM5CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM5CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer5Setup = 
{
	enableTimer5Clock,			//void (*clockFunc)(bool en);
	enableTimer5Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer5ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer5Setup = 
{
	PWM5,						//YSS_TIMER_Dev *dev;
	5							//uint8_t index;
};

PwmCh1 pwm5(gDrvTimer5Setup, gTimer5Setup);

#endif


#if PWM6_ENABLE && defined(PWM6)
#if YSS_TIMER == RUNTIME_PWM6
#error "현재 PWM6는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER6_ENABLE + PWM6_ENABLE)
#error "W7600에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7600에서 TIMER6, PWM6, CAPTURE6는 PWM6 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer6Clock(bool en)
{
	clock.lock();
	CRG->PWM6CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer6Interrup(bool en)
{
	PWM->IER |= 1 << 6;
	NVIC_EnableIRQ(PWM6_IRQn);
}

static uint32_t getTimer6ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM6CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM6CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer6Setup = 
{
	enableTimer6Clock,			//void (*clockFunc)(bool en);
	enableTimer6Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer6ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer6Setup = 
{
	PWM6,						//YSS_TIMER_Dev *dev;
	6							//uint8_t index;
};

PwmCh1 pwm6(gDrvTimer6Setup, gTimer6Setup);

#endif


#if PWM7_ENABLE && defined(PWM7)
#if YSS_TIMER == RUNTIME_PWM7
#error "현재 PWM7는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIMER7_ENABLE + PWM7_ENABLE)
#error "W7700에서는 동인한 번호의 TIMER, PWM, CAPTURE의 중복 사용을 금지합니다."
// W7700에서 TIMER7, PWM7, CAPTURE7는 PWM7 장치 하나를 공유해서 사용합니다.
// 한 프로젝트에서 하나의 장치만 사용할 수 있습니다.
#endif

static void enableTimer7Clock(bool en)
{
	clock.lock();
	CRG->PWM7CLK_SSR = 1;
	clock.unlock();
}

static void enableTimer7Interrup(bool en)
{
	PWM->IER |= 1 << 7;
	NVIC_EnableIRQ(PWM7_IRQn);
}

static uint32_t getTimer7ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM7CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->PWM7CLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvTimer7Setup = 
{
	enableTimer7Clock,			//void (*clockFunc)(bool en);
	enableTimer7Interrup,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getTimer7ClockFrequency		//uint32_t (*getClockFunc)(void);
};


static const Pwm::setup_t gTimer7Setup = 
{
	PWM7,						//YSS_TIMER_Dev *dev;
	7							//uint8_t index;
};

PwmCh1 pwm7(gDrvTimer7Setup, gTimer7Setup);

#endif

#endif

