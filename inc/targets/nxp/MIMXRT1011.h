/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1010RM Rev.1, 10/2021 | IMXRT1010SRM Rev.0
**     Version:             rev. 1.2, 2021-08-10
**     Build:               b211108
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1011
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1011.h
 * @version 1.2
 * @date 2021-08-10
 * @brief CMSIS Peripheral Access Layer for MIMXRT1011
 *
 * CMSIS Peripheral Access Layer for MIMXRT1011
 */

#ifndef _MIMXRT1011_H_
#define _MIMXRT1011_H_                           /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 96                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M7 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M7 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M7 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M7 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M7 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M7 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M7 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M7 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete */
  DMA4_IRQn                    = 4,                /**< DMA channel 4 transfer complete */
  DMA5_IRQn                    = 5,                /**< DMA channel 5 transfer complete */
  DMA6_IRQn                    = 6,                /**< DMA channel 6 transfer complete */
  DMA7_IRQn                    = 7,                /**< DMA channel 7 transfer complete */
  DMA8_IRQn                    = 8,                /**< DMA channel 8 transfer complete */
  DMA9_IRQn                    = 9,                /**< DMA channel 9 transfer complete */
  DMA10_IRQn                   = 10,               /**< DMA channel 10 transfer complete */
  DMA11_IRQn                   = 11,               /**< DMA channel 11 transfer complete */
  DMA12_IRQn                   = 12,               /**< DMA channel 12 transfer complete */
  DMA13_IRQn                   = 13,               /**< DMA channel 13 transfer complete */
  DMA14_IRQn                   = 14,               /**< DMA channel 14 transfer complete */
  DMA15_IRQn                   = 15,               /**< DMA channel 15 transfer complete */
  DMA_ERROR_IRQn               = 16,               /**< DMA error interrupt channels 0-15 */
  CTI0_ERROR_IRQn              = 17,               /**< CTI trigger outputs */
  CTI1_ERROR_IRQn              = 18,               /**< CTI trigger outputs */
  CORE_IRQn                    = 19,               /**< CorePlatform exception IRQ */
  LPUART1_IRQn                 = 20,               /**< LPUART1 TX interrupt and RX interrupt */
  LPUART2_IRQn                 = 21,               /**< LPUART2 TX interrupt and RX interrupt */
  LPUART3_IRQn                 = 22,               /**< LPUART3 TX interrupt and RX interrupt */
  LPUART4_IRQn                 = 23,               /**< LPUART4 TX interrupt and RX interrupt */
  PIT_IRQn                     = 24,               /**< PIT interrupt */
  USB_OTG1_IRQn                = 25,               /**< USBO2 USB OTG1 */
  FLEXSPI_IRQn                 = 26,               /**< FlexSPI0 interrupt */
  FLEXRAM_IRQn                 = 27,               /**< FlexRAM address out of range Or access hit IRQ */
  LPI2C1_IRQn                  = 28,               /**< LPI2C1 interrupt */
  LPI2C2_IRQn                  = 29,               /**< LPI2C2 interrupt */
  GPT1_IRQn                    = 30,               /**< GPT1 interrupt */
  GPT2_IRQn                    = 31,               /**< GPT2 interrupt */
  LPSPI1_IRQn                  = 32,               /**< LPSPI1 single interrupt vector for all sources */
  LPSPI2_IRQn                  = 33,               /**< LPSPI2 single interrupt vector for all sources */
  PWM1_0_IRQn                  = 34,               /**< PWM1 capture 0, compare 0, or reload 0 interrupt */
  PWM1_1_IRQn                  = 35,               /**< PWM1 capture 1, compare 1, or reload 0 interrupt */
  PWM1_2_IRQn                  = 36,               /**< PWM1 capture 2, compare 2, or reload 0 interrupt */
  PWM1_3_IRQn                  = 37,               /**< PWM1 capture 3, compare 3, or reload 0 interrupt */
  PWM1_FAULT_IRQn              = 38,               /**< PWM1 fault or reload error interrupt */
  KPP_IRQn                     = 39,               /**< Keypad nterrupt */
  SRC_IRQn                     = 40,               /**< SRC interrupt */
  GPR_IRQ_IRQn                 = 41,               /**< Used to notify cores on exception condition while boot */
  CCM_1_IRQn                   = 42,               /**< CCM IRQ1 interrupt */
  CCM_2_IRQn                   = 43,               /**< CCM IRQ2 interrupt */
  EWM_IRQn                     = 44,               /**< EWM interrupt */
  WDOG2_IRQn                   = 45,               /**< WDOG2 interrupt */
  SNVS_HP_WRAPPER_IRQn         = 46,               /**< SNVS Functional Interrupt */
  SNVS_HP_WRAPPER_TZ_IRQn      = 47,               /**< SNVS Security Interrupt */
  SNVS_LP_WRAPPER_IRQn         = 48,               /**< ON-OFF button press shorter than 5 secs (pulse event) */
  CSU_IRQn                     = 49,               /**< CSU interrupt */
  DCP_IRQn                     = 50,               /**< Combined DCP channel interrupts(except channel 0) and CRC interrupt */
  DCP_VMI_IRQn                 = 51,               /**< IRQ of DCP channel 0 */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  TRNG_IRQn                    = 53,               /**< TRNG interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt */
  SAI1_IRQn                    = 56,               /**< SAI1 interrupt */
  RTWDOG_IRQn                  = 57,               /**< RTWDOG interrupt */
  SAI3_RX_IRQn                 = 58,               /**< SAI3 interrupt */
  SAI3_TX_IRQn                 = 59,               /**< SAI3 interrupt */
  SPDIF_IRQn                   = 60,               /**< SPDIF interrupt */
  PMU_IRQn                     = 61,               /**< PMU interrupt */
  XBAR1_IRQ_0_1_2_3_IRQn       = 62,               /**< XBAR1 interrupt */
  TEMP_LOW_HIGH_IRQn           = 63,               /**< TEMPMON interrupt */
  TEMP_PANIC_IRQn              = 64,               /**< TEMPMON interrupt */
  USB_PHY_IRQn                 = 65,               /**< USBPHY (OTG1 UTMI), Interrupt */
  GPC_IRQn                     = 66,               /**< GPC interrupt */
  ADC1_IRQn                    = 67,               /**< ADC1 interrupt */
  FLEXIO1_IRQn                 = 68,               /**< FLEXIO1 interrupt */
  DCDC_IRQn                    = 69,               /**< DCDC interrupt */
  GPIO1_Combined_0_15_IRQn     = 70,               /**< Combined interrupt indication for GPIO1 signal 0 throughout 15 */
  GPIO1_Combined_16_31_IRQn    = 71,               /**< Combined interrupt indication for GPIO1 signal 16 throughout 31 */
  GPIO2_Combined_0_15_IRQn     = 72,               /**< Combined interrupt indication for GPIO2 signal 0 throughout 15 */
  GPIO5_Combined_0_15_IRQn     = 73,               /**< Combined interrupt indication for GPIO5 signal 0 throughout 15 */
  WDOG1_IRQn                   = 74,               /**< WDOG1 interrupt */
  ADC_ETC_IRQ0_IRQn            = 75,               /**< ADCETC IRQ0 interrupt */
  ADC_ETC_IRQ1_IRQn            = 76,               /**< ADCETC IRQ1 interrupt */
  ADC_ETC_IRQ2_IRQn            = 77,               /**< ADCETC IRQ2 interrupt */
  ADC_ETC_IRQ3_IRQn            = 78,               /**< ADCETC IRQ3 interrupt */
  ADC_ETC_ERROR_IRQ_IRQn       = 79                /**< ADCETC Error IRQ interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M7 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M7 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __ICACHE_PRESENT               1         /**< Defines if an ICACHE is present or not */
#define __DCACHE_PRESENT               1         /**< Defines if an DCACHE is present or not */
#define __DTCM_PRESENT                 1         /**< Defines if an DTCM is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm7.h"                  /* Core Peripheral Access Layer */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_mux_ctl_pad
{
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_14 = 0U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_13 = 1U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_12 = 2U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_11 = 3U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_10 = 4U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_09 = 5U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_08 = 6U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_07 = 7U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_06 = 8U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_05 = 9U,        /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_04 = 10U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_03 = 11U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_02 = 12U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_01 = 13U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_00 = 14U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_14 = 15U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_13 = 16U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_12 = 17U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_11 = 18U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_10 = 19U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_09 = 20U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_08 = 21U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_07 = 22U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_06 = 23U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_05 = 24U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_04 = 25U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_03 = 26U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_02 = 27U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_01 = 28U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_00 = 29U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_13  = 30U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_12  = 31U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_11  = 32U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_10  = 33U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_09  = 34U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_08  = 35U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_07  = 36U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_06  = 37U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_05  = 38U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_04  = 39U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_03  = 40U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_02  = 41U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_01  = 42U,         /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_00  = 43U,         /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc_sw_mux_ctl_pad_t;

/* @} */

/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_PAD_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_PAD_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_pad_ctl_pad
{
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_14 = 0U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_13 = 1U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_12 = 2U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_11 = 3U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_10 = 4U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_09 = 5U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_08 = 6U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_07 = 7U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_06 = 8U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_05 = 9U,        /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_04 = 10U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_03 = 11U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_02 = 12U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_01 = 13U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_00 = 14U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_14 = 15U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_13 = 16U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_12 = 17U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_11 = 18U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_10 = 19U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_09 = 20U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_08 = 21U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_07 = 22U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_06 = 23U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_05 = 24U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_04 = 25U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_03 = 26U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_02 = 27U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_01 = 28U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_00 = 29U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_13  = 30U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_12  = 31U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_11  = 32U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_10  = 33U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_09  = 34U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_08  = 35U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_07  = 36U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_06  = 37U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_05  = 38U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_04  = 39U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_03  = 40U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_02  = 41U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_01  = 42U,         /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_00  = 43U,         /**< IOMUXC SW_PAD_CTL_PAD index */
} iomuxc_sw_pad_ctl_pad_t;

/* @} */

/*!
 * @brief Enumeration for the IOMUXC select input
 *
 * Defines the enumeration for the IOMUXC select input collections.
 */
typedef enum _iomuxc_select_input
{
    kIOMUXC_USB_OTG_ID_SELECT_INPUT = 0U,          /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA_SELECT_INPUT_0 = 1U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA_SELECT_INPUT_1 = 2U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA_SELECT_INPUT_2 = 3U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA_SELECT_INPUT_3 = 4U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB_SELECT_INPUT_0 = 5U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB_SELECT_INPUT_1 = 6U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB_SELECT_INPUT_2 = 7U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB_SELECT_INPUT_3 = 8U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_DQS_FA_SELECT_INPUT = 9U,      /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_DQS_FB_SELECT_INPUT = 10U,     /**< IOMUXC select input index */
    kIOMUXC_KPP_COL_SELECT_INPUT_0  = 11U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_COL_SELECT_INPUT_1  = 12U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_COL_SELECT_INPUT_2  = 13U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_COL_SELECT_INPUT_3  = 14U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_ROW_SELECT_INPUT_0  = 15U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_ROW_SELECT_INPUT_1  = 16U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_ROW_SELECT_INPUT_2  = 17U,         /**< IOMUXC select input index */
    kIOMUXC_KPP_ROW_SELECT_INPUT_3  = 18U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_HREQ_SELECT_INPUT = 19U,        /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_SCL_SELECT_INPUT = 20U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_SDA_SELECT_INPUT = 21U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_SCL_SELECT_INPUT = 22U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_SDA_SELECT_INPUT = 23U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_PCS_SELECT_INPUT_0 = 24U,       /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SCK_SELECT_INPUT = 25U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SDI_SELECT_INPUT = 26U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SDO_SELECT_INPUT = 27U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_PCS_SELECT_INPUT_0 = 28U,       /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SCK_SELECT_INPUT = 29U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SDI_SELECT_INPUT = 30U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SDO_SELECT_INPUT = 31U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART1_RXD_SELECT_INPUT = 32U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART1_TXD_SELECT_INPUT = 33U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART2_RXD_SELECT_INPUT = 34U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART2_TXD_SELECT_INPUT = 35U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART3_RXD_SELECT_INPUT = 36U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART3_TXD_SELECT_INPUT = 37U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART4_RXD_SELECT_INPUT = 38U,        /**< IOMUXC select input index */
    kIOMUXC_LPUART4_TXD_SELECT_INPUT = 39U,        /**< IOMUXC select input index */
    kIOMUXC_NMI_GLUE_NMI_SELECT_INPUT = 40U,       /**< IOMUXC select input index */
    kIOMUXC_SPDIF_IN1_SELECT_INPUT  = 41U,         /**< IOMUXC select input index */
    kIOMUXC_SPDIF_TX_CLK2_SELECT_INPUT = 42U,      /**< IOMUXC select input index */
    kIOMUXC_USB_OTG_OC_SELECT_INPUT = 43U,         /**< IOMUXC select input index */
    kIOMUXC_XEV_GLUE_RXEV_SELECT_INPUT = 44U,      /**< IOMUXC select input index */
} iomuxc_select_input_t;

typedef enum _xbar_input_signal
{
    kXBARA1_InputRESERVED0          = 0|0x100U,    /**< XBARA_IN0 input is reserved. */
    kXBARA1_InputLogicHigh          = 1|0x100U,    /**< LOGIC_HIGH output assigned to XBARA_IN1 input. */
    kXBARA1_InputIomuxXbarInout02   = 2|0x100U,    /**< IOMUX_XBAR_INOUT02 output assigned to XBARA_IN2 input. */
    kXBARA1_InputIomuxXbarInout03   = 3|0x100U,    /**< IOMUX_XBAR_INOUT03 output assigned to XBARA_IN3 input. */
    kXBARA1_InputFlexpwm1Pwm1OutTrig01 = 4|0x100U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARA_IN4 input. */
    kXBARA1_InputFlexpwm1Pwm2OutTrig01 = 5|0x100U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARA_IN5 input. */
    kXBARA1_InputFlexpwm1Pwm3OutTrig01 = 6|0x100U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARA_IN6 input. */
    kXBARA1_InputFlexpwm1Pwm4OutTrig01 = 7|0x100U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARA_IN7 input. */
    kXBARA1_InputPitTrigger0        = 8|0x100U,    /**< PIT_TRIGGER0 output assigned to XBARA_IN8 input. */
    kXBARA1_InputPitTrigger1        = 9|0x100U,    /**< PIT_TRIGGER1 output assigned to XBARA_IN9 input. */
    kXBARA1_InputPitTrigger2        = 10|0x100U,   /**< PIT_TRIGGER2 output assigned to XBARA_IN10 input. */
    kXBARA1_InputPitTrigger3        = 11|0x100U,   /**< PIT_TRIGGER3 output assigned to XBARA_IN11 input. */
    kXBARA1_InputDmaDone0           = 12|0x100U,   /**< DMA_DONE0 output assigned to XBARA_IN12 input. */
    kXBARA1_InputDmaDone1           = 13|0x100U,   /**< DMA_DONE1 output assigned to XBARA_IN13 input. */
    kXBARA1_InputDmaDone2           = 14|0x100U,   /**< DMA_DONE2 output assigned to XBARA_IN14 input. */
    kXBARA1_InputDmaDone3           = 15|0x100U,   /**< DMA_DONE3 output assigned to XBARA_IN15 input. */
    kXBARA1_InputDmaDone4           = 16|0x100U,   /**< DMA_DONE4 output assigned to XBARA_IN16 input. */
    kXBARA1_InputDmaDone5           = 17|0x100U,   /**< DMA_DONE5 output assigned to XBARA_IN17 input. */
    kXBARA1_InputDmaDone6           = 18|0x100U,   /**< DMA_DONE6 output assigned to XBARA_IN18 input. */
    kXBARA1_InputDmaDone7           = 19|0x100U,   /**< DMA_DONE7 output assigned to XBARA_IN19 input. */
    kXBARA1_InputAoi1Out0           = 20|0x100U,   /**< AOI1_OUT0 output assigned to XBARA_IN20 input. */
    kXBARA1_InputAoi1Out1           = 21|0x100U,   /**< AOI1_OUT1 output assigned to XBARA_IN21 input. */
    kXBARA1_InputAoi1Out2           = 22|0x100U,   /**< AOI1_OUT2 output assigned to XBARA_IN22 input. */
    kXBARA1_InputAoi1Out3           = 23|0x100U,   /**< AOI1_OUT3 output assigned to XBARA_IN23 input. */
    kXBARA1_InputAdcEtc0Coco0       = 24|0x100U,   /**< ADC_ETC0_COCO0 output assigned to XBARA_IN24 input. */
    kXBARA1_InputAdcEtc0Coco1       = 25|0x100U,   /**< ADC_ETC0_COCO1 output assigned to XBARA_IN25 input. */
    kXBARA1_InputAdcEtc0Coco2       = 26|0x100U,   /**< ADC_ETC0_COCO2 output assigned to XBARA_IN26 input. */
    kXBARA1_InputAdcEtc0Coco3       = 27|0x100U,   /**< ADC_ETC0_COCO3 output assigned to XBARA_IN27 input. */
} xbar_input_signal_t;

typedef enum _xbar_output_signal
{
    kXBARA1_OutputFlexio1TriggerIn0 = 0|0x100U,    /**< XBARA_OUT0 output assigned to FLEXIO1_TRIGGER_IN0 */
    kXBARA1_OutputFlexio1TriggerIn1 = 1|0x100U,    /**< XBARA_OUT1 output assigned to FLEXIO1_TRIGGER_IN1 */
    kXBARA1_OutputIomuxXbarInout02  = 2|0x100U,    /**< XBARA_OUT2 output assigned to IOMUX_XBAR_INOUT02 */
    kXBARA1_OutputIomuxXbarInout03  = 3|0x100U,    /**< XBARA_OUT3 output assigned to IOMUX_XBAR_INOUT03 */
    kXBARA1_OutputFlexpwm1Exta0     = 4|0x100U,    /**< XBARA_OUT4 output assigned to FLEXPWM1_EXTA0 */
    kXBARA1_OutputFlexpwm1Exta1     = 5|0x100U,    /**< XBARA_OUT5 output assigned to FLEXPWM1_EXTA1 */
    kXBARA1_OutputFlexpwm1Exta2     = 6|0x100U,    /**< XBARA_OUT6 output assigned to FLEXPWM1_EXTA2 */
    kXBARA1_OutputFlexpwm1Exta3     = 7|0x100U,    /**< XBARA_OUT7 output assigned to FLEXPWM1_EXTA3 */
    kXBARA1_OutputFlexpwm1ExtSync0  = 8|0x100U,    /**< XBARA_OUT8 output assigned to FLEXPWM1_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm1ExtSync1  = 9|0x100U,    /**< XBARA_OUT9 output assigned to FLEXPWM1_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm1ExtSync2  = 10|0x100U,   /**< XBARA_OUT10 output assigned to FLEXPWM1_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm1ExtSync3  = 11|0x100U,   /**< XBARA_OUT11 output assigned to FLEXPWM1_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm1ExtClk    = 12|0x100U,   /**< XBARA_OUT12 output assigned to FLEXPWM1_EXT_CLK */
    kXBARA1_OutputFlexpwm1Fault0    = 13|0x100U,   /**< XBARA_OUT13 output assigned to FLEXPWM1_FAULT0 */
    kXBARA1_OutputFlexpwm1Fault1    = 14|0x100U,   /**< XBARA_OUT14 output assigned to FLEXPWM1_FAULT1 */
    kXBARA1_OutputFlexpwm1Fault2    = 15|0x100U,   /**< XBARA_OUT15 output assigned to FLEXPWM1_FAULT2 */
    kXBARA1_OutputFlexpwm1Fault3    = 16|0x100U,   /**< XBARA_OUT16 output assigned to FLEXPWM1_FAULT3 */
    kXBARA1_OutputFlexpwm1ExtForce  = 17|0x100U,   /**< XBARA_OUT17 output assigned to FLEXPWM1_EXT_FORCE */
    kXBARA1_OutputEwmEwmIn          = 18|0x100U,   /**< XBARA_OUT18 output assigned to EWM_EWM_IN */
    kXBARA1_OutputAdcEtcTrig00      = 19|0x100U,   /**< XBARA_OUT19 output assigned to ADC_ETC_TRIG00 */
    kXBARA1_OutputAdcEtcTrig01      = 20|0x100U,   /**< XBARA_OUT20 output assigned to ADC_ETC_TRIG01 */
    kXBARA1_OutputAdcEtcTrig02      = 21|0x100U,   /**< XBARA_OUT21 output assigned to ADC_ETC_TRIG02 */
    kXBARA1_OutputAdcEtcTrig03      = 22|0x100U,   /**< XBARA_OUT22 output assigned to ADC_ETC_TRIG03 */
    kXBARA1_OutputLpi2c1TrgInput    = 23|0x100U,   /**< XBARA_OUT23 output assigned to LPI2C1_TRG_INPUT */
    kXBARA1_OutputLpi2c2TrgInput    = 24|0x100U,   /**< XBARA_OUT24 output assigned to LPI2C2_TRG_INPUT */
    kXBARA1_OutputLpspi1TrgInput    = 25|0x100U,   /**< XBARA_OUT25 output assigned to LPSPI1_TRG_INPUT */
    kXBARA1_OutputLpspi2TrgInput    = 26|0x100U,   /**< XBARA_OUT26 output assigned to LPSPI2_TRG_INPUT */
    kXBARA1_OutputLpuart1TrgInput   = 27|0x100U,   /**< XBARA_OUT27 output assigned to LPUART1_TRG_INPUT */
    kXBARA1_OutputLpuart2TrgInput   = 28|0x100U,   /**< XBARA_OUT28 output assigned to LPUART2_TRG_INPUT */
    kXBARA1_OutputLpuart3TrgInput   = 29|0x100U,   /**< XBARA_OUT29 output assigned to LPUART3_TRG_INPUT */
    kXBARA1_OutputLpuart4TrgInput   = 30|0x100U,   /**< XBARA_OUT30 output assigned to LPUART4_TRG_INPUT */
} xbar_output_signal_t;

/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    kDmaRequestMuxFlexIO1Request0Request1 = 0|0x100U, /**< FlexIO1 Request0 and Request1 */
    kDmaRequestMuxFlexIO1Request4Request5 = 1|0x100U, /**< FlexIO1 Request4 and Request5 */
    kDmaRequestMuxLPUART1Tx         = 2|0x100U,    /**< LPUART1 Transmit */
    kDmaRequestMuxLPUART1Rx         = 3|0x100U,    /**< LPUART1 Receive */
    kDmaRequestMuxLPUART3Tx         = 4|0x100U,    /**< LPUART3 Transmit */
    kDmaRequestMuxLPUART3Rx         = 5|0x100U,    /**< LPUART3 Receive */
    kDmaRequestMuxLPSPI1Rx          = 13|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMuxLPSPI1Tx          = 14|0x100U,   /**< LPSPI1 Transmit */
    kDmaRequestMuxLPI2C1            = 17|0x100U,   /**< LPI2C1 */
    kDmaRequestMuxSai1Rx            = 19|0x100U,   /**< SAI1 Receive */
    kDmaRequestMuxSai1Tx            = 20|0x100U,   /**< SAI1 Transmit */
    kDmaRequestMuxADC_ETC           = 23|0x100U,   /**< ADC_ETC */
    kDmaRequestMuxADC1              = 24|0x100U,   /**< ADC1 */
    kDmaRequestMuxFlexSPIRx         = 28|0x100U,   /**< FLEXSPI Receive */
    kDmaRequestMuxFlexSPITx         = 29|0x100U,   /**< FLEXSPI Transmit */
    kDmaRequestMuxXBAR1Request0     = 30|0x100U,   /**< XBAR Request 0 */
    kDmaRequestMuxXBAR1Request1     = 31|0x100U,   /**< XBAR Request 1 */
    kDmaRequestMuxFlexPWM1CaptureSub0 = 32|0x100U, /**< FlexPWM1 Capture sub-module0 */
    kDmaRequestMuxFlexPWM1CaptureSub1 = 33|0x100U, /**< FlexPWM1 Capture sub-module1 */
    kDmaRequestMuxFlexPWM1CaptureSub2 = 34|0x100U, /**< FlexPWM1 Capture sub-module2 */
    kDmaRequestMuxFlexPWM1CaptureSub3 = 35|0x100U, /**< FlexPWM1 Capture sub-module3 */
    kDmaRequestMuxFlexPWM1ValueSub0 = 36|0x100U,   /**< FlexPWM1 Value sub-module0 */
    kDmaRequestMuxFlexPWM1ValueSub1 = 37|0x100U,   /**< FlexPWM1 Value sub-module1 */
    kDmaRequestMuxFlexPWM1ValueSub2 = 38|0x100U,   /**< FlexPWM1 Value sub-module2 */
    kDmaRequestMuxFlexPWM1ValueSub3 = 39|0x100U,   /**< FlexPWM1 Value sub-module3 */
    kDmaRequestMuxFlexIO1Request2Request3 = 64|0x100U, /**< FlexIO1 Request2 and Request3 */
    kDmaRequestMuxFlexIO1Request6Request7 = 65|0x100U, /**< FlexIO1 Request6 and Request7 */
    kDmaRequestMuxLPUART2Tx         = 66|0x100U,   /**< LPUART2 Transmit */
    kDmaRequestMuxLPUART2Rx         = 67|0x100U,   /**< LPUART2 Receive */
    kDmaRequestMuxLPUART4Tx         = 68|0x100U,   /**< LPUART4 Transmit */
    kDmaRequestMuxLPUART4Rx         = 69|0x100U,   /**< LPUART4 Receive */
    kDmaRequestMuxLPSPI2Rx          = 77|0x100U,   /**< LPSPI2 Receive */
    kDmaRequestMuxLPSPI2Tx          = 78|0x100U,   /**< LPSPI2 Transmit */
    kDmaRequestMuxLPI2C2            = 81|0x100U,   /**< LPI2C2 */
    kDmaRequestMuxSai3Rx            = 83|0x100U,   /**< SAI3 Receive */
    kDmaRequestMuxSai3Tx            = 84|0x100U,   /**< SAI3 Transmit */
    kDmaRequestMuxSpdifRx           = 85|0x100U,   /**< SPDIF Receive */
    kDmaRequestMuxSpdifTx           = 86|0x100U,   /**< SPDIF Transmit */
    kDmaRequestMuxXBAR1Request2     = 94|0x100U,   /**< XBAR Request 2 */
    kDmaRequestMuxXBAR1Request3     = 95|0x100U,   /**< XBAR Request 3 */
} dma_request_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t HC[8];                             /**< Control register for hardware triggers, array offset: 0x0, array step: 0x4 */
  __I  uint32_t HS;                                /**< Status register for HW triggers, offset: 0x20 */
  __I  uint32_t R[8];                              /**< Data result register for HW triggers, array offset: 0x24, array step: 0x4 */
  __IO uint32_t CFG;                               /**< Configuration register, offset: 0x44 */
  __IO uint32_t GC;                                /**< General control register, offset: 0x48 */
  __IO uint32_t GS;                                /**< General status register, offset: 0x4C */
  __IO uint32_t CV;                                /**< Compare value register, offset: 0x50 */
  __IO uint32_t OFS;                               /**< Offset correction value register, offset: 0x54 */
  __IO uint32_t CAL;                               /**< Calibration value register, offset: 0x58 */
} ADC_Type;


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x400C4000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { 0u, ADC1_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { NotAvail_IRQn, ADC1_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ADC_ETC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_ETC_Peripheral_Access_Layer ADC_ETC Peripheral Access Layer
 * @{
 */

/** ADC_ETC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< ADC_ETC Global Control Register, offset: 0x0 */
  __IO uint32_t DONE0_1_IRQ;                       /**< ETC DONE0 and DONE1 IRQ State Register, offset: 0x4 */
  __IO uint32_t DONE2_3_ERR_IRQ;                   /**< ETC DONE_2, DONE_3 and DONE_ERR IRQ State Register, offset: 0x8 */
  __IO uint32_t DMA_CTRL;                          /**< ETC DMA control Register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    __IO uint32_t TRIGn_CTRL;                        /**< ETC_TRIG Control Register, array offset: 0x10, array step: 0x28 */
    __IO uint32_t TRIGn_COUNTER;                     /**< ETC_TRIG Counter Register, array offset: 0x14, array step: 0x28 */
    __IO uint32_t TRIGn_CHAIN_1_0;                   /**< ETC_TRIG Chain 0/1 Register, array offset: 0x18, array step: 0x28 */
    __IO uint32_t TRIGn_CHAIN_3_2;                   /**< ETC_TRIG Chain 2/3 Register, array offset: 0x1C, array step: 0x28 */
    __IO uint32_t TRIGn_CHAIN_5_4;                   /**< ETC_TRIG Chain 4/5 Register, array offset: 0x20, array step: 0x28 */
    __IO uint32_t TRIGn_CHAIN_7_6;                   /**< ETC_TRIG Chain 6/7 Register, array offset: 0x24, array step: 0x28 */
    __I  uint32_t TRIGn_RESULT_1_0;                  /**< ETC_TRIG Result Data 1/0 Register, array offset: 0x28, array step: 0x28 */
    __I  uint32_t TRIGn_RESULT_3_2;                  /**< ETC_TRIG Result Data 3/2 Register, array offset: 0x2C, array step: 0x28 */
    __I  uint32_t TRIGn_RESULT_5_4;                  /**< ETC_TRIG Result Data 5/4 Register, array offset: 0x30, array step: 0x28 */
    __I  uint32_t TRIGn_RESULT_7_6;                  /**< ETC_TRIG Result Data 7/6 Register, array offset: 0x34, array step: 0x28 */
  } TRIG[4];
} ADC_ETC_Type;


/* ADC_ETC - Peripheral instance base addresses */
/** Peripheral ADC_ETC base address */
#define ADC_ETC_BASE                             (0x40088000u)
/** Peripheral ADC_ETC base pointer */
#define ADC_ETC                                  ((ADC_ETC_Type *)ADC_ETC_BASE)
/** Array initializer of ADC_ETC peripheral base addresses */
#define ADC_ETC_BASE_ADDRS                       { ADC_ETC_BASE }
/** Array initializer of ADC_ETC peripheral base pointers */
#define ADC_ETC_BASE_PTRS                        { ADC_ETC }
/** Interrupt vectors for the ADC_ETC peripheral type */
#define ADC_ETC_IRQS                             { { ADC_ETC_IRQ0_IRQn, ADC_ETC_IRQ1_IRQn, ADC_ETC_IRQ2_IRQn, ADC_ETC_IRQ3_IRQn } }
#define ADC_ETC_FAULT_IRQS                       { ADC_ETC_ERROR_IRQ_IRQn }

/*!
 * @}
 */ /* end of group ADC_ETC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- AIPSTZ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPSTZ_Peripheral_Access_Layer AIPSTZ Peripheral Access Layer
 * @{
 */

/** AIPSTZ - Register Layout Typedef */
typedef struct {
  __IO uint32_t MPR;                               /**< Master Priviledge Registers, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __IO uint32_t OPACR;                             /**< Off-Platform Peripheral Access Control Registers, offset: 0x40 */
  __IO uint32_t OPACR1;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x44 */
  __IO uint32_t OPACR2;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x48 */
  __IO uint32_t OPACR3;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x4C */
  __IO uint32_t OPACR4;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x50 */
} AIPSTZ_Type;


/* AIPSTZ - Peripheral instance base addresses */
/** Peripheral AIPSTZ1 base address */
#define AIPSTZ1_BASE                             (0x4007C000u)
/** Peripheral AIPSTZ1 base pointer */
#define AIPSTZ1                                  ((AIPSTZ_Type *)AIPSTZ1_BASE)
/** Peripheral AIPSTZ2 base address */
#define AIPSTZ2_BASE                             (0x4017C000u)
/** Peripheral AIPSTZ2 base pointer */
#define AIPSTZ2                                  ((AIPSTZ_Type *)AIPSTZ2_BASE)
/** Array initializer of AIPSTZ peripheral base addresses */
#define AIPSTZ_BASE_ADDRS                        { 0u, AIPSTZ1_BASE, AIPSTZ2_BASE }
/** Array initializer of AIPSTZ peripheral base pointers */
#define AIPSTZ_BASE_PTRS                         { (AIPSTZ_Type *)0u, AIPSTZ1, AIPSTZ2 }

/*!
 * @}
 */ /* end of group AIPSTZ_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- AOI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Peripheral_Access_Layer AOI Peripheral Access Layer
 * @{
 */

/** AOI - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x4 */
    __IO uint16_t BFCRT01;                           /**< Boolean Function Term 0 and 1 Configuration Register for EVENTn, array offset: 0x0, array step: 0x4 */
    __IO uint16_t BFCRT23;                           /**< Boolean Function Term 2 and 3 Configuration Register for EVENTn, array offset: 0x2, array step: 0x4 */
  } BFCRT[4];
} AOI_Type;

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI base address */
#define AOI_BASE                                 (0x40094000u)
/** Peripheral AOI base pointer */
#define AOI                                      ((AOI_Type *)AOI_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { AOI_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI }

