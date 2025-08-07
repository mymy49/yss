/**************************************************************************//**
 * @file     M251.h
 * @version  V1.0
 * @brief    Peripheral Access Layer Header File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/**
  \mainpage NuMicro M251/M252/M254/M256/M258 Series CMSIS BSP Driver Reference
  *
  * <b>Introduction</b>
  *
  * This user manual describes the usage of M251/M252/M254/M256/M258 Series MCU device driver
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
  * SPDX-License-Identifier: Apache-2.0<br/>
  * Copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
  */

#ifndef __M251_H__
#define __M251_H__

#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSIS_Device CMSIS Definitions
  Configuration of the Cortex-M23 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

/**
 * @details  Interrupt Number Definition.
 */
typedef enum IRQn
{
    /******  Cortex-M0 Processor Exceptions Numbers ***********************************************/
    NonMaskableInt_IRQn       = -14,    /*!< 2 Non Maskable Interrupt                             */
    HardFault_IRQn            = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                     */
    SVCall_IRQn               = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                       */
    PendSV_IRQn               = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                       */
    SysTick_IRQn              = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                   */

    /******  ARMIKMCU Swift specific Interrupt Numbers ********************************************/
    BOD_IRQn                  = 0,      /*!< Brown-Out Low Voltage Detected Interrupt             */
    IRCTRIM_IRQn              = 1,      /*!< Watch Dog Timer Interrupt                            */
    PWRWU_IRQn                = 2,      /*!< EINT0, EINT2 and EINT4 Interrupt                     */
    RESERVE0                  = 3,      /*!< Reserve 0                                            */
    CLKFAIL_IRQn              = 4,      /*!< Clock fail detected Interrupt                          */
    RESERVE1                  = 5,      /*!< Reserve 1                                            */
    RTC_IRQn                  = 6,      /*!< Real Time Clock Interrupt                            */
    TAMPER_IRQn               = 7,      /*!< Tamper detection Interrupt                           */
    WDT_IRQn                  = 8,      /*!< Watch Dog Timer Interrupt                            */
    WWDT_IRQn                 = 9,      /*!< Window Watch Dog Timer Interrupt                     */
    EINT0_IRQn                = 10,     /*!< External Input 0 Interrupt                           */
    EINT1_IRQn                = 11,     /*!< External Input 1 Interrupt                           */
    EINT2_IRQn                = 12,     /*!< External Input 2 Interrupt                           */
    EINT3_IRQn                = 13,     /*!< External Input 3 Interrupt                           */
    EINT4_IRQn                = 14,     /*!< External Input 4 Interrupt                           */
    EINT5_IRQn                = 15,     /*!< External Input 5 Interrupt                           */
    GPA_IRQn                  = 16,     /*!< GPIO PORT A Interrupt                                */
    GPB_IRQn                  = 17,     /*!< GPIO PORT B Interrupt                                */
    GPC_IRQn                  = 18,     /*!< GPIO PORT C Interrupt                                */
    GPD_IRQn                  = 19,     /*!< GPIO PORT D Interrupt                                */
    GPE_IRQn                  = 20,     /*!< GPIO PORT E Interrupt                                */
    GPF_IRQn                  = 21,     /*!< GPIO PORT F Interrupt                                */
    QSPI0_IRQn                = 22,     /*!< QSPI0 Interrupt                                      */
    SPI0_IRQn                 = 23,     /*!< SPI0 Interrupt                                       */
    BRAKE0_IRQn               = 24,     /*!< PWM Brake0 Interrupt                                 */
    PWM0_P0_IRQn              = 25,     /*!< PWM0 P0 Interrupt                                    */
    PWM0_P1_IRQn              = 26,     /*!< PWM0 P1 Interrupt                                    */
    PWM0_P2_IRQn              = 27,     /*!< PWM0 P2 Interrupt                                    */
    BRAKE1_IRQn               = 28,     /*!< PWM Brake1 Interrupt                                 */
    PWM1_P0_IRQn              = 29,     /*!< PWM1 P0 Interrupt                                    */
    PWM1_P1_IRQn              = 30,     /*!< PWM1 P1 Interrupt                                    */
    PWM1_P2_IRQn              = 31,     /*!< PWM1 P2 Interrupt                                    */
    TMR0_IRQn                 = 32,     /*!< TIMER0  Interrupt                                    */
    TMR1_IRQn                 = 33,     /*!< TIMER1  Interrupt                                    */
    TMR2_IRQn                 = 34,     /*!< TIMER2  Interrupt                                    */
    TMR3_IRQn                 = 35,     /*!< TIMER3  Interrupt                                    */
    UART0_IRQn                = 36,     /*!< UART0  Interrupt                                     */
    UART1_IRQn                = 37,     /*!< UART1  Interrupt                                     */
    I2C0_IRQn                 = 38,     /*!< I2C0  Interrupt                                      */
    I2C1_IRQn                 = 39,     /*!< I2C1  Interrupt                                      */
    PDMA_IRQn                 = 40,     /*!< Peripheral DMA Interrupt                             */
    DAC_IRQn                  = 41,     /*!< DAC Interrupt                                        */
    EADC_INT0_IRQn            = 42,     /*!< Enhance ADC Interrupt 0                              */
    EADC_INT1_IRQn            = 43,     /*!< Enhance ADC Interrupt 1                              */
    ACMP01_IRQn               = 44,     /*!< ACMP0 Interrupt                                      */
    BPWM0_IRQn                = 45,     /*!< BPWM0 Interrupt                                      */
    EADC_INT2_IRQn            = 46,     /*!< Enhance EADC Interrupt 2                             */
    EADC_INT3_IRQn            = 47,     /*!< Enhance EADC Interrupt 3                             */
    UART2_IRQn                = 48,     /*!< UART2 Interrupt                                      */
    UART3_IRQn                = 49,     /*!< UART3 Interrupt                                      */
    USCI0_IRQn                = 50,     /*!< USCI0 Interrupt                                      */
    SPI1_IRQn                 = 51,     /*!< SPI0 Interrupt                                       */
    USCI1_IRQn                = 52,     /*!< USCI1 Interrupt                                      */
    USBD_IRQn                 = 53,     /*!< USB Device Interrupt                                 */
    BPWM1_IRQn                = 54,     /*!< BPWM1 Interrupt                                      */
    PSIO_IRQn                 = 55,     /*!< PSIO Interrupt                                       */
    RESERVE4                  = 56,     /*!< Reserve 4                                            */
    CRPT_IRQn                 = 57,     /*!< Crypto interrupt                                     */
    SC0_IRQn                  = 58,     /*!< Smart Card0 Interrupt                                */
    RESERVE5                  = 59,     /*!< Reserve 5                                            */
    USCI2_IRQn                = 60,     /*!< USCI2 Interrupt                                      */
    LCD_IRQn                  = 61,     /*!< LCD Interrupt                                        */
    OPA_IRQn                  = 62,     /*!< OPA Interrupt                                        */
    TK_IRQn                   = 63,     /*!< Touch Key Interrupt                                  */
} IRQn_Type;

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
#pragma push
#pragma anon_unions
#elif defined (__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
/* anonymous unions are enabled by default */
#elif defined (__TMS470__)
/* anonymous unions are enabled by default */
#elif defined (__TASKING__)
#pragma warning 586
#elif defined (__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/* --------  Configuration of the Cortex-ARMv8MBL Processor and Core Peripherals  ------- */
#define __ARMv8MBL_REV            0x0000U   /* Core revision r0p0                         */
#define __SAU_PRESENT             0U        /* SAU present                                */
#define __MPU_PRESENT             1U        /* MPU present                                */
#define __VTOR_PRESENT            1U        /* VTOR present                               */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels    */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define USE_ASSERT                0U        /* Define to use Assert function or not       */

