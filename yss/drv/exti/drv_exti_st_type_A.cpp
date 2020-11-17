////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
 	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx) || \
	defined(STM32F100xB) || defined(STM32F100xE) || \
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) || \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/exti/drv_st_exti_type_A_register.h>

#if defined(EXTI)
static void setIntEn(bool en)
{
	nvic.setExtiEn(en);
}

drv::Exti exti(0, setIntEn);
#endif

namespace drv
{
	static void (*gIsr[16])(void);
	static bool gOneshotFlag[16];
	static unsigned long gTriggerNum[16];

	static void trigger0(void);
	static void trigger1(void);
	static void trigger2(void);
	static void trigger3(void);
	static void trigger4(void);
	static void trigger5(void);
	static void trigger6(void);
	static void trigger7(void);
	static void trigger8(void);
	static void trigger9(void);
	static void trigger10(void);
	static void trigger11(void);
	static void trigger12(void);
	static void trigger13(void);
	static void trigger14(void);
	static void trigger15(void);

	const void (*triggerIsr[16])(void) =
	{
		(const void (*)(void))trigger0,
		(const void (*)(void))trigger1,
		(const void (*)(void))trigger2,
		(const void (*)(void))trigger3,
		(const void (*)(void))trigger4,
		(const void (*)(void))trigger5,
		(const void (*)(void))trigger6,
		(const void (*)(void))trigger7,
		(const void (*)(void))trigger8,
		(const void (*)(void))trigger9,
		(const void (*)(void))trigger10,
		(const void (*)(void))trigger11,
		(const void (*)(void))trigger12,
		(const void (*)(void))trigger13,
		(const void (*)(void))trigger14,
		(const void (*)(void))trigger15
	};

	Exti::Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) :  Drv(clockFunc, nvicFunc)
	{

	}

	bool Exti::add(drv::Gpio &gpio, unsigned char pin, unsigned char mode, void(*func)(void))
	{
		if(pin > 15)
			return false;

		gOneshotFlag[pin] = false;
		gIsr[pin] = func;
		gpio.setExti(pin);

		if(define::exti::mode::RISING & mode)
			setExtiRisingEdgeTrigger(pin, true);
		else
			setExtiRisingEdgeTrigger(pin, false);

		if(define::exti::mode::FALLING & mode)
			setExtiFallingEdgeTrigger(pin, true);
		else
			setExtiFallingEdgeTrigger(pin, false);

		setExtiIntMask(pin, true);

		return true;
	}

	bool Exti::add(drv::Gpio &gpio, unsigned char pin, unsigned char mode, signed long trigger)
	{
		if(pin > 15)
			return false;

		gOneshotFlag[pin] = false;
		gIsr[pin] = (void(*)(void))triggerIsr[pin];
		gTriggerNum[pin] = trigger;
		gpio.setExti(pin);
		setExtiRisingEdgeTrigger(pin, mode && define::exti::mode::RISING);
		setExtiFallingEdgeTrigger(pin, mode && define::exti::mode::FALLING);
		setExtiIntMask(pin, true);

		return true;
	}

	static void trigger0(void)
	{
		trigger::run(gTriggerNum[0]);
	}

	static void trigger1(void)
	{
		trigger::run(gTriggerNum[1]);
	}

	static void trigger2(void)
	{
		trigger::run(gTriggerNum[2]);
	}

	static void trigger3(void)
	{
		trigger::run(gTriggerNum[3]);
	}

	static void trigger4(void)
	{
		trigger::run(gTriggerNum[4]);
	}

	static void trigger5(void)
	{
		trigger::run(gTriggerNum[5]);
	}

	static void trigger6(void)
	{
		trigger::run(gTriggerNum[6]);
	}

	static void trigger7(void)
	{
		trigger::run(gTriggerNum[7]);
	}

	static void trigger8(void)
	{
		trigger::run(gTriggerNum[8]);
	}

	static void trigger9(void)
	{
		trigger::run(gTriggerNum[9]);
	}

	static void trigger10(void)
	{
		trigger::run(gTriggerNum[10]);
	}

	static void trigger11(void)
	{
		trigger::run(gTriggerNum[11]);
	}

	static void trigger12(void)
	{
		trigger::run(gTriggerNum[12]);
	}

	static void trigger13(void)
	{
		trigger::run(gTriggerNum[13]);
	}

	static void trigger14(void)
	{
		trigger::run(gTriggerNum[14]);
	}

	static void trigger15(void)
	{
		trigger::run(gTriggerNum[15]);
	}