/*!
 * @}
 */ /* end of group AOI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR;                               /**< CCM Control Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CSR;                               /**< CCM Status Register, offset: 0x8 */
  __IO uint32_t CCSR;                              /**< CCM Clock Switcher Register, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t CBCDR;                             /**< CCM Bus Clock Divider Register, offset: 0x14 */
  __IO uint32_t CBCMR;                             /**< CCM Bus Clock Multiplexer Register, offset: 0x18 */
  __IO uint32_t CSCMR1;                            /**< CCM Serial Clock Multiplexer Register 1, offset: 0x1C */
  __IO uint32_t CSCMR2;                            /**< CCM Serial Clock Multiplexer Register 2, offset: 0x20 */
  __IO uint32_t CSCDR1;                            /**< CCM Serial Clock Divider Register 1, offset: 0x24 */
  __IO uint32_t CS1CDR;                            /**< CCM Clock Divider Register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CDCDR;                             /**< CCM D1 Clock Divider Register, offset: 0x30 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CSCDR2;                            /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
       uint8_t RESERVED_4[12];
  __I  uint32_t CDHIPR;                            /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
       uint8_t RESERVED_5[8];
  __IO uint32_t CLPCR;                             /**< CCM Low Power Control Register, offset: 0x54 */
  __IO uint32_t CISR;                              /**< CCM Interrupt Status Register, offset: 0x58 */
  __IO uint32_t CIMR;                              /**< CCM Interrupt Mask Register, offset: 0x5C */
  __IO uint32_t CCOSR;                             /**< CCM Clock Output Source Register, offset: 0x60 */
  __IO uint32_t CGPR;                              /**< CCM General Purpose Register, offset: 0x64 */
  __IO uint32_t CCGR0;                             /**< CCM Clock Gating Register 0, offset: 0x68 */
  __IO uint32_t CCGR1;                             /**< CCM Clock Gating Register 1, offset: 0x6C */
  __IO uint32_t CCGR2;                             /**< CCM Clock Gating Register 2, offset: 0x70 */
  __IO uint32_t CCGR3;                             /**< CCM Clock Gating Register 3, offset: 0x74 */
  __IO uint32_t CCGR4;                             /**< CCM Clock Gating Register 4, offset: 0x78 */
  __IO uint32_t CCGR5;                             /**< CCM Clock Gating Register 5, offset: 0x7C */
  __IO uint32_t CCGR6;                             /**< CCM Clock Gating Register 6, offset: 0x80 */
       uint8_t RESERVED_6[4];
  __IO uint32_t CMEOR;                             /**< CCM Module Enable Overide Register, offset: 0x88 */
} CCM_Type;


/* CCM - Peripheral instance base addresses */
/** Peripheral CCM base address */
#define CCM_BASE                                 (0x400FC000u)
/** Peripheral CCM base pointer */
#define CCM                                      ((CCM_Type *)CCM_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM }
/** Interrupt vectors for the CCM peripheral type */
#define CCM_IRQS                                 { CCM_1_IRQn, CCM_2_IRQn }

/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CCM_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Peripheral_Access_Layer CCM_ANALOG Peripheral Access Layer
 * @{
 */

/** CCM_ANALOG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PLL_USB1;                          /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
  __IO uint32_t PLL_USB1_SET;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
  __IO uint32_t PLL_USB1_CLR;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
  __IO uint32_t PLL_USB1_TOG;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
       uint8_t RESERVED_1[16];
  __IO uint32_t PLL_SYS;                           /**< Analog System PLL Control Register, offset: 0x30 */
  __IO uint32_t PLL_SYS_SET;                       /**< Analog System PLL Control Register, offset: 0x34 */
  __IO uint32_t PLL_SYS_CLR;                       /**< Analog System PLL Control Register, offset: 0x38 */
  __IO uint32_t PLL_SYS_TOG;                       /**< Analog System PLL Control Register, offset: 0x3C */
  __IO uint32_t PLL_SYS_SS;                        /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
       uint8_t RESERVED_2[12];
  __IO uint32_t PLL_SYS_NUM;                       /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
       uint8_t RESERVED_3[12];
  __IO uint32_t PLL_SYS_DENOM;                     /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
       uint8_t RESERVED_4[12];
  __IO uint32_t PLL_AUDIO;                         /**< Analog Audio PLL control Register, offset: 0x70 */
  __IO uint32_t PLL_AUDIO_SET;                     /**< Analog Audio PLL control Register, offset: 0x74 */
  __IO uint32_t PLL_AUDIO_CLR;                     /**< Analog Audio PLL control Register, offset: 0x78 */
  __IO uint32_t PLL_AUDIO_TOG;                     /**< Analog Audio PLL control Register, offset: 0x7C */
  __IO uint32_t PLL_AUDIO_NUM;                     /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PLL_AUDIO_DENOM;                   /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
       uint8_t RESERVED_6[76];
  __IO uint32_t PLL_ENET;                          /**< Analog ENET PLL Control Register, offset: 0xE0 */
  __IO uint32_t PLL_ENET_SET;                      /**< Analog ENET PLL Control Register, offset: 0xE4 */
  __IO uint32_t PLL_ENET_CLR;                      /**< Analog ENET PLL Control Register, offset: 0xE8 */
  __IO uint32_t PLL_ENET_TOG;                      /**< Analog ENET PLL Control Register, offset: 0xEC */
  __IO uint32_t PFD_480;                           /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
  __IO uint32_t PFD_480_SET;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
  __IO uint32_t PFD_480_CLR;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
  __IO uint32_t PFD_480_TOG;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
  __IO uint32_t PFD_528;                           /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
  __IO uint32_t PFD_528_SET;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
  __IO uint32_t PFD_528_CLR;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
  __IO uint32_t PFD_528_TOG;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
       uint8_t RESERVED_7[64];
  __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  __IO uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  __IO uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  __IO uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  __IO uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  __IO uint32_t MISC2;                             /**< Miscellaneous Register 2, offset: 0x170 */
  __IO uint32_t MISC2_SET;                         /**< Miscellaneous Register 2, offset: 0x174 */
  __IO uint32_t MISC2_CLR;                         /**< Miscellaneous Register 2, offset: 0x178 */
  __IO uint32_t MISC2_TOG;                         /**< Miscellaneous Register 2, offset: 0x17C */
} CCM_ANALOG_Type;


/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE                          (0x400D8000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG                               ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
/** Array initializer of CCM_ANALOG peripheral base addresses */
#define CCM_ANALOG_BASE_ADDRS                    { CCM_ANALOG_BASE }
/** Array initializer of CCM_ANALOG peripheral base pointers */
#define CCM_ANALOG_BASE_PTRS                     { CCM_ANALOG }

/*!
 * @}
 */ /* end of group CCM_ANALOG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CM7_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CM7_MCM_Peripheral_Access_Layer CM7_MCM Peripheral Access Layer
 * @{
 */

/** CM7_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
} CM7_MCM_Type;


/* CM7_MCM - Peripheral instance base addresses */
/** Peripheral CM7_MCM base address */
#define CM7_MCM_BASE                             (0xE0080000u)
/** Peripheral CM7_MCM base pointer */
#define CM7_MCM                                  ((CM7_MCM_Type *)CM7_MCM_BASE)
/** Array initializer of CM7_MCM peripheral base addresses */
#define CM7_MCM_BASE_ADDRS                       { CM7_MCM_BASE }
/** Array initializer of CM7_MCM peripheral base pointers */
#define CM7_MCM_BASE_PTRS                        { CM7_MCM }

/*!
 * @}
 */ /* end of group CM7_MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CSU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSU_Peripheral_Access_Layer CSU Peripheral Access Layer
 * @{
 */

/** CSU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSL[32];                           /**< Config security level register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[384];
  __IO uint32_t HP0;                               /**< HP0 register, offset: 0x200 */
       uint8_t RESERVED_1[20];
  __IO uint32_t SA;                                /**< Secure access register, offset: 0x218 */
       uint8_t RESERVED_2[316];
  __IO uint32_t HPCONTROL0;                        /**< HPCONTROL0 register, offset: 0x358 */
} CSU_Type;


/* CSU - Peripheral instance base addresses */
/** Peripheral CSU base address */
#define CSU_BASE                                 (0x400DC000u)
/** Peripheral CSU base pointer */
#define CSU                                      ((CSU_Type *)CSU_BASE)
/** Array initializer of CSU peripheral base addresses */
#define CSU_BASE_ADDRS                           { CSU_BASE }
/** Array initializer of CSU peripheral base pointers */
#define CSU_BASE_PTRS                            { CSU }

/*!
 * @}
 */ /* end of group CSU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DCDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCDC_Peripheral_Access_Layer DCDC Peripheral Access Layer
 * @{
 */

/** DCDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG0;                              /**< DCDC Register 0, offset: 0x0 */
  __IO uint32_t REG1;                              /**< DCDC Register 1, offset: 0x4 */
  __IO uint32_t REG2;                              /**< DCDC Register 2, offset: 0x8 */
  __IO uint32_t REG3;                              /**< DCDC Register 3, offset: 0xC */
} DCDC_Type;


/* DCDC - Peripheral instance base addresses */
/** Peripheral DCDC base address */
#define DCDC_BASE                                (0x40080000u)
/** Peripheral DCDC base pointer */
#define DCDC                                     ((DCDC_Type *)DCDC_BASE)
/** Array initializer of DCDC peripheral base addresses */
#define DCDC_BASE_ADDRS                          { DCDC_BASE }
/** Array initializer of DCDC peripheral base pointers */
#define DCDC_BASE_PTRS                           { DCDC }
/** Interrupt vectors for the DCDC peripheral type */
#define DCDC_IRQS                                { DCDC_IRQn }

/*!
 * @}
 */ /* end of group DCDC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCP_Peripheral_Access_Layer DCP Peripheral Access Layer
 * @{
 */

/** DCP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< DCP control register 0, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< DCP control register 0, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< DCP control register 0, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< DCP control register 0, offset: 0xC */
  __IO uint32_t STAT;                              /**< DCP status register, offset: 0x10 */
  __IO uint32_t STAT_SET;                          /**< DCP status register, offset: 0x14 */
  __IO uint32_t STAT_CLR;                          /**< DCP status register, offset: 0x18 */
  __IO uint32_t STAT_TOG;                          /**< DCP status register, offset: 0x1C */
  __IO uint32_t CHANNELCTRL;                       /**< DCP channel control register, offset: 0x20 */
  __IO uint32_t CHANNELCTRL_SET;                   /**< DCP channel control register, offset: 0x24 */
  __IO uint32_t CHANNELCTRL_CLR;                   /**< DCP channel control register, offset: 0x28 */
  __IO uint32_t CHANNELCTRL_TOG;                   /**< DCP channel control register, offset: 0x2C */
  __IO uint32_t CAPABILITY0;                       /**< DCP capability 0 register, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __I  uint32_t CAPABILITY1;                       /**< DCP capability 1 register, offset: 0x40 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CONTEXT;                           /**< DCP context buffer pointer, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t KEY;                               /**< DCP key index, offset: 0x60 */
       uint8_t RESERVED_3[12];
  __IO uint32_t KEYDATA;                           /**< DCP key data, offset: 0x70 */
       uint8_t RESERVED_4[12];
  __I  uint32_t PACKET0;                           /**< DCP work packet 0 status register, offset: 0x80 */
       uint8_t RESERVED_5[12];
  __I  uint32_t PACKET1;                           /**< DCP work packet 1 status register, offset: 0x90 */
       uint8_t RESERVED_6[12];
  __I  uint32_t PACKET2;                           /**< DCP work packet 2 status register, offset: 0xA0 */
       uint8_t RESERVED_7[12];
  __I  uint32_t PACKET3;                           /**< DCP work packet 3 status register, offset: 0xB0 */
       uint8_t RESERVED_8[12];
  __I  uint32_t PACKET4;                           /**< DCP work packet 4 status register, offset: 0xC0 */
       uint8_t RESERVED_9[12];
  __I  uint32_t PACKET5;                           /**< DCP work packet 5 status register, offset: 0xD0 */
       uint8_t RESERVED_10[12];
  __I  uint32_t PACKET6;                           /**< DCP work packet 6 status register, offset: 0xE0 */
       uint8_t RESERVED_11[28];
  __IO uint32_t CH0CMDPTR;                         /**< DCP channel 0 command pointer address register, offset: 0x100 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CH0SEMA;                           /**< DCP channel 0 semaphore register, offset: 0x110 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CH0STAT;                           /**< DCP channel 0 status register, offset: 0x120 */
  __IO uint32_t CH0STAT_SET;                       /**< DCP channel 0 status register, offset: 0x124 */
  __IO uint32_t CH0STAT_CLR;                       /**< DCP channel 0 status register, offset: 0x128 */
  __IO uint32_t CH0STAT_TOG;                       /**< DCP channel 0 status register, offset: 0x12C */
  __IO uint32_t CH0OPTS;                           /**< DCP channel 0 options register, offset: 0x130 */
  __IO uint32_t CH0OPTS_SET;                       /**< DCP channel 0 options register, offset: 0x134 */
  __IO uint32_t CH0OPTS_CLR;                       /**< DCP channel 0 options register, offset: 0x138 */
  __IO uint32_t CH0OPTS_TOG;                       /**< DCP channel 0 options register, offset: 0x13C */
  __IO uint32_t CH1CMDPTR;                         /**< DCP channel 1 command pointer address register, offset: 0x140 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CH1SEMA;                           /**< DCP channel 1 semaphore register, offset: 0x150 */
       uint8_t RESERVED_15[12];
  __IO uint32_t CH1STAT;                           /**< DCP channel 1 status register, offset: 0x160 */
  __IO uint32_t CH1STAT_SET;                       /**< DCP channel 1 status register, offset: 0x164 */
  __IO uint32_t CH1STAT_CLR;                       /**< DCP channel 1 status register, offset: 0x168 */
  __IO uint32_t CH1STAT_TOG;                       /**< DCP channel 1 status register, offset: 0x16C */
  __IO uint32_t CH1OPTS;                           /**< DCP channel 1 options register, offset: 0x170 */
  __IO uint32_t CH1OPTS_SET;                       /**< DCP channel 1 options register, offset: 0x174 */
  __IO uint32_t CH1OPTS_CLR;                       /**< DCP channel 1 options register, offset: 0x178 */
  __IO uint32_t CH1OPTS_TOG;                       /**< DCP channel 1 options register, offset: 0x17C */
  __IO uint32_t CH2CMDPTR;                         /**< DCP channel 2 command pointer address register, offset: 0x180 */
       uint8_t RESERVED_16[12];
  __IO uint32_t CH2SEMA;                           /**< DCP channel 2 semaphore register, offset: 0x190 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CH2STAT;                           /**< DCP channel 2 status register, offset: 0x1A0 */
  __IO uint32_t CH2STAT_SET;                       /**< DCP channel 2 status register, offset: 0x1A4 */
  __IO uint32_t CH2STAT_CLR;                       /**< DCP channel 2 status register, offset: 0x1A8 */
  __IO uint32_t CH2STAT_TOG;                       /**< DCP channel 2 status register, offset: 0x1AC */
  __IO uint32_t CH2OPTS;                           /**< DCP channel 2 options register, offset: 0x1B0 */
  __IO uint32_t CH2OPTS_SET;                       /**< DCP channel 2 options register, offset: 0x1B4 */
  __IO uint32_t CH2OPTS_CLR;                       /**< DCP channel 2 options register, offset: 0x1B8 */
  __IO uint32_t CH2OPTS_TOG;                       /**< DCP channel 2 options register, offset: 0x1BC */
  __IO uint32_t CH3CMDPTR;                         /**< DCP channel 3 command pointer address register, offset: 0x1C0 */
       uint8_t RESERVED_18[12];
  __IO uint32_t CH3SEMA;                           /**< DCP channel 3 semaphore register, offset: 0x1D0 */
       uint8_t RESERVED_19[12];
  __IO uint32_t CH3STAT;                           /**< DCP channel 3 status register, offset: 0x1E0 */
  __IO uint32_t CH3STAT_SET;                       /**< DCP channel 3 status register, offset: 0x1E4 */
  __IO uint32_t CH3STAT_CLR;                       /**< DCP channel 3 status register, offset: 0x1E8 */
  __IO uint32_t CH3STAT_TOG;                       /**< DCP channel 3 status register, offset: 0x1EC */
  __IO uint32_t CH3OPTS;                           /**< DCP channel 3 options register, offset: 0x1F0 */
  __IO uint32_t CH3OPTS_SET;                       /**< DCP channel 3 options register, offset: 0x1F4 */
  __IO uint32_t CH3OPTS_CLR;                       /**< DCP channel 3 options register, offset: 0x1F8 */
  __IO uint32_t CH3OPTS_TOG;                       /**< DCP channel 3 options register, offset: 0x1FC */
       uint8_t RESERVED_20[512];
  __IO uint32_t DBGSELECT;                         /**< DCP debug select register, offset: 0x400 */
       uint8_t RESERVED_21[12];
  __I  uint32_t DBGDATA;                           /**< DCP debug data register, offset: 0x410 */
       uint8_t RESERVED_22[12];
  __IO uint32_t PAGETABLE;                         /**< DCP page table register, offset: 0x420 */
       uint8_t RESERVED_23[12];
  __I  uint32_t VERSION;                           /**< DCP version register, offset: 0x430 */
} DCP_Type;


