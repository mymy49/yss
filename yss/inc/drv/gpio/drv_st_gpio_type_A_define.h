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

#ifndef YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_
#define YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_

#include <yss/mcu.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)

namespace define
{
namespace gpio
{
namespace altfunc
{
#if defined(STM32F7) || defined(STM32F4)
enum
{
    SYS_AF0 = 0,
    TIM1_AF1 = 1,
    TIM2_AF1 = 1,
    TIM3_AF2 = 2,
    TIM4_AF2 = 2,
    TIM5_AF2 = 2,
    TIM8_AF3 = 3,
    TIM9_AF3 = 3,
    TIM10_AF3 = 3,
    TIM11_AF3 = 3,
    I2C1_AF4 = 4,
    I2C2_AF4 = 4,
    I2C3_AF4 = 4,
    I2C4_AF4 = 4,
    SPI_AF5 = 5,
    SPI_AF6 = 6,
    SPI_AF7 = 7,
    USART1_AF7 = 7,
    USART2_AF7 = 7,
    USART3_AF7 = 7,
    UART5_AF7 = 7,
    USART6_AF8 = 8,
    UART4_AF8 = 8,
    UART5_AF8 = 8,
    UART7_AF8 = 8,
    UART8_AF8 = 8,
    CAN1_AF9 = 9,
    CAN2_AF9 = 9,
    TIM12_AF9 = 9,
    TIM13_AF9 = 9,
    TIM14_AF9 = 9,
    LCD_AF9 = 9,
    QUADSPI_AF9 = 9,
    OTG2_HS_AF10 = 10,
    OTG1_FS_AF10 = 10,
    QUADSPI_AF10 = 10,
    ETH_AF11 = 11,
    OTG1_FS_AF11 = 11,
    FMC_AF12 = 12,
    SDRAM_AF12 = 12,
    SDMMC1_AF12 = 12,
    OTG2_FS_AF12 = 12,
    DCMI_AF13 = 13,
    LCD_AF14 = 14,
    SYS_AF15 = 15
};

#elif defined(STM32G4)

enum
{
    SYS_AF0 = 0,
    I2C4_AF0 = 0,

    LPTIM1_AF1 = 1,
    TIM2_AF1 = 1,
    TIM5_AF1 = 1,
    TIM15_AF1 = 1,
    TIM16_AF1 = 1,
    TIM17_AF1 = 1,

    I2C1_AF2 = 2,
    I2C3_AF2 = 2,
    TIM1_AF2 = 2,
    TIM2_AF2 = 2,
    TIM3_AF2 = 2,
    TIM4_AF2 = 2,
    TIM5_AF2 = 2,
    TIM8_AF2 = 2,
    TIM15_AF2 = 2,
    TIM20_AF2 = 2,
    COMP1_AF2 = 2,

    QUADSPI1_AF3 = 3,
    I2C3_AF3 = 3,
    I2C4_AF3 = 3,
    SAI1_AF3 = 3,
    USB_AF3 = 3,
    HRTIM1_AF3 = 3,
    TIM8_AF3 = 3,
    TIM15_AF3 = 3,
    TIM20_AF3 = 3,
    COMP3_AF3 = 3,

    I2C1_AF4 = 4,
    I2C2_AF4 = 4,
    I2C3_AF4 = 4,
    I2C4_AF4 = 4,
    TIM1_AF4 = 4,
    TIM8_AF4 = 4,
    TIM16_AF4 = 4,
    TIM17_AF4 = 4,

    QUADSPI1_AF5 = 5,
    SPI1_AF5 = 5,
    SPI2_AF5 = 5,
    SPI3_AF5 = 5,
    SPI4_AF5 = 5,
    I2S2_AF5 = 5,
    I2S3_AF5 = 5,
    I2C4_AF5 = 5,
    UART4_AF5 = 5,
    UART5_AF5 = 5,
    TIM8_AF5 = 5,
    Infrared_AF5 = 5,

