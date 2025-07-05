/**************************************************************************//**
 * @file     M480.h
 * @version  V1.00
 * @brief    M480 peripheral access layer header file.
 *           This file contains all the peripheral register's definitions,
 *           bits definitions and memory mapping for NuMicro M480 MCU.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2022-2024 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
/**
  \mainpage NuMicro M480 Driver Reference Guide
  *
  * <b>Introduction</b>
  *
  * This user manual describes the usage of M480 Series MCU device driver
  *
  * <b>Disclaimer</b>
  *
  * The Software is furnished "AS IS", without warranty as to performance or results, and
  * the entire risk as to performance or results is assumed by YOU. Nuvoton disclaims all
  * warranties, express, implied or otherwise, with regard to the Software, its use, or
  * operation, including without limitation any and all warranties of merchantability, fitness
  * for a particular purpose, and non-infringement of intellectual property rights.
  *
  * <b>Important Notice</b>
  *
  * Nuvoton Products are neither intended nor warranted for usage in systems or equipment,
  * any malfunction or failure of which may cause loss of human life, bodily injury or severe
  * property damage. Such applications are deemed, "Insecure Usage".
  *
  * Insecure usage includes, but is not limited to: equipment for surgical implementation,
  * atomic energy control instruments, airplane or spaceship instruments, the control or
  * operation of dynamic, brake or safety systems designed for vehicular use, traffic signal
  * instruments, all types of safety devices, and other applications intended to support or
  * sustain life.
  *
  * All Insecure Usage shall be made at customer's risk, and in the event that third parties
  * lay claims to Nuvoton as a result of customer's Insecure Usage, customer shall indemnify
  * the damages and liabilities thus incurred by Nuvoton.
  *
  * Please note that all data and specifications are subject to change without notice. All the
  * trademarks of products and companies mentioned in this datasheet belong to their respective
  * owners.
  *
  * <b>Copyright Notice</b>
  *
  * Copyright (C) 2022-2024 Nuvoton Technology Corp. All rights reserved.
  */