/* DCP - Peripheral instance base addresses */
/** Peripheral DCP base address */
#define DCP_BASE                                 (0x400F0000u)
/** Peripheral DCP base pointer */
#define DCP                                      ((DCP_Type *)DCP_BASE)
/** Array initializer of DCP peripheral base addresses */
#define DCP_BASE_ADDRS                           { DCP_BASE }
/** Array initializer of DCP peripheral base pointers */
#define DCP_BASE_PTRS                            { DCP }
/** Interrupt vectors for the DCP peripheral type */
#define DCP_IRQS                                 { DCP_IRQn }
#define DCP_VMI_IRQS                             { DCP_VMI_IRQn }

/*!
 * @}
 */ /* end of group DCP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __I  uint32_t ES;                                /**< Error Status, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ERQ;                               /**< Enable Request, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t EEI;                               /**< Enable Error Interrupt, offset: 0x14 */
  __O  uint8_t CEEI;                               /**< Clear Enable Error Interrupt, offset: 0x18 */
  __O  uint8_t SEEI;                               /**< Set Enable Error Interrupt, offset: 0x19 */
  __O  uint8_t CERQ;                               /**< Clear Enable Request, offset: 0x1A */
  __O  uint8_t SERQ;                               /**< Set Enable Request, offset: 0x1B */
  __O  uint8_t CDNE;                               /**< Clear DONE Status Bit, offset: 0x1C */
  __O  uint8_t SSRT;                               /**< Set START Bit, offset: 0x1D */
  __O  uint8_t CERR;                               /**< Clear Error, offset: 0x1E */
  __O  uint8_t CINT;                               /**< Clear Interrupt Request, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint32_t INT;                               /**< Interrupt Request, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t ERR;                               /**< Error, offset: 0x2C */
       uint8_t RESERVED_4[4];
  __I  uint32_t HRS;                               /**< Hardware Request Status, offset: 0x34 */
       uint8_t RESERVED_5[12];
  __IO uint32_t EARS;                              /**< Enable Asynchronous Request in Stop, offset: 0x44 */
       uint8_t RESERVED_6[184];
  __IO uint8_t DCHPRI3;                            /**< Channel Priority, offset: 0x100 */
  __IO uint8_t DCHPRI2;                            /**< Channel Priority, offset: 0x101 */
  __IO uint8_t DCHPRI1;                            /**< Channel Priority, offset: 0x102 */
  __IO uint8_t DCHPRI0;                            /**< Channel Priority, offset: 0x103 */
  __IO uint8_t DCHPRI7;                            /**< Channel Priority, offset: 0x104 */
  __IO uint8_t DCHPRI6;                            /**< Channel Priority, offset: 0x105 */
  __IO uint8_t DCHPRI5;                            /**< Channel Priority, offset: 0x106 */
  __IO uint8_t DCHPRI4;                            /**< Channel Priority, offset: 0x107 */
  __IO uint8_t DCHPRI11;                           /**< Channel Priority, offset: 0x108 */
  __IO uint8_t DCHPRI10;                           /**< Channel Priority, offset: 0x109 */
  __IO uint8_t DCHPRI9;                            /**< Channel Priority, offset: 0x10A */
  __IO uint8_t DCHPRI8;                            /**< Channel Priority, offset: 0x10B */
  __IO uint8_t DCHPRI15;                           /**< Channel Priority, offset: 0x10C */
  __IO uint8_t DCHPRI14;                           /**< Channel Priority, offset: 0x10D */
  __IO uint8_t DCHPRI13;                           /**< Channel Priority, offset: 0x10E */
  __IO uint8_t DCHPRI12;                           /**< Channel Priority, offset: 0x10F */
       uint8_t RESERVED_7[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLNO;                       /**< TCD Minor Byte Count (Minor Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    __IO int32_t SLAST;                              /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    __IO int32_t DLAST_SGA;                          /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} DMA_Type;



/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base address */
#define DMAMUX_BASE                              (0x400EC000u)
/** Peripheral DMAMUX base pointer */
#define DMAMUX                                   ((DMAMUX_Type *)DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX }

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
  __IO uint8_t CLKCTRL;                            /**< Clock Control Register, offset: 0x4 */
  __IO uint8_t CLKPRESCALER;                       /**< Clock Prescaler Register, offset: 0x5 */
} EWM_Type;


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x400B4000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLEXIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Peripheral_Access_Layer FLEXIO Peripheral Access Layer
 * @{
 */

/** FLEXIO - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< FlexIO Control Register, offset: 0x8 */
  __I  uint32_t PIN;                               /**< Pin State Register, offset: 0xC */
  __IO uint32_t SHIFTSTAT;                         /**< Shifter Status Register, offset: 0x10 */
  __IO uint32_t SHIFTERR;                          /**< Shifter Error Register, offset: 0x14 */
  __IO uint32_t TIMSTAT;                           /**< Timer Status Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SHIFTSIEN;                         /**< Shifter Status Interrupt Enable, offset: 0x20 */
  __IO uint32_t SHIFTEIEN;                         /**< Shifter Error Interrupt Enable, offset: 0x24 */
  __IO uint32_t TIMIEN;                            /**< Timer Interrupt Enable Register, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SHIFTSDEN;                         /**< Shifter Status DMA Enable, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SHIFTSTATE;                        /**< Shifter State Register, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t SHIFTCTL[8];                       /**< Shifter Control N Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_4[96];
  __IO uint32_t SHIFTCFG[8];                       /**< Shifter Configuration N Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_5[224];
  __IO uint32_t SHIFTBUF[8];                       /**< Shifter Buffer N Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[96];
  __IO uint32_t SHIFTBUFBIS[8];                    /**< Shifter Buffer N Bit Swapped Register, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_7[96];
  __IO uint32_t SHIFTBUFBYS[8];                    /**< Shifter Buffer N Byte Swapped Register, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_8[96];
  __IO uint32_t SHIFTBUFBBS[8];                    /**< Shifter Buffer N Bit Byte Swapped Register, array offset: 0x380, array step: 0x4 */
       uint8_t RESERVED_9[96];
  __IO uint32_t TIMCTL[8];                         /**< Timer Control N Register, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_10[96];
  __IO uint32_t TIMCFG[8];                         /**< Timer Configuration N Register, array offset: 0x480, array step: 0x4 */
       uint8_t RESERVED_11[96];
  __IO uint32_t TIMCMP[8];                         /**< Timer Compare N Register, array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_12[352];
  __IO uint32_t SHIFTBUFNBS[8];                    /**< Shifter Buffer N Nibble Byte Swapped Register, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_13[96];
  __IO uint32_t SHIFTBUFHWS[8];                    /**< Shifter Buffer N Half Word Swapped Register, array offset: 0x700, array step: 0x4 */
       uint8_t RESERVED_14[96];
  __IO uint32_t SHIFTBUFNIS[8];                    /**< Shifter Buffer N Nibble Swapped Register, array offset: 0x780, array step: 0x4 */
} FLEXIO_Type;


/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x401AC000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn }

/*!
 * @}
 */ /* end of group FLEXIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLEXRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXRAM_Peripheral_Access_Layer FLEXRAM Peripheral Access Layer
 * @{
 */

/** FLEXRAM - Register Layout Typedef */
typedef struct {
  __IO uint32_t TCM_CTRL;                          /**< TCM CRTL Register, offset: 0x0 */
  __IO uint32_t OCRAM_MAGIC_ADDR;                  /**< OCRAM Magic Address Register, offset: 0x4 */
  __IO uint32_t DTCM_MAGIC_ADDR;                   /**< DTCM Magic Address Register, offset: 0x8 */
  __IO uint32_t ITCM_MAGIC_ADDR;                   /**< ITCM Magic Address Register, offset: 0xC */
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0x10 */
  __IO uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable Register, offset: 0x14 */
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Enable Register, offset: 0x18 */
} FLEXRAM_Type;


/* FLEXRAM - Peripheral instance base addresses */
/** Peripheral FLEXRAM base address */
#define FLEXRAM_BASE                             (0x400B0000u)
/** Peripheral FLEXRAM base pointer */
#define FLEXRAM                                  ((FLEXRAM_Type *)FLEXRAM_BASE)
/** Array initializer of FLEXRAM peripheral base addresses */
#define FLEXRAM_BASE_ADDRS                       { FLEXRAM_BASE }
/** Array initializer of FLEXRAM peripheral base pointers */
#define FLEXRAM_BASE_PTRS                        { FLEXRAM }
/** Interrupt vectors for the FLEXRAM peripheral type */
#define FLEXRAM_IRQS                             { FLEXRAM_IRQn }

/*!
 * @}
 */ /* end of group FLEXRAM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLEXSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_Peripheral_Access_Layer FLEXSPI Peripheral Access Layer
 * @{
 */

/** FLEXSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR0;                              /**< Module Control Register 0, offset: 0x0 */
  __IO uint32_t MCR1;                              /**< Module Control Register 1, offset: 0x4 */
  __IO uint32_t MCR2;                              /**< Module Control Register 2, offset: 0x8 */
  __IO uint32_t AHBCR;                             /**< AHB Bus Control Register, offset: 0xC */
  __IO uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t INTR;                              /**< Interrupt Register, offset: 0x14 */
  __IO uint32_t LUTKEY;                            /**< LUT Key Register, offset: 0x18 */
  __IO uint32_t LUTCR;                             /**< LUT Control Register, offset: 0x1C */
  __IO uint32_t AHBRXBUFCR0[4];                    /**< AHB RX Buffer 0 Control Register 0..AHB RX Buffer 3 Control Register 0, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[48];
  __IO uint32_t FLSHCR0[4];                        /**< Flash Control Register 0, array offset: 0x60, array step: 0x4 */
  __IO uint32_t FLSHCR1[4];                        /**< Flash Control Register 1, array offset: 0x70, array step: 0x4 */
  __IO uint32_t FLSHCR2[4];                        /**< Flash Control Register 2, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FLSHCR4;                           /**< Flash Control Register 4, offset: 0x94 */
       uint8_t RESERVED_2[8];
  __IO uint32_t IPCR0;                             /**< IP Control Register 0, offset: 0xA0 */
  __IO uint32_t IPCR1;                             /**< IP Control Register 1, offset: 0xA4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t IPCMD;                             /**< IP Command Register, offset: 0xB0 */
       uint8_t RESERVED_4[4];
  __IO uint32_t IPRXFCR;                           /**< IP RX FIFO Control Register, offset: 0xB8 */
  __IO uint32_t IPTXFCR;                           /**< IP TX FIFO Control Register, offset: 0xBC */
  __IO uint32_t DLLCR[2];                          /**< DLL Control Register 0, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_5[24];
  __I  uint32_t STS0;                              /**< Status Register 0, offset: 0xE0 */
  __I  uint32_t STS1;                              /**< Status Register 1, offset: 0xE4 */
  __I  uint32_t STS2;                              /**< Status Register 2, offset: 0xE8 */
  __I  uint32_t AHBSPNDSTS;                        /**< AHB Suspend Status Register, offset: 0xEC */
  __I  uint32_t IPRXFSTS;                          /**< IP RX FIFO Status Register, offset: 0xF0 */
  __I  uint32_t IPTXFSTS;                          /**< IP TX FIFO Status Register, offset: 0xF4 */
       uint8_t RESERVED_6[8];
  __I  uint32_t RFDR[32];                          /**< IP RX FIFO Data Register 0..IP RX FIFO Data Register 31, array offset: 0x100, array step: 0x4 */
  __O  uint32_t TFDR[32];                          /**< IP TX FIFO Data Register 0..IP TX FIFO Data Register 31, array offset: 0x180, array step: 0x4 */
  __IO uint32_t LUT[64];                           /**< LUT 0..LUT 63, array offset: 0x200, array step: 0x4 */
} FLEXSPI_Type;


/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI base address */
#define FLEXSPI_BASE                             (0x400A0000u)
/** Peripheral FLEXSPI base pointer */
#define FLEXSPI                                  ((FLEXSPI_Type *)FLEXSPI_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { FLEXSPI_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { FLEXSPI }
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FLEXSPI_IRQn }
/* FlexSPI AMBA address. */
#define FlexSPI_AMBA_BASE                       (0x60000000U)
/* FlexSPI ASFM address. */
#define FlexSPI_ASFM_BASE                        (0x60000000U)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI_ARDF_BASE                        (0x7FC00000U)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI_ATDF_BASE                        (0x7F800000U)


/*!
 * @}
 */ /* end of group FLEXSPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Peripheral_Access_Layer GPC Peripheral Access Layer
 * @{
 */

/** GPC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CNTR;                              /**< GPC Interface control register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IMR[4];                            /**< IRQ masking register 1..IRQ masking register 4, array offset: 0x8, array step: 0x4 */
  __I  uint32_t ISR[4];                            /**< IRQ status resister 1..IRQ status resister 4, array offset: 0x18, array step: 0x4 */
       uint8_t RESERVED_1[12];
  __IO uint32_t IMR5;                              /**< IRQ masking register 5, offset: 0x34 */
  __I  uint32_t ISR5;                              /**< IRQ status resister 5, offset: 0x38 */
} GPC_Type;


/* GPC - Peripheral instance base addresses */
/** Peripheral GPC base address */
#define GPC_BASE                                 (0x400F4000u)
/** Peripheral GPC base pointer */
#define GPC                                      ((GPC_Type *)GPC_BASE)
/** Array initializer of GPC peripheral base addresses */
#define GPC_BASE_ADDRS                           { GPC_BASE }
/** Array initializer of GPC peripheral base pointers */
#define GPC_BASE_PTRS                            { GPC }
/** Interrupt vectors for the GPC peripheral type */
#define GPC_IRQS                                 { GPC_IRQn }

/*!
 * @}
 */ /* end of group GPC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t DR;                                /**< GPIO data register, offset: 0x0 */
  __IO uint32_t GDIR;                              /**< GPIO direction register, offset: 0x4 */
  __I  uint32_t PSR;                               /**< GPIO pad status register, offset: 0x8 */
  __IO uint32_t ICR1;                              /**< GPIO interrupt configuration register1, offset: 0xC */
  __IO uint32_t ICR2;                              /**< GPIO interrupt configuration register2, offset: 0x10 */
  __IO uint32_t IMR;                               /**< GPIO interrupt mask register, offset: 0x14 */
  __IO uint32_t ISR;                               /**< GPIO interrupt status register, offset: 0x18 */
  __IO uint32_t EDGE_SEL;                          /**< GPIO edge select register, offset: 0x1C */
       uint8_t RESERVED_0[100];
  __O  uint32_t DR_SET;                            /**< GPIO data register SET, offset: 0x84 */
  __O  uint32_t DR_CLEAR;                          /**< GPIO data register CLEAR, offset: 0x88 */
  __O  uint32_t DR_TOGGLE;                         /**< GPIO data register TOGGLE, offset: 0x8C */
} GPIO_Type;


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x401B8000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x42000000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x400C0000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { 0u, GPIO1_BASE, GPIO2_BASE, 0u, 0u, GPIO5_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, GPIO1, GPIO2, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO5 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_COMBINED_LOW_IRQS                   { NotAvail_IRQn, GPIO1_Combined_0_15_IRQn, GPIO2_Combined_0_15_IRQn, NotAvail_IRQn, NotAvail_IRQn, GPIO5_Combined_0_15_IRQn }
#define GPIO_COMBINED_HIGH_IRQS                  { NotAvail_IRQn, GPIO1_Combined_16_31_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPT_Peripheral_Access_Layer GPT Peripheral Access Layer
 * @{
 */

/** GPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< GPT Control Register, offset: 0x0 */
  __IO uint32_t PR;                                /**< GPT Prescaler Register, offset: 0x4 */
  __IO uint32_t SR;                                /**< GPT Status Register, offset: 0x8 */
  __IO uint32_t IR;                                /**< GPT Interrupt Register, offset: 0xC */
  __IO uint32_t OCR[3];                            /**< GPT Output Compare Register 1..GPT Output Compare Register 3, array offset: 0x10, array step: 0x4 */
  __I  uint32_t ICR[2];                            /**< GPT Input Capture Register 1..GPT Input Capture Register 2, array offset: 0x1C, array step: 0x4 */
  __I  uint32_t CNT;                               /**< GPT Counter Register, offset: 0x24 */
} GPT_Type;


/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x401EC000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x401F0000u)
/** Peripheral GPT2 base pointer */
#define GPT2                                     ((GPT_Type *)GPT2_BASE)
/** Array initializer of GPT peripheral base addresses */
#define GPT_BASE_ADDRS                           { 0u, GPT1_BASE, GPT2_BASE }
/** Array initializer of GPT peripheral base pointers */
#define GPT_BASE_PTRS                            { (GPT_Type *)0u, GPT1, GPT2 }
/** Interrupt vectors for the GPT peripheral type */
#define GPT_IRQS                                 { NotAvail_IRQn, GPT1_IRQn, GPT2_IRQn }

/*!
 * @}
 */ /* end of group GPT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t TCSR;                              /**< Transmit Control, offset: 0x8 */
  __IO uint32_t TCR1;                              /**< Transmit Configuration 1, offset: 0xC */
  __IO uint32_t TCR2;                              /**< Transmit Configuration 2, offset: 0x10 */
  __IO uint32_t TCR3;                              /**< Transmit Configuration 3, offset: 0x14 */
  __IO uint32_t TCR4;                              /**< Transmit Configuration 4, offset: 0x18 */
  __IO uint32_t TCR5;                              /**< Transmit Configuration 5, offset: 0x1C */
  __O  uint32_t TDR[2];                            /**< Transmit Data, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __I  uint32_t TFR[2];                            /**< Transmit FIFO, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t TMR;                               /**< Transmit Mask, offset: 0x60 */
       uint8_t RESERVED_2[36];
  __IO uint32_t RCSR;                              /**< Receive Control, offset: 0x88 */
  __IO uint32_t RCR1;                              /**< Receive Configuration 1, offset: 0x8C */
  __IO uint32_t RCR2;                              /**< Receive Configuration 2, offset: 0x90 */
  __IO uint32_t RCR3;                              /**< Receive Configuration 3, offset: 0x94 */
  __IO uint32_t RCR4;                              /**< Receive Configuration 4, offset: 0x98 */
  __IO uint32_t RCR5;                              /**< Receive Configuration 5, offset: 0x9C */
  __I  uint32_t RDR[2];                            /**< Receive Data, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[24];
  __I  uint32_t RFR[2];                            /**< Receive FIFO, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __IO uint32_t RMR;                               /**< Receive Mask, offset: 0xE0 */
} I2S_Type;


/* I2S - Peripheral instance base addresses */
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x401E0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x401E8000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, 0u, SAI3_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, (I2S_Type *)0u, SAI3 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_RX_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_TX_IRQn }

/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOMUXC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Peripheral_Access_Layer IOMUXC Peripheral Access Layer
 * @{
 */

/** IOMUXC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SW_MUX_CTL_PAD[44];                /**< SW_MUX_CTL_PAD_GPIO_AD_14 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_00 SW MUX Control Register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[44];                /**< SW_PAD_CTL_PAD_GPIO_AD_14 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_00 SW PAD Control Register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[45];                  /**< USB_OTG_ID_SELECT_INPUT DAISY Register..XEV_GLUE_RXEV_SELECT_INPUT DAISY Register, array offset: 0x170, array step: 0x4 */
} IOMUXC_Type;


/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x401F8000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/*!
 * @}
 */ /* end of group IOMUXC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
  __IO uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
  __IO uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
  __IO uint32_t GPR4;                              /**< GPR4 General Purpose Register, offset: 0x10 */
  __IO uint32_t GPR5;                              /**< GPR5 General Purpose Register, offset: 0x14 */
  __IO uint32_t GPR6;                              /**< GPR6 General Purpose Register, offset: 0x18 */
  __IO uint32_t GPR7;                              /**< GPR7 General Purpose Register, offset: 0x1C */
  __IO uint32_t GPR8;                              /**< GPR8 General Purpose Register, offset: 0x20 */
       uint32_t GPR9;                              /**< GPR9 General Purpose Register, offset: 0x24 */
  __IO uint32_t GPR10;                             /**< GPR10 General Purpose Register, offset: 0x28 */
  __IO uint32_t GPR11;                             /**< GPR11 General Purpose Register, offset: 0x2C */
  __IO uint32_t GPR12;                             /**< GPR12 General Purpose Register, offset: 0x30 */
  __IO uint32_t GPR13;                             /**< GPR13 General Purpose Register, offset: 0x34 */
       uint32_t GPR14;                             /**< GPR14 General Purpose Register, offset: 0x38 */
       uint32_t GPR15;                             /**< GPR15 General Purpose Register, offset: 0x3C */
  __IO uint32_t GPR16;                             /**< GPR16 General Purpose Register, offset: 0x40 */
  __IO uint32_t GPR17;                             /**< GPR17 General Purpose Register, offset: 0x44 */
  __IO uint32_t GPR18;                             /**< GPR18 General Purpose Register, offset: 0x48 */
  __IO uint32_t GPR19;                             /**< GPR19 General Purpose Register, offset: 0x4C */
  __IO uint32_t GPR20;                             /**< GPR20 General Purpose Register, offset: 0x50 */
  __IO uint32_t GPR21;                             /**< GPR21 General Purpose Register, offset: 0x54 */
  __IO uint32_t GPR22;                             /**< GPR22 General Purpose Register, offset: 0x58 */
  __IO uint32_t GPR23;                             /**< GPR23 General Purpose Register, offset: 0x5C */
  __IO uint32_t GPR24;                             /**< GPR24 General Purpose Register, offset: 0x60 */
  __IO uint32_t GPR25;                             /**< GPR25 General Purpose Register, offset: 0x64 */
  __IO uint32_t GPR26;                             /**< GPR26 General Purpose Register, offset: 0x68 */
  __IO uint32_t GPR27;                             /**< GPR27 General Purpose Register, offset: 0x6C */
  __IO uint32_t GPR28;                             /**< GPR28 General Purpose Register, offset: 0x70 */
  __IO uint32_t GPR29;                             /**< GPR29 General Purpose Register, offset: 0x74 */
} IOMUXC_GPR_Type;


/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                          (0x400AC000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }

/*!
 * @}
 */ /* end of group IOMUXC_GPR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOMUXC_SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_Peripheral_Access_Layer IOMUXC_SNVS Peripheral Access Layer
 * @{
 */

/** IOMUXC_SNVS - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD_PMIC_ON_REQ;        /**< SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register, offset: 0x0 */
  __IO uint32_t SW_PAD_CTL_PAD_TEST_MODE;          /**< SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register, offset: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_POR_B;              /**< SW_PAD_CTL_PAD_POR_B SW PAD Control Register, offset: 0x8 */
  __IO uint32_t SW_PAD_CTL_PAD_ONOFF;              /**< SW_PAD_CTL_PAD_ONOFF SW PAD Control Register, offset: 0xC */
  __IO uint32_t SW_PAD_CTL_PAD_PMIC_ON_REQ;        /**< SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register, offset: 0x10 */
} IOMUXC_SNVS_Type;


/* IOMUXC_SNVS - Peripheral instance base addresses */
/** Peripheral IOMUXC_SNVS base address */
#define IOMUXC_SNVS_BASE                         (0x400A8000u)
/** Peripheral IOMUXC_SNVS base pointer */
#define IOMUXC_SNVS                              ((IOMUXC_SNVS_Type *)IOMUXC_SNVS_BASE)
/** Array initializer of IOMUXC_SNVS peripheral base addresses */
#define IOMUXC_SNVS_BASE_ADDRS                   { IOMUXC_SNVS_BASE }
/** Array initializer of IOMUXC_SNVS peripheral base pointers */
#define IOMUXC_SNVS_BASE_PTRS                    { IOMUXC_SNVS }

/*!
 * @}
 */ /* end of group IOMUXC_SNVS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOMUXC_SNVS_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_GPR_Peripheral_Access_Layer IOMUXC_SNVS_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_SNVS_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
       uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
       uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
} IOMUXC_SNVS_GPR_Type;


/* IOMUXC_SNVS_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_SNVS_GPR base address */
#define IOMUXC_SNVS_GPR_BASE                     (0x400A4000u)
/** Peripheral IOMUXC_SNVS_GPR base pointer */
#define IOMUXC_SNVS_GPR                          ((IOMUXC_SNVS_GPR_Type *)IOMUXC_SNVS_GPR_BASE)
/** Array initializer of IOMUXC_SNVS_GPR peripheral base addresses */
#define IOMUXC_SNVS_GPR_BASE_ADDRS               { IOMUXC_SNVS_GPR_BASE }
/** Array initializer of IOMUXC_SNVS_GPR peripheral base pointers */
#define IOMUXC_SNVS_GPR_BASE_PTRS                { IOMUXC_SNVS_GPR }

/*!
 * @}
 */ /* end of group IOMUXC_SNVS_GPR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- KPP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KPP_Peripheral_Access_Layer KPP Peripheral Access Layer
 * @{
 */

/** KPP - Register Layout Typedef */
typedef struct {
  __IO uint16_t KPCR;                              /**< Keypad Control Register, offset: 0x0 */
  __IO uint16_t KPSR;                              /**< Keypad Status Register, offset: 0x2 */
  __IO uint16_t KDDR;                              /**< Keypad Data Direction Register, offset: 0x4 */
  __IO uint16_t KPDR;                              /**< Keypad Data Register, offset: 0x6 */
} KPP_Type;


