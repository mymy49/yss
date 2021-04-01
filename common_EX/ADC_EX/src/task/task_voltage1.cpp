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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.03.31 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <memory.h>
#include <stdio.h>
#include <task/task_voltage.h>
#include <util/Measure.h>
#include <util/MultiMeasure.h>
#include <util/key.h>
#include <yss/instance.h>
#include <yss/thread.h>

void thread_voltage1(void);

namespace task
{
namespace voltage1
{
unsigned int gId;
drv::Adc *gAdc;
bool (*gGetKey)(void);
Measure gMeasure1, gMeasure2, gMeasure3;

void thread_voltage1(void);

void init(drv::Adc *adc, bool (*getKeyFunc)(void))
{
    gAdc = adc;
    gGetKey = getKeyFunc;
}

signed int start(FunctionQueue *fq)
{
    gMeasure1.setValueP1(0);
    gMeasure1.setValueP2(3.3);
    gMeasure1.setAdcP1(0);
    gMeasure1.setAdcP2(65535);

    gMeasure2.setValueP1(0.3);
    gMeasure2.setValueP2(3.0);
    gMeasure2.setAdcP1(5957);
    gMeasure2.setAdcP2(59578);

    gMeasure3.setValueP1(0.5);
    gMeasure3.setValueP2(2.5);
    gMeasure3.setAdcP1(9929);
    gMeasure3.setAdcP2(49647);

    thread::add(thread_voltage1, 512);

    return 0;
}

signed int stop(FunctionQueue *fq)
{
    if (gId)
    {
        thread::remove(gId);
        gId = 0;
    }

    return 0;
}

void thread_voltage1(void)
{
    char str[128];
    bool flag = false;

    key::clear();
    key::addPushHandler(gGetKey, flag);

    debug_printf("\n전압 출력 예제1 시작!!\n");

    while (1)
    {
        sprintf(str, "%5.3f[V], %5.3f[V], %5.3f[V]\r", gMeasure1.calculate(gAdc->get(0)), gMeasure2.calculate(gAdc->get(1)), gMeasure3.calculate(gAdc->get(2)));
        debug_printf("%s", str);

        if (flag)
        {
            debug_printf("\n전압 출력 예제1 끝!!\n");
            flag = false;
            gFq.add(stop);
            while (true)
                thread::yield();
        }
    }
}
}
}