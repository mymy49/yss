#include <dev/segment.h>
#include <yss/yss.h>

#define setCtrl1() GPIOA->BSRR = 1 << 3
#define resetCtrl1() GPIOA->BRR = 1 << 3

#define setCtrl2() GPIOA->BSRR = 1 << 2
#define resetCtrl2() GPIOA->BRR = 1 << 2

#define setCtrl3() GPIOA->BSRR = 1 << 1
#define resetCtrl3() GPIOA->BRR = 1 << 1

#define setCtrl4() GPIOA->BSRR = 1 << 4
#define resetCtrl4() GPIOA->BRR = 1 << 4

#define setCtrl5() GPIOA->BSRR = 1 << 6
#define resetCtrl5() GPIOA->BRR = 1 << 6

#define setSegA1() GPIOA->BSRR = 1 << 9
#define resetSegA1() GPIOA->BRR = 1 << 9

#define setSegA2() GPIOF->BSRR = 1 << 6
#define resetSegA2() GPIOF->BRR = 1 << 6

#define setSegB() GPIOA->BSRR = 1 << 11
#define resetSegB() GPIOA->BRR = 1 << 11

#define setSegC() GPIOC->BSRR = 1 << 13
#define resetSegC() GPIOC->BRR = 1 << 13

#define setSegD1() GPIOB->BSRR = 1 << 2
#define resetSegD1() GPIOB->BRR = 1 << 2

#define setSegD2() GPIOA->BSRR = 1 << 7
#define resetSegD2() GPIOA->BRR = 1 << 7

#define setSegE() GPIOB->BSRR = 1 << 10
#define resetSegE() GPIOB->BRR = 1 << 10

#define setSegF() GPIOB->BSRR = 1 << 14
#define resetSegF() GPIOB->BRR = 1 << 14

#define setSegG1() GPIOB->BSRR = 1 << 13
#define resetSegG1() GPIOB->BRR = 1 << 13

#define setSegG2() GPIOA->BSRR = 1 << 10
#define resetSegG2() GPIOA->BRR = 1 << 10

#define setSegH() GPIOB->BSRR = 1 << 15
#define resetSegH() GPIOB->BRR = 1 << 15

#define setSegI() GPIOA->BSRR = 1 << 8
#define resetSegI() GPIOA->BRR = 1 << 8

#define setSegJ() GPIOA->BSRR = 1 << 12
#define resetSegJ() GPIOA->BRR = 1 << 12

#define setSegK() GPIOB->BSRR = 1 << 11
#define resetSegK() GPIOB->BRR = 1 << 11

#define setSegL() GPIOB->BSRR = 1 << 12
#define resetSegL() GPIOB->BRR = 1 << 12

#define setSegM() GPIOC->BSRR = 1 << 15
#define resetSegM() GPIOC->BRR = 1 << 15

#define setSegDp() GPIOC->BSRR = 1 << 14
#define resetSegDp() GPIOC->BRR = 1 << 14

#define MAX_FONT 212
#define START_ASCII 43

namespace Segment
{
void isr_timer(void);
extern const unsigned short gFont[MAX_FONT];
unsigned char gSegIndex;
char gStr[5];

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
    timer14.init(300); // 60 Hz
    timer14.setUpdateIsr(isr_timer);
    timer14.setUpdateIntEn(true);
    timer14.setIntEn(true);
    timer14.start();
}

inline void setChar(unsigned short font)
{
    if (font & 1 << 0)
        setSegA1();
    else
        resetSegA1();

    if (font & 1 << 1)
        setSegA2();
    else
        resetSegA2();

    if (font & 1 << 2)
        setSegB();
    else
        resetSegB();

    if (font & 1 << 3)
        setSegC();
    else
        resetSegC();

    if (font & 1 << 4)
        setSegD1();
    else
        resetSegD1();

    if (font & 1 << 5)
        setSegD2();
    else
        resetSegD2();

    if (font & 1 << 6)
        setSegE();
    else
        resetSegE();

    if (font & 1 << 7)
        setSegF();
    else
        resetSegF();

    if (font & 1 << 8)
        setSegG1();
    else
        resetSegG1();

    if (font & 1 << 9)
        setSegG2();
    else
        resetSegG2();

    if (font & 1 << 10)
        setSegH();
    else
        resetSegH();

    if (font & 1 << 11)
        setSegI();
    else
        resetSegI();

    if (font & 1 << 12)
        setSegJ();
    else
        resetSegJ();

    if (font & 1 << 13)
        setSegK();
    else
        resetSegK();

    if (font & 1 << 14)
        setSegL();
    else
        resetSegL();

    if (font & 1 << 15)
        setSegM();
    else
        resetSegM();
}

void setChar1(char ascii)
{
    gStr[0] = ascii;
}

void setChar2(char ascii)
{
    gStr[1] = ascii;
}

void setChar3(char ascii)
{
    gStr[2] = ascii;
}

void setChar4(char ascii)
{
    gStr[3] = ascii;
}

void setChar5(char ascii)
{
    gStr[4] = ascii;
}

void setChar(unsigned char index, char ascii)
{
    if (index <= 4)
        gStr[index] = ascii;
}

void setNumber(unsigned int num)
{
    unsigned int buf;

    buf = num % 10;
    num /= 10;
    setChar5('0' + buf);

    buf = num % 10;
    num /= 10;
    setChar4('0' + buf);

    buf = num % 10;
    num /= 10;
    setChar3('0' + buf);

    buf = num % 10;
    num /= 10;
    setChar2('0' + buf);

    buf = num % 10;
    setChar1('0' + buf);
}

void isr_timer(void)
{
    char ch;

    ch = gStr[gSegIndex] - START_ASCII;
    if (ch > MAX_FONT)
        ch = ' ';

    switch (gSegIndex++)
    {
    case 0:
        setCtrl1();
        setChar(gFont[ch]);
        resetCtrl5();
        break;
    case 1:
        setCtrl5();
        setChar(gFont[ch]);
        resetCtrl4();
        break;
    case 2:
        setCtrl4();
        setChar(gFont[ch]);
        resetCtrl3();
        break;
    case 3:
        setCtrl3();
        setChar(gFont[ch]);
        resetCtrl2();
        break;
    case 4:
        setCtrl2();
        setChar(gFont[ch]);
        resetCtrl1();
        break;
    }

    if (gSegIndex > 4)
        gSegIndex = 0;
}

// 아스키 코드 43부터 시작
// 비트 [3]C  [2]B  [1]A2 [0]A1
//     [7]F  [6]E  [5]D2 [4]D1
//     [11]I [10]H [9]G2 [8]G1
//     [15]M [14]L [13]K [12]J
const unsigned short gFont[212] =
    {
        // 특수문자 + 부터
        0x4B00,
        0x0000,
        0x0300,
        0x0000,
        0x3000,

        // 숫자 0~9
        0x00FF,
        0x000C,
        0x0377,
        0x033F,
        0x038C,
        0x03BB,
        0x03FB,
        0x008F,
        0x03FF,
        0x03BF,
};

}