/* KPP - Peripheral instance base addresses */
/** Peripheral KPP base address */
#define KPP_BASE                                 (0x401FC000u)
/** Peripheral KPP base pointer */
#define KPP                                      ((KPP_Type *)KPP_BASE)
/** Array initializer of KPP peripheral base addresses */
#define KPP_BASE_ADDRS                           { KPP_BASE }
/** Array initializer of KPP peripheral base pointers */
#define KPP_BASE_PTRS                            { KPP }
/** Interrupt vectors for the KPP peripheral type */
#define KPP_IRQS                                 { KPP_IRQn }

/*!
 * @}
 */ /* end of group KPP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/** LPI2C - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t MCR;                               /**< Master Control, offset: 0x10 */
  __IO uint32_t MSR;                               /**< Master Status, offset: 0x14 */
  __IO uint32_t MIER;                              /**< Master Interrupt Enable, offset: 0x18 */
  __IO uint32_t MDER;                              /**< Master DMA Enable, offset: 0x1C */
  __IO uint32_t MCFGR0;                            /**< Master Configuration 0, offset: 0x20 */
  __IO uint32_t MCFGR1;                            /**< Master Configuration 1, offset: 0x24 */
  __IO uint32_t MCFGR2;                            /**< Master Configuration 2, offset: 0x28 */
  __IO uint32_t MCFGR3;                            /**< Master Configuration 3, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t MDMR;                              /**< Master Data Match, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MCCR0;                             /**< Master Clock Configuration 0, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MCCR1;                             /**< Master Clock Configuration 1, offset: 0x50 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MFCR;                              /**< Master FIFO Control, offset: 0x58 */
  __I  uint32_t MFSR;                              /**< Master FIFO Status, offset: 0x5C */
  __O  uint32_t MTDR;                              /**< Master Transmit Data, offset: 0x60 */
       uint8_t RESERVED_5[12];
  __I  uint32_t MRDR;                              /**< Master Receive Data, offset: 0x70 */
       uint8_t RESERVED_6[156];
  __IO uint32_t SCR;                               /**< Slave Control, offset: 0x110 */
  __IO uint32_t SSR;                               /**< Slave Status, offset: 0x114 */
  __IO uint32_t SIER;                              /**< Slave Interrupt Enable, offset: 0x118 */
  __IO uint32_t SDER;                              /**< Slave DMA Enable, offset: 0x11C */
       uint8_t RESERVED_7[4];
  __IO uint32_t SCFGR1;                            /**< Slave Configuration 1, offset: 0x124 */
  __IO uint32_t SCFGR2;                            /**< Slave Configuration 2, offset: 0x128 */
       uint8_t RESERVED_8[20];
  __IO uint32_t SAMR;                              /**< Slave Address Match, offset: 0x140 */
       uint8_t RESERVED_9[12];
  __I  uint32_t SASR;                              /**< Slave Address Status, offset: 0x150 */
  __IO uint32_t STAR;                              /**< Slave Transmit ACK, offset: 0x154 */
       uint8_t RESERVED_10[8];
  __O  uint32_t STDR;                              /**< Slave Transmit Data, offset: 0x160 */
       uint8_t RESERVED_11[12];
  __I  uint32_t SRDR;                              /**< Slave Receive Data, offset: 0x170 */
} LPI2C_Type;


/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x401A4000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x401A8000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn }

/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */

/** LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status, offset: 0x14 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x18 */
  __IO uint32_t DER;                               /**< DMA Enable, offset: 0x1C */
  __IO uint32_t CFGR0;                             /**< Configuration 0, offset: 0x20 */
  __IO uint32_t CFGR1;                             /**< Configuration 1, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMR0;                              /**< Data Match 0, offset: 0x30 */
  __IO uint32_t DMR1;                              /**< Data Match 1, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CCR;                               /**< Clock Configuration, offset: 0x40 */
       uint8_t RESERVED_3[20];
  __IO uint32_t FCR;                               /**< FIFO Control, offset: 0x58 */
  __I  uint32_t FSR;                               /**< FIFO Status, offset: 0x5C */
  __IO uint32_t TCR;                               /**< Transmit Command, offset: 0x60 */
  __O  uint32_t TDR;                               /**< Transmit Data, offset: 0x64 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RSR;                               /**< Receive Status, offset: 0x70 */
  __I  uint32_t RDR;                               /**< Receive Data, offset: 0x74 */
} LPSPI_Type;


/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x40194000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40198000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/** LPUART - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
  __IO uint32_t PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
  __IO uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< LPUART Status Register, offset: 0x14 */
  __IO uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x18 */
  __IO uint32_t DATA;                              /**< LPUART Data Register, offset: 0x1C */
  __IO uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
  __IO uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
  __IO uint32_t FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
  __IO uint32_t WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type;


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40184000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40188000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x4018C000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x40190000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn }

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- OCOTP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Peripheral_Access_Layer OCOTP Peripheral Access Layer
 * @{
 */

/** OCOTP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< OTP Controller Control and Status Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< OTP Controller Control and Status Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< OTP Controller Control and Status Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< OTP Controller Control and Status Register, offset: 0xC */
  __IO uint32_t TIMING;                            /**< OTP Controller Timing Register, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DATA;                              /**< OTP Controller Write Data Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t READ_CTRL;                         /**< OTP Controller Write Data Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t READ_FUSE_DATA;                    /**< OTP Controller Read Data Register, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t SW_STICKY;                         /**< Sticky bit Register, offset: 0x50 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCS;                               /**< Software Controllable Signals Register, offset: 0x60 */
  __IO uint32_t SCS_SET;                           /**< Software Controllable Signals Register, offset: 0x64 */
  __IO uint32_t SCS_CLR;                           /**< Software Controllable Signals Register, offset: 0x68 */
  __IO uint32_t SCS_TOG;                           /**< Software Controllable Signals Register, offset: 0x6C */
       uint8_t RESERVED_5[32];
  __I  uint32_t VERSION;                           /**< OTP Controller Version Register, offset: 0x90 */
       uint8_t RESERVED_6[108];
  __IO uint32_t TIMING2;                           /**< OTP Controller Timing Register 2, offset: 0x100 */
       uint8_t RESERVED_7[764];
  __IO uint32_t LOCK;                              /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
       uint8_t RESERVED_8[12];
  __IO uint32_t CFG0;                              /**< Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.), offset: 0x410 */
       uint8_t RESERVED_9[12];
  __IO uint32_t CFG1;                              /**< Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.), offset: 0x420 */
       uint8_t RESERVED_10[12];
  __IO uint32_t CFG2;                              /**< Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.), offset: 0x430 */
       uint8_t RESERVED_11[12];
  __IO uint32_t CFG3;                              /**< Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.), offset: 0x440 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CFG4;                              /**< Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.), offset: 0x450 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CFG5;                              /**< Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.), offset: 0x460 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CFG6;                              /**< Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.), offset: 0x470 */
       uint8_t RESERVED_15[12];
  __IO uint32_t MEM0;                              /**< Value of OTP Bank1 Word0 (Memory Related Info.), offset: 0x480 */
       uint8_t RESERVED_16[12];
  __IO uint32_t MEM1;                              /**< Value of OTP Bank1 Word1 (Memory Related Info.), offset: 0x490 */
       uint8_t RESERVED_17[12];
  __IO uint32_t MEM2;                              /**< Value of OTP Bank1 Word2 (Memory Related Info.), offset: 0x4A0 */
       uint8_t RESERVED_18[12];
  __IO uint32_t MEM3;                              /**< Value of OTP Bank1 Word3 (Memory Related Info.), offset: 0x4B0 */
       uint8_t RESERVED_19[12];
  __IO uint32_t MEM4;                              /**< Value of OTP Bank 1 Word 4 (Memory Related Info.), offset: 0x4C0 */
       uint8_t RESERVED_20[12];
  __IO uint32_t ANA0;                              /**< Value of OTP Bank 1 Word 5 (Analog Info.), offset: 0x4D0 */
       uint8_t RESERVED_21[12];
  __IO uint32_t ANA1;                              /**< Value of OTP Bank 1 Word 6 (Analog Info.), offset: 0x4E0 */
       uint8_t RESERVED_22[12];
  __IO uint32_t ANA2;                              /**< Value of OTP Bank 1 Word 7 (Analog Info.), offset: 0x4F0 */
       uint8_t RESERVED_23[140];
  __IO uint32_t SRK0;                              /**< Shadow Register for OTP Bank3 Word0 (SRK Hash), offset: 0x580 */
       uint8_t RESERVED_24[12];
  __IO uint32_t SRK1;                              /**< Shadow Register for OTP Bank3 Word1 (SRK Hash), offset: 0x590 */
       uint8_t RESERVED_25[12];
  __IO uint32_t SRK2;                              /**< Shadow Register for OTP Bank3 Word2 (SRK Hash), offset: 0x5A0 */
       uint8_t RESERVED_26[12];
  __IO uint32_t SRK3;                              /**< Shadow Register for OTP Bank3 Word3 (SRK Hash), offset: 0x5B0 */
       uint8_t RESERVED_27[12];
  __IO uint32_t SRK4;                              /**< Shadow Register for OTP Bank3 Word4 (SRK Hash), offset: 0x5C0 */
       uint8_t RESERVED_28[12];
  __IO uint32_t SRK5;                              /**< Shadow Register for OTP Bank3 Word5 (SRK Hash), offset: 0x5D0 */
       uint8_t RESERVED_29[12];
  __IO uint32_t SRK6;                              /**< Shadow Register for OTP Bank3 Word6 (SRK Hash), offset: 0x5E0 */
       uint8_t RESERVED_30[12];
  __IO uint32_t SRK7;                              /**< Shadow Register for OTP Bank3 Word7 (SRK Hash), offset: 0x5F0 */
       uint8_t RESERVED_31[12];
  __IO uint32_t SJC_RESP0;                         /**< Value of OTP Bank4 Word0 (Secure JTAG Response Field), offset: 0x600 */
       uint8_t RESERVED_32[12];
  __IO uint32_t SJC_RESP1;                         /**< Value of OTP Bank4 Word1 (Secure JTAG Response Field), offset: 0x610 */
       uint8_t RESERVED_33[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG0;               /**< Value of OTP Bank4 Word2 (OTFAD), offset: 0x620 */
       uint8_t RESERVED_34[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG1;               /**< Value of OTP Bank4 Word3 (OTFAD), offset: 0x630 */
       uint8_t RESERVED_35[12];
  __IO uint32_t GP3;                               /**< Value of OTP Bank4 Word4 (OTFAD), offset: 0x640 */
       uint8_t RESERVED_36[28];
  __IO uint32_t GP1;                               /**< Value of OTP Bank4 Word6 (General Purpose Customer Defined Info), offset: 0x660 */
       uint8_t RESERVED_37[12];
  __IO uint32_t GP2;                               /**< Value of OTP Bank4 Word7 (General Purpose Customer Defined Info), offset: 0x670 */
       uint8_t RESERVED_38[12];
  __IO uint32_t SW_GP1;                            /**< Value of OTP Bank5 Word0 (SW GP1), offset: 0x680 */
       uint8_t RESERVED_39[12];
  __IO uint32_t SW_GP20;                           /**< Value of OTP Bank5 Word1 (SW GP2), offset: 0x690 */
       uint8_t RESERVED_40[12];
  __IO uint32_t SW_GP21;                           /**< Value of OTP Bank5 Word2 (SW GP2), offset: 0x6A0 */
       uint8_t RESERVED_41[12];
  __IO uint32_t SW_GP22;                           /**< Value of OTP Bank5 Word3 (SW GP2), offset: 0x6B0 */
       uint8_t RESERVED_42[12];
  __IO uint32_t SW_GP23;                           /**< Value of OTP Bank5 Word4 (SW GP2), offset: 0x6C0 */
       uint8_t RESERVED_43[12];
  __IO uint32_t MISC_CONF0;                        /**< Value of OTP Bank5 Word5 (Misc Conf), offset: 0x6D0 */
       uint8_t RESERVED_44[12];
  __IO uint32_t MISC_CONF1;                        /**< Value of OTP Bank5 Word6 (Misc Conf), offset: 0x6E0 */
       uint8_t RESERVED_45[12];
  __IO uint32_t SRK_REVOKE;                        /**< Value of OTP Bank5 Word7 (SRK Revoke), offset: 0x6F0 */
} OCOTP_Type;


/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define OCOTP_BASE                               (0x401F4000u)
/** Peripheral OCOTP base pointer */
#define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP }

/*!
 * @}
 */ /* end of group OCOTP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- OTFAD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTFAD_Peripheral_Access_Layer OTFAD Peripheral Access Layer
 * @{
 */

/** OTFAD - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[3072];
  __IO uint32_t CR;                                /**< Control Register, offset: 0xC00 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0xC04 */
       uint8_t RESERVED_1[248];
  struct {                                         /* offset: 0xD00, array step: 0x40 */
    __IO uint32_t KEY[4];                            /**< AES Key Word, array offset: 0xD00, array step: index*0x40, index2*0x4 */
    __IO uint32_t CTR[2];                            /**< AES Counter Word, array offset: 0xD10, array step: index*0x40, index2*0x4 */
    __IO uint32_t RGD_W0;                            /**< AES Region Descriptor Word0, array offset: 0xD18, array step: 0x40 */
    __IO uint32_t RGD_W1;                            /**< AES Region Descriptor Word1, array offset: 0xD1C, array step: 0x40 */
         uint8_t RESERVED_0[32];
  } CTX[4];
} OTFAD_Type;


/* OTFAD - Peripheral instance base addresses */
/** Peripheral OTFAD base address */
#define OTFAD_BASE                               (0x400A0000u)
/** Peripheral OTFAD base pointer */
#define OTFAD                                    ((OTFAD_Type *)OTFAD_BASE)
/** Array initializer of OTFAD peripheral base addresses */
#define OTFAD_BASE_ADDRS                         { OTFAD_BASE }
/** Array initializer of OTFAD peripheral base pointers */
#define OTFAD_BASE_PTRS                          { OTFAD }

/*!
 * @}
 */ /* end of group OTFAD_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGC_Peripheral_Access_Layer PGC Peripheral Access Layer
 * @{
 */

/** PGC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[544];
  __IO uint32_t MEGA_CTRL;                         /**< PGC Mega Control Register, offset: 0x220 */
  __IO uint32_t MEGA_PUPSCR;                       /**< PGC Mega Power Up Sequence Control Register, offset: 0x224 */
  __IO uint32_t MEGA_PDNSCR;                       /**< PGC Mega Pull Down Sequence Control Register, offset: 0x228 */
  __IO uint32_t MEGA_SR;                           /**< PGC Mega Power Gating Controller Status Register, offset: 0x22C */
       uint8_t RESERVED_1[112];
  __IO uint32_t CPU_CTRL;                          /**< PGC CPU Control Register, offset: 0x2A0 */
  __IO uint32_t CPU_PUPSCR;                        /**< PGC CPU Power Up Sequence Control Register, offset: 0x2A4 */
  __IO uint32_t CPU_PDNSCR;                        /**< PGC CPU Pull Down Sequence Control Register, offset: 0x2A8 */
  __IO uint32_t CPU_SR;                            /**< PGC CPU Power Gating Controller Status Register, offset: 0x2AC */
} PGC_Type;


/* PGC - Peripheral instance base addresses */
/** Peripheral PGC base address */
#define PGC_BASE                                 (0x400F4000u)
/** Peripheral PGC base pointer */
#define PGC                                      ((PGC_Type *)PGC_BASE)
/** Array initializer of PGC peripheral base addresses */
#define PGC_BASE_ADDRS                           { PGC_BASE }
/** Array initializer of PGC peripheral base pointers */
#define PGC_BASE_PTRS                            { PGC }

/*!
 * @}
 */ /* end of group PGC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PIT Module Control Register, offset: 0x0 */
       uint8_t RESERVED_0[220];
  __I  uint32_t LTMR64H;                           /**< PIT Upper Lifetime Timer Register, offset: 0xE0 */
  __I  uint32_t LTMR64L;                           /**< PIT Lower Lifetime Timer Register, offset: 0xE4 */
       uint8_t RESERVED_1[24];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} PIT_Type;


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE                                 (0x40084000u)
/** Peripheral PIT base pointer */
#define PIT                                      ((PIT_Type *)PIT_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT }
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { { PIT_IRQn, PIT_IRQn, PIT_IRQn, PIT_IRQn } }

/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[272];
  __IO uint32_t REG_1P1;                           /**< Regulator 1P1 Register, offset: 0x110 */
  __IO uint32_t REG_1P1_SET;                       /**< Regulator 1P1 Register, offset: 0x114 */
  __IO uint32_t REG_1P1_CLR;                       /**< Regulator 1P1 Register, offset: 0x118 */
  __IO uint32_t REG_1P1_TOG;                       /**< Regulator 1P1 Register, offset: 0x11C */
  __IO uint32_t REG_3P0;                           /**< Regulator 3P0 Register, offset: 0x120 */
  __IO uint32_t REG_3P0_SET;                       /**< Regulator 3P0 Register, offset: 0x124 */
  __IO uint32_t REG_3P0_CLR;                       /**< Regulator 3P0 Register, offset: 0x128 */
  __IO uint32_t REG_3P0_TOG;                       /**< Regulator 3P0 Register, offset: 0x12C */
  __IO uint32_t REG_2P5;                           /**< Regulator 2P5 Register, offset: 0x130 */
  __IO uint32_t REG_2P5_SET;                       /**< Regulator 2P5 Register, offset: 0x134 */
  __IO uint32_t REG_2P5_CLR;                       /**< Regulator 2P5 Register, offset: 0x138 */
  __IO uint32_t REG_2P5_TOG;                       /**< Regulator 2P5 Register, offset: 0x13C */
  __IO uint32_t REG_CORE;                          /**< Digital Regulator Core Register, offset: 0x140 */
  __IO uint32_t REG_CORE_SET;                      /**< Digital Regulator Core Register, offset: 0x144 */
  __IO uint32_t REG_CORE_CLR;                      /**< Digital Regulator Core Register, offset: 0x148 */
  __IO uint32_t REG_CORE_TOG;                      /**< Digital Regulator Core Register, offset: 0x14C */
  __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  __IO uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  __IO uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  __IO uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  __IO uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  __IO uint32_t MISC2;                             /**< Miscellaneous Control Register, offset: 0x170 */
  __IO uint32_t MISC2_SET;                         /**< Miscellaneous Control Register, offset: 0x174 */
  __IO uint32_t MISC2_CLR;                         /**< Miscellaneous Control Register, offset: 0x178 */
  __IO uint32_t MISC2_TOG;                         /**< Miscellaneous Control Register, offset: 0x17C */
} PMU_Type;


/* PMU - Peripheral instance base addresses */
/** Peripheral PMU base address */
#define PMU_BASE                                 (0x400D8000u)
/** Peripheral PMU base pointer */
#define PMU                                      ((PMU_Type *)PMU_BASE)
/** Array initializer of PMU peripheral base addresses */
#define PMU_BASE_ADDRS                           { PMU_BASE }
/** Array initializer of PMU peripheral base pointers */
#define PMU_BASE_PTRS                            { PMU }

/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Peripheral_Access_Layer PWM Peripheral Access Layer
 * @{
 */

/** PWM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x60 */
    __I  uint16_t CNT;                               /**< Counter Register, array offset: 0x0, array step: 0x60 */
    __IO uint16_t INIT;                              /**< Initial Count Register, array offset: 0x2, array step: 0x60 */
    __IO uint16_t CTRL2;                             /**< Control 2 Register, array offset: 0x4, array step: 0x60 */
    __IO uint16_t CTRL;                              /**< Control Register, array offset: 0x6, array step: 0x60 */
         uint8_t RESERVED_0[2];
    __IO uint16_t VAL0;                              /**< Value Register 0, array offset: 0xA, array step: 0x60 */
    __IO uint16_t FRACVAL1;                          /**< Fractional Value Register 1, array offset: 0xC, array step: 0x60 */
    __IO uint16_t VAL1;                              /**< Value Register 1, array offset: 0xE, array step: 0x60 */
    __IO uint16_t FRACVAL2;                          /**< Fractional Value Register 2, array offset: 0x10, array step: 0x60 */
    __IO uint16_t VAL2;                              /**< Value Register 2, array offset: 0x12, array step: 0x60 */
    __IO uint16_t FRACVAL3;                          /**< Fractional Value Register 3, array offset: 0x14, array step: 0x60 */
    __IO uint16_t VAL3;                              /**< Value Register 3, array offset: 0x16, array step: 0x60 */
    __IO uint16_t FRACVAL4;                          /**< Fractional Value Register 4, array offset: 0x18, array step: 0x60 */
    __IO uint16_t VAL4;                              /**< Value Register 4, array offset: 0x1A, array step: 0x60 */
    __IO uint16_t FRACVAL5;                          /**< Fractional Value Register 5, array offset: 0x1C, array step: 0x60 */
    __IO uint16_t VAL5;                              /**< Value Register 5, array offset: 0x1E, array step: 0x60 */
    __IO uint16_t FRCTRL;                            /**< Fractional Control Register, array offset: 0x20, array step: 0x60 */
    __IO uint16_t OCTRL;                             /**< Output Control Register, array offset: 0x22, array step: 0x60 */
    __IO uint16_t STS;                               /**< Status Register, array offset: 0x24, array step: 0x60 */
    __IO uint16_t INTEN;                             /**< Interrupt Enable Register, array offset: 0x26, array step: 0x60 */
    __IO uint16_t DMAEN;                             /**< DMA Enable Register, array offset: 0x28, array step: 0x60 */
    __IO uint16_t TCTRL;                             /**< Output Trigger Control Register, array offset: 0x2A, array step: 0x60 */
    __IO uint16_t DISMAP[1];                         /**< Fault Disable Mapping Register 0, array offset: 0x2C, array step: index*0x60, index2*0x2 */
         uint8_t RESERVED_1[2];
    __IO uint16_t DTCNT0;                            /**< Deadtime Count Register 0, array offset: 0x30, array step: 0x60 */
    __IO uint16_t DTCNT1;                            /**< Deadtime Count Register 1, array offset: 0x32, array step: 0x60 */
    __IO uint16_t CAPTCTRLA;                         /**< Capture Control A Register, array offset: 0x34, array step: 0x60 */
    __IO uint16_t CAPTCOMPA;                         /**< Capture Compare A Register, array offset: 0x36, array step: 0x60 */
    __IO uint16_t CAPTCTRLB;                         /**< Capture Control B Register, array offset: 0x38, array step: 0x60 */
    __IO uint16_t CAPTCOMPB;                         /**< Capture Compare B Register, array offset: 0x3A, array step: 0x60 */
    __IO uint16_t CAPTCTRLX;                         /**< Capture Control X Register, array offset: 0x3C, array step: 0x60 */
    __IO uint16_t CAPTCOMPX;                         /**< Capture Compare X Register, array offset: 0x3E, array step: 0x60 */
    __I  uint16_t CVAL0;                             /**< Capture Value 0 Register, array offset: 0x40, array step: 0x60 */
    __I  uint16_t CVAL0CYC;                          /**< Capture Value 0 Cycle Register, array offset: 0x42, array step: 0x60 */
    __I  uint16_t CVAL1;                             /**< Capture Value 1 Register, array offset: 0x44, array step: 0x60 */
    __I  uint16_t CVAL1CYC;                          /**< Capture Value 1 Cycle Register, array offset: 0x46, array step: 0x60 */
    __I  uint16_t CVAL2;                             /**< Capture Value 2 Register, array offset: 0x48, array step: 0x60 */
    __I  uint16_t CVAL2CYC;                          /**< Capture Value 2 Cycle Register, array offset: 0x4A, array step: 0x60 */
    __I  uint16_t CVAL3;                             /**< Capture Value 3 Register, array offset: 0x4C, array step: 0x60 */
    __I  uint16_t CVAL3CYC;                          /**< Capture Value 3 Cycle Register, array offset: 0x4E, array step: 0x60 */
    __I  uint16_t CVAL4;                             /**< Capture Value 4 Register, array offset: 0x50, array step: 0x60 */
    __I  uint16_t CVAL4CYC;                          /**< Capture Value 4 Cycle Register, array offset: 0x52, array step: 0x60 */
    __I  uint16_t CVAL5;                             /**< Capture Value 5 Register, array offset: 0x54, array step: 0x60 */
    __I  uint16_t CVAL5CYC;                          /**< Capture Value 5 Cycle Register, array offset: 0x56, array step: 0x60 */
         uint8_t RESERVED_2[8];
  } SM[4];
  __IO uint16_t OUTEN;                             /**< Output Enable Register, offset: 0x180 */
  __IO uint16_t MASK;                              /**< Mask Register, offset: 0x182 */
  __IO uint16_t SWCOUT;                            /**< Software Controlled Output Register, offset: 0x184 */
  __IO uint16_t DTSRCSEL;                          /**< PWM Source Select Register, offset: 0x186 */
  __IO uint16_t MCTRL;                             /**< Master Control Register, offset: 0x188 */
  __IO uint16_t MCTRL2;                            /**< Master Control 2 Register, offset: 0x18A */
  __IO uint16_t FCTRL;                             /**< Fault Control Register, offset: 0x18C */
  __IO uint16_t FSTS;                              /**< Fault Status Register, offset: 0x18E */
  __IO uint16_t FFILT;                             /**< Fault Filter Register, offset: 0x190 */
  __IO uint16_t FTST;                              /**< Fault Test Register, offset: 0x192 */
  __IO uint16_t FCTRL2;                            /**< Fault Control 2 Register, offset: 0x194 */
} PWM_Type;


