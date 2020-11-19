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
//  주담당자 : 아이구 (mymy49@nate.com) 2019.12.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/yss.h>
#include <bsp.h>
#include <font/Ubuntu_10.h>

Frame *gFrm;
Mutex gMutex;

struct Box
{
	Frame *parent;
	Panel *me;
	signed short x, y;
	bool dirX, dirY;
};

struct Box1
{
	Panel *parent;
	Panel *me;
	signed short x, y;
	bool dirX, dirY;
};

void thread_test(void *var);

void handler_pushRed(void)
{
	gFrm->setBgColor(0xFF, 0x00, 0x00);
}

void handler_pushBlue(void)
{
	gFrm->setBgColor(0x00, 0x00, 0xFF);
}

int main(void)
{
	yss::init();
	bsp::init();

	gFrm = new Frame;
	gFrm->setBgColor(0xFF, 0x00, 0x00);

	Panel pn1, pn2, pn3;
	pn1.setSize(100, 100);
	pn1.setBgColor(0xFF, 0xFF, 0x00);

	pn2.setSize(30, 30);
	pn2.setBgColor(0x00, 0xFF, 0x00);

	pn3.setSize(20, 20);
	pn3.setBgColor(0xFF, 0x00, 0x00);

	Button bt1, bt2, bt3, bt4, bt5, bt6;

	bt1.setFont(Font_Ubuntu_10);
	bt1.setText("Red");
	bt1.setBgColor(0xFF, 0x00, 0x00);
	bt1.setSize(80, 25);
	bt1.setPos(10, 10);
	bt1.setPushEventHandler(handler_pushRed);

	bt2.setFont(Font_Ubuntu_10);
	bt2.setText("Green");
	bt2.setBgColor(0x00, 0xFF, 0x00);
	bt2.setSize(80, 25);
	bt2.setPos(10+80+10, 10);

	bt3.setFont(Font_Ubuntu_10);
	bt3.setText("Blue");
	bt3.setBgColor(0x00, 0x00, 0xFF);
	bt3.setSize(80, 25);
	bt3.setPos(10+(80+10)*2, 10);
	bt3.setPushEventHandler(handler_pushBlue);

	bt4.setFont(Font_Ubuntu_10);
	bt4.setText("Yellow");
	bt4.setBgColor(0xFF, 0xFF, 0x00);
	bt4.setSize(80, 25);
	bt4.setPos(10+(80+10)*0, 10+(25+10)*1);

	bt5.setFont(Font_Ubuntu_10);
	bt5.setText("Magenta");
	bt5.setBgColor(0xFF, 0x00, 0xFF);
	bt5.setSize(80, 25);
	bt5.setPos(10+(80+10)*1, 10+(25+10)*1);

	bt6.setFont(Font_Ubuntu_10);
	bt6.setText("Cyan");
	bt6.setBgColor(0x00, 0xFF, 0xFF);
	bt6.setSize(80, 25);
	bt6.setPos(10+(80+10)*2, 10+(25+10)*1);

	CheckBox checkbox;
	checkbox.setSize(150, 15);
	checkbox.setPos(10, 80);
	checkbox.setFont(Font_Ubuntu_10);
	checkbox.setText("Check Box");
	checkbox.setBgColor(200, 200, 200);

	Box box1 = 
	{
		gFrm,
		&pn1,
		30,
		20,
		false,
		false
	};

	Box box2 = 
	{
		gFrm,
		&pn2,
		50,
		90,
		false,
		false
	};

	Box1 box3 = 
	{
		&pn1,
		&pn3,
		10,
		20,
		false,
		false
	};

	thread::add(thread_test, (void*)&box1, 1024);
	thread::add(thread_test, (void*)&box2, 1024);
	thread::add(thread_test, (void*)&box3, 1024);

	pn1.add(pn3);

	gFrm->add(pn1);
	gFrm->add(pn2);
	gFrm->add(bt1);
	gFrm->add(bt2);
	gFrm->add(bt3);
	gFrm->add(bt4);
	gFrm->add(bt5);
	gFrm->add(bt6);
	gFrm->add(checkbox);

	yss::setFrame(gFrm);

	while(1)
	{
		uart1.send("hello world!!\n", sizeof("hello world!!\n"), 1000);
		thread::delay(500);
	}

	return 0;
}

void thread_test(void *var)
{
	Box *box = (Box*)var;
	unsigned short pWidth = box->parent->getSize().width - 1, mWidth = box->me->getSize().width;
	unsigned short pHeight = box->parent->getSize().height - 1, mHeight = box->me->getSize().height;

	while(1)
	{
		if(box->dirX)
		{
			box->x += 3;
			if(box->x >= (pWidth - mWidth))
			{
				box->x = (pWidth - mWidth);
				box->dirX = false;
			}
		}
		else
		{
			box->x -= 3;
			if(box->x <= 0)
			{
				box->x = 0;
				box->dirX = true;
			}
		}

		if(box->dirY)
		{
			box->y += 3;
			if(box->y >= (pHeight - mHeight))
			{
				box->y = (pHeight - mHeight);
				box->dirY = false;
			}
		}
		else
		{
			box->y -= 3;
			if(box->y <= 0)
			{
				box->y = 0;
				box->dirY = true;
			}
		}

		box->me->setPos(box->x, box->y);

		thread::delay(20);
	}
}

