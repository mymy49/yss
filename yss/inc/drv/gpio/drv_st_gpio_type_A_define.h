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

#ifndef YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_
#define YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                                                                 \
    defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                                 \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

namespace define
{
namespace gpio
{
namespace altfunc
{
#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)
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

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)
enum
{
    SYS_AF0 = 0,
    LPTIM1_AF1 = 1,
    TIM2_AF1 = 1,
    TIM5_AF1 = 1,
    TIM15_AF1 = 1,
    TIM16_AF1 = 1,
    TIM17_AF1 = 1,

    I2C3_AF2 = 2,
    TIM1_AF2 = 2,
    TIM2_AF2 = 2,
    TIM3_AF2 = 2,
    TIM4_AF2 = 2,
    TIM8_AF2 = 2,
    TIM15_AF2 = 2,
    GPCOMP1_AF2 = 2,

    I2C3_AF3 = 3,
    SAI1_AF3 = 3,
    USB_AF3 = 3,
    TIM8_AF3 = 3,
    TIM15_AF3 = 3,
    GPCOMP3_AF3 = 3,

    I2C1_AF4 = 4,
    I2C2_AF4 = 4,
    I2C3_AF4 = 4,
    TIM1_AF4 = 4,
    TIM8_AF4 = 4,
    TIM16_AF4 = 4,
    TIM17_AF4 = 4,

    SPI1_AF5 = 5,
    SPI2_AF5 = 5,
    SPI3_AF5 = 5,
    I2S2_AF5 = 5,
    I2S3_AF5 = 5,
    UART4_AF5 = 5,
    TIM8_AF5 = 5,
    Infrared_AF5 = 5,

    SPI2_AF6 = 6,
    SPI3_AF6 = 6,
    I2S2_AF6 = 6,
    I2S3_AF6 = 6,
    TIM1_AF6 = 6,
    TIM8_AF6 = 6,
    Infrared_AF6 = 6,

    USART1_AF7 = 7,
    USART2_AF7 = 7,
    USART3_AF7 = 7,

    I2C3_AF8 = 8,
    I2C4_AF8 = 8,
    UART4_AF8 = 8,
    LPUART1_AF8 = 8,
    GPCOMP1_AF8 = 8,
    GPCOMP2_AF8 = 8,
    GPCOMP3_AF8 = 8,

    TIM1_AF9 = 9,
    TIM8_AF9 = 9,
    TIM15_AF9 = 9,
    FDCAN1_AF9 = 9,

    TIM2_AF10 = 10,
    TIM3_AF10 = 10,
    TIM4_AF10 = 10,
    TIM8_AF10 = 10,
    TIM17_AF10 = 10,

    LPTIM1_AF11 = 11,
    TIM1_AF11 = 11,
    TIM8_AF11 = 11,
    FDCAN1_AF11 = 11,

    LPUART1_AF12 = 12,
    SAI1_AF12 = 12,
    TIM1_AF12 = 12,

    SAI1_AF13 = 13,
    OPAMP2_AF13 = 13,

    UART4_AF14 = 14,
    SAI1_AF14 = 14,
    TIM2_AF14 = 14,
    TIM15_AF14 = 14,
    UCPD1_AF14 = 14,

    EVENT_AF15 = 15
};
#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
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
}
}

#endif

#endif