/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x401CC000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { 0u, PWM1_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_RELOAD_IRQS                          { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_FAULT_IRQS                           { NotAvail_IRQn, PWM1_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { NotAvail_IRQn, PWM1_FAULT_IRQn }

/*!
 * @}
 */ /* end of group PWM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTWDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTWDOG_Peripheral_Access_Layer RTWDOG Peripheral Access Layer
 * @{
 */

/** RTWDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
} RTWDOG_Type;


/* RTWDOG - Peripheral instance base addresses */
/** Peripheral RTWDOG base address */
#define RTWDOG_BASE                              (0x400BC000u)
/** Peripheral RTWDOG base pointer */
#define RTWDOG                                   ((RTWDOG_Type *)RTWDOG_BASE)
/** Array initializer of RTWDOG peripheral base addresses */
#define RTWDOG_BASE_ADDRS                        { RTWDOG_BASE }
/** Array initializer of RTWDOG peripheral base pointers */
#define RTWDOG_BASE_PTRS                         { RTWDOG }
/** Interrupt vectors for the RTWDOG peripheral type */
#define RTWDOG_IRQS                              { RTWDOG_IRQn }
/* Extra definition */
#define RTWDOG_UPDATE_KEY                        (0xD928C520U)
#define RTWDOG_REFRESH_KEY                       (0xB480A602U)


/*!
 * @}
 */ /* end of group RTWDOG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SNVS_Peripheral_Access_Layer SNVS Peripheral Access Layer
 * @{
 */

/** SNVS - Register Layout Typedef */
typedef struct {
  __IO uint32_t HPLR;                              /**< SNVS_HP Lock Register, offset: 0x0 */
  __IO uint32_t HPCOMR;                            /**< SNVS_HP Command Register, offset: 0x4 */
  __IO uint32_t HPCR;                              /**< SNVS_HP Control Register, offset: 0x8 */
  __IO uint32_t HPSICR;                            /**< SNVS_HP Security Interrupt Control Register, offset: 0xC */
  __IO uint32_t HPSVCR;                            /**< SNVS_HP Security Violation Control Register, offset: 0x10 */
  __IO uint32_t HPSR;                              /**< SNVS_HP Status Register, offset: 0x14 */
  __IO uint32_t HPSVSR;                            /**< SNVS_HP Security Violation Status Register, offset: 0x18 */
  __IO uint32_t HPHACIVR;                          /**< SNVS_HP High Assurance Counter IV Register, offset: 0x1C */
  __I  uint32_t HPHACR;                            /**< SNVS_HP High Assurance Counter Register, offset: 0x20 */
  __IO uint32_t HPRTCMR;                           /**< SNVS_HP Real Time Counter MSB Register, offset: 0x24 */
  __IO uint32_t HPRTCLR;                           /**< SNVS_HP Real Time Counter LSB Register, offset: 0x28 */
  __IO uint32_t HPTAMR;                            /**< SNVS_HP Time Alarm MSB Register, offset: 0x2C */
  __IO uint32_t HPTALR;                            /**< SNVS_HP Time Alarm LSB Register, offset: 0x30 */
  __IO uint32_t LPLR;                              /**< SNVS_LP Lock Register, offset: 0x34 */
  __IO uint32_t LPCR;                              /**< SNVS_LP Control Register, offset: 0x38 */
  __IO uint32_t LPMKCR;                            /**< SNVS_LP Master Key Control Register, offset: 0x3C */
  __IO uint32_t LPSVCR;                            /**< SNVS_LP Security Violation Control Register, offset: 0x40 */
  __IO uint32_t LPTGFCR;                           /**< SNVS_LP Tamper Glitch Filters Configuration Register, offset: 0x44 */
  __IO uint32_t LPTDCR;                            /**< SNVS_LP Tamper Detect Configuration Register, offset: 0x48 */
  __IO uint32_t LPSR;                              /**< SNVS_LP Status Register, offset: 0x4C */
  __IO uint32_t LPSRTCMR;                          /**< SNVS_LP Secure Real Time Counter MSB Register, offset: 0x50 */
  __IO uint32_t LPSRTCLR;                          /**< SNVS_LP Secure Real Time Counter LSB Register, offset: 0x54 */
  __IO uint32_t LPTAR;                             /**< SNVS_LP Time Alarm Register, offset: 0x58 */
  __IO uint32_t LPSMCMR;                           /**< SNVS_LP Secure Monotonic Counter MSB Register, offset: 0x5C */
  __IO uint32_t LPSMCLR;                           /**< SNVS_LP Secure Monotonic Counter LSB Register, offset: 0x60 */
  __IO uint32_t LPLVDR;                            /**< SNVS_LP Digital Low-Voltage Detector Register, offset: 0x64 */
  __IO uint32_t LPGPR0_LEGACY_ALIAS;               /**< SNVS_LP General Purpose Register 0 (legacy alias), offset: 0x68 */
  __IO uint32_t LPZMKR[8];                         /**< SNVS_LP Zeroizable Master Key Register, array offset: 0x6C, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t LPGPR_ALIAS[4];                    /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_1[96];
  __IO uint32_t LPGPR[4];                          /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_2[2792];
  __I  uint32_t HPVIDR1;                           /**< SNVS_HP Version ID Register 1, offset: 0xBF8 */
  __I  uint32_t HPVIDR2;                           /**< SNVS_HP Version ID Register 2, offset: 0xBFC */
} SNVS_Type;


/* SNVS - Peripheral instance base addresses */
/** Peripheral SNVS base address */
#define SNVS_BASE                                (0x400D4000u)
/** Peripheral SNVS base pointer */
#define SNVS                                     ((SNVS_Type *)SNVS_BASE)
/** Array initializer of SNVS peripheral base addresses */
#define SNVS_BASE_ADDRS                          { SNVS_BASE }
/** Array initializer of SNVS peripheral base pointers */
#define SNVS_BASE_PTRS                           { SNVS }
/** Interrupt vectors for the SNVS peripheral type */
#define SNVS_IRQS                                { SNVS_LP_WRAPPER_IRQn }
#define SNVS_CONSOLIDATED_IRQS                   { SNVS_HP_WRAPPER_IRQn }
#define SNVS_SECURITY_IRQS                       { SNVS_HP_WRAPPER_TZ_IRQn }

/*!
 * @}
 */ /* end of group SNVS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPDIF_Peripheral_Access_Layer SPDIF Peripheral Access Layer
 * @{
 */

/** SPDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SPDIF Configuration Register, offset: 0x0 */
  __IO uint32_t SRCD;                              /**< CDText Control Register, offset: 0x4 */
  __IO uint32_t SRPC;                              /**< PhaseConfig Register, offset: 0x8 */
  __IO uint32_t SIE;                               /**< InterruptEn Register, offset: 0xC */
  union {                                          /* offset: 0x10 */
    __O  uint32_t SIC;                               /**< InterruptClear Register, offset: 0x10 */
    __I  uint32_t SIS;                               /**< InterruptStat Register, offset: 0x10 */
  };
  __I  uint32_t SRL;                               /**< SPDIFRxLeft Register, offset: 0x14 */
  __I  uint32_t SRR;                               /**< SPDIFRxRight Register, offset: 0x18 */
  __I  uint32_t SRCSH;                             /**< SPDIFRxCChannel_h Register, offset: 0x1C */
  __I  uint32_t SRCSL;                             /**< SPDIFRxCChannel_l Register, offset: 0x20 */
  __I  uint32_t SRU;                               /**< UchannelRx Register, offset: 0x24 */
  __I  uint32_t SRQ;                               /**< QchannelRx Register, offset: 0x28 */
  __O  uint32_t STL;                               /**< SPDIFTxLeft Register, offset: 0x2C */
  __O  uint32_t STR;                               /**< SPDIFTxRight Register, offset: 0x30 */
  __IO uint32_t STCSCH;                            /**< SPDIFTxCChannelCons_h Register, offset: 0x34 */
  __IO uint32_t STCSCL;                            /**< SPDIFTxCChannelCons_l Register, offset: 0x38 */
       uint8_t RESERVED_0[8];
  __I  uint32_t SRFM;                              /**< FreqMeas Register, offset: 0x44 */
       uint8_t RESERVED_1[8];
  __IO uint32_t STC;                               /**< SPDIFTxClk Register, offset: 0x50 */
} SPDIF_Type;


/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF base address */
#define SPDIF_BASE                               (0x401DC000u)
/** Peripheral SPDIF base pointer */
#define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { SPDIF }
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { SPDIF_IRQn }

/*!
 * @}
 */ /* end of group SPDIF_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Peripheral_Access_Layer SRC Peripheral Access Layer
 * @{
 */

/** SRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SRC Control Register, offset: 0x0 */
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x4 */
  __IO uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x8 */
       uint8_t RESERVED_0[16];
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x1C */
  __IO uint32_t GPR[10];                           /**< SRC General Purpose Register 1..SRC General Purpose Register 10, array offset: 0x20, array step: 0x4 */
} SRC_Type;


/* SRC - Peripheral instance base addresses */
/** Peripheral SRC base address */
#define SRC_BASE                                 (0x400F8000u)
/** Peripheral SRC base pointer */
#define SRC                                      ((SRC_Type *)SRC_BASE)
/** Array initializer of SRC peripheral base addresses */
#define SRC_BASE_ADDRS                           { SRC_BASE }
/** Array initializer of SRC peripheral base pointers */
#define SRC_BASE_PTRS                            { SRC }
/** Interrupt vectors for the SRC peripheral type */
#define SRC_IRQS                                 { SRC_IRQn }
/* Backward compatibility */
#define SRC_SCR_MWDR_MASK                      SRC_SCR_MASK_WDOG_RST_MASK
#define SRC_SCR_MWDR_SHIFT                     SRC_SCR_MASK_WDOG_RST_SHIFT
#define SRC_SCR_MWDR(x)                        SRC_SCR_MASK_WDOG_RST(x)
#define SRC_SRSR_WDOG_MASK                     SRC_SRSR_WDOG_RST_B_MASK
#define SRC_SRSR_WDOG_SHIFT                    SRC_SRSR_WDOG_RST_B_SHIFT
#define SRC_SRSR_WDOG(x)                       SRC_SRSR_WDOG_RST_B(x)
#define SRC_SRSR_JTAG_MASK                     SRC_SRSR_JTAG_RST_B_MASK
#define SRC_SRSR_JTAG_SHIFT                    SRC_SRSR_JTAG_RST_B_SHIFT
#define SRC_SRSR_JTAG(x)                       SRC_SRSR_JTAG_RST_B(x)
#define SRC_SRSR_SJC_MASK                      SRC_SRSR_JTAG_SW_RST_MASK
#define SRC_SRSR_SJC_SHIFT                     SRC_SRSR_JTAG_SW_RST_SHIFT
#define SRC_SRSR_SJC(x)                        SRC_SRSR_JTAG_SW_RST(x)
#define SRC_SRSR_TSR_MASK                      SRC_SRSR_TEMPSENSE_RST_B_MASK
#define SRC_SRSR_TSR_SHIFT                     SRC_SRSR_TEMPSENSE_RST_B_SHIFT
#define SRC_SRSR_TSR(x)                        SRC_SRSR_TEMPSENSE_RST_B(x)
/* Extra definition */
#define SRC_SRSR_W1C_BITS_MASK  ( SRC_SRSR_WDOG3_RST_B_MASK \
                                | SRC_SRSR_JTAG_SW_RST_MASK \
                                | SRC_SRSR_JTAG_RST_B_MASK \
                                | SRC_SRSR_WDOG_RST_B_MASK \
                                | SRC_SRSR_IPP_USER_RESET_B_MASK \
                                | SRC_SRSR_CSU_RESET_B_MASK \
                                | SRC_SRSR_LOCKUP_MASK \
                                | SRC_SRSR_IPP_RESET_B_MASK)


/*!
 * @}
 */ /* end of group SRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TEMPMON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPMON_Peripheral_Access_Layer TEMPMON Peripheral Access Layer
 * @{
 */

/** TEMPMON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[384];
  __IO uint32_t TEMPSENSE0;                        /**< Tempsensor Control Register 0, offset: 0x180 */
  __IO uint32_t TEMPSENSE0_SET;                    /**< Tempsensor Control Register 0, offset: 0x184 */
  __IO uint32_t TEMPSENSE0_CLR;                    /**< Tempsensor Control Register 0, offset: 0x188 */
  __IO uint32_t TEMPSENSE0_TOG;                    /**< Tempsensor Control Register 0, offset: 0x18C */
  __IO uint32_t TEMPSENSE1;                        /**< Tempsensor Control Register 1, offset: 0x190 */
  __IO uint32_t TEMPSENSE1_SET;                    /**< Tempsensor Control Register 1, offset: 0x194 */
  __IO uint32_t TEMPSENSE1_CLR;                    /**< Tempsensor Control Register 1, offset: 0x198 */
  __IO uint32_t TEMPSENSE1_TOG;                    /**< Tempsensor Control Register 1, offset: 0x19C */
       uint8_t RESERVED_1[240];
  __IO uint32_t TEMPSENSE2;                        /**< Tempsensor Control Register 2, offset: 0x290 */
  __IO uint32_t TEMPSENSE2_SET;                    /**< Tempsensor Control Register 2, offset: 0x294 */
  __IO uint32_t TEMPSENSE2_CLR;                    /**< Tempsensor Control Register 2, offset: 0x298 */
  __IO uint32_t TEMPSENSE2_TOG;                    /**< Tempsensor Control Register 2, offset: 0x29C */
} TEMPMON_Type;


/* TEMPMON - Peripheral instance base addresses */
/** Peripheral TEMPMON base address */
#define TEMPMON_BASE                             (0x400D8000u)
/** Peripheral TEMPMON base pointer */
#define TEMPMON                                  ((TEMPMON_Type *)TEMPMON_BASE)
/** Array initializer of TEMPMON peripheral base addresses */
#define TEMPMON_BASE_ADDRS                       { TEMPMON_BASE }
/** Array initializer of TEMPMON peripheral base pointers */
#define TEMPMON_BASE_PTRS                        { TEMPMON }

/*!
 * @}
 */ /* end of group TEMPMON_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TRNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Peripheral_Access_Layer TRNG Peripheral Access Layer
 * @{
 */

/** TRNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCTL;                              /**< Miscellaneous Control Register, offset: 0x0 */
  __IO uint32_t SCMISC;                            /**< Statistical Check Miscellaneous Register, offset: 0x4 */
  __IO uint32_t PKRRNG;                            /**< Poker Range Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t PKRMAX;                            /**< Poker Maximum Limit Register, offset: 0xC */
    __I  uint32_t PKRSQ;                             /**< Poker Square Calculation Result Register, offset: 0xC */
  };
  __IO uint32_t SDCTL;                             /**< Seed Control Register, offset: 0x10 */
  union {                                          /* offset: 0x14 */
    __IO uint32_t SBLIM;                             /**< Sparse Bit Limit Register, offset: 0x14 */
    __I  uint32_t TOTSAM;                            /**< Total Samples Register, offset: 0x14 */
  };
  __IO uint32_t FRQMIN;                            /**< Frequency Count Minimum Limit Register, offset: 0x18 */
  union {                                          /* offset: 0x1C */
    __I  uint32_t FRQCNT;                            /**< Frequency Count Register, offset: 0x1C */
    __IO uint32_t FRQMAX;                            /**< Frequency Count Maximum Limit Register, offset: 0x1C */
  };
  union {                                          /* offset: 0x20 */
    __I  uint32_t SCMC;                              /**< Statistical Check Monobit Count Register, offset: 0x20 */
    __IO uint32_t SCML;                              /**< Statistical Check Monobit Limit Register, offset: 0x20 */
  };
  union {                                          /* offset: 0x24 */
    __I  uint32_t SCR1C;                             /**< Statistical Check Run Length 1 Count Register, offset: 0x24 */
    __IO uint32_t SCR1L;                             /**< Statistical Check Run Length 1 Limit Register, offset: 0x24 */
  };
  union {                                          /* offset: 0x28 */
    __I  uint32_t SCR2C;                             /**< Statistical Check Run Length 2 Count Register, offset: 0x28 */
    __IO uint32_t SCR2L;                             /**< Statistical Check Run Length 2 Limit Register, offset: 0x28 */
  };
  union {                                          /* offset: 0x2C */
    __I  uint32_t SCR3C;                             /**< Statistical Check Run Length 3 Count Register, offset: 0x2C */
    __IO uint32_t SCR3L;                             /**< Statistical Check Run Length 3 Limit Register, offset: 0x2C */
  };
  union {                                          /* offset: 0x30 */
    __I  uint32_t SCR4C;                             /**< Statistical Check Run Length 4 Count Register, offset: 0x30 */
    __IO uint32_t SCR4L;                             /**< Statistical Check Run Length 4 Limit Register, offset: 0x30 */
  };
  union {                                          /* offset: 0x34 */
    __I  uint32_t SCR5C;                             /**< Statistical Check Run Length 5 Count Register, offset: 0x34 */
    __IO uint32_t SCR5L;                             /**< Statistical Check Run Length 5 Limit Register, offset: 0x34 */
  };
  union {                                          /* offset: 0x38 */
    __I  uint32_t SCR6PC;                            /**< Statistical Check Run Length 6+ Count Register, offset: 0x38 */
    __IO uint32_t SCR6PL;                            /**< Statistical Check Run Length 6+ Limit Register, offset: 0x38 */
  };
  __I  uint32_t STATUS;                            /**< Status Register, offset: 0x3C */
  __I  uint32_t ENT[16];                           /**< Entropy Read Register, array offset: 0x40, array step: 0x4 */
  __I  uint32_t PKRCNT10;                          /**< Statistical Check Poker Count 1 and 0 Register, offset: 0x80 */
  __I  uint32_t PKRCNT32;                          /**< Statistical Check Poker Count 3 and 2 Register, offset: 0x84 */
  __I  uint32_t PKRCNT54;                          /**< Statistical Check Poker Count 5 and 4 Register, offset: 0x88 */
  __I  uint32_t PKRCNT76;                          /**< Statistical Check Poker Count 7 and 6 Register, offset: 0x8C */
  __I  uint32_t PKRCNT98;                          /**< Statistical Check Poker Count 9 and 8 Register, offset: 0x90 */
  __I  uint32_t PKRCNTBA;                          /**< Statistical Check Poker Count B and A Register, offset: 0x94 */
  __I  uint32_t PKRCNTDC;                          /**< Statistical Check Poker Count D and C Register, offset: 0x98 */
  __I  uint32_t PKRCNTFE;                          /**< Statistical Check Poker Count F and E Register, offset: 0x9C */
  __IO uint32_t SEC_CFG;                           /**< Security Configuration Register, offset: 0xA0 */
  __IO uint32_t INT_CTRL;                          /**< Interrupt Control Register, offset: 0xA4 */
  __IO uint32_t INT_MASK;                          /**< Mask Register, offset: 0xA8 */
  __I  uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0xAC */
       uint8_t RESERVED_0[64];
  __I  uint32_t VID1;                              /**< Version ID Register (MS), offset: 0xF0 */
  __I  uint32_t VID2;                              /**< Version ID Register (LS), offset: 0xF4 */
} TRNG_Type;


/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x400CC000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }

/*!
 * @}
 */ /* end of group TRNG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID;                                /**< Identification register, offset: 0x0 */
  __I  uint32_t HWGENERAL;                         /**< Hardware General, offset: 0x4 */
  __I  uint32_t HWHOST;                            /**< Host Hardware Parameters, offset: 0x8 */
  __I  uint32_t HWDEVICE;                          /**< Device Hardware Parameters, offset: 0xC */
  __I  uint32_t HWTXBUF;                           /**< TX Buffer Hardware Parameters, offset: 0x10 */
  __I  uint32_t HWRXBUF;                           /**< RX Buffer Hardware Parameters, offset: 0x14 */
       uint8_t RESERVED_0[104];
  __IO uint32_t GPTIMER0LD;                        /**< General Purpose Timer #0 Load, offset: 0x80 */
  __IO uint32_t GPTIMER0CTRL;                      /**< General Purpose Timer #0 Controller, offset: 0x84 */
  __IO uint32_t GPTIMER1LD;                        /**< General Purpose Timer #1 Load, offset: 0x88 */
  __IO uint32_t GPTIMER1CTRL;                      /**< General Purpose Timer #1 Controller, offset: 0x8C */
  __IO uint32_t SBUSCFG;                           /**< System Bus Config, offset: 0x90 */
       uint8_t RESERVED_1[108];
  __I  uint8_t CAPLENGTH;                          /**< Capability Registers Length, offset: 0x100 */
       uint8_t RESERVED_2[1];
  __I  uint16_t HCIVERSION;                        /**< Host Controller Interface Version, offset: 0x102 */
  __I  uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x104 */
  __I  uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x108 */
       uint8_t RESERVED_3[20];
  __I  uint16_t DCIVERSION;                        /**< Device Controller Interface Version, offset: 0x120 */
       uint8_t RESERVED_4[2];
  __I  uint32_t DCCPARAMS;                         /**< Device Controller Capability Parameters, offset: 0x124 */
       uint8_t RESERVED_5[24];
  __IO uint32_t USBCMD;                            /**< USB Command Register, offset: 0x140 */
  __IO uint32_t USBSTS;                            /**< USB Status Register, offset: 0x144 */
  __IO uint32_t USBINTR;                           /**< Interrupt Enable Register, offset: 0x148 */
  __IO uint32_t FRINDEX;                           /**< USB Frame Index, offset: 0x14C */
       uint8_t RESERVED_6[4];
  union {                                          /* offset: 0x154 */
    __IO uint32_t DEVICEADDR;                        /**< Device Address, offset: 0x154 */
    __IO uint32_t PERIODICLISTBASE;                  /**< Frame List Base Address, offset: 0x154 */
  };
  union {                                          /* offset: 0x158 */
    __IO uint32_t ASYNCLISTADDR;                     /**< Next Asynch. Address, offset: 0x158 */
    __IO uint32_t ENDPTLISTADDR;                     /**< Endpoint List Address, offset: 0x158 */
  };
       uint8_t RESERVED_7[4];
  __IO uint32_t BURSTSIZE;                         /**< Programmable Burst Size, offset: 0x160 */
  __IO uint32_t TXFILLTUNING;                      /**< TX FIFO Fill Tuning, offset: 0x164 */
       uint8_t RESERVED_8[16];
  __IO uint32_t ENDPTNAK;                          /**< Endpoint NAK, offset: 0x178 */
  __IO uint32_t ENDPTNAKEN;                        /**< Endpoint NAK Enable, offset: 0x17C */
  __I  uint32_t CONFIGFLAG;                        /**< Configure Flag Register, offset: 0x180 */
  __IO uint32_t PORTSC1;                           /**< Port Status & Control, offset: 0x184 */
       uint8_t RESERVED_9[28];
  __IO uint32_t OTGSC;                             /**< On-The-Go Status & control, offset: 0x1A4 */
  __IO uint32_t USBMODE;                           /**< USB Device Mode, offset: 0x1A8 */
  __IO uint32_t ENDPTSETUPSTAT;                    /**< Endpoint Setup Status, offset: 0x1AC */
  __IO uint32_t ENDPTPRIME;                        /**< Endpoint Prime, offset: 0x1B0 */
  __IO uint32_t ENDPTFLUSH;                        /**< Endpoint Flush, offset: 0x1B4 */
  __I  uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  __IO uint32_t ENDPTCOMPLETE;                     /**< Endpoint Complete, offset: 0x1BC */
  __IO uint32_t ENDPTCTRL0;                        /**< Endpoint Control0, offset: 0x1C0 */
  __IO uint32_t ENDPTCTRL[7];                      /**< Endpoint Control 1..Endpoint Control 7, array offset: 0x1C4, array step: 0x4 */
} USB_Type;


