#include <dev/segment.h>
#include <yss/yss.h>

namespace Segment
{
static void isr_timer(void);

void init(void)
{
    // 세그먼트 포트 출력 설정
    gpioA.setToOutput(1);
    gpioA.setToOutput(2);
    gpioA.setToOutput(3);
    gpioA.setToOutput(4);
    gpioA.setToOutput(6);
    gpioA.setToOutput(7);
    gpioA.setToOutput(8);
    gpioA.setToOutput(9);
    gpioA.setToOutput(10);
    gpioA.setToOutput(11);
    gpioA.setToOutput(12);

    gpioB.setToOutput(2);
    gpioB.setToOutput(10);
    gpioB.setToOutput(11);
    gpioB.setToOutput(12);
    gpioB.setToOutput(13);
    gpioB.setToOutput(14);
    gpioB.setToOutput(15);

    gpioC.setToOutput(13);
    gpioC.setToOutput(14);
    gpioC.setToOutput(15);

    gpioF.setToOutput(6);

    // 타이머14 15Hz 초기화
    timer14.setClockEn(true);
    timer14.init(75); // 15 Hz
    timer14.setUpdateIsr(isr_timer);
    timer14.setUpdateIntEn(true);
    timer14.setIntEn(true);
    timer14.start();
}

static void isr_timer(void)
{
}
}