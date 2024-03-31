/**
 ******************************************************************************
 * @file    w7500x.h
 * @author  WIZnet
 * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer Header File.
 *          This file contains all the peripheral register's definitions, bits
 *          definitions and memory mapping for W7500x devices.
 *
 *          The file is the unique include file that the application programmer
 *          is using in the C source code, usually in main.c. This file contains:
 *           - Configuration section that allows to select:
 *              - The device used in the target application
 *              - To use or not the peripheral’s drivers in application code(i.e.
 *                code will be based on direct access to peripheral’s registers
 *                rather than drivers API), this option is controlled by
 *                "#define USE_STDPERIPH_DRIVER"
 *              - To change few application-specific parameters such as the HSE
 *                crystal frequency
 *           - Data structures and the address mapping for all peripherals
 *           - Peripheral's registers declarations and bits definition
 *           - Macros to access peripheral’s registers hardware
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2018 WIZnet</center></h2>
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/** @addtogroup CMSIS
 * @{
 */

/** @addtogroup w7500x
 * @{
 */

#ifndef __W7500X_H
#define __W7500X_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Library_configuration_section
 * @{
 */

/* Uncomment the line below according to the target W7500x device used in your
 application
 */
#if !defined (W7500) && !defined (W7500P)
#define W7500
//#define W7500P
#endif

#if !defined (W7500) && !defined (W7500P)
#error "Please select first the target W7500x device used in your application (in w7500x.h file)"
#endif

/**
 * @brief In the following line adjust the value of External oscillator clock (8MHz ~ 24MHz)
 used in your application

 Tip: If you want to use the Internal 8MHz RC oscillator clock, uncomment the line below.
 */
//#define OCLK_VALUE 12000000UL
/**
 * @brief In the following line adjust the value of PLL
 */
#define PLL_VALUE 1

#if defined (OCLK_VALUE)
#if ((OCLK_VALUE * PLL_VALUE) > 48000000) || (OCLK_VALUE > 24000000)
#error "Can not exceed 48MHz, Please adjust the PLL value (in w7500x.h file)"
#endif
#else
#define RCLK_VALUE 8000000
#if ((RCLK_VALUE * PLL_VALUE) > 48000000)
#error "Can not exceed 48MHz, Please adjust the PLL value (in w7500x.h file)"
#endif
#endif

#if !defined (PLL_VALUE)
#define PLL_VALUE 1
#endif

/**
 * @brief W7500x Standard Peripheral Library version number
 */
#define __W7500X_STDPERIPH_VERSION_MAIN   (0x01) /*!< [23:16] main version */
#define __W7500X_STDPERIPH_VERSION_SUB1   (0x00) /*!< [15:8] sub1 version */
#define __W7500X_STDPERIPH_VERSION_SUB2   (0x00) /*!< [7:0]  sub2 version */
#define __W7500X_STDPERIPH_VERSION        ((__W7500X_STDPERIPH_VERSION_MAIN << 16)\
                                          |(__W7500X_STDPERIPH_VERSION_SUB1 << 8)\
										  |(__W7500X_STDPERIPH_VERSION_SUB2))

/**
 * @}
 */

/** @addtogroup Configuration_section_for_CMSIS
 * @{
 */