/** @} end of group CMSIS_Device */


#include <stdint.h>
#include "core_cm23.h"                      /* Processor and core peripherals             */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/

//#include "acmp_reg.h"

/**
    @addtogroup BPWM Basic Pulse Width Modulation Controller (BPWM)
    Memory Mapped Structure for BPWM Controller
    @{
*/

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
    __IO uint32_t CMPDAT[6];             /*!< [0x0050 ~ 0x0064] BPWM Comparator Register 0 ~ 6                          */
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
    BCAPDAT_T CAPDAT[6];                 /*!< [0x020C ~ 0x0238] BPWM Rising and Falling Capture Data Register 0~5       */
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
    __I  uint32_t CMPBUF[6];             /*!< [0x031c ~ 0x0330] BPWM CMPDAT 0 ~ 5 Buffer                                */
} BPWM_T;

/**
    @addtogroup CLK System Clock Controller (CLK)
    Memory Mapped Structure for CLK Controller
    @{
*/

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
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKDIV4;               /*!< [0x0030] Clock Divider Number Register 4                                  */
    __IO uint32_t PCLKDIV;               /*!< [0x0034] APB Clock Divider Register                                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PLLCTL;                /*!< [0x0040] PLL Control Register                                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[3];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t STATUS;                /*!< [0x0050] Clock Status Monitor Register                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKOCTL;               /*!< [0x0060] Clock Output Control Register                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKDCTL;               /*!< [0x0070] Clock Fail Detector Control Register                             */
    __IO uint32_t CLKDSTS;               /*!< [0x0074] Clock Fail Detector Status Register                              */
    __IO uint32_t CDUPB;                 /*!< [0x0078] Clock Frequency Range Detector Upper Boundary Register           */
    __IO uint32_t CDLOWB;                /*!< [0x007c] Clock Frequency Range Detector Lower Boundary Register           */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[4];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PMUCTL;                /*!< [0x0090] Power Manager Control Register                                   */
    __IO uint32_t PMUSTS;                /*!< [0x0094] Power Manager Status Register                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t HXTFSEL;               /*!< [0x00b4] HXT Filter Select Control Register                               */
} CLK_T;