    QUADSPI1_AF6 = 6,
    SPI2_AF6 = 6,
    SPI3_AF6 = 6,
    I2S2_AF6 = 6,
    I2S3_AF6 = 6,
    TIM1_AF6 = 6,
    TIM5_AF6 = 6,
    TIM8_AF6 = 6,
    TIM20_AF6 = 6,
    Infrared_AF6 = 6,

    USART1_AF7 = 7,
    USART2_AF7 = 7,
    USART3_AF7 = 7,
    FDCAN_AF7 = 7,
    COMP5_AF7 = 7,
    COMP6_AF7 = 7,
    COMP7_AF7 = 7,

    I2C3_AF8 = 8,
    I2C4_AF8 = 8,
    UART4_AF8 = 8,
    UART5_AF8 = 8,
    LPUART1_AF8 = 8,
    COMP1_AF8 = 8,
    COMP2_AF8 = 8,
    COMP3_AF8 = 8,
    COMP4_AF8 = 8,
    COMP5_AF8 = 8,
    COMP6_AF8 = 8,
    COMP7_AF8 = 8,

    FDCAN_AF9 = 9,
    TIM1_AF9 = 9,
    TIM8_AF9 = 9,
    TIM15_AF9 = 9,
    FDCAN1_AF9 = 9,
    FDCAN2_AF9 = 9,

    QUADSPI1_AF10 = 10,
    TIM2_AF10 = 10,
    TIM3_AF10 = 10,
    TIM4_AF10 = 10,
    TIM8_AF10 = 10,
    TIM17_AF10 = 10,

    LPTIM1_AF11 = 11,
    TIM1_AF11 = 11,
    TIM8_AF11 = 11,
    FDCAN1_AF11 = 11,
    FDCAN3_AF11 = 11,

    FMC_AF12 = 12,
    LPUART1_AF12 = 12,
    SAI1_AF12 = 12,
    HRTIM1_AF12 = 12,
    TIM1_AF12 = 12,

    SAI1_AF13 = 13,
    HRTIM1_AF13 = 13,
    OPAMP2_AF13 = 13,

    UART4_AF14 = 14,
    UART5_AF14 = 14,
    SAI1_AF14 = 14,
    TIM2_AF14 = 14,
    TIM15_AF14 = 14,
    UCPD1_AF14 = 14,

    EVENT_AF15 = 15
};
#elif defined(STM32L0)

enum
{
    SYS_AF0 = 0,
    SPI1_AF0 = 0,
    SPI2_AF0 = 0,
    I2S2_AF0 = 0,
    USART1_AF0 = 0,
    USART2_AF0 = 0,
    LPUART1_AF0 = 0,
    USB_AF0 = 0,
    LPTIM1_AF0 = 0,
    TSC_AF0 = 0,
    TIM2_AF0 = 0,
    TIM21_AF0 = 0,
    TIM22_AF0 = 0,
    EVENTOUT_AF0 = 0,

    SPI1_AF1 = 1,
    SPI2_AF1 = 1,
    I2S2_AF1 = 1,
    I2C1_AF1 = 1,
    LCD_AF1 = 1,
    TIM2_AF1 = 1,
    TIM21_AF1 = 1,

    SPI1_AF2 = 2,
    SPI2_AF2 = 2,
    I2S2_AF2 = 2,
    LPUART1_AF2 = 2,
    USART5_AF2 = 2,
    USB_AF2 = 2,
    LPTIM1_AF2 = 2,
    TIM2_AF2 = 2,
    TIM3_AF2 = 2,
    EVENTOUT_AF2 = 2,
    SYS_AF2 = 2,

    I2C1_AF3 = 3,
    TSC_AF3 = 3,
    EVENTOUT_AF3 = 3,

    I2C1_AF4 = 4,
    USART1_AF4 = 4,
    USART2_AF4 = 4,
    LPUART1_AF4 = 4,
    TIM3_AF4 = 4,
    TIM22_AF4 = 4,
    EVENTOUT_AF4 = 4,

    SPI2_AF5 = 5,
    I2S2_AF5 = 5,
    I2C2_AF5 = 5,
    USART1_AF5 = 5,
    TIM21_AF5 = 5,
    EVENTOUT_AF5 = 5,