/**
 * @brief W7500x Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __CM0_REV                 0x0000    /*!< Core Revision r0p0                               */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
    /******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn = -14,                  /*!<  2 Cortex-M0 Non Maskable Interrupt              */
    HardFault_IRQn = -13,                       /*!<  3 Cortex-M0 Hard Fault Interrupt                */
    SVCall_IRQn = -5,                           /*!< 11 Cortex-M0 SV Call Interrupt                   */
    PendSV_IRQn = -2,                           /*!< 14 Cortex-M0 Pend SV Interrupt                   */
    SysTick_IRQn = -1,                          /*!< 15 Cortex-M0 System Tick Interrupt               */
    /******  W7500x Specific Interrupt Numbers ********************************************************/
    SSP0_IRQn = 0,                              /*!< SSP 0 Interrupt                                  */
    SSP1_IRQn = 1,                              /*!< SSP 1 Interrupt                                  */
    UART0_IRQn = 2,                             /*!< UART 0 Interrupt                                 */
    UART1_IRQn = 3,                             /*!< UART 1 Interrupt                                 */
    UART2_IRQn = 4,                             /*!< UART 2 Interrupt                                 */
                                                /*!< Reserved                                         */
                                                /*!< Reserved                                         */
    PORT0_IRQn = 7,                             /*!< Port 0 combined Interrupt                        */
    PORT1_IRQn = 8,                             /*!< Port 1 combined Interrupt                        */
    PORT2_IRQn = 9,                             /*!< Port 2 combined Interrupt                        */
    PORT3_IRQn = 10,                            /*!< Port 3 combined Interrupt                        */
    DMA_IRQn = 11,                              /*!< DMA combined Interrupt                           */
    DUALTIMER0_IRQn = 12,                       /*!< Dual Timer 0 Interrupt                           */
    DUALTIMER1_IRQn = 13,                       /*!< Dual Timer 1 Interrupt                           */
    PWM0_IRQn = 14,                             /*!< PWM 0 Interrupt                                  */
    PWM1_IRQn = 15,                             /*!< PWM 1 Interrupt                                  */
    PWM2_IRQn = 16,                             /*!< PWM 2 Interrupt                                  */
    PWM3_IRQn = 17,                             /*!< PWM 3 Interrupt                                  */
    PWM4_IRQn = 18,                             /*!< PWM 4 Interrupt                                  */
    PWM5_IRQn = 19,                             /*!< PWM 5 Interrupt                                  */
    PWM6_IRQn = 20,                             /*!< PWM 6 Interrupt                                  */
    PWM7_IRQn = 21,                             /*!< PWM 7 Interrupt                                  */
    RTC_IRQn = 22,                              /*!< RTC Interrupt                                    */
    ADC_IRQn = 23,                              /*!< ADC Interrupt                                    */
    WZTOE_IRQn = 24,                            /*!< WZTOE Interrupt                                  */
    EXTI_IRQn = 25                              /*!< EXTI Interrupt                                   */
} IRQn_Type;

/**
 * @}
 */

#include "core_cm0.h"                    /* Cortex-M0 processor and core peripherals              */

#if defined(USE_STDPERIPH_DRIVER)
#include "system_w7500x.h"               /* W7500x System include file                            */
#endif

/** @addtogroup Exported_types
 * @{
 */

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

/** @addtogroup Peripheral_registers_structures
 * @{
 */

/**
 * @brief Clock Reset Generator
 */
