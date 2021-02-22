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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.01.20 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <string.h>
#include <yss/yss.h>
#include <mod/oled/UG_2832HSWEG04.h>
#include "../font/Gulim_12.h"
#include "../font/Ubuntu_12.h"
#include "../font/Ubuntu_13.h"
#include "../font/Ubuntu_14.h"
#include "../font/Ubuntu_15.h"
#include "../font/Ubuntu_16.h"
#include "../font/Ubuntu_17.h"
#include "../font/Ubuntu_18.h"
#include "../font/Ubuntu_19.h"
#include "../font/Ubuntu_20.h"
#include "../font/Ubuntu_21.h"
#include "../font/Ubuntu_22.h"
#include "../font/Ubuntu_23.h"
#include "../font/Ubuntu_24.h"
#include "../font/Ubuntu_25.h"
#include "../font/Ubuntu_26.h"
#include "../font/Ubuntu_27.h"
#include "../font/Ubuntu_28.h"
#include "../font/Ubuntu_29.h"
#include "../font/Ubuntu_30.h"
#include "../font/Ubuntu_31.h"
#include "../font/Ubuntu_32.h"

extern "C"
{
	void HardFault_Handler(void)
	{

	}
}

mod::oled::UG_2832HSWEG04 oled;

int main(void)
{
	unsigned char rcvData, sendData = 0xAA;

	// 이순신 os 초기화
	yss::init();

	// SPI5 초기화
	gpioB.setToAltFunc(22, define::gpio::altfunc::SERCOM_ALT_D);
	gpioB.setToAltFunc(23, define::gpio::altfunc::SERCOM_ALT_D);
	gpioB.setToAltFunc(16, define::gpio::altfunc::SERCOM_ALT_D);

	spi5.setClockEn(true);
	spi5.setPad(define::spi::txPad::DO2_SCK3_SS1, define::spi::rxPad::DI0);
	spi5.init();
	spi5.setIntEn(true);

	gpioA.setToOutput(27);
	gpioB.setToOutput(17);
	gpioB.setToOutput(30);
	
	config::gpio::Set oledCs = {&gpioB, 17};
	config::gpio::Set oledRst = {&gpioA, 27};
	config::gpio::Set oledCd = {&gpioB, 30};

	oled.init(spi5, oledCs, oledCd, oledRst);

	oled.clear();
	oled.refresh();

	int x = 0;
	int delay = 300;

	oled.clear();
	oled.setFont(Font_Ubuntu_12);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_13);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_14);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_15);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_16);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_17);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_18);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_19);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_20);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_21);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_22);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_23);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_24);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_25);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_26);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_27);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_28);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_29);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_30);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_31);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	oled.clear();
	oled.setFont(Font_Ubuntu_32);
	x = 0;
	x += oled.drawChar(Pos{x, 0}, '한');
	x += oled.drawChar(Pos{x, 0}, '글');
	x += 10;
	x += oled.drawChar(Pos{x, 0}, '테');
	x += oled.drawChar(Pos{x, 0}, '스');
	x += oled.drawChar(Pos{x, 0}, '트');
	oled.refresh();
	thread::delay(delay);

	while(1)
		thread::yield();

	while (1)
	{
		for(int y=0;y<32;y++)
		{
			for(int x=0;x<128;x++)
			{
				oled.drawDot(x, y, true);
				oled.refresh();
				thread::delay(25);
			}
		}

		for(int y=0;y<32;y++)
		{
			for(int x=0;x<128;x++)
			{
				oled.drawDot(x, y, false);
				oled.refresh();
				thread::delay(25);
			}
		}
	}
	return 0;
}