    I2C1_AF6 = 6,
    I2C2_AF6 = 6,
    LPUART1_AF6 = 6,
    USART4_AF6 = 6,
    UASRT5_AF6 = 6,
    TIM21_AF6 = 6,
    EVENTOUT_AF6 = 6,

    I2C3_AF7 = 7,
    LPUART1_AF7 = 7,
    COMP1_AF7 = 7,
    COMP2_AF7 = 7,
    TIM3_AF7 = 7
};

#elif defined(STM32F0)

enum
{
    PA0_USART1_CTS = 1,
    PA0_USART2_CTS = 1,
    PA0_UART4_TX = 4,

    PA1_EVENT_OUT = 0,
    PA1_USART1_RTS = 1,
    PA1_USART2_RTS = 1,
    PA1_UART4_RX = 4,
    PA1_TIM15_CH1N = 5,

    PA2_TIM15_CH1 = 0,
    PA2_USART1_TX = 1,
    PA2_USART2_TX = 1,

    PA3_TIM15_CH2 = 0,
    PA3_USART1_RX = 1,
    PA3_USART2_RX = 1,

    PA4_SPI1_NSS = 0,
    PA4_USART1_CK = 1,
    PA4_USART2_CK = 1,
    PA4_TIM14_CH1 = 4,
    PA4_USART6_TX = 5,

    PA5_SPI1_SCK = 0,
    PA5_USART6_RX = 5,

    PA6_SPI1_MISO = 0,
    PA6_TIM3_CH1 = 1,
    PA6_TIM1_BKIN = 2,
    PA6_USART3_CTS = 4,
    PA6_TIM16_CH1 = 5,
    PA6_EVENTOUT = 6,

    PA7_SPI1_MOSI = 0,
    PA7_TIM3_CH2 = 1,
    PA7_TIM1_CH1N = 2,
    PA7_TIM14_CH1 = 4,
    PA7_TIM17_CH1 = 5,
    PA7_EVENTOUT = 6,

    PA8_MCO = 0,
    PA8_USART1_CK = 1,
    PA8_TIM1_CH1 = 2,
    PA8_EVENTOUT = 3,

    PA9_TIM15_BKIN = 0,
    PA9_USART1_TX = 1,
    PA9_TIM1_CH2 = 2,
    PA9_I2C1_SCL = 4,
    PA9_MCO = 5,

    PA10_TIM17_BKIN = 0,
    PA10_USART1_RX = 1,
    PA10_TIM1_CH3 = 2,
    PA10_I2C1_SDA = 4,

    PA11_EVENTOUT = 0,
    PA11_USART1_CTS = 1,
    PA11_TIM1_CH4 = 2,
    PA11_SCL = 5,

    PA12_EVENTOUT = 0,
    PA12_USART1_RTS = 1,
    PA12_TIM1_ETR = 2,
    PA12_SDA = 5,

    PA13_SWDIO = 0,
    PA13_IR_OUT = 1,

    PA14_SWCLK = 0,
    PA14_USART1_TX = 1,
    PA14_USART2_TX = 1,

    PA15_SPI1_NSS = 0,
    PA15_USART1_RX = 1,
    PA15_USART2_RX = 1,

    PB0_EVENTOUT = 0,
    PB0_TIM3_CH3 = 1,
    PB0_TIM1_CH2N = 2,
    PB0_USART3_CK = 4,

    PB1_TIM14_CH1 = 0,
    PB1_TIM3_CH4 = 1,
    PB1_TIM1_CH3N = 2,
    PB1_USART3_RTS = 4,

    PB3_SPI1_SCK = 0,
    PB3_EVENTOUT = 1,
    PB3_USART5_TX = 4,

    PB4_SPI1_MISO = 0,
    PB4_TIM3_CH1 = 1,
    PB4_EVENTOUT = 2,
    PB4_USART5_RX = 4,
    PB4_TIM17_BKIN = 5,

    PB5_SPI1_MOSI = 0,
    PB5_TIM3_CH2 = 1,
    PB5_TIM16_BKIN = 2,
    PB5_I2C1_SMBA = 3,
    PB5_USART5_CK_RTS = 4,