typedef struct
{
    __IO uint32_t OSC_PDR;              /*!< Oscillator power down register,               Address offset : 0x000 */
         uint32_t RESERVED0[3];
    __IO uint32_t PLL_PDR;              /*!< PLL power down register,                      Address offset : 0x010 */
    __IO uint32_t PLL_FCR;              /*!< PLL frequency calculating register,           Address offset : 0x014 */
    __IO uint32_t PLL_OER;              /*!< PLL output enable register,                   Address offset : 0x018 */
    __IO uint32_t PLL_BPR;              /*!< PLL bypass register,                          Address offset : 0x01C */
    __IO uint32_t PLL_IFSR;             /*!< PLL input frequency select register,          Address offset : 0x020 */
         uint32_t RESERVED1[3];
    __IO uint32_t FCLK_SSR;             /*!< FCLK source select register,                  Address offset : 0x030 */
    __IO uint32_t FCLK_PVSR;            /*!< FCLK prescale value select register,          Address offset : 0x034 */
         uint32_t RESERVED2[2];
    __IO uint32_t SSPCLK_SSR;           /*!< SSPCLK source select register,                Address offset : 0x040 */
    __IO uint32_t SSPCLK_PVSR;          /*!< SSPCLK prescale value select register,        Address offset : 0x044 */
         uint32_t RESERVED3[6];
    __IO uint32_t ADCCLK_SSR;           /*!< ADCCLK source select register,                Address offset : 0x060 */
    __IO uint32_t ADCCLK_PVSR;          /*!< ADCCLK prescale value select register,        Address offset : 0x064 */
         uint32_t RESERVED4[2];
    __IO uint32_t TIMER0CLK_SSR;        /*!< TIMER0CLK source select register,             Address offset : 0x070 */
    __IO uint32_t TIMER0CLK_PVSR;       /*!< TIMER0CLK prescale value select register,     Address offset : 0x074 */
         uint32_t RESERVED5[2];
    __IO uint32_t TIMER1CLK_SSR;        /*!< TIMER1CLK source select register,             Address offset : 0x080 */
    __IO uint32_t TIMER1CLK_PVSR;       /*!< TIMER1CLK prescale value select register,     Address offset : 0x084 */
         uint32_t RESERVED6[10];
    __IO uint32_t PWM0CLK_SSR;          /*!< PWM0CLK source select register,               Address offset : 0x0B0 */
    __IO uint32_t PWM0CLK_PVSR;         /*!< PWM0CLK prescale value select register,       Address offset : 0x0B4 */
         uint32_t RESERVED7[2];
    __IO uint32_t PWM1CLK_SSR;          /*!< PWM1CLK source select register,               Address offset : 0x0C0 */
    __IO uint32_t PWM1CLK_PVSR;         /*!< PWM1CLK prescale value select register,       Address offset : 0x0C4 */
         uint32_t RESERVED8[2];
    __IO uint32_t PWM2CLK_SSR;          /*!< PWM2CLK source select register,               Address offset : 0x0D0 */
    __IO uint32_t PWM2CLK_PVSR;         /*!< PWM2CLK prescale value select register,       Address offset : 0x0D4 */
         uint32_t RESERVED9[2];
    __IO uint32_t PWM3CLK_SSR;          /*!< PWM3CLK source select register,               Address offset : 0x0E0 */
    __IO uint32_t PWM3CLK_PVSR;         /*!< PWM3CLK prescale value select register,       Address offset : 0x0E4 */
         uint32_t RESERVED10[2];
    __IO uint32_t PWM4CLK_SSR;          /*!< PWM4CLK source select register,               Address offset : 0x0F0 */
    __IO uint32_t PWM4CLK_PVSR;         /*!< PWM4CLK prescale value select register,       Address offset : 0x0F4 */
         uint32_t RESERVED11[2];
    __IO uint32_t PWM5CLK_SSR;          /*!< PWM5CLK source select register,               Address offset : 0x100 */
    __IO uint32_t PWM5CLK_PVSR;         /*!< PWM5CLK prescale value select register,       Address offset : 0x104 */
         uint32_t RESERVED12[2];
    __IO uint32_t PWM6CLK_SSR;          /*!< PWM6CLK source select register,               Address offset : 0x110 */
    __IO uint32_t PWM6CLK_PVSR;         /*!< PWM6CLK prescale value select register,       Address offset : 0x114 */
         uint32_t RESERVED13[2];
    __IO uint32_t PWM7CLK_SSR;          /*!< PWM7CLK source select register,               Address offset : 0x120 */
    __IO uint32_t PWM7CLK_PVSR;         /*!< PWM7CLK prescale value select register,       Address offset : 0x124 */
         uint32_t RESERVED14[2];

    __IO uint32_t RTC_HS_SSR;           /*!< RTCCLK source select register,                Address offset : 0x130 */
    __IO uint32_t RTC_HS_PVSR;          /*!< RTCCLK prescale value select register,        Address offset : 0x134 */
         uint32_t RESERVED15[1];
    __IO uint32_t RTC_SSR;              /*!< RTCCLK 32K select register,                   Address offset : 0x13C */

    __IO uint32_t WDOGCLK_HS_SSR;       /*!< WDOGCLK High Speed source select register,                         Address offset : 0x140 */
    __IO uint32_t WDOGCLK_HS_PVSR;      /*!< WDOGCLK High Speed prescale value select register,                 Address offset : 0x144 */
         uint32_t RESERVED16[2];

    __IO uint32_t UARTCLK_SSR;          /*!< UARTCLK source select register,                                    Address offset : 0x150 */
    __IO uint32_t UARTCLK_PVSR;         /*!< UARTCLK prescale value select register,                            Address offset : 0x154 */
         uint32_t RESERVED17[2];
    __IO uint32_t MIICLK_ECR;           /*!< MII clock enable control register,                                 Address offset : 0x160 */
         uint32_t RESERVED18[3];
    __IO uint32_t MONCLK_SSR;           /*!< Select clock source for monitoring (monitoring pin : PA_02),       Address offset : 0x170 */
} CRG_TypeDef;

/**
 * @brief Random Number generator
 */
typedef struct
{
    __IO uint32_t RUN;                  /*!< RNG run register,                    Address offset : 0x000 */
    __IO uint32_t SEED;                 /*!< RNG seed value register,             Address offset : 0x004 */
    __IO uint32_t CLKSEL;               /*!< RNG Clock source select register,    Address offset : 0x008 */
    __IO uint32_t MODE;                 /*!< RNG MODE select register,            Address offset : 0x00C */
    __I  uint32_t RN;                   /*!< RNG random number value register,    Address offset : 0x010 */
    __IO uint32_t POLY;                 /*!< RNG polynomial register,             Address offset : 0x014 */
} RNG_TypeDef;

/**
 * @brief Alternate Function Controller, External Interrupt, Pad Controller
 */
