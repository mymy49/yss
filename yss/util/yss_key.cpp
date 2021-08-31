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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if !defined (__MCU_SMALL_SRAM_NO_SCHEDULE)

#include <config.h>
#include <util/key.h>
#include <util/time.h>
#include <yss/thread.h>

class Key
{
    bool (*mTrigger[2])(void);
    bool *mPushFlag, mCycleFlag;
    void (*mHandler)(void);
    signed int mThreadId;
    int *mInt, mIntMax, mIntMin;
    unsigned int mDeadtime, mRepeatDelayTime;
    unsigned int mAcceptTime;

  public:
    Key(void);
    bool setPush(bool (*trigger)(void), void (*handler)(void));
    bool setPushWithRepeat(bool (*trigger)(void), void (*handler)(void), unsigned int repeatDelay);
    bool setPush(bool (*trigger)(void), bool &flag);
    bool setRelease(bool (*trigger)(void), bool &flag);
    bool setCountUp(bool (*trigger)(void), int &num, int min, int max);
    bool setCountUpWithRepeat(bool (*trigger)(void), int &num, int min, int max, unsigned int acceptTime, unsigned int repeatDelay);
    bool setCountDown(bool (*trigger)(void), int &num, int min, int max);
    bool setCountDownWithRepeat(bool (*trigger)(void), int &num, int min, int max, unsigned int acceptTime, unsigned int repeatDelay);
    void reset(void);
    ~Key(void);
    bool isDetect(void);
    void waitWhileDeadtime(void);
    void delayForRepeatTime(void);
    void handle(void);
    void setFlag(void);
    void countup(void);
    void countdown(void);
    void setCycle(bool en);
    unsigned int getAcceptTime(void);
    unsigned int getDeadTime(void);
    void setDeadTime(unsigned int time);
};

static Key gKey[NUM_OF_YSS_KEY];

namespace key
{
unsigned char gHandlerCnt;
void clear(void)
{
    for (int i = 0; i < gHandlerCnt; i++)
        gKey[i].reset();
    gHandlerCnt = 0;
}

bool addPushHandler(bool (*trigger)(void), void (*handler)(void), int deadTime)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    if (gKey[gHandlerCnt].setPush(trigger, handler))
    {
        gKey[gHandlerCnt++].setDeadTime(deadTime);
        return true;
    }
    else
        return false;
}

bool addPushHandler(bool (*trigger)(void), bool &flag, int deadTime)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    if (gKey[gHandlerCnt].setPush(trigger, flag))
    {
        gKey[gHandlerCnt++].setDeadTime(deadTime);
        return true;
    }
    else
        return false;
}

bool addReleaseHandler(bool (*trigger)(void), bool &flag)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    if (gKey[gHandlerCnt].setRelease(trigger, flag))
    {
        gHandlerCnt++;
        return true;
    }
    else
        return false;
}

bool addHandlerWithRepeat(bool (*trigger)(void), void (*handler)(void), unsigned int repeatDelay)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    return gKey[gHandlerCnt++].setPushWithRepeat(trigger, handler, repeatDelay);
}

bool addCountUpHandler(bool (*trigger)(void), int &num, int min, int max, bool cycle)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    gKey[gHandlerCnt].setCycle(cycle);
    return gKey[gHandlerCnt++].setCountUp(trigger, num, min, max);
}

bool addCountUpHandlerWithRepeat(bool (*trigger)(void), int &num, int min, int max, bool cycle, unsigned int acceptDelay, unsigned int repeatDelay)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    gKey[gHandlerCnt].setCycle(cycle);
    return gKey[gHandlerCnt++].setCountUpWithRepeat(trigger, num, min, max, acceptDelay, repeatDelay);
}

bool addCountDownHandler(bool (*trigger)(void), int &num, int min, int max, bool cycle)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    gKey[gHandlerCnt].setCycle(cycle);
    return gKey[gHandlerCnt++].setCountDown(trigger, num, min, max);
}

bool addCountDownHandlerWithRepeat(bool (*trigger)(void), int &num, int min, int max, bool cycle, unsigned int acceptDelay, unsigned int repeatDelay)
{
    if (gHandlerCnt >= NUM_OF_YSS_KEY)
        return false;

    gKey[gHandlerCnt].setCycle(cycle);
    return gKey[gHandlerCnt++].setCountDownWithRepeat(trigger, num, min, max, acceptDelay, repeatDelay);
}
}

static void thread_handlerPush(void *arg);
static void thread_handlerPushWithRepeat(void *arg);
static void thread_handlerPushUsingBoolFlag(void *arg);
static void thread_handlerReleaseUsingBoolFlag(void *arg);
static void thread_handlerCountUp(void *arg);
static void thread_handlerCountUpWithRepeat(void *arg);
static void thread_handlerCountDown(void *arg);
static void thread_handlerCountDownWithRepeat(void *arg);

Key::Key(void)
{
    mThreadId = 0;
    reset();
}

Key::~Key(void)
{
    if (mThreadId)
        thread::remove(mThreadId);
}

void Key::reset(void)
{
    if (mThreadId)
    {
        thread::remove(mThreadId);
        mThreadId = 0;
    }

    mTrigger[0] = 0;
    mTrigger[1] = 0;
    mHandler = 0;
    mDeadtime = 50;
    mRepeatDelayTime = 50;
}

