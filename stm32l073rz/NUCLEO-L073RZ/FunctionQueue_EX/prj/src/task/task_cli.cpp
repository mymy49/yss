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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.12.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <dev/led.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <task/cli.h>
#include <yss/yss.h>

namespace task
{
namespace cli
{
int gId;
Mutex gMutex;
drv::Uart *gUart;
const char *gMenu;

void init(drv::Uart &peri)
{
    gUart = &peri;
}

void clear(void)
{
    if (gId)
    {
        thread::remove(gId);
        gId = 0;
    }
}

signed int intro(FunctionQueue *fq)
{
    const char *msg1 = "\n\n\rHello~! It is CLI Demo projet using yss os\n\r";
    const char *msg2 = "Please enjoy it~!\n\n\r";

    gUart->lock();
    gUart->send(msg1, strlen(msg1));
    gUart->send(msg2, strlen(msg2));
    gUart->unlock();

    return 0;
}

#define MAX_CHAR 32

signed int processMenuGetNumber(const char *menu)
{
    const char *str = "> ";
    char input[MAX_CHAR], buf;
    char space[MAX_CHAR + 3];
    unsigned char inputCnt = 0;
    bool refreshFlag = true;
    signed int rt;

    memset(input, 0, MAX_CHAR);
    memset(space, ' ', MAX_CHAR + 1);
    space[0] = '\r';
    space[MAX_CHAR + 1] = '\r';
    space[MAX_CHAR + 2] = 0;

    gUart->lock();
    gUart->send(menu, strlen(menu));
    gUart->send(str, strlen(str));
    gUart->unlock();

    while (1)
    {
        buf = gUart->getWaitUntilReceive();

        switch (buf)
        {
        case 0x0d:
            sscanf(input, "%d", &rt);
            gUart->lock();
            gUart->send((void *)"\n\r", 3);
            gUart->unlock();
            return rt;
            break;
        case 0x08:
            input[--inputCnt] = 0;
            gUart->lock();
            gUart->send((void *)&buf, 1);
            gUart->send((void *)" ", 1);
            gUart->send((void *)&buf, 1);
            gUart->unlock();
            break;
        default:
            if (inputCnt < MAX_CHAR)
            {
                debug_printf("0x%02x\n\r", buf);
                input[inputCnt++] = buf;
                input[inputCnt] = 0;
                gUart->lock();
                gUart->send((void *)&buf, 1);
                gUart->unlock();
            }
            break;
        }
    }
}

void thread_handleMainPage(void)
{
    const char *menu = "[1] LED [2] Dump(not working yet)\n\r";
    const char *msg1 = "\n\r=============== Main Menu ===============\n\r";
    const char *errMsg = "Not support!!\n\n\r";
    signed int input;

    gUart->lock();
    gUart->send(msg1, strlen(msg1));
    gUart->unlock();

    while (1)
    {
        input = processMenuGetNumber(menu);

        switch (input)
        {
        case 1:
            gMutex.lock();
            gFq.add(led);
            gMutex.unlock();
            while (1)
                thread::yield();
            break;
        case 2:
        default:
            gUart->lock();
            gUart->send(errMsg, strlen(errMsg));
            gUart->unlock();
            break;
        }
    }
}

signed int main(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_handleMainPage, 512);

    gMutex.unlock();
    return 0;
}

void thread_handleLedPage(void)
{
    const char *menu = "[1] on [2] off [3] fade in fade out [4] exit\n\r";
    const char *msg1 = "\n\r=============== LED Menu ===============\n\r";
    const char *errMsg = "Not support!!\n\n\r";
    signed int input;

    gUart->lock();
    gUart->send(msg1, strlen(msg1));
    gUart->unlock();

    while (1)
    {
        input = processMenuGetNumber(menu);

        switch (input)
        {
        case 1:
            led::on(true);
            break;
        case 2:
            led::on(false);
            break;
        case 3:
            led::fadeInOut();
            break;
        case 4:
            gMutex.lock();
            gFq.add(main);
            gMutex.unlock();
            while (1)
                thread::yield();
            break;
        default:
            gUart->lock();
            gUart->send(errMsg, strlen(errMsg));
            gUart->unlock();
            break;
        }
    }
}

signed int led(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_handleLedPage, 512);

    gMutex.unlock();
    return 0;
}
}
}