typedef struct
{
    __IO uint32_t REGISTER[16];
} PORTX_TypeDef;

/**
 * @brief General-purpose I/Os
 */
typedef struct
{
    __I  uint32_t DATA;                 /*!< DATA register,                         Address offset : 0x000 */
    __IO uint32_t DATAOUT;              /*!< Data Output Latch register,            Address offset : 0x004 */
         uint32_t RESERVED0[2];
    __IO uint32_t OUTENSET;             /*!< Output Enable Set register,            Address offset : 0x010 */
    __IO uint32_t OUTENCLR;             /*!< Output Enable Clear register,          Address offset : 0x014 */
    __IO uint32_t RESERVED1;            /*!< Alternate Function Set register,       Address offset : 0x018 */
    __IO uint32_t RESERVED2;            /*!< Alternate Function Clear register,     Address offset : 0x01C */
    __IO uint32_t INTENSET;             /*!< Interrupt Enable Set register,         Address offset : 0x020 */
    __IO uint32_t INTENCLR;             /*!< Interrupt Enable Clear register,       Address offset : 0x024 */
    __IO uint32_t INTTYPESET;           /*!< Interrupt Type Set register,           Address offset : 0x028 */
    __IO uint32_t INTTYPECLR;           /*!< Interrupt Type Clear register,         Address offset : 0x02C */
    __IO uint32_t INTPOLSET;            /*!< Interrupt Polarity Set register,       Address offset : 0x030 */
    __IO uint32_t INTPOLCLR;            /*!< Interrupt Polarity Clear register,     Address offset : 0x034 */
    union
    {
        __I uint32_t INTSTATUS;         /*!< Interrupt Status register,             Address offset : 0x038 */
        __O uint32_t INTCLEAR;          /*!< Interrupt Clear register,              Address offset : 0x038 */
    } Interrupt;
         uint32_t RESERVED3[241];
    __IO uint32_t LB_MASKED[256];       /*!< Lower byte Masked Access register,     Address offset : 0x400 - 0x7FC */
    __IO uint32_t UB_MASKED[256];       /*!< Upper byte Masked Access register,     Address offset : 0x800 - 0xBFC */
} GPIO_TypeDef;

/**
 * @brief Direct memory access controller
 */
typedef struct
{
    __I  uint32_t STATUS;               /*!< DMA status register,                                       Address offset: 0x00 */
    __O  uint32_t CFG;                  /*!< DMA configuration register,                                Address offset: 0x04 */
    __IO uint32_t CTRL_BASE_PTR;        /*!< Channel Control Data Base Pointer register,                Address offset: 0x08 */
    __I  uint32_t ALT_CTRL_BASE_PTR;    /*!< Channel Alternate Control Data Base Pointer register,      Address offset: 0x0C */
    __I  uint32_t WAITONREQ_STATUS;     /*!< Channel Wait On Request Status register,                   Address offset: 0x10 */
    __O  uint32_t CHNL_SW_REQUEST;      /*!< Channel Software Request register,                         Address offset: 0x14 */
    __IO uint32_t CHNL_USEBURST_SET;    /*!< Channel UseBurst Set register,                             Address offset: 0x18 */
    __O  uint32_t CHNL_USEBURST_CLR;    /*!< Channel UseBurst Clear register,                           Address offset: 0x1C */
    __IO uint32_t CHNL_REQ_MASK_SET;    /*!< Channel Request Mask Set register,                         Address offset: 0x20 */
    __O  uint32_t CHNL_REQ_MASK_CLR;    /*!< Channel Request Mask Clear register,                       Address offset: 0x24 */
    __IO uint32_t CHNL_ENABLE_SET;      /*!< Channel Enable Set register,                               Address offset: 0x28 */
    __O  uint32_t CHNL_ENABLE_CLR;      /*!< Channel Enable Clear register,                             Address offset: 0x2C */
    __IO uint32_t CHNL_PRI_ALT_SET;     /*!< Channel Primary-Alterante Set register,                    Address offset: 0x30 */
    __O  uint32_t CHNL_PRI_ALT_CLR;     /*!< Channel Primary-Alterante Clear register,                  Address offset: 0x34 */
    __IO uint32_t CHNL_PRIORITY_SET;    /*!< Channel Priority Set register,                             Address offset: 0x38 */
    __O  uint32_t CHNL_PRIORITY_CLR;    /*!< Channel Priority Clear register,                           Address offset: 0x3C */
         uint32_t RESERVED0[3];
    __IO uint32_t ERR_CLR;              /*!< Bus Error Clear register,                                  Address offset: 0x4C */
} DMA_TypeDef;