/* USB - Peripheral instance base addresses */
/** Peripheral USB base address */
#define USB_BASE                                 (0x400E4000u)
/** Peripheral USB base pointer */
#define USB                                      ((USB_Type *)USB_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { 0u, USB_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { (USB_Type *)0u, USB }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { NotAvail_IRQn, USB_OTG1_IRQn }
/* Backward compatibility */
#define GPTIMER0CTL                              GPTIMER0CTRL
#define GPTIMER1CTL                              GPTIMER1CTRL
#define USB_SBUSCFG                              SBUSCFG
#define EPLISTADDR                               ENDPTLISTADDR
#define EPSETUPSR                                ENDPTSETUPSTAT
#define EPPRIME                                  ENDPTPRIME
#define EPFLUSH                                  ENDPTFLUSH
#define EPSR                                     ENDPTSTAT
#define EPCOMPLETE                               ENDPTCOMPLETE
#define EPCR                                     ENDPTCTRL
#define EPCR0                                    ENDPTCTRL0
#define USBHS_ID_ID_MASK                         USB_ID_ID_MASK
#define USBHS_ID_ID_SHIFT                        USB_ID_ID_SHIFT
#define USBHS_ID_ID(x)                           USB_ID_ID(x)
#define USBHS_ID_NID_MASK                        USB_ID_NID_MASK
#define USBHS_ID_NID_SHIFT                       USB_ID_NID_SHIFT
#define USBHS_ID_NID(x)                          USB_ID_NID(x)
#define USBHS_ID_REVISION_MASK                   USB_ID_REVISION_MASK
#define USBHS_ID_REVISION_SHIFT                  USB_ID_REVISION_SHIFT
#define USBHS_ID_REVISION(x)                     USB_ID_REVISION(x)
#define USBHS_HWGENERAL_PHYW_MASK                USB_HWGENERAL_PHYW_MASK
#define USBHS_HWGENERAL_PHYW_SHIFT               USB_HWGENERAL_PHYW_SHIFT
#define USBHS_HWGENERAL_PHYW(x)                  USB_HWGENERAL_PHYW(x)
#define USBHS_HWGENERAL_PHYM_MASK                USB_HWGENERAL_PHYM_MASK
#define USBHS_HWGENERAL_PHYM_SHIFT               USB_HWGENERAL_PHYM_SHIFT
#define USBHS_HWGENERAL_PHYM(x)                  USB_HWGENERAL_PHYM(x)
#define USBHS_HWGENERAL_SM_MASK                  USB_HWGENERAL_SM_MASK
#define USBHS_HWGENERAL_SM_SHIFT                 USB_HWGENERAL_SM_SHIFT
#define USBHS_HWGENERAL_SM(x)                    USB_HWGENERAL_SM(x)
#define USBHS_HWHOST_HC_MASK                     USB_HWHOST_HC_MASK
#define USBHS_HWHOST_HC_SHIFT                    USB_HWHOST_HC_SHIFT
#define USBHS_HWHOST_HC(x)                       USB_HWHOST_HC(x)
#define USBHS_HWHOST_NPORT_MASK                  USB_HWHOST_NPORT_MASK
#define USBHS_HWHOST_NPORT_SHIFT                 USB_HWHOST_NPORT_SHIFT
#define USBHS_HWHOST_NPORT(x)                    USB_HWHOST_NPORT(x)
#define USBHS_HWDEVICE_DC_MASK                   USB_HWDEVICE_DC_MASK
#define USBHS_HWDEVICE_DC_SHIFT                  USB_HWDEVICE_DC_SHIFT
#define USBHS_HWDEVICE_DC(x)                     USB_HWDEVICE_DC(x)
#define USBHS_HWDEVICE_DEVEP_MASK                USB_HWDEVICE_DEVEP_MASK
#define USBHS_HWDEVICE_DEVEP_SHIFT               USB_HWDEVICE_DEVEP_SHIFT
#define USBHS_HWDEVICE_DEVEP(x)                  USB_HWDEVICE_DEVEP(x)
#define USBHS_HWTXBUF_TXBURST_MASK               USB_HWTXBUF_TXBURST_MASK
#define USBHS_HWTXBUF_TXBURST_SHIFT              USB_HWTXBUF_TXBURST_SHIFT
#define USBHS_HWTXBUF_TXBURST(x)                 USB_HWTXBUF_TXBURST(x)
#define USBHS_HWTXBUF_TXCHANADD_MASK             USB_HWTXBUF_TXCHANADD_MASK
#define USBHS_HWTXBUF_TXCHANADD_SHIFT            USB_HWTXBUF_TXCHANADD_SHIFT
#define USBHS_HWTXBUF_TXCHANADD(x)               USB_HWTXBUF_TXCHANADD(x)
#define USBHS_HWRXBUF_RXBURST_MASK               USB_HWRXBUF_RXBURST_MASK
#define USBHS_HWRXBUF_RXBURST_SHIFT              USB_HWRXBUF_RXBURST_SHIFT
#define USBHS_HWRXBUF_RXBURST(x)                 USB_HWRXBUF_RXBURST(x)
#define USBHS_HWRXBUF_RXADD_MASK                 USB_HWRXBUF_RXADD_MASK
#define USBHS_HWRXBUF_RXADD_SHIFT                USB_HWRXBUF_RXADD_SHIFT
#define USBHS_HWRXBUF_RXADD(x)                   USB_HWRXBUF_RXADD(x)
#define USBHS_GPTIMER0LD_GPTLD_MASK              USB_GPTIMER0LD_GPTLD_MASK
#define USBHS_GPTIMER0LD_GPTLD_SHIFT             USB_GPTIMER0LD_GPTLD_SHIFT
#define USBHS_GPTIMER0LD_GPTLD(x)                USB_GPTIMER0LD_GPTLD(x)
#define USBHS_GPTIMER0CTL_GPTCNT_MASK            USB_GPTIMER0CTRL_GPTCNT_MASK
#define USBHS_GPTIMER0CTL_GPTCNT_SHIFT           USB_GPTIMER0CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER0CTL_GPTCNT(x)              USB_GPTIMER0CTRL_GPTCNT(x)
#define USBHS_GPTIMER0CTL_MODE_MASK              USB_GPTIMER0CTRL_GPTMODE_MASK
#define USBHS_GPTIMER0CTL_MODE_SHIFT             USB_GPTIMER0CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER0CTL_MODE(x)                USB_GPTIMER0CTRL_GPTMODE(x)
#define USBHS_GPTIMER0CTL_RST_MASK               USB_GPTIMER0CTRL_GPTRST_MASK
#define USBHS_GPTIMER0CTL_RST_SHIFT              USB_GPTIMER0CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER0CTL_RST(x)                 USB_GPTIMER0CTRL_GPTRST(x)
#define USBHS_GPTIMER0CTL_RUN_MASK               USB_GPTIMER0CTRL_GPTRUN_MASK
#define USBHS_GPTIMER0CTL_RUN_SHIFT              USB_GPTIMER0CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER0CTL_RUN(x)                 USB_GPTIMER0CTRL_GPTRUN(x)
#define USBHS_GPTIMER1LD_GPTLD_MASK              USB_GPTIMER1LD_GPTLD_MASK
#define USBHS_GPTIMER1LD_GPTLD_SHIFT             USB_GPTIMER1LD_GPTLD_SHIFT
#define USBHS_GPTIMER1LD_GPTLD(x)                USB_GPTIMER1LD_GPTLD(x)
#define USBHS_GPTIMER1CTL_GPTCNT_MASK            USB_GPTIMER1CTRL_GPTCNT_MASK
#define USBHS_GPTIMER1CTL_GPTCNT_SHIFT           USB_GPTIMER1CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER1CTL_GPTCNT(x)              USB_GPTIMER1CTRL_GPTCNT(x)
#define USBHS_GPTIMER1CTL_MODE_MASK              USB_GPTIMER1CTRL_GPTMODE_MASK
#define USBHS_GPTIMER1CTL_MODE_SHIFT             USB_GPTIMER1CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER1CTL_MODE(x)                USB_GPTIMER1CTRL_GPTMODE(x)
#define USBHS_GPTIMER1CTL_RST_MASK               USB_GPTIMER1CTRL_GPTRST_MASK
#define USBHS_GPTIMER1CTL_RST_SHIFT              USB_GPTIMER1CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER1CTL_RST(x)                 USB_GPTIMER1CTRL_GPTRST(x)
#define USBHS_GPTIMER1CTL_RUN_MASK               USB_GPTIMER1CTRL_GPTRUN_MASK
#define USBHS_GPTIMER1CTL_RUN_SHIFT              USB_GPTIMER1CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER1CTL_RUN(x)                 USB_GPTIMER1CTRL_GPTRUN(x)
#define USBHS_USB_SBUSCFG_BURSTMODE_MASK         USB_SBUSCFG_AHBBRST_MASK
#define USBHS_USB_SBUSCFG_BURSTMODE_SHIFT        USB_SBUSCFG_AHBBRST_SHIFT
#define USBHS_USB_SBUSCFG_BURSTMODE(x)           USB_SBUSCFG_AHBBRST(x)
#define USBHS_HCIVERSION_CAPLENGTH(x)            USB_HCIVERSION_CAPLENGTH(x)
#define USBHS_HCIVERSION_HCIVERSION_MASK         USB_HCIVERSION_HCIVERSION_MASK
#define USBHS_HCIVERSION_HCIVERSION_SHIFT        USB_HCIVERSION_HCIVERSION_SHIFT
#define USBHS_HCIVERSION_HCIVERSION(x)           USB_HCIVERSION_HCIVERSION(x)
#define USBHS_HCSPARAMS_N_PORTS_MASK             USB_HCSPARAMS_N_PORTS_MASK
#define USBHS_HCSPARAMS_N_PORTS_SHIFT            USB_HCSPARAMS_N_PORTS_SHIFT
#define USBHS_HCSPARAMS_N_PORTS(x)               USB_HCSPARAMS_N_PORTS(x)
#define USBHS_HCSPARAMS_PPC_MASK                 USB_HCSPARAMS_PPC_MASK
#define USBHS_HCSPARAMS_PPC_SHIFT                USB_HCSPARAMS_PPC_SHIFT
#define USBHS_HCSPARAMS_PPC(x)                   USB_HCSPARAMS_PPC(x)
#define USBHS_HCSPARAMS_N_PCC_MASK               USB_HCSPARAMS_N_PCC_MASK
#define USBHS_HCSPARAMS_N_PCC_SHIFT              USB_HCSPARAMS_N_PCC_SHIFT
#define USBHS_HCSPARAMS_N_PCC(x)                 USB_HCSPARAMS_N_PCC(x)
#define USBHS_HCSPARAMS_N_CC_MASK                USB_HCSPARAMS_N_CC_MASK
#define USBHS_HCSPARAMS_N_CC_SHIFT               USB_HCSPARAMS_N_CC_SHIFT
#define USBHS_HCSPARAMS_N_CC(x)                  USB_HCSPARAMS_N_CC(x)
#define USBHS_HCSPARAMS_PI_MASK                  USB_HCSPARAMS_PI_MASK
#define USBHS_HCSPARAMS_PI_SHIFT                 USB_HCSPARAMS_PI_SHIFT
#define USBHS_HCSPARAMS_PI(x)                    USB_HCSPARAMS_PI(x)
#define USBHS_HCSPARAMS_N_PTT_MASK               USB_HCSPARAMS_N_PTT_MASK
#define USBHS_HCSPARAMS_N_PTT_SHIFT              USB_HCSPARAMS_N_PTT_SHIFT
#define USBHS_HCSPARAMS_N_PTT(x)                 USB_HCSPARAMS_N_PTT(x)
#define USBHS_HCSPARAMS_N_TT_MASK                USB_HCSPARAMS_N_TT_MASK
#define USBHS_HCSPARAMS_N_TT_SHIFT               USB_HCSPARAMS_N_TT_SHIFT
#define USBHS_HCSPARAMS_N_TT(x)                  USB_HCSPARAMS_N_TT(x)
#define USBHS_HCCPARAMS_ADC_MASK                 USB_HCCPARAMS_ADC_MASK
#define USBHS_HCCPARAMS_ADC_SHIFT                USB_HCCPARAMS_ADC_SHIFT
#define USBHS_HCCPARAMS_ADC(x)                   USB_HCCPARAMS_ADC(x)
#define USBHS_HCCPARAMS_PFL_MASK                 USB_HCCPARAMS_PFL_MASK
#define USBHS_HCCPARAMS_PFL_SHIFT                USB_HCCPARAMS_PFL_SHIFT
#define USBHS_HCCPARAMS_PFL(x)                   USB_HCCPARAMS_PFL(x)
#define USBHS_HCCPARAMS_ASP_MASK                 USB_HCCPARAMS_ASP_MASK
#define USBHS_HCCPARAMS_ASP_SHIFT                USB_HCCPARAMS_ASP_SHIFT
#define USBHS_HCCPARAMS_ASP(x)                   USB_HCCPARAMS_ASP(x)
#define USBHS_HCCPARAMS_IST_MASK                 USB_HCCPARAMS_IST_MASK
#define USBHS_HCCPARAMS_IST_SHIFT                USB_HCCPARAMS_IST_SHIFT
#define USBHS_HCCPARAMS_IST(x)                   USB_HCCPARAMS_IST(x)
#define USBHS_HCCPARAMS_EECP_MASK                USB_HCCPARAMS_EECP_MASK
#define USBHS_HCCPARAMS_EECP_SHIFT               USB_HCCPARAMS_EECP_SHIFT
#define USBHS_HCCPARAMS_EECP(x)                  USB_HCCPARAMS_EECP(x)
#define USBHS_DCIVERSION_DCIVERSION_MASK         USB_DCIVERSION_DCIVERSION_MASK
#define USBHS_DCIVERSION_DCIVERSION_SHIFT        USB_DCIVERSION_DCIVERSION_SHIFT
#define USBHS_DCIVERSION_DCIVERSION(x)           USB_DCIVERSION_DCIVERSION(x)
#define USBHS_DCCPARAMS_DEN_MASK                 USB_DCCPARAMS_DEN_MASK
#define USBHS_DCCPARAMS_DEN_SHIFT                USB_DCCPARAMS_DEN_SHIFT
#define USBHS_DCCPARAMS_DEN(x)                   USB_DCCPARAMS_DEN(x)
#define USBHS_DCCPARAMS_DC_MASK                  USB_DCCPARAMS_DC_MASK
#define USBHS_DCCPARAMS_DC_SHIFT                 USB_DCCPARAMS_DC_SHIFT
#define USBHS_DCCPARAMS_DC(x)                    USB_DCCPARAMS_DC(x)
#define USBHS_DCCPARAMS_HC_MASK                  USB_DCCPARAMS_HC_MASK
#define USBHS_DCCPARAMS_HC_SHIFT                 USB_DCCPARAMS_HC_SHIFT
#define USBHS_DCCPARAMS_HC(x)                    USB_DCCPARAMS_HC(x)
#define USBHS_USBCMD_RS_MASK                     USB_USBCMD_RS_MASK
#define USBHS_USBCMD_RS_SHIFT                    USB_USBCMD_RS_SHIFT
#define USBHS_USBCMD_RS(x)                       USB_USBCMD_RS(x)
#define USBHS_USBCMD_RST_MASK                    USB_USBCMD_RST_MASK
#define USBHS_USBCMD_RST_SHIFT                   USB_USBCMD_RST_SHIFT
#define USBHS_USBCMD_RST(x)                      USB_USBCMD_RST(x)
#define USBHS_USBCMD_FS_MASK                     USB_USBCMD_FS_1_MASK
#define USBHS_USBCMD_FS_SHIFT                    USB_USBCMD_FS_1_SHIFT
#define USBHS_USBCMD_FS(x)                       USB_USBCMD_FS_1(x)
#define USBHS_USBCMD_PSE_MASK                    USB_USBCMD_PSE_MASK
#define USBHS_USBCMD_PSE_SHIFT                   USB_USBCMD_PSE_SHIFT
#define USBHS_USBCMD_PSE(x)                      USB_USBCMD_PSE(x)
#define USBHS_USBCMD_ASE_MASK                    USB_USBCMD_ASE_MASK
#define USBHS_USBCMD_ASE_SHIFT                   USB_USBCMD_ASE_SHIFT
#define USBHS_USBCMD_ASE(x)                      USB_USBCMD_ASE(x)
#define USBHS_USBCMD_IAA_MASK                    USB_USBCMD_IAA_MASK
#define USBHS_USBCMD_IAA_SHIFT                   USB_USBCMD_IAA_SHIFT
#define USBHS_USBCMD_IAA(x)                      USB_USBCMD_IAA(x)
#define USBHS_USBCMD_ASP_MASK                    USB_USBCMD_ASP_MASK
#define USBHS_USBCMD_ASP_SHIFT                   USB_USBCMD_ASP_SHIFT
#define USBHS_USBCMD_ASP(x)                      USB_USBCMD_ASP(x)
#define USBHS_USBCMD_ASPE_MASK                   USB_USBCMD_ASPE_MASK
#define USBHS_USBCMD_ASPE_SHIFT                  USB_USBCMD_ASPE_SHIFT
#define USBHS_USBCMD_ASPE(x)                     USB_USBCMD_ASPE(x)
#define USBHS_USBCMD_ATDTW_MASK                  USB_USBCMD_ATDTW_MASK
#define USBHS_USBCMD_ATDTW_SHIFT                 USB_USBCMD_ATDTW_SHIFT
#define USBHS_USBCMD_ATDTW(x)                    USB_USBCMD_ATDTW(x)
#define USBHS_USBCMD_SUTW_MASK                   USB_USBCMD_SUTW_MASK
#define USBHS_USBCMD_SUTW_SHIFT                  USB_USBCMD_SUTW_SHIFT
#define USBHS_USBCMD_SUTW(x)                     USB_USBCMD_SUTW(x)
#define USBHS_USBCMD_FS2_MASK                    USB_USBCMD_FS_2_MASK
#define USBHS_USBCMD_FS2_SHIFT                   USB_USBCMD_FS_2_SHIFT
#define USBHS_USBCMD_FS2(x)                      USB_USBCMD_FS_2(x)
#define USBHS_USBCMD_ITC_MASK                    USB_USBCMD_ITC_MASK
#define USBHS_USBCMD_ITC_SHIFT                   USB_USBCMD_ITC_SHIFT
#define USBHS_USBCMD_ITC(x)                      USB_USBCMD_ITC(x)
#define USBHS_USBSTS_UI_MASK                     USB_USBSTS_UI_MASK
#define USBHS_USBSTS_UI_SHIFT                    USB_USBSTS_UI_SHIFT
#define USBHS_USBSTS_UI(x)                       USB_USBSTS_UI(x)
#define USBHS_USBSTS_UEI_MASK                    USB_USBSTS_UEI_MASK
#define USBHS_USBSTS_UEI_SHIFT                   USB_USBSTS_UEI_SHIFT
#define USBHS_USBSTS_UEI(x)                      USB_USBSTS_UEI(x)
#define USBHS_USBSTS_PCI_MASK                    USB_USBSTS_PCI_MASK
#define USBHS_USBSTS_PCI_SHIFT                   USB_USBSTS_PCI_SHIFT
#define USBHS_USBSTS_PCI(x)                      USB_USBSTS_PCI(x)
#define USBHS_USBSTS_FRI_MASK                    USB_USBSTS_FRI_MASK
#define USBHS_USBSTS_FRI_SHIFT                   USB_USBSTS_FRI_SHIFT
#define USBHS_USBSTS_FRI(x)                      USB_USBSTS_FRI(x)
#define USBHS_USBSTS_SEI_MASK                    USB_USBSTS_SEI_MASK
#define USBHS_USBSTS_SEI_SHIFT                   USB_USBSTS_SEI_SHIFT
#define USBHS_USBSTS_SEI(x)                      USB_USBSTS_SEI(x)
#define USBHS_USBSTS_AAI_MASK                    USB_USBSTS_AAI_MASK
#define USBHS_USBSTS_AAI_SHIFT                   USB_USBSTS_AAI_SHIFT
#define USBHS_USBSTS_AAI(x)                      USB_USBSTS_AAI(x)
#define USBHS_USBSTS_URI_MASK                    USB_USBSTS_URI_MASK
#define USBHS_USBSTS_URI_SHIFT                   USB_USBSTS_URI_SHIFT
#define USBHS_USBSTS_URI(x)                      USB_USBSTS_URI(x)
#define USBHS_USBSTS_SRI_MASK                    USB_USBSTS_SRI_MASK
#define USBHS_USBSTS_SRI_SHIFT                   USB_USBSTS_SRI_SHIFT
#define USBHS_USBSTS_SRI(x)                      USB_USBSTS_SRI(x)
#define USBHS_USBSTS_SLI_MASK                    USB_USBSTS_SLI_MASK
#define USBHS_USBSTS_SLI_SHIFT                   USB_USBSTS_SLI_SHIFT
#define USBHS_USBSTS_SLI(x)                      USB_USBSTS_SLI(x)
#define USBHS_USBSTS_ULPII_MASK                  USB_USBSTS_ULPII_MASK
#define USBHS_USBSTS_ULPII_SHIFT                 USB_USBSTS_ULPII_SHIFT
#define USBHS_USBSTS_ULPII(x)                    USB_USBSTS_ULPII(x)
#define USBHS_USBSTS_HCH_MASK                    USB_USBSTS_HCH_MASK
#define USBHS_USBSTS_HCH_SHIFT                   USB_USBSTS_HCH_SHIFT
#define USBHS_USBSTS_HCH(x)                      USB_USBSTS_HCH(x)
#define USBHS_USBSTS_RCL_MASK                    USB_USBSTS_RCL_MASK
#define USBHS_USBSTS_RCL_SHIFT                   USB_USBSTS_RCL_SHIFT
#define USBHS_USBSTS_RCL(x)                      USB_USBSTS_RCL(x)
#define USBHS_USBSTS_PS_MASK                     USB_USBSTS_PS_MASK
#define USBHS_USBSTS_PS_SHIFT                    USB_USBSTS_PS_SHIFT
#define USBHS_USBSTS_PS(x)                       USB_USBSTS_PS(x)
#define USBHS_USBSTS_AS_MASK                     USB_USBSTS_AS_MASK
#define USBHS_USBSTS_AS_SHIFT                    USB_USBSTS_AS_SHIFT
#define USBHS_USBSTS_AS(x)                       USB_USBSTS_AS(x)
#define USBHS_USBSTS_NAKI_MASK                   USB_USBSTS_NAKI_MASK
#define USBHS_USBSTS_NAKI_SHIFT                  USB_USBSTS_NAKI_SHIFT
#define USBHS_USBSTS_NAKI(x)                     USB_USBSTS_NAKI(x)
#define USBHS_USBSTS_TI0_MASK                    USB_USBSTS_TI0_MASK
#define USBHS_USBSTS_TI0_SHIFT                   USB_USBSTS_TI0_SHIFT
#define USBHS_USBSTS_TI0(x)                      USB_USBSTS_TI0(x)
#define USBHS_USBSTS_TI1_MASK                    USB_USBSTS_TI1_MASK
#define USBHS_USBSTS_TI1_SHIFT                   USB_USBSTS_TI1_SHIFT
#define USBHS_USBSTS_TI1(x)                      USB_USBSTS_TI1(x)
#define USBHS_USBINTR_UE_MASK                    USB_USBINTR_UE_MASK
#define USBHS_USBINTR_UE_SHIFT                   USB_USBINTR_UE_SHIFT
#define USBHS_USBINTR_UE(x)                      USB_USBINTR_UE(x)
#define USBHS_USBINTR_UEE_MASK                   USB_USBINTR_UEE_MASK
#define USBHS_USBINTR_UEE_SHIFT                  USB_USBINTR_UEE_SHIFT
#define USBHS_USBINTR_UEE(x)                     USB_USBINTR_UEE(x)
#define USBHS_USBINTR_PCE_MASK                   USB_USBINTR_PCE_MASK
#define USBHS_USBINTR_PCE_SHIFT                  USB_USBINTR_PCE_SHIFT
#define USBHS_USBINTR_PCE(x)                     USB_USBINTR_PCE(x)
#define USBHS_USBINTR_FRE_MASK                   USB_USBINTR_FRE_MASK
#define USBHS_USBINTR_FRE_SHIFT                  USB_USBINTR_FRE_SHIFT
#define USBHS_USBINTR_FRE(x)                     USB_USBINTR_FRE(x)
#define USBHS_USBINTR_SEE_MASK                   USB_USBINTR_SEE_MASK
#define USBHS_USBINTR_SEE_SHIFT                  USB_USBINTR_SEE_SHIFT
#define USBHS_USBINTR_SEE(x)                     USB_USBINTR_SEE(x)
#define USBHS_USBINTR_AAE_MASK                   USB_USBINTR_AAE_MASK
#define USBHS_USBINTR_AAE_SHIFT                  USB_USBINTR_AAE_SHIFT
#define USBHS_USBINTR_AAE(x)                     USB_USBINTR_AAE(x)
#define USBHS_USBINTR_URE_MASK                   USB_USBINTR_URE_MASK
#define USBHS_USBINTR_URE_SHIFT                  USB_USBINTR_URE_SHIFT
#define USBHS_USBINTR_URE(x)                     USB_USBINTR_URE(x)
#define USBHS_USBINTR_SRE_MASK                   USB_USBINTR_SRE_MASK
#define USBHS_USBINTR_SRE_SHIFT                  USB_USBINTR_SRE_SHIFT
#define USBHS_USBINTR_SRE(x)                     USB_USBINTR_SRE(x)
#define USBHS_USBINTR_SLE_MASK                   USB_USBINTR_SLE_MASK
#define USBHS_USBINTR_SLE_SHIFT                  USB_USBINTR_SLE_SHIFT
#define USBHS_USBINTR_SLE(x)                     USB_USBINTR_SLE(x)
#define USBHS_USBINTR_ULPIE_MASK                 USB_USBINTR_ULPIE_MASK
#define USBHS_USBINTR_ULPIE_SHIFT                USB_USBINTR_ULPIE_SHIFT
#define USBHS_USBINTR_ULPIE(x)                   USB_USBINTR_ULPIE(x)
#define USBHS_USBINTR_NAKE_MASK                  USB_USBINTR_NAKE_MASK
#define USBHS_USBINTR_NAKE_SHIFT                 USB_USBINTR_NAKE_SHIFT
#define USBHS_USBINTR_NAKE(x)                    USB_USBINTR_NAKE(x)
#define USBHS_USBINTR_UAIE_MASK                  USB_USBINTR_UAIE_MASK
#define USBHS_USBINTR_UAIE_SHIFT                 USB_USBINTR_UAIE_SHIFT
#define USBHS_USBINTR_UAIE(x)                    USB_USBINTR_UAIE(x)
#define USBHS_USBINTR_UPIE_MASK                  USB_USBINTR_UPIE_MASK
#define USBHS_USBINTR_UPIE_SHIFT                 USB_USBINTR_UPIE_SHIFT
#define USBHS_USBINTR_UPIE(x)                    USB_USBINTR_UPIE(x)
#define USBHS_USBINTR_TIE0_MASK                  USB_USBINTR_TIE0_MASK
#define USBHS_USBINTR_TIE0_SHIFT                 USB_USBINTR_TIE0_SHIFT
#define USBHS_USBINTR_TIE0(x)                    USB_USBINTR_TIE0(x)
#define USBHS_USBINTR_TIE1_MASK                  USB_USBINTR_TIE1_MASK
#define USBHS_USBINTR_TIE1_SHIFT                 USB_USBINTR_TIE1_SHIFT
#define USBHS_USBINTR_TIE1(x)                    USB_USBINTR_TIE1(x)
#define USBHS_FRINDEX_FRINDEX_MASK               USB_FRINDEX_FRINDEX_MASK
#define USBHS_FRINDEX_FRINDEX_SHIFT              USB_FRINDEX_FRINDEX_SHIFT
#define USBHS_FRINDEX_FRINDEX(x)                 USB_FRINDEX_FRINDEX(x)
#define USBHS_DEVICEADDR_USBADRA_MASK            USB_DEVICEADDR_USBADRA_MASK
#define USBHS_DEVICEADDR_USBADRA_SHIFT           USB_DEVICEADDR_USBADRA_SHIFT
#define USBHS_DEVICEADDR_USBADRA(x)              USB_DEVICEADDR_USBADRA(x)
#define USBHS_DEVICEADDR_USBADR_MASK             USB_DEVICEADDR_USBADR_MASK
#define USBHS_DEVICEADDR_USBADR_SHIFT            USB_DEVICEADDR_USBADR_SHIFT
#define USBHS_DEVICEADDR_USBADR(x)               USB_DEVICEADDR_USBADR(x)
#define USBHS_PERIODICLISTBASE_PERBASE_MASK      USB_PERIODICLISTBASE_BASEADR_MASK
#define USBHS_PERIODICLISTBASE_PERBASE_SHIFT     USB_PERIODICLISTBASE_BASEADR_SHIFT
#define USBHS_PERIODICLISTBASE_PERBASE(x)        USB_PERIODICLISTBASE_BASEADR(x)
#define USBHS_ASYNCLISTADDR_ASYBASE_MASK         USB_ASYNCLISTADDR_ASYBASE_MASK
#define USBHS_ASYNCLISTADDR_ASYBASE_SHIFT        USB_ASYNCLISTADDR_ASYBASE_SHIFT
#define USBHS_ASYNCLISTADDR_ASYBASE(x)           USB_ASYNCLISTADDR_ASYBASE(x)
#define USBHS_EPLISTADDR_EPBASE_MASK             USB_ENDPTLISTADDR_EPBASE_MASK
#define USBHS_EPLISTADDR_EPBASE_SHIFT            USB_ENDPTLISTADDR_EPBASE_SHIFT
#define USBHS_EPLISTADDR_EPBASE(x)               USB_ENDPTLISTADDR_EPBASE(x)
#define USBHS_BURSTSIZE_RXPBURST_MASK            USB_BURSTSIZE_RXPBURST_MASK
#define USBHS_BURSTSIZE_RXPBURST_SHIFT           USB_BURSTSIZE_RXPBURST_SHIFT
#define USBHS_BURSTSIZE_RXPBURST(x)              USB_BURSTSIZE_RXPBURST(x)
#define USBHS_BURSTSIZE_TXPBURST_MASK            USB_BURSTSIZE_TXPBURST_MASK
#define USBHS_BURSTSIZE_TXPBURST_SHIFT           USB_BURSTSIZE_TXPBURST_SHIFT
#define USBHS_BURSTSIZE_TXPBURST(x)              USB_BURSTSIZE_TXPBURST(x)
#define USBHS_TXFILLTUNING_TXSCHOH_MASK          USB_TXFILLTUNING_TXSCHOH_MASK
#define USBHS_TXFILLTUNING_TXSCHOH_SHIFT         USB_TXFILLTUNING_TXSCHOH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHOH(x)            USB_TXFILLTUNING_TXSCHOH(x)
#define USBHS_TXFILLTUNING_TXSCHHEALTH_MASK      USB_TXFILLTUNING_TXSCHHEALTH_MASK
#define USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT     USB_TXFILLTUNING_TXSCHHEALTH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHHEALTH(x)        USB_TXFILLTUNING_TXSCHHEALTH(x)
#define USBHS_TXFILLTUNING_TXFIFOTHRES_MASK      USB_TXFILLTUNING_TXFIFOTHRES_MASK
#define USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT     USB_TXFILLTUNING_TXFIFOTHRES_SHIFT
#define USBHS_TXFILLTUNING_TXFIFOTHRES(x)        USB_TXFILLTUNING_TXFIFOTHRES(x)
#define USBHS_ENDPTNAK_EPRN_MASK                 USB_ENDPTNAK_EPRN_MASK
#define USBHS_ENDPTNAK_EPRN_SHIFT                USB_ENDPTNAK_EPRN_SHIFT
#define USBHS_ENDPTNAK_EPRN(x)                   USB_ENDPTNAK_EPRN(x)
#define USBHS_ENDPTNAK_EPTN_MASK                 USB_ENDPTNAK_EPTN_MASK
#define USBHS_ENDPTNAK_EPTN_SHIFT                USB_ENDPTNAK_EPTN_SHIFT
#define USBHS_ENDPTNAK_EPTN(x)                   USB_ENDPTNAK_EPTN(x)
#define USBHS_ENDPTNAKEN_EPRNE_MASK              USB_ENDPTNAKEN_EPRNE_MASK
#define USBHS_ENDPTNAKEN_EPRNE_SHIFT             USB_ENDPTNAKEN_EPRNE_SHIFT
#define USBHS_ENDPTNAKEN_EPRNE(x)                USB_ENDPTNAKEN_EPRNE(x)
#define USBHS_ENDPTNAKEN_EPTNE_MASK              USB_ENDPTNAKEN_EPTNE_MASK
#define USBHS_ENDPTNAKEN_EPTNE_SHIFT             USB_ENDPTNAKEN_EPTNE_SHIFT
#define USBHS_ENDPTNAKEN_EPTNE(x)                USB_ENDPTNAKEN_EPTNE(x)
#define USBHS_CONFIGFLAG_CF_MASK                 USB_CONFIGFLAG_CF_MASK
#define USBHS_CONFIGFLAG_CF_SHIFT                USB_CONFIGFLAG_CF_SHIFT
#define USBHS_CONFIGFLAG_CF(x)                   USB_CONFIGFLAG_CF(x)
#define USBHS_PORTSC1_CCS_MASK                   USB_PORTSC1_CCS_MASK
#define USBHS_PORTSC1_CCS_SHIFT                  USB_PORTSC1_CCS_SHIFT
#define USBHS_PORTSC1_CCS(x)                     USB_PORTSC1_CCS(x)
#define USBHS_PORTSC1_CSC_MASK                   USB_PORTSC1_CSC_MASK
#define USBHS_PORTSC1_CSC_SHIFT                  USB_PORTSC1_CSC_SHIFT
#define USBHS_PORTSC1_CSC(x)                     USB_PORTSC1_CSC(x)
#define USBHS_PORTSC1_PE_MASK                    USB_PORTSC1_PE_MASK
#define USBHS_PORTSC1_PE_SHIFT                   USB_PORTSC1_PE_SHIFT
#define USBHS_PORTSC1_PE(x)                      USB_PORTSC1_PE(x)
#define USBHS_PORTSC1_PEC_MASK                   USB_PORTSC1_PEC_MASK
#define USBHS_PORTSC1_PEC_SHIFT                  USB_PORTSC1_PEC_SHIFT
#define USBHS_PORTSC1_PEC(x)                     USB_PORTSC1_PEC(x)
#define USBHS_PORTSC1_OCA_MASK                   USB_PORTSC1_OCA_MASK
#define USBHS_PORTSC1_OCA_SHIFT                  USB_PORTSC1_OCA_SHIFT
#define USBHS_PORTSC1_OCA(x)                     USB_PORTSC1_OCA(x)
#define USBHS_PORTSC1_OCC_MASK                   USB_PORTSC1_OCC_MASK
#define USBHS_PORTSC1_OCC_SHIFT                  USB_PORTSC1_OCC_SHIFT
#define USBHS_PORTSC1_OCC(x)                     USB_PORTSC1_OCC(x)
#define USBHS_PORTSC1_FPR_MASK                   USB_PORTSC1_FPR_MASK
#define USBHS_PORTSC1_FPR_SHIFT                  USB_PORTSC1_FPR_SHIFT
#define USBHS_PORTSC1_FPR(x)                     USB_PORTSC1_FPR(x)
#define USBHS_PORTSC1_SUSP_MASK                  USB_PORTSC1_SUSP_MASK
#define USBHS_PORTSC1_SUSP_SHIFT                 USB_PORTSC1_SUSP_SHIFT
#define USBHS_PORTSC1_SUSP(x)                    USB_PORTSC1_SUSP(x)
#define USBHS_PORTSC1_PR_MASK                    USB_PORTSC1_PR_MASK
#define USBHS_PORTSC1_PR_SHIFT                   USB_PORTSC1_PR_SHIFT
#define USBHS_PORTSC1_PR(x)                      USB_PORTSC1_PR(x)
#define USBHS_PORTSC1_HSP_MASK                   USB_PORTSC1_HSP_MASK
#define USBHS_PORTSC1_HSP_SHIFT                  USB_PORTSC1_HSP_SHIFT
#define USBHS_PORTSC1_HSP(x)                     USB_PORTSC1_HSP(x)
#define USBHS_PORTSC1_LS_MASK                    USB_PORTSC1_LS_MASK
#define USBHS_PORTSC1_LS_SHIFT                   USB_PORTSC1_LS_SHIFT
#define USBHS_PORTSC1_LS(x)                      USB_PORTSC1_LS(x)
#define USBHS_PORTSC1_PP_MASK                    USB_PORTSC1_PP_MASK
#define USBHS_PORTSC1_PP_SHIFT                   USB_PORTSC1_PP_SHIFT
#define USBHS_PORTSC1_PP(x)                      USB_PORTSC1_PP(x)
#define USBHS_PORTSC1_PO_MASK                    USB_PORTSC1_PO_MASK
#define USBHS_PORTSC1_PO_SHIFT                   USB_PORTSC1_PO_SHIFT
#define USBHS_PORTSC1_PO(x)                      USB_PORTSC1_PO(x)
#define USBHS_PORTSC1_PIC_MASK                   USB_PORTSC1_PIC_MASK
#define USBHS_PORTSC1_PIC_SHIFT                  USB_PORTSC1_PIC_SHIFT
#define USBHS_PORTSC1_PIC(x)                     USB_PORTSC1_PIC(x)
#define USBHS_PORTSC1_PTC_MASK                   USB_PORTSC1_PTC_MASK
#define USBHS_PORTSC1_PTC_SHIFT                  USB_PORTSC1_PTC_SHIFT
#define USBHS_PORTSC1_PTC(x)                     USB_PORTSC1_PTC(x)
#define USBHS_PORTSC1_WKCN_MASK                  USB_PORTSC1_WKCN_MASK
#define USBHS_PORTSC1_WKCN_SHIFT                 USB_PORTSC1_WKCN_SHIFT
#define USBHS_PORTSC1_WKCN(x)                    USB_PORTSC1_WKCN(x)
#define USBHS_PORTSC1_WKDS_MASK                  USB_PORTSC1_WKDC_MASK
#define USBHS_PORTSC1_WKDS_SHIFT                 USB_PORTSC1_WKDC_SHIFT
#define USBHS_PORTSC1_WKDS(x)                    USB_PORTSC1_WKDC(x)
#define USBHS_PORTSC1_WKOC_MASK                  USB_PORTSC1_WKOC_MASK
#define USBHS_PORTSC1_WKOC_SHIFT                 USB_PORTSC1_WKOC_SHIFT
#define USBHS_PORTSC1_WKOC(x)                    USB_PORTSC1_WKOC(x)
#define USBHS_PORTSC1_PHCD_MASK                  USB_PORTSC1_PHCD_MASK
#define USBHS_PORTSC1_PHCD_SHIFT                 USB_PORTSC1_PHCD_SHIFT
#define USBHS_PORTSC1_PHCD(x)                    USB_PORTSC1_PHCD(x)
#define USBHS_PORTSC1_PFSC_MASK                  USB_PORTSC1_PFSC_MASK
#define USBHS_PORTSC1_PFSC_SHIFT                 USB_PORTSC1_PFSC_SHIFT
#define USBHS_PORTSC1_PFSC(x)                    USB_PORTSC1_PFSC(x)
#define USBHS_PORTSC1_PTS2_MASK                  USB_PORTSC1_PTS_2_MASK
#define USBHS_PORTSC1_PTS2_SHIFT                 USB_PORTSC1_PTS_2_SHIFT
#define USBHS_PORTSC1_PTS2(x)                    USB_PORTSC1_PTS_2(x)
#define USBHS_PORTSC1_PSPD_MASK                  USB_PORTSC1_PSPD_MASK
#define USBHS_PORTSC1_PSPD_SHIFT                 USB_PORTSC1_PSPD_SHIFT
#define USBHS_PORTSC1_PSPD(x)                    USB_PORTSC1_PSPD(x)
#define USBHS_PORTSC1_PTW_MASK                   USB_PORTSC1_PTW_MASK
#define USBHS_PORTSC1_PTW_SHIFT                  USB_PORTSC1_PTW_SHIFT
#define USBHS_PORTSC1_PTW(x)                     USB_PORTSC1_PTW(x)
#define USBHS_PORTSC1_STS_MASK                   USB_PORTSC1_STS_MASK
#define USBHS_PORTSC1_STS_SHIFT                  USB_PORTSC1_STS_SHIFT
#define USBHS_PORTSC1_STS(x)                     USB_PORTSC1_STS(x)
#define USBHS_PORTSC1_PTS_MASK                   USB_PORTSC1_PTS_1_MASK
#define USBHS_PORTSC1_PTS_SHIFT                  USB_PORTSC1_PTS_1_SHIFT
#define USBHS_PORTSC1_PTS(x)                     USB_PORTSC1_PTS_1(x)
#define USBHS_OTGSC_VD_MASK                      USB_OTGSC_VD_MASK
#define USBHS_OTGSC_VD_SHIFT                     USB_OTGSC_VD_SHIFT
#define USBHS_OTGSC_VD(x)                        USB_OTGSC_VD(x)
#define USBHS_OTGSC_VC_MASK                      USB_OTGSC_VC_MASK
#define USBHS_OTGSC_VC_SHIFT                     USB_OTGSC_VC_SHIFT
#define USBHS_OTGSC_VC(x)                        USB_OTGSC_VC(x)
#define USBHS_OTGSC_OT_MASK                      USB_OTGSC_OT_MASK
#define USBHS_OTGSC_OT_SHIFT                     USB_OTGSC_OT_SHIFT
#define USBHS_OTGSC_OT(x)                        USB_OTGSC_OT(x)
#define USBHS_OTGSC_DP_MASK                      USB_OTGSC_DP_MASK
#define USBHS_OTGSC_DP_SHIFT                     USB_OTGSC_DP_SHIFT
#define USBHS_OTGSC_DP(x)                        USB_OTGSC_DP(x)
#define USBHS_OTGSC_IDPU_MASK                    USB_OTGSC_IDPU_MASK
#define USBHS_OTGSC_IDPU_SHIFT                   USB_OTGSC_IDPU_SHIFT
#define USBHS_OTGSC_IDPU(x)                      USB_OTGSC_IDPU(x)
#define USBHS_OTGSC_ID_MASK                      USB_OTGSC_ID_MASK
#define USBHS_OTGSC_ID_SHIFT                     USB_OTGSC_ID_SHIFT
#define USBHS_OTGSC_ID(x)                        USB_OTGSC_ID(x)
#define USBHS_OTGSC_AVV_MASK                     USB_OTGSC_AVV_MASK
#define USBHS_OTGSC_AVV_SHIFT                    USB_OTGSC_AVV_SHIFT
#define USBHS_OTGSC_AVV(x)                       USB_OTGSC_AVV(x)
#define USBHS_OTGSC_ASV_MASK                     USB_OTGSC_ASV_MASK
#define USBHS_OTGSC_ASV_SHIFT                    USB_OTGSC_ASV_SHIFT
#define USBHS_OTGSC_ASV(x)                       USB_OTGSC_ASV(x)
#define USBHS_OTGSC_BSV_MASK                     USB_OTGSC_BSV_MASK
#define USBHS_OTGSC_BSV_SHIFT                    USB_OTGSC_BSV_SHIFT
#define USBHS_OTGSC_BSV(x)                       USB_OTGSC_BSV(x)
#define USBHS_OTGSC_BSE_MASK                     USB_OTGSC_BSE_MASK
#define USBHS_OTGSC_BSE_SHIFT                    USB_OTGSC_BSE_SHIFT
#define USBHS_OTGSC_BSE(x)                       USB_OTGSC_BSE(x)
#define USBHS_OTGSC_MST_MASK                     USB_OTGSC_TOG_1MS_MASK
#define USBHS_OTGSC_MST_SHIFT                    USB_OTGSC_TOG_1MS_SHIFT
#define USBHS_OTGSC_MST(x)                       USB_OTGSC_TOG_1MS(x)
#define USBHS_OTGSC_DPS_MASK                     USB_OTGSC_DPS_MASK
#define USBHS_OTGSC_DPS_SHIFT                    USB_OTGSC_DPS_SHIFT
#define USBHS_OTGSC_DPS(x)                       USB_OTGSC_DPS(x)
#define USBHS_OTGSC_IDIS_MASK                    USB_OTGSC_IDIS_MASK
#define USBHS_OTGSC_IDIS_SHIFT                   USB_OTGSC_IDIS_SHIFT
#define USBHS_OTGSC_IDIS(x)                      USB_OTGSC_IDIS(x)
#define USBHS_OTGSC_AVVIS_MASK                   USB_OTGSC_AVVIS_MASK
#define USBHS_OTGSC_AVVIS_SHIFT                  USB_OTGSC_AVVIS_SHIFT
#define USBHS_OTGSC_AVVIS(x)                     USB_OTGSC_AVVIS(x)
#define USBHS_OTGSC_ASVIS_MASK                   USB_OTGSC_ASVIS_MASK
#define USBHS_OTGSC_ASVIS_SHIFT                  USB_OTGSC_ASVIS_SHIFT
#define USBHS_OTGSC_ASVIS(x)                     USB_OTGSC_ASVIS(x)
#define USBHS_OTGSC_BSVIS_MASK                   USB_OTGSC_BSVIS_MASK
#define USBHS_OTGSC_BSVIS_SHIFT                  USB_OTGSC_BSVIS_SHIFT
#define USBHS_OTGSC_BSVIS(x)                     USB_OTGSC_BSVIS(x)
#define USBHS_OTGSC_BSEIS_MASK                   USB_OTGSC_BSEIS_MASK
#define USBHS_OTGSC_BSEIS_SHIFT                  USB_OTGSC_BSEIS_SHIFT
#define USBHS_OTGSC_BSEIS(x)                     USB_OTGSC_BSEIS(x)
#define USBHS_OTGSC_MSS_MASK                     USB_OTGSC_STATUS_1MS_MASK
#define USBHS_OTGSC_MSS_SHIFT                    USB_OTGSC_STATUS_1MS_SHIFT
#define USBHS_OTGSC_MSS(x)                       USB_OTGSC_STATUS_1MS(x)
#define USBHS_OTGSC_DPIS_MASK                    USB_OTGSC_DPIS_MASK
#define USBHS_OTGSC_DPIS_SHIFT                   USB_OTGSC_DPIS_SHIFT
#define USBHS_OTGSC_DPIS(x)                      USB_OTGSC_DPIS(x)
#define USBHS_OTGSC_IDIE_MASK                    USB_OTGSC_IDIE_MASK
#define USBHS_OTGSC_IDIE_SHIFT                   USB_OTGSC_IDIE_SHIFT
#define USBHS_OTGSC_IDIE(x)                      USB_OTGSC_IDIE(x)
#define USBHS_OTGSC_AVVIE_MASK                   USB_OTGSC_AVVIE_MASK
#define USBHS_OTGSC_AVVIE_SHIFT                  USB_OTGSC_AVVIE_SHIFT
#define USBHS_OTGSC_AVVIE(x)                     USB_OTGSC_AVVIE(x)
#define USBHS_OTGSC_ASVIE_MASK                   USB_OTGSC_ASVIE_MASK
#define USBHS_OTGSC_ASVIE_SHIFT                  USB_OTGSC_ASVIE_SHIFT
#define USBHS_OTGSC_ASVIE(x)                     USB_OTGSC_ASVIE(x)
#define USBHS_OTGSC_BSVIE_MASK                   USB_OTGSC_BSVIE_MASK
#define USBHS_OTGSC_BSVIE_SHIFT                  USB_OTGSC_BSVIE_SHIFT
#define USBHS_OTGSC_BSVIE(x)                     USB_OTGSC_BSVIE(x)
#define USBHS_OTGSC_BSEIE_MASK                   USB_OTGSC_BSEIE_MASK
#define USBHS_OTGSC_BSEIE_SHIFT                  USB_OTGSC_BSEIE_SHIFT
#define USBHS_OTGSC_BSEIE(x)                     USB_OTGSC_BSEIE(x)
#define USBHS_OTGSC_MSE_MASK                     USB_OTGSC_EN_1MS_MASK
#define USBHS_OTGSC_MSE_SHIFT                    USB_OTGSC_EN_1MS_SHIFT
#define USBHS_OTGSC_MSE(x)                       USB_OTGSC_EN_1MS(x)
#define USBHS_OTGSC_DPIE_MASK                    USB_OTGSC_DPIE_MASK
#define USBHS_OTGSC_DPIE_SHIFT                   USB_OTGSC_DPIE_SHIFT
#define USBHS_OTGSC_DPIE(x)                      USB_OTGSC_DPIE(x)
#define USBHS_USBMODE_CM_MASK                    USB_USBMODE_CM_MASK
#define USBHS_USBMODE_CM_SHIFT                   USB_USBMODE_CM_SHIFT
#define USBHS_USBMODE_CM(x)                      USB_USBMODE_CM(x)
#define USBHS_USBMODE_ES_MASK                    USB_USBMODE_ES_MASK
#define USBHS_USBMODE_ES_SHIFT                   USB_USBMODE_ES_SHIFT
#define USBHS_USBMODE_ES(x)                      USB_USBMODE_ES(x)
#define USBHS_USBMODE_SLOM_MASK                  USB_USBMODE_SLOM_MASK
#define USBHS_USBMODE_SLOM_SHIFT                 USB_USBMODE_SLOM_SHIFT
#define USBHS_USBMODE_SLOM(x)                    USB_USBMODE_SLOM(x)
#define USBHS_USBMODE_SDIS_MASK                  USB_USBMODE_SDIS_MASK
#define USBHS_USBMODE_SDIS_SHIFT                 USB_USBMODE_SDIS_SHIFT
#define USBHS_USBMODE_SDIS(x)                    USB_USBMODE_SDIS(x)
#define USBHS_EPSETUPSR_EPSETUPSTAT_MASK         USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK
#define USBHS_EPSETUPSR_EPSETUPSTAT_SHIFT        USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT
#define USBHS_EPSETUPSR_EPSETUPSTAT(x)           USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)
#define USBHS_EPPRIME_PERB_MASK                  USB_ENDPTPRIME_PERB_MASK
#define USBHS_EPPRIME_PERB_SHIFT                 USB_ENDPTPRIME_PERB_SHIFT
#define USBHS_EPPRIME_PERB(x)                    USB_ENDPTPRIME_PERB(x)
#define USBHS_EPPRIME_PETB_MASK                  USB_ENDPTPRIME_PETB_MASK
#define USBHS_EPPRIME_PETB_SHIFT                 USB_ENDPTPRIME_PETB_SHIFT
#define USBHS_EPPRIME_PETB(x)                    USB_ENDPTPRIME_PETB(x)
#define USBHS_EPFLUSH_FERB_MASK                  USB_ENDPTFLUSH_FERB_MASK
#define USBHS_EPFLUSH_FERB_SHIFT                 USB_ENDPTFLUSH_FERB_SHIFT
#define USBHS_EPFLUSH_FERB(x)                    USB_ENDPTFLUSH_FERB(x)
#define USBHS_EPFLUSH_FETB_MASK                  USB_ENDPTFLUSH_FETB_MASK
#define USBHS_EPFLUSH_FETB_SHIFT                 USB_ENDPTFLUSH_FETB_SHIFT
#define USBHS_EPFLUSH_FETB(x)                    USB_ENDPTFLUSH_FETB(x)
#define USBHS_EPSR_ERBR_MASK                     USB_ENDPTSTAT_ERBR_MASK
#define USBHS_EPSR_ERBR_SHIFT                    USB_ENDPTSTAT_ERBR_SHIFT
#define USBHS_EPSR_ERBR(x)                       USB_ENDPTSTAT_ERBR(x)
#define USBHS_EPSR_ETBR_MASK                     USB_ENDPTSTAT_ETBR_MASK
#define USBHS_EPSR_ETBR_SHIFT                    USB_ENDPTSTAT_ETBR_SHIFT
#define USBHS_EPSR_ETBR(x)                       USB_ENDPTSTAT_ETBR(x)
#define USBHS_EPCOMPLETE_ERCE_MASK               USB_ENDPTCOMPLETE_ERCE_MASK
#define USBHS_EPCOMPLETE_ERCE_SHIFT              USB_ENDPTCOMPLETE_ERCE_SHIFT
#define USBHS_EPCOMPLETE_ERCE(x)                 USB_ENDPTCOMPLETE_ERCE(x)
#define USBHS_EPCOMPLETE_ETCE_MASK               USB_ENDPTCOMPLETE_ETCE_MASK
#define USBHS_EPCOMPLETE_ETCE_SHIFT              USB_ENDPTCOMPLETE_ETCE_SHIFT
#define USBHS_EPCOMPLETE_ETCE(x)                 USB_ENDPTCOMPLETE_ETCE(x)
#define USBHS_EPCR0_RXS_MASK                     USB_ENDPTCTRL0_RXS_MASK
#define USBHS_EPCR0_RXS_SHIFT                    USB_ENDPTCTRL0_RXS_SHIFT
#define USBHS_EPCR0_RXS(x)                       USB_ENDPTCTRL0_RXS(x)
#define USBHS_EPCR0_RXT_MASK                     USB_ENDPTCTRL0_RXT_MASK
#define USBHS_EPCR0_RXT_SHIFT                    USB_ENDPTCTRL0_RXT_SHIFT
#define USBHS_EPCR0_RXT(x)                       USB_ENDPTCTRL0_RXT(x)
#define USBHS_EPCR0_RXE_MASK                     USB_ENDPTCTRL0_RXE_MASK
#define USBHS_EPCR0_RXE_SHIFT                    USB_ENDPTCTRL0_RXE_SHIFT
#define USBHS_EPCR0_RXE(x)                       USB_ENDPTCTRL0_RXE(x)
#define USBHS_EPCR0_TXS_MASK                     USB_ENDPTCTRL0_TXS_MASK
#define USBHS_EPCR0_TXS_SHIFT                    USB_ENDPTCTRL0_TXS_SHIFT
#define USBHS_EPCR0_TXS(x)                       USB_ENDPTCTRL0_TXS(x)
#define USBHS_EPCR0_TXT_MASK                     USB_ENDPTCTRL0_TXT_MASK
#define USBHS_EPCR0_TXT_SHIFT                    USB_ENDPTCTRL0_TXT_SHIFT
#define USBHS_EPCR0_TXT(x)                       USB_ENDPTCTRL0_TXT(x)
#define USBHS_EPCR0_TXE_MASK                     USB_ENDPTCTRL0_TXE_MASK
#define USBHS_EPCR0_TXE_SHIFT                    USB_ENDPTCTRL0_TXE_SHIFT
#define USBHS_EPCR0_TXE(x)                       USB_ENDPTCTRL0_TXE(x)
#define USBHS_EPCR_RXS_MASK                      USB_ENDPTCTRL_RXS_MASK
#define USBHS_EPCR_RXS_SHIFT                     USB_ENDPTCTRL_RXS_SHIFT
#define USBHS_EPCR_RXS(x)                        USB_ENDPTCTRL_RXS(x)
#define USBHS_EPCR_RXD_MASK                      USB_ENDPTCTRL_RXD_MASK
#define USBHS_EPCR_RXD_SHIFT                     USB_ENDPTCTRL_RXD_SHIFT
#define USBHS_EPCR_RXD(x)                        USB_ENDPTCTRL_RXD(x)
#define USBHS_EPCR_RXT_MASK                      USB_ENDPTCTRL_RXT_MASK
#define USBHS_EPCR_RXT_SHIFT                     USB_ENDPTCTRL_RXT_SHIFT
#define USBHS_EPCR_RXT(x)                        USB_ENDPTCTRL_RXT(x)
#define USBHS_EPCR_RXI_MASK                      USB_ENDPTCTRL_RXI_MASK
#define USBHS_EPCR_RXI_SHIFT                     USB_ENDPTCTRL_RXI_SHIFT
#define USBHS_EPCR_RXI(x)                        USB_ENDPTCTRL_RXI(x)
#define USBHS_EPCR_RXR_MASK                      USB_ENDPTCTRL_RXR_MASK
#define USBHS_EPCR_RXR_SHIFT                     USB_ENDPTCTRL_RXR_SHIFT
#define USBHS_EPCR_RXR(x)                        USB_ENDPTCTRL_RXR(x)
#define USBHS_EPCR_RXE_MASK                      USB_ENDPTCTRL_RXE_MASK
#define USBHS_EPCR_RXE_SHIFT                     USB_ENDPTCTRL_RXE_SHIFT
#define USBHS_EPCR_RXE(x)                        USB_ENDPTCTRL_RXE(x)
#define USBHS_EPCR_TXS_MASK                      USB_ENDPTCTRL_TXS_MASK
#define USBHS_EPCR_TXS_SHIFT                     USB_ENDPTCTRL_TXS_SHIFT
#define USBHS_EPCR_TXS(x)                        USB_ENDPTCTRL_TXS(x)
#define USBHS_EPCR_TXD_MASK                      USB_ENDPTCTRL_TXD_MASK
#define USBHS_EPCR_TXD_SHIFT                     USB_ENDPTCTRL_TXD_SHIFT
#define USBHS_EPCR_TXD(x)                        USB_ENDPTCTRL_TXD(x)
#define USBHS_EPCR_TXT_MASK                      USB_ENDPTCTRL_TXT_MASK
#define USBHS_EPCR_TXT_SHIFT                     USB_ENDPTCTRL_TXT_SHIFT
#define USBHS_EPCR_TXT(x)                        USB_ENDPTCTRL_TXT(x)
#define USBHS_EPCR_TXI_MASK                      USB_ENDPTCTRL_TXI_MASK
#define USBHS_EPCR_TXI_SHIFT                     USB_ENDPTCTRL_TXI_SHIFT
#define USBHS_EPCR_TXI(x)                        USB_ENDPTCTRL_TXI(x)
#define USBHS_EPCR_TXR_MASK                      USB_ENDPTCTRL_TXR_MASK
#define USBHS_EPCR_TXR_SHIFT                     USB_ENDPTCTRL_TXR_SHIFT
#define USBHS_EPCR_TXR(x)                        USB_ENDPTCTRL_TXR(x)
#define USBHS_EPCR_TXE_MASK                      USB_ENDPTCTRL_TXE_MASK
#define USBHS_EPCR_TXE_SHIFT                     USB_ENDPTCTRL_TXE_SHIFT
#define USBHS_EPCR_TXE(x)                        USB_ENDPTCTRL_TXE(x)
#define USBHS_EPCR_COUNT                         USB_ENDPTCTRL_COUNT
#define USBHS_Type                               USB_Type
#define USBHS_BASE_ADDRS                         { USB_BASE }
#define USBHS_IRQS                               { USB_OTG1_IRQn }
#define USBHS_IRQHandler                         USB_OTG1_IRQHandler


