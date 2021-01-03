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

#include <__cross_studio_io.h>
#include <config.h>
//#include <status.h>
#include <internal/scheduler.h>
#include <string.h>
#include <util/time.h>
#include <yss/malloc.h>
#include <yss/mcu.h>
#include <yss/thread.h>

struct Task
{
    int *stack;
    int *sp;
    int size;
    bool able, mallocated, trigger, pending, ready;
    signed short lockCnt;
    void (*entry)(void *);
    void *var;
};

void trigger_cleanupTask(void);
void terminateThread(void);

namespace trigger
{
void activeTriggerThread(signed int num);
}

Task gTask[MAX_THREAD];
static unsigned short gStartingTrigger[MAX_THREAD];
static unsigned short gNumOfThread = 1;
static unsigned short gCurrentThreadNum;
static Mutex gMutex;
static bool gInitFlag = false;
static signed int gCleanupTaskId;

void initScheduler(void)
{
    gTask[0].able = true;
    gTask[0].mallocated = true;
    gCleanupTaskId = trigger::add(trigger_cleanupTask, 512);
    gInitFlag = true;
}

void trigger_cleanupTask(void)
{
    signed int i;

    gMutex.lock();

    for (i = 0; i < MAX_THREAD; i++)
    {
        if (!gTask[i].able && !gTask[i].trigger && gTask[i].mallocated)
        {
#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
            hfree((void *)gTask[i].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
            lfree((void *)gTask[i].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
            cfree((void *)gTask[i].stack);
#endif
            gTask[i].mallocated = false;
            gNumOfThread--;
        }

        if (gTask[i].trigger && !gTask[i].able && !gTask[i].ready)
        {
            trigger::activeTriggerThread(i);
            if (gTask[i].pending)
            {
                gTask[i].pending = false;
                trigger::run(i);
            }
        }
    }
    gMutex.unlock();
}

namespace thread
{
void terminateThread(void);

signed int add(void (*func)(void *var), void *var, int stackSize)
{
    volatile signed int i;

    gMutex.lock();
    if (gNumOfThread >= MAX_THREAD)
    {
        gMutex.unlock();
#if defined(THREAD_MONITOR)
        debug_printf("쓰레드 생성 실패!! 쓰레드 생성 갯수가 설정된 %d개를 초과했습니다.", MAX_THREAD);
#endif
        return -1;
    }

    for (i = 1; i < MAX_THREAD; i++)
    {
        if (!gTask[i].mallocated)
        {
            gTask[i].mallocated = true;
            break;
        }
    }
#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
    gTask[i].stack = (int *)hmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
    gTask[i].stack = (int *)lmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
    gTask[i].stack = (int *)cmalloc(stackSize);
#endif
    if (!gTask[i].stack)
    {
        gTask[i].mallocated = false;
        gMutex.unlock();
#if defined(THREAD_MONITOR)
        debug_printf("쓰레드 생성 실패!! 스텍 할당에 실패 했습니다.");
#endif
        return -1;
    }
    gTask[i].size = stackSize;
    //		memset(gTask[i].stack, 0xaa, stackSize);
    stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
    gTask[i].stack[stackSize - 1] = 0x61000000;                           // xPSR
    gTask[i].stack[stackSize - 2] = (int)func;                            // PC
    gTask[i].stack[stackSize - 3] = (int)(void (*)(void))terminateThread; // LR
    gTask[i].stack[stackSize - 8] = (int)var;                             // R0
    gTask[i].stack[stackSize - 17 - 16] = 0xfffffffd;                     // R3
    gTask[i].stack[stackSize - 18 - 16] = 0;                              // R2
    gTask[i].stack[stackSize - 19 - 16] = 0xc0000000;                     // R1
    gTask[i].sp = &(gTask[i].stack[stackSize - 19 - 16]);
#else
    gTask[i].stack[stackSize - 1] = 0x61000000;                           // xPSR
    gTask[i].stack[stackSize - 2] = (int)func;                            // PC
    gTask[i].stack[stackSize - 3] = (int)(void (*)(void))terminateThread; // LR
    gTask[i].stack[stackSize - 8] = (int)var;                             // R0
    gTask[i].stack[stackSize - 17] = 0xfffffffd;                          // R3
    gTask[i].sp = &(gTask[i].stack[stackSize - 17]);
#endif
    gTask[i].lockCnt = 0;
    gTask[i].trigger = false;
    gTask[i].entry = func;
    gTask[i].able = true;

    gNumOfThread++;
    gMutex.unlock();
    return i;
}

signed int add(void (*func)(void *), void *var, int stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
    volatile signed int i;

    gMutex.lock();
    if (gNumOfThread >= MAX_THREAD)
    {
        gMutex.unlock();
#if defined(THREAD_MONITOR)
        debug_printf("쓰레드 생성 실패!! 쓰레드 생성 갯수가 설정된 %d개를 초과했습니다.", MAX_THREAD);
#endif
        return -1;
    }

    for (i = 1; i < MAX_THREAD; i++)
    {
        if (!gTask[i].mallocated)
        {
            gTask[i].mallocated = true;
            break;
        }
    }
#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
    gTask[i].stack = (int *)hmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
    gTask[i].stack = (int *)lmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
    gTask[i].stack = (int *)cmalloc(stackSize);
#endif
    if (!gTask[i].stack)
    {
        gTask[i].mallocated = false;
        gMutex.unlock();
#if defined(THREAD_MONITOR)
        debug_printf("쓰레드 생성 실패!! 스텍 할당에 실패 했습니다.");
#endif
        return -1;
    }
    gTask[i].size = stackSize;

    stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
    gTask[i].stack[stackSize - 1] = 0x61000000;                           // xPSR
    gTask[i].stack[stackSize - 2] = (int)func;                            // PC
    gTask[i].stack[stackSize - 3] = (int)(void (*)(void))terminateThread; // LR
    gTask[i].stack[stackSize - 4] = (unsigned int)r12;                    // R12
    gTask[i].stack[stackSize - 8] = (int)var;                             // R0
    gTask[i].stack[stackSize - 9 - 16] = (unsigned int)r11;               // R11
    gTask[i].stack[stackSize - 10 - 16] = (unsigned int)r10;              // R10
    gTask[i].stack[stackSize - 11 - 16] = (unsigned int)r9;               // R9
    gTask[i].stack[stackSize - 12 - 16] = (unsigned int)r8;               // R8
    gTask[i].stack[stackSize - 17 - 16] = 0xfffffffd;                     // R3
    gTask[i].stack[stackSize - 18 - 16] = 0;                              // R2
    gTask[i].stack[stackSize - 19 - 16] = 0xc0000000;                     // R1
    gTask[i].sp = &(gTask[i].stack[stackSize - 19 - 32]);
#else
    gTask[i].stack[stackSize - 1] = 0x61000000;                           // xPSR
    gTask[i].stack[stackSize - 2] = (int)func;                            // PC
    gTask[i].stack[stackSize - 3] = (int)(void (*)(void))terminateThread; // LR
    gTask[i].stack[stackSize - 4] = (unsigned int)r12;                    // R12
    gTask[i].stack[stackSize - 8] = (int)var;                             // R0
    gTask[i].stack[stackSize - 9] = (unsigned int)r11;                    // R11
    gTask[i].stack[stackSize - 10] = (unsigned int)r10;                   // R10
    gTask[i].stack[stackSize - 11] = (unsigned int)r9;                    // R9
    gTask[i].stack[stackSize - 12] = (unsigned int)r8;                    // R8
    gTask[i].stack[stackSize - 17] = 0xfffffffd;                          // R3
    gTask[i].sp = &(gTask[i].stack[stackSize - 17]);
#endif
    gTask[i].lockCnt = 0;
    gTask[i].trigger = false;
    gTask[i].entry = func;
    gTask[i].able = true;

    gNumOfThread++;
    gMutex.unlock();
    return i;
}

signed int add(void (*func)(void), int stackSize)
{
    return add((void (*)(void *))func, 0, stackSize);
}

signed int add(void (*func)(void), int stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
    return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12);
}

void remove(signed int num)
{
    while (gTask[num].lockCnt > 0)
    {
        switchContext();
    }

    gMutex.lock();

    if (num != gCurrentThreadNum && num > 0)
    {
        if (gTask[num].mallocated == true)
        {
            gTask[num].able = false;
            gTask[num].mallocated = false;

#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
            hfree((void *)gTask[num].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
            lfree(gTask[num].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
            cfree(gTask[num].stack);
#endif
            gTask[num].stack = 0;
            gTask[num].sp = 0;
            gTask[num].size = 0;
            gNumOfThread--;
        }
    }

    gMutex.unlock();
}

unsigned short getCurrentThreadNum(void)
{
    return gCurrentThreadNum;
}

void protect(void)
{
    __disable_irq();
    gTask[gCurrentThreadNum].lockCnt++;
    __enable_irq();
}

void protect(unsigned short num)
{
    __disable_irq();
    gTask[num].lockCnt++;
    __enable_irq();
}

void unprotect(void)
{
    __disable_irq();
    gTask[gCurrentThreadNum].lockCnt--;
    __enable_irq();
}

void unprotect(unsigned short num)
{
    __disable_irq();
    gTask[num].lockCnt--;
    __enable_irq();
}

void terminateThread(void)
{
    gTask[gCurrentThreadNum].able = false;
    trigger::run(gCleanupTaskId);
    thread::yield();
}

void delay(unsigned int delayTime)
{
    unsigned long long endTime = time::getRunningUsec() + delayTime * 1000;
    while (1)
    {
        if (time::getRunningUsec() >= endTime)
            return;

        thread::yield();
    }
}

void delayUs(unsigned int delayTime)
{
    unsigned long long endTime = time::getRunningUsec() + delayTime;
    while (1)
    {
        if (time::getRunningUsec() >= endTime)
            return;

        thread::yield();
    }
}
}

namespace trigger
{
void disable(void);

signed int add(void (*func)(void *), void *var, int stackSize)
{
    signed int i;
    gMutex.lock();

    if (gNumOfThread >= MAX_THREAD)
    {
        gMutex.unlock();
        return -1;
    }

    for (i = 1; i < MAX_THREAD; i++)
    {
        if (!gTask[i].mallocated)
        {
            gTask[i].mallocated = true;
            break;
        }
    }
#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
    gTask[i].stack = (int *)hmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
    gTask[i].stack = (int *)lmalloc(stackSize);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
    gTask[i].stack = (int *)cmalloc(stackSize);
#endif
    if (!gTask[i].stack)
    {
        gTask[i].mallocated = false;
        gMutex.unlock();
        return -1;
    }
    gTask[i].size = stackSize;

    gTask[i].var = var;
    gTask[i].lockCnt = 0;
    gTask[i].trigger = true;
    gTask[i].entry = func;
    gTask[i].able = false;
    gTask[i].ready = false;
    gTask[i].pending = false;

    gNumOfThread++;

    activeTriggerThread(i);
    gMutex.unlock();
    return i;
}

signed int add(void (*func)(void), int stackSize)
{
    return add((void (*)(void *))func, 0, stackSize);
}

void remove(signed int num)
{
    gMutex.lock();
    while (gTask[num].lockCnt)
    {
        thread::switchContext();
    }
    if (num != gCurrentThreadNum && num > 0)
    {
        if (gTask[num].mallocated == true)
        {
            gTask[num].able = false;
            gTask[num].mallocated = false;

#if THREAD_STACK_ALLOCATION_PLACE == YSS_H_HEAP
            hfree((void *)gTask[num].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_L_HEAP
            lfree((void *)gTask[num].stack);
#elif THREAD_STACK_ALLOCATION_PLACE == YSS_C_HEAP
            cfree((void *)gTask[num].stack);
#endif
            gTask[num].stack = 0;
            gTask[num].sp = 0;
            gTask[num].size = 0;
            gNumOfThread--;
        }
    }

    gMutex.unlock();
}

void run(signed int num)
{
    __disable_irq();
    if (!gTask[num].able && gTask[num].ready)
    {
        gTask[num].able = true;

        for (unsigned short i = 0; i < MAX_THREAD; i++)
        {
            if (gStartingTrigger[i] == 0)
            {
                gStartingTrigger[i] = num;
                break;
            }
        }

        *(volatile unsigned int *)0xe000ed04 |= (1 << 28);
    }
    else
    {
        gTask[num].pending = true;
    }
    __enable_irq();
}

void activeTriggerThread(signed int num)
{
    unsigned int size = gTask[num].size >> 2;

#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
    gTask[num].stack[size - 1] = 0x61000000;                   // xPSR
    gTask[num].stack[size - 2] = (int)gTask[num].entry;        // PC
    gTask[num].stack[size - 3] = (int)(void (*)(void))disable; // LR
    gTask[num].stack[size - 8] = (int)gTask[num].var;          // R0
    gTask[num].stack[size - 17 - 32] = 0xfffffffd;             // R3
    gTask[num].stack[size - 18 - 32] = 0;                      // R2
    gTask[num].stack[size - 19 - 32] = 0xc0000000;             // R1
    gTask[num].sp = &(gTask[num].stack[size - 19 - 32]);
#else
    gTask[num].stack[size - 1] = 0x61000000;                   // xPSR
    gTask[num].stack[size - 2] = (int)gTask[num].entry;        // PC
    gTask[num].stack[size - 3] = (int)(void (*)(void))disable; // LR
    gTask[num].stack[size - 8] = (int)gTask[num].var;          // R0
    gTask[num].stack[size - 17] = 0xfffffffd;                  // R3
    gTask[num].sp = &(gTask[num].stack[size - 17]);
#endif
    gTask[num].ready = true;
}

void disable(void)
{
    __disable_irq();
    gTask[gCurrentThreadNum].ready = false;
    gTask[gCurrentThreadNum].able = false;
    trigger::run(gCleanupTaskId);
    __enable_irq();
    thread::yield();
}

void protect(void)
{
    __disable_irq();
    gTask[gCurrentThreadNum].lockCnt++;
    __enable_irq();
}

void protect(unsigned short num)
{
    __disable_irq();
    gTask[num].lockCnt++;
    __enable_irq();
}

void unprotect(void)
{
    __disable_irq();
    gTask[gCurrentThreadNum].lockCnt--;
    __enable_irq();

    if (gTask[gCurrentThreadNum].lockCnt == 0)
        thread::switchContext();
}

void unprotect(unsigned short num)
{
    __disable_irq();
    gTask[num].lockCnt--;
    __enable_irq();
}
}

extern "C"
{
    static bool gTriggerFlag = false;
    static int gLastNormalThread = 0;

    volatile int *getNextContext(int *sp)
    {
        int i = 0;
        gTask[gCurrentThreadNum].sp = sp;

        __disable_irq();
        if (gStartingTrigger[0])
        {
            gCurrentThreadNum = gStartingTrigger[0];

            if (gTriggerFlag == false)
                gLastNormalThread = gCurrentThreadNum;
            gTriggerFlag = true;

            for (i = 0; i < MAX_THREAD - 1; i++)
            {
                if (gStartingTrigger[i + 1])
                    gStartingTrigger[i] = gStartingTrigger[i + 1];
                else
                    break;
            }
            gStartingTrigger[i] = 0;
            __enable_irq();

            if (!gTask[gCurrentThreadNum].able)
                goto finding;
        }
        else
        {
        finding:
            __enable_irq();
            if (gTriggerFlag)
            {
                gCurrentThreadNum = gLastNormalThread;
                gTriggerFlag = false;
            }

            gCurrentThreadNum++;
            while (!gTask[gCurrentThreadNum].able)
            {
                gCurrentThreadNum++;
                if (gCurrentThreadNum >= MAX_THREAD)
                {
                    gCurrentThreadNum = 0;
                    // 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
                    time::getRunningUsec();
                }
            }
        }
        sp = (int *)gTask[gCurrentThreadNum].sp;
        return sp;
    }
}