/**
 * @brief Analog-to-digital converter
 */
typedef struct
{
    __IO uint32_t CTR;                  /*!< ADC control register,                    Address offset : 0x00 */
    __IO uint32_t CHSEL;                /*!< ADC channel select register,             Address offset : 0x04 */
    __O  uint32_t START;                /*!< ADC start register,                      Address offset : 0x08 */
    __I  uint32_t DATA;                 /*!< ADC conversion data register,            Address offset : 0x0C */
    __IO uint32_t INT;                  /*!< ADC interrupt register,                  Address offset : 0x10 */
         uint32_t RESERVED0[2];
    __O  uint32_t INTCLR;               /*!< ADC interrupt clear register,            Address offset : 0x1C */
} ADC_TypeDef;

/**
 * @brief Pulse-Width Modulation
 */
typedef struct
{
    __IO uint32_t IER;                  /*!< Interrupt enable register,                             Address offset : 0x00 */
    __IO uint32_t SSR;                  /*!< Start Stop register,                                   Address offset : 0x04 */
    __IO uint32_t PSR;                  /*!< Pause register,                                        Address offset : 0x08 */
} PWM_Common_TypeDef;

typedef struct
{
    __I  uint32_t IR;                   /*!< Interrupt register,                                    Address offset : 0x00 */
    __IO uint32_t IER;                  /*!< Interrupt enable register,                             Address offset : 0x04 */
    __O  uint32_t ICR;                  /*!< Interrupt clear register,                              Address offset : 0x08 */
    __I  uint32_t TCR;                  /*!< Timer/Counter register,                                Address offset : 0x0C */
    __I  uint32_t PCR;                  /*!< Prescale counter register,                             Address offset : 0x10 */
    __IO uint32_t PR;                   /*!< Prescale register,                                     Address offset : 0x14 */
    __IO uint32_t MR;                   /*!< Match register,                                        Address offset : 0x18 */
    __IO uint32_t LR;                   /*!< Limit register,                                        Address offset : 0x1C */
    __IO uint32_t UDMR;                 /*!< Up-Down mode register,                                 Address offset : 0x20 */
    __IO uint32_t TCMR;                 /*!< Timer/Counter mode register,                           Address offset : 0x24 */
    __IO uint32_t PEEER;                /*!< PWM output enable and external input enable register,  Address offset : 0x28 */
    __IO uint32_t CMR;                  /*!< Capture mode register,                                 Address offset : 0x2C */
    __I  uint32_t CR;                   /*!< Capture register,                                      Address offset : 0x30 */
    __IO uint32_t PDMR;                 /*!< Periodic mode register,                                Address offset : 0x34 */
    __IO uint32_t DZER;                 /*!< Dead-zone enable register,                             Address offset : 0x38 */
    __IO uint32_t DZCR;                 /*!< Dead-zone counter register,                            Address offset : 0x3C */
} PWM_TypeDef;

/**
 * @brief Dual timers
 */
typedef struct
{
    __IO uint32_t LOAD;                 /*!< Timer Load register,                       Address offset : 0x00 */
    __I  uint32_t VALUE;                /*!< Timer Counter Current Value register,      Address offset : 0x04 */
    __IO uint32_t CONTROL;              /*!< Timer Control register,                    Address offset : 0x08 */
    __O  uint32_t INTCLR;               /*!< Timer Interrupt Clear register,            Address offset : 0x0C */
    __I  uint32_t RIS;                  /*!< Timer Raw Interrupt Status register,       Address offset : 0x10 */
    __I  uint32_t MIS;                  /*!< Timer Masked Interrupt Status register,    Address offset : 0x14 */
    __IO uint32_t BGLOAD;               /*!< Background Load register,                  Address offset : 0x18 */
         uint32_t RESERVED[25];
    __IO uint32_t CE;                   /*!< Clock enable register,                     Address offset : 0x80 */
} DUALTIMER_TypeDef;

/**
 * @brief Watchdog timer
 */
typedef struct
{
    __IO uint32_t LOAD;                 /*!< Watchdog timer Load register,                      Address offset : 0x000 */
    __I  uint32_t VALUE;                /*!< Watchdog timer Value register,                     Address offset : 0x004 */
    __IO uint32_t CONTROL;              /*!< Watchdog timer Control register,                   Address offset : 0x008 */
    __O  uint32_t INTCLR;               /*!< Watchdog timer Clear Interrupt register,           Address offset : 0x00C */
    __I  uint32_t RIS;                  /*!< Watchdog timer Raw Interrupt Status register,      Address offset : 0x010 */
    __I  uint32_t MIS;                  /*!< Watchdog timer Masked Interrupt Status register,   Address offset : 0x014 */
         uint32_t RESERVED[762];
    __IO uint32_t LOCK;                 /*!< Watchdog timer Lock register,                      Address offset : 0xC00 */
} WDT_TypeDef;