    PB6_USART1_TX = 0,
    PB6_I2C1_SCL = 1,
    PB6_TIM16_CH1N = 2,

    PB7_USART1_RX = 0,
    PB7_I2C1_SDA = 1,
    PB7_TIM17_CH1N = 2,
    PB7_USART4_CTS = 4,

    PB8_I2C1_SCL = 1,
    PB8_TIM16_CH1 = 2,

    PB9_IR_OUT = 0,
    PB9_I2C1_SDA = 1,
    PB9_TIM17_CH1 = 2,
    PB9_EVENTOUT = 3,
    PB9_SPI2_NSS = 5,

    PB10_I2C1_SCL = 1,
    PB10_I2C2_SCL = 1,
    PB10_USART3_TX = 4,
    PB10_SPI2_SCK = 5,

    PB11_EVENTOUT = 0,
    PB11_I2C1_SDA = 1,
    PB11_I2C2_SDA = 1,
    PB11_USART3_RX = 4,

    PB12_SPI1_NSS = 0,
    PB12_SPI2_NSS = 0,
    PB12_EVENTOUT = 1,
    PB12_TIM1_BKIN = 2,
    PB12_USART3_RTS = 4,
    PB12_TIM15 = 5,

    PB13_SPI1_SCK = 0,
    PB13_SPI2_SCK = 0,
    PB13_TIM1_CH1N = 2,
    PB13_USART3_CTS = 4,
    PB13_I2C2_SCL = 5,

    PB14_SPI1_MISO = 0,
    PB14_SPI2_MISO = 0,
    PB14_TIM15_CH1 = 1,
    PB14_TIM1_CH2N = 2,
    PB14_USART3_RTS = 4,
    PB14_I2C2_SDA = 5,

    PB15_SPI1_MOSI = 0,
    PB15_SPI2_MOSI = 0,
    PB15_TIM15_CH2 = 1,
    PB15_TIM1_CH3N = 2,
    PB15_TIM15_CH1N = 3,

    PC0_EVENTOUT = 0,
    PC0_USART6_TX = 2,

    PC1_EVENTOUT = 0,
    PC1_USART6_RX = 2,

    PC2_EVENTOUT = 0,
    PC2_SPI2_MISO = 1,

    PC3_EVENTOUT = 0,
    PC3_SPI2_MOSI = 1,

    PC4_EVENTOUT = 0,
    PC4_USART3_TX = 1,

    PC5_USART3_RX = 1,

    PC6_TIM3_CH1 = 0,

    PC7_TIM3_CH2 = 0,

    PC8_TIM3_CH3 = 0,

    PC9_TIM3_CH4 = 0,

    PC10_USART4_TX = 0,
    PC10_USART3_TX = 1,

    PC11_USART4_RX = 0,
    PC11_USART3_RX = 1,

    PC12_USART4_CK = 0,
    PC12_USART3_CK = 1,
    PC12_USART5_TX = 2,

    PD2_TIM3_ETR = 0,
    PD2_USART3_RTS = 1,
    PD2_USART5_RX = 2,

    PF0_I2C1_SDA = 0,

    PF1_I2C1_SCL = 1,

    PF4_EVENTOUT = 0,

    PF5_EVENTOUT = 0,

    PF6_I2C1_SCL = 0,
    PF6_I2C2_SCL = 0,

    PF7_I2C1_SDA = 0,
    PF7_I2C2_SDA = 0,
};
#endif
}

namespace ospeed
{
enum
{
    LOW = 0,
    MID = 1,
    FAST = 2,
    HIGH = 3,
};
}

namespace otype
{
enum
{
    PUSH_PULL = 0,
    OPEN_DRAIN = 1,
};
}

namespace mode
{
enum
{
    INPUT = 0,
    OUTPUT = 1,
    ALT_FUNC = 2,
    ANALOG = 3
};
}

namespace pupd
{
enum
{
    NONE = 0,
    PULL_UP = 1,
    PULL_DOWN = 2
};
}

namespace exti
{
enum
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5,
    PORTG = 6,
    PORTH = 7,
    PORTI = 8,
    PORTJ = 9,
    PORTK = 10
};
}

}
}

#endif

#endif