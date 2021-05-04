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

#include <bsp.h>
#include <drv/peripherals.h>
#include <mod/cputft/ILI9341.h>
#include <mod/rtouch/STMPE811.h>
#include <mod/sdram/IS42S16400J_7TL.h>
#include <mod/tft/SF_TC240T_9370_T.h>

#include <__cross_studio_io.h>

#include <util/time.h>

void initSdram(void)
{
    config::gpio::AltFunc sdramPort[38]{
        {GPIOF, 0, define::gpio::altfunc::SDRAM_AF12},  //	ADDR0
        {GPIOF, 1, define::gpio::altfunc::SDRAM_AF12},  //	ADDR1
        {GPIOF, 2, define::gpio::altfunc::SDRAM_AF12},  //	ADDR2
        {GPIOF, 3, define::gpio::altfunc::SDRAM_AF12},  //	ADDR3
        {GPIOF, 4, define::gpio::altfunc::SDRAM_AF12},  //	ADDR4
        {GPIOF, 5, define::gpio::altfunc::SDRAM_AF12},  //	ADDR5
        {GPIOF, 12, define::gpio::altfunc::SDRAM_AF12}, //	ADDR6
        {GPIOF, 13, define::gpio::altfunc::SDRAM_AF12}, //	ADDR7
        {GPIOF, 14, define::gpio::altfunc::SDRAM_AF12}, //	ADDR8
        {GPIOF, 15, define::gpio::altfunc::SDRAM_AF12}, //	ADDR9
        {GPIOG, 0, define::gpio::altfunc::SDRAM_AF12},  //	ADDR10
        {GPIOG, 1, define::gpio::altfunc::SDRAM_AF12},  //	ADDR11
        {GPIOG, 4, define::gpio::altfunc::SDRAM_AF12},  //	BA0
        {GPIOG, 5, define::gpio::altfunc::SDRAM_AF12},  //	BA1
        {GPIOD, 14, define::gpio::altfunc::SDRAM_AF12}, //	DATA0
        {GPIOD, 15, define::gpio::altfunc::SDRAM_AF12}, //	DATA1
        {GPIOD, 0, define::gpio::altfunc::SDRAM_AF12},  //	DATA2
        {GPIOD, 1, define::gpio::altfunc::SDRAM_AF12},  //	DATA3
        {GPIOE, 7, define::gpio::altfunc::SDRAM_AF12},  //	DATA4
        {GPIOE, 8, define::gpio::altfunc::SDRAM_AF12},  //	DATA5
        {GPIOE, 9, define::gpio::altfunc::SDRAM_AF12},  //	DATA6
        {GPIOE, 10, define::gpio::altfunc::SDRAM_AF12}, //	DATA7
        {GPIOE, 11, define::gpio::altfunc::SDRAM_AF12}, //	DATA8
        {GPIOE, 12, define::gpio::altfunc::SDRAM_AF12}, //	DATA9
        {GPIOE, 13, define::gpio::altfunc::SDRAM_AF12}, //	DATA10
        {GPIOE, 14, define::gpio::altfunc::SDRAM_AF12}, //	DATA11
        {GPIOE, 15, define::gpio::altfunc::SDRAM_AF12}, //	DATA12
        {GPIOD, 8, define::gpio::altfunc::SDRAM_AF12},  //	DATA13
        {GPIOD, 9, define::gpio::altfunc::SDRAM_AF12},  //	DATA14
        {GPIOD, 10, define::gpio::altfunc::SDRAM_AF12}, //	DATA15
        {GPIOE, 0, define::gpio::altfunc::SDRAM_AF12},  //	NBL0
        {GPIOE, 1, define::gpio::altfunc::SDRAM_AF12},  //	NBL1
        {GPIOG, 8, define::gpio::altfunc::SDRAM_AF12},  //	SDCLK
        {GPIOC, 0, define::gpio::altfunc::SDRAM_AF12},  //	SDNWE
        {GPIOF, 11, define::gpio::altfunc::SDRAM_AF12}, //	SDNRAS
        {GPIOG, 15, define::gpio::altfunc::SDRAM_AF12}, //	SDNCAS
        {GPIOB, 5, define::gpio::altfunc::SDRAM_AF12},  //	SDCKE
        {GPIOB, 6, define::gpio::altfunc::SDRAM_AF12}   //	SDNE
    };

    gpioA.setAsAltFunc(sdramPort, 38, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);

    clock.peripheral.setFmcEn(true);
    sdram.init(define::sdram::bank::BANK2, mod::sdram::IS42S16400J_7TL);
}