/**
 * @brief Real-time Clock(RTC)
 */
typedef struct
{
    __IO uint32_t RTCCON;               /*!< control register,                  Address offset: 0x00 */
    __IO uint32_t RTCINTE;              /*!< Interrupt Mask register,           Address offset: 0x04 */
    __IO uint32_t RTCINTP;              /*!< Interrupt Pending register,        Address offset: 0x08 */
    __IO uint32_t RTCAMR;               /*!< Alarm Mask register,               Address offset: 0x0C */
    __IO uint32_t BCDSEC;               /*!< BCD Second register,               Address offset: 0x10 */
    __IO uint32_t BCDMIN;               /*!< BCD Minute register,               Address offset: 0x14 */
    __IO uint32_t BCDHOUR;              /*!< BCD Hour register,                 Address offset: 0x18 */
    __IO uint32_t BCDDAY;               /*!< BCD Day register,                  Address offset: 0x1C */
    __IO uint32_t BCDDATE;              /*!< BCD Date register,                 Address offset: 0x20 */
    __IO uint32_t BCDMON;               /*!< BCD Month register,                Address offset: 0x24 */
    __IO uint32_t BCDYEAR;              /*!< BCD Year register,                 Address offset: 0x28 */
    __IO uint32_t PRESEC;               /*!< Predetermining Second register,    Address offset: 0x2C */
    __IO uint32_t PREMIN;               /*!< Predetermining Minute register,    Address offset: 0x30 */
    __IO uint32_t PREHOUR;              /*!< Predetermining Hour register,      Address offset: 0x34 */
    __IO uint32_t PREDAY;               /*!< Predetermining Day register,       Address offset: 0x38 */
    __IO uint32_t PREDATE;              /*!< Predetermining Date register,      Address offset: 0x3C */
    __IO uint32_t PREMON;               /*!< Predetermining Month register,     Address offset: 0x40 */
    __IO uint32_t PREYEAR;              /*!< Predetermining Year register,      Address offset: 0x44 */
    __I  uint32_t RTCTIME0;             /*!< Consolidated Time0 register,       Address offset: 0x48 */
    __I  uint32_t RTCTIME1;             /*!< Consolidated Time1 register,       Address offset: 0x4C */
} RTC_TypeDef;

/**
 * @brief UART
 */
typedef struct
{
    __IO uint32_t DR;                   /*!< Data,                              Address offset : 0x00 */
    union
    {
        __I uint32_t RSR;               /*!< Receive Status,                    Address offset : 0x04 */
        __O uint32_t ECR;               /*!< Error Clear,                       Address offset : 0x04 */
    } STATUS;
    uint32_t RESERVED0[4];
    __I  uint32_t FR;                   /*!< Flags,                             Address offset : 0x18 */
         uint32_t RESERVED1;
    __IO uint32_t ILPR;                 /*!< IrDA Low-power Counter,            Address offset : 0x20 */
    __IO uint32_t IBRD;                 /*!< Integer Baud Rate,                 Address offset : 0x24 */
    __IO uint32_t FBRD;                 /*!< Fractional Baud Rate,              Address offset : 0x28 */
    __IO uint32_t LCR_H;                /*!< Line Control,                      Address offset : 0x2C */
    __IO uint32_t CR;                   /*!< Control,                           Address offset : 0x30 */
    __IO uint32_t IFLS;                 /*!< Interrupt FIFO Level Select,       Address offset : 0x34 */
    __IO uint32_t IMSC;                 /*!< Interrupt Mask Set / Clear,        Address offset : 0x38 */
    __I  uint32_t RIS;                  /*!< Raw Interrupt Status ,             Address offset : 0x3C */
    __I  uint32_t MIS;                  /*!< Masked Interrupt Status ,          Address offset : 0x40 */
    __O  uint32_t ICR;                  /*!< Interrupt Clear,                   Address offset : 0x44 */
    __IO uint32_t DMACR;                /*!< DMA Control,                       Address offset : 0x48 */
} UART_TypeDef;

/**
 * @brief Simple UART
 */