/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USBNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Peripheral_Access_Layer USBNC Peripheral Access Layer
 * @{
 */

/** USBNC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __IO uint32_t USB_OTGn_CTRL;                     /**< USB OTG1 Control Register, offset: 0x800 */
       uint8_t RESERVED_1[20];
  __IO uint32_t USB_OTGn_PHY_CTRL_0;               /**< OTG1 UTMI PHY Control 0 Register, offset: 0x818 */
} USBNC_Type;


/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC base address */
#define USBNC_BASE                               (0x400E4000u)
/** Peripheral USBNC base pointer */
#define USBNC                                    ((USBNC_Type *)USBNC_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { 0u, USBNC_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { (USBNC_Type *)0u, USBNC }

/*!
 * @}
 */ /* end of group USBNC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USBPHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Peripheral_Access_Layer USBPHY Peripheral Access Layer
 * @{
 */

/** USBPHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PWD;                               /**< USB PHY Power-Down Register, offset: 0x0 */
  __IO uint32_t PWD_SET;                           /**< USB PHY Power-Down Register, offset: 0x4 */
  __IO uint32_t PWD_CLR;                           /**< USB PHY Power-Down Register, offset: 0x8 */
  __IO uint32_t PWD_TOG;                           /**< USB PHY Power-Down Register, offset: 0xC */
  __IO uint32_t TX;                                /**< USB PHY Transmitter Control Register, offset: 0x10 */
  __IO uint32_t TX_SET;                            /**< USB PHY Transmitter Control Register, offset: 0x14 */
  __IO uint32_t TX_CLR;                            /**< USB PHY Transmitter Control Register, offset: 0x18 */
  __IO uint32_t TX_TOG;                            /**< USB PHY Transmitter Control Register, offset: 0x1C */
  __IO uint32_t RX;                                /**< USB PHY Receiver Control Register, offset: 0x20 */
  __IO uint32_t RX_SET;                            /**< USB PHY Receiver Control Register, offset: 0x24 */
  __IO uint32_t RX_CLR;                            /**< USB PHY Receiver Control Register, offset: 0x28 */
  __IO uint32_t RX_TOG;                            /**< USB PHY Receiver Control Register, offset: 0x2C */
  __IO uint32_t CTRL;                              /**< USB PHY General Control Register, offset: 0x30 */
  __IO uint32_t CTRL_SET;                          /**< USB PHY General Control Register, offset: 0x34 */
  __IO uint32_t CTRL_CLR;                          /**< USB PHY General Control Register, offset: 0x38 */
  __IO uint32_t CTRL_TOG;                          /**< USB PHY General Control Register, offset: 0x3C */
  __IO uint32_t STATUS;                            /**< USB PHY Status Register, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DEBUGr;                            /**< USB PHY Debug Register, offset: 0x50 */
  __IO uint32_t DEBUG_SET;                         /**< USB PHY Debug Register, offset: 0x54 */
  __IO uint32_t DEBUG_CLR;                         /**< USB PHY Debug Register, offset: 0x58 */
  __IO uint32_t DEBUG_TOG;                         /**< USB PHY Debug Register, offset: 0x5C */
  __I  uint32_t DEBUG0_STATUS;                     /**< UTMI Debug Status Register 0, offset: 0x60 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DEBUG1;                            /**< UTMI Debug Status Register 1, offset: 0x70 */
  __IO uint32_t DEBUG1_SET;                        /**< UTMI Debug Status Register 1, offset: 0x74 */
  __IO uint32_t DEBUG1_CLR;                        /**< UTMI Debug Status Register 1, offset: 0x78 */
  __IO uint32_t DEBUG1_TOG;                        /**< UTMI Debug Status Register 1, offset: 0x7C */
  __I  uint32_t VERSION;                           /**< UTMI RTL Version, offset: 0x80 */
} USBPHY_Type;