//#include "crc_reg.h"
//#include "crypto_reg.h"
//#include "dac_reg.h"
//#include "eadc_reg.h"
//#include "ebi_reg.h"

/**
    @addtogroup FMC Flash Memory Controller (FMC)
    Memory Mapped Structure for FMC Controller
    @{
*/

typedef struct
{
    __IO uint32_t ISPCTL;                /*!< [0x0000] ISP Control Register                                             */
    __IO uint32_t ISPADDR;               /*!< [0x0004] ISP Address Register                                             */
    __IO uint32_t ISPDAT;                /*!< [0x0008] ISP Data Register                                                */
    __IO uint32_t ISPCMD;                /*!< [0x000c] ISP CMD Register                                                 */
    __IO uint32_t ISPTRG;                /*!< [0x0010] ISP Trigger Control Register                                     */
    __I  uint32_t RESERVE0;
    __IO uint32_t FTCTL;                 /*!< [0x0018] Flash Access Time Control Register                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[9];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t ISPSTS;                /*!< [0x0040] ISP Status Register                                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CYCCTL;                /*!< [0x004c] Flash Access Cycle Control Register                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[12];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t MPDAT0;                /*!< [0x0080] ISP Data0 Register                                               */
    __IO uint32_t MPDAT1;                /*!< [0x0084] ISP Data1 Register                                               */
    __IO uint32_t MPDAT2;                /*!< [0x0088] ISP Data2 Register                                               */
    __IO uint32_t MPDAT3;                /*!< [0x008c] ISP Data3 Register                                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[12];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t MPSTS;                 /*!< [0x00c0] ISP Multi-program Status Register                                */
    __I  uint32_t MPADDR;                /*!< [0x00c4] ISP Multi-program Address Register                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[2];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t XOMR0STS0;             /*!< [0x00d0] XOM Region 0 Status Register 0                                   */
    __I  uint32_t XOMR0STS1;             /*!< [0x00d4] XOM Region 0 Status Register 1                                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[2];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t XOMSTS;                /*!< [0x00e0] XOM Status Register                                              */
} FMC_T;

/**
    @addtogroup GPIO_CONST GPIO Bit Field Definition
    Constant Definitions for GPIO Controller
@{ */

typedef struct
{
    __IO uint32_t MODE;               /*!< [0x00/0x40/0x80/0xc0/0x100/0x140] PA~PF I/O Mode Control                     */
    __IO uint32_t DINOFF;             /*!< [0x04/0x44/0x84/0xc4/0x104/0x144] PA~PF Digital Input Path Disable Control   */
    __IO uint32_t DOUT;               /*!< [0x08/0x48/0x88/0xc8/0x108/0x148] PA~PF Data Output Value                    */
    __IO uint32_t DATMSK;             /*!< [0x0c/0x4c/0x8c/0xcc/0x10c/0x14c] PA~PF Data Output Write Mask               */
    __I  uint32_t PIN;                /*!< [0x10/0x50/0x90/0xd0/0x110/0x150] PA~PF Pin Value                            */
    __IO uint32_t DBEN;               /*!< [0x14/0x54/0x94/0xd4/0x114/0x154] PA~PF De-bounce Enable Control Register    */
    __IO uint32_t INTTYPE;            /*!< [0x18/0x58/0x98/0xd8/0x118/0x158] PA~PF Interrupt Trigger Type Control       */
    __IO uint32_t INTEN;              /*!< [0x1c/0x5c/0x9c/0xdc/0x11c/0x15c] PA~PF Interrupt Enable Control Register    */
    __IO uint32_t INTSRC;             /*!< [0x20/0x60/0xa0/0xe0/0x120/0x160] PA~PF Interrupt Source Flag                */
    __IO uint32_t SMTEN;              /*!< [0x24/0x64/0xa4/0xe4/0x124/0x164] PA~PF Input Schmitt Trigger Enable Register*/
    __IO uint32_t SLEWCTL;            /*!< [0x28/0x68/0xa8/0xe8/0x128/0x168] PA~PF High Slew Rate Control Register      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PUSEL;              /*!< [0x30/0x70/0xB0/0xF0/0x130/0x170] PA~PF Pull-up and Pull-down Selection Register*/
} GPIO_T;