typedef struct
{
    __IO uint32_t DR;                   /*!< Data register,                     Address offset: 0x00 */
    __IO uint32_t SR;                   /*!< Status register,                   Address offset: 0x04 */
    __IO uint32_t CR;                   /*!< Control register,                  Address offset: 0x08 */
    union
    {
        __I uint32_t ISR;               /*!< Interrupt Status register,         Address offset: 0x0C */
        __O uint32_t ICR;               /*!< Interrupt Clear register,          Address offset: 0x0C */
    } INT;
    __IO uint32_t BDR;                  /*!< Baudrate Divider register,         Address offset: 0x10 */

} S_UART_TypeDef;

/**
 * @brief Serial Peripheral Interface
 */
typedef struct
{
    __IO uint32_t CR0;                  /*!< Control register 0,                        Address offset: 0x00 */
    __IO uint32_t CR1;                  /*!< Control register 1,                        Address offset: 0x04 */
    __IO uint32_t DR;                   /*!< Data register,                             Address offset: 0x08 */
    __IO uint32_t SR;                   /*!< Status register,                           Address offset: 0x0C */
    __IO uint32_t CPSR;                 /*!< Clock prescale register,                   Address offset: 0x10 */
    __IO uint32_t IMSC;                 /*!< Interrupt mask set or clear register,      Address offset: 0x14 */
    __IO uint32_t RIS;                  /*!< Raw interrupt status register,             Address offset: 0x18 */
    __IO uint32_t MIS;                  /*!< Masked interrupt status register,          Address offset: 0x1C */
    __IO uint32_t ICR;                  /*!< Interrupt clear register,                  Address offset: 0x20 */
    __IO uint32_t DMACR;                /*!< DMA control register,                      Address offset: 0x24 */
} SSP_TypeDef;

/**
 * @}
 */

/**
 * @brief Random Number generator
 */
typedef struct
{
    __IO uint32_t REMAP;                /*!< Remap Control Register (R/W),        Address offset: 0x00 */
    __IO uint32_t PMUCTRL;              /*!< PMU Control Register (R/W),          Address offset: 0x04 */
    __IO uint32_t RESETOP;              /*!< Reset Option Register  (R/W),        Address offset: 0x08 */
    __IO uint32_t EMICTRL;              /*!< EMI Control Register  (R/W),         Address offset: 0x0C */
    __IO uint32_t RSTINFO;              /*!< Reset Information Register (R/W),    Address offset: 0x10 */
} SYSCFG_TypeDef;

/** @addtogroup Peripheral_memory_map
 * @{
 */

/* Peripheral and SRAM base address */
#define FLASH_BASE          (0x00000000UL)  /*!< (FLASH     ) Base Address */
#define INFO_BGT            (0x0003FDB8UL)
#define INFO_OSC            (0x0003FDBCUL)
#define SRAM_BASE           (0x20000000UL)  /*!< (SRAM      ) Base Address */
#define PERIPH_BASE         (0x40000000UL)  /*!< (Peripheral) Base Address */

#define RAM_BASE            SRAM_BASE
#define APB0_BASE           PERIPH_BASE
#define APB1_BASE           (0x41000000UL)
#define AHB_BASE            (0x42000000UL)

#define WDT_BASE            (APB0_BASE + 0x00000000UL)
#define DUALTIMER0_BASE     (APB0_BASE + 0x00001000UL)
#define DUALTIMER1_BASE     (APB0_BASE + 0x00002000UL)
#define PWM_BASE            (APB0_BASE + 0x00005000UL)
#define SUART_BASE          (APB0_BASE + 0x00006000UL)
#define RNG_BASE            (APB0_BASE + 0x00007000UL)
#define SSP0_BASE 	        (APB0_BASE + 0x0000A000UL)
#define SSP1_BASE 	        (APB0_BASE + 0x0000B000UL)
#define UART0_BASE          (APB0_BASE + 0x0000C000UL)
#define UART1_BASE          (APB0_BASE + 0x0000D000UL)
#define RTC_BASE            (APB0_BASE + 0x0000E000UL)
#define SYSCFG_BASE         (APB0_BASE + 0x0001F000UL)

#define ADC_BASE            (APB1_BASE + 0x00000000UL)
#define CRG_BASE            (APB1_BASE + 0x00001000UL)
#define TRIM_OSC            (APB1_BASE + 0x00001004UL)
#define TRIM_BGT            (APB1_BASE + 0x00001210UL)
#define AFC_BASE            (APB1_BASE + 0x00002000UL)
#define EXTI_BASE           (APB1_BASE + 0x00002200UL)
#define PAD_BASE            (APB1_BASE + 0x00003000UL)
#define DMA_BASE            (APB1_BASE + 0x00004000UL)