extern "C"
{
	void EXTI0_IRQHandler(void)
	{
		clrExtiInt(0);

		if(gIsr[0])
		{
			gIsr[0]();
			if(gOneshotFlag[0])
			{
				setExtiIntMask(0, false);
				gOneshotFlag[0] = false;
			}
		}
	}

	void EXTI1_IRQHandler(void)
	{
		clrExtiInt(1);

		if(gIsr[1])
		{
			gIsr[1]();
			if(gOneshotFlag[1])
			{
				setExtiIntMask(1, false);
				gOneshotFlag[1] = false;
			}
		}
	}

	void EXTI2_IRQHandler(void)
	{
		clrExtiInt(2);

		if(gIsr[2])
		{
			gIsr[2]();
			if(gOneshotFlag[2])
			{
				setExtiIntMask(2, false);
				gOneshotFlag[2] = false;
			}
		}
	}

	void EXTI3_IRQHandler(void)
	{
		clrExtiInt(3);

		if(gIsr[3])
		{
			gIsr[3]();
			if(gOneshotFlag[3])
			{
				setExtiIntMask(3, false);
				gOneshotFlag[3] = false;
			}
		}
	}

	void EXTI4_IRQHandler(void)
	{
		clrExtiInt(4);

		if(gIsr[4])
		{
			gIsr[4]();
			if(gOneshotFlag[4])
			{
				setExtiIntMask(4, false);
				gOneshotFlag[4] = false;
			}
		}
	}

	void EXTI9_5_IRQHandler(void)
	{
		unsigned short pr = EXTI->PR;

		if(pr & 0x20)
		{
			clrExtiInt(5);

			if(gIsr[5])
			{
				gIsr[5]();
				if(gOneshotFlag[5])
				{
					setExtiIntMask(5, false);
					gOneshotFlag[5] = false;
				}
			}
		}

		if(pr & 0x40)
		{
			clrExtiInt(6);

			if(gIsr[6])
			{
				gIsr[6]();
				if(gOneshotFlag[6])
				{
					setExtiIntMask(6, false);
					gOneshotFlag[6] = false;
				}
			}
		}

		if(pr & 0x80)
		{
			clrExtiInt(7);

			if(gIsr[7])
			{
				gIsr[7]();
				if(gOneshotFlag[7])
				{
					setExtiIntMask(7, false);
					gOneshotFlag[7] = false;
				}
			}
		}

		if(pr & 0x100)
		{
			clrExtiInt(8);

			if(gIsr[8])
			{
				gIsr[8]();
				if(gOneshotFlag[8])
				{
					setExtiIntMask(8, false);
					gOneshotFlag[8] = false;
				}
			}
		}

		if(pr & 0x200)
		{
			clrExtiInt(9);

			if(gIsr[9])
			{
				gIsr[9]();
				if(gOneshotFlag[9])
				{
					setExtiIntMask(9, false);
					gOneshotFlag[9] = false;
				}
			}
		}
	}

	void EXTI15_10_IRQHandler(void)
	{
		unsigned short pr = EXTI->PR;

		if(pr & 0x400)
		{
			clrExtiInt(10);

			if(gIsr[10])
			{
				gIsr[10]();
				if(gOneshotFlag[10])
				{
					setExtiIntMask(10, false);
					gOneshotFlag[10] = false;
				}
			}
		}

		if(pr & 0x800)
		{
			clrExtiInt(11);

			if(gIsr[11])
			{
				gIsr[11]();
				if(gOneshotFlag[11])
				{
					setExtiIntMask(11, false);
					gOneshotFlag[11] = false;
				}
			}
		}

		if(pr & 0x1000)
		{
			clrExtiInt(12);

			if(gIsr[12])
			{
				gIsr[12]();
				if(gOneshotFlag[12])
				{
					setExtiIntMask(12, false);
					gOneshotFlag[12] = false;
				}
			}
		}

		if(pr & 0x2000)
		{
			clrExtiInt(13);

			if(gIsr[13])
			{
				gIsr[13]();
				if(gOneshotFlag[13])
				{
					setExtiIntMask(13, false);
					gOneshotFlag[13] = false;
				}
			}
		}

		if(pr & 0x4000)
		{
			clrExtiInt(14);

			if(gIsr[14])
			{
				gIsr[14]();
				if(gOneshotFlag[14])
				{
					setExtiIntMask(14, false);
					gOneshotFlag[14] = false;
				}
			}
		}

		if(pr & 0x8000)
		{
			clrExtiInt(15);

			if(gIsr[15])
			{
				gIsr[15]();
				if(gOneshotFlag[15])
				{
					setExtiIntMask(15, false);
					gOneshotFlag[15] = false;
				}
			}
		}
	}
}
}
#endif

