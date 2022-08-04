#include <task/display.h>
#include <yss/gui.h>
#include "../font/Abyssinica_SIL_25.h"
#include <yss/yss.h>
#include <stdio.h>
#include <util/key.h>
#include "../gui/Gauge.h"
#include <status.h>

namespace task
{
namespace display
{
	void thread_displayGauge(void)
	{
		float lastValue1 = 0, lastValue2 = 0, lastValue3 = 0;

		thread::protect(); // frm이 새로 생성되고 gFrame에 무사히 대입 될 때까지 보호
		Frame *frm = new Frame;
		Gauge *gauge1 = new Gauge;
		Gauge *gauge2 = new Gauge;
		Gauge *gauge3 = new Gauge;

		gFrame = frm;
		thread::unprotect();

		frm->setBackgroundColor(0xA0, 0xA5, 0xA8);

		gauge1->setPosition(Position{60, 10});
		gauge1->setBackgroundColor(0xA0, 0xA5, 0xA8);
		gauge1->setSize(200, 200);
		gauge1->setTopValue(500);
		gauge1->setFont(Font_Abyssinica_SIL_25);
		gauge1->setTitle("Value1");
		gauge1->makeBg();

		gauge2->setBackgroundColor(0xA0, 0xA5, 0xA8);
		gauge2->setSize(150, 150);
		gauge2->setTopValue(250);
		gauge2->setFont(Font_Abyssinica_SIL_25);
		gauge2->setTitle("Value2");
		gauge2->makeBg();
		gauge2->setPosition(5, 220);
		
		gauge3->setBackgroundColor(0xA0, 0xA5, 0xA8);
		gauge3->setSize(150, 150);
		gauge3->setTopValue(125);
		gauge3->setFont(Font_Abyssinica_SIL_25);
		gauge3->setTitle("Value3");
		gauge3->makeBg();
		gauge3->setPosition(165, 220);

		frm->add(gauge1);
		frm->add(gauge2);
		frm->add(gauge3);
		yss::setFrame(frm);
		
		while(1)
		{
			if(Status::value1 != lastValue1)
			{
				lastValue1 = Status::value1;
				gauge1->setValue(lastValue1);
			}

			if(Status::value2 != lastValue2)
			{
				lastValue2 = Status::value2;
				gauge2->setValue(lastValue2);
			}

			if(Status::value3 != lastValue3)
			{
				lastValue3 = Status::value3;
				gauge3->setValue(lastValue3);
			}

			thread::yield();
		}
	}

	void thread_upcountValue(void)
	{
		while(1)
		{
			Status::value1 += 1;
			if(Status::value1 >= 500)
				Status::value1 = 0;

			Status::value2 += 1;
			if(Status::value2 >= 250)
				Status::value2 = 0;

			Status::value3 += 1;
			if(Status::value3 >= 125)
				Status::value3 = 0;

			thread::delay(10);
		}
	}

	error displayGauge(FunctionQueue *obj)
	{
		gMutex.lock();
		clear();

		gThreadId[0] = thread::add(thread_displayGauge, 2048);
		gThreadId[1] = thread::add(thread_upcountValue, 2048);
		gMutex.unlock();

		return Error::NONE;
	}
}
}