typedef struct
{
    __IO uint32_t DBCTL;   /*!< [0x0440] Interrupt De-bounce Control Register                             */

} GPIO_DBCTL_T;

//#include "i2c_reg.h"
//#include "opa_reg.h"

/**
    @addtogroup PDMA Peripheral Direct Memory Access Controller (PDMA)
    Memory Mapped Structure for PDMA Controller
    @{
*/

typedef struct
{
    __IO uint32_t CTL;      /*!< [0x0000] Descriptor Table Control Register of PDMA Channel n.              */
    __IO uint32_t SA;       /*!< [0x0004] Source Address Register of PDMA Channel n                        */
    __IO uint32_t DA;       /*!< [0x0008] Destination Address Register of PDMA Channel n                   */
    __IO uint32_t NEXT;     /*!< [0x000c] First Scatter-Gather Descriptor Table Offset Address of PDMA Channel n */

} DSCT_T;

typedef struct
{
    __IO uint32_t STC;      /*!< [0x0500] Stride Transfer Count Register of PDMA Channel 0                 */
    __IO uint32_t ASOCR;    /*!< [0x0504] Address Stride Offset Register of PDMA Channel 0                 */
} STRIDE_T;



typedef struct
{
    DSCT_T        DSCT[8];               /*!< [0x0000 ~ 0x007C] Control Register of PDMA Channel 0 ~ 7                  */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[32];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t CURSCAT[8];            /*!< [0x0100 ~ 0x11c] Current Scatter-gather Descriptor Table Address of PDMA Channel n */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[184];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CHCTL;                 /*!< [0x0400] PDMA Channel Control Register                                    */
    __O  uint32_t PAUSE;                 /*!< [0x0404] PDMA Transfer Pause Control Register                             */
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
    __IO uint32_t SCATBA;                /*!< [0x043c] PDMA Scatter-gather Descriptor Table Base Address Register       */
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
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[30];
    /// @endcond //HIDDEN_SYMBOLS
    STRIDE_T      STRIDE[6];             /*!< [0x0500 ~ 0x528] Stride Register of PDMA Channel 0 ~ 5                    */
} PDMA_T;

//#include "psio_reg.h"
//#include "pwm_reg.h"
//#include "rtc_reg.h"
//#include "sc_reg.h"
//#include "qspi_reg.h"

/**
    @addtogroup SPI Serial Peripheral Interface Controller (SPI)
    Memory Mapped Structure for SPI Controller
    @{
*/

