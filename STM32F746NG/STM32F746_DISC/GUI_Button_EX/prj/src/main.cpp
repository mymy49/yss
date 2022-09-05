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

#include <__cross_studio_io.h>
#include <bsp.h>
#include <font/Ubuntu_12_B.h>
#include <yss/yss.h>

Frame *gFrame;

void handler_red(void)
{
	gFrame->setBackgroundColor(255, 0, 0);
}

void handler_yellow(void)
{
	gFrame->setBackgroundColor(255, 255, 0);
}

void handler_white(void)
{
	gFrame->setBackgroundColor(255, 255, 255);
}

void handler_black(void)
{
	gFrame->setBackgroundColor(0, 0, 0);
}

void handler_blue(void)
{
	gFrame->setBackgroundColor(0, 0, 255);
}

void handler_magenta(void)
{
	gFrame->setBackgroundColor(0, 255, 255);
}

void handler_green(void)
{
	gFrame->setBackgroundColor(0, 255, 0);
}

int main(void)
{
	yss::init();
	bsp::init();

	gFrame = new Frame;
	gFrame->setBackgroundColor(0x00, 0x00, 0x00);

	Button redBtn, yelloBtn, whiteBtn, blackBtn, blueBtn, magentaBtn, greenBtn;

	redBtn.setFont(Font_Ubuntu_12_B);
	redBtn.setSize(50, 30);
	redBtn.setPosition(20, 20);
	redBtn.setBackgroundColor(255, 0, 0);
	redBtn.setText("적색");
	redBtn.setPushEventHandler(handler_red);

	yelloBtn.setFont(Font_Ubuntu_12_B);
	yelloBtn.setSize(50, 30);
	yelloBtn.setPosition(90, 20);
	yelloBtn.setBackgroundColor(255, 255, 0);
	yelloBtn.setText("황색");
	yelloBtn.setPushEventHandler(handler_yellow);

	whiteBtn.setFont(Font_Ubuntu_12_B);
	whiteBtn.setSize(50, 30);
	whiteBtn.setPosition(20, 70);
	whiteBtn.setBackgroundColor(255, 255, 255);
	whiteBtn.setText("백색");
	whiteBtn.setPushEventHandler(handler_white);

	blackBtn.setFont(Font_Ubuntu_12_B);
	blackBtn.setSize(50, 30);
	blackBtn.setPosition(90, 70);
	blackBtn.setBackgroundColor(0, 0, 0);
	blackBtn.setFontColor(255, 255, 255);
	blackBtn.setText("흑색");
	blackBtn.setPushEventHandler(handler_black);

	blueBtn.setFont(Font_Ubuntu_12_B);
	blueBtn.setSize(50, 30);
	blueBtn.setPosition(20, 120);
	blueBtn.setBackgroundColor(0, 0, 255);
	blueBtn.setText("청색");
	blueBtn.setPushEventHandler(handler_blue);

	magentaBtn.setFont(Font_Ubuntu_12_B);
	magentaBtn.setSize(50, 30);
	magentaBtn.setPosition(90, 120);
	magentaBtn.setBackgroundColor(0, 255, 255);
	magentaBtn.setText("자색");
	magentaBtn.setPushEventHandler(handler_magenta);

	greenBtn.setFont(Font_Ubuntu_12_B);
	greenBtn.setSize(50, 30);
	greenBtn.setPosition(20, 170);
	greenBtn.setBackgroundColor(0, 255, 0);
	greenBtn.setText("녹색");
	greenBtn.setPushEventHandler(handler_green);

	gFrame->add(redBtn);
	gFrame->add(yelloBtn);
	gFrame->add(whiteBtn);
	gFrame->add(blackBtn);
	gFrame->add(blueBtn);
	gFrame->add(magentaBtn);
	gFrame->add(greenBtn);

	yss::setFrame(gFrame);

	while (1)
	{
		//greenBtn.setText("녹색");
		//greenBtn.paint();
		//greenBtn.update();
		//thread::delay(1000);
		//greenBtn.setText("Green");
		//greenBtn.paint();
		//greenBtn.update();
		//thread::delay(1000);
		thread::yield();
	}

	return 0;
}