#ifndef __M480_H__
#define __M480_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSIS_Device Device CMSIS Definitions
  Configuration of the Cortex-M4 Processor and Core Peripherals
  @{
*/

/**
 * @details  Interrupt Number Definition.
 */
typedef enum IRQn
{
    /******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
    MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt                   */
    BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt                           */
    UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt                         */
    SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
    DebugMonitor_IRQn             = -4,       /*!< 12 Debug Monitor Interrupt                       */
    PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
    SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

    /******  M480 Specific Interrupt Numbers ********************************************************/

    BOD_IRQn                      = 0,        /*!< Brown Out detection Interrupt                    */
    IRC_IRQn                      = 1,        /*!< Internal RC Interrupt                            */
    PWRWU_IRQn                    = 2,        /*!< Power Down Wake Up Interrupt                     */
    RAMPE_IRQn                    = 3,        /*!< SRAM parity check failed Interrupt               */
    CKFAIL_IRQn                   = 4,        /*!< Clock failed Interrupt                           */
    RTC_IRQn                      = 6,        /*!< Real Time Clock Interrupt                        */
    TAMPER_IRQn                   = 7,        /*!< Tamper detection Interrupt                       */
    WDT_IRQn                      = 8,        /*!< Watchdog timer Interrupt                         */
    WWDT_IRQn                     = 9,        /*!< Window Watchdog timer Interrupt                  */
    EINT0_IRQn                    = 10,       /*!< External Input 0 Interrupt                       */
    EINT1_IRQn                    = 11,       /*!< External Input 1 Interrupt                       */
    EINT2_IRQn                    = 12,       /*!< External Input 2 Interrupt                       */
    EINT3_IRQn                    = 13,       /*!< External Input 3 Interrupt                       */
    EINT4_IRQn                    = 14,       /*!< External Input 4 Interrupt                       */
    EINT5_IRQn                    = 15,       /*!< External Input 5 Interrupt                       */
    GPA_IRQn                      = 16,       /*!< GPIO Port A Interrupt                            */
    GPB_IRQn                      = 17,       /*!< GPIO Port B Interrupt                            */
    GPC_IRQn                      = 18,       /*!< GPIO Port C Interrupt                            */
    GPD_IRQn                      = 19,       /*!< GPIO Port D Interrupt                            */
    GPE_IRQn                      = 20,       /*!< GPIO Port E Interrupt                            */
    GPF_IRQn                      = 21,       /*!< GPIO Port F Interrupt                            */
    QSPI0_IRQn                    = 22,       /*!< QSPI0 Interrupt                                   */
    SPI0_IRQn                     = 23,       /*!< SPI0 Interrupt                                   */
    BRAKE0_IRQn                   = 24,       /*!< BRAKE0 Interrupt                                 */
    EPWM0P0_IRQn                  = 25,       /*!< EPWM0P0 Interrupt                                */
    EPWM0P1_IRQn                  = 26,       /*!< EPWM0P1 Interrupt                                */
    EPWM0P2_IRQn                  = 27,       /*!< EPWM0P2 Interrupt                                */
    BRAKE1_IRQn                   = 28,       /*!< BRAKE1 Interrupt                                 */
    EPWM1P0_IRQn                  = 29,       /*!< EPWM1P0 Interrupt                                */
    EPWM1P1_IRQn                  = 30,       /*!< EPWM1P1 Interrupt                                */
    EPWM1P2_IRQn                  = 31,       /*!< EPWM1P2 Interrupt                                */
    TMR0_IRQn                     = 32,       /*!< Timer 0 Interrupt                                */
    TMR1_IRQn                     = 33,       /*!< Timer 1 Interrupt                                */
    TMR2_IRQn                     = 34,       /*!< Timer 2 Interrupt                                */
    TMR3_IRQn                     = 35,       /*!< Timer 3 Interrupt                                */
    UART0_IRQn                    = 36,       /*!< UART 0 Interrupt                                 */
    UART1_IRQn                    = 37,       /*!< UART 1 Interrupt                                 */
    I2C0_IRQn                     = 38,       /*!< I2C 0 Interrupt                                  */
    I2C1_IRQn                     = 39,       /*!< I2C 1 Interrupt                                  */
    PDMA_IRQn                     = 40,       /*!< Peripheral DMA Interrupt                         */
    DAC_IRQn                      = 41,       /*!< DAC Interrupt                                    */
    EADC00_IRQn                   = 42,       /*!< EADC00 Interrupt                                 */
    EADC01_IRQn                   = 43,       /*!< EADC01 Interrupt                                 */
    ACMP01_IRQn                   = 44,       /*!< Analog Comparator 0 and 1 Interrupt              */
    EADC02_IRQn                   = 46,       /*!< EADC02 Interrupt                                 */
    EADC03_IRQn                   = 47,       /*!< EADC03 Interrupt                                 */
    UART2_IRQn                    = 48,       /*!< UART2 Interrupt                                  */
    UART3_IRQn                    = 49,       /*!< UART3 Interrupt                                  */
    QSPI1_IRQn                    = 50,       /*!< QSPI1 Interrupt                                   */
    SPI1_IRQn                     = 51,       /*!< SPI1 Interrupt                                   */
    SPI2_IRQn                     = 52,       /*!< SPI2 Interrupt                                   */
    USBD_IRQn                     = 53,       /*!< USB device Interrupt                             */
    USBH_IRQn                     = 54,       /*!< USB host Interrupt                               */
    USBOTG_IRQn                   = 55,       /*!< USB OTG Interrupt                                */
    CAN0_IRQn                     = 56,       /*!< CAN0 Interrupt                                   */
    CAN1_IRQn                     = 57,       /*!< CAN1 Interrupt                                   */
    SC0_IRQn                      = 58,       /*!< Smart Card 0 Interrupt                           */
    SC1_IRQn                      = 59,       /*!< Smart Card 1 Interrupt                           */
    SC2_IRQn                      = 60,       /*!< Smart Card 2 Interrupt                           */
    SPI3_IRQn                     = 62,       /*!< SPI3 Interrupt                                   */
    EMAC_TX_IRQn                  = 66,       /*!< Ethernet MAC TX Interrupt                        */
    EMAC_RX_IRQn                  = 67,       /*!< Ethernet MAC RX Interrupt                        */
    SDH0_IRQn                     = 64,       /*!< Secure Digital Host Controller 0 Interrupt       */
    USBD20_IRQn                   = 65,       /*!< High Speed USB device Interrupt                  */
    I2S0_IRQn                     = 68,       /*!< I2S0 Interrupt                                   */
    OPA_IRQn                      = 70,       /*!< OPA Interrupt                                    */
    CRPT_IRQn                     = 71,       /*!< CRPT Interrupt                                   */
    GPG_IRQn                      = 72,       /*!< GPIO Port G Interrupt                            */
    EINT6_IRQn                    = 73,       /*!< External Input 6 Interrupt                       */
    UART4_IRQn                    = 74,       /*!< UART4 Interrupt                                  */
    UART5_IRQn                    = 75,       /*!< UART5 Interrupt                                  */
    USCI0_IRQn                    = 76,       /*!< USCI0 Interrupt                                  */
    USCI1_IRQn                    = 77,       /*!< USCI1 Interrupt                                  */
    BPWM0_IRQn                    = 78,       /*!< BPWM0 Interrupt                                  */
    BPWM1_IRQn                    = 79,       /*!< BPWM1 Interrupt                                  */
    SPIM_IRQn                     = 80,       /*!< SPIM Interrupt                                   */
    CCAP_IRQn                     = 81,       /*!< CCAP Interrupt                                   */
    I2C2_IRQn                     = 82,       /*!< I2C2 Interrupt                                   */
    QEI0_IRQn                     = 84,       /*!< QEI0 Interrupt                                   */
    QEI1_IRQn                     = 85,       /*!< QEI1 Interrupt                                   */
    ECAP0_IRQn                    = 86,       /*!< ECAP0 Interrupt                                  */
    ECAP1_IRQn                    = 87,       /*!< ECAP1 Interrupt                                  */
    GPH_IRQn                      = 88,       /*!< GPIO Port H Interrupt                            */
    EINT7_IRQn                    = 89,       /*!< External Input 7 Interrupt                       */
    SDH1_IRQn                     = 90,       /*!< Secure Digital Host Controller 1 Interrupt       */
    HSUSBH_IRQn                   = 92,       /*!< High speed USB host Interrupt                    */
    USBOTG20_IRQn                 = 93,       /*!< High speed USB OTG Interrupt                     */
    TRNG_IRQn                     = 101,      /*!< TRNG Interrupt                                   */
    UART6_IRQn                    = 102,      /*!< UART6 Interrupt                                  */
    UART7_IRQn                    = 103,      /*!< UART7 Interrupt                                  */
    EADC10_IRQn                   = 104,      /*!< EADC10 Interrupt                                 */
    EADC11_IRQn                   = 105,      /*!< EADC11 Interrupt                                 */
    EADC12_IRQn                   = 106,      /*!< EADC12 Interrupt                                 */
    EADC13_IRQn                   = 107,      /*!< EADC13 Interrupt                                 */
    CAN2_IRQn                     = 108,      /*!< CAN2 Interrupt                                   */
}
IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __CM4_REV                 0x0201UL    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          4UL         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0UL         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             1UL         /*!< MPU present or not                               */
#ifdef __FPU_PRESENT
#undef __FPU_PRESENT
#define __FPU_PRESENT             1UL         /*!< FPU present or not                               */
#else
#define __FPU_PRESENT             1UL         /*!< FPU present or not                               */
#endif

/*@}*/ /* end of group CMSIS_Device */


#include "../../cmsis/core_cm4.h"
//#include "system_M480.h"            /* System include file                         */
#include <stdint.h>



#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                            Register definitions                            */
/******************************************************************************/

/**
    @addtogroup SYS System Manger Controller(SYS)
    Memory Mapped Structure for SYS Controller
@{ */

typedef struct
{
    __I  uint32_t PDID;                  /*!< [0x0000] Part Device Identification Number Register                       */
    __IO uint32_t RSTSTS;                /*!< [0x0004] System Reset Status Register                                     */
    __IO uint32_t IPRST0;                /*!< [0x0008] Peripheral  Reset Control Register 0                             */
    __IO uint32_t IPRST1;                /*!< [0x000c] Peripheral Reset Control Register 1                              */
    __IO uint32_t IPRST2;                /*!< [0x0010] Peripheral Reset Control Register 2                              */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE0[1];
    /** @endcond */
    __IO uint32_t BODCTL;                /*!< [0x0018] Brown-Out Detector Control Register                              */
    __IO uint32_t IVSCTL;                /*!< [0x001c] Internal Voltage Source Control Register                         */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE1[1];
    /** @endcond */
    __IO uint32_t PORCTL;                /*!< [0x0024] Power-On-Reset Controller Register                               */
    __IO uint32_t VREFCTL;               /*!< [0x0028] VREF Control Register                                            */
    __IO uint32_t USBPHY;                /*!< [0x002c] USB PHY Control Register                                         */
    __IO uint32_t GPA_MFPL;              /*!< [0x0030] GPIOA Low Byte Multiple Function Control Register                */
    __IO uint32_t GPA_MFPH;              /*!< [0x0034] GPIOA High Byte Multiple Function Control Register               */
    __IO uint32_t GPB_MFPL;              /*!< [0x0038] GPIOB Low Byte Multiple Function Control Register                */
    __IO uint32_t GPB_MFPH;              /*!< [0x003c] GPIOB High Byte Multiple Function Control Register               */
    __IO uint32_t GPC_MFPL;              /*!< [0x0040] GPIOC Low Byte Multiple Function Control Register                */
    __IO uint32_t GPC_MFPH;              /*!< [0x0044] GPIOC High Byte Multiple Function Control Register               */
    __IO uint32_t GPD_MFPL;              /*!< [0x0048] GPIOD Low Byte Multiple Function Control Register                */
    __IO uint32_t GPD_MFPH;              /*!< [0x004c] GPIOD High Byte Multiple Function Control Register               */
    __IO uint32_t GPE_MFPL;              /*!< [0x0050] GPIOE Low Byte Multiple Function Control Register                */
    __IO uint32_t GPE_MFPH;              /*!< [0x0054] GPIOE High Byte Multiple Function Control Register               */
    __IO uint32_t GPF_MFPL;              /*!< [0x0058] GPIOF Low Byte Multiple Function Control Register                */
    __IO uint32_t GPF_MFPH;              /*!< [0x005c] GPIOF High Byte Multiple Function Control Register               */
    __IO uint32_t GPG_MFPL;              /*!< [0x0060] GPIOG Low Byte Multiple Function Control Register                */
    __IO uint32_t GPG_MFPH;              /*!< [0x0064] GPIOG High Byte Multiple Function Control Register               */
    __IO uint32_t GPH_MFPL;              /*!< [0x0068] GPIOH Low Byte Multiple Function Control Register                */
    __IO uint32_t GPH_MFPH;              /*!< [0x006c] GPIOH High Byte Multiple Function Control Register               */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE2[4];
    /** @endcond */
    __IO uint32_t GPA_MFOS;              /*!< [0x0080] GPIOA Multiple Function Output Select Register                   */
    __IO uint32_t GPB_MFOS;              /*!< [0x0084] GPIOB Multiple Function Output Select Register                   */
    __IO uint32_t GPC_MFOS;              /*!< [0x0088] GPIOC Multiple Function Output Select Register                   */
    __IO uint32_t GPD_MFOS;              /*!< [0x008c] GPIOD Multiple Function Output Select Register                   */
    __IO uint32_t GPE_MFOS;              /*!< [0x0090] GPIOE Multiple Function Output Select Register                   */
    __IO uint32_t GPF_MFOS;              /*!< [0x0094] GPIOF Multiple Function Output Select Register                   */
    __IO uint32_t GPG_MFOS;              /*!< [0x0098] GPIOG Multiple Function Output Select Register                   */
    __IO uint32_t GPH_MFOS;              /*!< [0x009c] GPIOH Multiple Function Output Select Register                   */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE3[8];
    /** @endcond */
    __IO uint32_t SRAM_INTCTL;           /*!< [0x00c0] System SRAM Interrupt Enable Control Register                    */
    __IO uint32_t SRAM_STATUS;           /*!< [0x00c4] System SRAM Parity Error Status Register                         */
    __I  uint32_t SRAM_ERRADDR;          /*!< [0x00c8] System SRAM Parity Check Error Address Register                  */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE4[1];
    /** @endcond */
    __IO uint32_t SRAM_BISTCTL;          /*!< [0x00d0] System SRAM BIST Test Control Register                           */
    __I  uint32_t SRAM_BISTSTS;          /*!< [0x00d4] System SRAM BIST Test Status Register                            */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE5[3];
    /** @endcond */
    __IO uint32_t HIRCTCTL;              /*!< [0x00e4] HIRC48M Trim Control Register                                    */
    __IO uint32_t HIRCTIEN;              /*!< [0x00e8] HIRC48M Trim Interrupt Enable Register                           */
    __IO uint32_t HIRCTISTS;             /*!< [0x00ec] HIRC48M Trim Interrupt Status Register                           */
    __IO uint32_t IRCTCTL;               /*!< [0x00f0] HIRC Trim Control Register                                       */
    __IO uint32_t IRCTIEN;               /*!< [0x00f4] HIRC Trim Interrupt Enable Register                              */
    __IO uint32_t IRCTISTS;              /*!< [0x00f8] HIRC Trim Interrupt Status Register                              */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE6[1];
    /** @endcond */
    __IO uint32_t REGLCTL;               /*!< [0x0100] Register Lock Control Register                                   */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE7[58];
    /** @endcond */
    __IO uint32_t PORDISAN;              /*!< [0x01ec] Analog POR Disable Control Register                              */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE8;
    /** @endcond */
    __I  uint32_t CSERVER;               /*!< [0x01f4] Chip Series Version Register                                     */
    __IO uint32_t PLCTL;                 /*!< [0x01f8] Power Level Control Register                                     */
    __I  uint32_t PLSTS;                 /*!< [0x01fc] Power Level Status Register                                      */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE9[128];
    /** @endcond */
    __IO uint32_t AHBMCTL;               /*!< [0x0400] AHB Bus Matrix Priority Control Register                         */

} SYS_T;

/**
    @addtogroup NMI NMI Controller (NMI)
    Memory Mapped Structure for NMI Controller
@{ */

typedef struct
{
    __IO uint32_t NMIEN;                 /*!< [0x0000] NMI Source Interrupt Enable Register                             */
    __I  uint32_t NMISTS;                /*!< [0x0004] NMI Source Interrupt Status Register                             */

} NMI_T;

/**
    @addtogroup CLK System Clock Controller(CLK)
    Memory Mapped Structure for CLK Controller
@{ */

typedef struct
{
    __IO uint32_t PWRCTL;                /*!< [0x0000] System Power-down Control Register                               */
    __IO uint32_t AHBCLK;                /*!< [0x0004] AHB Devices Clock Enable Control Register                        */
    __IO uint32_t APBCLK0;               /*!< [0x0008] APB Devices Clock Enable Control Register 0                      */
    __IO uint32_t APBCLK1;               /*!< [0x000c] APB Devices Clock Enable Control Register 1                      */
    __IO uint32_t CLKSEL0;               /*!< [0x0010] Clock Source Select Control Register 0                           */
    __IO uint32_t CLKSEL1;               /*!< [0x0014] Clock Source Select Control Register 1                           */
    __IO uint32_t CLKSEL2;               /*!< [0x0018] Clock Source Select Control Register 2                           */
    __IO uint32_t CLKSEL3;               /*!< [0x001c] Clock Source Select Control Register 3                           */
    __IO uint32_t CLKDIV0;               /*!< [0x0020] Clock Divider Number Register 0                                  */
    __IO uint32_t CLKDIV1;               /*!< [0x0024] Clock Divider Number Register 1                                  */
    __IO uint32_t CLKDIV2;               /*!< [0x0028] Clock Divider Number Register 2                                  */
    __IO uint32_t CLKDIV3;               /*!< [0x002c] Clock Divider Number Register 3                                  */
    __IO uint32_t CLKDIV4;               /*!< [0x0030] Clock Divider Number Register 4                                  */
    __IO uint32_t PCLKDIV;               /*!< [0x0034] APB Clock Divider Register                                       */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE1[2];
    /** @endcond */
    __IO uint32_t PLLCTL;                /*!< [0x0040] PLL Control Register                                             */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE2[3];
    /** @endcond */
    __I  uint32_t STATUS;                /*!< [0x0050] Clock Status Monitor Register                                    */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE3[3];
    /** @endcond */
    __IO uint32_t CLKOCTL;               /*!< [0x0060] Clock Output Control Register                                    */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE4[3];
    /** @endcond */
    __IO uint32_t CLKDCTL;               /*!< [0x0070] Clock Fail Detector Control Register                             */
    __IO uint32_t CLKDSTS;               /*!< [0x0074] Clock Fail Detector Status Register                              */
    __IO uint32_t CDUPB;                 /*!< [0x0078] Clock Frequency Range Detector Upper Boundary Register           */
    __IO uint32_t CDLOWB;                /*!< [0x007c] Clock Frequency Range Detector Lower Boundary Register           */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE5[4];
    /** @endcond */
    __IO uint32_t PMUCTL;                /*!< [0x0090] Power Manager Control Register                                   */
    __IO uint32_t PMUSTS;                /*!< [0x0094] Power Manager Status Register                                    */
    __IO uint32_t LDOCTL;                /*!< [0x0098] LDO Control Register                                             */
    __IO uint32_t SWKDBCTL;              /*!< [0x009c] Standby Power-down Wake-up De-bounce Control Register            */
    __IO uint32_t PASWKCTL;              /*!< [0x00a0] GPA Standby Power-down Wake-up Control Register                  */
    __IO uint32_t PBSWKCTL;              /*!< [0x00a4] GPB Standby Power-down Wake-up Control Register                  */
    __IO uint32_t PCSWKCTL;              /*!< [0x00a8] GPC Standby Power-down Wake-up Control Register                  */
    __IO uint32_t PDSWKCTL;              /*!< [0x00ac] GPD Standby Power-down Wake-up Control Register                  */
    __IO uint32_t IOPDCTL;               /*!< [0x00b0] GPIO Standby Power-down Control Register                         */

} CLK_T;

/**
    @addtogroup FMC Flash Memory Controller(FMC)
    Memory Mapped Structure for FMC Controller
@{ */

typedef struct
{
    __IO uint32_t ISPCTL;                /*!< [0x0000] ISP Control Register                                             */
    __IO uint32_t ISPADDR;               /*!< [0x0004] ISP Address Register                                             */
    __IO uint32_t ISPDAT;                /*!< [0x0008] ISP Data Register                                                */
    __IO uint32_t ISPCMD;                /*!< [0x000c] ISP Command Register                                             */
    __IO uint32_t ISPTRG;                /*!< [0x0010] ISP Trigger Control Register                                     */
    __I  uint32_t DFBA;                  /*!< [0x0014] Data Flash Base Address                                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[10];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t ISPSTS;                /*!< [0x0040] ISP Status Register                                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CYCCTL;                /*!< [0x004c] Flash Access Cycle Control Register                              */
    __O  uint32_t KPKEY0;                /*!< [0x0050] KPROM KEY0 Data Register                                         */
    __O  uint32_t KPKEY1;                /*!< [0x0054] KPROM KEY1 Data Register                                         */
    __O  uint32_t KPKEY2;                /*!< [0x0058] KPROM KEY2 Data Register                                         */
    __IO uint32_t KPKEYTRG;              /*!< [0x005c] KPROM KEY Comparison Trigger Control Register                    */
    __IO uint32_t KPKEYSTS;              /*!< [0x0060] KPROM KEY Comparison Status Register                             */
    __I  uint32_t KPKEYCNT;              /*!< [0x0064] KPROM KEY-Unmatched Counting Register                            */
    __I  uint32_t KPCNT;                 /*!< [0x0068] KPROM KEY-Unmatched Power-On Counting Register                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[5];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t MPDAT0;                /*!< [0x0080] ISP Data0 Register                                               */
    __IO uint32_t MPDAT1;                /*!< [0x0084] ISP Data1 Register                                               */
    __IO uint32_t MPDAT2;                /*!< [0x0088] ISP Data2 Register                                               */
    __IO uint32_t MPDAT3;                /*!< [0x008c] ISP Data3 Register                                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[12];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t MPSTS;                 /*!< [0x00c0] ISP Multi-Program Status Register                                */
    __I  uint32_t MPADDR;                /*!< [0x00c4] ISP Multi-Program Address Register                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[2];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t XOMR0STS;              /*!< [0x00d0] XOM Region 0 Status Register                                     */
    __I  uint32_t XOMR1STS;              /*!< [0x00d4] XOM Region 1 Status Register                                     */
    __I  uint32_t XOMR2STS;              /*!< [0x00d8] XOM Region 2 Status Register                                     */
    __I  uint32_t XOMR3STS;              /*!< [0x00dc] XOM Region 3 Status Register                                     */
    __I  uint32_t XOMSTS;                /*!< [0x00e0] XOM Status Register                                              */

} FMC_T;

/**
    @addtogroup GPIO General Purpose Input/Output Controller(GPIO)
    Memory Mapped Structure for GPIO Controller
@{ */

typedef struct
{
    __IO uint32_t MODE;          /* Offset: 0x00/0x40/0x80/0xC0/0x100/0x140/0x180/0x1C0  Port A-H I/O Mode Control                       */
    __IO uint32_t DINOFF;        /* Offset: 0x04/0x44/0x84/0xC4/0x104/0x144/0x184/0x1C4  Port A-H Digital Input Path Disable Control     */
    __IO uint32_t DOUT;          /* Offset: 0x08/0x48/0x88/0xC8/0x108/0x148/0x188/0x1C8  Port A-H Data Output Value                      */
    __IO uint32_t DATMSK;        /* Offset: 0x0C/0x4C/0x8C/0xCC/0x10C/0x14C/0x18C/0x1CC  Port A-H Data Output Write Mask                 */
    __I  uint32_t PIN;           /* Offset: 0x10/0x50/0x90/0xD0/0x110/0x150/0x190/0x1D0  Port A-H Pin Value                              */
    __IO uint32_t DBEN;          /* Offset: 0x14/0x54/0x94/0xD4/0x114/0x154/0x194/0x1D4  Port A-H De-Bounce Enable Control Register      */
    __IO uint32_t INTTYPE;       /* Offset: 0x18/0x58/0x98/0xD8/0x118/0x158/0x198/0x1D8  Port A-H Interrupt Trigger Type Control         */
    __IO uint32_t INTEN;         /* Offset: 0x1C/0x5C/0x9C/0xDC/0x11C/0x15C/0x19C/0x1DC  Port A-H Interrupt Enable Control Register      */
    __IO uint32_t INTSRC;        /* Offset: 0x20/0x60/0xA0/0xE0/0x120/0x160/0x1A0/0x1E0  Port A-H Interrupt Source Flag                  */
    __IO uint32_t SMTEN;         /* Offset: 0x24/0x64/0xA4/0xE4/0x124/0x164/0x1A4/0x1E4  Port A-H Input Schmitt Trigger Enable Register  */
    __IO uint32_t SLEWCTL;       /* Offset: 0x28/0x68/0xA8/0xE8/0x128/0x168/0x1A8/0x1E8  Port A-H High Slew Rate Control Register        */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PUSEL;         /* Offset: 0x30/0x70/0xB0/0xF0/0x130/0x170/0x1B0/0x1F0  Port A-H Pull-up and Pull-down Enable Register  */

} GPIO_T;

typedef struct
{
    __IO uint32_t DBCTL;         /* Offset: 0x440  Interrupt De-bounce Control Register                              */

} GPIO_DBCTL_T;

/**
    @addtogroup PDMA Peripheral Direct Memory Access Controller(PDMA)
    Memory Mapped Structure for PDMA Controller
@{ */


typedef struct
{
    __IO uint32_t CTL;             /*!< [0x0000] Descriptor Table Control Register of PDMA Channel n.             */
    __IO uint32_t SA;              /*!< [0x0004] Source Address Register of PDMA Channel n                        */
    __IO uint32_t DA;              /*!< [0x0008] Destination Address Register of PDMA Channel n                   */
    __IO uint32_t NEXT;            /*!< [0x000c] First Scatter-Gather Descriptor Table Offset Address of PDMA Channel n */
} DSCT_T;


typedef struct
{
    __IO uint32_t STCR;           /*!< [0x0500] Stride Transfer Count Register of PDMA Channel 0                 */
    __IO uint32_t ASOCR;          /*!< [0x0504] Address Stride Offset Register of PDMA Channel 0                 */
} STRIDE_T;

typedef struct
{
    __IO uint32_t AICTL;         /*!< [0x0600] Address Interval Control Register of PDMA Channel 0                 */
    __IO uint32_t RCNT;          /*!< [0x0604] Repeat Count Register of PDMA Channel 0                             */
} REPEAT_T;

typedef struct
{
    DSCT_T DSCT[16];
    __I  uint32_t CURSCAT[16];              /*!< [0x0100] Current Scatter-Gather Descriptor Table Address of PDMA Channel n */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[176];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CHCTL;                 /*!< [0x0400] PDMA Channel Control Register                                    */
    __O  uint32_t PAUSE;                 /*!< [0x0404] PDMA Transfer Pause Control Register                              */
    __O  uint32_t SWREQ;                 /*!< [0x0408] PDMA Software Request Register                                   */
    __I  uint32_t TRGSTS;                /*!< [0x040c] PDMA Channel Request Status Register                             */
    __IO uint32_t PRISET;                /*!< [0x0410] PDMA Fixed Priority Setting Register                             */
    __O  uint32_t PRICLR;                /*!< [0x0414] PDMA Fixed Priority Clear Register                               */
    __IO uint32_t INTEN;                 /*!< [0x0418] PDMA Interrupt Enable Register                                   */
    __IO uint32_t INTSTS;                /*!< [0x041c] PDMA Interrupt Status Register                                   */
    __IO uint32_t ABTSTS;                /*!< [0x0420] PDMA Channel Read/Write Target Abort Flag Register               */
    __IO uint32_t TDSTS;                 /*!< [0x0424] PDMA Channel Transfer Done Flag Register                         */
    __IO uint32_t ALIGN;                 /*!< [0x0428] PDMA Transfer Alignment Status Register                          */
    __I  uint32_t TACTSTS;               /*!< [0x042c] PDMA Transfer Active Flag Register                               */
    __IO uint32_t TOUTPSC;               /*!< [0x0430] PDMA Time-out Prescaler Register                                 */
    __IO uint32_t TOUTEN;                /*!< [0x0434] PDMA Time-out Enable Register                                    */
    __IO uint32_t TOUTIEN;               /*!< [0x0438] PDMA Time-out Interrupt Enable Register                          */
    __IO uint32_t SCATBA;                /*!< [0x043c] PDMA Scatter-Gather Descriptor Table Base Address Register       */
    __IO uint32_t TOC0_1;                /*!< [0x0440] PDMA Time-out Counter Ch1 and Ch0 Register                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CHRST;                 /*!< [0x0460] PDMA Channel Reset Register                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t REQSEL0_3;             /*!< [0x0480] PDMA Request Source Select Register 0                            */
    __IO uint32_t REQSEL4_7;             /*!< [0x0484] PDMA Request Source Select Register 1                            */
    __IO uint32_t REQSEL8_11;            /*!< [0x0488] PDMA Request Source Select Register 2                            */
    __IO uint32_t REQSEL12_15;           /*!< [0x048c] PDMA Request Source Select Register 3                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[28];
    /// @endcond //HIDDEN_SYMBOLS
    STRIDE_T     STRIDE[6];
    /// @cond HIDDEN_SYMBOLS
    __IO uint32_t RESERVE5[52];
    /// @endcond //HIDDEN_SYMBOLS
    REPEAT_T    REPEAT[2];
} PDMA_T;

/**
    @addtogroup TIMER Timer Controller(TIMER)
    Memory Mapped Structure for TIMER Controller
@{ */

typedef struct
{
    __IO uint32_t CTL;                   /*!< [0x0000] Timer Control Register                                           */
    __IO uint32_t CMP;                   /*!< [0x0004] Timer Comparator Register                                        */
    __IO uint32_t INTSTS;                /*!< [0x0008] Timer Interrupt Status Register                                  */
    __IO uint32_t CNT;                   /*!< [0x000c] Timer Data Register                                              */
    __I  uint32_t CAP;                   /*!< [0x0010] Timer Capture Data Register                                      */
    __IO uint32_t EXTCTL;                /*!< [0x0014] Timer External Control Register                                  */
    __IO uint32_t EINTSTS;               /*!< [0x0018] Timer External Interrupt Status Register                         */
    __IO uint32_t TRGCTL;                /*!< [0x001c] Timer Trigger Control Register                                   */
    __IO uint32_t ALTCTL;                /*!< [0x0020] Timer Alternative Control Register                               */
    /** @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE0[7];
    /** @endcond */
    __IO uint32_t PWMCTL;                /*!< [0x0040] Timer PWM Control Register                                       */
    __IO uint32_t PWMCLKSRC;             /*!< [0x0044] Timer PWM Counter Clock Source Register                          */
    __IO uint32_t PWMCLKPSC;             /*!< [0x0048] Timer PWM Counter Clock Pre-scale Register                       */
    __IO uint32_t PWMCNTCLR;             /*!< [0x004c] Timer PWM Clear Counter Register                                 */
    __IO uint32_t PWMPERIOD;             /*!< [0x0050] Timer PWM Period Register                                        */
    __IO uint32_t PWMCMPDAT;             /*!< [0x0054] Timer PWM Comparator Register                                    */
    __IO uint32_t PWMDTCTL;              /*!< [0x0058] Timer PWM Dead-Time Control Register                             */
    __I  uint32_t PWMCNT;                /*!< [0x005c] Timer PWM Counter Register                                       */
    __IO uint32_t PWMMSKEN;              /*!< [0x0060] Timer PWM Output Mask Enable Register                            */
    __IO uint32_t PWMMSK;                /*!< [0x0064] Timer PWM Output Mask Data Control Register                      */
    __IO uint32_t PWMBNF;                /*!< [0x0068] Timer PWM Brake Pin Noise Filter Register                        */
    __IO uint32_t PWMFAILBRK;            /*!< [0x006c] Timer PWM System Fail Brake Control Register                     */
    __IO uint32_t PWMBRKCTL;             /*!< [0x0070] Timer PWM Brake Control Register                                 */
    __IO uint32_t PWMPOLCTL;             /*!< [0x0074] Timer PWM Pin Output Polar Control Register                      */
    __IO uint32_t PWMPOEN;               /*!< [0x0078] Timer PWM Pin Output Enable Register                             */
    __O  uint32_t PWMSWBRK;              /*!< [0x007c] Timer PWM Software Trigger Brake Control Register                */
    __IO uint32_t PWMINTEN0;             /*!< [0x0080] Timer PWM Interrupt Enable Register 0                            */
    __IO uint32_t PWMINTEN1;             /*!< [0x0084] Timer PWM Interrupt Enable Register 1                            */
    __IO uint32_t PWMINTSTS0;            /*!< [0x0088] Timer PWM Interrupt Status Register 0                            */
    __IO uint32_t PWMINTSTS1;            /*!< [0x008c] Timer PWM Interrupt Status Register 1                            */
    __IO uint32_t PWMEADCTS;             /*!< [0x0090] Timer PWM EADC Trigger Source Select Register                    */
    __IO uint32_t PWMSCTL;               /*!< [0x0094] Timer PWM Synchronous Control Register                           */
    __O  uint32_t PWMSTRG;               /*!< [0x0098] Timer PWM Synchronous Trigger Register                           */
    __IO uint32_t PWMSTATUS;             /*!< [0x009c] Timer PWM Status Register                                        */
    __I  uint32_t PWMPBUF;               /*!< [0x00a0] Timer PWM Period Buffer Register                                 */
    __I  uint32_t PWMCMPBUF;             /*!< [0x00a4] Timer PWM Comparator Buffer Register                             */

} TIMER_T;

//#include "wdt_reg.h"
//#include "wwdt_reg.h"
//#include "rtc_reg.h"

/**
    @addtogroup EPWM Pulse Width Modulation Controller(EPWM)
    Memory Mapped Structure for EPWM Controller
@{ */

typedef struct
{
    __IO uint32_t RCAPDAT; /*!< [0x20C/0x214/0x21C/0x224/0x22C/0x234] EPWM Rising Capture Data Register 0~5 */
    __IO uint32_t FCAPDAT; /*!< [0x210/0x218/0x220/0x228/0x230/0x238] EPWM Falling Capture Data Register 0~5 */
} ECAPDAT_T;

typedef struct
{
    __IO uint32_t CTL0;                  /*!< [0x0000] EPWM Control Register 0                                           */
    __IO uint32_t CTL1;                  /*!< [0x0004] EPWM Control Register 1                                           */
    __IO uint32_t SYNC;                  /*!< [0x0008] EPWM Synchronization Register                                     */
    __IO uint32_t SWSYNC;                /*!< [0x000c] EPWM Software Control Synchronization Register                    */
    __IO uint32_t CLKSRC;                /*!< [0x0010] EPWM Clock Source Register                                        */
    __IO uint32_t CLKPSC[3];             /*!< [0x0014] EPWM Clock Prescale Register 0/1,2/3,4/5                          */
    __IO uint32_t CNTEN;                 /*!< [0x0020] EPWM Counter Enable Register                                      */
    __IO uint32_t CNTCLR;                /*!< [0x0024] EPWM Clear Counter Register                                       */
    __IO uint32_t LOAD;                  /*!< [0x0028] EPWM Load Register                                                */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PERIOD[6];             /*!< [0x0030] EPWM Period Register 0~5                                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CMPDAT[6];             /*!< [0x0050] EPWM Comparator Register 0~5                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t DTCTL[3];              /*!< [0x0070] EPWM Dead-Time Control Register 0/1,2/3,4/5                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PHS[3];                /*!< [0x0080] EPWM Counter Phase Register 0/1,2/3,4/5                           */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[1];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t CNT[6];                /*!< [0x0090] EPWM Counter Register 0~5                                         */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t WGCTL0;                /*!< [0x00b0] EPWM Generation Register 0                                        */
    __IO uint32_t WGCTL1;                /*!< [0x00b4] EPWM Generation Register 1                                        */
    __IO uint32_t MSKEN;                 /*!< [0x00b8] EPWM Mask Enable Register                                         */
    __IO uint32_t MSK;                   /*!< [0x00bc] EPWM Mask Data Register                                           */
    __IO uint32_t BNF;                   /*!< [0x00c0] EPWM Brake Noise Filter Register                                  */
    __IO uint32_t FAILBRK;               /*!< [0x00c4] EPWM System Fail Brake Control Register                           */
    __IO uint32_t BRKCTL[3];             /*!< [0x00c8] EPWM Brake Edge Detect Control Register 0/1,2/3,4/5               */
    __IO uint32_t POLCTL;                /*!< [0x00d4] EPWM Pin Polar Inverse Register                                   */
    __IO uint32_t POEN;                  /*!< [0x00d8] EPWM Output Enable Register                                       */
    __O  uint32_t SWBRK;                 /*!< [0x00dc] EPWM Software Brake Control Register                              */
    __IO uint32_t INTEN0;                /*!< [0x00e0] EPWM Interrupt Enable Register 0                                  */
    __IO uint32_t INTEN1;                /*!< [0x00e4] EPWM Interrupt Enable Register 1                                  */
    __IO uint32_t INTSTS0;               /*!< [0x00e8] EPWM Interrupt Flag Register 0                                    */
    __IO uint32_t INTSTS1;               /*!< [0x00ec] EPWM Interrupt Flag Register 1                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t DACTRGEN;              /*!< [0x00f4] EPWM Trigger DAC Enable Register                                  */
    __IO uint32_t EADCTS0;               /*!< [0x00f8] EPWM Trigger EADC Source Select Register 0                        */
    __IO uint32_t EADCTS1;               /*!< [0x00fc] EPWM Trigger EADC Source Select Register 1                        */
    __IO uint32_t FTCMPDAT[3];           /*!< [0x0100] EPWM Free Trigger Compare Register 0/1,2/3,4/5                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE7[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t SSCTL;                 /*!< [0x0110] EPWM Synchronous Start Control Register                           */
    __O  uint32_t SSTRG;                 /*!< [0x0114] EPWM Synchronous Start Trigger Register                           */
    __IO uint32_t LEBCTL;                /*!< [0x0118] EPWM Leading Edge Blanking Control Register                       */
    __IO uint32_t LEBCNT;                /*!< [0x011c] EPWM Leading Edge Blanking Counter Register                       */
    __IO uint32_t STATUS;                /*!< [0x0120] EPWM Status Register                                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE8[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t IFA[6];                /*!< [0x0130] EPWM Interrupt Flag Accumulator Register 0~5                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE9[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t AINTSTS;               /*!< [0x0150] EPWM Accumulator Interrupt Flag Register                          */
    __IO uint32_t AINTEN;                /*!< [0x0154] EPWM Accumulator Interrupt Enable Register                        */
    __IO uint32_t APDMACTL;              /*!< [0x0158] EPWM Accumulator PDMA Control Register                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE10[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t FDEN;                  /*!< [0x0160] EPWM Fault Detect Enable Register                                 */
    __IO uint32_t FDCTL[6];              /*!< [0x0164~0x178] EPWM Fault Detect Control Register 0~5                      */
    __IO uint32_t FDIEN;                 /*!< [0x017C] EPWM Fault Detect Interrupt Enable Register                       */
    __IO uint32_t FDSTS;                 /*!< [0x0180] EPWM Fault Detect Interrupt Flag Register                         */
    __IO uint32_t EADCPSCCTL;            /*!< [0x0184] EPWM Trigger EADC Prescale Control Register                       */
    __IO uint32_t EADCPSC0;              /*!< [0x0188] EPWM Trigger EADC Prescale Register 0                             */
    __IO uint32_t EADCPSC1;              /*!< [0x018C] EPWM Trigger EADC Prescale Register 1                             */
    __IO uint32_t EADCPSCNT0;            /*!< [0x0190] EPWM Trigger EADC Prescale Counter Register 0                     */
    __IO uint32_t EADCPSCNT1;            /*!< [0x0194] EPWM Trigger EADC Prescale Counter Register 1                     */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE11[26];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CAPINEN;               /*!< [0x0200] EPWM Capture Input Enable Register                                */
    __IO uint32_t CAPCTL;                /*!< [0x0204] EPWM Capture Control Register                                     */
    __I  uint32_t CAPSTS;                /*!< [0x0208] EPWM Capture Status Register                                      */
    ECAPDAT_T CAPDAT[6];                  /*!< [0x020C] EPWM Rising and Falling Capture Data Register 0~5                 */
    __IO uint32_t PDMACTL;               /*!< [0x023c] EPWM PDMA Control Register                                        */
    __I  uint32_t PDMACAP[3];            /*!< [0x0240] EPWM Capture Channel 01,23,45 PDMA Register                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE12[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CAPIEN;                /*!< [0x0250] EPWM Capture Interrupt Enable Register                            */
    __IO uint32_t CAPIF;                 /*!< [0x0254] EPWM Capture Interrupt Flag Register                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE13[43];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t PBUF[6];               /*!< [0x0304] EPWM PERIOD0~5 Buffer                                             */
    __I  uint32_t CMPBUF[6];             /*!< [0x031c] EPWM CMPDAT0~5 Buffer                                             */
    __I  uint32_t CPSCBUF[3];            /*!< [0x0334] EPWM CLKPSC0_1/2_3/4_5 Buffer                                     */
    __I  uint32_t FTCBUF[3];             /*!< [0x0340] EPWM FTCMPDAT0_1/2_3/4_5 Buffer                                   */
    __IO uint32_t FTCI;                  /*!< [0x034c] EPWM FTCMPDAT Indicator Register                                  */

} EPWM_T;

/**
    @addtogroup BPWM Basic Pulse Width Modulation Controller(BPWM)
    Memory Mapped Structure for BPWM Controller
@{ */

typedef struct
{
    __IO uint32_t RCAPDAT; /*!< [0x20C/0x214/0x21C/0x224/0x22C/0x234] BPWM Rising Capture Data Register 0~5 */
    __IO uint32_t FCAPDAT; /*!< [0x210/0x218/0x220/0x228/0x230/0x238] BPWM Falling Capture Data Register 0~5 */
} BCAPDAT_T;

typedef struct
{
    __IO uint32_t CTL0;                  /*!< [0x0000] BPWM Control Register 0                                          */
    __IO uint32_t CTL1;                  /*!< [0x0004] BPWM Control Register 1                                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKSRC;                /*!< [0x0010] BPWM Clock Source Register                                       */
    __IO uint32_t CLKPSC;                /*!< [0x0014] BPWM Clock Prescale Register                                     */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CNTEN;                 /*!< [0x0020] BPWM Counter Enable Register                                     */
    __IO uint32_t CNTCLR;                /*!< [0x0024] BPWM Clear Counter Register                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PERIOD;                /*!< [0x0030] BPWM Period Register                                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CMPDAT[6];             /*!< [0x0050] BPWM Comparator Register 0~5                                     */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[10];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t CNT;                   /*!< [0x0090] BPWM Counter Register                                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t WGCTL0;                /*!< [0x00b0] BPWM Generation Register 0                                       */
    __IO uint32_t WGCTL1;                /*!< [0x00b4] BPWM Generation Register 1                                       */
    __IO uint32_t MSKEN;                 /*!< [0x00b8] BPWM Mask Enable Register                                        */
    __IO uint32_t MSK;                   /*!< [0x00bc] BPWM Mask Data Register                                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[5];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t POLCTL;                /*!< [0x00d4] BPWM Pin Polar Inverse Register                                  */
    __IO uint32_t POEN;                  /*!< [0x00d8] BPWM Output Enable Register                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE7[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t INTEN;                 /*!< [0x00e0] BPWM Interrupt Enable Register                                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE8[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t INTSTS;                /*!< [0x00e8] BPWM Interrupt Flag Register                                     */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE9[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t EADCTS0;               /*!< [0x00f8] BPWM Trigger EADC Source Select Register 0                       */
    __IO uint32_t EADCTS1;               /*!< [0x00fc] BPWM Trigger EADC Source Select Register 1                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE10[4];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t SSCTL;                 /*!< [0x0110] BPWM Synchronous Start Control Register                          */
    __O  uint32_t SSTRG;                 /*!< [0x0114] BPWM Synchronous Start Trigger Register                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE11[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t STATUS;                /*!< [0x0120] BPWM Status Register                                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE12[55];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CAPINEN;               /*!< [0x0200] BPWM Capture Input Enable Register                               */
    __IO uint32_t CAPCTL;                /*!< [0x0204] BPWM Capture Control Register                                    */
    __I  uint32_t CAPSTS;                /*!< [0x0208] BPWM Capture Status Register                                     */
    BCAPDAT_T CAPDAT[6];                  /*!< [0x020C] BPWM Rising and Falling Capture Data Register 0~5                */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE13[5];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CAPIEN;                /*!< [0x0250] BPWM Capture Interrupt Enable Register                           */
    __IO uint32_t CAPIF;                 /*!< [0x0254] BPWM Capture Interrupt Flag Register                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE14[43];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t PBUF;                  /*!< [0x0304] BPWM PERIOD Buffer                                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE15[5];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t CMPBUF[6];             /*!< [0x031c] BPWM CMPDAT 0~5 Buffer                                           */

} BPWM_T;

//#include "qei_reg.h"
//#include "ecap_reg.h"
//#include "uart_reg.h"
//#include "emac_reg.h"
//#include "sc_reg.h"
//#include "i2s_reg.h"

/**
    @addtogroup SPI Serial Peripheral Interface Controller(SPI)
    Memory Mapped Structure for SPI Controller
@{ */

typedef struct
{
    __IO uint32_t CTL;                   /*!< [0x0000] SPI Control Register                                             */
    __IO uint32_t CLKDIV;                /*!< [0x0004] SPI Clock Divider Register                                       */
    __IO uint32_t SSCTL;                 /*!< [0x0008] SPI Slave Select Control Register                                */
    __IO uint32_t PDMACTL;               /*!< [0x000c] SPI PDMA Control Register                                        */
    __IO uint32_t FIFOCTL;               /*!< [0x0010] SPI FIFO Control Register                                        */
    __IO uint32_t STATUS;                /*!< [0x0014] SPI Status Register                                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[2];
    /// @endcond //HIDDEN_SYMBOLS
    __O  uint32_t TX;                    /*!< [0x0020] SPI Data Transmit Register                                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[3];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t RX;                    /*!< [0x0030] SPI Data Receive Register                                        */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[11];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t I2SCTL;                /*!< [0x0060] I2S Control Register                                             */
    __IO uint32_t I2SCLK;                /*!< [0x0064] I2S Clock Divider Control Register                               */
    __IO uint32_t I2SSTS;                /*!< [0x0068] I2S Status Register                                              */

} SPI_T;

//#include "qspi_reg.h"
//#include "spim_reg.h"
/**
    @addtogroup I2C Inter-IC Bus Controller(I2C)
    Memory Mapped Structure for I2C Controller
@{ */

typedef struct
{
    __IO uint32_t CTL0;                  /*!< [0x0000] I2C Control Register 0                                           */
    __IO uint32_t ADDR0;                 /*!< [0x0004] I2C Slave Address Register0                                      */
    __IO uint32_t DAT;                   /*!< [0x0008] I2C Data Register                                                */
    __I  uint32_t STATUS0;               /*!< [0x000c] I2C Status Register 0                                            */
    __IO uint32_t CLKDIV;                /*!< [0x0010] I2C Clock Divided Register                                       */
    __IO uint32_t TOCTL;                 /*!< [0x0014] I2C Time-out Control Register                                    */
    __IO uint32_t ADDR1;                 /*!< [0x0018] I2C Slave Address Register1                                      */
    __IO uint32_t ADDR2;                 /*!< [0x001c] I2C Slave Address Register2                                      */
    __IO uint32_t ADDR3;                 /*!< [0x0020] I2C Slave Address Register3                                      */
    __IO uint32_t ADDRMSK0;              /*!< [0x0024] I2C Slave Address Mask Register0                                 */
    __IO uint32_t ADDRMSK1;              /*!< [0x0028] I2C Slave Address Mask Register1                                 */
    __IO uint32_t ADDRMSK2;              /*!< [0x002c] I2C Slave Address Mask Register2                                 */
    __IO uint32_t ADDRMSK3;              /*!< [0x0030] I2C Slave Address Mask Register3                                 */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t WKCTL;                 /*!< [0x003c] I2C Wake-up Control Register                                     */
    __IO uint32_t WKSTS;                 /*!< [0x0040] I2C Wake-up Status Register                                      */
    __IO uint32_t CTL1;                  /*!< [0x0044] I2C Control Register 1                                           */
    __IO uint32_t STATUS1;               /*!< [0x0048] I2C Status Register 1                                            */
    __IO uint32_t TMCTL;                 /*!< [0x004c] I2C Timing Configure Control Register                            */
    __IO uint32_t BUSCTL;                /*!< [0x0050] I2C Bus Management Control Register                              */
    __IO uint32_t BUSTCTL;               /*!< [0x0054] I2C Bus Management Timer Control Register                        */
    __IO uint32_t BUSSTS;                /*!< [0x0058] I2C Bus Management Status Register                               */
    __IO uint32_t PKTSIZE;               /*!< [0x005c] I2C Packet Error Checking Byte Number Register                   */
    __I  uint32_t PKTCRC;                /*!< [0x0060] I2C Packet Error Checking Byte Value Register                    */
    __IO uint32_t BUSTOUT;               /*!< [0x0064] I2C Bus Management Timer Register                                */
    __IO uint32_t CLKTOUT;               /*!< [0x0068] I2C Bus Management Clock Low Timer Register                      */

} I2C_T;

/**
    @addtogroup UUART UART Mode of USCI Controller(UUART)
    Memory Mapped Structure for UUART Controller
@{ */

typedef struct
{
    __IO uint32_t CTL;                   /*!< [0x0000] USCI Control Register                                            */
    __IO uint32_t INTEN;                 /*!< [0x0004] USCI Interrupt Enable Register                                   */
    __IO uint32_t BRGEN;                 /*!< [0x0008] USCI Baud Rate Generator Register                                */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t DATIN0;                /*!< [0x0010] USCI Input Data Signal Configuration Register 0                  */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CTLIN0;                /*!< [0x0020] USCI Input Control Signal Configuration Register 0               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKIN;                 /*!< [0x0028] USCI Input Clock Signal Configuration Register                   */
    __IO uint32_t LINECTL;               /*!< [0x002c] USCI Line Control Register                                       */
    __IO uint32_t TXDAT;                 /*!< [0x0030] USCI Transmit Data Register                                      */
    __IO uint32_t RXDAT;                 /*!< [0x0034] USCI Receive Data Register                                       */
    __IO uint32_t BUFCTL;                /*!< [0x0038] USCI Transmit/Receive Buffer Control Register                    */
    __IO uint32_t BUFSTS;                /*!< [0x003c] USCI Transmit/Receive Buffer Status Register                     */
    __IO uint32_t PDMACTL;               /*!< [0x0040] USCI PDMA Control Register                                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[4];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t WKCTL;                 /*!< [0x0054] USCI Wake-up Control Register                                    */
    __IO uint32_t WKSTS;                 /*!< [0x0058] USCI Wake-up Status Register                                     */
    __IO uint32_t PROTCTL;               /*!< [0x005c] USCI Protocol Control Register                                   */
    __IO uint32_t PROTIEN;               /*!< [0x0060] USCI Protocol Interrupt Enable Register                          */
    __IO uint32_t PROTSTS;               /*!< [0x0064] USCI Protocol Status Register                                    */

} UUART_T;

//#include "uspi_reg.h"
//#include "ui2c_reg.h"
//#include "can_reg.h"
//#include "sdh_reg.h"
//#include "ebi_reg.h"

/**
    @addtogroup USBD USB Device Controller(USBD)
    Memory Mapped Structure for USBD Controller
@{ */

#define USBD_MAX_EP_BUF		12

typedef struct
{
    __IO uint32_t BUFSEG;               /*!< [0x0000] Endpoint n Buffer Segmentation Register                          */
    __IO uint32_t MXPLD;                /*!< [0x0004] Endpoint n Maximal Payload Register                              */
    __IO uint32_t CFG;                  /*!< [0x0008] Endpoint n Configuration Register                                */
    __IO uint32_t CFGP;                 /*!< [0x000c] Endpoint n Set Stall and Clear In/Out Ready Control Register     */

} USBD_EP_T;

typedef struct
{
    __IO uint32_t INTEN;                 /*!< [0x0000] USB Device Interrupt Enable Register                             */
    __IO uint32_t INTSTS;                /*!< [0x0004] USB Device Interrupt Event Status Register                       */
    __IO uint32_t FADDR;                 /*!< [0x0008] USB Device Function Address Register                             */
    __I  uint32_t EPSTS;                 /*!< [0x000c] USB Device Endpoint Status Register                              */
    __IO uint32_t ATTR;                  /*!< [0x0010] USB Device Bus Status and Attribution Register                   */
    __I  uint32_t VBUSDET;               /*!< [0x0014] USB Device VBUS Detection Register                               */
    __IO uint32_t STBUFSEG;              /*!< [0x0018] SETUP Token Buffer Segmentation Register                         */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t EPSTS0;                /*!< [0x0020] USB Device Endpoint Status Register 0                            */
    __I  uint32_t EPSTS1;                /*!< [0x0024] USB Device Endpoint Status Register 1                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[24];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t LPMATTR;               /*!< [0x0088] USB LPM Attribution Register                                     */
    __I  uint32_t FN;                    /*!< [0x008c] USB Frame number Register                                        */
    __IO uint32_t SE0;                   /*!< [0x0090] USB Device Drive SE0 Control Register                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[283];
    /// @endcond //HIDDEN_SYMBOLS
    USBD_EP_T     EP[USBD_MAX_EP_BUF];       /*!< [0x500~0x5bc] USB End Point 0 ~ 11 Configuration Register                 */

} USBD_T;

//#include "hsusbd_reg.h"
//#include "usbh_reg.h"
//#include "hsusbh_reg.h"
//#include "otg_reg.h"
//#include "hsotg_reg.h"
//#include "crc_reg.h"
//#include "crypto_reg.h"
//#include "trng_reg.h"
//#include "eadc_reg.h"
//#include "dac_reg.h"
//#include "acmp_reg.h"
//#include "opa_reg.h"
//#include "ccap_reg.h"


/** @addtogroup PERIPHERAL_MEM_MAP Peripheral Memory Base
  Memory Mapped Structure for Peripherals
  @{
 */
/* Peripheral and SRAM base address */
#define FLASH_BASE           ((uint32_t)0x00000000)      /*!< Flash base address      */
#define SRAM_BASE            ((uint32_t)0x20000000)      /*!< SRAM Base Address       */
#define PERIPH_BASE          ((uint32_t)0x40000000)      /*!< Peripheral Base Address */
#define AHBPERIPH_BASE       PERIPH_BASE                 /*!< AHB Base Address */
#define APBPERIPH_BASE       (PERIPH_BASE + (uint32_t)0x00040000)  /*!< APB Base Address */

/*!< AHB peripherals */
#define SYS_BASE               (AHBPERIPH_BASE + 0x00000UL)
#define CLK_BASE               (AHBPERIPH_BASE + 0x00200UL)
#define NMI_BASE               (AHBPERIPH_BASE + 0x00300UL)
#define GPIOA_BASE             (AHBPERIPH_BASE + 0x04000UL)
#define GPIOB_BASE             (AHBPERIPH_BASE + 0x04040UL)
#define GPIOC_BASE             (AHBPERIPH_BASE + 0x04080UL)
#define GPIOD_BASE             (AHBPERIPH_BASE + 0x040C0UL)
#define GPIOE_BASE             (AHBPERIPH_BASE + 0x04100UL)
#define GPIOF_BASE             (AHBPERIPH_BASE + 0x04140UL)
#define GPIOG_BASE             (AHBPERIPH_BASE + 0x04180UL)
#define GPIOH_BASE             (AHBPERIPH_BASE + 0x041C0UL)
#define GPIOI_BASE             (AHBPERIPH_BASE + 0x04200UL)
#define GPIO_DBCTL_BASE        (AHBPERIPH_BASE + 0x04440UL)
#define GPIO_PIN_DATA_BASE     (AHBPERIPH_BASE + 0x04800UL)
#define PDMA_BASE              (AHBPERIPH_BASE + 0x08000UL)
#define USBH_BASE              (AHBPERIPH_BASE + 0x09000UL)
#define HSUSBH_BASE            (AHBPERIPH_BASE + 0x1A000UL)
#define EMAC_BASE              (AHBPERIPH_BASE + 0x0B000UL)
#define FMC_BASE               (AHBPERIPH_BASE + 0x0C000UL)
#define SDH0_BASE              (AHBPERIPH_BASE + 0x0D000UL)
#define SDH1_BASE              (AHBPERIPH_BASE + 0x0E000UL)
#define EBI_BASE               (AHBPERIPH_BASE + 0x10000UL)
#define HSUSBD_BASE            (AHBPERIPH_BASE + 0x19000UL)
#define CCAP_BASE              (AHBPERIPH_BASE + 0x30000UL)
#define CRC_BASE               (AHBPERIPH_BASE + 0x31000UL)
#define TAMPER_BASE            (AHBPERIPH_BASE + 0xE1000UL)

/*!< APB2 peripherals */
#define WDT_BASE              (APBPERIPH_BASE + 0x00000UL)
#define WWDT_BASE             (APBPERIPH_BASE + 0x00100UL)
#define OPA_BASE              (APBPERIPH_BASE + 0x06000UL)
#define I2S_BASE              (APBPERIPH_BASE + 0x08000UL)
#define EADC1_BASE            (APBPERIPH_BASE + 0x0B000UL)
#define TIMER0_BASE           (APBPERIPH_BASE + 0x10000UL)
#define TIMER1_BASE           (APBPERIPH_BASE + 0x10100UL)
#define EPWM0_BASE            (APBPERIPH_BASE + 0x18000UL)
#define BPWM0_BASE            (APBPERIPH_BASE + 0x1A000UL)
#define QSPI0_BASE            (APBPERIPH_BASE + 0x20000UL)
#define SPI1_BASE             (APBPERIPH_BASE + 0x22000UL)
#define SPI3_BASE             (APBPERIPH_BASE + 0x24000UL)
#define UART0_BASE            (APBPERIPH_BASE + 0x30000UL)
#define UART2_BASE            (APBPERIPH_BASE + 0x32000UL)
#define UART4_BASE            (APBPERIPH_BASE + 0x34000UL)
#define UART6_BASE            (APBPERIPH_BASE + 0x36000UL)
#define I2C0_BASE             (APBPERIPH_BASE + 0x40000UL)
#define I2C2_BASE             (APBPERIPH_BASE + 0x42000UL)
#define CAN0_BASE             (APBPERIPH_BASE + 0x60000UL)
#define CAN2_BASE             (APBPERIPH_BASE + 0x62000UL)
#define QEI0_BASE             (APBPERIPH_BASE + 0x70000UL)
#define ECAP0_BASE            (APBPERIPH_BASE + 0x74000UL)
#define USCI0_BASE            (APBPERIPH_BASE + 0x90000UL)


/*!< APB1 peripherals */
#define RTC_BASE              (APBPERIPH_BASE + 0x01000UL)
#define EADC_BASE             (APBPERIPH_BASE + 0x03000UL)
#define ACMP01_BASE           (APBPERIPH_BASE + 0x05000UL)
#define USBD_BASE             (APBPERIPH_BASE + 0x80000UL)
#define OTG_BASE              (APBPERIPH_BASE + 0x0D000UL)
#define HSOTG_BASE            (APBPERIPH_BASE + 0x0F000UL)
#define TIMER2_BASE           (APBPERIPH_BASE + 0x11000UL)
#define TIMER3_BASE           (APBPERIPH_BASE + 0x11100UL)
#define EPWM1_BASE            (APBPERIPH_BASE + 0x19000UL)
#define BPWM1_BASE            (APBPERIPH_BASE + 0x1B000UL)
#define SPI0_BASE             (APBPERIPH_BASE + 0x21000UL)
#define SPI2_BASE             (APBPERIPH_BASE + 0x23000UL)
#define QSPI1_BASE            (APBPERIPH_BASE + 0x29000UL)
#define UART1_BASE            (APBPERIPH_BASE + 0x31000UL)
#define UART3_BASE            (APBPERIPH_BASE + 0x33000UL)
#define UART5_BASE            (APBPERIPH_BASE + 0x35000UL)
#define UART7_BASE            (APBPERIPH_BASE + 0x37000UL)
#define I2C1_BASE             (APBPERIPH_BASE + 0x41000UL)
#define CAN1_BASE             (APBPERIPH_BASE + 0x61000UL)
#define QEI1_BASE             (APBPERIPH_BASE + 0x71000UL)
#define ECAP1_BASE            (APBPERIPH_BASE + 0x75000UL)
#define TRNG_BASE             (APBPERIPH_BASE + 0x79000UL)
#define USCI1_BASE            (APBPERIPH_BASE + 0x91000UL)
#define CRPT_BASE             (0x50080000UL)
#define SPIM_BASE             (0x40007000UL)

#define SC0_BASE             (APBPERIPH_BASE + 0x50000UL)
#define SC1_BASE             (APBPERIPH_BASE + 0x51000UL)
#define SC2_BASE             (APBPERIPH_BASE + 0x52000UL)
#define DAC0_BASE            (APBPERIPH_BASE + 0x07000UL)
#define DAC1_BASE            (APBPERIPH_BASE + 0x07040UL)
#define DACDBG_BASE          (APBPERIPH_BASE + 0x07FECUL)
#define OPA0_BASE            (APBPERIPH_BASE + 0x06000UL)

/*@}*/ /* end of group PERIPHERAL_MEM_MAP */


/** @addtogroup PERIPHERAL_DECLARATION Peripheral Pointer
  The Declaration of Peripherals
  @{
 */

#define SYS                  ((SYS_T *)   SYS_BASE)
#define CLK                  ((CLK_T *)   CLK_BASE)
#define NMI                  ((NMI_T *)   NMI_BASE)
#define PA                   ((GPIO_T *)  GPIOA_BASE)
#define PB                   ((GPIO_T *)  GPIOB_BASE)
#define PC                   ((GPIO_T *)  GPIOC_BASE)
#define PD                   ((GPIO_T *)  GPIOD_BASE)
#define PE                   ((GPIO_T *)  GPIOE_BASE)
#define PF                   ((GPIO_T *)  GPIOF_BASE)
#define PG                   ((GPIO_T *)  GPIOG_BASE)
#define PH                   ((GPIO_T *)  GPIOH_BASE)
#define GPA                  ((GPIO_T *)  GPIOA_BASE)
#define GPB                  ((GPIO_T *)  GPIOB_BASE)
#define GPC                  ((GPIO_T *)  GPIOC_BASE)
#define GPD                  ((GPIO_T *)  GPIOD_BASE)
#define GPE                  ((GPIO_T *)  GPIOE_BASE)
#define GPF                  ((GPIO_T *)  GPIOF_BASE)
#define GPG                  ((GPIO_T *)  GPIOG_BASE)
#define GPH                  ((GPIO_T *)  GPIOH_BASE)
#define GPIO                 ((GPIO_DBCTL_T *) GPIO_DBCTL_BASE)
#define PDMA                 ((PDMA_T *)  PDMA_BASE)
#define USBH                 ((USBH_T *)  USBH_BASE)
#define HSUSBH               ((HSUSBH_T *)  HSUSBH_BASE)
#define EMAC                 ((EMAC_T *)  EMAC_BASE)
#define FMC                  ((FMC_T *)   FMC_BASE)
#define SDH0                 ((SDH_T *)   SDH0_BASE)
#define SDH1                 ((SDH_T *)   SDH1_BASE)
#define EBI                  ((EBI_T *)   EBI_BASE)
#define CRC                  ((CRC_T *)   CRC_BASE)
#define TAMPER               ((TAMPER_T *) TAMPER_BASE)

#define WDT                  ((WDT_T *)   WDT_BASE)
#define WWDT                 ((WWDT_T *)  WWDT_BASE)
#define RTC                  ((RTC_T *)   RTC_BASE)
#define EADC                 ((EADC_T *)  EADC_BASE)
#define EADC0                ((EADC_T *)  EADC_BASE)
#define EADC1                ((EADC_T *)  EADC1_BASE)
#define ACMP01               ((ACMP_T *)  ACMP01_BASE)

#define I2S0                 ((I2S_T *)   I2S_BASE)
#define USBD                 ((USBD_T *)  USBD_BASE)
#define OTG                  ((OTG_T *)   OTG_BASE)
#define HSUSBD               ((HSUSBD_T *)HSUSBD_BASE)
#define HSOTG                ((HSOTG_T *) HSOTG_BASE)
#define TIMER0               ((TIMER_T *) TIMER0_BASE)
#define TIMER1               ((TIMER_T *) TIMER1_BASE)
#define TIMER2               ((TIMER_T *) TIMER2_BASE)
#define TIMER3               ((TIMER_T *) TIMER3_BASE)
#define EPWM0                ((EPWM_T *)  EPWM0_BASE)
#define EPWM1                ((EPWM_T *)  EPWM1_BASE)
#define BPWM0                ((BPWM_T *)  BPWM0_BASE)
#define BPWM1                ((BPWM_T *)  BPWM1_BASE)
#define ECAP0                ((ECAP_T *)  ECAP0_BASE)
#define ECAP1                ((ECAP_T *)  ECAP1_BASE)
#define QEI0                 ((QEI_T *)   QEI0_BASE)
#define QEI1                 ((QEI_T *)   QEI1_BASE)
#define QSPI0                ((QSPI_T *)  QSPI0_BASE)
#define QSPI1                ((QSPI_T *)  QSPI1_BASE)
#define SPI0                 ((SPI_T *)   SPI0_BASE)
#define SPI1                 ((SPI_T *)   SPI1_BASE)
#define SPI2                 ((SPI_T *)   SPI2_BASE)
#define SPI3                 ((SPI_T *)   SPI3_BASE)
#define UART0                ((UART_T *)  UART0_BASE)
#define UART1                ((UART_T *)  UART1_BASE)
#define UART2                ((UART_T *)  UART2_BASE)
#define UART3                ((UART_T *)  UART3_BASE)
#define UART4                ((UART_T *)  UART4_BASE)
#define UART5                ((UART_T *)  UART5_BASE)
#define UART6                ((UART_T *)  UART6_BASE)
#define UART7                ((UART_T *)  UART7_BASE)
#define I2C0                 ((I2C_T *)   I2C0_BASE)
#define I2C1                 ((I2C_T *)   I2C1_BASE)
#define I2C2                 ((I2C_T *)   I2C2_BASE)
#define SC0                  ((SC_T *)    SC0_BASE)
#define SC1                  ((SC_T *)    SC1_BASE)
#define SC2                  ((SC_T *)    SC2_BASE)
#define CAN0                 ((CAN_T *)   CAN0_BASE)
#define CAN1                 ((CAN_T *)   CAN1_BASE)
#define CAN2                 ((CAN_T *)   CAN2_BASE)
#define CRPT                 ((CRPT_T *)  CRPT_BASE)
#define TRNG                 ((TRNG_T *)  TRNG_BASE)
#define SPIM                 ((volatile SPIM_T *)  SPIM_BASE)
#define DAC0                 ((DAC_T *)   DAC0_BASE)
#define DAC1                 ((DAC_T *)   DAC1_BASE)
#define USPI0                ((USPI_T *) USCI0_BASE)                     /*!< USPI0 Configuration Struct                       */
#define USPI1                ((USPI_T *) USCI1_BASE)                     /*!< USPI1 Configuration Struct                       */
#define OPA                  ((OPA_T *) OPA_BASE)
#define UI2C0                ((UI2C_T *) USCI0_BASE)                     /*!< UI2C0 Configuration Struct                       */
#define UI2C1                ((UI2C_T *) USCI1_BASE)                     /*!< UI2C1 Configuration Struct                       */
#define UUART0               ((UUART_T *) USCI0_BASE)                    /*!< UUART0 Configuration Struct                      */
#define UUART1               ((UUART_T *) USCI1_BASE)                    /*!< UUART1 Configuration Struct                      */
#define CCAP                 ((CCAP_T *)  CCAP_BASE)

/*@}*/ /* end of group ERIPHERAL_DECLARATION */

/** @addtogroup IO_ROUTINE I/O Routines
  The Declaration of I/O Routines
  @{
 */

typedef volatile uint8_t  vu8;        ///< Define 8-bit unsigned volatile data type
typedef volatile uint16_t vu16;       ///< Define 16-bit unsigned volatile data type
typedef volatile uint32_t vu32;       ///< Define 32-bit unsigned volatile data type
typedef volatile uint64_t vu64;       ///< Define 64-bit unsigned volatile data type

/**
  * @brief Get a 8-bit unsigned value from specified address
  * @param[in] addr Address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified address
  */
#define M8(addr)  (*((vu8  *) (addr)))

/**
  * @brief Get a 16-bit unsigned value from specified address
  * @param[in] addr Address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified address
  * @note The input address must be 16-bit aligned
  */
#define M16(addr) (*((vu16 *) (addr)))

/**
  * @brief Get a 32-bit unsigned value from specified address
  * @param[in] addr Address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified address
  * @note The input address must be 32-bit aligned
  */
#define M32(addr) (*((vu32 *) (addr)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = (value)

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = (value)

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)            (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = (value)

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = (value)

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = (value)

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = (value)

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)            (*((volatile unsigned char *)(port)))


/*@}*/ /* end of group IO_ROUTINE */

/******************************************************************************/
/*                Legacy Constants                                            */
/******************************************************************************/
/** @addtogroup Legacy_Constants Legacy Constants
  Legacy Constants
  @{
*/

#ifndef NULL
#define NULL           (0)      ///< NULL pointer
#endif

#define TRUE           (1UL)      ///< Boolean true, define to use in API parameters or return value
#define FALSE          (0UL)      ///< Boolean false, define to use in API parameters or return value

#define ENABLE         (1UL)      ///< Enable, define to use in API parameters
#define DISABLE        (0UL)      ///< Disable, define to use in API parameters

/* Byte Mask Definitions */
#define BYTE0_Msk              (0x000000FFUL)         ///< Mask to get bit0~bit7 from a 32 bit integer
#define BYTE1_Msk              (0x0000FF00UL)         ///< Mask to get bit8~bit15 from a 32 bit integer
#define BYTE2_Msk              (0x00FF0000UL)         ///< Mask to get bit16~bit23 from a 32 bit integer
#define BYTE3_Msk              (0xFF000000UL)         ///< Mask to get bit24~bit31 from a 32 bit integer

#define GET_BYTE0(u32Param)    (((u32Param) & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    (((u32Param) & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    (((u32Param) & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    (((u32Param) & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

/*@}*/ /* end of group Legacy_Constants */


/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
//#include "sys.h"
//#include "clk.h"

//#include "acmp.h"
//#include "dac.h"
//#include "emac.h"

/**
    @addtogroup UART Universal Asynchronous Receiver/Transmitter Controller(UART)
    Memory Mapped Structure for UART Controller
@{ */

typedef struct
{
    __IO uint32_t DAT;                   /*!< [0x0000] UART Receive/Transmit Buffer Register                            */
    __IO uint32_t INTEN;                 /*!< [0x0004] UART Interrupt Enable Register                                   */
    __IO uint32_t FIFO;                  /*!< [0x0008] UART FIFO Control Register                                       */
    __IO uint32_t LINE;                  /*!< [0x000c] UART Line Control Register                                       */
    __IO uint32_t MODEM;                 /*!< [0x0010] UART Modem Control Register                                      */
    __IO uint32_t MODEMSTS;              /*!< [0x0014] UART Modem Status Register                                       */
    __IO uint32_t FIFOSTS;               /*!< [0x0018] UART FIFO Status Register                                        */
    __IO uint32_t INTSTS;                /*!< [0x001c] UART Interrupt Status Register                                   */
    __IO uint32_t TOUT;                  /*!< [0x0020] UART Time-out Register                                           */
    __IO uint32_t BAUD;                  /*!< [0x0024] UART Baud Rate Divider Register                                  */
    __IO uint32_t IRDA;                  /*!< [0x0028] UART IrDA Control Register                                       */
    __IO uint32_t ALTCTL;                /*!< [0x002c] UART Alternate Control/Status Register                           */
    __IO uint32_t FUNCSEL;               /*!< [0x0030] UART Function Select Register                                    */
    __IO uint32_t LINCTL;                /*!< [0x0034] UART LIN Control Register                                        */
    __IO uint32_t LINSTS;                /*!< [0x0038] UART LIN Status Register                                         */
    __IO uint32_t BRCOMP;                /*!< [0x003c] UART Baud Rate Compensation Register                             */
    __IO uint32_t WKCTL;                 /*!< [0x0040] UART Wake-up Control Register                                    */
    __IO uint32_t WKSTS;                 /*!< [0x0044] UART Wake-up Status Register                                     */
    __IO uint32_t DWKCOMP;               /*!< [0x0048] UART Incoming Data Wake-up Compensation Register                 */

} UART_T;

//#include "usci_spi.h"
//#include "gpio.h"
//#include "ccap.h"
//#include "ecap.h"
//#include "qei.h"
//#include "timer.h"
//#include "timer_pwm.h"
//#include "pdma.h"
//#include "crypto.h"
//#include "trng.h"
//#include "fmc.h"
//#include "spim.h"
//#include "i2c.h"
//#include "i2s.h"
//#include "epwm.h"
//#include "eadc.h"
//#include "bpwm.h"
//#include "wdt.h"
//#include "wwdt.h"
//#include "opa.h"
//#include "crc.h"
//#include "ebi.h"
//#include "usci_i2c.h"
//#include "scuart.h"
//#include "sc.h"
//#include "spi.h"
//#include "qspi.h"
//#include "can.h"
//#include "rtc.h"
//#include "usci_uart.h"
//#include "sdh.h"
//#include "usbd.h"
//#include "hsusbd.h"
//#include "otg.h"
//#include "hsotg.h"

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TIMER0		1
#define RUNTIME_TIMER1		2
#define RUNTIME_TIMER2		3
#define RUNTIME_TIMER3		4

#ifdef __cplusplus
}
#endif

#endif  /* __M480_H__ */