typedef struct
{
    __IO uint32_t CTL;                   /*!< [0x0000] SPI Control Register                                             */
    __IO uint32_t CLKDIV;                /*!< [0x0004] SPI Clock Divider Register                                       */
    __IO uint32_t SSCTL;                 /*!< [0x0008] SPI Slave Select Control Register                                */
    __IO uint32_t PDMACTL;               /*!< [0x000c] SPI PDMA Control Register                                        */
    __IO uint32_t FIFOCTL;               /*!< [0x0010] SPI FIFO Control Register                                        */
    __IO uint32_t STATUS;                /*!< [0x0014] SPI Status Register                                              */
    __IO uint32_t STATUS2;               /*!< [0x0018] SPI Status2 Register                                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0;
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

/**
    @addtogroup SYS System Manger Controller (SYS)
    Memory Mapped Structure for SYS Controller
    @{
*/

typedef struct
{
    __I  uint32_t PDID;                  /*!< [0x0000] Part Device Identification Number Register                       */
    __IO uint32_t RSTSTS;                /*!< [0x0004] System Reset Status Register                                     */
    __IO uint32_t IPRST0;                /*!< [0x0008] Peripheral  Reset Control Register 0                             */
    __IO uint32_t IPRST1;                /*!< [0x000c] Peripheral Reset Control Register 1                              */
    __IO uint32_t IPRST2;                /*!< [0x0010] Peripheral Reset Control Register 2                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t BODCTL;                /*!< [0x0018] Brown-out Detector Control Register                              */
    __IO uint32_t IVSCTL;                /*!< [0x001c] Internal Voltage Source Control Register                         */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PORCTL0;               /*!< [0x0024] Power-On-reset Controller Register 0                             */
    __IO uint32_t VREFCTL;               /*!< [0x0028] VREF Control Register                                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[1];
    /// @endcond //HIDDEN_SYMBOLS
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
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[8];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t GPA_MFOS;              /*!< [0x0080] GPIOA Multiple Function Output Select Register                   */
    __IO uint32_t GPB_MFOS;              /*!< [0x0084] GPIOB Multiple Function Output Select Register                   */
    __IO uint32_t GPC_MFOS;              /*!< [0x0088] GPIOC Multiple Function Output Select Register                   */
    __IO uint32_t GPD_MFOS;              /*!< [0x008c] GPIOD Multiple Function Output Select Register                   */
    __IO uint32_t GPE_MFOS;              /*!< [0x0090] GPIOE Multiple Function Output Select Register                   */
    __IO uint32_t GPF_MFOS;              /*!< [0x0094] GPIOF Multiple Function Output Select Register                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[10];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t MODCTL;                /*!< [0x00c0] Modulation Control Register                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t SRAM_BISTCTL;          /*!< [0x00d0] System SRAM BIST Test Control Register                           */
    __I  uint32_t SRAM_BISTSTS;          /*!< [0x00d4] System SRAM BIST Test Status Register                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[6];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t HIRCTRIMCTL;           /*!< [0x00f0] HIRC Trim Control Register                                       */
    __IO uint32_t HIRCTRIMIEN;           /*!< [0x00f4] HIRC Trim Interrupt Enable Register                              */
    __IO uint32_t HIRCTRIMSTS;           /*!< [0x00f8] HIRC Trim Interrupt Status Register                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE7[1];
    /// @endcond //HIDDEN_SYMBOLS
    __O  uint32_t REGLCTL;               /*!< [0x0100] Register Lock Control Register                                   */
    __IO uint32_t MIRCTRIMCTL;           /*!< [0x0104] MIRC Trim Control Register                                       */
    __IO uint32_t MIRCTRIMIEN;           /*!< [0x0108] MIRC Trim Interrupt Enable Register                              */
    __IO uint32_t MIRCTRIMSTS;           /*!< [0x010c] MIRC Trim Interrupt Status Register                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE8[13];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t RTCLVRIEN;             /*!< [0x0144] RTC LVR interrupt control register                               */
    __IO uint32_t RTCLVRSTS;             /*!< [0x0148] RTC LVR interrupt status register                                */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE9[40];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PORCTL1;               /*!< [0x01ec] Power-On-reset Controller Register 1                             */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE10[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PLCTL;                 /*!< [0x01F8] Power Level Control Register                                     */
    __I  uint32_t PLSTS;                 /*!< [0x01Fc] Power Level Status Register                                      */
} SYS_T;

/**
    @addtogroup TIMER Timer Controller (TIMER)
    Memory Mapped Structure for TIMER Controller
    @{
*/

typedef struct
{
    __IO uint32_t CTL;                   /*!< [0x0000] Timer Control Register                                          */
    __IO uint32_t CMP;                   /*!< [0x0004] Timer Comparator Register                                       */
    __IO uint32_t INTSTS;                /*!< [0x0008] Timer Interrupt Status Register                                 */
    __IO uint32_t CNT;                   /*!< [0x000c] Timer Data Register                                             */
    __I  uint32_t CAP;                   /*!< [0x0010] Timer Capture Data Register                                     */
    __IO uint32_t EXTCTL;                /*!< [0x0014] Timer External Control Register                                 */
    __IO uint32_t EINTSTS;               /*!< [0x0018] Timer External Interrupt Status Register                        */
    __IO uint32_t TRGCTL;                /*!< [0x001c] Timer Trigger Control Register                                  */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[8];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PWMCTL;                /*!< [0x0040] Timer PWM Control Register                                      */
    __IO uint32_t PWMCLKPSC;             /*!< [0x0044] Timer PWM Counter Clock Pre-scale Register                      */
    __IO uint32_t PWMCNTCLR;             /*!< [0x0048] Timer PWM Clear Counter Register                                */
    __IO uint32_t PWMPERIOD;             /*!< [0x004c] Timer PWM Period Register                                       */
    __IO uint32_t PWMCMPDAT;             /*!< [0x0050] Timer PWM Comparator Register                                   */
    __I  uint32_t PWMCNT;                /*!< [0x0054] Timer PWM Counter Register                                      */
    __IO uint32_t PWMPOLCTL;             /*!< [0x0058] Timer PWM Pin Output Polar Control Register                     */
    __IO uint32_t PWMPOCTL;              /*!< [0x005c] Timer PWM Pin Output Control Register                           */
    __IO uint32_t PWMINTEN0;             /*!< [0x0060] Timer PWM Interrupt Enable Register 0                           */
    __IO uint32_t PWMINTSTS0;            /*!< [0x0064] Timer PWM Interrupt Status Register 0                           */
    __IO uint32_t PWMTRGCTL;             /*!< [0x0068] Timer PWM Trigger Control Register                              */
    __IO uint32_t PWMSTATUS;             /*!< [0x006c] Timer PWM Status Register                                       */
    __I  uint32_t PWMPBUF;               /*!< [0x0070] Timer PWM Period Buffer Register                                */
    __I  uint32_t PWMCMPBUF;             /*!< [0x0074] Timer PWM Comparator Buffer Register                            */
} TIMER_T;

/**
    @addtogroup UART Universal Asynchronous Receiver/Transmitter Controller (UART)
    Memory Mapped Structure for UART Controller
    @{
*/

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

//#include "uuart_reg.h"
//#include "ui2c_reg.h"
//#include "uspi_reg.h"
/**
    @addtogroup USBD USB Device Controller (USBD)
    Memory Mapped Structure for USBD Controller
    @{
*/

#define USBD_MAX_EP_BUF		12

typedef struct
{
    __IO uint32_t BUFSEG;                /*!< [0x0000] Endpoint n Buffer Segmentation Register                            */
    __IO uint32_t MXPLD;                 /*!< [0x0004] Endpoint n Maximal Payload Register                                */
    __IO uint32_t CFG;                   /*!< [0x0008] Endpoint n Configuration Register                                  */
    __IO uint32_t CFGP;                  /*!< [0x000c] Endpoint n Set Stall and Clear In/Out Ready Control Register       */

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
    /* @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE0[1];
    /* @endcond //HIDDEN_SYMBOLS */
    __I  uint32_t EPSTS0;                /*!< [0x0020] USB Device Endpoint Status Register 0                            */
    __I  uint32_t EPSTS1;                /*!< [0x0024] USB Device Endpoint Status Register 1                            */
    /* @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE1[24];
    /* @endcond //HIDDEN_SYMBOLS */
    __I  uint32_t LPMATTR;               /*!< [0x0088] USB LPM Attribution Register                                     */
    __I  uint32_t FN;                    /*!< [0x008c] USB Frame number Register                                        */
    __IO uint32_t SE0;                   /*!< [0x0090] USB Device Drive SE0 Control Register                            */
    __IO uint32_t BCDC;                  /*!< [0x0094] USB Device Battery Charge Detect Control Register                */
    /* @cond HIDDEN_SYMBOLS */
    __I  uint32_t RESERVE2[282];
    /* @endcond //HIDDEN_SYMBOLS */
    USBD_EP_T EP[12];                    /*!< [0x0500~0x60C] USB Device Endpoints(0~16)                                 */
} USBD_T;

//#include "wdt_reg.h"
//#include "wwdt_reg.h"
//#include "lcd_reg.h"
//#include "tk_reg.h"

/** @} end of REGISTER group */


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/

/** @addtogroup PERIPHERAL_BASE Peripheral Memory Base
  Memory Mapped Structure for Series Peripheral
  @{
 */

/* Peripheral and SRAM base address */
#define FLASH_BASE            ((uint32_t)0x00000000UL)      /*!< Flash Base Address      */
#define SRAM_BASE             ((uint32_t)0x20000000UL)      /*!< SRAM Base Address       */
#define PERIPH_BASE           ((uint32_t)0x40000000UL)      /*!< Peripheral Base Address */

/* Peripheral memory map */
#define AHBPERIPH_BASE         PERIPH_BASE                  /*!< AHB Base Address        */
#define APBPERIPH_BASE        (PERIPH_BASE + 0x00040000UL)  /*!< APB Base Address        */

/*!< AHB peripherals */
#define SYS_BASE              (AHBPERIPH_BASE + 0x00000UL)
#define CLK_BASE              (AHBPERIPH_BASE + 0x00200UL)
#define NMI_BASE              (AHBPERIPH_BASE + 0x00300UL)
#define GPIO_BASE             (AHBPERIPH_BASE + 0x04000UL)
#define GPIOA_BASE            (AHBPERIPH_BASE + 0x04000UL)
#define GPIOB_BASE            (AHBPERIPH_BASE + 0x04040UL)
#define GPIOC_BASE            (AHBPERIPH_BASE + 0x04080UL)
#define GPIOD_BASE            (AHBPERIPH_BASE + 0x040C0UL)
#define GPIOE_BASE            (AHBPERIPH_BASE + 0x04100UL)
#define GPIOF_BASE            (AHBPERIPH_BASE + 0x04140UL)
#define GPIO_DBCTL_BASE       (AHBPERIPH_BASE + 0x04440UL)
#define GPIO_PIN_DATA_BASE    (AHBPERIPH_BASE + 0x04800UL)
#define PDMA_BASE             (AHBPERIPH_BASE + 0x08000UL)
#define FMC_BASE              (AHBPERIPH_BASE + 0x0C000UL)
#define EBI_BASE              (AHBPERIPH_BASE + 0x10000UL)
#define CRC_BASE              (AHBPERIPH_BASE + 0x31000UL)
#define CRPT_BASE             (AHBPERIPH_BASE + 0x32000UL)

/*!< APB0 peripherals */
#define WDT_BASE              (APBPERIPH_BASE + 0x00000UL)
#define WWDT_BASE             (APBPERIPH_BASE + 0x00100UL)
#define OPA_BASE              (APBPERIPH_BASE + 0x06000UL)
#define TIMER01_BASE          (APBPERIPH_BASE + 0x10000UL)
#define PWM0_BASE             (APBPERIPH_BASE + 0x18000UL)
#define BPWM0_BASE            (APBPERIPH_BASE + 0x1A000UL)
#define QSPI0_BASE            (APBPERIPH_BASE + 0x20000UL)
#define SPI1_BASE             (APBPERIPH_BASE + 0x22000UL)
#define UART0_BASE            (APBPERIPH_BASE + 0x30000UL)
#define UART2_BASE            (APBPERIPH_BASE + 0x32000UL)
#define I2C0_BASE             (APBPERIPH_BASE + 0x40000UL)
#define SC0_BASE              (APBPERIPH_BASE + 0x50000UL)
#define USBD_BASE             (APBPERIPH_BASE + 0x80000UL)
#define USCI0_BASE            (APBPERIPH_BASE + 0x90000UL)
#define USCI2_BASE            (APBPERIPH_BASE + 0x92000UL)
#define TK_BASE               (APBPERIPH_BASE + 0x82000UL)

/*!< APB1 peripherals */
#define RTC_BASE              (APBPERIPH_BASE + 0x01000UL)
#define EADC_BASE             (APBPERIPH_BASE + 0x03000UL)
#define ACMP01_BASE           (APBPERIPH_BASE + 0x05000UL)
#define DAC_BASE              (APBPERIPH_BASE + 0x07000UL)
#define TIMER23_BASE          (APBPERIPH_BASE + 0x11000UL)
#define PWM1_BASE             (APBPERIPH_BASE + 0x19000UL)
#define BPWM1_BASE            (APBPERIPH_BASE + 0x1B000UL)
#define SPI0_BASE             (APBPERIPH_BASE + 0x21000UL)
#define UART1_BASE            (APBPERIPH_BASE + 0x31000UL)
#define UART3_BASE            (APBPERIPH_BASE + 0x33000UL)
#define I2C1_BASE             (APBPERIPH_BASE + 0x41000UL)
#define PSIO_BASE             (APBPERIPH_BASE + 0x83000UL)
#define USCI1_BASE            (APBPERIPH_BASE + 0x91000UL)
#define LCD_BASE              (APBPERIPH_BASE + 0x7B000UL)

/** @} end of group PERIPHERAL_BASE */


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/** @addtogroup PERIPHERAL_DECLARATION Peripheral Pointer
  The Declaration of Peripheral Pointer
  @{
 */

/*!< AHB peripherals */
#define SYS                  ((SYS_T *)             SYS_BASE)
#define CLK                  ((CLK_T *)             CLK_BASE)
#define PA                   ((GPIO_T *)            GPIOA_BASE)
#define PB                   ((GPIO_T *)            GPIOB_BASE)
#define PC                   ((GPIO_T *)            GPIOC_BASE)
#define PD                   ((GPIO_T *)            GPIOD_BASE)
#define PE                   ((GPIO_T *)            GPIOE_BASE)
#define PF                   ((GPIO_T *)            GPIOF_BASE)
#define GPIO                 ((GPIO_DBCTL_T *)      GPIO_DBCTL_BASE)
#define PDMA                 ((PDMA_T *)            PDMA_BASE)
#define FMC                  ((FMC_T *)             FMC_BASE)
#define EBI                  ((EBI_T *)             EBI_BASE)
#define CRC                  ((CRC_T *)             CRC_BASE)
#define CRPT                 ((CRPT_T *)            CRPT_BASE)

/*!< APB0 peripherals */
#define WDT                  ((WDT_T *)             WDT_BASE)
#define WWDT                 ((WWDT_T *)            WWDT_BASE)
#define OPA                  ((OPA_T *)             OPA_BASE)
#define TIMER0               ((TIMER_T *)           TIMER01_BASE)
#define TIMER1               ((TIMER_T *)           (TIMER01_BASE + 0x100UL))
#define PWM0                 ((PWM_T *)             PWM0_BASE)
#define BPWM0                ((BPWM_T *)            BPWM0_BASE)
#define QSPI0                ((QSPI_T *)            QSPI0_BASE)
#define SPI1                 ((SPI_T *)             SPI1_BASE)
#define UART0                ((UART_T *)            UART0_BASE)
#define UART2                ((UART_T *)            UART2_BASE)
#define I2C0                 ((I2C_T *)             I2C0_BASE)
#define SC0                  ((SC_T *)              SC0_BASE)
#define USBD                 ((USBD_T *)            USBD_BASE)
#define UI2C0                ((UI2C_T *)            USCI0_BASE)
#define USPI0                ((USPI_T *)            USCI0_BASE)
#define UUART0               ((UUART_T *)           USCI0_BASE)
#define UI2C2                ((UI2C_T *)            USCI2_BASE)
#define USPI2                ((USPI_T *)            USCI2_BASE)
#define UUART2               ((UUART_T *)           USCI2_BASE)
#define TK                   ((TK_T *)              TK_BASE)

/*!< APB1 peripherals */
#define RTC                  ((RTC_T *)             RTC_BASE)
#define EADC                 ((EADC_T *)            EADC_BASE)
#define ACMP01               ((ACMP_T *)            ACMP01_BASE)
#define DAC0                 ((DAC_T *)             DAC_BASE)
#define DAC1                 ((DAC_T *)             (DAC_BASE+0x40UL))
#define TIMER2               ((TIMER_T *)           TIMER23_BASE)
#define TIMER3               ((TIMER_T *)           (TIMER23_BASE+ 0x100UL))
#define PWM1                 ((PWM_T *)             PWM1_BASE)
#define BPWM1                ((BPWM_T *)            BPWM1_BASE)
#define SPI0                 ((SPI_T *)             SPI0_BASE)
#define UART1                ((UART_T *)            UART1_BASE)
#define UART3                ((UART_T *)            UART3_BASE)
#define I2C1                 ((I2C_T *)             I2C1_BASE)
#define PSIO                 ((PSIO_T *)            PSIO_BASE)
#define UI2C1                ((UI2C_T *)            USCI1_BASE)
#define USPI1                ((USPI_T *)            USCI1_BASE)
#define UUART1               ((UUART_T *)           USCI1_BASE)
#define LCD                  ((LCD_T *)             LCD_BASE)

/** @} end of group PERIPHERAL_DECLARATION */


/* --------------------  End of section using anonymous unions  ------------------- */
#if   defined (__CC_ARM)
#pragma pop
#elif defined (__ICCARM__)
/* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#elif defined (__GNUC__)
/* anonymous unions are enabled by default */
#elif defined (__TMS470__)
/* anonymous unions are enabled by default */
#elif defined (__TASKING__)
#pragma warning restore
#elif defined (__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

#ifdef __cplusplus
}

#endif


/*=============================================================================*/

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
#define outpw(port,value)   (*((volatile unsigned int *)(port))=(value))

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)          ((*((volatile unsigned int *)(port))))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)   (*((volatile unsigned short *)(port))=(value))

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)          ((*((volatile unsigned short *)(port))))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)   (*((volatile unsigned char *)(port))=(value))

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)          ((*((volatile unsigned char *)(port))))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)  (*((volatile unsigned int *)(port))=(value))

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)         ((*((volatile unsigned int *)(port))))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)  (*((volatile unsigned short *)(port))=(value))

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)         ((*((volatile unsigned short *)(port))))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)   (*((volatile unsigned char *)(port))=(value))

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)          ((*((volatile unsigned char *)(port))))

