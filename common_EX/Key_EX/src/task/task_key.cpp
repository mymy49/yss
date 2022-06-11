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
#include <dev/led.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <task/key.h>
#include <util/key.h>
#include <yss/yss.h>

namespace task
{
namespace ex
{
int gId;
Mutex gMutex;
bool (*gGetKeyFunc)(void);

void init(bool (*getKeyFunc)(void))
{
    gGetKeyFunc = getKeyFunc;
}

void clear(void)
{
    if (gId)
    {
        thread::remove(gId);
        gId = 0;
    }
}

void thread_mode1(void)
{
    bool keyShortFlag = false, keyLongFlag = false;
    bool ledFlag = false;

    while (gGetKeyFunc == 0)
        thread::yield();

    key::clear();
    key::addPushHandler(gGetKeyFunc, keyShortFlag);
    key::addPushHandler(gGetKeyFunc, keyLongFlag, 3000);

    debug_printf("begin thread mode1\n");
    debug_printf("Flag handle method\n");
    led::on(ledFlag);

    while (1)
    {
        if (keyShortFlag)
        {
            keyShortFlag = false;
            ledFlag = !ledFlag;
            led::on(ledFlag);
            debug_printf("key pressed in mode1\n");
        }

        if (keyLongFlag)
        {
            gMutex.lock();
            keyLongFlag = false;
            gFq.add(mode2);
            gMutex.unlock();
            while (1)
                thread::yield();
        }
    }
}

signed int mode1(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_mode1, 512);

    gMutex.unlock();
    return 0;
}

void thread_mode2(void)
{
    bool keyShortFlag = false, keyLongFlag = false;
    bool ledFlag = false;

    while (gGetKeyFunc == 0)
        thread::yield();

    key::clear();
    key::addPushHandler(gGetKeyFunc, keyShortFlag);
    key::addPushHandler(gGetKeyFunc, keyLongFlag, 3000);

    debug_printf("begin thread mode2\n");
    debug_printf("Flag handle method with LED fade in fade out\n");
    led::on(ledFlag);

    while (1)
    {
        if (keyShortFlag)
        {
            keyShortFlag = false;
            ledFlag = !ledFlag;
            if (ledFlag)
                led::fadeInOut();
            else
                led::on(false);
            debug_printf("key pressed in mode2\n");
        }

        if (keyLongFlag)
        {
            gMutex.lock();
            keyLongFlag = false;
            gFq.add(mode3);
            gMutex.unlock();
            while (1)
                thread::yield();
        }
    }
}

signed int mode2(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_mode2, 512);

    gMutex.unlock();
    return 0;
}

static bool gLedFlag;
void callback_key(void)
{
    gLedFlag = !gLedFlag;
    if (gLedFlag)
        led::fadeInOut();
    else
        led::on(false);
    debug_printf("key pressed in mode3\n");
}

void thread_mode3(void)
{
    bool keyShortFlag = false, keyLongFlag = false;

    gLedFlag = false;

    while (gGetKeyFunc == 0)
        thread::yield();

    key::clear();
    key::addPushHandler(gGetKeyFunc, callback_key);
    key::addPushHandler(gGetKeyFunc, keyLongFlag, 3000);

    debug_printf("begin thread mode3\n");
    debug_printf("Call back handle method with LED fade in fade out\n");

    led::on(gLedFlag);

    while (1)
    {
        if (keyLongFlag)
        {
            gMutex.lock();
            keyLongFlag = false;
            gFq.add(mode4);
            gMutex.unlock();
            while (1)
                thread::yield();
        }
    }
}

signed int mode3(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_mode3, 512);

    gMutex.unlock();
    return 0;
}

void thread_mode4(void)
{
    bool keyShortFlag = false, keyLongFlag = false;
    int value = 0, before = 0;
    gLedFlag = false;

    while (gGetKeyFunc == 0)
        thread::yield();

    key::clear();
    key::addCountUpHandler(gGetKeyFunc, value, 0, 100);
    key::addPushHandler(gGetKeyFunc, keyLongFlag, 3000);

    debug_printf("begin thread mode4\n");
    debug_printf("addCountUpHanlder using method with LED fade in fade out\n");
    led::on(gLedFlag);

    while (1)
    {
        if (value != before)
        {
            before = value;
            debug_printf("key pressed in mode4 : cnt = %d\n", value);
        }

        if (keyLongFlag)
        {
            gMutex.lock();
            keyLongFlag = false;
            gFq.add(mode1);
            gMutex.unlock();
            while (1)
                thread::yield();
        }
    }
}

signed int mode4(FunctionQueue *fq)
{
    gMutex.lock();

    clear();

    gId = thread::add(thread_mode4, 512);

    gMutex.unlock();
    return 0;
}

}
}