namespace bsp
{
mod::tft::SF_TC240T_9370_T lcd1;
mod::rtouch::STMPE811 touch;

void init(void)
{
    // LED 초기화
    gpioG.setAsOutput(13, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
    gpioG.setAsOutput(14, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);

    // SPI5 초기화
    gpioF.setAsAltFunc(7, define::gpio::altfunc::SPI_AF5, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // SCK
    gpioF.setAsAltFunc(9, define::gpio::altfunc::SPI_AF5, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // MOSI

    spi5.setClockEn(true);
    spi5.init();
    spi5.setIntEn(true);

    // 그래픽 LCD 초기화
    gpioB.setAsAltFunc((unsigned char)0, define::gpio::altfunc::LCD_AF9, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // R3
    gpioA.setAsAltFunc(11, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);              // R4
    gpioA.setAsAltFunc(12, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);              // R5
    gpioB.setAsAltFunc(1, define::gpio::altfunc::LCD_AF9, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);                // R6
    gpioG.setAsAltFunc(6, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);               // R7

    gpioA.setAsAltFunc(6, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // G2
    gpioG.setAsAltFunc(10, define::gpio::altfunc::LCD_AF9, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // G3
    gpioB.setAsAltFunc(10, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // G4
    gpioB.setAsAltFunc(11, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // G5
    gpioC.setAsAltFunc(7, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // G6
    gpioD.setAsAltFunc(3, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // G7

    gpioG.setAsAltFunc(11, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // B3
    gpioG.setAsAltFunc(12, define::gpio::altfunc::LCD_AF9, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // B4
    gpioA.setAsAltFunc(3, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // B5
    gpioB.setAsAltFunc(8, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // B6
    gpioB.setAsAltFunc(9, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // B7

    gpioA.setAsAltFunc(4, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // VSYNC
    gpioC.setAsAltFunc(6, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // HSYNC
    gpioF.setAsAltFunc(10, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // EN
    gpioG.setAsAltFunc(7, define::gpio::altfunc::LCD_AF14, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // CLK

    gpioC.setAsOutput(2, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);  // CS
    gpioD.setAsOutput(13, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL); // DCX

    config::gpio::Set lcdCs = {&gpioC, 2};
    config::gpio::Set lcdDcx = {&gpioD, 13};

    bsp::lcd1.init(spi5, lcdCs, lcdDcx);
    ltdc.setClockEn(true);
    ltdc.init(lcd1.getConfig());
    ltdc.setIntEn(true);

    // DMA2D 초기화
    dma2d.setClockEn(true);
    dma2d.init();
    dma2d.setIntEn(true);

    // I2C 초기화
    gpioA.setAsAltFunc(8, define::gpio::altfunc::I2C3_AF4, define::gpio::ospeed::MID, define::gpio::otype::OPEN_DRAIN);
    gpioC.setAsAltFunc(9, define::gpio::altfunc::I2C3_AF4, define::gpio::ospeed::MID, define::gpio::otype::OPEN_DRAIN);

    i2c3.setClockEn(true);
    i2c3.init(define::i2c::speed::STANDARD);
    i2c3.setIntEn(true);

    config::gpio::Set touchIsr = {&gpioA, 15};

    touch.init(i2c3, touchIsr);
    touch.setCalibration(3440, 690, 500, 3650);
    touch.setSize(240, 320);

    //UART Init
    gpioA.setAsAltFunc(9, define::gpio::altfunc::USART1_AF7, define::gpio::ospeed::LOW, define::gpio::otype::PUSH_PULL);
    gpioA.setAsAltFunc(10, define::gpio::altfunc::USART1_AF7, define::gpio::ospeed::LOW, define::gpio::otype::PUSH_PULL);

    uart1.setClockEn(true);
    uart1.setIntEn(true);
    uart1.init(9600, 512);
    uart1.setIntEn(true);
}
}