bool Key::setPush(bool (*trigger)(void), void (*handler)(void))
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    if (handler)
        mHandler = handler;
    else
        return false;

    mThreadId = thread::add(thread_handlerPush, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setPushWithRepeat(bool (*trigger)(void), void (*handler)(void), unsigned int repeatDelay)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    if (handler)
        mHandler = handler;
    else
        return false;

    mRepeatDelayTime = repeatDelay;
    mThreadId = thread::add(thread_handlerPushWithRepeat, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setPush(bool (*trigger)(void), bool &flag)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mPushFlag = &flag;
    mThreadId = thread::add(thread_handlerPushUsingBoolFlag, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setRelease(bool (*trigger)(void), bool &flag)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mPushFlag = &flag;
    mThreadId = thread::add(thread_handlerReleaseUsingBoolFlag, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setCountUp(bool (*trigger)(void), int &num, int min, int max)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mInt = &num;
    mIntMin = min;
    mIntMax = max;
    mThreadId = thread::add(thread_handlerCountUp, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setCountUpWithRepeat(bool (*trigger)(void), int &num, int min, int max, unsigned int acceptDelay, unsigned int repeatDelay)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mInt = &num;
    mIntMin = min;
    mIntMax = max;
    mRepeatDelayTime = repeatDelay;
    mAcceptTime = acceptDelay;
    mThreadId = thread::add(thread_handlerCountUpWithRepeat, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setCountDown(bool (*trigger)(void), int &num, int min, int max)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mInt = &num;
    mIntMin = min;
    mIntMax = max;
    mThreadId = thread::add(thread_handlerCountDown, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

bool Key::setCountDownWithRepeat(bool (*trigger)(void), int &num, int min, int max, unsigned int acceptDelay, unsigned int repeatDelay)
{
    if (trigger)
        mTrigger[0] = trigger;
    else
        return false;

    mInt = &num;
    mIntMin = min;
    mIntMax = max;
    mRepeatDelayTime = repeatDelay;
    mAcceptTime = acceptDelay;
    mThreadId = thread::add(thread_handlerCountDownWithRepeat, this, 512);

    if (mThreadId < 0)
        return false;
    else
        return true;
}

void Key::delayForRepeatTime(void)
{
    if (mRepeatDelayTime)
        thread::delay(mRepeatDelayTime);
}

bool Key::isDetect(void)
{
    return mTrigger[0]();
}

void Key::waitWhileDeadtime(void)
{
    if (mDeadtime > 0)
        thread::delay(mDeadtime);
}

void Key::handle(void)
{
    mHandler();
}

void Key::setCycle(bool en)
{
    mCycleFlag = en;
}

void Key::setFlag(void)
{
    if (mPushFlag)
        *mPushFlag = true;
}

void Key::countup(void)
{
    if (mCycleFlag)
    {
        *mInt += 1;
        if (*mInt > mIntMax)
            *mInt = mIntMin;
    }
    else
    {
        if (*mInt < mIntMax)
            *mInt += 1;
    }
}

void Key::countdown(void)
{
    if (mCycleFlag)
    {
        *mInt -= 1;
        if (*mInt < mIntMin)
            *mInt = mIntMax;
    }
    else
    {
        if (*mInt > mIntMin)
            *mInt -= 1;
    }
}

unsigned int Key::getAcceptTime(void)
{
    return mAcceptTime;
}

unsigned int Key::getDeadTime(void)
{
    return mDeadtime;
}

void Key::setDeadTime(unsigned int time)
{
    mDeadtime = time;
}

static void thread_handlerPush(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        key->handle();

        while (key->isDetect() == true)
            thread::yield();
    }
}

static void thread_handlerPushWithRepeat(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        while (key->isDetect())
        {
            key->handle();
            key->delayForRepeatTime();
        }
    }
}

static void thread_handlerPushUsingBoolFlag(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        key->setFlag();

        while (key->isDetect() == true)
            thread::yield();
    }
}

static void thread_handlerReleaseUsingBoolFlag(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        while (key->isDetect() == true)
            thread::yield();

        key->setFlag();
    }
}

static void thread_handlerCountUp(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        key->countup();

        while (key->isDetect() == true)
            thread::yield();
    }
}

static void thread_handlerCountUpWithRepeat(void *arg)
{
    Key *key = (Key *)arg;
    unsigned int acceptTime = key->getAcceptTime(), deadTime = key->getDeadTime();
    unsigned long long time, start;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        start = time::getRunningMsec();
        do
        {
            thread::yield();
            time = time::getRunningMsec();
            if (key->isDetect() == false)
            {
                if (time > start + (unsigned long long)deadTime)
                    key->countup();
                goto start;
            }
        } while (start + (unsigned long long)acceptTime > time);

        while (key->isDetect())
        {
            key->countup();
            key->delayForRepeatTime();
        }
    }
}

static void thread_handlerCountDown(void *arg)
{
    Key *key = (Key *)arg;
    unsigned long long detectTime;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        detectTime = time::getRunningMsec() + key->getDeadTime();

        while (detectTime >= time::getRunningMsec())
        {
            thread::yield();
            if (key->isDetect() == false)
                goto start;
        }

        key->countdown();

        while (key->isDetect() == true)
            thread::yield();
    }
}

static void thread_handlerCountDownWithRepeat(void *arg)
{
    Key *key = (Key *)arg;
    unsigned int acceptTime = key->getAcceptTime(), deadTime = key->getDeadTime();
    unsigned long long time, start;

    while (key->isDetect())
        thread::yield();

    while (1)
    {
    start:
        while (key->isDetect() == false)
            thread::yield();

        start = time::getRunningMsec();
        do
        {
            thread::yield();
            time = time::getRunningMsec();
            if (key->isDetect() == false)
            {
                if (time > start + (unsigned long long)deadTime)
                    key->countdown();
                goto start;
            }
        } while (start + (unsigned long long)acceptTime > time);

        while (key->isDetect())
        {
            key->countdown();
            key->delayForRepeatTime();
        }
    }
}

#endif
