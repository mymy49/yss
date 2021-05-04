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

#if defined(STM32F1)

#include <__cross_studio_io.h>
#include <drv/gpio/drv_st_gpio_type_B.h>
#include <drv/gpio/drv_st_gpio_type_B_register.h>

namespace drv
{
Gpio::Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), unsigned char exti) : Drv(clockFunc, 0, resetFunc)
{
    mPeri = peri;
    mExti = exti;
}

void Gpio::setExti(unsigned char pin)
{
    setGpioExti(pin, mExti);
}

void Gpio::setAsAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype)
{
    GPIO_TypeDef *port;
    unsigned char pin;
    unsigned char func;

    for (unsigned char i = 0; i < numOfPort; i++)
    {
        port = altport[i].port;
        pin = altport[i].pin;
        func = altport[i].func;
    }
}

void Gpio::setAsInput(unsigned char pin)
{
    setGpioConfig(mPeri, pin, 1);
    setGpioMode(mPeri, pin, 0);
}

void Gpio::setAsOutput(unsigned char pin, unsigned char ospeed, unsigned char otype)
{
    setGpioConfig(mPeri, pin, otype);
    setGpioMode(mPeri, pin, ospeed);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
    setGpioOdr(mPeri, pin, data);
}

void Gpio::setAsAltFunc(unsigned char pin, unsigned char ospeed, bool otype)
{
    setGpioMode(mPeri, pin, ospeed);
    setGpioConfig(mPeri, pin, otype | 0x2);
}

void Gpio::setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
{
    setGpioConfig(mPeri, pin, otype | 0x2);
    setGpioMode(mPeri, pin, ospeed);

    using namespace define::gpio::altfunc;

    switch (altFunc)
    {
    case PB8_I2C1_SCL:
    case PB9_I2C1_SDA:
        setAfioRemapI2c1(true);
        break;
    case PB3_SPI1_SCK:
    case PB4_SPI1_MISO:
    case PB5_SPI1_MOSI:
        setAfioRemapSpi1(true);
        break;
    case PB9_CAN_TX:
    case PB8_CAN_RX:
        AFIO->MAPR &= ~AFIO_MAPR_CAN_REMAP_Msk;
        AFIO->MAPR |= 2 << AFIO_MAPR_CAN_REMAP_Pos;
        break;
    case PA11_CAN_RX:
    case PA12_CAN_TX:
        AFIO->MAPR &= ~AFIO_MAPR_CAN_REMAP_Msk;
        break;
    case PA15_TIM2_CH1_ETR:
    case PB3_TIM2_CH2:
        AFIO->MAPR |= AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk;
        break;
    case PB10_TIM2_CH3:
    case PB11_TIM2_CH4:
        AFIO->MAPR |= AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk;
        break;
    case PC6_TIM3_CH1:
    case PC7_TIM3_CH2:
    case PC8_TIM3_CH3:
    case PC9_TIM3_CH4:
        AFIO->MAPR |= AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk;
        break;
    case PA6_TIM3_CH1:
    case PA7_TIM3_CH2:
        AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk;
        break;
    case PB4_TIM3_CH1:
    case PB5_TIM3_CH2:
        AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk;
        AFIO->MAPR |= AFIO_MAPR_TIM3_REMAP_1;
        break;
    case PB0_TIM3_CH3:
    case PB1_TIM3_CH4:
        AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP_0;
        break;
    }
}

bool Gpio::getData(unsigned char pin)
{
    return getGpioInputData(mPeri, pin);
}

void Gpio::setAsAnalog(unsigned char pin)
{
    setGpioMode(mPeri, pin, 0);
    setGpioConfig(mPeri, pin, 0);
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
    setGpioMode(mPeri, pin, 0);
    setGpioConfig(mPeri, pin, 2);

    if (pupd == define::gpio::pupd::PULL_DOWN)
        mPeri->BRR = 1 << pin;
    else
        mPeri->BSRR = 1 << pin;
}
}
#endif