/** @} end of group IO_ROUTINE */


/******************************************************************************/
/*                Legacy Constants                                            */
/******************************************************************************/

/** @addtogroup Legacy_Constants Legacy Constants
  Legacy Constants
  @{
*/

#define E_SUCCESS     (0)

#ifndef NULL
    #define NULL      (0)                  ///< NULL pointer
#endif

#define TRUE          (1UL)                ///< Boolean true, define to use in API parameters or return value
#define FALSE         (0UL)                ///< Boolean false, define to use in API parameters or return value

#define ENABLE        (1UL)                ///< Enable, define to use in API parameters
#define DISABLE       (0UL)                ///< Disable, define to use in API parameters

/* Byte Mask Definitions */
#define BYTE0_Msk     (0x000000FFUL)       ///< Mask to get bit0~bit7 from a 32 bit integer
#define BYTE1_Msk     (0x0000FF00UL)       ///< Mask to get bit8~bit15 from a 32 bit integer
#define BYTE2_Msk     (0x00FF0000UL)       ///< Mask to get bit16~bit23 from a 32 bit integer
#define BYTE3_Msk     (0xFF000000UL)       ///< Mask to get bit24~bit31 from a 32 bit integer

#define GET_BYTE0(u32Param)    (((u32Param) & BYTE0_Msk)      ) /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    (((u32Param) & BYTE1_Msk) >>  8) /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    (((u32Param) & BYTE2_Msk) >> 16) /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    (((u32Param) & BYTE3_Msk) >> 24) /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

/** @} end of group Legacy_Constants */

#endif  /* __M251_H__ */