#define GPIOA_BASE          (AHB_BASE + 0x00000000UL)
#define GPIOB_BASE          (AHB_BASE + 0x01000000UL)
#define GPIOC_BASE          (AHB_BASE + 0x02000000UL)
#define GPIOD_BASE          (AHB_BASE + 0x03000000UL)

#define WZTOE_BASE          (APB0_BASE + 0x06000000UL)
#define TXMEM_BASE          (WZTOE_BASE + 0x00020000UL)
#define RXMEM_BASE          (WZTOE_BASE + 0x00030000UL)
/**
 * @}
 */

/** @addtogroup Peripheral_declaration
 * @{
 */
#define WDT                 ((WDT_TypeDef *)            WDT_BASE)
#define DUALTIMER0_0        ((DUALTIMER_TypeDef *)      DUALTIMER0_BASE)
#define DUALTIMER0_1        ((DUALTIMER_TypeDef *)      (DUALTIMER0_BASE + 0x20UL))
#define DUALTIMER1_0        ((DUALTIMER_TypeDef *)      DUALTIMER1_BASE)
#define DUALTIMER1_1        ((DUALTIMER_TypeDef *)      (DUALTIMER1_BASE + 0x20UL))
#define PWM                 ((PWM_Common_TypeDef *)     (PWM_BASE + 0x800UL))
#define PWM0                ((PWM_TypeDef *)            PWM_BASE)
#define PWM1                ((PWM_TypeDef *)            (PWM_BASE + 0x100UL))
#define PWM2                ((PWM_TypeDef *)            (PWM_BASE + 0x200UL))
#define PWM3                ((PWM_TypeDef *)            (PWM_BASE + 0x300UL))
#define PWM4                ((PWM_TypeDef *)            (PWM_BASE + 0x400UL))
#define PWM5                ((PWM_TypeDef *)            (PWM_BASE + 0x500UL))
#define PWM6                ((PWM_TypeDef *)            (PWM_BASE + 0x600UL))
#define PWM7                ((PWM_TypeDef *)            (PWM_BASE + 0x700UL))
#define UART2               ((S_UART_TypeDef *)         SUART_BASE)
#define RNG                 ((RNG_TypeDef *)            RNG_BASE)
#define SSP0                ((SSP_TypeDef *)            SSP0_BASE)
#define SSP1                ((SSP_TypeDef *)            SSP1_BASE)
#define UART0               ((UART_TypeDef *)           UART0_BASE)
#define UART1               ((UART_TypeDef *)           UART1_BASE)
#define RTC                 ((RTC_TypeDef *)            RTC_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *)         SYSCFG_BASE)

#define ADC                 ((ADC_TypeDef *)            ADC_BASE)
#define CRG                 ((CRG_TypeDef *)            CRG_BASE)
#define AFC_PA              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000000UL))
#define AFC_PB              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000040UL))
#define AFC_PC              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000080UL))
#define AFC_PD              ((PORTX_TypeDef *)          (AFC_BASE + 0x000000C0UL))
#define EXTI_PA             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000000UL))
#define EXTI_PB             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000040UL))
#define EXTI_PC             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000080UL))
#define EXTI_PD             ((PORTX_TypeDef *)          (EXTI_BASE + 0x000000C0UL))
#define PADCON_PA           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000000UL))
#define PADCON_PB           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000040UL))
#define PADCON_PC           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000080UL))
#define PADCON_PD           ((PORTX_TypeDef *)          (PAD_BASE + 0x000000C0UL))
#define DMA                 ((DMA_TypeDef *)            DMA_BASE)

#define GPIOA               ((GPIO_TypeDef *)           GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)           GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)           GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)           GPIOD_BASE)

#define RUNTIME_PWM0		0
#define RUNTIME_PWM1		1
#define RUNTIME_PWM2		2
#define RUNTIME_PWM3		3
#define RUNTIME_PWM4		4
#define RUNTIME_PWM5		5
#define RUNTIME_PWM6		6
#define RUNTIME_PWM7		7

/**
 * @}
 */

/** @addtogroup Exported_constants
 * @{
 */

/**
 * @}
 */

#ifdef USE_STDPERIPH_DRIVER
#include "w7500x_conf.h"
#endif

/** @addtogroup Exported_macro
 * @{
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  /* __W7500X_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT WIZnet *****END OF FILE****************/
