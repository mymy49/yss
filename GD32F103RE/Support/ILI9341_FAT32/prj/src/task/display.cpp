////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <task/display.h>
#include <task/task.h>
#include <guiCpu/ValueDisplay.h>
#include <gui/Bmp565Brush.h>
#include <util/ElapsedTime.h>

#include "board.h"
#include "status.h"
#include "../font/Ubuntu_20.h"
#include "../font/Ubuntu_12_B.h"

namespace task
{
namespace display
{
	Bmp565BrushSwappedByte gBrush(240*45);
	int gDelayTime = 0;

	void thread_displayMeasureValueExample(void)
	{
		ValueDisplay temperature, pressure;
		ElapsedTime temperatureUpdateTime, pressureUpdateTime;
		float lastTemperature, lastPressure;
		Font font1(Font_Ubuntu_20), font2(Font_Ubuntu_12_B);

		font1.setCharWidth(12);
		font2.setCharWidth(9);

		// 온도 디스플레이 설정
		temperature.setBmp565Brush(gBrush);
		temperature.setCpuTft(lcd);
		temperature.setPosition(20, 50);
		temperature.setSize(111, 30);
		temperature.setBgColor(0x32, 0x32, 0x32);
		temperature.setFont(font1);
		temperature.setUnit(87, 5, "℃");
		temperature.setValue(10, 5, "%6.2f");
		temperature.setOverValue(95.f);
		temperature.setUnderValue(5.f);
		
		// 압력 디스플레이 설정
		pressure.setBmp565Brush(gBrush);
		pressure.setCpuTft(lcd);
		pressure.setPosition(20, 105);
		pressure.setSize(106, 24);
		pressure.setBgColor(0x32, 0x32, 0x32);
		pressure.setFont(font2);
		pressure.setUnit(69, 6, "kPa");
		pressure.setValue(10, 6, "%6.1f");
		pressure.setOverValue(500.f);
		pressure.setUnderValue(30.f);

		lcd.lock();

		// 온도 디스플레이 초기화
		gBrush.setSize(111+10, 52);
		gBrush.setBgColor(0x50, 0x80, 0x50);
		gBrush.setFontColor(0x00, 0x00, 0x00);
		gBrush.setFont(Font_Ubuntu_12_B);
		gBrush.clear();
		gBrush.drawString(Pos{2, 5}, "Temperature");
		lcd.drawBmp(Pos{20-5, 50-19}, gBrush.getBmp565());

		temperatureUpdateTime.reset();
		temperature.drawBackground(0xFF, 0xFF, 0xFF);
		lastTemperature = 0;
		temperature.drawValue(0);

		// 압력 디스플레이 초기화
		gBrush.setSize(106+10, 46);
		gBrush.setBgColor(0x50, 0x80, 0x50);
		gBrush.setFontColor(0x00, 0x00, 0x00);
		gBrush.setFont(Font_Ubuntu_12_B);
		gBrush.clear();
		gBrush.drawString(Pos{2, 5}, "Pressure");
		lcd.drawBmp(Pos{20-5, 105-19}, gBrush.getBmp565());

		pressureUpdateTime.reset();
		pressure.drawBackground(0xFF, 0xFF, 0xFF);
		lastPressure = 0;
		pressure.drawValue(0);

		lcd.unlock();
		
		while(1)
		{
			 //온도 디스플레이
//			if(status::temperature != lastTemperature && temperatureUpdateTime.getMsec() >= 10)
			if(status::temperature != lastTemperature)
			{
				temperatureUpdateTime.reset();
				lastTemperature = status::temperature;

				lcd.lock();
				temperature.drawValue(status::temperature);
				lcd.unlock();
			}

			if(status::pressure != lastPressure)
			{
				pressureUpdateTime.reset();
				lastPressure = status::pressure;

				lcd.lock();
				pressure.drawValue(status::pressure);
				lcd.unlock();
			}
		}
	}

	void thread_changeTemperature(void)
	{
		bool tDir = true, pDir = true;

		while(1)
		{
			if(tDir)
			{
				status::temperature += 0.01f;
				if(status::temperature > 100.f)
				{
					status::temperature = 100.f;
					tDir = false;
				}
			}
			else
			{
				status::temperature -= 0.01f;
				if(status::temperature < 0.f)
				{
					tDir = true;
					status::temperature = 0.f;
				}
			}

			if(pDir)
			{
				status::pressure += .1f;
				if(status::pressure > 1000.f)
				{
					status::pressure = 1000.f;
					pDir = false;
				}
			}
			else
			{
				status::pressure -= 0.1f;
				if(status::pressure < 0.f)
				{
					pDir = true;
					status::pressure = 0.f;
				}
			}

			thread::delay(gDelayTime);
		}
	}

	void thread_changeDelayTime(void)
	{
		bool dir = true;
		gDelayTime = 100;

		while(1)
		{
			if(dir)
			{
				gDelayTime++;
				if(gDelayTime >= 100)
					dir = false;
			}
			else
			{
				gDelayTime--;
				if(gDelayTime <= 5)
					dir = true;
			}

			thread::delay(20);
		}
	}

	signed int displayMeasureValueExample(FunctionQueue *obj)
	{
		gMutex.lock();
		clear();

		gThreadId[0] = thread::add(thread_displayMeasureValueExample, 2048);
		gThreadId[1] = thread::add(thread_changeDelayTime, 256);
		gThreadId[2] = thread::add(thread_changeTemperature, 256);

		gMutex.unlock();
		return 0;
	}

	signed int displayRgbForTest(FunctionQueue *obj)
	{
		gMutex.lock();
		clear();
		gMutex.unlock();

		lcd.lock();
		lcd.setBgColor(255, 0, 0);
		lcd.clear();
		lcd.unlock();
		thread::delay(1000);
		
		lcd.lock();
		lcd.setBgColor(0, 255, 0);
		lcd.clear();
		lcd.unlock();
		thread::delay(1000);

		lcd.lock();
		lcd.setBgColor(0, 0, 255);
		lcd.clear();
		lcd.unlock();
		thread::delay(1000);

		lcd.lock();
		gBrush.setSize(240, 45);

		gBrush.setBgColor(0xFF, 0x00, 0x00);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 0}, gBrush.getBmp565());

		gBrush.setBgColor(0xFF, 0x7F, 0x00);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45}, gBrush.getBmp565());

		gBrush.setBgColor(0xFF, 0xFF, 0x00);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45*2}, gBrush.getBmp565());

		gBrush.setBgColor(0x00, 0xFF, 0x00);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45*3}, gBrush.getBmp565());

		gBrush.setBgColor(0x00, 0x00, 0xFF);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45*4}, gBrush.getBmp565());

		gBrush.setBgColor(0x00, 0x00, 0x80);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45*5}, gBrush.getBmp565());

		gBrush.setBgColor(0x8B, 0x00, 0xFF);
		gBrush.clear();
		lcd.drawBmp(Pos{0, 45*6}, gBrush.getBmp565());
		lcd.unlock();

		thread::delay(1000);

		lcd.lock();
		lcd.setBgColor(0, 0, 0);
		lcd.clear();
		lcd.unlock();

		return 0;
	}
}
}