/* ----------------------------------------------------------------------------
   -- USB_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_ANALOG_Peripheral_Access_Layer USB_ANALOG Peripheral Access Layer
 * @{
 */

/** USB_ANALOG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[416];
  struct {                                         /* offset: 0x1A0, array step: 0x60 */
    __IO uint32_t VBUS_DETECT;                       /**< USB VBUS Detect Register, array offset: 0x1A0, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_SET;                   /**< USB VBUS Detect Register, array offset: 0x1A4, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_CLR;                   /**< USB VBUS Detect Register, array offset: 0x1A8, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_TOG;                   /**< USB VBUS Detect Register, array offset: 0x1AC, array step: 0x60 */
    __IO uint32_t CHRG_DETECT;                       /**< USB Charger Detect Register, array offset: 0x1B0, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_SET;                   /**< USB Charger Detect Register, array offset: 0x1B4, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_CLR;                   /**< USB Charger Detect Register, array offset: 0x1B8, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_TOG;                   /**< USB Charger Detect Register, array offset: 0x1BC, array step: 0x60 */
    __I  uint32_t VBUS_DETECT_STAT;                  /**< USB VBUS Detect Status Register, array offset: 0x1C0, array step: 0x60 */
         uint8_t RESERVED_0[12];
    __I  uint32_t CHRG_DETECT_STAT;                  /**< USB Charger Detect Status Register, array offset: 0x1D0, array step: 0x60 */
         uint8_t RESERVED_1[12];
    __IO uint32_t LOOPBACK;                          /**< USB Loopback Test Register, array offset: 0x1E0, array step: 0x60 */
    __IO uint32_t LOOPBACK_SET;                      /**< USB Loopback Test Register, array offset: 0x1E4, array step: 0x60 */
    __IO uint32_t LOOPBACK_CLR;                      /**< USB Loopback Test Register, array offset: 0x1E8, array step: 0x60 */
    __IO uint32_t LOOPBACK_TOG;                      /**< USB Loopback Test Register, array offset: 0x1EC, array step: 0x60 */
    __IO uint32_t MISC;                              /**< USB Misc Register, array offset: 0x1F0, array step: 0x60 */
    __IO uint32_t MISC_SET;                          /**< USB Misc Register, array offset: 0x1F4, array step: 0x60 */
    __IO uint32_t MISC_CLR;                          /**< USB Misc Register, array offset: 0x1F8, array step: 0x60 */
    __IO uint32_t MISC_TOG;                          /**< USB Misc Register, array offset: 0x1FC, array step: 0x60 */
  } INSTANCE[1];
       uint8_t RESERVED_1[96];
  __I  uint32_t DIGPROG;                           /**< Chip Silicon Version, offset: 0x260 */
} USB_ANALOG_Type;


/* USB_ANALOG - Peripheral instance base addresses */
/** Peripheral USB_ANALOG base address */
#define USB_ANALOG_BASE                          (0x400D8000u)
/** Peripheral USB_ANALOG base pointer */
#define USB_ANALOG                               ((USB_ANALOG_Type *)USB_ANALOG_BASE)
/** Array initializer of USB_ANALOG peripheral base addresses */
#define USB_ANALOG_BASE_ADDRS                    { USB_ANALOG_BASE }
/** Array initializer of USB_ANALOG peripheral base pointers */
#define USB_ANALOG_BASE_PTRS                     { USB_ANALOG }

/*!
 * @}
 */ /* end of group USB_ANALOG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint16_t WCR;                               /**< Watchdog Control Register, offset: 0x0 */
  __IO uint16_t WSR;                               /**< Watchdog Service Register, offset: 0x2 */
  __I  uint16_t WRSR;                              /**< Watchdog Reset Status Register, offset: 0x4 */
  __IO uint16_t WICR;                              /**< Watchdog Interrupt Control Register, offset: 0x6 */
  __IO uint16_t WMCR;                              /**< Watchdog Miscellaneous Control Register, offset: 0x8 */
} WDOG_Type;


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x400B8000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x400D0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { 0u, WDOG1_BASE, WDOG2_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { (WDOG_Type *)0u, WDOG1, WDOG2 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { NotAvail_IRQn, WDOG1_IRQn, WDOG2_IRQn }

/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- XBARA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Peripheral_Access_Layer XBARA Peripheral Access Layer
 * @{
 */

/** XBARA - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar A Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar A Select Register 1, offset: 0x2 */
  __IO uint16_t SEL2;                              /**< Crossbar A Select Register 2, offset: 0x4 */
  __IO uint16_t SEL3;                              /**< Crossbar A Select Register 3, offset: 0x6 */
  __IO uint16_t SEL4;                              /**< Crossbar A Select Register 4, offset: 0x8 */
  __IO uint16_t SEL5;                              /**< Crossbar A Select Register 5, offset: 0xA */
  __IO uint16_t SEL6;                              /**< Crossbar A Select Register 6, offset: 0xC */
  __IO uint16_t SEL7;                              /**< Crossbar A Select Register 7, offset: 0xE */
  __IO uint16_t SEL8;                              /**< Crossbar A Select Register 8, offset: 0x10 */
  __IO uint16_t SEL9;                              /**< Crossbar A Select Register 9, offset: 0x12 */
  __IO uint16_t SEL10;                             /**< Crossbar A Select Register 10, offset: 0x14 */
  __IO uint16_t SEL11;                             /**< Crossbar A Select Register 11, offset: 0x16 */
  __IO uint16_t SEL12;                             /**< Crossbar A Select Register 12, offset: 0x18 */
  __IO uint16_t SEL13;                             /**< Crossbar A Select Register 13, offset: 0x1A */
  __IO uint16_t SEL14;                             /**< Crossbar A Select Register 14, offset: 0x1C */
  __IO uint16_t SEL15;                             /**< Crossbar A Select Register 15, offset: 0x1E */
  __IO uint16_t SEL16;                             /**< Crossbar A Select Register 16, offset: 0x20 */
  __IO uint16_t SEL17;                             /**< Crossbar A Select Register 17, offset: 0x22 */
  __IO uint16_t SEL18;                             /**< Crossbar A Select Register 18, offset: 0x24 */
  __IO uint16_t SEL19;                             /**< Crossbar A Select Register 19, offset: 0x26 */
  __IO uint16_t SEL20;                             /**< Crossbar A Select Register 20, offset: 0x28 */
  __IO uint16_t SEL21;                             /**< Crossbar A Select Register 21, offset: 0x2A */
  __IO uint16_t SEL22;                             /**< Crossbar A Select Register 22, offset: 0x2C */
  __IO uint16_t SEL23;                             /**< Crossbar A Select Register 23, offset: 0x2E */
  __IO uint16_t SEL24;                             /**< Crossbar A Select Register 24, offset: 0x30 */
  __IO uint16_t SEL25;                             /**< Crossbar A Select Register 25, offset: 0x32 */
  __IO uint16_t SEL26;                             /**< Crossbar A Select Register 26, offset: 0x34 */
  __IO uint16_t SEL27;                             /**< Crossbar A Select Register 27, offset: 0x36 */
  __IO uint16_t SEL28;                             /**< Crossbar A Select Register 28, offset: 0x38 */
  __IO uint16_t SEL29;                             /**< Crossbar A Select Register 29, offset: 0x3A */
  __IO uint16_t SEL30;                             /**< Crossbar A Select Register 30, offset: 0x3C */
  __IO uint16_t SEL31;                             /**< Crossbar A Select Register 31, offset: 0x3E */
  __IO uint16_t SEL32;                             /**< Crossbar A Select Register 32, offset: 0x40 */
  __IO uint16_t SEL33;                             /**< Crossbar A Select Register 33, offset: 0x42 */
  __IO uint16_t SEL34;                             /**< Crossbar A Select Register 34, offset: 0x44 */
  __IO uint16_t SEL35;                             /**< Crossbar A Select Register 35, offset: 0x46 */
  __IO uint16_t SEL36;                             /**< Crossbar A Select Register 36, offset: 0x48 */
  __IO uint16_t SEL37;                             /**< Crossbar A Select Register 37, offset: 0x4A */
  __IO uint16_t SEL38;                             /**< Crossbar A Select Register 38, offset: 0x4C */
  __IO uint16_t SEL39;                             /**< Crossbar A Select Register 39, offset: 0x4E */
  __IO uint16_t SEL40;                             /**< Crossbar A Select Register 40, offset: 0x50 */
  __IO uint16_t SEL41;                             /**< Crossbar A Select Register 41, offset: 0x52 */
  __IO uint16_t SEL42;                             /**< Crossbar A Select Register 42, offset: 0x54 */
  __IO uint16_t SEL43;                             /**< Crossbar A Select Register 43, offset: 0x56 */
  __IO uint16_t SEL44;                             /**< Crossbar A Select Register 44, offset: 0x58 */
  __IO uint16_t SEL45;                             /**< Crossbar A Select Register 45, offset: 0x5A */
  __IO uint16_t SEL46;                             /**< Crossbar A Select Register 46, offset: 0x5C */
  __IO uint16_t SEL47;                             /**< Crossbar A Select Register 47, offset: 0x5E */
  __IO uint16_t SEL48;                             /**< Crossbar A Select Register 48, offset: 0x60 */
  __IO uint16_t SEL49;                             /**< Crossbar A Select Register 49, offset: 0x62 */
  __IO uint16_t SEL50;                             /**< Crossbar A Select Register 50, offset: 0x64 */
  __IO uint16_t SEL51;                             /**< Crossbar A Select Register 51, offset: 0x66 */
  __IO uint16_t SEL52;                             /**< Crossbar A Select Register 52, offset: 0x68 */
  __IO uint16_t SEL53;                             /**< Crossbar A Select Register 53, offset: 0x6A */
  __IO uint16_t SEL54;                             /**< Crossbar A Select Register 54, offset: 0x6C */
  __IO uint16_t SEL55;                             /**< Crossbar A Select Register 55, offset: 0x6E */
  __IO uint16_t SEL56;                             /**< Crossbar A Select Register 56, offset: 0x70 */
  __IO uint16_t SEL57;                             /**< Crossbar A Select Register 57, offset: 0x72 */
  __IO uint16_t SEL58;                             /**< Crossbar A Select Register 58, offset: 0x74 */
  __IO uint16_t SEL59;                             /**< Crossbar A Select Register 59, offset: 0x76 */
  __IO uint16_t SEL60;                             /**< Crossbar A Select Register 60, offset: 0x78 */
  __IO uint16_t SEL61;                             /**< Crossbar A Select Register 61, offset: 0x7A */
  __IO uint16_t SEL62;                             /**< Crossbar A Select Register 62, offset: 0x7C */
  __IO uint16_t SEL63;                             /**< Crossbar A Select Register 63, offset: 0x7E */
  __IO uint16_t SEL64;                             /**< Crossbar A Select Register 64, offset: 0x80 */
  __IO uint16_t SEL65;                             /**< Crossbar A Select Register 65, offset: 0x82 */
  __IO uint16_t CTRL0;                             /**< Crossbar A Control Register 0, offset: 0x84 */
  __IO uint16_t CTRL1;                             /**< Crossbar A Control Register 1, offset: 0x86 */
} XBARA_Type;


/* XBARA - Peripheral instance base addresses */
/** Peripheral XBARA base address */
#define XBARA_BASE                               (0x40098000u)
/** Peripheral XBARA base pointer */
#define XBARA                                    ((XBARA_Type *)XBARA_BASE)
/** Array initializer of XBARA peripheral base addresses */
#define XBARA_BASE_ADDRS                         { XBARA_BASE }
/** Array initializer of XBARA peripheral base pointers */
#define XBARA_BASE_PTRS                          { XBARA }

/*!
 * @}
 */ /* end of group XBARA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- XTALOSC24M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XTALOSC24M_Peripheral_Access_Layer XTALOSC24M Peripheral Access Layer
 * @{
 */

/** XTALOSC24M - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[336];
  __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
       uint8_t RESERVED_1[272];
  __IO uint32_t LOWPWR_CTRL;                       /**< XTAL OSC (LP) Control Register, offset: 0x270 */
  __IO uint32_t LOWPWR_CTRL_SET;                   /**< XTAL OSC (LP) Control Register, offset: 0x274 */
  __IO uint32_t LOWPWR_CTRL_CLR;                   /**< XTAL OSC (LP) Control Register, offset: 0x278 */
  __IO uint32_t LOWPWR_CTRL_TOG;                   /**< XTAL OSC (LP) Control Register, offset: 0x27C */
       uint8_t RESERVED_2[32];
  __IO uint32_t OSC_CONFIG0;                       /**< XTAL OSC Configuration 0 Register, offset: 0x2A0 */
  __IO uint32_t OSC_CONFIG0_SET;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2A4 */
  __IO uint32_t OSC_CONFIG0_CLR;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2A8 */
  __IO uint32_t OSC_CONFIG0_TOG;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2AC */
  __IO uint32_t OSC_CONFIG1;                       /**< XTAL OSC Configuration 1 Register, offset: 0x2B0 */
  __IO uint32_t OSC_CONFIG1_SET;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2B4 */
  __IO uint32_t OSC_CONFIG1_CLR;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2B8 */
  __IO uint32_t OSC_CONFIG1_TOG;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2BC */
  __IO uint32_t OSC_CONFIG2;                       /**< XTAL OSC Configuration 2 Register, offset: 0x2C0 */
  __IO uint32_t OSC_CONFIG2_SET;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2C4 */
  __IO uint32_t OSC_CONFIG2_CLR;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2C8 */
  __IO uint32_t OSC_CONFIG2_TOG;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2CC */
} XTALOSC24M_Type;


/* XTALOSC24M - Peripheral instance base addresses */
/** Peripheral XTALOSC24M base address */
#define XTALOSC24M_BASE                          (0x400D8000u)
/** Peripheral XTALOSC24M base pointer */
#define XTALOSC24M                               ((XTALOSC24M_Type *)XTALOSC24M_BASE)
/** Array initializer of XTALOSC24M peripheral base addresses */
#define XTALOSC24M_BASE_ADDRS                    { XTALOSC24M_BASE }
/** Array initializer of XTALOSC24M peripheral base pointers */
#define XTALOSC24M_BASE_PTRS                     { XTALOSC24M }

/*!
 * @}
 */ /* end of group XTALOSC24M_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* _MIMXRT1011_H_ */

