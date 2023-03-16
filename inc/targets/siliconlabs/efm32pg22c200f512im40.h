/**************************************************************************//**
 * @file
 * @brief CMSIS Cortex-M Peripheral Access Layer Header File
 *        for EFM32PG22C200F512IM40
 ******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories, Inc. www.silabs.com</b>
 ******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *****************************************************************************/
#ifndef EFM32PG22C200F512IM40_H
#define EFM32PG22C200F512IM40_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************//**
 * @addtogroup Parts
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @defgroup EFM32PG22C200F512IM40 EFM32PG22C200F512IM40
 * @{
 *****************************************************************************/

/** Interrupt Number Definition */
typedef enum IRQn{
  /******  Cortex-M Processor Exceptions Numbers ******************************************/
  NonMaskableInt_IRQn    = -14,             /*!< -14 Cortex-M Non Maskable Interrupt      */
  HardFault_IRQn         = -13,             /*!< -13 Cortex-M Hard Fault Interrupt        */
  MemoryManagement_IRQn  = -12,             /*!< -12 Cortex-M Memory Management Interrupt */
  BusFault_IRQn          = -11,             /*!< -11 Cortex-M Bus Fault Interrupt         */
  UsageFault_IRQn        = -10,             /*!< -10 Cortex-M Usage Fault Interrupt       */
  SVCall_IRQn            = -5,              /*!< -5  Cortex-M SV Call Interrupt           */
  DebugMonitor_IRQn      = -4,              /*!< -4  Cortex-M Debug Monitor Interrupt     */
  PendSV_IRQn            = -2,              /*!< -2  Cortex-M Pend SV Interrupt           */
  SysTick_IRQn           = -1,              /*!< -1  Cortex-M System Tick Interrupt       */

  /******  EFM32PG22 Peripheral Interrupt Numbers ******************************************/

  CRYPTOACC_IRQn         = 0,  /*!<  0 EFM32 CRYPTOACC Interrupt */
  TRNG_IRQn              = 1,  /*!<  1 EFM32 TRNG Interrupt */
  PKE_IRQn               = 2,  /*!<  2 EFM32 PKE Interrupt */
  SMU_SECURE_IRQn        = 3,  /*!<  3 EFM32 SMU_SECURE Interrupt */
  SMU_S_PRIVILEGED_IRQn  = 4,  /*!<  4 EFM32 SMU_S_PRIVILEGED Interrupt */
  SMU_NS_PRIVILEGED_IRQn = 5,  /*!<  5 EFM32 SMU_NS_PRIVILEGED Interrupt */
  EMU_IRQn               = 6,  /*!<  6 EFM32 EMU Interrupt */
  TIMER0_IRQn            = 7,  /*!<  7 EFM32 TIMER0 Interrupt */
  TIMER1_IRQn            = 8,  /*!<  8 EFM32 TIMER1 Interrupt */
  TIMER2_IRQn            = 9,  /*!<  9 EFM32 TIMER2 Interrupt */
  TIMER3_IRQn            = 10, /*!< 10 EFM32 TIMER3 Interrupt */
  TIMER4_IRQn            = 11, /*!< 11 EFM32 TIMER4 Interrupt */
  RTCC_IRQn              = 12, /*!< 12 EFM32 RTCC Interrupt */
  USART0_RX_IRQn         = 13, /*!< 13 EFM32 USART0_RX Interrupt */
  USART0_TX_IRQn         = 14, /*!< 14 EFM32 USART0_TX Interrupt */
  USART1_RX_IRQn         = 15, /*!< 15 EFM32 USART1_RX Interrupt */
  USART1_TX_IRQn         = 16, /*!< 16 EFM32 USART1_TX Interrupt */
  ICACHE0_IRQn           = 17, /*!< 17 EFM32 ICACHE0 Interrupt */
  BURTC_IRQn             = 18, /*!< 18 EFM32 BURTC Interrupt */
  LETIMER0_IRQn          = 19, /*!< 19 EFM32 LETIMER0 Interrupt */
  SYSCFG_IRQn            = 20, /*!< 20 EFM32 SYSCFG Interrupt */
  LDMA_IRQn              = 21, /*!< 21 EFM32 LDMA Interrupt */
  LFXO_IRQn              = 22, /*!< 22 EFM32 LFXO Interrupt */
  LFRCO_IRQn             = 23, /*!< 23 EFM32 LFRCO Interrupt */
  ULFRCO_IRQn            = 24, /*!< 24 EFM32 ULFRCO Interrupt */
  GPIO_ODD_IRQn          = 25, /*!< 25 EFM32 GPIO_ODD Interrupt */
  GPIO_EVEN_IRQn         = 26, /*!< 26 EFM32 GPIO_EVEN Interrupt */
  I2C0_IRQn              = 27, /*!< 27 EFM32 I2C0 Interrupt */
  I2C1_IRQn              = 28, /*!< 28 EFM32 I2C1 Interrupt */
  EMUDG_IRQn             = 29, /*!< 29 EFM32 EMUDG Interrupt */
  EMUSE_IRQn             = 30, /*!< 30 EFM32 EMUSE Interrupt */
  WDOG0_IRQn             = 43, /*!< 43 EFM32 WDOG0 Interrupt */
  HFXO0_IRQn             = 44, /*!< 44 EFM32 HFXO0 Interrupt */
  HFRCO0_IRQn            = 45, /*!< 45 EFM32 HFRCO0 Interrupt */
  CMU_IRQn               = 46, /*!< 46 EFM32 CMU Interrupt */
  IADC_IRQn              = 48, /*!< 48 EFM32 IADC Interrupt */
  MSC_IRQn               = 49, /*!< 49 EFM32 MSC Interrupt */
  DPLL0_IRQn             = 50, /*!< 50 EFM32 DPLL0 Interrupt */
  PDM_IRQn               = 51, /*!< 51 EFM32 PDM Interrupt */
  SW0_IRQn               = 52, /*!< 52 EFM32 SW0 Interrupt */
  SW1_IRQn               = 53, /*!< 53 EFM32 SW1 Interrupt */
  SW2_IRQn               = 54, /*!< 54 EFM32 SW2 Interrupt */
  SW3_IRQn               = 55, /*!< 55 EFM32 SW3 Interrupt */
  KERNEL0_IRQn           = 56, /*!< 56 EFM32 KERNEL0 Interrupt */
  KERNEL1_IRQn           = 57, /*!< 57 EFM32 KERNEL1 Interrupt */
  M33CTI0_IRQn           = 58, /*!< 58 EFM32 M33CTI0 Interrupt */
  M33CTI1_IRQn           = 59, /*!< 59 EFM32 M33CTI1 Interrupt */
  EMUEFP_IRQn            = 60, /*!< 60 EFM32 EMUEFP Interrupt */
  DCDC_IRQn              = 61, /*!< 61 EFM32 DCDC Interrupt */
  EUART0_RX_IRQn         = 62, /*!< 62 EFM32 EUART0_RX Interrupt */
  EUART0_TX_IRQn         = 63, /*!< 63 EFM32 EUART0_TX Interrupt */
} IRQn_Type;

/**************************************************************************//**
 * @defgroup EFM32PG22C200F512IM40_Core EFM32PG22C200F512IM40 Core
 * @{
 * @brief Processor and Core Peripheral Section
 *****************************************************************************/

#define __CM33_REV                0x0004U /**< Cortex-M33 Core revision */
#define __DSP_PRESENT             1U      /**< Presence of DSP  */
#define __FPU_PRESENT             1U      /**< Presence of FPU  */
#define __MPU_PRESENT             1U      /**< Presence of MPU  */
#define __SAUREGION_PRESENT       1U      /**< Presence of FPU  */
#define __TZ_PRESENT              1U      /**< Presence of TrustZone */
#define __VTOR_PRESENT            1U      /**< Presence of VTOR register in SCB  */
#define __NVIC_PRIO_BITS          4U      /**< NVIC interrupt priority bits */
#define __Vendor_SysTickConfig    0U      /**< Is 1 if different SysTick counter is used */

/** @} End of group EFM32PG22C200F512IM40_Core */

/**************************************************************************//**
* @defgroup EFM32PG22C200F512IM40_Part EFM32PG22C200F512IM40 Part
* @{
******************************************************************************/

/** Part number */

/* If part number is not defined as compiler option, define it */
#if !defined(EFM32PG22C200F512IM40)
#define EFM32PG22C200F512IM40    1 /**< FULL Part */
#endif

/** Configure part number */
#define PART_NUMBER                              "EFM32PG22C200F512IM40" /**< Part Number */

/** Family / Line / Series / Config */
#define _EFM32_PEARL_FAMILY                      1                                    /** Device Family Name Identifier */
#define _EFM32_PG_FAMILY                         1                                    /** Device Family Identifier */
#define _EFM_DEVICE                              1                                    /** Product Line Identifier */
#define _SILICON_LABS_32B_SERIES_2                                                    /** Product Series Identifier */
#define _SILICON_LABS_32B_SERIES                 2                                    /** Product Series Identifier */
#define _SILICON_LABS_32B_SERIES_2_CONFIG_2                                           /** Product Config Identifier */
#define _SILICON_LABS_32B_SERIES_2_CONFIG        2                                    /** Product Config Identifier */
#define _SILICON_LABS_GECKO_INTERNAL_SDID        205                                  /** Silicon Labs internal use only */
#define _SILICON_LABS_GECKO_INTERNAL_SDID_205                                         /** Silicon Labs internal use only */
#define _SILICON_LABS_SECURITY_FEATURE_SE        0                                    /** Mid */
#define _SILICON_LABS_SECURITY_FEATURE_VAULT     1                                    /** High */
#define _SILICON_LABS_SECURITY_FEATURE_ROT       2                                    /** Root Of Trust */
#define _SILICON_LABS_SECURITY_FEATURE           _SILICON_LABS_SECURITY_FEATURE_ROT   /** Security feature set */
#define _SILICON_LABS_DCDC_FEATURE_NOTUSED       0                                    /** Not Used */
#define _SILICON_LABS_DCDC_FEATURE_DCDC_BUCK     1                                    /** Includes Buck DCDC */
#define _SILICON_LABS_DCDC_FEATURE_DCDC_BOOST    2                                    /** Includes Boost DCDC */
#define _SILICON_LABS_DCDC_FEATURE_DCDC_BOB      3                                    /** Includes Buck or Boost DCDC */
#define _SILICON_LABS_DCDC_FEATURE               _SILICON_LABS_DCDC_FEATURE_DCDC_BUCK /** DCDC feature set */
#define _SILICON_LABS_EFR32_RADIO_NONE           0                                    /** No radio present */
#define _SILICON_LABS_EFR32_RADIO_SUBGHZ         1                                    /** Radio supports Sub-GHz */
#define _SILICON_LABS_EFR32_RADIO_2G4HZ          2                                    /** Radio supports 2.4 GHz */
#define _SILICON_LABS_EFR32_RADIO_DUALBAND       3                                    /** Radio supports dual band */
#define _SILICON_LABS_EFR32_RADIO_TYPE           _SILICON_LABS_EFR32_RADIO_NONE       /** Radio type */
#define LFRCO_PRECISION_MODE                     1                                    /** Precision mode of LFRCO enabled or disabled */

/** Memory Base addresses and limits */
#define FLASH_MEM_BASE                           (0x00000000UL) /** FLASH_MEM base address */
#define FLASH_MEM_SIZE                           (0x00080000UL) /** FLASH_MEM available address space */
#define FLASH_MEM_END                            (0x0007FFFFUL) /** FLASH_MEM end address */
#define FLASH_MEM_BITS                           (0x14UL)       /** FLASH_MEM used bits */
#define MSC_FLASH_MEM_BASE                       (0x00000000UL) /** MSC_FLASH_MEM base address */
#define MSC_FLASH_MEM_SIZE                       (0x00080000UL) /** MSC_FLASH_MEM available address space */
#define MSC_FLASH_MEM_END                        (0x0007FFFFUL) /** MSC_FLASH_MEM end address */
#define MSC_FLASH_MEM_BITS                       (0x14UL)       /** MSC_FLASH_MEM used bits */
#define MSC_FLASH_USERDATA_MEM_BASE              (0x0FE00000UL) /** MSC_FLASH_USERDATA_MEM base address */
#define MSC_FLASH_USERDATA_MEM_SIZE              (0x00000400UL) /** MSC_FLASH_USERDATA_MEM available address space */
#define MSC_FLASH_USERDATA_MEM_END               (0x0FE003FFUL) /** MSC_FLASH_USERDATA_MEM end address */
#define MSC_FLASH_USERDATA_MEM_BITS              (0xBUL)        /** MSC_FLASH_USERDATA_MEM used bits */
#define USERDATA_BASE                            (0x0FE00000UL) /** USERDATA base address */
#define USERDATA_SIZE                            (0x00000400UL) /** USERDATA available address space */
#define USERDATA_END                             (0x0FE003FFUL) /** USERDATA end address */
#define USERDATA_BITS                            (0xBUL)        /** USERDATA used bits */
#define MSC_FLASH_DEVINFO_MEM_BASE               (0x0FE08000UL) /** MSC_FLASH_DEVINFO_MEM base address */
#define MSC_FLASH_DEVINFO_MEM_SIZE               (0x00000400UL) /** MSC_FLASH_DEVINFO_MEM available address space */
#define MSC_FLASH_DEVINFO_MEM_END                (0x0FE083FFUL) /** MSC_FLASH_DEVINFO_MEM end address */
#define MSC_FLASH_DEVINFO_MEM_BITS               (0xBUL)        /** MSC_FLASH_DEVINFO_MEM used bits */
#define MSC_FLASH_CHIPCONFIG_MEM_BASE            (0x0FE0E000UL) /** MSC_FLASH_CHIPCONFIG_MEM base address */
#define MSC_FLASH_CHIPCONFIG_MEM_SIZE            (0x00000600UL) /** MSC_FLASH_CHIPCONFIG_MEM available address space */
#define MSC_FLASH_CHIPCONFIG_MEM_END             (0x0FE0E5FFUL) /** MSC_FLASH_CHIPCONFIG_MEM end address */
#define MSC_FLASH_CHIPCONFIG_MEM_BITS            (0xBUL)        /** MSC_FLASH_CHIPCONFIG_MEM used bits */
#define DMEM_RAM0_RAM_MEM_BASE                   (0x20000000UL) /** DMEM_RAM0_RAM_MEM base address */
#define DMEM_RAM0_RAM_MEM_SIZE                   (0x00008000UL) /** DMEM_RAM0_RAM_MEM available address space */
#define DMEM_RAM0_RAM_MEM_END                    (0x20007FFFUL) /** DMEM_RAM0_RAM_MEM end address */
#define DMEM_RAM0_RAM_MEM_BITS                   (0x10UL)       /** DMEM_RAM0_RAM_MEM used bits */
#define RAM_MEM_BASE                             (0x20000000UL) /** RAM_MEM base address */
#define RAM_MEM_SIZE                             (0x00008000UL) /** RAM_MEM available address space */
#define RAM_MEM_END                              (0x20007FFFUL) /** RAM_MEM end address */
#define RAM_MEM_BITS                             (0x10UL)       /** RAM_MEM used bits */
#define CRYPTOACC_RNGOUT_FIFO_S_MEM_BASE         (0x4C024000UL) /** CRYPTOACC_RNGOUT_FIFO_S_MEM base address */
#define CRYPTOACC_RNGOUT_FIFO_S_MEM_SIZE         (0x00004000UL) /** CRYPTOACC_RNGOUT_FIFO_S_MEM available address space */
#define CRYPTOACC_RNGOUT_FIFO_S_MEM_END          (0x4C027FFFUL) /** CRYPTOACC_RNGOUT_FIFO_S_MEM end address */
#define CRYPTOACC_RNGOUT_FIFO_S_MEM_BITS         (0xFUL)        /** CRYPTOACC_RNGOUT_FIFO_S_MEM used bits */
#define CRYPTOACC_PKRAM_MAIN_S_MEM_BASE          (0x4C028000UL) /** CRYPTOACC_PKRAM_MAIN_S_MEM base address */
#define CRYPTOACC_PKRAM_MAIN_S_MEM_SIZE          (0x00001000UL) /** CRYPTOACC_PKRAM_MAIN_S_MEM available address space */
#define CRYPTOACC_PKRAM_MAIN_S_MEM_END           (0x4C028FFFUL) /** CRYPTOACC_PKRAM_MAIN_S_MEM end address */
#define CRYPTOACC_PKRAM_MAIN_S_MEM_BITS          (0xDUL)        /** CRYPTOACC_PKRAM_MAIN_S_MEM used bits */
#define CRYPTOACC_RNGOUT_FIFO_MEM_BASE           (0x5C024000UL) /** CRYPTOACC_RNGOUT_FIFO_MEM base address */
#define CRYPTOACC_RNGOUT_FIFO_MEM_SIZE           (0x00004000UL) /** CRYPTOACC_RNGOUT_FIFO_MEM available address space */
#define CRYPTOACC_RNGOUT_FIFO_MEM_END            (0x5C027FFFUL) /** CRYPTOACC_RNGOUT_FIFO_MEM end address */
#define CRYPTOACC_RNGOUT_FIFO_MEM_BITS           (0xFUL)        /** CRYPTOACC_RNGOUT_FIFO_MEM used bits */
#define CRYPTOACC_RNGOUT_FIFO_NS_MEM_BASE        (0x5C024000UL) /** CRYPTOACC_RNGOUT_FIFO_NS_MEM base address */
#define CRYPTOACC_RNGOUT_FIFO_NS_MEM_SIZE        (0x00004000UL) /** CRYPTOACC_RNGOUT_FIFO_NS_MEM available address space */
#define CRYPTOACC_RNGOUT_FIFO_NS_MEM_END         (0x5C027FFFUL) /** CRYPTOACC_RNGOUT_FIFO_NS_MEM end address */
#define CRYPTOACC_RNGOUT_FIFO_NS_MEM_BITS        (0xFUL)        /** CRYPTOACC_RNGOUT_FIFO_NS_MEM used bits */
#define CRYPTOACC_PKRAM_MAIN_MEM_BASE            (0x5C028000UL) /** CRYPTOACC_PKRAM_MAIN_MEM base address */
#define CRYPTOACC_PKRAM_MAIN_MEM_SIZE            (0x00001000UL) /** CRYPTOACC_PKRAM_MAIN_MEM available address space */
#define CRYPTOACC_PKRAM_MAIN_MEM_END             (0x5C028FFFUL) /** CRYPTOACC_PKRAM_MAIN_MEM end address */
#define CRYPTOACC_PKRAM_MAIN_MEM_BITS            (0xDUL)        /** CRYPTOACC_PKRAM_MAIN_MEM used bits */
#define CRYPTOACC_PKRAM_MAIN_NS_MEM_BASE         (0x5C028000UL) /** CRYPTOACC_PKRAM_MAIN_NS_MEM base address */
#define CRYPTOACC_PKRAM_MAIN_NS_MEM_SIZE         (0x00001000UL) /** CRYPTOACC_PKRAM_MAIN_NS_MEM available address space */
#define CRYPTOACC_PKRAM_MAIN_NS_MEM_END          (0x5C028FFFUL) /** CRYPTOACC_PKRAM_MAIN_NS_MEM end address */
#define CRYPTOACC_PKRAM_MAIN_NS_MEM_BITS         (0xDUL)        /** CRYPTOACC_PKRAM_MAIN_NS_MEM used bits */
#define RDMEM_SEQRAM_S_MEM_BASE                  (0xA0000000UL) /** RDMEM_SEQRAM_S_MEM base address */
#define RDMEM_SEQRAM_S_MEM_SIZE                  (0x00004000UL) /** RDMEM_SEQRAM_S_MEM available address space */
#define RDMEM_SEQRAM_S_MEM_END                   (0xA0003FFFUL) /** RDMEM_SEQRAM_S_MEM end address */
#define RDMEM_SEQRAM_S_MEM_BITS                  (0xFUL)        /** RDMEM_SEQRAM_S_MEM used bits */
#define RDMEM_FRCRAM_S_MEM_BASE                  (0xA0004000UL) /** RDMEM_FRCRAM_S_MEM base address */
#define RDMEM_FRCRAM_S_MEM_SIZE                  (0x00001000UL) /** RDMEM_FRCRAM_S_MEM available address space */
#define RDMEM_FRCRAM_S_MEM_END                   (0xA0004FFFUL) /** RDMEM_FRCRAM_S_MEM end address */
#define RDMEM_FRCRAM_S_MEM_BITS                  (0xDUL)        /** RDMEM_FRCRAM_S_MEM used bits */
#define RDMEM_SEQRAM_NS_MEM_BASE                 (0xB0000000UL) /** RDMEM_SEQRAM_NS_MEM base address */
#define RDMEM_SEQRAM_NS_MEM_SIZE                 (0x00004000UL) /** RDMEM_SEQRAM_NS_MEM available address space */
#define RDMEM_SEQRAM_NS_MEM_END                  (0xB0003FFFUL) /** RDMEM_SEQRAM_NS_MEM end address */
#define RDMEM_SEQRAM_NS_MEM_BITS                 (0xFUL)        /** RDMEM_SEQRAM_NS_MEM used bits */
#define RDMEM_SEQRAM_SEQRAM_MEM_BASE             (0xB0000000UL) /** RDMEM_SEQRAM_SEQRAM_MEM base address */
#define RDMEM_SEQRAM_SEQRAM_MEM_SIZE             (0x00004000UL) /** RDMEM_SEQRAM_SEQRAM_MEM available address space */
#define RDMEM_SEQRAM_SEQRAM_MEM_END              (0xB0003FFFUL) /** RDMEM_SEQRAM_SEQRAM_MEM end address */
#define RDMEM_SEQRAM_SEQRAM_MEM_BITS             (0xFUL)        /** RDMEM_SEQRAM_SEQRAM_MEM used bits */
#define RDMEM_FRCRAM_FRCRAM_MEM_BASE             (0xB0004000UL) /** RDMEM_FRCRAM_FRCRAM_MEM base address */
#define RDMEM_FRCRAM_FRCRAM_MEM_SIZE             (0x00001000UL) /** RDMEM_FRCRAM_FRCRAM_MEM available address space */
#define RDMEM_FRCRAM_FRCRAM_MEM_END              (0xB0004FFFUL) /** RDMEM_FRCRAM_FRCRAM_MEM end address */
#define RDMEM_FRCRAM_FRCRAM_MEM_BITS             (0xDUL)        /** RDMEM_FRCRAM_FRCRAM_MEM used bits */
#define RDMEM_FRCRAM_NS_MEM_BASE                 (0xB0004000UL) /** RDMEM_FRCRAM_NS_MEM base address */
#define RDMEM_FRCRAM_NS_MEM_SIZE                 (0x00001000UL) /** RDMEM_FRCRAM_NS_MEM available address space */
#define RDMEM_FRCRAM_NS_MEM_END                  (0xB0004FFFUL) /** RDMEM_FRCRAM_NS_MEM end address */
#define RDMEM_FRCRAM_NS_MEM_BITS                 (0xDUL)        /** RDMEM_FRCRAM_NS_MEM used bits */

/** Flash and SRAM limits for EFM32PG22C200F512IM40 */
#define FLASH_BASE                               (0x00000000UL) /**< Flash Base Address */
#define FLASH_SIZE                               (0x00080000UL) /**< Available Flash Memory */
#define FLASH_PAGE_SIZE                          (0x00002000UL) /**< Flash Memory page size */
#define SRAM_BASE                                (0x20000000UL) /**< SRAM Base Address */
#define SRAM_SIZE                                (0x00008000UL) /**< Available SRAM Memory */
#define DMA_CHAN_COUNT                           LDMA_CH_NUM    /**< Number of DMA channels */
#define EXT_IRQ_COUNT                            64             /**< Number of External (NVIC) interrupts */

/* GPIO Avalibility Info */
#define GPIO_PA_INDEX                            0U         /**< Index of port PA */
#define GPIO_PA_COUNT                            9U         /**< Number of pins on port PA */
#define GPIO_PA_MASK                             (0x01FFUL) /**< Port PA pin mask */
#define GPIO_PA_PIN0                             1U         /**< GPIO pin PA0 is present. */
#define GPIO_PA_PIN1                             1U         /**< GPIO pin PA1 is present. */
#define GPIO_PA_PIN2                             1U         /**< GPIO pin PA2 is present. */
#define GPIO_PA_PIN3                             1U         /**< GPIO pin PA3 is present. */
#define GPIO_PA_PIN4                             1U         /**< GPIO pin PA4 is present. */
#define GPIO_PA_PIN5                             1U         /**< GPIO pin PA5 is present. */
#define GPIO_PA_PIN6                             1U         /**< GPIO pin PA6 is present. */
#define GPIO_PA_PIN7                             1U         /**< GPIO pin PA7 is present. */
#define GPIO_PA_PIN8                             1U         /**< GPIO pin PA8 is present. */
#define GPIO_PB_INDEX                            1U         /**< Index of port PB */
#define GPIO_PB_COUNT                            5U         /**< Number of pins on port PB */
#define GPIO_PB_MASK                             (0x001FUL) /**< Port PB pin mask */
#define GPIO_PB_PIN0                             1U         /**< GPIO pin PB0 is present. */
#define GPIO_PB_PIN1                             1U         /**< GPIO pin PB1 is present. */
#define GPIO_PB_PIN2                             1U         /**< GPIO pin PB2 is present. */
#define GPIO_PB_PIN3                             1U         /**< GPIO pin PB3 is present. */
#define GPIO_PB_PIN4                             1U         /**< GPIO pin PB4 is present. */
#define GPIO_PC_INDEX                            2U         /**< Index of port PC */
#define GPIO_PC_COUNT                            8U         /**< Number of pins on port PC */
#define GPIO_PC_MASK                             (0x00FFUL) /**< Port PC pin mask */
#define GPIO_PC_PIN0                             1U         /**< GPIO pin PC0 is present. */
#define GPIO_PC_PIN1                             1U         /**< GPIO pin PC1 is present. */
#define GPIO_PC_PIN2                             1U         /**< GPIO pin PC2 is present. */
#define GPIO_PC_PIN3                             1U         /**< GPIO pin PC3 is present. */
#define GPIO_PC_PIN4                             1U         /**< GPIO pin PC4 is present. */
#define GPIO_PC_PIN5                             1U         /**< GPIO pin PC5 is present. */
#define GPIO_PC_PIN6                             1U         /**< GPIO pin PC6 is present. */
#define GPIO_PC_PIN7                             1U         /**< GPIO pin PC7 is present. */
#define GPIO_PD_INDEX                            3U         /**< Index of port PD */
#define GPIO_PD_COUNT                            4U         /**< Number of pins on port PD */
#define GPIO_PD_MASK                             (0x000FUL) /**< Port PD pin mask */
#define GPIO_PD_PIN0                             1U         /**< GPIO pin PD0 is present. */
#define GPIO_PD_PIN1                             1U         /**< GPIO pin PD1 is present. */
#define GPIO_PD_PIN2                             1U         /**< GPIO pin PD2 is present. */
#define GPIO_PD_PIN3                             1U         /**< GPIO pin PD3 is present. */

/* Fixed Resource Locations */
#define GPIO_SWCLK_PORT                          GPIO_PA_INDEX /**< Port of SWCLK.*/
#define GPIO_SWCLK_PIN                           1U            /**< Pin of SWCLK.*/
#define GPIO_SWDIO_PORT                          GPIO_PA_INDEX /**< Port of SWDIO.*/
#define GPIO_SWDIO_PIN                           2U            /**< Pin of SWDIO.*/
#define GPIO_SWV_PORT                            GPIO_PA_INDEX /**< Port of SWV.*/
#define GPIO_SWV_PIN                             3U            /**< Pin of SWV.*/
#define GPIO_TDI_PORT                            GPIO_PA_INDEX /**< Port of TDI.*/
#define GPIO_TDI_PIN                             4U            /**< Pin of TDI.*/
#define GPIO_TDO_PORT                            GPIO_PA_INDEX /**< Port of TDO.*/
#define GPIO_TDO_PIN                             3U            /**< Pin of TDO.*/
#define GPIO_TRACECLK_PORT                       GPIO_PA_INDEX /**< Port of TRACECLK.*/
#define GPIO_TRACECLK_PIN                        4U            /**< Pin of TRACECLK.*/
#define GPIO_TRACEDATA0_PORT                     GPIO_PA_INDEX /**< Port of TRACEDATA0.*/
#define GPIO_TRACEDATA0_PIN                      3U            /**< Pin of TRACEDATA0.*/
#define GPIO_EM4WU0_PORT                         GPIO_PA_INDEX /**< Port of EM4WU0.*/
#define GPIO_EM4WU0_PIN                          5U            /**< Pin of EM4WU0.*/
#define GPIO_EM4WU3_PORT                         GPIO_PB_INDEX /**< Port of EM4WU3.*/
#define GPIO_EM4WU3_PIN                          1U            /**< Pin of EM4WU3.*/
#define GPIO_EM4WU4_PORT                         GPIO_PB_INDEX /**< Port of EM4WU4.*/
#define GPIO_EM4WU4_PIN                          3U            /**< Pin of EM4WU4.*/
#define GPIO_EM4WU6_PORT                         GPIO_PC_INDEX /**< Port of EM4WU6.*/
#define GPIO_EM4WU6_PIN                          0U            /**< Pin of EM4WU6.*/
#define GPIO_EM4WU7_PORT                         GPIO_PC_INDEX /**< Port of EM4WU7.*/
#define GPIO_EM4WU7_PIN                          5U            /**< Pin of EM4WU7.*/
#define GPIO_EM4WU8_PORT                         GPIO_PC_INDEX /**< Port of EM4WU8.*/
#define GPIO_EM4WU8_PIN                          7U            /**< Pin of EM4WU8.*/
#define GPIO_EM4WU9_PORT                         GPIO_PD_INDEX /**< Port of EM4WU9.*/
#define GPIO_EM4WU9_PIN                          2U            /**< Pin of EM4WU9.*/
#define IADC0_VREFP_PORT                         GPIO_PA_INDEX /**< Port of VREFP.*/
#define IADC0_VREFP_PIN                          0U            /**< Pin of VREFP.*/
#define LFXO_LFXTAL_I_PORT                       GPIO_PD_INDEX /**< Port of LFXTAL_I.*/
#define LFXO_LFXTAL_I_PIN                        1U            /**< Pin of LFXTAL_I.*/
#define LFXO_LFXTAL_O_PORT                       GPIO_PD_INDEX /**< Port of LFXTAL_O.*/
#define LFXO_LFXTAL_O_PIN                        0U            /**< Pin of LFXTAL_O.*/
#define LFXO_LF_EXTCLK_PORT                      GPIO_PD_INDEX /**< Port of LF_EXTCLK.*/
#define LFXO_LF_EXTCLK_PIN                       1U            /**< Pin of LF_EXTCLK.*/

/* Part number capabilities */
#define AMUXCP_PRESENT                             /** AMUXCP is available in this part */
#define AMUXCP_COUNT                             1 /** 1 AMUXCPs available  */
#define BURAM_PRESENT                              /** BURAM is available in this part */
#define BURAM_COUNT                              1 /** 1 BURAMs available  */
#define BURTC_PRESENT                              /** BURTC is available in this part */
#define BURTC_COUNT                              1 /** 1 BURTCs available  */
#define CMU_PRESENT                                /** CMU is available in this part */
#define CMU_COUNT                                1 /** 1 CMUs available  */
#define CRYPTOACC_PRESENT                          /** CRYPTOACC is available in this part */
#define CRYPTOACC_COUNT                          1 /** 1 CRYPTOACCs available  */
#define DCDC_PRESENT                               /** DCDC is available in this part */
#define DCDC_COUNT                               1 /** 1 DCDCs available  */
#define DPLL_PRESENT                               /** DPLL is available in this part */
#define DPLL_COUNT                               1 /** 1 DPLLs available  */
#define EMU_PRESENT                                /** EMU is available in this part */
#define EMU_COUNT                                1 /** 1 EMUs available  */
#define EUART_PRESENT                              /** EUART is available in this part */
#define EUART_COUNT                              1 /** 1 EUARTs available  */
#define FSRCO_PRESENT                              /** FSRCO is available in this part */
#define FSRCO_COUNT                              1 /** 1 FSRCOs available  */
#define GPCRC_PRESENT                              /** GPCRC is available in this part */
#define GPCRC_COUNT                              1 /** 1 GPCRCs available  */
#define GPIO_PRESENT                               /** GPIO is available in this part */
#define GPIO_COUNT                               1 /** 1 GPIOs available  */
#define HFRCO_PRESENT                              /** HFRCO is available in this part */
#define HFRCO_COUNT                              1 /** 1 HFRCOs available  */
#define HFXO_PRESENT                               /** HFXO is available in this part */
#define HFXO_COUNT                               1 /** 1 HFXOs available  */
#define I2C_PRESENT                                /** I2C is available in this part */
#define I2C_COUNT                                2 /** 2 I2Cs available  */
#define IADC_PRESENT                               /** IADC is available in this part */
#define IADC_COUNT                               1 /** 1 IADCs available  */
#define ICACHE_PRESENT                             /** ICACHE is available in this part */
#define ICACHE_COUNT                             1 /** 1 ICACHEs available  */
#define LDMA_PRESENT                               /** LDMA is available in this part */
#define LDMA_COUNT                               1 /** 1 LDMAs available  */
#define LDMAXBAR_PRESENT                           /** LDMAXBAR is available in this part */
#define LDMAXBAR_COUNT                           1 /** 1 LDMAXBARs available  */
#define LETIMER_PRESENT                            /** LETIMER is available in this part */
#define LETIMER_COUNT                            1 /** 1 LETIMERs available  */
#define LFRCO_PRESENT                              /** LFRCO is available in this part */
#define LFRCO_COUNT                              1 /** 1 LFRCOs available  */
#define LFXO_PRESENT                               /** LFXO is available in this part */
#define LFXO_COUNT                               1 /** 1 LFXOs available  */
#define MSC_PRESENT                                /** MSC is available in this part */
#define MSC_COUNT                                1 /** 1 MSCs available  */
#define PDM_PRESENT                                /** PDM is available in this part */
#define PDM_COUNT                                1 /** 1 PDMs available  */
#define PRS_PRESENT                                /** PRS is available in this part */
#define PRS_COUNT                                1 /** 1 PRSs available  */
#define RTCC_PRESENT                               /** RTCC is available in this part */
#define RTCC_COUNT                               1 /** 1 RTCCs available  */
#define SMU_PRESENT                                /** SMU is available in this part */
#define SMU_COUNT                                1 /** 1 SMUs available  */
#define SYSCFG_PRESENT                             /** SYSCFG is available in this part */
#define SYSCFG_COUNT                             1 /** 1 SYSCFGs available  */
#define TIMER_PRESENT                              /** TIMER is available in this part */
#define TIMER_COUNT                              5 /** 5 TIMERs available  */
#define ULFRCO_PRESENT                             /** ULFRCO is available in this part */
#define ULFRCO_COUNT                             1 /** 1 ULFRCOs available  */
#define USART_PRESENT                              /** USART is available in this part */
#define USART_COUNT                              2 /** 2 USARTs available  */
#define WDOG_PRESENT                               /** WDOG is available in this part */
#define WDOG_COUNT                               1 /** 1 WDOGs available  */
#define DEVINFO_PRESENT                            /** DEVINFO is available in this part */
#define DEVINFO_COUNT                            1 /** 1 DEVINFOs available  */

/* Include standard ARM headers for the core */
#include <cmsis/core_cm33.h>        /* Core Header File */

/** @} End of group EFM32PG22C200F512IM40_Part */

/**************************************************************************//**
 * @defgroup EFM32PG22_AMUXCP AMUXCP
 * @{
 * @brief EFM32PG22 AMUXCP Register Declaration.
 *****************************************************************************/

/** AMUXCP Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IPVERSION                                          */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CTRL;                          /**< Control                                            */
  __IM uint32_t  STATUS;                        /**< Status                                             */
  __IOM uint32_t TEST;                          /**< Test                                               */
  __IOM uint32_t TRIM;                          /**< Trim                                               */
  uint32_t       RESERVED1[1018U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IPVERSION                                          */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CTRL_SET;                      /**< Control                                            */
  __IM uint32_t  STATUS_SET;                    /**< Status                                             */
  __IOM uint32_t TEST_SET;                      /**< Test                                               */
  __IOM uint32_t TRIM_SET;                      /**< Trim                                               */
  uint32_t       RESERVED3[1018U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IPVERSION                                          */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CTRL_CLR;                      /**< Control                                            */
  __IM uint32_t  STATUS_CLR;                    /**< Status                                             */
  __IOM uint32_t TEST_CLR;                      /**< Test                                               */
  __IOM uint32_t TRIM_CLR;                      /**< Trim                                               */
  uint32_t       RESERVED5[1018U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IPVERSION                                          */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CTRL_TGL;                      /**< Control                                            */
  __IM uint32_t  STATUS_TGL;                    /**< Status                                             */
  __IOM uint32_t TEST_TGL;                      /**< Test                                               */
  __IOM uint32_t TRIM_TGL;                      /**< Trim                                               */
} AMUXCP_TypeDef;
/** @} End of group EFM32PG22_AMUXCP */

/**************************************************************************//**
 * @defgroup EFM32PG22_BURAM BURAM
 * @{
 * @brief EFM32PG22 BURAM Register Declaration.
 *****************************************************************************/

/** BURAM RET Register Group Declaration. */
typedef struct {
  __IOM uint32_t REG;                                /**< Retention Register                                 */
} BURAM_RET_TypeDef;

/** BURAM Register Declaration. */
typedef struct {
  BURAM_RET_TypeDef RET[32U];                   /**< RetentionReg                                       */
  uint32_t          RESERVED0[992U];            /**< Reserved for future use                            */
  BURAM_RET_TypeDef RET_SET[32U];               /**< RetentionReg                                       */
  uint32_t          RESERVED1[992U];            /**< Reserved for future use                            */
  BURAM_RET_TypeDef RET_CLR[32U];               /**< RetentionReg                                       */
  uint32_t          RESERVED2[992U];            /**< Reserved for future use                            */
  BURAM_RET_TypeDef RET_TGL[32U];               /**< RetentionReg                                       */
} BURAM_TypeDef;
/** @} End of group EFM32PG22_BURAM */

/**************************************************************************//**
 * @defgroup EFM32PG22_BURTC BURTC
 * @{
 * @brief EFM32PG22 BURTC Register Declaration.
 *****************************************************************************/

/** BURTC Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version ID                                      */
  __IOM uint32_t EN;                            /**< Module Enable Register                             */
  __IOM uint32_t CFG;                           /**< Configuration Register                             */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  __IOM uint32_t PRECNT;                        /**< Pre-Counter Value Register                         */
  __IOM uint32_t CNT;                           /**< Counter Value Register                             */
  __IOM uint32_t EM4WUEN;                       /**< EM4 wakeup request Enable Register                 */
  __IM uint32_t  SYNCBUSY;                      /**< Synchronization Busy Register                      */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  __IOM uint32_t COMP;                          /**< Compare Value Register                             */
  uint32_t       RESERVED0[1011U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version ID                                      */
  __IOM uint32_t EN_SET;                        /**< Module Enable Register                             */
  __IOM uint32_t CFG_SET;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t PRECNT_SET;                    /**< Pre-Counter Value Register                         */
  __IOM uint32_t CNT_SET;                       /**< Counter Value Register                             */
  __IOM uint32_t EM4WUEN_SET;                   /**< EM4 wakeup request Enable Register                 */
  __IM uint32_t  SYNCBUSY_SET;                  /**< Synchronization Busy Register                      */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  __IOM uint32_t COMP_SET;                      /**< Compare Value Register                             */
  uint32_t       RESERVED1[1011U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version ID                                      */
  __IOM uint32_t EN_CLR;                        /**< Module Enable Register                             */
  __IOM uint32_t CFG_CLR;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t PRECNT_CLR;                    /**< Pre-Counter Value Register                         */
  __IOM uint32_t CNT_CLR;                       /**< Counter Value Register                             */
  __IOM uint32_t EM4WUEN_CLR;                   /**< EM4 wakeup request Enable Register                 */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< Synchronization Busy Register                      */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  __IOM uint32_t COMP_CLR;                      /**< Compare Value Register                             */
  uint32_t       RESERVED2[1011U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version ID                                      */
  __IOM uint32_t EN_TGL;                        /**< Module Enable Register                             */
  __IOM uint32_t CFG_TGL;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t PRECNT_TGL;                    /**< Pre-Counter Value Register                         */
  __IOM uint32_t CNT_TGL;                       /**< Counter Value Register                             */
  __IOM uint32_t EM4WUEN_TGL;                   /**< EM4 wakeup request Enable Register                 */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< Synchronization Busy Register                      */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
  __IOM uint32_t COMP_TGL;                      /**< Compare Value Register                             */
} BURTC_TypeDef;
/** @} End of group EFM32PG22_BURTC */

/**************************************************************************//**
 * @defgroup EFM32PG22_CMU CMU
 * @{
 * @brief EFM32PG22 CMU Register Declaration.
 *****************************************************************************/

/** CMU Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version ID                                      */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED1[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  __IOM uint32_t WDOGLOCK;                      /**< WDOG Configuration Lock Register                   */
  uint32_t       RESERVED2[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED3[10U];                /**< Reserved for future use                            */
  __IOM uint32_t CALCMD;                        /**< Calibration Command Register                       */
  __IOM uint32_t CALCTRL;                       /**< Calibration Control Register                       */
  __IM uint32_t  CALCNT;                        /**< Calibration Result Counter Register                */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t CLKEN0;                        /**< Clock Enable Register 0                            */
  __IOM uint32_t CLKEN1;                        /**<  Clock Enable Register 1                           */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t SYSCLKCTRL;                    /**< System Clock Control                               */
  uint32_t       RESERVED6[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t TRACECLKCTRL;                  /**< Debug Trace Clock Control                          */
  uint32_t       RESERVED7[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t EXPORTCLKCTRL;                 /**< Export Clock Control                               */
  uint32_t       RESERVED8[27U];                /**< Reserved for future use                            */
  __IOM uint32_t DPLLREFCLKCTRL;                /**< Digital PLL Reference Clock Control                */
  uint32_t       RESERVED9[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t EM01GRPACLKCTRL;               /**< EM01 Peripheral Group A Clock Control              */
  __IOM uint32_t EM01GRPBCLKCTRL;               /**< EM01 Peripheral Group B Clock Control              */
  uint32_t       RESERVED10[6U];                /**< Reserved for future use                            */
  __IOM uint32_t EM23GRPACLKCTRL;               /**< EM23 Peripheral Group A Clock Control              */
  uint32_t       RESERVED11[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM4GRPACLKCTRL;                /**< EM4 Peripheral Group A Clock Control               */
  uint32_t       RESERVED12[7U];                /**< Reserved for future use                            */
  __IOM uint32_t IADCCLKCTRL;                   /**< IADC Clock Control                                 */
  uint32_t       RESERVED13[31U];               /**< Reserved for future use                            */
  __IOM uint32_t WDOG0CLKCTRL;                  /**< Watchdog0 Clock Control                            */
  uint32_t       RESERVED14[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EUART0CLKCTRL;                 /**< UART Clock Control                                 */
  uint32_t       RESERVED15[7U];                /**< Reserved for future use                            */
  __IOM uint32_t RTCCCLKCTRL;                   /**< RTCC Clock Control                                 */
  uint32_t       RESERVED16[7U];                /**< Reserved for future use                            */
  __IOM uint32_t CRYPTOACCCLKCTRL;              /**< CRYPTOACC Clock Control                            */
  uint32_t       RESERVED17[871U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version ID                                      */
  uint32_t       RESERVED18[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED19[1U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  __IOM uint32_t WDOGLOCK_SET;                  /**< WDOG Configuration Lock Register                   */
  uint32_t       RESERVED20[2U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED21[10U];               /**< Reserved for future use                            */
  __IOM uint32_t CALCMD_SET;                    /**< Calibration Command Register                       */
  __IOM uint32_t CALCTRL_SET;                   /**< Calibration Control Register                       */
  __IM uint32_t  CALCNT_SET;                    /**< Calibration Result Counter Register                */
  uint32_t       RESERVED22[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CLKEN0_SET;                    /**< Clock Enable Register 0                            */
  __IOM uint32_t CLKEN1_SET;                    /**<  Clock Enable Register 1                           */
  uint32_t       RESERVED23[1U];                /**< Reserved for future use                            */
  __IOM uint32_t SYSCLKCTRL_SET;                /**< System Clock Control                               */
  uint32_t       RESERVED24[3U];                /**< Reserved for future use                            */
  __IOM uint32_t TRACECLKCTRL_SET;              /**< Debug Trace Clock Control                          */
  uint32_t       RESERVED25[3U];                /**< Reserved for future use                            */
  __IOM uint32_t EXPORTCLKCTRL_SET;             /**< Export Clock Control                               */
  uint32_t       RESERVED26[27U];               /**< Reserved for future use                            */
  __IOM uint32_t DPLLREFCLKCTRL_SET;            /**< Digital PLL Reference Clock Control                */
  uint32_t       RESERVED27[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM01GRPACLKCTRL_SET;           /**< EM01 Peripheral Group A Clock Control              */
  __IOM uint32_t EM01GRPBCLKCTRL_SET;           /**< EM01 Peripheral Group B Clock Control              */
  uint32_t       RESERVED28[6U];                /**< Reserved for future use                            */
  __IOM uint32_t EM23GRPACLKCTRL_SET;           /**< EM23 Peripheral Group A Clock Control              */
  uint32_t       RESERVED29[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM4GRPACLKCTRL_SET;            /**< EM4 Peripheral Group A Clock Control               */
  uint32_t       RESERVED30[7U];                /**< Reserved for future use                            */
  __IOM uint32_t IADCCLKCTRL_SET;               /**< IADC Clock Control                                 */
  uint32_t       RESERVED31[31U];               /**< Reserved for future use                            */
  __IOM uint32_t WDOG0CLKCTRL_SET;              /**< Watchdog0 Clock Control                            */
  uint32_t       RESERVED32[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EUART0CLKCTRL_SET;             /**< UART Clock Control                                 */
  uint32_t       RESERVED33[7U];                /**< Reserved for future use                            */
  __IOM uint32_t RTCCCLKCTRL_SET;               /**< RTCC Clock Control                                 */
  uint32_t       RESERVED34[7U];                /**< Reserved for future use                            */
  __IOM uint32_t CRYPTOACCCLKCTRL_SET;          /**< CRYPTOACC Clock Control                            */
  uint32_t       RESERVED35[871U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version ID                                      */
  uint32_t       RESERVED36[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED37[1U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  __IOM uint32_t WDOGLOCK_CLR;                  /**< WDOG Configuration Lock Register                   */
  uint32_t       RESERVED38[2U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED39[10U];               /**< Reserved for future use                            */
  __IOM uint32_t CALCMD_CLR;                    /**< Calibration Command Register                       */
  __IOM uint32_t CALCTRL_CLR;                   /**< Calibration Control Register                       */
  __IM uint32_t  CALCNT_CLR;                    /**< Calibration Result Counter Register                */
  uint32_t       RESERVED40[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CLKEN0_CLR;                    /**< Clock Enable Register 0                            */
  __IOM uint32_t CLKEN1_CLR;                    /**<  Clock Enable Register 1                           */
  uint32_t       RESERVED41[1U];                /**< Reserved for future use                            */
  __IOM uint32_t SYSCLKCTRL_CLR;                /**< System Clock Control                               */
  uint32_t       RESERVED42[3U];                /**< Reserved for future use                            */
  __IOM uint32_t TRACECLKCTRL_CLR;              /**< Debug Trace Clock Control                          */
  uint32_t       RESERVED43[3U];                /**< Reserved for future use                            */
  __IOM uint32_t EXPORTCLKCTRL_CLR;             /**< Export Clock Control                               */
  uint32_t       RESERVED44[27U];               /**< Reserved for future use                            */
  __IOM uint32_t DPLLREFCLKCTRL_CLR;            /**< Digital PLL Reference Clock Control                */
  uint32_t       RESERVED45[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM01GRPACLKCTRL_CLR;           /**< EM01 Peripheral Group A Clock Control              */
  __IOM uint32_t EM01GRPBCLKCTRL_CLR;           /**< EM01 Peripheral Group B Clock Control              */
  uint32_t       RESERVED46[6U];                /**< Reserved for future use                            */
  __IOM uint32_t EM23GRPACLKCTRL_CLR;           /**< EM23 Peripheral Group A Clock Control              */
  uint32_t       RESERVED47[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM4GRPACLKCTRL_CLR;            /**< EM4 Peripheral Group A Clock Control               */
  uint32_t       RESERVED48[7U];                /**< Reserved for future use                            */
  __IOM uint32_t IADCCLKCTRL_CLR;               /**< IADC Clock Control                                 */
  uint32_t       RESERVED49[31U];               /**< Reserved for future use                            */
  __IOM uint32_t WDOG0CLKCTRL_CLR;              /**< Watchdog0 Clock Control                            */
  uint32_t       RESERVED50[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EUART0CLKCTRL_CLR;             /**< UART Clock Control                                 */
  uint32_t       RESERVED51[7U];                /**< Reserved for future use                            */
  __IOM uint32_t RTCCCLKCTRL_CLR;               /**< RTCC Clock Control                                 */
  uint32_t       RESERVED52[7U];                /**< Reserved for future use                            */
  __IOM uint32_t CRYPTOACCCLKCTRL_CLR;          /**< CRYPTOACC Clock Control                            */
  uint32_t       RESERVED53[871U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version ID                                      */
  uint32_t       RESERVED54[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED55[1U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
  __IOM uint32_t WDOGLOCK_TGL;                  /**< WDOG Configuration Lock Register                   */
  uint32_t       RESERVED56[2U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED57[10U];               /**< Reserved for future use                            */
  __IOM uint32_t CALCMD_TGL;                    /**< Calibration Command Register                       */
  __IOM uint32_t CALCTRL_TGL;                   /**< Calibration Control Register                       */
  __IM uint32_t  CALCNT_TGL;                    /**< Calibration Result Counter Register                */
  uint32_t       RESERVED58[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CLKEN0_TGL;                    /**< Clock Enable Register 0                            */
  __IOM uint32_t CLKEN1_TGL;                    /**<  Clock Enable Register 1                           */
  uint32_t       RESERVED59[1U];                /**< Reserved for future use                            */
  __IOM uint32_t SYSCLKCTRL_TGL;                /**< System Clock Control                               */
  uint32_t       RESERVED60[3U];                /**< Reserved for future use                            */
  __IOM uint32_t TRACECLKCTRL_TGL;              /**< Debug Trace Clock Control                          */
  uint32_t       RESERVED61[3U];                /**< Reserved for future use                            */
  __IOM uint32_t EXPORTCLKCTRL_TGL;             /**< Export Clock Control                               */
  uint32_t       RESERVED62[27U];               /**< Reserved for future use                            */
  __IOM uint32_t DPLLREFCLKCTRL_TGL;            /**< Digital PLL Reference Clock Control                */
  uint32_t       RESERVED63[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM01GRPACLKCTRL_TGL;           /**< EM01 Peripheral Group A Clock Control              */
  __IOM uint32_t EM01GRPBCLKCTRL_TGL;           /**< EM01 Peripheral Group B Clock Control              */
  uint32_t       RESERVED64[6U];                /**< Reserved for future use                            */
  __IOM uint32_t EM23GRPACLKCTRL_TGL;           /**< EM23 Peripheral Group A Clock Control              */
  uint32_t       RESERVED65[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EM4GRPACLKCTRL_TGL;            /**< EM4 Peripheral Group A Clock Control               */
  uint32_t       RESERVED66[7U];                /**< Reserved for future use                            */
  __IOM uint32_t IADCCLKCTRL_TGL;               /**< IADC Clock Control                                 */
  uint32_t       RESERVED67[31U];               /**< Reserved for future use                            */
  __IOM uint32_t WDOG0CLKCTRL_TGL;              /**< Watchdog0 Clock Control                            */
  uint32_t       RESERVED68[7U];                /**< Reserved for future use                            */
  __IOM uint32_t EUART0CLKCTRL_TGL;             /**< UART Clock Control                                 */
  uint32_t       RESERVED69[7U];                /**< Reserved for future use                            */
  __IOM uint32_t RTCCCLKCTRL_TGL;               /**< RTCC Clock Control                                 */
  uint32_t       RESERVED70[7U];                /**< Reserved for future use                            */
  __IOM uint32_t CRYPTOACCCLKCTRL_TGL;          /**< CRYPTOACC Clock Control                            */
} CMU_TypeDef;
/** @} End of group EFM32PG22_CMU */

/**************************************************************************//**
 * @defgroup EFM32PG22_CRYPTOACC CRYPTOACC
 * @{
 * @brief EFM32PG22 CRYPTOACC Register Declaration.
 *****************************************************************************/

/** CRYPTOACC Register Declaration. */
typedef struct {
  __IOM uint32_t FETCHADDR;                     /**< Fetcher Address                                    */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t FETCHLEN;                      /**< Fetcher Length                                     */
  __IOM uint32_t FETCHTAG;                      /**< Fetcher Tag                                        */
  __IOM uint32_t PUSHADDR;                      /**< Pusher Address                                     */
  uint32_t       RESERVED1[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t PUSHLEN;                       /**< Pusher Length                                      */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  uint32_t       RESERVED2[2U];                 /**< Reserved for future use                            */
  __IM uint32_t  IF;                            /**< Interrupt Flags                                    */
  uint32_t       RESERVED3[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt status clear                             */
  __IOM uint32_t CTRL;                          /**< Control register                                   */
  __IOM uint32_t CMD;                           /**< Command register                                   */
  __IM uint32_t  STATUS;                        /**< Status register                                    */
  uint32_t       RESERVED4[240U];               /**< Reserved for future use                            */
  __IM uint32_t  INCL_IPS_HW_CFG;               /**< General CRYPTOACC Hardware Configuration           */
  __IM uint32_t  BA411E_HW_CFG_1;               /**< BA411E Hardware Configuration 1                    */
  __IM uint32_t  BA411E_HW_CFG_2;               /**< BA411E Hardware Configuration 2                    */
  __IM uint32_t  BA413_HW_CFG;                  /**< BA413 Hardware Configuration                       */
  __IM uint32_t  BA418_HW_CFG;                  /**< BA418 Hardware Configuration                       */
  __IM uint32_t  BA419_HW_CFG;                  /**< BA419 Hardware Configuration                       */
} CRYPTOACC_TypeDef;
/** @} End of group EFM32PG22_CRYPTOACC */

/**************************************************************************//**
 * @defgroup EFM32PG22_DCDC DCDC
 * @{
 * @brief EFM32PG22 DCDC Register Declaration.
 *****************************************************************************/

/** DCDC Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IPVERSION                                          */
  __IOM uint32_t EN;                            /**< Enable                                             */
  __IOM uint32_t CTRL;                          /**< Control                                            */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t EM01CTRL0;                     /**< EM01 Control                                       */
  __IOM uint32_t EM23CTRL0;                     /**< EM23 Control                                       */
  uint32_t       RESERVED1[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flags                                    */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED2[4U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Lock Register                                      */
  __IM uint32_t  LOCKSTATUS;                    /**< Lock Status Register                               */
  uint32_t       RESERVED3[2U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED5[7U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED7[995U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_SET;                        /**< Enable                                             */
  __IOM uint32_t CTRL_SET;                      /**< Control                                            */
  uint32_t       RESERVED8[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t EM01CTRL0_SET;                 /**< EM01 Control                                       */
  __IOM uint32_t EM23CTRL0_SET;                 /**< EM23 Control                                       */
  uint32_t       RESERVED9[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED10[4U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Lock Register                                      */
  __IM uint32_t  LOCKSTATUS_SET;                /**< Lock Status Register                               */
  uint32_t       RESERVED11[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED13[7U];                /**< Reserved for future use                            */
  uint32_t       RESERVED14[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED15[995U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_CLR;                        /**< Enable                                             */
  __IOM uint32_t CTRL_CLR;                      /**< Control                                            */
  uint32_t       RESERVED16[1U];                /**< Reserved for future use                            */
  __IOM uint32_t EM01CTRL0_CLR;                 /**< EM01 Control                                       */
  __IOM uint32_t EM23CTRL0_CLR;                 /**< EM23 Control                                       */
  uint32_t       RESERVED17[3U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED18[4U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Lock Register                                      */
  __IM uint32_t  LOCKSTATUS_CLR;                /**< Lock Status Register                               */
  uint32_t       RESERVED19[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED20[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED21[7U];                /**< Reserved for future use                            */
  uint32_t       RESERVED22[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED23[995U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_TGL;                        /**< Enable                                             */
  __IOM uint32_t CTRL_TGL;                      /**< Control                                            */
  uint32_t       RESERVED24[1U];                /**< Reserved for future use                            */
  __IOM uint32_t EM01CTRL0_TGL;                 /**< EM01 Control                                       */
  __IOM uint32_t EM23CTRL0_TGL;                 /**< EM23 Control                                       */
  uint32_t       RESERVED25[3U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED26[4U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Lock Register                                      */
  __IM uint32_t  LOCKSTATUS_TGL;                /**< Lock Status Register                               */
  uint32_t       RESERVED27[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED28[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED29[7U];                /**< Reserved for future use                            */
  uint32_t       RESERVED30[1U];                /**< Reserved for future use                            */
} DCDC_TypeDef;
/** @} End of group EFM32PG22_DCDC */

/**************************************************************************//**
 * @defgroup EFM32PG22_DEVINFO DEVINFO
 * @{
 * @brief EFM32PG22 DEVINFO Register Declaration.
 *****************************************************************************/

/** DEVINFO HFRCODPLLCAL Register Group Declaration. */
typedef struct {
  __IM uint32_t HFRCODPLLCAL;                        /**< HFRCODPLL Calibration                              */
} DEVINFO_HFRCODPLLCAL_TypeDef;

/** DEVINFO HFRCOEM23CAL Register Group Declaration. */
typedef struct {
  uint32_t RESERVED0[1U];                            /**< Reserved for future use                            */
} DEVINFO_HFRCOEM23CAL_TypeDef;

/** DEVINFO HFRCOSECAL Register Group Declaration. */
typedef struct {
  uint32_t RESERVED0[1U];                            /**< Reserved for future use                            */
} DEVINFO_HFRCOSECAL_TypeDef;

/** DEVINFO Register Declaration. */
typedef struct {
  __IM uint32_t                INFO;                  /**< DI Information                                     */
  __IM uint32_t                PART;                  /**< Part Info                                          */
  __IM uint32_t                MEMINFO;               /**< Memory Info                                        */
  __IM uint32_t                MSIZE;                 /**< Memory Size                                        */
  __IM uint32_t                PKGINFO;               /**< Misc Device Info                                   */
  __IM uint32_t                CUSTOMINFO;            /**< Custom Part Info                                   */
  __IM uint32_t                SWFIX;                 /**< SW Fix Register                                    */
  __IM uint32_t                SWCAPA0;               /**< Software Restriction                               */
  __IM uint32_t                SWCAPA1;               /**< Software Restriction                               */
  uint32_t                     RESERVED0[1U];         /**< Reserved for future use                            */
  __IM uint32_t                EXTINFO;               /**< External Component Info                            */
  uint32_t                     RESERVED1[2U];         /**< Reserved for future use                            */
  uint32_t                     RESERVED2[3U];         /**< Reserved for future use                            */
  __IM uint32_t                EUI48L;                /**< EUI 48 Low                                         */
  __IM uint32_t                EUI48H;                /**< EUI 48 High                                        */
  __IM uint32_t                EUI64L;                /**< EUI64 Low                                          */
  __IM uint32_t                EUI64H;                /**< EUI64 High                                         */
  __IM uint32_t                CALTEMP;               /**< Calibration temperature Information                */
  __IM uint32_t                EMUTEMP;               /**< EMU Temperature Sensor Calibration Information     */
  DEVINFO_HFRCODPLLCAL_TypeDef HFRCODPLLCAL[18U];     /**<                                                    */
  DEVINFO_HFRCOEM23CAL_TypeDef HFRCOEM23CAL[18U];     /**<                                                    */
  DEVINFO_HFRCOSECAL_TypeDef   HFRCOSECAL[18U];       /**<                                                    */
  __IM uint32_t                MODULENAME0;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME1;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME2;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME3;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME4;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME5;           /**< Module Name Information                            */
  __IM uint32_t                MODULENAME6;           /**< Module Name Information                            */
  __IM uint32_t                MODULEINFO;            /**< Module Information                                 */
  __IM uint32_t                MODXOCAL;              /**< Module External Oscillator Calibration Information */
  uint32_t                     RESERVED3[11U];        /**< Reserved for future use                            */
  __IM uint32_t                IADC0GAIN0;            /**< IADC Gain Calibration                              */
  __IM uint32_t                IADC0GAIN1;            /**< IADC Gain Calibration                              */
  __IM uint32_t                IADC0OFFSETCAL0;       /**< IADC Offset Calibration                            */
  __IM uint32_t                IADC0NORMALOFFSETCAL0; /**< IADC Offset Calibration                            */
  __IM uint32_t                IADC0NORMALOFFSETCAL1; /**< IADC Offset Calibration                            */
  __IM uint32_t                IADC0HISPDOFFSETCAL0;  /**< IADC Offset Calibration                            */
  __IM uint32_t                IADC0HISPDOFFSETCAL1;  /**< IADC Offset Calibration                            */
  uint32_t                     RESERVED4[24U];        /**< Reserved for future use                            */
  __IM uint32_t                LEGACY;                /**< Legacy Device Info                                 */
  uint32_t                     RESERVED5[23U];        /**< Reserved for future use                            */
  __IM uint32_t                RTHERM;                /**< Thermistor Calibration                             */
  uint32_t                     RESERVED6[80U];        /**< Reserved for future use                            */
  uint32_t                     RESERVED7[1U];         /**< Reserved for future use                            */
} DEVINFO_TypeDef;
/** @} End of group EFM32PG22_DEVINFO */

/**************************************************************************//**
 * @defgroup DMA_DESCRIPTOR DMA Descriptor
 * @{
 *****************************************************************************/
/** DMA_DESCRIPTOR Register Declaration */
typedef struct {
  /* Note! Use of double __IOM (volatile) qualifier to ensure that both */
  /* pointer and referenced memory are declared volatile. */
  __IOM uint32_t     CTRL;     /**< DMA control register */
  __IOM void * __IOM SRC;      /**< DMA source address */
  __IOM void * __IOM DST;      /**< DMA destination address */
  __IOM void * __IOM LINK;     /**< DMA link address */
} DMA_DESCRIPTOR_TypeDef;      /**< @} */

/** @} End of group Parts */

/**************************************************************************//**
 * @defgroup EFM32PG22_DPLL DPLL
 * @{
 * @brief EFM32PG22 DPLL Register Declaration.
 *****************************************************************************/

/** DPLL Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version                                         */
  __IOM uint32_t EN;                            /**< Enable                                             */
  __IOM uint32_t CFG;                           /**< Config                                             */
  __IOM uint32_t CFG1;                          /**< Config1                                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag                                     */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS;                        /**< Status                                             */
  uint32_t       RESERVED0[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Lock                                               */
  uint32_t       RESERVED1[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version                                         */
  __IOM uint32_t EN_SET;                        /**< Enable                                             */
  __IOM uint32_t CFG_SET;                       /**< Config                                             */
  __IOM uint32_t CFG1_SET;                      /**< Config1                                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status                                             */
  uint32_t       RESERVED2[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Lock                                               */
  uint32_t       RESERVED3[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version                                         */
  __IOM uint32_t EN_CLR;                        /**< Enable                                             */
  __IOM uint32_t CFG_CLR;                       /**< Config                                             */
  __IOM uint32_t CFG1_CLR;                      /**< Config1                                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status                                             */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Lock                                               */
  uint32_t       RESERVED5[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version                                         */
  __IOM uint32_t EN_TGL;                        /**< Enable                                             */
  __IOM uint32_t CFG_TGL;                       /**< Config                                             */
  __IOM uint32_t CFG1_TGL;                      /**< Config1                                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status                                             */
  uint32_t       RESERVED6[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Lock                                               */
} DPLL_TypeDef;
/** @} End of group EFM32PG22_DPLL */

/**************************************************************************//**
 * @defgroup EFM32PG22_EMU EMU
 * @{
 * @brief EFM32PG22 EMU Register Declaration.
 *****************************************************************************/

/** EMU Register Declaration. */
typedef struct {
  uint32_t       RESERVED0[4U];                 /**< Reserved for future use                            */
  __IOM uint32_t DECBOD;                        /**< DECOUPLE LVBOD  Control register                   */
  uint32_t       RESERVED1[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t BOD3SENSE;                     /**< BOD3SENSE Control register                         */
  uint32_t       RESERVED2[6U];                 /**< Reserved for future use                            */
  __IOM uint32_t VREGVDDCMPCTRL;                /**< DC-DC VREGVDD Comparator Control Register          */
  __IOM uint32_t PD1PARETCTRL;                  /**< PD1 Partial Retention Control                      */
  uint32_t       RESERVED3[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< EMU Configuration lock register                    */
  __IOM uint32_t IF;                            /**< Interrupt Flags                                    */
  __IOM uint32_t IEN;                           /**< Interrupt Enables                                  */
  __IOM uint32_t EM4CTRL;                       /**< EM4 Control                                        */
  __IOM uint32_t CMD;                           /**< EMU Command register                               */
  __IOM uint32_t CTRL;                          /**< EMU Control register                               */
  __IOM uint32_t TEMPLIMITS;                    /**< EMU Temperature thresholds                         */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< EMU Status register                                */
  __IM uint32_t  TEMP;                          /**< Temperature                                        */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t RSTCTRL;                       /**< Reset Management Control register                  */
  __IM uint32_t  RSTCAUSE;                      /**< Reset cause                                        */
  uint32_t       RESERVED6[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t DGIF;                          /**< Interrupt Flags Debug                              */
  __IOM uint32_t DGIEN;                         /**< Interrupt Enables Debug                            */
  uint32_t       RESERVED7[6U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED8[1U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED9[15U];                /**< Reserved for future use                            */
  __IOM uint32_t EFPIF;                         /**< EFP Interrupt Register                             */
  __IOM uint32_t EFPIEN;                        /**< EFP Interrupt Enable Register                      */
  uint32_t       RESERVED10[958U];              /**< Reserved for future use                            */
  uint32_t       RESERVED11[4U];                /**< Reserved for future use                            */
  __IOM uint32_t DECBOD_SET;                    /**< DECOUPLE LVBOD  Control register                   */
  uint32_t       RESERVED12[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BOD3SENSE_SET;                 /**< BOD3SENSE Control register                         */
  uint32_t       RESERVED13[6U];                /**< Reserved for future use                            */
  __IOM uint32_t VREGVDDCMPCTRL_SET;            /**< DC-DC VREGVDD Comparator Control Register          */
  __IOM uint32_t PD1PARETCTRL_SET;              /**< PD1 Partial Retention Control                      */
  uint32_t       RESERVED14[7U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< EMU Configuration lock register                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enables                                  */
  __IOM uint32_t EM4CTRL_SET;                   /**< EM4 Control                                        */
  __IOM uint32_t CMD_SET;                       /**< EMU Command register                               */
  __IOM uint32_t CTRL_SET;                      /**< EMU Control register                               */
  __IOM uint32_t TEMPLIMITS_SET;                /**< EMU Temperature thresholds                         */
  uint32_t       RESERVED15[2U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< EMU Status register                                */
  __IM uint32_t  TEMP_SET;                      /**< Temperature                                        */
  uint32_t       RESERVED16[1U];                /**< Reserved for future use                            */
  __IOM uint32_t RSTCTRL_SET;                   /**< Reset Management Control register                  */
  __IM uint32_t  RSTCAUSE_SET;                  /**< Reset cause                                        */
  uint32_t       RESERVED17[2U];                /**< Reserved for future use                            */
  __IOM uint32_t DGIF_SET;                      /**< Interrupt Flags Debug                              */
  __IOM uint32_t DGIEN_SET;                     /**< Interrupt Enables Debug                            */
  uint32_t       RESERVED18[6U];                /**< Reserved for future use                            */
  uint32_t       RESERVED19[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED20[15U];               /**< Reserved for future use                            */
  __IOM uint32_t EFPIF_SET;                     /**< EFP Interrupt Register                             */
  __IOM uint32_t EFPIEN_SET;                    /**< EFP Interrupt Enable Register                      */
  uint32_t       RESERVED21[958U];              /**< Reserved for future use                            */
  uint32_t       RESERVED22[4U];                /**< Reserved for future use                            */
  __IOM uint32_t DECBOD_CLR;                    /**< DECOUPLE LVBOD  Control register                   */
  uint32_t       RESERVED23[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BOD3SENSE_CLR;                 /**< BOD3SENSE Control register                         */
  uint32_t       RESERVED24[6U];                /**< Reserved for future use                            */
  __IOM uint32_t VREGVDDCMPCTRL_CLR;            /**< DC-DC VREGVDD Comparator Control Register          */
  __IOM uint32_t PD1PARETCTRL_CLR;              /**< PD1 Partial Retention Control                      */
  uint32_t       RESERVED25[7U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< EMU Configuration lock register                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enables                                  */
  __IOM uint32_t EM4CTRL_CLR;                   /**< EM4 Control                                        */
  __IOM uint32_t CMD_CLR;                       /**< EMU Command register                               */
  __IOM uint32_t CTRL_CLR;                      /**< EMU Control register                               */
  __IOM uint32_t TEMPLIMITS_CLR;                /**< EMU Temperature thresholds                         */
  uint32_t       RESERVED26[2U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< EMU Status register                                */
  __IM uint32_t  TEMP_CLR;                      /**< Temperature                                        */
  uint32_t       RESERVED27[1U];                /**< Reserved for future use                            */
  __IOM uint32_t RSTCTRL_CLR;                   /**< Reset Management Control register                  */
  __IM uint32_t  RSTCAUSE_CLR;                  /**< Reset cause                                        */
  uint32_t       RESERVED28[2U];                /**< Reserved for future use                            */
  __IOM uint32_t DGIF_CLR;                      /**< Interrupt Flags Debug                              */
  __IOM uint32_t DGIEN_CLR;                     /**< Interrupt Enables Debug                            */
  uint32_t       RESERVED29[6U];                /**< Reserved for future use                            */
  uint32_t       RESERVED30[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED31[15U];               /**< Reserved for future use                            */
  __IOM uint32_t EFPIF_CLR;                     /**< EFP Interrupt Register                             */
  __IOM uint32_t EFPIEN_CLR;                    /**< EFP Interrupt Enable Register                      */
  uint32_t       RESERVED32[958U];              /**< Reserved for future use                            */
  uint32_t       RESERVED33[4U];                /**< Reserved for future use                            */
  __IOM uint32_t DECBOD_TGL;                    /**< DECOUPLE LVBOD  Control register                   */
  uint32_t       RESERVED34[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BOD3SENSE_TGL;                 /**< BOD3SENSE Control register                         */
  uint32_t       RESERVED35[6U];                /**< Reserved for future use                            */
  __IOM uint32_t VREGVDDCMPCTRL_TGL;            /**< DC-DC VREGVDD Comparator Control Register          */
  __IOM uint32_t PD1PARETCTRL_TGL;              /**< PD1 Partial Retention Control                      */
  uint32_t       RESERVED36[7U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< EMU Configuration lock register                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flags                                    */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enables                                  */
  __IOM uint32_t EM4CTRL_TGL;                   /**< EM4 Control                                        */
  __IOM uint32_t CMD_TGL;                       /**< EMU Command register                               */
  __IOM uint32_t CTRL_TGL;                      /**< EMU Control register                               */
  __IOM uint32_t TEMPLIMITS_TGL;                /**< EMU Temperature thresholds                         */
  uint32_t       RESERVED37[2U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< EMU Status register                                */
  __IM uint32_t  TEMP_TGL;                      /**< Temperature                                        */
  uint32_t       RESERVED38[1U];                /**< Reserved for future use                            */
  __IOM uint32_t RSTCTRL_TGL;                   /**< Reset Management Control register                  */
  __IM uint32_t  RSTCAUSE_TGL;                  /**< Reset cause                                        */
  uint32_t       RESERVED39[2U];                /**< Reserved for future use                            */
  __IOM uint32_t DGIF_TGL;                      /**< Interrupt Flags Debug                              */
  __IOM uint32_t DGIEN_TGL;                     /**< Interrupt Enables Debug                            */
  uint32_t       RESERVED40[6U];                /**< Reserved for future use                            */
  uint32_t       RESERVED41[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED42[15U];               /**< Reserved for future use                            */
  __IOM uint32_t EFPIF_TGL;                     /**< EFP Interrupt Register                             */
  __IOM uint32_t EFPIEN_TGL;                    /**< EFP Interrupt Enable Register                      */
} EMU_TypeDef;
/** @} End of group EFM32PG22_EMU */

/**************************************************************************//**
 * @defgroup EFM32PG22_EUSART EUSART
 * @{
 * @brief EFM32PG22 EUSART Register Declaration.
 *****************************************************************************/

/** EUSART Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version ID                                      */
  __IOM uint32_t EN;                            /**< Enable Register                                    */
  __IOM uint32_t CFG0;                          /**< Configuration 0 Register                           */
  __IOM uint32_t CFG1;                          /**< Configuration 1 Register                           */
  __IOM uint32_t FRAMECFG;                      /**< Frame Format Register                              */
  __IOM uint32_t IRHFCFG;                       /**< HF IrDA Mod Config Register                        */
  __IOM uint32_t IRLFCFG;                       /**< LF IrDA Pulse Config Register                      */
  __IOM uint32_t TIMINGCFG;                     /**< Timing Register                                    */
  __IOM uint32_t STARTFRAMECFG;                 /**< Start Frame Register                               */
  __IOM uint32_t SIGFRAMECFG;                   /**< Signal Frame Register                              */
  __IOM uint32_t CLKDIV;                        /**< Clock Divider Register                             */
  __IOM uint32_t TRIGCTRL;                      /**< Trigger Control Register                           */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IM uint32_t  RXDATA;                        /**< RX Data Register                                   */
  __IM uint32_t  RXDATAP;                       /**< RX Data Peek Register                              */
  __IOM uint32_t TXDATA;                        /**< TX Data Register                                   */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY;                      /**< Synchronization Busy Register                      */
  uint32_t       RESERVED0[1004U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version ID                                      */
  __IOM uint32_t EN_SET;                        /**< Enable Register                                    */
  __IOM uint32_t CFG0_SET;                      /**< Configuration 0 Register                           */
  __IOM uint32_t CFG1_SET;                      /**< Configuration 1 Register                           */
  __IOM uint32_t FRAMECFG_SET;                  /**< Frame Format Register                              */
  __IOM uint32_t IRHFCFG_SET;                   /**< HF IrDA Mod Config Register                        */
  __IOM uint32_t IRLFCFG_SET;                   /**< LF IrDA Pulse Config Register                      */
  __IOM uint32_t TIMINGCFG_SET;                 /**< Timing Register                                    */
  __IOM uint32_t STARTFRAMECFG_SET;             /**< Start Frame Register                               */
  __IOM uint32_t SIGFRAMECFG_SET;               /**< Signal Frame Register                              */
  __IOM uint32_t CLKDIV_SET;                    /**< Clock Divider Register                             */
  __IOM uint32_t TRIGCTRL_SET;                  /**< Trigger Control Register                           */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IM uint32_t  RXDATA_SET;                    /**< RX Data Register                                   */
  __IM uint32_t  RXDATAP_SET;                   /**< RX Data Peek Register                              */
  __IOM uint32_t TXDATA_SET;                    /**< TX Data Register                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_SET;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED1[1004U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version ID                                      */
  __IOM uint32_t EN_CLR;                        /**< Enable Register                                    */
  __IOM uint32_t CFG0_CLR;                      /**< Configuration 0 Register                           */
  __IOM uint32_t CFG1_CLR;                      /**< Configuration 1 Register                           */
  __IOM uint32_t FRAMECFG_CLR;                  /**< Frame Format Register                              */
  __IOM uint32_t IRHFCFG_CLR;                   /**< HF IrDA Mod Config Register                        */
  __IOM uint32_t IRLFCFG_CLR;                   /**< LF IrDA Pulse Config Register                      */
  __IOM uint32_t TIMINGCFG_CLR;                 /**< Timing Register                                    */
  __IOM uint32_t STARTFRAMECFG_CLR;             /**< Start Frame Register                               */
  __IOM uint32_t SIGFRAMECFG_CLR;               /**< Signal Frame Register                              */
  __IOM uint32_t CLKDIV_CLR;                    /**< Clock Divider Register                             */
  __IOM uint32_t TRIGCTRL_CLR;                  /**< Trigger Control Register                           */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IM uint32_t  RXDATA_CLR;                    /**< RX Data Register                                   */
  __IM uint32_t  RXDATAP_CLR;                   /**< RX Data Peek Register                              */
  __IOM uint32_t TXDATA_CLR;                    /**< TX Data Register                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED2[1004U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version ID                                      */
  __IOM uint32_t EN_TGL;                        /**< Enable Register                                    */
  __IOM uint32_t CFG0_TGL;                      /**< Configuration 0 Register                           */
  __IOM uint32_t CFG1_TGL;                      /**< Configuration 1 Register                           */
  __IOM uint32_t FRAMECFG_TGL;                  /**< Frame Format Register                              */
  __IOM uint32_t IRHFCFG_TGL;                   /**< HF IrDA Mod Config Register                        */
  __IOM uint32_t IRLFCFG_TGL;                   /**< LF IrDA Pulse Config Register                      */
  __IOM uint32_t TIMINGCFG_TGL;                 /**< Timing Register                                    */
  __IOM uint32_t STARTFRAMECFG_TGL;             /**< Start Frame Register                               */
  __IOM uint32_t SIGFRAMECFG_TGL;               /**< Signal Frame Register                              */
  __IOM uint32_t CLKDIV_TGL;                    /**< Clock Divider Register                             */
  __IOM uint32_t TRIGCTRL_TGL;                  /**< Trigger Control Register                           */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IM uint32_t  RXDATA_TGL;                    /**< RX Data Register                                   */
  __IM uint32_t  RXDATAP_TGL;                   /**< RX Data Peek Register                              */
  __IOM uint32_t TXDATA_TGL;                    /**< TX Data Register                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< Synchronization Busy Register                      */
} EUSART_TypeDef;
/** @} End of group EFM32PG22_EUSART */

/**************************************************************************//**
 * @defgroup EFM32PG22_FSRCO FSRCO
 * @{
 * @brief EFM32PG22 FSRCO Register Declaration.
 *****************************************************************************/

/** FSRCO Register Declaration. */
typedef struct {
  __IM uint32_t IPVERSION;                      /**< IP Version                                         */
  uint32_t      RESERVED0[1023U];               /**< Reserved for future use                            */
  __IM uint32_t IPVERSION_SET;                  /**< IP Version                                         */
  uint32_t      RESERVED1[1023U];               /**< Reserved for future use                            */
  __IM uint32_t IPVERSION_CLR;                  /**< IP Version                                         */
  uint32_t      RESERVED2[1023U];               /**< Reserved for future use                            */
  __IM uint32_t IPVERSION_TGL;                  /**< IP Version                                         */
} FSRCO_TypeDef;
/** @} End of group EFM32PG22_FSRCO */

/**************************************************************************//**
 * @defgroup EFM32PG22_GPCRC GPCRC
 * @{
 * @brief EFM32PG22 GPCRC Register Declaration.
 *****************************************************************************/

/** GPCRC Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version ID                                      */
  __IOM uint32_t EN;                            /**< CRC Enable                                         */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IOM uint32_t INIT;                          /**< CRC Init Value                                     */
  __IOM uint32_t POLY;                          /**< CRC Polynomial Value                               */
  __IOM uint32_t INPUTDATA;                     /**< Input 32-bit Data Register                         */
  __IOM uint32_t INPUTDATAHWORD;                /**< Input 16-bit Data Register                         */
  __IOM uint32_t INPUTDATABYTE;                 /**< Input 8-bit Data Register                          */
  __IM uint32_t  DATA;                          /**< CRC Data Register                                  */
  __IM uint32_t  DATAREV;                       /**< CRC Data Reverse Register                          */
  __IM uint32_t  DATABYTEREV;                   /**< CRC Data Byte Reverse Register                     */
  uint32_t       RESERVED0[1012U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_SET;                        /**< CRC Enable                                         */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IOM uint32_t INIT_SET;                      /**< CRC Init Value                                     */
  __IOM uint32_t POLY_SET;                      /**< CRC Polynomial Value                               */
  __IOM uint32_t INPUTDATA_SET;                 /**< Input 32-bit Data Register                         */
  __IOM uint32_t INPUTDATAHWORD_SET;            /**< Input 16-bit Data Register                         */
  __IOM uint32_t INPUTDATABYTE_SET;             /**< Input 8-bit Data Register                          */
  __IM uint32_t  DATA_SET;                      /**< CRC Data Register                                  */
  __IM uint32_t  DATAREV_SET;                   /**< CRC Data Reverse Register                          */
  __IM uint32_t  DATABYTEREV_SET;               /**< CRC Data Byte Reverse Register                     */
  uint32_t       RESERVED1[1012U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_CLR;                        /**< CRC Enable                                         */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IOM uint32_t INIT_CLR;                      /**< CRC Init Value                                     */
  __IOM uint32_t POLY_CLR;                      /**< CRC Polynomial Value                               */
  __IOM uint32_t INPUTDATA_CLR;                 /**< Input 32-bit Data Register                         */
  __IOM uint32_t INPUTDATAHWORD_CLR;            /**< Input 16-bit Data Register                         */
  __IOM uint32_t INPUTDATABYTE_CLR;             /**< Input 8-bit Data Register                          */
  __IM uint32_t  DATA_CLR;                      /**< CRC Data Register                                  */
  __IM uint32_t  DATAREV_CLR;                   /**< CRC Data Reverse Register                          */
  __IM uint32_t  DATABYTEREV_CLR;               /**< CRC Data Byte Reverse Register                     */
  uint32_t       RESERVED2[1012U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_TGL;                        /**< CRC Enable                                         */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IOM uint32_t INIT_TGL;                      /**< CRC Init Value                                     */
  __IOM uint32_t POLY_TGL;                      /**< CRC Polynomial Value                               */
  __IOM uint32_t INPUTDATA_TGL;                 /**< Input 32-bit Data Register                         */
  __IOM uint32_t INPUTDATAHWORD_TGL;            /**< Input 16-bit Data Register                         */
  __IOM uint32_t INPUTDATABYTE_TGL;             /**< Input 8-bit Data Register                          */
  __IM uint32_t  DATA_TGL;                      /**< CRC Data Register                                  */
  __IM uint32_t  DATAREV_TGL;                   /**< CRC Data Reverse Register                          */
  __IM uint32_t  DATABYTEREV_TGL;               /**< CRC Data Byte Reverse Register                     */
} GPCRC_TypeDef;
/** @} End of group EFM32PG22_GPCRC */

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< CMU pin enable                                     */
  __IOM uint32_t CLKIN0ROUTE;                        /**< CLKIN0 port/pin select                             */
  __IOM uint32_t CLKOUT0ROUTE;                       /**< CLKOUT0 port/pin select                            */
  __IOM uint32_t CLKOUT1ROUTE;                       /**< CLKOUT1 port/pin select                            */
  __IOM uint32_t CLKOUT2ROUTE;                       /**< CLKOUT2 port/pin select                            */
  uint32_t       RESERVED0[2U];                      /**< Reserved for future use                            */
} GPIO_CMUROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< DCDC pin enable                                    */
  uint32_t       RESERVED0[3U];                      /**< Reserved for future use                            */
} GPIO_DCDCROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< I2C0 pin enable                                    */
  __IOM uint32_t SCLROUTE;                           /**< SCL port/pin select                                */
  __IOM uint32_t SDAROUTE;                           /**< SDA port/pin select                                */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_I2CROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< LETIMER pin enable                                 */
  __IOM uint32_t OUT0ROUTE;                          /**< OUT0 port/pin select                               */
  __IOM uint32_t OUT1ROUTE;                          /**< OUT1 port/pin select                               */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_LETIMERROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< EUART pin enable                                   */
  __IOM uint32_t CTSROUTE;                           /**< CTS port/pin select                                */
  __IOM uint32_t RTSROUTE;                           /**< RTS port/pin select                                */
  __IOM uint32_t RXROUTE;                            /**< RX port/pin select                                 */
  __IOM uint32_t TXROUTE;                            /**< TX port/pin select                                 */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_EUARTROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< PDM pin enable                                     */
  __IOM uint32_t CLKROUTE;                           /**< CLK port/pin select                                */
  __IOM uint32_t DAT0ROUTE;                          /**< DAT0 port/pin select                               */
  __IOM uint32_t DAT1ROUTE;                          /**< DAT1 port/pin select                               */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_PDMROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< PRS0 pin enable                                    */
  __IOM uint32_t ASYNCH0ROUTE;                       /**< ASYNCH0 port/pin select                            */
  __IOM uint32_t ASYNCH1ROUTE;                       /**< ASYNCH1 port/pin select                            */
  __IOM uint32_t ASYNCH2ROUTE;                       /**< ASYNCH2 port/pin select                            */
  __IOM uint32_t ASYNCH3ROUTE;                       /**< ASYNCH3 port/pin select                            */
  __IOM uint32_t ASYNCH4ROUTE;                       /**< ASYNCH4 port/pin select                            */
  __IOM uint32_t ASYNCH5ROUTE;                       /**< ASYNCH5 port/pin select                            */
  __IOM uint32_t ASYNCH6ROUTE;                       /**< ASYNCH6 port/pin select                            */
  __IOM uint32_t ASYNCH7ROUTE;                       /**< ASYNCH7 port/pin select                            */
  __IOM uint32_t ASYNCH8ROUTE;                       /**< ASYNCH8 port/pin select                            */
  __IOM uint32_t ASYNCH9ROUTE;                       /**< ASYNCH9 port/pin select                            */
  __IOM uint32_t ASYNCH10ROUTE;                      /**< ASYNCH10 port/pin select                           */
  __IOM uint32_t ASYNCH11ROUTE;                      /**< ASYNCH11 port/pin select                           */
  __IOM uint32_t SYNCH0ROUTE;                        /**< SYNCH0 port/pin select                             */
  __IOM uint32_t SYNCH1ROUTE;                        /**< SYNCH1 port/pin select                             */
  __IOM uint32_t SYNCH2ROUTE;                        /**< SYNCH2 port/pin select                             */
  __IOM uint32_t SYNCH3ROUTE;                        /**< SYNCH3 port/pin select                             */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_PRSROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< TIMER0 pin enable                                  */
  __IOM uint32_t CC0ROUTE;                           /**< CC0 port/pin select                                */
  __IOM uint32_t CC1ROUTE;                           /**< CC1 port/pin select                                */
  __IOM uint32_t CC2ROUTE;                           /**< CC2 port/pin select                                */
  __IOM uint32_t CDTI0ROUTE;                         /**< CDTI0 port/pin select                              */
  __IOM uint32_t CDTI1ROUTE;                         /**< CDTI1 port/pin select                              */
  __IOM uint32_t CDTI2ROUTE;                         /**< CDTI2 port/pin select                              */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_TIMERROUTE_TypeDef;

typedef struct {
  __IOM uint32_t ROUTEEN;                            /**< USART0 pin enable                                  */
  __IOM uint32_t CSROUTE;                            /**< CS port/pin select                                 */
  __IOM uint32_t CTSROUTE;                           /**< CTS port/pin select                                */
  __IOM uint32_t RTSROUTE;                           /**< RTS port/pin select                                */
  __IOM uint32_t RXROUTE;                            /**< RX port/pin select                                 */
  __IOM uint32_t CLKROUTE;                           /**< SCLK port/pin select                               */
  __IOM uint32_t TXROUTE;                            /**< TX port/pin select                                 */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
} GPIO_USARTROUTE_TypeDef;

typedef struct {
  __IOM uint32_t CTRL;                          /**< Port control            */
  __IOM uint32_t MODEL;                         /**< mode low                */
  uint32_t       RESERVED0[1];                  /**< Reserved for future use */
  __IOM uint32_t MODEH;                         /**< mode high               */
  __IOM uint32_t DOUT;                          /**< data out                */
  __IM uint32_t  DIN;                           /**< data in                 */
  uint32_t       RESERVED1[6];                  /**< Reserved for future use */
} GPIO_PORT_TypeDef;

typedef struct {
  GPIO_PORT_TypeDef         P[4U];                   /**<                                                    */
  uint32_t                  RESERVED0[144U];         /**< Reserved for future use                            */
  __IOM uint32_t            LOCK;                    /**< Lock Register                                      */
  uint32_t                  RESERVED1[3U];           /**< Reserved for future use                            */
  __IM uint32_t             GPIOLOCKSTATUS;          /**< Lock Status                                        */
  uint32_t                  RESERVED2[3U];           /**< Reserved for future use                            */
  __IOM uint32_t            ABUSALLOC;               /**< A Bus allocation                                   */
  __IOM uint32_t            BBUSALLOC;               /**< B Bus allocation                                   */
  __IOM uint32_t            CDBUSALLOC;              /**< CD Bus allocation                                  */
  uint32_t                  RESERVED3[53U];          /**< Reserved for future use                            */
  __IOM uint32_t            EXTIPSELL;               /**< External Interrupt Port Select Low                 */
  __IOM uint32_t            EXTIPSELH;               /**< External interrupt Port Select High                */
  __IOM uint32_t            EXTIPINSELL;             /**< External Interrupt Pin Select Low                  */
  __IOM uint32_t            EXTIPINSELH;             /**< External Interrupt Pin Select High                 */
  __IOM uint32_t            EXTIRISE;                /**< External Interrupt Rising Edge Trigger             */
  __IOM uint32_t            EXTIFALL;                /**< External Interrupt Falling Edge Trigger            */
  uint32_t                  RESERVED4[2U];           /**< Reserved for future use                            */
  __IOM uint32_t            IF;                      /**< Interrupt Flag                                     */
  __IOM uint32_t            IEN;                     /**< Interrupt Enable                                   */
  uint32_t                  RESERVED5[1U];           /**< Reserved for future use                            */
  __IOM uint32_t            EM4WUEN;                 /**< EM4 wakeup enable                                  */
  __IOM uint32_t            EM4WUPOL;                /**< EM4 wakeup polarity                                */
  uint32_t                  RESERVED6[3U];           /**< Reserved for future use                            */
  __IOM uint32_t            DBGROUTEPEN;             /**< Debugger Route Pin enable                          */
  __IOM uint32_t            TRACEROUTEPEN;           /**< Trace Route Pin Enable                             */
  uint32_t                  RESERVED7[2U];           /**< Reserved for future use                            */
  GPIO_CMUROUTE_TypeDef     CMUROUTE;                /**< cmu DBUS config registers                          */
  GPIO_DCDCROUTE_TypeDef    DCDCROUTE;               /**< dcdc DBUS config registers                         */
  uint32_t                  RESERVED8[5U];           /**< Reserved for future use                            */
  GPIO_I2CROUTE_TypeDef     I2CROUTE[2U];            /**< i2c0 DBUS config registers                         */
  GPIO_LETIMERROUTE_TypeDef LETIMERROUTE[1U];        /**< letimer DBUS config registers                      */
  GPIO_EUARTROUTE_TypeDef   EUARTROUTE[1U];          /**< leuart DBUS config registers                       */
  uint32_t                  RESERVED9[18U];          /**< Reserved for future use                            */
  GPIO_PDMROUTE_TypeDef     PDMROUTE;                /**< pdm DBUS config registers                          */
  GPIO_PRSROUTE_TypeDef     PRSROUTE[1U];            /**< prs0 DBUS config registers                         */
  GPIO_TIMERROUTE_TypeDef   TIMERROUTE[5U];          /**< timer0 DBUS config registers                       */
  GPIO_USARTROUTE_TypeDef   USARTROUTE[2U];          /**< usart0 DBUS config registers                       */
  uint32_t                  RESERVED10[617U];        /**< Reserved for future use                            */
  GPIO_PORT_TypeDef         P_SET[4U];               /**<                                                    */
  uint32_t                  RESERVED11[144U];        /**< Reserved for future use                            */
  __IOM uint32_t            LOCK_SET;                /**< Lock Register                                      */
  uint32_t                  RESERVED12[3U];          /**< Reserved for future use                            */
  __IM uint32_t             GPIOLOCKSTATUS_SET;      /**< Lock Status                                        */
  uint32_t                  RESERVED13[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            ABUSALLOC_SET;           /**< A Bus allocation                                   */
  __IOM uint32_t            BBUSALLOC_SET;           /**< B Bus allocation                                   */
  __IOM uint32_t            CDBUSALLOC_SET;          /**< CD Bus allocation                                  */
  uint32_t                  RESERVED14[53U];         /**< Reserved for future use                            */
  __IOM uint32_t            EXTIPSELL_SET;           /**< External Interrupt Port Select Low                 */
  __IOM uint32_t            EXTIPSELH_SET;           /**< External interrupt Port Select High                */
  __IOM uint32_t            EXTIPINSELL_SET;         /**< External Interrupt Pin Select Low                  */
  __IOM uint32_t            EXTIPINSELH_SET;         /**< External Interrupt Pin Select High                 */
  __IOM uint32_t            EXTIRISE_SET;            /**< External Interrupt Rising Edge Trigger             */
  __IOM uint32_t            EXTIFALL_SET;            /**< External Interrupt Falling Edge Trigger            */
  uint32_t                  RESERVED15[2U];          /**< Reserved for future use                            */
  __IOM uint32_t            IF_SET;                  /**< Interrupt Flag                                     */
  __IOM uint32_t            IEN_SET;                 /**< Interrupt Enable                                   */
  uint32_t                  RESERVED16[1U];          /**< Reserved for future use                            */
  __IOM uint32_t            EM4WUEN_SET;             /**< EM4 wakeup enable                                  */
  __IOM uint32_t            EM4WUPOL_SET;            /**< EM4 wakeup polarity                                */
  uint32_t                  RESERVED17[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            DBGROUTEPEN_SET;         /**< Debugger Route Pin enable                          */
  __IOM uint32_t            TRACEROUTEPEN_SET;       /**< Trace Route Pin Enable                             */
  uint32_t                  RESERVED18[2U];          /**< Reserved for future use                            */
  GPIO_CMUROUTE_TypeDef     CMUROUTE_SET;            /**< cmu DBUS config registers                          */
  GPIO_DCDCROUTE_TypeDef    DCDCROUTE_SET;           /**< dcdc DBUS config registers                         */
  uint32_t                  RESERVED19[5U];          /**< Reserved for future use                            */
  GPIO_I2CROUTE_TypeDef     I2CROUTE_SET[2U];        /**< i2c0 DBUS config registers                         */
  GPIO_LETIMERROUTE_TypeDef LETIMERROUTE_SET[1U];    /**< letimer DBUS config registers                      */
  GPIO_EUARTROUTE_TypeDef   EUARTROUTE_SET[1U];      /**< leuart DBUS config registers                       */
  uint32_t                  RESERVED20[18U];         /**< Reserved for future use                            */
  GPIO_PDMROUTE_TypeDef     PDMROUTE_SET;            /**< pdm DBUS config registers                          */
  GPIO_PRSROUTE_TypeDef     PRSROUTE_SET[1U];        /**< prs0 DBUS config registers                         */
  GPIO_TIMERROUTE_TypeDef   TIMERROUTE_SET[5U];      /**< timer0 DBUS config registers                       */
  GPIO_USARTROUTE_TypeDef   USARTROUTE_SET[2U];      /**< usart0 DBUS config registers                       */
  uint32_t                  RESERVED21[617U];        /**< Reserved for future use                            */
  GPIO_PORT_TypeDef         P_CLR[4U];               /**<                                                    */
  uint32_t                  RESERVED22[144U];        /**< Reserved for future use                            */
  __IOM uint32_t            LOCK_CLR;                /**< Lock Register                                      */
  uint32_t                  RESERVED23[3U];          /**< Reserved for future use                            */
  __IM uint32_t             GPIOLOCKSTATUS_CLR;      /**< Lock Status                                        */
  uint32_t                  RESERVED24[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            ABUSALLOC_CLR;           /**< A Bus allocation                                   */
  __IOM uint32_t            BBUSALLOC_CLR;           /**< B Bus allocation                                   */
  __IOM uint32_t            CDBUSALLOC_CLR;          /**< CD Bus allocation                                  */
  uint32_t                  RESERVED25[53U];         /**< Reserved for future use                            */
  __IOM uint32_t            EXTIPSELL_CLR;           /**< External Interrupt Port Select Low                 */
  __IOM uint32_t            EXTIPSELH_CLR;           /**< External interrupt Port Select High                */
  __IOM uint32_t            EXTIPINSELL_CLR;         /**< External Interrupt Pin Select Low                  */
  __IOM uint32_t            EXTIPINSELH_CLR;         /**< External Interrupt Pin Select High                 */
  __IOM uint32_t            EXTIRISE_CLR;            /**< External Interrupt Rising Edge Trigger             */
  __IOM uint32_t            EXTIFALL_CLR;            /**< External Interrupt Falling Edge Trigger            */
  uint32_t                  RESERVED26[2U];          /**< Reserved for future use                            */
  __IOM uint32_t            IF_CLR;                  /**< Interrupt Flag                                     */
  __IOM uint32_t            IEN_CLR;                 /**< Interrupt Enable                                   */
  uint32_t                  RESERVED27[1U];          /**< Reserved for future use                            */
  __IOM uint32_t            EM4WUEN_CLR;             /**< EM4 wakeup enable                                  */
  __IOM uint32_t            EM4WUPOL_CLR;            /**< EM4 wakeup polarity                                */
  uint32_t                  RESERVED28[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            DBGROUTEPEN_CLR;         /**< Debugger Route Pin enable                          */
  __IOM uint32_t            TRACEROUTEPEN_CLR;       /**< Trace Route Pin Enable                             */
  uint32_t                  RESERVED29[2U];          /**< Reserved for future use                            */
  GPIO_CMUROUTE_TypeDef     CMUROUTE_CLR;            /**< cmu DBUS config registers                          */
  GPIO_DCDCROUTE_TypeDef    DCDCROUTE_CLR;           /**< dcdc DBUS config registers                         */
  uint32_t                  RESERVED30[5U];          /**< Reserved for future use                            */
  GPIO_I2CROUTE_TypeDef     I2CROUTE_CLR[2U];        /**< i2c0 DBUS config registers                         */
  GPIO_LETIMERROUTE_TypeDef LETIMERROUTE_CLR[1U];    /**< letimer DBUS config registers                      */
  GPIO_EUARTROUTE_TypeDef   EUARTROUTE_CLR[1U];      /**< leuart DBUS config registers                       */
  uint32_t                  RESERVED31[18U];         /**< Reserved for future use                            */
  GPIO_PDMROUTE_TypeDef     PDMROUTE_CLR;            /**< pdm DBUS config registers                          */
  GPIO_PRSROUTE_TypeDef     PRSROUTE_CLR[1U];        /**< prs0 DBUS config registers                         */
  GPIO_TIMERROUTE_TypeDef   TIMERROUTE_CLR[5U];      /**< timer0 DBUS config registers                       */
  GPIO_USARTROUTE_TypeDef   USARTROUTE_CLR[2U];      /**< usart0 DBUS config registers                       */
  uint32_t                  RESERVED32[617U];        /**< Reserved for future use                            */
  GPIO_PORT_TypeDef         P_TGL[4U];               /**<                                                    */
  uint32_t                  RESERVED33[144U];        /**< Reserved for future use                            */
  __IOM uint32_t            LOCK_TGL;                /**< Lock Register                                      */
  uint32_t                  RESERVED34[3U];          /**< Reserved for future use                            */
  __IM uint32_t             GPIOLOCKSTATUS_TGL;      /**< Lock Status                                        */
  uint32_t                  RESERVED35[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            ABUSALLOC_TGL;           /**< A Bus allocation                                   */
  __IOM uint32_t            BBUSALLOC_TGL;           /**< B Bus allocation                                   */
  __IOM uint32_t            CDBUSALLOC_TGL;          /**< CD Bus allocation                                  */
  uint32_t                  RESERVED36[53U];         /**< Reserved for future use                            */
  __IOM uint32_t            EXTIPSELL_TGL;           /**< External Interrupt Port Select Low                 */
  __IOM uint32_t            EXTIPSELH_TGL;           /**< External interrupt Port Select High                */
  __IOM uint32_t            EXTIPINSELL_TGL;         /**< External Interrupt Pin Select Low                  */
  __IOM uint32_t            EXTIPINSELH_TGL;         /**< External Interrupt Pin Select High                 */
  __IOM uint32_t            EXTIRISE_TGL;            /**< External Interrupt Rising Edge Trigger             */
  __IOM uint32_t            EXTIFALL_TGL;            /**< External Interrupt Falling Edge Trigger            */
  uint32_t                  RESERVED37[2U];          /**< Reserved for future use                            */
  __IOM uint32_t            IF_TGL;                  /**< Interrupt Flag                                     */
  __IOM uint32_t            IEN_TGL;                 /**< Interrupt Enable                                   */
  uint32_t                  RESERVED38[1U];          /**< Reserved for future use                            */
  __IOM uint32_t            EM4WUEN_TGL;             /**< EM4 wakeup enable                                  */
  __IOM uint32_t            EM4WUPOL_TGL;            /**< EM4 wakeup polarity                                */
  uint32_t                  RESERVED39[3U];          /**< Reserved for future use                            */
  __IOM uint32_t            DBGROUTEPEN_TGL;         /**< Debugger Route Pin enable                          */
  __IOM uint32_t            TRACEROUTEPEN_TGL;       /**< Trace Route Pin Enable                             */
  uint32_t                  RESERVED40[2U];          /**< Reserved for future use                            */
  GPIO_CMUROUTE_TypeDef     CMUROUTE_TGL;            /**< cmu DBUS config registers                          */
  GPIO_DCDCROUTE_TypeDef    DCDCROUTE_TGL;           /**< dcdc DBUS config registers                         */
  uint32_t                  RESERVED41[5U];          /**< Reserved for future use                            */
  GPIO_I2CROUTE_TypeDef     I2CROUTE_TGL[2U];        /**< i2c0 DBUS config registers                         */
  GPIO_LETIMERROUTE_TypeDef LETIMERROUTE_TGL[1U];    /**< letimer DBUS config registers                      */
  GPIO_EUARTROUTE_TypeDef   EUARTROUTE_TGL[1U];      /**< leuart DBUS config registers                       */
  uint32_t                  RESERVED42[18U];         /**< Reserved for future use                            */
  GPIO_PDMROUTE_TypeDef     PDMROUTE_TGL;            /**< pdm DBUS config registers                          */
  GPIO_PRSROUTE_TypeDef     PRSROUTE_TGL[1U];        /**< prs0 DBUS config registers                         */
  GPIO_TIMERROUTE_TypeDef   TIMERROUTE_TGL[5U];      /**< timer0 DBUS config registers                       */
  GPIO_USARTROUTE_TypeDef   USARTROUTE_TGL[2U];      /**< usart0 DBUS config registers                       */
} GPIO_TypeDef;

/**************************************************************************//**
 * @defgroup EFM32PG22_HFRCO HFRCO
 * @{
 * @brief EFM32PG22 HFRCO Register Declaration.
 *****************************************************************************/

/** HFRCO Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version ID                                      */
  __IOM uint32_t CTRL;                          /**< Ctrl Register                                      */
  __IOM uint32_t CAL;                           /**< Calibration Register                               */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Lock Register                                      */
  uint32_t       RESERVED1[1016U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version ID                                      */
  __IOM uint32_t CTRL_SET;                      /**< Ctrl Register                                      */
  __IOM uint32_t CAL_SET;                       /**< Calibration Register                               */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Lock Register                                      */
  uint32_t       RESERVED3[1016U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version ID                                      */
  __IOM uint32_t CTRL_CLR;                      /**< Ctrl Register                                      */
  __IOM uint32_t CAL_CLR;                       /**< Calibration Register                               */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Lock Register                                      */
  uint32_t       RESERVED5[1016U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version ID                                      */
  __IOM uint32_t CTRL_TGL;                      /**< Ctrl Register                                      */
  __IOM uint32_t CAL_TGL;                       /**< Calibration Register                               */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Lock Register                                      */
} HFRCO_TypeDef;
/** @} End of group EFM32PG22_HFRCO */

/**************************************************************************//**
 * @defgroup EFM32PG22_HFXO HFXO
 * @{
 * @brief EFM32PG22 HFXO Register Declaration.
 *****************************************************************************/

/** HFXO Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version ID                                      */
  uint32_t       RESERVED0[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t XTALCFG;                       /**< Crystal Configuration Register                     */
  uint32_t       RESERVED1[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t XTALCTRL;                      /**< Crystal Control Register                           */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CFG;                           /**< Configuration Register                             */
  uint32_t       RESERVED3[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  uint32_t       RESERVED4[9U];                 /**< Reserved for future use                            */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED6[5U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED7[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  uint32_t       RESERVED8[991U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version ID                                      */
  uint32_t       RESERVED9[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t XTALCFG_SET;                   /**< Crystal Configuration Register                     */
  uint32_t       RESERVED10[1U];                /**< Reserved for future use                            */
  __IOM uint32_t XTALCTRL_SET;                  /**< Crystal Control Register                           */
  uint32_t       RESERVED11[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CFG_SET;                       /**< Configuration Register                             */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  uint32_t       RESERVED13[9U];                /**< Reserved for future use                            */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  uint32_t       RESERVED14[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED15[5U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED16[2U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  uint32_t       RESERVED17[991U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version ID                                      */
  uint32_t       RESERVED18[3U];                /**< Reserved for future use                            */
  __IOM uint32_t XTALCFG_CLR;                   /**< Crystal Configuration Register                     */
  uint32_t       RESERVED19[1U];                /**< Reserved for future use                            */
  __IOM uint32_t XTALCTRL_CLR;                  /**< Crystal Control Register                           */
  uint32_t       RESERVED20[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CFG_CLR;                       /**< Configuration Register                             */
  uint32_t       RESERVED21[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  uint32_t       RESERVED22[9U];                /**< Reserved for future use                            */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  uint32_t       RESERVED23[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED24[5U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED25[2U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  uint32_t       RESERVED26[991U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version ID                                      */
  uint32_t       RESERVED27[3U];                /**< Reserved for future use                            */
  __IOM uint32_t XTALCFG_TGL;                   /**< Crystal Configuration Register                     */
  uint32_t       RESERVED28[1U];                /**< Reserved for future use                            */
  __IOM uint32_t XTALCTRL_TGL;                  /**< Crystal Control Register                           */
  uint32_t       RESERVED29[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CFG_TGL;                       /**< Configuration Register                             */
  uint32_t       RESERVED30[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  uint32_t       RESERVED31[9U];                /**< Reserved for future use                            */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  uint32_t       RESERVED32[1U];                /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED33[5U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED34[2U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
} HFXO_TypeDef;
/** @} End of group EFM32PG22_HFXO */

/**************************************************************************//**
 * @defgroup EFM32PG22_I2C I2C
 * @{
 * @brief EFM32PG22 I2C Register Declaration.
 *****************************************************************************/

/** I2C Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP VERSION Register                                */
  __IOM uint32_t EN;                            /**< Enable Register                                    */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IM uint32_t  STATE;                         /**< State Register                                     */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t CLKDIV;                        /**< Clock Division Register                            */
  __IOM uint32_t SADDR;                         /**< Follower Address Register                          */
  __IOM uint32_t SADDRMASK;                     /**< Follower Address Mask Register                     */
  __IM uint32_t  RXDATA;                        /**< Receive Buffer Data Register                       */
  __IM uint32_t  RXDOUBLE;                      /**< Receive Buffer Double Data Register                */
  __IM uint32_t  RXDATAP;                       /**< Receive Buffer Data Peek Register                  */
  __IM uint32_t  RXDOUBLEP;                     /**< Receive Buffer Double Data Peek Register           */
  __IOM uint32_t TXDATA;                        /**< Transmit Buffer Data Register                      */
  __IOM uint32_t TXDOUBLE;                      /**< Transmit Buffer Double Data Register               */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED0[1007U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP VERSION Register                                */
  __IOM uint32_t EN_SET;                        /**< Enable Register                                    */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IM uint32_t  STATE_SET;                     /**< State Register                                     */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t CLKDIV_SET;                    /**< Clock Division Register                            */
  __IOM uint32_t SADDR_SET;                     /**< Follower Address Register                          */
  __IOM uint32_t SADDRMASK_SET;                 /**< Follower Address Mask Register                     */
  __IM uint32_t  RXDATA_SET;                    /**< Receive Buffer Data Register                       */
  __IM uint32_t  RXDOUBLE_SET;                  /**< Receive Buffer Double Data Register                */
  __IM uint32_t  RXDATAP_SET;                   /**< Receive Buffer Data Peek Register                  */
  __IM uint32_t  RXDOUBLEP_SET;                 /**< Receive Buffer Double Data Peek Register           */
  __IOM uint32_t TXDATA_SET;                    /**< Transmit Buffer Data Register                      */
  __IOM uint32_t TXDOUBLE_SET;                  /**< Transmit Buffer Double Data Register               */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED1[1007U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP VERSION Register                                */
  __IOM uint32_t EN_CLR;                        /**< Enable Register                                    */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IM uint32_t  STATE_CLR;                     /**< State Register                                     */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t CLKDIV_CLR;                    /**< Clock Division Register                            */
  __IOM uint32_t SADDR_CLR;                     /**< Follower Address Register                          */
  __IOM uint32_t SADDRMASK_CLR;                 /**< Follower Address Mask Register                     */
  __IM uint32_t  RXDATA_CLR;                    /**< Receive Buffer Data Register                       */
  __IM uint32_t  RXDOUBLE_CLR;                  /**< Receive Buffer Double Data Register                */
  __IM uint32_t  RXDATAP_CLR;                   /**< Receive Buffer Data Peek Register                  */
  __IM uint32_t  RXDOUBLEP_CLR;                 /**< Receive Buffer Double Data Peek Register           */
  __IOM uint32_t TXDATA_CLR;                    /**< Transmit Buffer Data Register                      */
  __IOM uint32_t TXDOUBLE_CLR;                  /**< Transmit Buffer Double Data Register               */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED2[1007U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP VERSION Register                                */
  __IOM uint32_t EN_TGL;                        /**< Enable Register                                    */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IM uint32_t  STATE_TGL;                     /**< State Register                                     */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t CLKDIV_TGL;                    /**< Clock Division Register                            */
  __IOM uint32_t SADDR_TGL;                     /**< Follower Address Register                          */
  __IOM uint32_t SADDRMASK_TGL;                 /**< Follower Address Mask Register                     */
  __IM uint32_t  RXDATA_TGL;                    /**< Receive Buffer Data Register                       */
  __IM uint32_t  RXDOUBLE_TGL;                  /**< Receive Buffer Double Data Register                */
  __IM uint32_t  RXDATAP_TGL;                   /**< Receive Buffer Data Peek Register                  */
  __IM uint32_t  RXDOUBLEP_TGL;                 /**< Receive Buffer Double Data Peek Register           */
  __IOM uint32_t TXDATA_TGL;                    /**< Transmit Buffer Data Register                      */
  __IOM uint32_t TXDOUBLE_TGL;                  /**< Transmit Buffer Double Data Register               */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
} I2C_TypeDef;
/** @} End of group EFM32PG22_I2C */

/**************************************************************************//**
 * @defgroup EFM32PG22_IADC IADC
 * @{
 * @brief EFM32PG22 IADC Register Declaration.
 *****************************************************************************/

/** IADC CFG Register Group Declaration. */
typedef struct {
  __IOM uint32_t CFG;                                /**< Configuration                                      */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
  __IOM uint32_t SCALE;                              /**< Scaling                                            */
  __IOM uint32_t SCHED;                              /**< Scheduling                                         */
} IADC_CFG_TypeDef;

/** IADC SCANTABLE Register Group Declaration. */
typedef struct {
  __IOM uint32_t SCAN;                               /**< SCAN Entry                                         */
} IADC_SCANTABLE_TypeDef;

/** IADC Register Declaration. */
typedef struct {
  __IM uint32_t          IPVERSION;             /**< IPVERSION                                          */
  __IOM uint32_t         EN;                    /**< Enable                                             */
  __IOM uint32_t         CTRL;                  /**< Control                                            */
  __IOM uint32_t         CMD;                   /**< Command                                            */
  __IOM uint32_t         TIMER;                 /**< Timer                                              */
  __IM uint32_t          STATUS;                /**< Status                                             */
  __IOM uint32_t         MASKREQ;               /**< Mask Request                                       */
  __IM uint32_t          STMASK;                /**< Scan Table Mask                                    */
  __IOM uint32_t         CMPTHR;                /**< Digital Window Comparator Threshold                */
  __IOM uint32_t         IF;                    /**< Interrupt Flags                                    */
  __IOM uint32_t         IEN;                   /**< Interrupt Enable                                   */
  __IOM uint32_t         TRIGGER;               /**< Trigger                                            */
  uint32_t               RESERVED0[1U];         /**< Reserved for future use                            */
  uint32_t               RESERVED1[5U];         /**< Reserved for future use                            */
  IADC_CFG_TypeDef       CFG[2U];               /**< CFG                                                */
  uint32_t               RESERVED2[2U];         /**< Reserved for future use                            */
  __IOM uint32_t         SINGLEFIFOCFG;         /**< Single FIFO Configuration                          */
  __IM uint32_t          SINGLEFIFODATA;        /**< Single FIFO Read Data                              */
  __IM uint32_t          SINGLEFIFOSTAT;        /**< Single FIFO Status                                 */
  __IM uint32_t          SINGLEDATA;            /**< Single Data                                        */
  __IOM uint32_t         SCANFIFOCFG;           /**< Scan FIFO Configuration                            */
  __IM uint32_t          SCANFIFODATA;          /**< Scan FIFO Read Data                                */
  __IM uint32_t          SCANFIFOSTAT;          /**< Scan FIFO Status                                   */
  __IM uint32_t          SCANDATA;              /**< Scan Data                                          */
  uint32_t               RESERVED3[1U];         /**< Reserved for future use                            */
  uint32_t               RESERVED4[1U];         /**< Reserved for future use                            */
  __IOM uint32_t         SINGLE;                /**< Single Queue Port Selection                        */
  uint32_t               RESERVED5[1U];         /**< Reserved for future use                            */
  IADC_SCANTABLE_TypeDef SCANTABLE[16U];        /**< SCANTABLE                                          */
  uint32_t               RESERVED6[4U];         /**< Reserved for future use                            */
  uint32_t               RESERVED7[1U];         /**< Reserved for future use                            */
  uint32_t               RESERVED8[963U];       /**< Reserved for future use                            */
  __IM uint32_t          IPVERSION_SET;         /**< IPVERSION                                          */
  __IOM uint32_t         EN_SET;                /**< Enable                                             */
  __IOM uint32_t         CTRL_SET;              /**< Control                                            */
  __IOM uint32_t         CMD_SET;               /**< Command                                            */
  __IOM uint32_t         TIMER_SET;             /**< Timer                                              */
  __IM uint32_t          STATUS_SET;            /**< Status                                             */
  __IOM uint32_t         MASKREQ_SET;           /**< Mask Request                                       */
  __IM uint32_t          STMASK_SET;            /**< Scan Table Mask                                    */
  __IOM uint32_t         CMPTHR_SET;            /**< Digital Window Comparator Threshold                */
  __IOM uint32_t         IF_SET;                /**< Interrupt Flags                                    */
  __IOM uint32_t         IEN_SET;               /**< Interrupt Enable                                   */
  __IOM uint32_t         TRIGGER_SET;           /**< Trigger                                            */
  uint32_t               RESERVED9[1U];         /**< Reserved for future use                            */
  uint32_t               RESERVED10[5U];        /**< Reserved for future use                            */
  IADC_CFG_TypeDef       CFG_SET[2U];           /**< CFG                                                */
  uint32_t               RESERVED11[2U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLEFIFOCFG_SET;     /**< Single FIFO Configuration                          */
  __IM uint32_t          SINGLEFIFODATA_SET;    /**< Single FIFO Read Data                              */
  __IM uint32_t          SINGLEFIFOSTAT_SET;    /**< Single FIFO Status                                 */
  __IM uint32_t          SINGLEDATA_SET;        /**< Single Data                                        */
  __IOM uint32_t         SCANFIFOCFG_SET;       /**< Scan FIFO Configuration                            */
  __IM uint32_t          SCANFIFODATA_SET;      /**< Scan FIFO Read Data                                */
  __IM uint32_t          SCANFIFOSTAT_SET;      /**< Scan FIFO Status                                   */
  __IM uint32_t          SCANDATA_SET;          /**< Scan Data                                          */
  uint32_t               RESERVED12[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED13[1U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLE_SET;            /**< Single Queue Port Selection                        */
  uint32_t               RESERVED14[1U];        /**< Reserved for future use                            */
  IADC_SCANTABLE_TypeDef SCANTABLE_SET[16U];    /**< SCANTABLE                                          */
  uint32_t               RESERVED15[4U];        /**< Reserved for future use                            */
  uint32_t               RESERVED16[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED17[963U];      /**< Reserved for future use                            */
  __IM uint32_t          IPVERSION_CLR;         /**< IPVERSION                                          */
  __IOM uint32_t         EN_CLR;                /**< Enable                                             */
  __IOM uint32_t         CTRL_CLR;              /**< Control                                            */
  __IOM uint32_t         CMD_CLR;               /**< Command                                            */
  __IOM uint32_t         TIMER_CLR;             /**< Timer                                              */
  __IM uint32_t          STATUS_CLR;            /**< Status                                             */
  __IOM uint32_t         MASKREQ_CLR;           /**< Mask Request                                       */
  __IM uint32_t          STMASK_CLR;            /**< Scan Table Mask                                    */
  __IOM uint32_t         CMPTHR_CLR;            /**< Digital Window Comparator Threshold                */
  __IOM uint32_t         IF_CLR;                /**< Interrupt Flags                                    */
  __IOM uint32_t         IEN_CLR;               /**< Interrupt Enable                                   */
  __IOM uint32_t         TRIGGER_CLR;           /**< Trigger                                            */
  uint32_t               RESERVED18[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED19[5U];        /**< Reserved for future use                            */
  IADC_CFG_TypeDef       CFG_CLR[2U];           /**< CFG                                                */
  uint32_t               RESERVED20[2U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLEFIFOCFG_CLR;     /**< Single FIFO Configuration                          */
  __IM uint32_t          SINGLEFIFODATA_CLR;    /**< Single FIFO Read Data                              */
  __IM uint32_t          SINGLEFIFOSTAT_CLR;    /**< Single FIFO Status                                 */
  __IM uint32_t          SINGLEDATA_CLR;        /**< Single Data                                        */
  __IOM uint32_t         SCANFIFOCFG_CLR;       /**< Scan FIFO Configuration                            */
  __IM uint32_t          SCANFIFODATA_CLR;      /**< Scan FIFO Read Data                                */
  __IM uint32_t          SCANFIFOSTAT_CLR;      /**< Scan FIFO Status                                   */
  __IM uint32_t          SCANDATA_CLR;          /**< Scan Data                                          */
  uint32_t               RESERVED21[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED22[1U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLE_CLR;            /**< Single Queue Port Selection                        */
  uint32_t               RESERVED23[1U];        /**< Reserved for future use                            */
  IADC_SCANTABLE_TypeDef SCANTABLE_CLR[16U];    /**< SCANTABLE                                          */
  uint32_t               RESERVED24[4U];        /**< Reserved for future use                            */
  uint32_t               RESERVED25[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED26[963U];      /**< Reserved for future use                            */
  __IM uint32_t          IPVERSION_TGL;         /**< IPVERSION                                          */
  __IOM uint32_t         EN_TGL;                /**< Enable                                             */
  __IOM uint32_t         CTRL_TGL;              /**< Control                                            */
  __IOM uint32_t         CMD_TGL;               /**< Command                                            */
  __IOM uint32_t         TIMER_TGL;             /**< Timer                                              */
  __IM uint32_t          STATUS_TGL;            /**< Status                                             */
  __IOM uint32_t         MASKREQ_TGL;           /**< Mask Request                                       */
  __IM uint32_t          STMASK_TGL;            /**< Scan Table Mask                                    */
  __IOM uint32_t         CMPTHR_TGL;            /**< Digital Window Comparator Threshold                */
  __IOM uint32_t         IF_TGL;                /**< Interrupt Flags                                    */
  __IOM uint32_t         IEN_TGL;               /**< Interrupt Enable                                   */
  __IOM uint32_t         TRIGGER_TGL;           /**< Trigger                                            */
  uint32_t               RESERVED27[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED28[5U];        /**< Reserved for future use                            */
  IADC_CFG_TypeDef       CFG_TGL[2U];           /**< CFG                                                */
  uint32_t               RESERVED29[2U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLEFIFOCFG_TGL;     /**< Single FIFO Configuration                          */
  __IM uint32_t          SINGLEFIFODATA_TGL;    /**< Single FIFO Read Data                              */
  __IM uint32_t          SINGLEFIFOSTAT_TGL;    /**< Single FIFO Status                                 */
  __IM uint32_t          SINGLEDATA_TGL;        /**< Single Data                                        */
  __IOM uint32_t         SCANFIFOCFG_TGL;       /**< Scan FIFO Configuration                            */
  __IM uint32_t          SCANFIFODATA_TGL;      /**< Scan FIFO Read Data                                */
  __IM uint32_t          SCANFIFOSTAT_TGL;      /**< Scan FIFO Status                                   */
  __IM uint32_t          SCANDATA_TGL;          /**< Scan Data                                          */
  uint32_t               RESERVED30[1U];        /**< Reserved for future use                            */
  uint32_t               RESERVED31[1U];        /**< Reserved for future use                            */
  __IOM uint32_t         SINGLE_TGL;            /**< Single Queue Port Selection                        */
  uint32_t               RESERVED32[1U];        /**< Reserved for future use                            */
  IADC_SCANTABLE_TypeDef SCANTABLE_TGL[16U];    /**< SCANTABLE                                          */
  uint32_t               RESERVED33[4U];        /**< Reserved for future use                            */
  uint32_t               RESERVED34[1U];        /**< Reserved for future use                            */
} IADC_TypeDef;
/** @} End of group EFM32PG22_IADC */

/**************************************************************************//**
 * @defgroup EFM32PG22_ICACHE ICACHE
 * @{
 * @brief EFM32PG22 ICACHE Register Declaration.
 *****************************************************************************/

/** ICACHE Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version                                         */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IM uint32_t  PCHITS;                        /**< Performance Counter Hits                           */
  __IM uint32_t  PCMISSES;                      /**< Performance Counter Misses                         */
  __IM uint32_t  PCAHITS;                       /**< Performance Counter Advanced Hits                  */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IOM uint32_t LPMODE;                        /**< Low Power Mode                                     */
  __IOM uint32_t IF;                            /**< Interrupt Flag                                     */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  uint32_t       RESERVED0[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version                                         */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IM uint32_t  PCHITS_SET;                    /**< Performance Counter Hits                           */
  __IM uint32_t  PCMISSES_SET;                  /**< Performance Counter Misses                         */
  __IM uint32_t  PCAHITS_SET;                   /**< Performance Counter Advanced Hits                  */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IOM uint32_t LPMODE_SET;                    /**< Low Power Mode                                     */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED1[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version                                         */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IM uint32_t  PCHITS_CLR;                    /**< Performance Counter Hits                           */
  __IM uint32_t  PCMISSES_CLR;                  /**< Performance Counter Misses                         */
  __IM uint32_t  PCAHITS_CLR;                   /**< Performance Counter Advanced Hits                  */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IOM uint32_t LPMODE_CLR;                    /**< Low Power Mode                                     */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED2[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version                                         */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IM uint32_t  PCHITS_TGL;                    /**< Performance Counter Hits                           */
  __IM uint32_t  PCMISSES_TGL;                  /**< Performance Counter Misses                         */
  __IM uint32_t  PCAHITS_TGL;                   /**< Performance Counter Advanced Hits                  */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IOM uint32_t LPMODE_TGL;                    /**< Low Power Mode                                     */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable                                   */
} ICACHE_TypeDef;
/** @} End of group EFM32PG22_ICACHE */

/**************************************************************************//**
 * @defgroup EFM32PG22_LDMA LDMA
 * @{
 * @brief EFM32PG22 LDMA Register Declaration.
 *****************************************************************************/

/** LDMA CH Register Group Declaration. */
typedef struct {
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
  __IOM uint32_t CFG;                                /**< Channel Configuration Register                     */
  __IOM uint32_t LOOP;                               /**< Channel Loop Counter Register                      */
  __IOM uint32_t CTRL;                               /**< Channel Descriptor Control Word Register           */
  __IOM uint32_t SRC;                                /**< Channel Descriptor Source Address                  */
  __IOM uint32_t DST;                                /**< Channel Descriptor Destination Address             */
  __IOM uint32_t LINK;                               /**< Channel Descriptor Link Address                    */
  uint32_t       RESERVED1[5U];                      /**< Reserved for future use                            */
} LDMA_CH_TypeDef;

/** LDMA Register Declaration. */
typedef struct {
  __IM uint32_t   IPVERSION;                    /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  EN;                           /**< DMA module enable disable Register                 */
  __IOM uint32_t  CTRL;                         /**< DMA Control Register                               */
  __IM uint32_t   STATUS;                       /**< DMA Status Register                                */
  __IOM uint32_t  SYNCSWSET;                    /**< DMA Sync Trig Sw Set Register                      */
  __IOM uint32_t  SYNCSWCLR;                    /**< DMA Sync Trig Sw Clear register                    */
  __IOM uint32_t  SYNCHWEN;                     /**< DMA Sync HW trigger enable register                */
  __IOM uint32_t  SYNCHWSEL;                    /**< DMA Sync HW trigger selection register             */
  __IM uint32_t   SYNCSTATUS;                   /**< DMA Sync Trigger Status Register                   */
  __IOM uint32_t  CHEN;                         /**< DMA Channel Enable Register                        */
  __IOM uint32_t  CHDIS;                        /**< DMA Channel Disable Register                       */
  __IM uint32_t   CHSTATUS;                     /**< DMA Channel Status Register                        */
  __IM uint32_t   CHBUSY;                       /**< DMA Channel Busy Register                          */
  __IOM uint32_t  CHDONE;                       /**< DMA Channel Linking Done Register                  */
  __IOM uint32_t  DBGHALT;                      /**< DMA Channel Debug Halt Register                    */
  __IOM uint32_t  SWREQ;                        /**< DMA Channel Software Transfer Request              */
  __IOM uint32_t  REQDIS;                       /**< DMA Channel Request Disable Register               */
  __IM uint32_t   REQPEND;                      /**< DMA Channel Requests Pending Register              */
  __IOM uint32_t  LINKLOAD;                     /**< DMA Channel Link Load Register                     */
  __IOM uint32_t  REQCLEAR;                     /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  IF;                           /**< Interrupt Flag Register                            */
  __IOM uint32_t  IEN;                          /**< Interrupt Enable Register                          */
  LDMA_CH_TypeDef CH[8U];                       /**< DMA Channel Registers                              */
  uint32_t        RESERVED0[906U];              /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_SET;                /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  EN_SET;                       /**< DMA module enable disable Register                 */
  __IOM uint32_t  CTRL_SET;                     /**< DMA Control Register                               */
  __IM uint32_t   STATUS_SET;                   /**< DMA Status Register                                */
  __IOM uint32_t  SYNCSWSET_SET;                /**< DMA Sync Trig Sw Set Register                      */
  __IOM uint32_t  SYNCSWCLR_SET;                /**< DMA Sync Trig Sw Clear register                    */
  __IOM uint32_t  SYNCHWEN_SET;                 /**< DMA Sync HW trigger enable register                */
  __IOM uint32_t  SYNCHWSEL_SET;                /**< DMA Sync HW trigger selection register             */
  __IM uint32_t   SYNCSTATUS_SET;               /**< DMA Sync Trigger Status Register                   */
  __IOM uint32_t  CHEN_SET;                     /**< DMA Channel Enable Register                        */
  __IOM uint32_t  CHDIS_SET;                    /**< DMA Channel Disable Register                       */
  __IM uint32_t   CHSTATUS_SET;                 /**< DMA Channel Status Register                        */
  __IM uint32_t   CHBUSY_SET;                   /**< DMA Channel Busy Register                          */
  __IOM uint32_t  CHDONE_SET;                   /**< DMA Channel Linking Done Register                  */
  __IOM uint32_t  DBGHALT_SET;                  /**< DMA Channel Debug Halt Register                    */
  __IOM uint32_t  SWREQ_SET;                    /**< DMA Channel Software Transfer Request              */
  __IOM uint32_t  REQDIS_SET;                   /**< DMA Channel Request Disable Register               */
  __IM uint32_t   REQPEND_SET;                  /**< DMA Channel Requests Pending Register              */
  __IOM uint32_t  LINKLOAD_SET;                 /**< DMA Channel Link Load Register                     */
  __IOM uint32_t  REQCLEAR_SET;                 /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  IF_SET;                       /**< Interrupt Flag Register                            */
  __IOM uint32_t  IEN_SET;                      /**< Interrupt Enable Register                          */
  LDMA_CH_TypeDef CH_SET[8U];                   /**< DMA Channel Registers                              */
  uint32_t        RESERVED1[906U];              /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_CLR;                /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  EN_CLR;                       /**< DMA module enable disable Register                 */
  __IOM uint32_t  CTRL_CLR;                     /**< DMA Control Register                               */
  __IM uint32_t   STATUS_CLR;                   /**< DMA Status Register                                */
  __IOM uint32_t  SYNCSWSET_CLR;                /**< DMA Sync Trig Sw Set Register                      */
  __IOM uint32_t  SYNCSWCLR_CLR;                /**< DMA Sync Trig Sw Clear register                    */
  __IOM uint32_t  SYNCHWEN_CLR;                 /**< DMA Sync HW trigger enable register                */
  __IOM uint32_t  SYNCHWSEL_CLR;                /**< DMA Sync HW trigger selection register             */
  __IM uint32_t   SYNCSTATUS_CLR;               /**< DMA Sync Trigger Status Register                   */
  __IOM uint32_t  CHEN_CLR;                     /**< DMA Channel Enable Register                        */
  __IOM uint32_t  CHDIS_CLR;                    /**< DMA Channel Disable Register                       */
  __IM uint32_t   CHSTATUS_CLR;                 /**< DMA Channel Status Register                        */
  __IM uint32_t   CHBUSY_CLR;                   /**< DMA Channel Busy Register                          */
  __IOM uint32_t  CHDONE_CLR;                   /**< DMA Channel Linking Done Register                  */
  __IOM uint32_t  DBGHALT_CLR;                  /**< DMA Channel Debug Halt Register                    */
  __IOM uint32_t  SWREQ_CLR;                    /**< DMA Channel Software Transfer Request              */
  __IOM uint32_t  REQDIS_CLR;                   /**< DMA Channel Request Disable Register               */
  __IM uint32_t   REQPEND_CLR;                  /**< DMA Channel Requests Pending Register              */
  __IOM uint32_t  LINKLOAD_CLR;                 /**< DMA Channel Link Load Register                     */
  __IOM uint32_t  REQCLEAR_CLR;                 /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  IF_CLR;                       /**< Interrupt Flag Register                            */
  __IOM uint32_t  IEN_CLR;                      /**< Interrupt Enable Register                          */
  LDMA_CH_TypeDef CH_CLR[8U];                   /**< DMA Channel Registers                              */
  uint32_t        RESERVED2[906U];              /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_TGL;                /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  EN_TGL;                       /**< DMA module enable disable Register                 */
  __IOM uint32_t  CTRL_TGL;                     /**< DMA Control Register                               */
  __IM uint32_t   STATUS_TGL;                   /**< DMA Status Register                                */
  __IOM uint32_t  SYNCSWSET_TGL;                /**< DMA Sync Trig Sw Set Register                      */
  __IOM uint32_t  SYNCSWCLR_TGL;                /**< DMA Sync Trig Sw Clear register                    */
  __IOM uint32_t  SYNCHWEN_TGL;                 /**< DMA Sync HW trigger enable register                */
  __IOM uint32_t  SYNCHWSEL_TGL;                /**< DMA Sync HW trigger selection register             */
  __IM uint32_t   SYNCSTATUS_TGL;               /**< DMA Sync Trigger Status Register                   */
  __IOM uint32_t  CHEN_TGL;                     /**< DMA Channel Enable Register                        */
  __IOM uint32_t  CHDIS_TGL;                    /**< DMA Channel Disable Register                       */
  __IM uint32_t   CHSTATUS_TGL;                 /**< DMA Channel Status Register                        */
  __IM uint32_t   CHBUSY_TGL;                   /**< DMA Channel Busy Register                          */
  __IOM uint32_t  CHDONE_TGL;                   /**< DMA Channel Linking Done Register                  */
  __IOM uint32_t  DBGHALT_TGL;                  /**< DMA Channel Debug Halt Register                    */
  __IOM uint32_t  SWREQ_TGL;                    /**< DMA Channel Software Transfer Request              */
  __IOM uint32_t  REQDIS_TGL;                   /**< DMA Channel Request Disable Register               */
  __IM uint32_t   REQPEND_TGL;                  /**< DMA Channel Requests Pending Register              */
  __IOM uint32_t  LINKLOAD_TGL;                 /**< DMA Channel Link Load Register                     */
  __IOM uint32_t  REQCLEAR_TGL;                 /**< DMA Channel Request Clear Register                 */
  __IOM uint32_t  IF_TGL;                       /**< Interrupt Flag Register                            */
  __IOM uint32_t  IEN_TGL;                      /**< Interrupt Enable Register                          */
  LDMA_CH_TypeDef CH_TGL[8U];                   /**< DMA Channel Registers                              */
} LDMA_TypeDef;
/** @} End of group EFM32PG22_LDMA */

/**************************************************************************//**
 * @defgroup EFM32PG22_LDMAXBAR LDMAXBAR
 * @{
 * @brief EFM32PG22 LDMAXBAR Register Declaration.
 *****************************************************************************/

/** LDMAXBAR CH Register Group Declaration. */
typedef struct {
  __IOM uint32_t REQSEL;                             /**< Channel Peripheral Request Select Reg...           */
} LDMAXBAR_CH_TypeDef;

/** LDMAXBAR Register Declaration. */
typedef struct {
  LDMAXBAR_CH_TypeDef CH[8U];                   /**< DMA Channel Registers                              */
  uint32_t            RESERVED0[1016U];         /**< Reserved for future use                            */
  LDMAXBAR_CH_TypeDef CH_SET[8U];               /**< DMA Channel Registers                              */
  uint32_t            RESERVED1[1016U];         /**< Reserved for future use                            */
  LDMAXBAR_CH_TypeDef CH_CLR[8U];               /**< DMA Channel Registers                              */
  uint32_t            RESERVED2[1016U];         /**< Reserved for future use                            */
  LDMAXBAR_CH_TypeDef CH_TGL[8U];               /**< DMA Channel Registers                              */
} LDMAXBAR_TypeDef;
/** @} End of group EFM32PG22_LDMAXBAR */

/**************************************************************************//**
 * @defgroup EFM32PG22_LETIMER LETIMER
 * @{
 * @brief EFM32PG22 LETIMER Register Declaration.
 *****************************************************************************/

/** LETIMER Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version                                         */
  __IOM uint32_t EN;                            /**< module en                                          */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CNT;                           /**< Counter Value Register                             */
  __IOM uint32_t COMP0;                         /**< Compare Value Register 0                           */
  __IOM uint32_t COMP1;                         /**< Compare Value Register 1                           */
  __IOM uint32_t TOP;                           /**< Counter TOP Value Register                         */
  __IOM uint32_t TOPBUFF;                       /**< Buffered Counter TOP Value                         */
  __IOM uint32_t REP0;                          /**< Repeat Counter Register 0                          */
  __IOM uint32_t REP1;                          /**< Repeat Counter Register 1                          */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED1[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY;                      /**< Synchronization Busy Register                      */
  uint32_t       RESERVED2[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t PRSMODE;                       /**< PRS Input mode select Register                     */
  uint32_t       RESERVED3[1003U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version                                         */
  __IOM uint32_t EN_SET;                        /**< module en                                          */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CNT_SET;                       /**< Counter Value Register                             */
  __IOM uint32_t COMP0_SET;                     /**< Compare Value Register 0                           */
  __IOM uint32_t COMP1_SET;                     /**< Compare Value Register 1                           */
  __IOM uint32_t TOP_SET;                       /**< Counter TOP Value Register                         */
  __IOM uint32_t TOPBUFF_SET;                   /**< Buffered Counter TOP Value                         */
  __IOM uint32_t REP0_SET;                      /**< Repeat Counter Register 0                          */
  __IOM uint32_t REP1_SET;                      /**< Repeat Counter Register 1                          */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_SET;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED6[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t PRSMODE_SET;                   /**< PRS Input mode select Register                     */
  uint32_t       RESERVED7[1003U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version                                         */
  __IOM uint32_t EN_CLR;                        /**< module en                                          */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED8[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t CNT_CLR;                       /**< Counter Value Register                             */
  __IOM uint32_t COMP0_CLR;                     /**< Compare Value Register 0                           */
  __IOM uint32_t COMP1_CLR;                     /**< Compare Value Register 1                           */
  __IOM uint32_t TOP_CLR;                       /**< Counter TOP Value Register                         */
  __IOM uint32_t TOPBUFF_CLR;                   /**< Buffered Counter TOP Value                         */
  __IOM uint32_t REP0_CLR;                      /**< Repeat Counter Register 0                          */
  __IOM uint32_t REP1_CLR;                      /**< Repeat Counter Register 1                          */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED9[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED10[3U];                /**< Reserved for future use                            */
  __IOM uint32_t PRSMODE_CLR;                   /**< PRS Input mode select Register                     */
  uint32_t       RESERVED11[1003U];             /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version                                         */
  __IOM uint32_t EN_TGL;                        /**< module en                                          */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  __IOM uint32_t CNT_TGL;                       /**< Counter Value Register                             */
  __IOM uint32_t COMP0_TGL;                     /**< Compare Value Register 0                           */
  __IOM uint32_t COMP1_TGL;                     /**< Compare Value Register 1                           */
  __IOM uint32_t TOP_TGL;                       /**< Counter TOP Value Register                         */
  __IOM uint32_t TOPBUFF_TGL;                   /**< Buffered Counter TOP Value                         */
  __IOM uint32_t REP0_TGL;                      /**< Repeat Counter Register 0                          */
  __IOM uint32_t REP1_TGL;                      /**< Repeat Counter Register 1                          */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED13[1U];                /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED14[3U];                /**< Reserved for future use                            */
  __IOM uint32_t PRSMODE_TGL;                   /**< PRS Input mode select Register                     */
} LETIMER_TypeDef;
/** @} End of group EFM32PG22_LETIMER */

/**************************************************************************//**
 * @defgroup EFM32PG22_LFRCO LFRCO
 * @{
 * @brief EFM32PG22 LFRCO Register Declaration.
 *****************************************************************************/

/** LFRCO Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version                                         */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED0[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED1[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  __IOM uint32_t CFG;                           /**< Configuration Register                             */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t NOMCAL;                        /**< Nominal Calibration Register                       */
  __IOM uint32_t NOMCALINV;                     /**< Nominal Calibration Inverted Register              */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  uint32_t       RESERVED3[1010U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version                                         */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  __IOM uint32_t CFG_SET;                       /**< Configuration Register                             */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t NOMCAL_SET;                    /**< Nominal Calibration Register                       */
  __IOM uint32_t NOMCALINV_SET;                 /**< Nominal Calibration Inverted Register              */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  uint32_t       RESERVED7[1010U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version                                         */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED8[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED9[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  __IOM uint32_t CFG_CLR;                       /**< Configuration Register                             */
  uint32_t       RESERVED10[1U];                /**< Reserved for future use                            */
  __IOM uint32_t NOMCAL_CLR;                    /**< Nominal Calibration Register                       */
  __IOM uint32_t NOMCALINV_CLR;                 /**< Nominal Calibration Inverted Register              */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  uint32_t       RESERVED11[1010U];             /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version                                         */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED12[2U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED13[1U];                /**< Reserved for future use                            */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
  __IOM uint32_t CFG_TGL;                       /**< Configuration Register                             */
  uint32_t       RESERVED14[1U];                /**< Reserved for future use                            */
  __IOM uint32_t NOMCAL_TGL;                    /**< Nominal Calibration Register                       */
  __IOM uint32_t NOMCALINV_TGL;                 /**< Nominal Calibration Inverted Register              */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
} LFRCO_TypeDef;
/** @} End of group EFM32PG22_LFRCO */

/**************************************************************************//**
 * @defgroup EFM32PG22_LFXO LFXO
 * @{
 * @brief EFM32PG22 LFXO Register Declaration.
 *****************************************************************************/

/** LFXO Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< LFXO IP version                                    */
  __IOM uint32_t CTRL;                          /**< LFXO Control Register                              */
  __IOM uint32_t CFG;                           /**< LFXO Configuration Register                        */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< LFXO Status Register                               */
  __IOM uint32_t CAL;                           /**< LFXO Calibration Register                          */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY;                      /**< LFXO Sync Busy Register                            */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  uint32_t       RESERVED1[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< LFXO IP version                                    */
  __IOM uint32_t CTRL_SET;                      /**< LFXO Control Register                              */
  __IOM uint32_t CFG_SET;                       /**< LFXO Configuration Register                        */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< LFXO Status Register                               */
  __IOM uint32_t CAL_SET;                       /**< LFXO Calibration Register                          */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_SET;                  /**< LFXO Sync Busy Register                            */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  uint32_t       RESERVED3[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< LFXO IP version                                    */
  __IOM uint32_t CTRL_CLR;                      /**< LFXO Control Register                              */
  __IOM uint32_t CFG_CLR;                       /**< LFXO Configuration Register                        */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< LFXO Status Register                               */
  __IOM uint32_t CAL_CLR;                       /**< LFXO Calibration Register                          */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< LFXO Sync Busy Register                            */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  uint32_t       RESERVED5[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< LFXO IP version                                    */
  __IOM uint32_t CTRL_TGL;                      /**< LFXO Control Register                              */
  __IOM uint32_t CFG_TGL;                       /**< LFXO Configuration Register                        */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< LFXO Status Register                               */
  __IOM uint32_t CAL_TGL;                       /**< LFXO Calibration Register                          */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< LFXO Sync Busy Register                            */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
} LFXO_TypeDef;
/** @} End of group EFM32PG22_LFXO */

/**************************************************************************//**
 * @defgroup EFM32PG22_MSC MSC
 * @{
 * @brief EFM32PG22 MSC Register Declaration.
 *****************************************************************************/

/** MSC Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version ID                                      */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t READCTRL;                      /**< Read Control Register                              */
  __IOM uint32_t WRITECTRL;                     /**< Write Control Register                             */
  __IOM uint32_t WRITECMD;                      /**< Write Command Register                             */
  __IOM uint32_t ADDRB;                         /**< Page Erase/Write Address Buffer                    */
  __IOM uint32_t WDATA;                         /**< Write Data Register                                */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED1[3U];                 /**< Reserved for future use                            */
  __IM uint32_t  USERDATASIZE;                  /**< User Data Region Size Register                     */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IOM uint32_t LOCK;                          /**< Configuration Lock Register                        */
  __IOM uint32_t MISCLOCKWORD;                  /**< Mass erase and User data page lock word            */
  uint32_t       RESERVED2[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t PWRCTRL;                       /**< Power control register                             */
  uint32_t       RESERVED3[51U];                /**< Reserved for future use                            */
  __IOM uint32_t PAGELOCK0;                     /**< Main space page 0-31 lock word                     */
  __IOM uint32_t PAGELOCK1;                     /**< Main space page 32-63 lock word                    */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED5[4U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED6[4U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED7[4U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED8[4U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED9[12U];                /**< Reserved for future use                            */
  uint32_t       RESERVED10[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED11[919U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version ID                                      */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  __IOM uint32_t READCTRL_SET;                  /**< Read Control Register                              */
  __IOM uint32_t WRITECTRL_SET;                 /**< Write Control Register                             */
  __IOM uint32_t WRITECMD_SET;                  /**< Write Command Register                             */
  __IOM uint32_t ADDRB_SET;                     /**< Page Erase/Write Address Buffer                    */
  __IOM uint32_t WDATA_SET;                     /**< Write Data Register                                */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED13[3U];                /**< Reserved for future use                            */
  __IM uint32_t  USERDATASIZE_SET;              /**< User Data Region Size Register                     */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IOM uint32_t LOCK_SET;                      /**< Configuration Lock Register                        */
  __IOM uint32_t MISCLOCKWORD_SET;              /**< Mass erase and User data page lock word            */
  uint32_t       RESERVED14[3U];                /**< Reserved for future use                            */
  __IOM uint32_t PWRCTRL_SET;                   /**< Power control register                             */
  uint32_t       RESERVED15[51U];               /**< Reserved for future use                            */
  __IOM uint32_t PAGELOCK0_SET;                 /**< Main space page 0-31 lock word                     */
  __IOM uint32_t PAGELOCK1_SET;                 /**< Main space page 32-63 lock word                    */
  uint32_t       RESERVED16[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED17[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED18[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED19[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED20[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED21[12U];               /**< Reserved for future use                            */
  uint32_t       RESERVED22[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED23[919U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version ID                                      */
  uint32_t       RESERVED24[1U];                /**< Reserved for future use                            */
  __IOM uint32_t READCTRL_CLR;                  /**< Read Control Register                              */
  __IOM uint32_t WRITECTRL_CLR;                 /**< Write Control Register                             */
  __IOM uint32_t WRITECMD_CLR;                  /**< Write Command Register                             */
  __IOM uint32_t ADDRB_CLR;                     /**< Page Erase/Write Address Buffer                    */
  __IOM uint32_t WDATA_CLR;                     /**< Write Data Register                                */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED25[3U];                /**< Reserved for future use                            */
  __IM uint32_t  USERDATASIZE_CLR;              /**< User Data Region Size Register                     */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IOM uint32_t LOCK_CLR;                      /**< Configuration Lock Register                        */
  __IOM uint32_t MISCLOCKWORD_CLR;              /**< Mass erase and User data page lock word            */
  uint32_t       RESERVED26[3U];                /**< Reserved for future use                            */
  __IOM uint32_t PWRCTRL_CLR;                   /**< Power control register                             */
  uint32_t       RESERVED27[51U];               /**< Reserved for future use                            */
  __IOM uint32_t PAGELOCK0_CLR;                 /**< Main space page 0-31 lock word                     */
  __IOM uint32_t PAGELOCK1_CLR;                 /**< Main space page 32-63 lock word                    */
  uint32_t       RESERVED28[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED29[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED30[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED31[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED32[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED33[12U];               /**< Reserved for future use                            */
  uint32_t       RESERVED34[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED35[919U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version ID                                      */
  uint32_t       RESERVED36[1U];                /**< Reserved for future use                            */
  __IOM uint32_t READCTRL_TGL;                  /**< Read Control Register                              */
  __IOM uint32_t WRITECTRL_TGL;                 /**< Write Control Register                             */
  __IOM uint32_t WRITECMD_TGL;                  /**< Write Command Register                             */
  __IOM uint32_t ADDRB_TGL;                     /**< Page Erase/Write Address Buffer                    */
  __IOM uint32_t WDATA_TGL;                     /**< Write Data Register                                */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED37[3U];                /**< Reserved for future use                            */
  __IM uint32_t  USERDATASIZE_TGL;              /**< User Data Region Size Register                     */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IOM uint32_t LOCK_TGL;                      /**< Configuration Lock Register                        */
  __IOM uint32_t MISCLOCKWORD_TGL;              /**< Mass erase and User data page lock word            */
  uint32_t       RESERVED38[3U];                /**< Reserved for future use                            */
  __IOM uint32_t PWRCTRL_TGL;                   /**< Power control register                             */
  uint32_t       RESERVED39[51U];               /**< Reserved for future use                            */
  __IOM uint32_t PAGELOCK0_TGL;                 /**< Main space page 0-31 lock word                     */
  __IOM uint32_t PAGELOCK1_TGL;                 /**< Main space page 32-63 lock word                    */
  uint32_t       RESERVED40[2U];                /**< Reserved for future use                            */
  uint32_t       RESERVED41[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED42[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED43[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED44[4U];                /**< Reserved for future use                            */
  uint32_t       RESERVED45[12U];               /**< Reserved for future use                            */
  uint32_t       RESERVED46[1U];                /**< Reserved for future use                            */
} MSC_TypeDef;
/** @} End of group EFM32PG22_MSC */

/**************************************************************************//**
 * @defgroup EFM32PG22_PDM PDM
 * @{
 * @brief EFM32PG22 PDM Register Declaration.
 *****************************************************************************/

/** PDM Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version ID                                      */
  __IOM uint32_t EN;                            /**< PDM Module enable Register                         */
  __IOM uint32_t CTRL;                          /**< PDM Core Control Register                          */
  __IOM uint32_t CMD;                           /**< PDM Core Command Register                          */
  __IM uint32_t  STATUS;                        /**< PDM Status register                                */
  __IOM uint32_t CFG0;                          /**< PDM Core Configuration Register0                   */
  __IOM uint32_t CFG1;                          /**< PDM Core Configuration Register1                   */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  RXDATA;                        /**< PDM Received Data Register                         */
  uint32_t       RESERVED1[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Flag Register                            */
  uint32_t       RESERVED2[6U];                 /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY;                      /**< Synchronization Busy Register                      */
  uint32_t       RESERVED3[999U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_SET;                        /**< PDM Module enable Register                         */
  __IOM uint32_t CTRL_SET;                      /**< PDM Core Control Register                          */
  __IOM uint32_t CMD_SET;                       /**< PDM Core Command Register                          */
  __IM uint32_t  STATUS_SET;                    /**< PDM Status register                                */
  __IOM uint32_t CFG0_SET;                      /**< PDM Core Configuration Register0                   */
  __IOM uint32_t CFG1_SET;                      /**< PDM Core Configuration Register1                   */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  RXDATA_SET;                    /**< PDM Received Data Register                         */
  uint32_t       RESERVED5[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Flag Register                            */
  uint32_t       RESERVED6[6U];                 /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_SET;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED7[999U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_CLR;                        /**< PDM Module enable Register                         */
  __IOM uint32_t CTRL_CLR;                      /**< PDM Core Control Register                          */
  __IOM uint32_t CMD_CLR;                       /**< PDM Core Command Register                          */
  __IM uint32_t  STATUS_CLR;                    /**< PDM Status register                                */
  __IOM uint32_t CFG0_CLR;                      /**< PDM Core Configuration Register0                   */
  __IOM uint32_t CFG1_CLR;                      /**< PDM Core Configuration Register1                   */
  uint32_t       RESERVED8[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  RXDATA_CLR;                    /**< PDM Received Data Register                         */
  uint32_t       RESERVED9[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Flag Register                            */
  uint32_t       RESERVED10[6U];                /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED11[999U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version ID                                      */
  __IOM uint32_t EN_TGL;                        /**< PDM Module enable Register                         */
  __IOM uint32_t CTRL_TGL;                      /**< PDM Core Control Register                          */
  __IOM uint32_t CMD_TGL;                       /**< PDM Core Command Register                          */
  __IM uint32_t  STATUS_TGL;                    /**< PDM Status register                                */
  __IOM uint32_t CFG0_TGL;                      /**< PDM Core Configuration Register0                   */
  __IOM uint32_t CFG1_TGL;                      /**< PDM Core Configuration Register1                   */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  __IM uint32_t  RXDATA_TGL;                    /**< PDM Received Data Register                         */
  uint32_t       RESERVED13[7U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Flag Register                            */
  uint32_t       RESERVED14[6U];                /**< Reserved for future use                            */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< Synchronization Busy Register                      */
} PDM_TypeDef;
/** @} End of group EFM32PG22_PDM */

/**************************************************************************//**
 * @defgroup EFM32PG22_PRS PRS
 * @{
 * @brief EFM32PG22 PRS Register Declaration.
 *****************************************************************************/

/** PRS ASYNC_CH Register Group Declaration. */
typedef struct {
  __IOM uint32_t CTRL;                               /**< Async Channel Control Register                     */
} PRS_ASYNC_CH_TypeDef;

/** PRS SYNC_CH Register Group Declaration. */
typedef struct {
  __IOM uint32_t CTRL;                               /**< Sync Channel Control Register                      */
} PRS_SYNC_CH_TypeDef;

/** PRS Register Declaration. */
typedef struct {
  __IM uint32_t        IPVERSION;                        /**< IP version ID                                      */
  uint32_t             RESERVED0[1U];                    /**< Reserved for future use                            */
  __IOM uint32_t       ASYNC_SWPULSE;                    /**< Software Pulse Register                            */
  __IOM uint32_t       ASYNC_SWLEVEL;                    /**< Software Level Register                            */
  __IM uint32_t        ASYNC_PEEK;                       /**< Async Channel Values                               */
  __IM uint32_t        SYNC_PEEK;                        /**< Sync Channel Values                                */
  PRS_ASYNC_CH_TypeDef ASYNC_CH[12U];                    /**< Async Channel registers                            */
  PRS_SYNC_CH_TypeDef  SYNC_CH[4U];                      /**< Sync Channel registers                             */
  __IOM uint32_t       CONSUMER_CMU_CALDN;               /**< CMU CALDN Consumer Selection                       */
  __IOM uint32_t       CONSUMER_CMU_CALUP;               /**< CMU CALUP Consumer Selection                       */
  uint32_t             RESERVED1[1U];                    /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_IADC0_SCANTRIGGER;       /**< IADC0 SCANTRIGGER Consumer Selection               */
  __IOM uint32_t       CONSUMER_IADC0_SINGLETRIGGER;     /**< IADC0 SINGLETRIGGER Consumer Selection             */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ0;        /**< DMAREQ0 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ1;        /**< DMAREQ1 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LETIMER0_CLEAR;          /**< LETIMER CLEAR Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_START;          /**< LETIMER START Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_STOP;           /**< LETIMER STOP Consumer Selection                    */
  __IOM uint32_t       CONSUMER_EUART0_RX;               /**< EUART0 RX consumer register                        */
  __IOM uint32_t       CONSUMER_EUART0_TRIGGER;          /**< EUART0 TRIGGER Consumer register                   */
  uint32_t             RESERVED2[1U];                    /**< Reserved for future use                            */
  uint32_t             RESERVED3[2U];                    /**< Reserved for future use                            */
  uint32_t             RESERVED4[11U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED5[10U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_RTCC_CC0;                /**< RTCC CC0 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC1;                /**< RTCC CC1 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC2;                /**< RTCC CC2 Consumer Selection                        */
  uint32_t             RESERVED6[1U];                    /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN0;             /**< CTI0 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN1;             /**< CTI1 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN2;             /**< CTI2 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN3;             /**< CTI3 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_M33RXEV;            /**< M33 Consumer Selection                             */
  __IOM uint32_t       CONSUMER_TIMER0_CC0;              /**< TIMER0 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC1;              /**< TIMER0 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC2;              /**< TIMER0 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTI;              /**< TIMER0 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS1;           /**< TIMER0 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS2;           /**< TIMER0 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_CC0;              /**< TIMER1 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC1;              /**< TIMER1 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC2;              /**< TIMER1 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTI;              /**< TIMER1 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS1;           /**< TIMER1 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS2;           /**< TIMER1 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_CC0;              /**< TIMER2 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC1;              /**< TIMER2 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC2;              /**< TIMER2 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTI;              /**< TIMER2 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS1;           /**< TIMER2 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS2;           /**< TIMER2 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_CC0;              /**< TIMER3 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC1;              /**< TIMER3 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC2;              /**< TIMER3 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTI;              /**< TIMER3 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS1;           /**< TIMER3 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS2;           /**< TIMER3 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_CC0;              /**< TIMER4 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC1;              /**< TIMER4 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC2;              /**< TIMER4 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTI;              /**< TIMER4 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS1;           /**< TIMER4 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS2;           /**< TIMER4 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_USART0_CLK;              /**< USART0 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART0_IR;               /**< USART0 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_RX;               /**< USART0 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_TRIGGER;          /**< USART0 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_USART1_CLK;              /**< USART1 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART1_IR;               /**< USART1 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_RX;               /**< USART1 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_TRIGGER;          /**< USART1 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_WDOG0_SRC0;              /**< WDOG0 SRC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_WDOG0_SRC1;              /**< WDOG0 SRC1 Consumer Selection                      */
  uint32_t             RESERVED7[917U];                  /**< Reserved for future use                            */
  __IM uint32_t        IPVERSION_SET;                    /**< IP version ID                                      */
  uint32_t             RESERVED8[1U];                    /**< Reserved for future use                            */
  __IOM uint32_t       ASYNC_SWPULSE_SET;                /**< Software Pulse Register                            */
  __IOM uint32_t       ASYNC_SWLEVEL_SET;                /**< Software Level Register                            */
  __IM uint32_t        ASYNC_PEEK_SET;                   /**< Async Channel Values                               */
  __IM uint32_t        SYNC_PEEK_SET;                    /**< Sync Channel Values                                */
  PRS_ASYNC_CH_TypeDef ASYNC_CH_SET[12U];                /**< Async Channel registers                            */
  PRS_SYNC_CH_TypeDef  SYNC_CH_SET[4U];                  /**< Sync Channel registers                             */
  __IOM uint32_t       CONSUMER_CMU_CALDN_SET;           /**< CMU CALDN Consumer Selection                       */
  __IOM uint32_t       CONSUMER_CMU_CALUP_SET;           /**< CMU CALUP Consumer Selection                       */
  uint32_t             RESERVED9[1U];                    /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_IADC0_SCANTRIGGER_SET;   /**< IADC0 SCANTRIGGER Consumer Selection               */
  __IOM uint32_t       CONSUMER_IADC0_SINGLETRIGGER_SET; /**< IADC0 SINGLETRIGGER Consumer Selection             */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ0_SET;    /**< DMAREQ0 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ1_SET;    /**< DMAREQ1 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LETIMER0_CLEAR_SET;      /**< LETIMER CLEAR Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_START_SET;      /**< LETIMER START Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_STOP_SET;       /**< LETIMER STOP Consumer Selection                    */
  __IOM uint32_t       CONSUMER_EUART0_RX_SET;           /**< EUART0 RX consumer register                        */
  __IOM uint32_t       CONSUMER_EUART0_TRIGGER_SET;      /**< EUART0 TRIGGER Consumer register                   */
  uint32_t             RESERVED10[1U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED11[2U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED12[11U];                  /**< Reserved for future use                            */
  uint32_t             RESERVED13[10U];                  /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_RTCC_CC0_SET;            /**< RTCC CC0 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC1_SET;            /**< RTCC CC1 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC2_SET;            /**< RTCC CC2 Consumer Selection                        */
  uint32_t             RESERVED14[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN0_SET;         /**< CTI0 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN1_SET;         /**< CTI1 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN2_SET;         /**< CTI2 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN3_SET;         /**< CTI3 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_M33RXEV_SET;        /**< M33 Consumer Selection                             */
  __IOM uint32_t       CONSUMER_TIMER0_CC0_SET;          /**< TIMER0 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC1_SET;          /**< TIMER0 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC2_SET;          /**< TIMER0 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTI_SET;          /**< TIMER0 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS1_SET;       /**< TIMER0 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS2_SET;       /**< TIMER0 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_CC0_SET;          /**< TIMER1 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC1_SET;          /**< TIMER1 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC2_SET;          /**< TIMER1 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTI_SET;          /**< TIMER1 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS1_SET;       /**< TIMER1 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS2_SET;       /**< TIMER1 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_CC0_SET;          /**< TIMER2 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC1_SET;          /**< TIMER2 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC2_SET;          /**< TIMER2 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTI_SET;          /**< TIMER2 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS1_SET;       /**< TIMER2 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS2_SET;       /**< TIMER2 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_CC0_SET;          /**< TIMER3 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC1_SET;          /**< TIMER3 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC2_SET;          /**< TIMER3 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTI_SET;          /**< TIMER3 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS1_SET;       /**< TIMER3 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS2_SET;       /**< TIMER3 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_CC0_SET;          /**< TIMER4 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC1_SET;          /**< TIMER4 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC2_SET;          /**< TIMER4 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTI_SET;          /**< TIMER4 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS1_SET;       /**< TIMER4 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS2_SET;       /**< TIMER4 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_USART0_CLK_SET;          /**< USART0 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART0_IR_SET;           /**< USART0 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_RX_SET;           /**< USART0 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_TRIGGER_SET;      /**< USART0 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_USART1_CLK_SET;          /**< USART1 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART1_IR_SET;           /**< USART1 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_RX_SET;           /**< USART1 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_TRIGGER_SET;      /**< USART1 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_WDOG0_SRC0_SET;          /**< WDOG0 SRC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_WDOG0_SRC1_SET;          /**< WDOG0 SRC1 Consumer Selection                      */
  uint32_t             RESERVED15[917U];                 /**< Reserved for future use                            */
  __IM uint32_t        IPVERSION_CLR;                    /**< IP version ID                                      */
  uint32_t             RESERVED16[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       ASYNC_SWPULSE_CLR;                /**< Software Pulse Register                            */
  __IOM uint32_t       ASYNC_SWLEVEL_CLR;                /**< Software Level Register                            */
  __IM uint32_t        ASYNC_PEEK_CLR;                   /**< Async Channel Values                               */
  __IM uint32_t        SYNC_PEEK_CLR;                    /**< Sync Channel Values                                */
  PRS_ASYNC_CH_TypeDef ASYNC_CH_CLR[12U];                /**< Async Channel registers                            */
  PRS_SYNC_CH_TypeDef  SYNC_CH_CLR[4U];                  /**< Sync Channel registers                             */
  __IOM uint32_t       CONSUMER_CMU_CALDN_CLR;           /**< CMU CALDN Consumer Selection                       */
  __IOM uint32_t       CONSUMER_CMU_CALUP_CLR;           /**< CMU CALUP Consumer Selection                       */
  uint32_t             RESERVED17[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_IADC0_SCANTRIGGER_CLR;   /**< IADC0 SCANTRIGGER Consumer Selection               */
  __IOM uint32_t       CONSUMER_IADC0_SINGLETRIGGER_CLR; /**< IADC0 SINGLETRIGGER Consumer Selection             */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ0_CLR;    /**< DMAREQ0 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ1_CLR;    /**< DMAREQ1 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LETIMER0_CLEAR_CLR;      /**< LETIMER CLEAR Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_START_CLR;      /**< LETIMER START Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_STOP_CLR;       /**< LETIMER STOP Consumer Selection                    */
  __IOM uint32_t       CONSUMER_EUART0_RX_CLR;           /**< EUART0 RX consumer register                        */
  __IOM uint32_t       CONSUMER_EUART0_TRIGGER_CLR;      /**< EUART0 TRIGGER Consumer register                   */
  uint32_t             RESERVED18[1U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED19[2U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED20[11U];                  /**< Reserved for future use                            */
  uint32_t             RESERVED21[10U];                  /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_RTCC_CC0_CLR;            /**< RTCC CC0 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC1_CLR;            /**< RTCC CC1 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC2_CLR;            /**< RTCC CC2 Consumer Selection                        */
  uint32_t             RESERVED22[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN0_CLR;         /**< CTI0 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN1_CLR;         /**< CTI1 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN2_CLR;         /**< CTI2 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN3_CLR;         /**< CTI3 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_M33RXEV_CLR;        /**< M33 Consumer Selection                             */
  __IOM uint32_t       CONSUMER_TIMER0_CC0_CLR;          /**< TIMER0 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC1_CLR;          /**< TIMER0 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC2_CLR;          /**< TIMER0 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTI_CLR;          /**< TIMER0 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS1_CLR;       /**< TIMER0 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS2_CLR;       /**< TIMER0 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_CC0_CLR;          /**< TIMER1 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC1_CLR;          /**< TIMER1 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC2_CLR;          /**< TIMER1 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTI_CLR;          /**< TIMER1 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS1_CLR;       /**< TIMER1 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS2_CLR;       /**< TIMER1 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_CC0_CLR;          /**< TIMER2 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC1_CLR;          /**< TIMER2 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC2_CLR;          /**< TIMER2 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTI_CLR;          /**< TIMER2 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS1_CLR;       /**< TIMER2 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS2_CLR;       /**< TIMER2 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_CC0_CLR;          /**< TIMER3 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC1_CLR;          /**< TIMER3 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC2_CLR;          /**< TIMER3 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTI_CLR;          /**< TIMER3 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS1_CLR;       /**< TIMER3 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS2_CLR;       /**< TIMER3 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_CC0_CLR;          /**< TIMER4 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC1_CLR;          /**< TIMER4 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC2_CLR;          /**< TIMER4 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTI_CLR;          /**< TIMER4 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS1_CLR;       /**< TIMER4 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS2_CLR;       /**< TIMER4 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_USART0_CLK_CLR;          /**< USART0 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART0_IR_CLR;           /**< USART0 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_RX_CLR;           /**< USART0 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_TRIGGER_CLR;      /**< USART0 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_USART1_CLK_CLR;          /**< USART1 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART1_IR_CLR;           /**< USART1 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_RX_CLR;           /**< USART1 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_TRIGGER_CLR;      /**< USART1 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_WDOG0_SRC0_CLR;          /**< WDOG0 SRC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_WDOG0_SRC1_CLR;          /**< WDOG0 SRC1 Consumer Selection                      */
  uint32_t             RESERVED23[917U];                 /**< Reserved for future use                            */
  __IM uint32_t        IPVERSION_TGL;                    /**< IP version ID                                      */
  uint32_t             RESERVED24[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       ASYNC_SWPULSE_TGL;                /**< Software Pulse Register                            */
  __IOM uint32_t       ASYNC_SWLEVEL_TGL;                /**< Software Level Register                            */
  __IM uint32_t        ASYNC_PEEK_TGL;                   /**< Async Channel Values                               */
  __IM uint32_t        SYNC_PEEK_TGL;                    /**< Sync Channel Values                                */
  PRS_ASYNC_CH_TypeDef ASYNC_CH_TGL[12U];                /**< Async Channel registers                            */
  PRS_SYNC_CH_TypeDef  SYNC_CH_TGL[4U];                  /**< Sync Channel registers                             */
  __IOM uint32_t       CONSUMER_CMU_CALDN_TGL;           /**< CMU CALDN Consumer Selection                       */
  __IOM uint32_t       CONSUMER_CMU_CALUP_TGL;           /**< CMU CALUP Consumer Selection                       */
  uint32_t             RESERVED25[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_IADC0_SCANTRIGGER_TGL;   /**< IADC0 SCANTRIGGER Consumer Selection               */
  __IOM uint32_t       CONSUMER_IADC0_SINGLETRIGGER_TGL; /**< IADC0 SINGLETRIGGER Consumer Selection             */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ0_TGL;    /**< DMAREQ0 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LDMAXBAR_DMAREQ1_TGL;    /**< DMAREQ1 Consumer Selection                         */
  __IOM uint32_t       CONSUMER_LETIMER0_CLEAR_TGL;      /**< LETIMER CLEAR Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_START_TGL;      /**< LETIMER START Consumer Selection                   */
  __IOM uint32_t       CONSUMER_LETIMER0_STOP_TGL;       /**< LETIMER STOP Consumer Selection                    */
  __IOM uint32_t       CONSUMER_EUART0_RX_TGL;           /**< EUART0 RX consumer register                        */
  __IOM uint32_t       CONSUMER_EUART0_TRIGGER_TGL;      /**< EUART0 TRIGGER Consumer register                   */
  uint32_t             RESERVED26[1U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED27[2U];                   /**< Reserved for future use                            */
  uint32_t             RESERVED28[11U];                  /**< Reserved for future use                            */
  uint32_t             RESERVED29[10U];                  /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_RTCC_CC0_TGL;            /**< RTCC CC0 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC1_TGL;            /**< RTCC CC1 Consumer Selection                        */
  __IOM uint32_t       CONSUMER_RTCC_CC2_TGL;            /**< RTCC CC2 Consumer Selection                        */
  uint32_t             RESERVED30[1U];                   /**< Reserved for future use                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN0_TGL;         /**< CTI0 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN1_TGL;         /**< CTI1 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN2_TGL;         /**< CTI2 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_CTIIN3_TGL;         /**< CTI3 Consumer Selection                            */
  __IOM uint32_t       CONSUMER_CORE_M33RXEV_TGL;        /**< M33 Consumer Selection                             */
  __IOM uint32_t       CONSUMER_TIMER0_CC0_TGL;          /**< TIMER0 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC1_TGL;          /**< TIMER0 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_CC2_TGL;          /**< TIMER0 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTI_TGL;          /**< TIMER0 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS1_TGL;       /**< TIMER0 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER0_DTIFS2_TGL;       /**< TIMER0 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_CC0_TGL;          /**< TIMER1 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC1_TGL;          /**< TIMER1 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_CC2_TGL;          /**< TIMER1 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTI_TGL;          /**< TIMER1 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS1_TGL;       /**< TIMER1 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER1_DTIFS2_TGL;       /**< TIMER1 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_CC0_TGL;          /**< TIMER2 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC1_TGL;          /**< TIMER2 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_CC2_TGL;          /**< TIMER2 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTI_TGL;          /**< TIMER2 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS1_TGL;       /**< TIMER2 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER2_DTIFS2_TGL;       /**< TIMER2 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_CC0_TGL;          /**< TIMER3 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC1_TGL;          /**< TIMER3 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_CC2_TGL;          /**< TIMER3 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTI_TGL;          /**< TIMER3 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS1_TGL;       /**< TIMER3 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER3_DTIFS2_TGL;       /**< TIMER3 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_CC0_TGL;          /**< TIMER4 CC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC1_TGL;          /**< TIMER4 CC1 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_CC2_TGL;          /**< TIMER4 CC2 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTI_TGL;          /**< TIMER4 DTI Consumer Selection                      */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS1_TGL;       /**< TIMER4 DTIFS1 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_TIMER4_DTIFS2_TGL;       /**< TIMER4 DTIFS2 Consumer Selection                   */
  __IOM uint32_t       CONSUMER_USART0_CLK_TGL;          /**< USART0 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART0_IR_TGL;           /**< USART0 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_RX_TGL;           /**< USART0 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART0_TRIGGER_TGL;      /**< USART0 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_USART1_CLK_TGL;          /**< USART1 CLK Consumer Selection                      */
  __IOM uint32_t       CONSUMER_USART1_IR_TGL;           /**< USART1 IR Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_RX_TGL;           /**< USART1 RX Consumer Selection                       */
  __IOM uint32_t       CONSUMER_USART1_TRIGGER_TGL;      /**< USART1 TRIGGER Consumer Selection                  */
  __IOM uint32_t       CONSUMER_WDOG0_SRC0_TGL;          /**< WDOG0 SRC0 Consumer Selection                      */
  __IOM uint32_t       CONSUMER_WDOG0_SRC1_TGL;          /**< WDOG0 SRC1 Consumer Selection                      */
} PRS_TypeDef;
/** @} End of group EFM32PG22_PRS */

/**************************************************************************//**
 * @defgroup EFM32PG22_RTCC RTCC
 * @{
 * @brief EFM32PG22 RTCC Register Declaration.
 *****************************************************************************/

/** RTCC CC Register Group Declaration. */
typedef struct {
  __IOM uint32_t CTRL;                               /**< CC Channel Control Register                        */
  __IOM uint32_t OCVALUE;                            /**< Output Compare Value Register                      */
  __IM uint32_t  ICVALUE;                            /**< Input Capture Value Register                       */
} RTCC_CC_TypeDef;

/** RTCC Register Declaration. */
typedef struct {
  __IM uint32_t   IPVERSION;                    /**< IP VERSION                                         */
  __IOM uint32_t  EN;                           /**< Module Enable Register                             */
  __IOM uint32_t  CFG;                          /**< Configuration Register                             */
  __IOM uint32_t  CMD;                          /**< Command Register                                   */
  __IM uint32_t   STATUS;                       /**< Status register                                    */
  __IOM uint32_t  IF;                           /**< RTCC Interrupt Flags                               */
  __IOM uint32_t  IEN;                          /**< Interrupt Enable Register                          */
  __IOM uint32_t  PRECNT;                       /**< Pre-Counter Value Register                         */
  __IOM uint32_t  CNT;                          /**< Counter Value Register                             */
  __IM uint32_t   COMBCNT;                      /**< Combined Pre-Counter and Counter Valu...           */
  __IM uint32_t   SYNCBUSY;                     /**< Synchronization Busy Register                      */
  __IOM uint32_t  LOCK;                         /**< Configuration Lock Register                        */
  RTCC_CC_TypeDef CC[3U];                       /**< Capture/Compare Channel                            */
  uint32_t        RESERVED0[1003U];             /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_SET;                /**< IP VERSION                                         */
  __IOM uint32_t  EN_SET;                       /**< Module Enable Register                             */
  __IOM uint32_t  CFG_SET;                      /**< Configuration Register                             */
  __IOM uint32_t  CMD_SET;                      /**< Command Register                                   */
  __IM uint32_t   STATUS_SET;                   /**< Status register                                    */
  __IOM uint32_t  IF_SET;                       /**< RTCC Interrupt Flags                               */
  __IOM uint32_t  IEN_SET;                      /**< Interrupt Enable Register                          */
  __IOM uint32_t  PRECNT_SET;                   /**< Pre-Counter Value Register                         */
  __IOM uint32_t  CNT_SET;                      /**< Counter Value Register                             */
  __IM uint32_t   COMBCNT_SET;                  /**< Combined Pre-Counter and Counter Valu...           */
  __IM uint32_t   SYNCBUSY_SET;                 /**< Synchronization Busy Register                      */
  __IOM uint32_t  LOCK_SET;                     /**< Configuration Lock Register                        */
  RTCC_CC_TypeDef CC_SET[3U];                   /**< Capture/Compare Channel                            */
  uint32_t        RESERVED1[1003U];             /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_CLR;                /**< IP VERSION                                         */
  __IOM uint32_t  EN_CLR;                       /**< Module Enable Register                             */
  __IOM uint32_t  CFG_CLR;                      /**< Configuration Register                             */
  __IOM uint32_t  CMD_CLR;                      /**< Command Register                                   */
  __IM uint32_t   STATUS_CLR;                   /**< Status register                                    */
  __IOM uint32_t  IF_CLR;                       /**< RTCC Interrupt Flags                               */
  __IOM uint32_t  IEN_CLR;                      /**< Interrupt Enable Register                          */
  __IOM uint32_t  PRECNT_CLR;                   /**< Pre-Counter Value Register                         */
  __IOM uint32_t  CNT_CLR;                      /**< Counter Value Register                             */
  __IM uint32_t   COMBCNT_CLR;                  /**< Combined Pre-Counter and Counter Valu...           */
  __IM uint32_t   SYNCBUSY_CLR;                 /**< Synchronization Busy Register                      */
  __IOM uint32_t  LOCK_CLR;                     /**< Configuration Lock Register                        */
  RTCC_CC_TypeDef CC_CLR[3U];                   /**< Capture/Compare Channel                            */
  uint32_t        RESERVED2[1003U];             /**< Reserved for future use                            */
  __IM uint32_t   IPVERSION_TGL;                /**< IP VERSION                                         */
  __IOM uint32_t  EN_TGL;                       /**< Module Enable Register                             */
  __IOM uint32_t  CFG_TGL;                      /**< Configuration Register                             */
  __IOM uint32_t  CMD_TGL;                      /**< Command Register                                   */
  __IM uint32_t   STATUS_TGL;                   /**< Status register                                    */
  __IOM uint32_t  IF_TGL;                       /**< RTCC Interrupt Flags                               */
  __IOM uint32_t  IEN_TGL;                      /**< Interrupt Enable Register                          */
  __IOM uint32_t  PRECNT_TGL;                   /**< Pre-Counter Value Register                         */
  __IOM uint32_t  CNT_TGL;                      /**< Counter Value Register                             */
  __IM uint32_t   COMBCNT_TGL;                  /**< Combined Pre-Counter and Counter Valu...           */
  __IM uint32_t   SYNCBUSY_TGL;                 /**< Synchronization Busy Register                      */
  __IOM uint32_t  LOCK_TGL;                     /**< Configuration Lock Register                        */
  RTCC_CC_TypeDef CC_TGL[3U];                   /**< Capture/Compare Channel                            */
} RTCC_TypeDef;
/** @} End of group EFM32PG22_RTCC */

/**************************************************************************//**
 * @defgroup EFM32PG22_SMU SMU
 * @{
 * @brief EFM32PG22 SMU Register Declaration.
 *****************************************************************************/

/** SMU Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version                                         */
  __IM uint32_t  STATUS;                        /**< Status                                             */
  __IOM uint32_t LOCK;                          /**< Lock                                               */
  __IOM uint32_t IF;                            /**< Interrupt Flag                                     */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  uint32_t       RESERVED0[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t M33CTRL;                       /**< M33 Control                                        */
  uint32_t       RESERVED1[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t PPUPATD0;                      /**< PPU PATD Register 0                                */
  __IOM uint32_t PPUPATD1;                      /**< PPU PATD Register 1                                */
  uint32_t       RESERVED2[6U];                 /**< Reserved for future use                            */
  __IOM uint32_t PPUSATD0;                      /**< PPU SATD Register 0                                */
  __IOM uint32_t PPUSATD1;                      /**< PPU SATD Register 1                                */
  uint32_t       RESERVED3[54U];                /**< Reserved for future use                            */
  __IM uint32_t  PPUFS;                         /**< PPU Fault Status                                   */
  uint32_t       RESERVED4[3U];                 /**< Reserved for future use                            */
  __IOM uint32_t BMPUPATD0;                     /**< BMPU PATD Register 0                               */
  uint32_t       RESERVED5[7U];                 /**< Reserved for future use                            */
  __IOM uint32_t BMPUSATD0;                     /**< BMPU SATD Register 0                               */
  uint32_t       RESERVED6[55U];                /**< Reserved for future use                            */
  __IM uint32_t  BMPUFS;                        /**< BMPU Fault Status                                  */
  __IM uint32_t  BMPUFSADDR;                    /**< BMPU Fault Status Address                          */
  uint32_t       RESERVED7[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t ESAURTYPES0;                   /**< ESAU Region Types Register 0                       */
  __IOM uint32_t ESAURTYPES1;                   /**< ESAU Region Types Register 1                       */
  uint32_t       RESERVED8[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB01;                     /**< ESAU Movable Region Boundary 0-1                   */
  __IOM uint32_t ESAUMRB12;                     /**< ESAU Movable Region Boundary 1-2                   */
  uint32_t       RESERVED9[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB45;                     /**< ESAU Movable Region Boundary 4-5                   */
  __IOM uint32_t ESAUMRB56;                     /**< ESAU Movable Region Boundary 5-6                   */
  uint32_t       RESERVED10[862U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version                                         */
  __IM uint32_t  STATUS_SET;                    /**< Status                                             */
  __IOM uint32_t LOCK_SET;                      /**< Lock                                               */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED11[3U];                /**< Reserved for future use                            */
  __IOM uint32_t M33CTRL_SET;                   /**< M33 Control                                        */
  uint32_t       RESERVED12[7U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUPATD0_SET;                  /**< PPU PATD Register 0                                */
  __IOM uint32_t PPUPATD1_SET;                  /**< PPU PATD Register 1                                */
  uint32_t       RESERVED13[6U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUSATD0_SET;                  /**< PPU SATD Register 0                                */
  __IOM uint32_t PPUSATD1_SET;                  /**< PPU SATD Register 1                                */
  uint32_t       RESERVED14[54U];               /**< Reserved for future use                            */
  __IM uint32_t  PPUFS_SET;                     /**< PPU Fault Status                                   */
  uint32_t       RESERVED15[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUPATD0_SET;                 /**< BMPU PATD Register 0                               */
  uint32_t       RESERVED16[7U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUSATD0_SET;                 /**< BMPU SATD Register 0                               */
  uint32_t       RESERVED17[55U];               /**< Reserved for future use                            */
  __IM uint32_t  BMPUFS_SET;                    /**< BMPU Fault Status                                  */
  __IM uint32_t  BMPUFSADDR_SET;                /**< BMPU Fault Status Address                          */
  uint32_t       RESERVED18[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAURTYPES0_SET;               /**< ESAU Region Types Register 0                       */
  __IOM uint32_t ESAURTYPES1_SET;               /**< ESAU Region Types Register 1                       */
  uint32_t       RESERVED19[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB01_SET;                 /**< ESAU Movable Region Boundary 0-1                   */
  __IOM uint32_t ESAUMRB12_SET;                 /**< ESAU Movable Region Boundary 1-2                   */
  uint32_t       RESERVED20[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB45_SET;                 /**< ESAU Movable Region Boundary 4-5                   */
  __IOM uint32_t ESAUMRB56_SET;                 /**< ESAU Movable Region Boundary 5-6                   */
  uint32_t       RESERVED21[862U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version                                         */
  __IM uint32_t  STATUS_CLR;                    /**< Status                                             */
  __IOM uint32_t LOCK_CLR;                      /**< Lock                                               */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED22[3U];                /**< Reserved for future use                            */
  __IOM uint32_t M33CTRL_CLR;                   /**< M33 Control                                        */
  uint32_t       RESERVED23[7U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUPATD0_CLR;                  /**< PPU PATD Register 0                                */
  __IOM uint32_t PPUPATD1_CLR;                  /**< PPU PATD Register 1                                */
  uint32_t       RESERVED24[6U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUSATD0_CLR;                  /**< PPU SATD Register 0                                */
  __IOM uint32_t PPUSATD1_CLR;                  /**< PPU SATD Register 1                                */
  uint32_t       RESERVED25[54U];               /**< Reserved for future use                            */
  __IM uint32_t  PPUFS_CLR;                     /**< PPU Fault Status                                   */
  uint32_t       RESERVED26[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUPATD0_CLR;                 /**< BMPU PATD Register 0                               */
  uint32_t       RESERVED27[7U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUSATD0_CLR;                 /**< BMPU SATD Register 0                               */
  uint32_t       RESERVED28[55U];               /**< Reserved for future use                            */
  __IM uint32_t  BMPUFS_CLR;                    /**< BMPU Fault Status                                  */
  __IM uint32_t  BMPUFSADDR_CLR;                /**< BMPU Fault Status Address                          */
  uint32_t       RESERVED29[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAURTYPES0_CLR;               /**< ESAU Region Types Register 0                       */
  __IOM uint32_t ESAURTYPES1_CLR;               /**< ESAU Region Types Register 1                       */
  uint32_t       RESERVED30[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB01_CLR;                 /**< ESAU Movable Region Boundary 0-1                   */
  __IOM uint32_t ESAUMRB12_CLR;                 /**< ESAU Movable Region Boundary 1-2                   */
  uint32_t       RESERVED31[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB45_CLR;                 /**< ESAU Movable Region Boundary 4-5                   */
  __IOM uint32_t ESAUMRB56_CLR;                 /**< ESAU Movable Region Boundary 5-6                   */
  uint32_t       RESERVED32[862U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version                                         */
  __IM uint32_t  STATUS_TGL;                    /**< Status                                             */
  __IOM uint32_t LOCK_TGL;                      /**< Lock                                               */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED33[3U];                /**< Reserved for future use                            */
  __IOM uint32_t M33CTRL_TGL;                   /**< M33 Control                                        */
  uint32_t       RESERVED34[7U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUPATD0_TGL;                  /**< PPU PATD Register 0                                */
  __IOM uint32_t PPUPATD1_TGL;                  /**< PPU PATD Register 1                                */
  uint32_t       RESERVED35[6U];                /**< Reserved for future use                            */
  __IOM uint32_t PPUSATD0_TGL;                  /**< PPU SATD Register 0                                */
  __IOM uint32_t PPUSATD1_TGL;                  /**< PPU SATD Register 1                                */
  uint32_t       RESERVED36[54U];               /**< Reserved for future use                            */
  __IM uint32_t  PPUFS_TGL;                     /**< PPU Fault Status                                   */
  uint32_t       RESERVED37[3U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUPATD0_TGL;                 /**< BMPU PATD Register 0                               */
  uint32_t       RESERVED38[7U];                /**< Reserved for future use                            */
  __IOM uint32_t BMPUSATD0_TGL;                 /**< BMPU SATD Register 0                               */
  uint32_t       RESERVED39[55U];               /**< Reserved for future use                            */
  __IM uint32_t  BMPUFS_TGL;                    /**< BMPU Fault Status                                  */
  __IM uint32_t  BMPUFSADDR_TGL;                /**< BMPU Fault Status Address                          */
  uint32_t       RESERVED40[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAURTYPES0_TGL;               /**< ESAU Region Types Register 0                       */
  __IOM uint32_t ESAURTYPES1_TGL;               /**< ESAU Region Types Register 1                       */
  uint32_t       RESERVED41[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB01_TGL;                 /**< ESAU Movable Region Boundary 0-1                   */
  __IOM uint32_t ESAUMRB12_TGL;                 /**< ESAU Movable Region Boundary 1-2                   */
  uint32_t       RESERVED42[2U];                /**< Reserved for future use                            */
  __IOM uint32_t ESAUMRB45_TGL;                 /**< ESAU Movable Region Boundary 4-5                   */
  __IOM uint32_t ESAUMRB56_TGL;                 /**< ESAU Movable Region Boundary 5-6                   */
} SMU_TypeDef;
/** @} End of group EFM32PG22_SMU */

/**************************************************************************//**
 * @defgroup EFM32PG22_SYSCFG SYSCFG
 * @{
 * @brief EFM32PG22 SYSCFG Register Declaration.
 *****************************************************************************/

/** SYSCFG Register Declaration. */
typedef struct {
  __IOM uint32_t IF;                            /**< Interrupt Flag                                     */
  __IOM uint32_t IEN;                           /**< Interrupt Enable                                   */
  uint32_t       RESERVED0[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t CHIPREVHW;                     /**< Chip Revision, Hard-wired                          */
  __IOM uint32_t CHIPREV;                       /**< Part Family and Revision Values                    */
  uint32_t       RESERVED1[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t CFGSYSTIC;                     /**< SysTick clock source                               */
  uint32_t       RESERVED2[55U];                /**< Reserved for future use                            */
  uint32_t       RESERVED3[1U];                 /**< Reserved for future use                            */
  uint32_t       RESERVED4[63U];                /**< Reserved for future use                            */
  __IOM uint32_t CTRL;                          /**< Memory System Control                              */
  uint32_t       RESERVED5[1U];                 /**< Reserved for future use                            */
  __IOM uint32_t DMEM0RETNCTRL;                 /**< DMEM0 Retention Control                            */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  DMEM0ECCADDR;                  /**< DMEM0 ECC Address                                  */
  __IOM uint32_t DMEM0ECCCTRL;                  /**< DMEM0 ECC Control                                  */
  uint32_t       RESERVED7[250U];               /**< Reserved for future use                            */
  __IOM uint32_t ROOTDATA0;                     /**< Root Data Register 0                               */
  __IOM uint32_t ROOTDATA1;                     /**< Root Data Register 1                               */
  __IM uint32_t  ROOTLOCKSTATUS;                /**< Lock Status                                        */
  uint32_t       RESERVED8[637U];               /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED9[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t CHIPREVHW_SET;                 /**< Chip Revision, Hard-wired                          */
  __IOM uint32_t CHIPREV_SET;                   /**< Part Family and Revision Values                    */
  uint32_t       RESERVED10[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CFGSYSTIC_SET;                 /**< SysTick clock source                               */
  uint32_t       RESERVED11[55U];               /**< Reserved for future use                            */
  uint32_t       RESERVED12[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED13[63U];               /**< Reserved for future use                            */
  __IOM uint32_t CTRL_SET;                      /**< Memory System Control                              */
  uint32_t       RESERVED14[1U];                /**< Reserved for future use                            */
  __IOM uint32_t DMEM0RETNCTRL_SET;             /**< DMEM0 Retention Control                            */
  uint32_t       RESERVED15[1U];                /**< Reserved for future use                            */
  __IM uint32_t  DMEM0ECCADDR_SET;              /**< DMEM0 ECC Address                                  */
  __IOM uint32_t DMEM0ECCCTRL_SET;              /**< DMEM0 ECC Control                                  */
  uint32_t       RESERVED16[250U];              /**< Reserved for future use                            */
  __IOM uint32_t ROOTDATA0_SET;                 /**< Root Data Register 0                               */
  __IOM uint32_t ROOTDATA1_SET;                 /**< Root Data Register 1                               */
  __IM uint32_t  ROOTLOCKSTATUS_SET;            /**< Lock Status                                        */
  uint32_t       RESERVED17[637U];              /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED18[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CHIPREVHW_CLR;                 /**< Chip Revision, Hard-wired                          */
  __IOM uint32_t CHIPREV_CLR;                   /**< Part Family and Revision Values                    */
  uint32_t       RESERVED19[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CFGSYSTIC_CLR;                 /**< SysTick clock source                               */
  uint32_t       RESERVED20[55U];               /**< Reserved for future use                            */
  uint32_t       RESERVED21[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED22[63U];               /**< Reserved for future use                            */
  __IOM uint32_t CTRL_CLR;                      /**< Memory System Control                              */
  uint32_t       RESERVED23[1U];                /**< Reserved for future use                            */
  __IOM uint32_t DMEM0RETNCTRL_CLR;             /**< DMEM0 Retention Control                            */
  uint32_t       RESERVED24[1U];                /**< Reserved for future use                            */
  __IM uint32_t  DMEM0ECCADDR_CLR;              /**< DMEM0 ECC Address                                  */
  __IOM uint32_t DMEM0ECCCTRL_CLR;              /**< DMEM0 ECC Control                                  */
  uint32_t       RESERVED25[250U];              /**< Reserved for future use                            */
  __IOM uint32_t ROOTDATA0_CLR;                 /**< Root Data Register 0                               */
  __IOM uint32_t ROOTDATA1_CLR;                 /**< Root Data Register 1                               */
  __IM uint32_t  ROOTLOCKSTATUS_CLR;            /**< Lock Status                                        */
  uint32_t       RESERVED26[637U];              /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag                                     */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable                                   */
  uint32_t       RESERVED27[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CHIPREVHW_TGL;                 /**< Chip Revision, Hard-wired                          */
  __IOM uint32_t CHIPREV_TGL;                   /**< Part Family and Revision Values                    */
  uint32_t       RESERVED28[2U];                /**< Reserved for future use                            */
  __IOM uint32_t CFGSYSTIC_TGL;                 /**< SysTick clock source                               */
  uint32_t       RESERVED29[55U];               /**< Reserved for future use                            */
  uint32_t       RESERVED30[1U];                /**< Reserved for future use                            */
  uint32_t       RESERVED31[63U];               /**< Reserved for future use                            */
  __IOM uint32_t CTRL_TGL;                      /**< Memory System Control                              */
  uint32_t       RESERVED32[1U];                /**< Reserved for future use                            */
  __IOM uint32_t DMEM0RETNCTRL_TGL;             /**< DMEM0 Retention Control                            */
  uint32_t       RESERVED33[1U];                /**< Reserved for future use                            */
  __IM uint32_t  DMEM0ECCADDR_TGL;              /**< DMEM0 ECC Address                                  */
  __IOM uint32_t DMEM0ECCCTRL_TGL;              /**< DMEM0 ECC Control                                  */
  uint32_t       RESERVED34[250U];              /**< Reserved for future use                            */
  __IOM uint32_t ROOTDATA0_TGL;                 /**< Root Data Register 0                               */
  __IOM uint32_t ROOTDATA1_TGL;                 /**< Root Data Register 1                               */
  __IM uint32_t  ROOTLOCKSTATUS_TGL;            /**< Lock Status                                        */
} SYSCFG_TypeDef;
/** @} End of group EFM32PG22_SYSCFG */

/**************************************************************************//**
 * @defgroup EFM32PG22_TIMER TIMER
 * @{
 * @brief EFM32PG22 TIMER Register Declaration.
 *****************************************************************************/

/** TIMER CC Register Group Declaration. */
typedef struct {
  __IOM uint32_t CFG;                                /**< CC Channel Configuration Register                  */
  __IOM uint32_t CTRL;                               /**< CC Channel Control Register                        */
  __IOM uint32_t OC;                                 /**< OC Channel Value Register                          */
  uint32_t       RESERVED0[1U];                      /**< Reserved for future use                            */
  __IOM uint32_t OCB;                                /**< OC Channel Value Buffer Register                   */
  __IM uint32_t  ICF;                                /**< IC Channel Value Register                          */
  __IM uint32_t  ICOF;                               /**< IC Channel Value Overflow Register                 */
  uint32_t       RESERVED1[1U];                      /**< Reserved for future use                            */
} TIMER_CC_TypeDef;

/** TIMER Register Declaration. */
typedef struct {
  __IM uint32_t    IPVERSION;                   /**< IP version ID                                      */
  __IOM uint32_t   CFG;                         /**< Configuration Register                             */
  __IOM uint32_t   CTRL;                        /**< Control Register                                   */
  __IOM uint32_t   CMD;                         /**< Command Register                                   */
  __IM uint32_t    STATUS;                      /**< Status Register                                    */
  __IOM uint32_t   IF;                          /**< Interrupt Flag Register                            */
  __IOM uint32_t   IEN;                         /**< Interrupt Enable Register                          */
  __IOM uint32_t   TOP;                         /**< Counter Top Value Register                         */
  __IOM uint32_t   TOPB;                        /**< Counter Top Value Buffer Register                  */
  __IOM uint32_t   CNT;                         /**< Counter Value Register                             */
  uint32_t         RESERVED0[1U];               /**< Reserved for future use                            */
  __IOM uint32_t   LOCK;                        /**< TIMER Configuration Lock Register                  */
  __IOM uint32_t   EN;                          /**< module en                                          */
  uint32_t         RESERVED1[11U];              /**< Reserved for future use                            */
  TIMER_CC_TypeDef CC[3U];                      /**< Compare/Capture Channel                            */
  uint32_t         RESERVED2[8U];               /**< Reserved for future use                            */
  __IOM uint32_t   DTCFG;                       /**< DTI Configuration Register                         */
  __IOM uint32_t   DTTIMECFG;                   /**< DTI Time Configuration Register                    */
  __IOM uint32_t   DTFCFG;                      /**< DTI Fault Configuration Register                   */
  __IOM uint32_t   DTCTRL;                      /**< DTI Control Register                               */
  __IOM uint32_t   DTOGEN;                      /**< DTI Output Generation Enable Register              */
  __IM uint32_t    DTFAULT;                     /**< DTI Fault Register                                 */
  __IOM uint32_t   DTFAULTC;                    /**< DTI Fault Clear Register                           */
  __IOM uint32_t   DTLOCK;                      /**< DTI Configuration Lock Register                    */
  uint32_t         RESERVED3[960U];             /**< Reserved for future use                            */
  __IM uint32_t    IPVERSION_SET;               /**< IP version ID                                      */
  __IOM uint32_t   CFG_SET;                     /**< Configuration Register                             */
  __IOM uint32_t   CTRL_SET;                    /**< Control Register                                   */
  __IOM uint32_t   CMD_SET;                     /**< Command Register                                   */
  __IM uint32_t    STATUS_SET;                  /**< Status Register                                    */
  __IOM uint32_t   IF_SET;                      /**< Interrupt Flag Register                            */
  __IOM uint32_t   IEN_SET;                     /**< Interrupt Enable Register                          */
  __IOM uint32_t   TOP_SET;                     /**< Counter Top Value Register                         */
  __IOM uint32_t   TOPB_SET;                    /**< Counter Top Value Buffer Register                  */
  __IOM uint32_t   CNT_SET;                     /**< Counter Value Register                             */
  uint32_t         RESERVED4[1U];               /**< Reserved for future use                            */
  __IOM uint32_t   LOCK_SET;                    /**< TIMER Configuration Lock Register                  */
  __IOM uint32_t   EN_SET;                      /**< module en                                          */
  uint32_t         RESERVED5[11U];              /**< Reserved for future use                            */
  TIMER_CC_TypeDef CC_SET[3U];                  /**< Compare/Capture Channel                            */
  uint32_t         RESERVED6[8U];               /**< Reserved for future use                            */
  __IOM uint32_t   DTCFG_SET;                   /**< DTI Configuration Register                         */
  __IOM uint32_t   DTTIMECFG_SET;               /**< DTI Time Configuration Register                    */
  __IOM uint32_t   DTFCFG_SET;                  /**< DTI Fault Configuration Register                   */
  __IOM uint32_t   DTCTRL_SET;                  /**< DTI Control Register                               */
  __IOM uint32_t   DTOGEN_SET;                  /**< DTI Output Generation Enable Register              */
  __IM uint32_t    DTFAULT_SET;                 /**< DTI Fault Register                                 */
  __IOM uint32_t   DTFAULTC_SET;                /**< DTI Fault Clear Register                           */
  __IOM uint32_t   DTLOCK_SET;                  /**< DTI Configuration Lock Register                    */
  uint32_t         RESERVED7[960U];             /**< Reserved for future use                            */
  __IM uint32_t    IPVERSION_CLR;               /**< IP version ID                                      */
  __IOM uint32_t   CFG_CLR;                     /**< Configuration Register                             */
  __IOM uint32_t   CTRL_CLR;                    /**< Control Register                                   */
  __IOM uint32_t   CMD_CLR;                     /**< Command Register                                   */
  __IM uint32_t    STATUS_CLR;                  /**< Status Register                                    */
  __IOM uint32_t   IF_CLR;                      /**< Interrupt Flag Register                            */
  __IOM uint32_t   IEN_CLR;                     /**< Interrupt Enable Register                          */
  __IOM uint32_t   TOP_CLR;                     /**< Counter Top Value Register                         */
  __IOM uint32_t   TOPB_CLR;                    /**< Counter Top Value Buffer Register                  */
  __IOM uint32_t   CNT_CLR;                     /**< Counter Value Register                             */
  uint32_t         RESERVED8[1U];               /**< Reserved for future use                            */
  __IOM uint32_t   LOCK_CLR;                    /**< TIMER Configuration Lock Register                  */
  __IOM uint32_t   EN_CLR;                      /**< module en                                          */
  uint32_t         RESERVED9[11U];              /**< Reserved for future use                            */
  TIMER_CC_TypeDef CC_CLR[3U];                  /**< Compare/Capture Channel                            */
  uint32_t         RESERVED10[8U];              /**< Reserved for future use                            */
  __IOM uint32_t   DTCFG_CLR;                   /**< DTI Configuration Register                         */
  __IOM uint32_t   DTTIMECFG_CLR;               /**< DTI Time Configuration Register                    */
  __IOM uint32_t   DTFCFG_CLR;                  /**< DTI Fault Configuration Register                   */
  __IOM uint32_t   DTCTRL_CLR;                  /**< DTI Control Register                               */
  __IOM uint32_t   DTOGEN_CLR;                  /**< DTI Output Generation Enable Register              */
  __IM uint32_t    DTFAULT_CLR;                 /**< DTI Fault Register                                 */
  __IOM uint32_t   DTFAULTC_CLR;                /**< DTI Fault Clear Register                           */
  __IOM uint32_t   DTLOCK_CLR;                  /**< DTI Configuration Lock Register                    */
  uint32_t         RESERVED11[960U];            /**< Reserved for future use                            */
  __IM uint32_t    IPVERSION_TGL;               /**< IP version ID                                      */
  __IOM uint32_t   CFG_TGL;                     /**< Configuration Register                             */
  __IOM uint32_t   CTRL_TGL;                    /**< Control Register                                   */
  __IOM uint32_t   CMD_TGL;                     /**< Command Register                                   */
  __IM uint32_t    STATUS_TGL;                  /**< Status Register                                    */
  __IOM uint32_t   IF_TGL;                      /**< Interrupt Flag Register                            */
  __IOM uint32_t   IEN_TGL;                     /**< Interrupt Enable Register                          */
  __IOM uint32_t   TOP_TGL;                     /**< Counter Top Value Register                         */
  __IOM uint32_t   TOPB_TGL;                    /**< Counter Top Value Buffer Register                  */
  __IOM uint32_t   CNT_TGL;                     /**< Counter Value Register                             */
  uint32_t         RESERVED12[1U];              /**< Reserved for future use                            */
  __IOM uint32_t   LOCK_TGL;                    /**< TIMER Configuration Lock Register                  */
  __IOM uint32_t   EN_TGL;                      /**< module en                                          */
  uint32_t         RESERVED13[11U];             /**< Reserved for future use                            */
  TIMER_CC_TypeDef CC_TGL[3U];                  /**< Compare/Capture Channel                            */
  uint32_t         RESERVED14[8U];              /**< Reserved for future use                            */
  __IOM uint32_t   DTCFG_TGL;                   /**< DTI Configuration Register                         */
  __IOM uint32_t   DTTIMECFG_TGL;               /**< DTI Time Configuration Register                    */
  __IOM uint32_t   DTFCFG_TGL;                  /**< DTI Fault Configuration Register                   */
  __IOM uint32_t   DTCTRL_TGL;                  /**< DTI Control Register                               */
  __IOM uint32_t   DTOGEN_TGL;                  /**< DTI Output Generation Enable Register              */
  __IM uint32_t    DTFAULT_TGL;                 /**< DTI Fault Register                                 */
  __IOM uint32_t   DTFAULTC_TGL;                /**< DTI Fault Clear Register                           */
  __IOM uint32_t   DTLOCK_TGL;                  /**< DTI Configuration Lock Register                    */
} TIMER_TypeDef;
/** @} End of group EFM32PG22_TIMER */

/**************************************************************************//**
 * @defgroup EFM32PG22_ULFRCO ULFRCO
 * @{
 * @brief EFM32PG22 ULFRCO Register Declaration.
 *****************************************************************************/

/** ULFRCO Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP version                                         */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  uint32_t       RESERVED1[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  uint32_t       RESERVED2[1017U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP version                                         */
  uint32_t       RESERVED3[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  uint32_t       RESERVED4[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED5[1017U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP version                                         */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  uint32_t       RESERVED7[2U];                 /**< Reserved for future use                            */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  uint32_t       RESERVED8[1017U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP version                                         */
  uint32_t       RESERVED9[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  uint32_t       RESERVED10[2U];                /**< Reserved for future use                            */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
} ULFRCO_TypeDef;
/** @} End of group EFM32PG22_ULFRCO */

/**************************************************************************//**
 * @defgroup EFM32PG22_USART USART
 * @{
 * @brief EFM32PG22 USART Register Declaration.
 *****************************************************************************/

/** USART Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IPVERSION                                          */
  __IOM uint32_t EN;                            /**< USART Enable                                       */
  __IOM uint32_t CTRL;                          /**< Control Register                                   */
  __IOM uint32_t FRAME;                         /**< USART Frame Format Register                        */
  __IOM uint32_t TRIGCTRL;                      /**< USART Trigger Control register                     */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  __IM uint32_t  STATUS;                        /**< USART Status Register                              */
  __IOM uint32_t CLKDIV;                        /**< Clock Control Register                             */
  __IM uint32_t  RXDATAX;                       /**< RX Buffer Data Extended Register                   */
  __IM uint32_t  RXDATA;                        /**< RX Buffer Data Register                            */
  __IM uint32_t  RXDOUBLEX;                     /**< RX Buffer Double Data Extended Register            */
  __IM uint32_t  RXDOUBLE;                      /**< RX FIFO Double Data Register                       */
  __IM uint32_t  RXDATAXP;                      /**< RX Buffer Data Extended Peek Register              */
  __IM uint32_t  RXDOUBLEXP;                    /**< RX Buffer Double Data Extended Peek R...           */
  __IOM uint32_t TXDATAX;                       /**< TX Buffer Data Extended Register                   */
  __IOM uint32_t TXDATA;                        /**< TX Buffer Data Register                            */
  __IOM uint32_t TXDOUBLEX;                     /**< TX Buffer Double Data Extended Register            */
  __IOM uint32_t TXDOUBLE;                      /**< TX Buffer Double Data Register                     */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  __IOM uint32_t IRCTRL;                        /**< IrDA Control Register                              */
  __IOM uint32_t I2SCTRL;                       /**< I2S Control Register                               */
  __IOM uint32_t TIMING;                        /**< Timing Register                                    */
  __IOM uint32_t CTRLX;                         /**< Control Register Extended                          */
  __IOM uint32_t TIMECMP0;                      /**< Timer Compare 0                                    */
  __IOM uint32_t TIMECMP1;                      /**< Timer Compare 1                                    */
  __IOM uint32_t TIMECMP2;                      /**< Timer Compare 2                                    */
  uint32_t       RESERVED0[997U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_SET;                        /**< USART Enable                                       */
  __IOM uint32_t CTRL_SET;                      /**< Control Register                                   */
  __IOM uint32_t FRAME_SET;                     /**< USART Frame Format Register                        */
  __IOM uint32_t TRIGCTRL_SET;                  /**< USART Trigger Control register                     */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_SET;                    /**< USART Status Register                              */
  __IOM uint32_t CLKDIV_SET;                    /**< Clock Control Register                             */
  __IM uint32_t  RXDATAX_SET;                   /**< RX Buffer Data Extended Register                   */
  __IM uint32_t  RXDATA_SET;                    /**< RX Buffer Data Register                            */
  __IM uint32_t  RXDOUBLEX_SET;                 /**< RX Buffer Double Data Extended Register            */
  __IM uint32_t  RXDOUBLE_SET;                  /**< RX FIFO Double Data Register                       */
  __IM uint32_t  RXDATAXP_SET;                  /**< RX Buffer Data Extended Peek Register              */
  __IM uint32_t  RXDOUBLEXP_SET;                /**< RX Buffer Double Data Extended Peek R...           */
  __IOM uint32_t TXDATAX_SET;                   /**< TX Buffer Data Extended Register                   */
  __IOM uint32_t TXDATA_SET;                    /**< TX Buffer Data Register                            */
  __IOM uint32_t TXDOUBLEX_SET;                 /**< TX Buffer Double Data Extended Register            */
  __IOM uint32_t TXDOUBLE_SET;                  /**< TX Buffer Double Data Register                     */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t IRCTRL_SET;                    /**< IrDA Control Register                              */
  __IOM uint32_t I2SCTRL_SET;                   /**< I2S Control Register                               */
  __IOM uint32_t TIMING_SET;                    /**< Timing Register                                    */
  __IOM uint32_t CTRLX_SET;                     /**< Control Register Extended                          */
  __IOM uint32_t TIMECMP0_SET;                  /**< Timer Compare 0                                    */
  __IOM uint32_t TIMECMP1_SET;                  /**< Timer Compare 1                                    */
  __IOM uint32_t TIMECMP2_SET;                  /**< Timer Compare 2                                    */
  uint32_t       RESERVED1[997U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_CLR;                        /**< USART Enable                                       */
  __IOM uint32_t CTRL_CLR;                      /**< Control Register                                   */
  __IOM uint32_t FRAME_CLR;                     /**< USART Frame Format Register                        */
  __IOM uint32_t TRIGCTRL_CLR;                  /**< USART Trigger Control register                     */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_CLR;                    /**< USART Status Register                              */
  __IOM uint32_t CLKDIV_CLR;                    /**< Clock Control Register                             */
  __IM uint32_t  RXDATAX_CLR;                   /**< RX Buffer Data Extended Register                   */
  __IM uint32_t  RXDATA_CLR;                    /**< RX Buffer Data Register                            */
  __IM uint32_t  RXDOUBLEX_CLR;                 /**< RX Buffer Double Data Extended Register            */
  __IM uint32_t  RXDOUBLE_CLR;                  /**< RX FIFO Double Data Register                       */
  __IM uint32_t  RXDATAXP_CLR;                  /**< RX Buffer Data Extended Peek Register              */
  __IM uint32_t  RXDOUBLEXP_CLR;                /**< RX Buffer Double Data Extended Peek R...           */
  __IOM uint32_t TXDATAX_CLR;                   /**< TX Buffer Data Extended Register                   */
  __IOM uint32_t TXDATA_CLR;                    /**< TX Buffer Data Register                            */
  __IOM uint32_t TXDOUBLEX_CLR;                 /**< TX Buffer Double Data Extended Register            */
  __IOM uint32_t TXDOUBLE_CLR;                  /**< TX Buffer Double Data Register                     */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t IRCTRL_CLR;                    /**< IrDA Control Register                              */
  __IOM uint32_t I2SCTRL_CLR;                   /**< I2S Control Register                               */
  __IOM uint32_t TIMING_CLR;                    /**< Timing Register                                    */
  __IOM uint32_t CTRLX_CLR;                     /**< Control Register Extended                          */
  __IOM uint32_t TIMECMP0_CLR;                  /**< Timer Compare 0                                    */
  __IOM uint32_t TIMECMP1_CLR;                  /**< Timer Compare 1                                    */
  __IOM uint32_t TIMECMP2_CLR;                  /**< Timer Compare 2                                    */
  uint32_t       RESERVED2[997U];               /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IPVERSION                                          */
  __IOM uint32_t EN_TGL;                        /**< USART Enable                                       */
  __IOM uint32_t CTRL_TGL;                      /**< Control Register                                   */
  __IOM uint32_t FRAME_TGL;                     /**< USART Frame Format Register                        */
  __IOM uint32_t TRIGCTRL_TGL;                  /**< USART Trigger Control register                     */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  __IM uint32_t  STATUS_TGL;                    /**< USART Status Register                              */
  __IOM uint32_t CLKDIV_TGL;                    /**< Clock Control Register                             */
  __IM uint32_t  RXDATAX_TGL;                   /**< RX Buffer Data Extended Register                   */
  __IM uint32_t  RXDATA_TGL;                    /**< RX Buffer Data Register                            */
  __IM uint32_t  RXDOUBLEX_TGL;                 /**< RX Buffer Double Data Extended Register            */
  __IM uint32_t  RXDOUBLE_TGL;                  /**< RX FIFO Double Data Register                       */
  __IM uint32_t  RXDATAXP_TGL;                  /**< RX Buffer Data Extended Peek Register              */
  __IM uint32_t  RXDOUBLEXP_TGL;                /**< RX Buffer Double Data Extended Peek R...           */
  __IOM uint32_t TXDATAX_TGL;                   /**< TX Buffer Data Extended Register                   */
  __IOM uint32_t TXDATA_TGL;                    /**< TX Buffer Data Register                            */
  __IOM uint32_t TXDOUBLEX_TGL;                 /**< TX Buffer Double Data Extended Register            */
  __IOM uint32_t TXDOUBLE_TGL;                  /**< TX Buffer Double Data Register                     */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t IRCTRL_TGL;                    /**< IrDA Control Register                              */
  __IOM uint32_t I2SCTRL_TGL;                   /**< I2S Control Register                               */
  __IOM uint32_t TIMING_TGL;                    /**< Timing Register                                    */
  __IOM uint32_t CTRLX_TGL;                     /**< Control Register Extended                          */
  __IOM uint32_t TIMECMP0_TGL;                  /**< Timer Compare 0                                    */
  __IOM uint32_t TIMECMP1_TGL;                  /**< Timer Compare 1                                    */
  __IOM uint32_t TIMECMP2_TGL;                  /**< Timer Compare 2                                    */
} USART_TypeDef;
/** @} End of group EFM32PG22_USART */

/**************************************************************************//**
 * @defgroup EFM32PG22_WDOG WDOG
 * @{
 * @brief EFM32PG22 WDOG Register Declaration.
 *****************************************************************************/

/** WDOG Register Declaration. */
typedef struct {
  __IM uint32_t  IPVERSION;                     /**< IP Version Register                                */
  __IOM uint32_t EN;                            /**< Enable Register                                    */
  __IOM uint32_t CFG;                           /**< Configuration Register                             */
  __IOM uint32_t CMD;                           /**< Command Register                                   */
  uint32_t       RESERVED0[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS;                        /**< Status Register                                    */
  __IOM uint32_t IF;                            /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN;                           /**< Interrupt Enable Register                          */
  __IOM uint32_t LOCK;                          /**< Lock Register                                      */
  __IM uint32_t  SYNCBUSY;                      /**< Synchronization Busy Register                      */
  uint32_t       RESERVED1[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_SET;                 /**< IP Version Register                                */
  __IOM uint32_t EN_SET;                        /**< Enable Register                                    */
  __IOM uint32_t CFG_SET;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_SET;                       /**< Command Register                                   */
  uint32_t       RESERVED2[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_SET;                    /**< Status Register                                    */
  __IOM uint32_t IF_SET;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_SET;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t LOCK_SET;                      /**< Lock Register                                      */
  __IM uint32_t  SYNCBUSY_SET;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED3[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_CLR;                 /**< IP Version Register                                */
  __IOM uint32_t EN_CLR;                        /**< Enable Register                                    */
  __IOM uint32_t CFG_CLR;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_CLR;                       /**< Command Register                                   */
  uint32_t       RESERVED4[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_CLR;                    /**< Status Register                                    */
  __IOM uint32_t IF_CLR;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_CLR;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t LOCK_CLR;                      /**< Lock Register                                      */
  __IM uint32_t  SYNCBUSY_CLR;                  /**< Synchronization Busy Register                      */
  uint32_t       RESERVED5[1014U];              /**< Reserved for future use                            */
  __IM uint32_t  IPVERSION_TGL;                 /**< IP Version Register                                */
  __IOM uint32_t EN_TGL;                        /**< Enable Register                                    */
  __IOM uint32_t CFG_TGL;                       /**< Configuration Register                             */
  __IOM uint32_t CMD_TGL;                       /**< Command Register                                   */
  uint32_t       RESERVED6[1U];                 /**< Reserved for future use                            */
  __IM uint32_t  STATUS_TGL;                    /**< Status Register                                    */
  __IOM uint32_t IF_TGL;                        /**< Interrupt Flag Register                            */
  __IOM uint32_t IEN_TGL;                       /**< Interrupt Enable Register                          */
  __IOM uint32_t LOCK_TGL;                      /**< Lock Register                                      */
  __IM uint32_t  SYNCBUSY_TGL;                  /**< Synchronization Busy Register                      */
} WDOG_TypeDef;
/** @} End of group EFM32PG22_WDOG */


/**************************************************************************//**
 * @defgroup EFM32PG22C200F512IM40_Peripheral_Base EFM32PG22C200F512IM40 Peripheral Memory Map
 * @{
 *****************************************************************************/

#define EMU_S_BASE                   (0x40004000UL) /* EMU_S base address */
#define CMU_S_BASE                   (0x40008000UL) /* CMU_S base address */
#define HFXO0_S_BASE                 (0x4000C000UL) /* HFXO0_S base address */
#define HFRCO0_S_BASE                (0x40010000UL) /* HFRCO0_S base address */
#define FSRCO_S_BASE                 (0x40018000UL) /* FSRCO_S base address */
#define DPLL0_S_BASE                 (0x4001C000UL) /* DPLL0_S base address */
#define LFXO_S_BASE                  (0x40020000UL) /* LFXO_S base address */
#define LFRCO_S_BASE                 (0x40024000UL) /* LFRCO_S base address */
#define ULFRCO_S_BASE                (0x40028000UL) /* ULFRCO_S base address */
#define MSC_S_BASE                   (0x40030000UL) /* MSC_S base address */
#define ICACHE0_S_BASE               (0x40034000UL) /* ICACHE0_S base address */
#define PRS_S_BASE                   (0x40038000UL) /* PRS_S base address */
#define GPIO_S_BASE                  (0x4003C000UL) /* GPIO_S base address */
#define LDMA_S_BASE                  (0x40040000UL) /* LDMA_S base address */
#define LDMAXBAR_S_BASE              (0x40044000UL) /* LDMAXBAR_S base address */
#define TIMER0_S_BASE                (0x40048000UL) /* TIMER0_S base address */
#define TIMER1_S_BASE                (0x4004C000UL) /* TIMER1_S base address */
#define TIMER2_S_BASE                (0x40050000UL) /* TIMER2_S base address */
#define TIMER3_S_BASE                (0x40054000UL) /* TIMER3_S base address */
#define TIMER4_S_BASE                (0x40058000UL) /* TIMER4_S base address */
#define USART0_S_BASE                (0x4005C000UL) /* USART0_S base address */
#define USART1_S_BASE                (0x40060000UL) /* USART1_S base address */
#define BURTC_S_BASE                 (0x40064000UL) /* BURTC_S base address */
#define I2C1_S_BASE                  (0x40068000UL) /* I2C1_S base address */
#define SYSCFG_S_CFGNS_BASE          (0x40078000UL) /* SYSCFG_S_CFGNS base address */
#define SYSCFG_S_BASE                (0x4007C000UL) /* SYSCFG_S base address */
#define BURAM_S_BASE                 (0x40080000UL) /* BURAM_S base address */
#define GPCRC_S_BASE                 (0x40088000UL) /* GPCRC_S base address */
#define DCDC_S_BASE                  (0x40094000UL) /* DCDC_S base address */
#define PDM_S_BASE                   (0x40098000UL) /* PDM_S base address */
#define SMU_S_BASE                   (0x44008000UL) /* SMU_S base address */
#define SMU_S_CFGNS_BASE             (0x4400C000UL) /* SMU_S_CFGNS base address */
#define RTCC_S_BASE                  (0x48000000UL) /* RTCC_S base address */
#define LETIMER0_S_BASE              (0x4A000000UL) /* LETIMER0_S base address */
#define IADC0_S_BASE                 (0x4A004000UL) /* IADC0_S base address */
#define I2C0_S_BASE                  (0x4A010000UL) /* I2C0_S base address */
#define WDOG0_S_BASE                 (0x4A018000UL) /* WDOG0_S base address */
#define AMUXCP0_S_BASE               (0x4A020000UL) /* AMUXCP0_S base address */
#define EUART0_S_BASE                (0x4A030000UL) /* EUART0_S base address */
#define CRYPTOACC_S_BASE             (0x4C020000UL) /* CRYPTOACC_S base address */
#define CRYPTOACC_S_RNGCTRL_BASE     (0x4C021000UL) /* CRYPTOACC_S_RNGCTRL base address */
#define CRYPTOACC_S_PKCTRL_BASE      (0x4C022000UL) /* CRYPTOACC_S_PKCTRL base address */
#define EMU_NS_BASE                  (0x50004000UL) /* EMU_NS base address */
#define CMU_NS_BASE                  (0x50008000UL) /* CMU_NS base address */
#define HFXO0_NS_BASE                (0x5000C000UL) /* HFXO0_NS base address */
#define HFRCO0_NS_BASE               (0x50010000UL) /* HFRCO0_NS base address */
#define FSRCO_NS_BASE                (0x50018000UL) /* FSRCO_NS base address */
#define DPLL0_NS_BASE                (0x5001C000UL) /* DPLL0_NS base address */
#define LFXO_NS_BASE                 (0x50020000UL) /* LFXO_NS base address */
#define LFRCO_NS_BASE                (0x50024000UL) /* LFRCO_NS base address */
#define ULFRCO_NS_BASE               (0x50028000UL) /* ULFRCO_NS base address */
#define MSC_NS_BASE                  (0x50030000UL) /* MSC_NS base address */
#define ICACHE0_NS_BASE              (0x50034000UL) /* ICACHE0_NS base address */
#define PRS_NS_BASE                  (0x50038000UL) /* PRS_NS base address */
#define GPIO_NS_BASE                 (0x5003C000UL) /* GPIO_NS base address */
#define LDMA_NS_BASE                 (0x50040000UL) /* LDMA_NS base address */
#define LDMAXBAR_NS_BASE             (0x50044000UL) /* LDMAXBAR_NS base address */
#define TIMER0_NS_BASE               (0x50048000UL) /* TIMER0_NS base address */
#define TIMER1_NS_BASE               (0x5004C000UL) /* TIMER1_NS base address */
#define TIMER2_NS_BASE               (0x50050000UL) /* TIMER2_NS base address */
#define TIMER3_NS_BASE               (0x50054000UL) /* TIMER3_NS base address */
#define TIMER4_NS_BASE               (0x50058000UL) /* TIMER4_NS base address */
#define USART0_NS_BASE               (0x5005C000UL) /* USART0_NS base address */
#define USART1_NS_BASE               (0x50060000UL) /* USART1_NS base address */
#define BURTC_NS_BASE                (0x50064000UL) /* BURTC_NS base address */
#define I2C1_NS_BASE                 (0x50068000UL) /* I2C1_NS base address */
#define SYSCFG_NS_CFGNS_BASE         (0x50078000UL) /* SYSCFG_NS_CFGNS base address */
#define SYSCFG_NS_BASE               (0x5007C000UL) /* SYSCFG_NS base address */
#define BURAM_NS_BASE                (0x50080000UL) /* BURAM_NS base address */
#define GPCRC_NS_BASE                (0x50088000UL) /* GPCRC_NS base address */
#define DCDC_NS_BASE                 (0x50094000UL) /* DCDC_NS base address */
#define PDM_NS_BASE                  (0x50098000UL) /* PDM_NS base address */
#define SMU_NS_BASE                  (0x54008000UL) /* SMU_NS base address */
#define SMU_NS_CFGNS_BASE            (0x5400C000UL) /* SMU_NS_CFGNS base address */
#define RTCC_NS_BASE                 (0x58000000UL) /* RTCC_NS base address */
#define LETIMER0_NS_BASE             (0x5A000000UL) /* LETIMER0_NS base address */
#define IADC0_NS_BASE                (0x5A004000UL) /* IADC0_NS base address */
#define I2C0_NS_BASE                 (0x5A010000UL) /* I2C0_NS base address */
#define WDOG0_NS_BASE                (0x5A018000UL) /* WDOG0_NS base address */
#define AMUXCP0_NS_BASE              (0x5A020000UL) /* AMUXCP0_NS base address */
#define EUART0_NS_BASE               (0x5A030000UL) /* EUART0_NS base address */
#define CRYPTOACC_NS_BASE            (0x5C020000UL) /* CRYPTOACC_NS base address */
#define CRYPTOACC_NS_RNGCTRL_BASE    (0x5C021000UL) /* CRYPTOACC_NS_RNGCTRL base address */
#define CRYPTOACC_NS_PKCTRL_BASE     (0x5C022000UL) /* CRYPTOACC_NS_PKCTRL base address */

#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"

#endif
#if defined(SL_CATALOG_TRUSTZONE_SECURE_CONFIG_PRESENT)
#include "sl_trustzone_secure_config.h"

#endif

#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_EMU_S)) || SL_TRUSTZONE_PERIPHERAL_EMU_S)
#define EMU_BASE                  (EMU_S_BASE)               /* EMU base address */
#else
#define EMU_BASE                  (EMU_NS_BASE)              /* EMU base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_EMU_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_CMU_S)) || SL_TRUSTZONE_PERIPHERAL_CMU_S)
#define CMU_BASE                  (CMU_S_BASE)               /* CMU base address */
#else
#define CMU_BASE                  (CMU_NS_BASE)              /* CMU base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_CMU_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_HFXO0_S)) || SL_TRUSTZONE_PERIPHERAL_HFXO0_S)
#define HFXO0_BASE                (HFXO0_S_BASE)             /* HFXO0 base address */
#else
#define HFXO0_BASE                (HFXO0_NS_BASE)            /* HFXO0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_HFXO0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_HFRCO0_S)) || SL_TRUSTZONE_PERIPHERAL_HFRCO0_S)
#define HFRCO0_BASE               (HFRCO0_S_BASE)            /* HFRCO0 base address */
#else
#define HFRCO0_BASE               (HFRCO0_NS_BASE)           /* HFRCO0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_HFRCO0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_FSRCO_S)) || SL_TRUSTZONE_PERIPHERAL_FSRCO_S)
#define FSRCO_BASE                (FSRCO_S_BASE)             /* FSRCO base address */
#else
#define FSRCO_BASE                (FSRCO_NS_BASE)            /* FSRCO base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_FSRCO_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_DPLL0_S)) || SL_TRUSTZONE_PERIPHERAL_DPLL0_S)
#define DPLL0_BASE                (DPLL0_S_BASE)             /* DPLL0 base address */
#else
#define DPLL0_BASE                (DPLL0_NS_BASE)            /* DPLL0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_DPLL0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_LFXO_S)) || SL_TRUSTZONE_PERIPHERAL_LFXO_S)
#define LFXO_BASE                 (LFXO_S_BASE)              /* LFXO base address */
#else
#define LFXO_BASE                 (LFXO_NS_BASE)             /* LFXO base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_LFXO_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_LFRCO_S)) || SL_TRUSTZONE_PERIPHERAL_LFRCO_S)
#define LFRCO_BASE                (LFRCO_S_BASE)             /* LFRCO base address */
#else
#define LFRCO_BASE                (LFRCO_NS_BASE)            /* LFRCO base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_LFRCO_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_ULFRCO_S)) || SL_TRUSTZONE_PERIPHERAL_ULFRCO_S)
#define ULFRCO_BASE               (ULFRCO_S_BASE)            /* ULFRCO base address */
#else
#define ULFRCO_BASE               (ULFRCO_NS_BASE)           /* ULFRCO base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_ULFRCO_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_MSC_S)) || SL_TRUSTZONE_PERIPHERAL_MSC_S)
#define MSC_BASE                  (MSC_S_BASE)               /* MSC base address */
#else
#define MSC_BASE                  (MSC_NS_BASE)              /* MSC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_MSC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_ICACHE0_S)) || SL_TRUSTZONE_PERIPHERAL_ICACHE0_S)
#define ICACHE0_BASE              (ICACHE0_S_BASE)           /* ICACHE0 base address */
#else
#define ICACHE0_BASE              (ICACHE0_NS_BASE)          /* ICACHE0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_ICACHE0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_PRS_S)) || SL_TRUSTZONE_PERIPHERAL_PRS_S)
#define PRS_BASE                  (PRS_S_BASE)               /* PRS base address */
#else
#define PRS_BASE                  (PRS_NS_BASE)              /* PRS base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_PRS_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_GPIO_S)) || SL_TRUSTZONE_PERIPHERAL_GPIO_S)
#define GPIO_BASE                 (GPIO_S_BASE)              /* GPIO base address */
#else
#define GPIO_BASE                 (GPIO_NS_BASE)             /* GPIO base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_GPIO_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_LDMA_S)) || SL_TRUSTZONE_PERIPHERAL_LDMA_S)
#define LDMA_BASE                 (LDMA_S_BASE)              /* LDMA base address */
#else
#define LDMA_BASE                 (LDMA_NS_BASE)             /* LDMA base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_LDMA_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_LDMAXBAR_S)) || SL_TRUSTZONE_PERIPHERAL_LDMAXBAR_S)
#define LDMAXBAR_BASE             (LDMAXBAR_S_BASE)          /* LDMAXBAR base address */
#else
#define LDMAXBAR_BASE             (LDMAXBAR_NS_BASE)         /* LDMAXBAR base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_LDMAXBAR_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_TIMER0_S)) || SL_TRUSTZONE_PERIPHERAL_TIMER0_S)
#define TIMER0_BASE               (TIMER0_S_BASE)            /* TIMER0 base address */
#else
#define TIMER0_BASE               (TIMER0_NS_BASE)           /* TIMER0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_TIMER0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_TIMER1_S)) || SL_TRUSTZONE_PERIPHERAL_TIMER1_S)
#define TIMER1_BASE               (TIMER1_S_BASE)            /* TIMER1 base address */
#else
#define TIMER1_BASE               (TIMER1_NS_BASE)           /* TIMER1 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_TIMER1_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_TIMER2_S)) || SL_TRUSTZONE_PERIPHERAL_TIMER2_S)
#define TIMER2_BASE               (TIMER2_S_BASE)            /* TIMER2 base address */
#else
#define TIMER2_BASE               (TIMER2_NS_BASE)           /* TIMER2 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_TIMER2_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_TIMER3_S)) || SL_TRUSTZONE_PERIPHERAL_TIMER3_S)
#define TIMER3_BASE               (TIMER3_S_BASE)            /* TIMER3 base address */
#else
#define TIMER3_BASE               (TIMER3_NS_BASE)           /* TIMER3 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_TIMER3_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_TIMER4_S)) || SL_TRUSTZONE_PERIPHERAL_TIMER4_S)
#define TIMER4_BASE               (TIMER4_S_BASE)            /* TIMER4 base address */
#else
#define TIMER4_BASE               (TIMER4_NS_BASE)           /* TIMER4 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_TIMER4_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_USART0_S)) || SL_TRUSTZONE_PERIPHERAL_USART0_S)
#define USART0_BASE               (USART0_S_BASE)            /* USART0 base address */
#else
#define USART0_BASE               (USART0_NS_BASE)           /* USART0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_USART0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_USART1_S)) || SL_TRUSTZONE_PERIPHERAL_USART1_S)
#define USART1_BASE               (USART1_S_BASE)            /* USART1 base address */
#else
#define USART1_BASE               (USART1_NS_BASE)           /* USART1 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_USART1_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_BURTC_S)) || SL_TRUSTZONE_PERIPHERAL_BURTC_S)
#define BURTC_BASE                (BURTC_S_BASE)             /* BURTC base address */
#else
#define BURTC_BASE                (BURTC_NS_BASE)            /* BURTC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_BURTC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_I2C1_S)) || SL_TRUSTZONE_PERIPHERAL_I2C1_S)
#define I2C1_BASE                 (I2C1_S_BASE)              /* I2C1 base address */
#else
#define I2C1_BASE                 (I2C1_NS_BASE)             /* I2C1 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_I2C1_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_SYSCFG_CFGNS_S)) || SL_TRUSTZONE_PERIPHERAL_SYSCFG_CFGNS_S)
#define SYSCFG_CFGNS_BASE         (SYSCFG_S_CFGNS_BASE)      /* SYSCFG_CFGNS base address */
#else
#define SYSCFG_CFGNS_BASE         (SYSCFG_NS_CFGNS_BASE)     /* SYSCFG_CFGNS base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_SYSCFG_CFGNS_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_SYSCFG_S)) || SL_TRUSTZONE_PERIPHERAL_SYSCFG_S)
#define SYSCFG_BASE               (SYSCFG_S_BASE)            /* SYSCFG base address */
#else
#define SYSCFG_BASE               (SYSCFG_NS_BASE)           /* SYSCFG base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_SYSCFG_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_BURAM_S)) || SL_TRUSTZONE_PERIPHERAL_BURAM_S)
#define BURAM_BASE                (BURAM_S_BASE)             /* BURAM base address */
#else
#define BURAM_BASE                (BURAM_NS_BASE)            /* BURAM base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_BURAM_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_GPCRC_S)) || SL_TRUSTZONE_PERIPHERAL_GPCRC_S)
#define GPCRC_BASE                (GPCRC_S_BASE)             /* GPCRC base address */
#else
#define GPCRC_BASE                (GPCRC_NS_BASE)            /* GPCRC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_GPCRC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_DCDC_S)) || SL_TRUSTZONE_PERIPHERAL_DCDC_S)
#define DCDC_BASE                 (DCDC_S_BASE)              /* DCDC base address */
#else
#define DCDC_BASE                 (DCDC_NS_BASE)             /* DCDC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_DCDC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_PDM_S)) || SL_TRUSTZONE_PERIPHERAL_PDM_S)
#define PDM_BASE                  (PDM_S_BASE)               /* PDM base address */
#else
#define PDM_BASE                  (PDM_NS_BASE)              /* PDM base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_PDM_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_SMU_S)) || SL_TRUSTZONE_PERIPHERAL_SMU_S)
#define SMU_BASE                  (SMU_S_BASE)               /* SMU base address */
#else
#define SMU_BASE                  (SMU_S_BASE)               /* SMU base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_SMU_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_SMU_CFGNS_S)) || SL_TRUSTZONE_PERIPHERAL_SMU_CFGNS_S)
#define SMU_CFGNS_BASE            (SMU_S_CFGNS_BASE)         /* SMU_CFGNS base address */
#else
#define SMU_CFGNS_BASE            (SMU_NS_CFGNS_BASE)        /* SMU_CFGNS base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_SMU_CFGNS_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_RTCC_S)) || SL_TRUSTZONE_PERIPHERAL_RTCC_S)
#define RTCC_BASE                 (RTCC_S_BASE)              /* RTCC base address */
#else
#define RTCC_BASE                 (RTCC_NS_BASE)             /* RTCC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_RTCC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_LETIMER0_S)) || SL_TRUSTZONE_PERIPHERAL_LETIMER0_S)
#define LETIMER0_BASE             (LETIMER0_S_BASE)          /* LETIMER0 base address */
#else
#define LETIMER0_BASE             (LETIMER0_NS_BASE)         /* LETIMER0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_LETIMER0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_IADC0_S)) || SL_TRUSTZONE_PERIPHERAL_IADC0_S)
#define IADC0_BASE                (IADC0_S_BASE)             /* IADC0 base address */
#else
#define IADC0_BASE                (IADC0_NS_BASE)            /* IADC0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_IADC0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_I2C0_S)) || SL_TRUSTZONE_PERIPHERAL_I2C0_S)
#define I2C0_BASE                 (I2C0_S_BASE)              /* I2C0 base address */
#else
#define I2C0_BASE                 (I2C0_NS_BASE)             /* I2C0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_I2C0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_WDOG0_S)) || SL_TRUSTZONE_PERIPHERAL_WDOG0_S)
#define WDOG0_BASE                (WDOG0_S_BASE)             /* WDOG0 base address */
#else
#define WDOG0_BASE                (WDOG0_NS_BASE)            /* WDOG0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_WDOG0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_AMUXCP0_S)) || SL_TRUSTZONE_PERIPHERAL_AMUXCP0_S)
#define AMUXCP0_BASE              (AMUXCP0_S_BASE)           /* AMUXCP0 base address */
#else
#define AMUXCP0_BASE              (AMUXCP0_NS_BASE)          /* AMUXCP0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_AMUXCP0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_EUART0_S)) || SL_TRUSTZONE_PERIPHERAL_EUART0_S)
#define EUART0_BASE               (EUART0_S_BASE)            /* EUART0 base address */
#else
#define EUART0_BASE               (EUART0_NS_BASE)           /* EUART0 base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_EUART0_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_S)) || SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_S)
#define CRYPTOACC_BASE            (CRYPTOACC_S_BASE)         /* CRYPTOACC base address */
#else
#define CRYPTOACC_BASE            (CRYPTOACC_NS_BASE)        /* CRYPTOACC base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_RNGCTRL_S)) || SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_RNGCTRL_S)
#define CRYPTOACC_RNGCTRL_BASE    (CRYPTOACC_S_RNGCTRL_BASE)  /* CRYPTOACC_RNGCTRL base address */
#else
#define CRYPTOACC_RNGCTRL_BASE    (CRYPTOACC_NS_RNGCTRL_BASE) /* CRYPTOACC_RNGCTRL base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_RNGCTRL_S */
#if ((defined(SL_TRUSTZONE_SECURE) && !defined(SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_PKCTRL_S)) || SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_PKCTRL_S)
#define CRYPTOACC_PKCTRL_BASE     (CRYPTOACC_S_PKCTRL_BASE)  /* CRYPTOACC_PKCTRL base address */
#else
#define CRYPTOACC_PKCTRL_BASE     (CRYPTOACC_NS_PKCTRL_BASE) /* CRYPTOACC_PKCTRL base address */
#endif /* SL_TRUSTZONE_PERIPHERAL_CRYPTOACC_PKCTRL_S */

#define DEVINFO_BASE              (0x0FE08000UL) /* DEVINFO base address */
/** @} End of group EFM32PG22C200F512IM40_Peripheral_Base */

/**************************************************************************//**
 * @defgroup EFM32PG22C200F512IM40_Peripheral_Declaration EFM32PG22C200F512IM40 Peripheral Declarations Map
 * @{
 *****************************************************************************/

#define EMU_S                   ((EMU_TypeDef *) EMU_S_BASE)                              /**< EMU_S base pointer */
#define CMU_S                   ((CMU_TypeDef *) CMU_S_BASE)                              /**< CMU_S base pointer */
#define HFXO0_S                 ((HFXO_TypeDef *) HFXO0_S_BASE)                           /**< HFXO0_S base pointer */
#define HFRCO0_S                ((HFRCO_TypeDef *) HFRCO0_S_BASE)                         /**< HFRCO0_S base pointer */
#define FSRCO_S                 ((FSRCO_TypeDef *) FSRCO_S_BASE)                          /**< FSRCO_S base pointer */
#define DPLL0_S                 ((DPLL_TypeDef *) DPLL0_S_BASE)                           /**< DPLL0_S base pointer */
#define LFXO_S                  ((LFXO_TypeDef *) LFXO_S_BASE)                            /**< LFXO_S base pointer */
#define LFRCO_S                 ((LFRCO_TypeDef *) LFRCO_S_BASE)                          /**< LFRCO_S base pointer */
#define ULFRCO_S                ((ULFRCO_TypeDef *) ULFRCO_S_BASE)                        /**< ULFRCO_S base pointer */
#define MSC_S                   ((MSC_TypeDef *) MSC_S_BASE)                              /**< MSC_S base pointer */
#define ICACHE0_S               ((ICACHE_TypeDef *) ICACHE0_S_BASE)                       /**< ICACHE0_S base pointer */
#define PRS_S                   ((PRS_TypeDef *) PRS_S_BASE)                              /**< PRS_S base pointer */
#define GPIO_S                  ((GPIO_TypeDef *) GPIO_S_BASE)                            /**< GPIO_S base pointer */
#define LDMA_S                  ((LDMA_TypeDef *) LDMA_S_BASE)                            /**< LDMA_S base pointer */
#define LDMAXBAR_S              ((LDMAXBAR_TypeDef *) LDMAXBAR_S_BASE)                    /**< LDMAXBAR_S base pointer */
#define TIMER0_S                ((TIMER_TypeDef *) TIMER0_S_BASE)                         /**< TIMER0_S base pointer */
#define TIMER1_S                ((TIMER_TypeDef *) TIMER1_S_BASE)                         /**< TIMER1_S base pointer */
#define TIMER2_S                ((TIMER_TypeDef *) TIMER2_S_BASE)                         /**< TIMER2_S base pointer */
#define TIMER3_S                ((TIMER_TypeDef *) TIMER3_S_BASE)                         /**< TIMER3_S base pointer */
#define TIMER4_S                ((TIMER_TypeDef *) TIMER4_S_BASE)                         /**< TIMER4_S base pointer */
#define USART0_S                ((USART_TypeDef *) USART0_S_BASE)                         /**< USART0_S base pointer */
#define USART1_S                ((USART_TypeDef *) USART1_S_BASE)                         /**< USART1_S base pointer */
#define BURTC_S                 ((BURTC_TypeDef *) BURTC_S_BASE)                          /**< BURTC_S base pointer */
#define I2C1_S                  ((I2C_TypeDef *) I2C1_S_BASE)                             /**< I2C1_S base pointer */
#define SYSCFG_S_CFGNS          ((SYSCFG_CFGNS_TypeDef *) SYSCFG_S_CFGNS_BASE)            /**< SYSCFG_S_CFGNS base pointer */
#define SYSCFG_S                ((SYSCFG_TypeDef *) SYSCFG_S_BASE)                        /**< SYSCFG_S base pointer */
#define BURAM_S                 ((BURAM_TypeDef *) BURAM_S_BASE)                          /**< BURAM_S base pointer */
#define GPCRC_S                 ((GPCRC_TypeDef *) GPCRC_S_BASE)                          /**< GPCRC_S base pointer */
#define DCDC_S                  ((DCDC_TypeDef *) DCDC_S_BASE)                            /**< DCDC_S base pointer */
#define PDM_S                   ((PDM_TypeDef *) PDM_S_BASE)                              /**< PDM_S base pointer */
#define SMU_S                   ((SMU_TypeDef *) SMU_S_BASE)                              /**< SMU_S base pointer */
#define SMU_S_CFGNS             ((SMU_CFGNS_TypeDef *) SMU_S_CFGNS_BASE)                  /**< SMU_S_CFGNS base pointer */
#define RTCC_S                  ((RTCC_TypeDef *) RTCC_S_BASE)                            /**< RTCC_S base pointer */
#define LETIMER0_S              ((LETIMER_TypeDef *) LETIMER0_S_BASE)                     /**< LETIMER0_S base pointer */
#define IADC0_S                 ((IADC_TypeDef *) IADC0_S_BASE)                           /**< IADC0_S base pointer */
#define I2C0_S                  ((I2C_TypeDef *) I2C0_S_BASE)                             /**< I2C0_S base pointer */
#define WDOG0_S                 ((WDOG_TypeDef *) WDOG0_S_BASE)                           /**< WDOG0_S base pointer */
#define AMUXCP0_S               ((AMUXCP_TypeDef *) AMUXCP0_S_BASE)                       /**< AMUXCP0_S base pointer */
#define EUART0_S                ((EUSART_TypeDef *) EUART0_S_BASE)                        /**< EUART0_S base pointer */
#define CRYPTOACC_S             ((CRYPTOACC_TypeDef *) CRYPTOACC_S_BASE)                  /**< CRYPTOACC_S base pointer */
#define CRYPTOACC_S_RNGCTRL     ((CRYPTOACC_RNGCTRL_TypeDef *) CRYPTOACC_S_RNGCTRL_BASE)  /**< CRYPTOACC_S_RNGCTRL base pointer */
#define CRYPTOACC_S_PKCTRL      ((CRYPTOACC_PKCTRL_TypeDef *) CRYPTOACC_S_PKCTRL_BASE)    /**< CRYPTOACC_S_PKCTRL base pointer */
#define EMU_NS                  ((EMU_TypeDef *) EMU_NS_BASE)                             /**< EMU_NS base pointer */
#define CMU_NS                  ((CMU_TypeDef *) CMU_NS_BASE)                             /**< CMU_NS base pointer */
#define HFXO0_NS                ((HFXO_TypeDef *) HFXO0_NS_BASE)                          /**< HFXO0_NS base pointer */
#define HFRCO0_NS               ((HFRCO_TypeDef *) HFRCO0_NS_BASE)                        /**< HFRCO0_NS base pointer */
#define FSRCO_NS                ((FSRCO_TypeDef *) FSRCO_NS_BASE)                         /**< FSRCO_NS base pointer */
#define DPLL0_NS                ((DPLL_TypeDef *) DPLL0_NS_BASE)                          /**< DPLL0_NS base pointer */
#define LFXO_NS                 ((LFXO_TypeDef *) LFXO_NS_BASE)                           /**< LFXO_NS base pointer */
#define LFRCO_NS                ((LFRCO_TypeDef *) LFRCO_NS_BASE)                         /**< LFRCO_NS base pointer */
#define ULFRCO_NS               ((ULFRCO_TypeDef *) ULFRCO_NS_BASE)                       /**< ULFRCO_NS base pointer */
#define MSC_NS                  ((MSC_TypeDef *) MSC_NS_BASE)                             /**< MSC_NS base pointer */
#define ICACHE0_NS              ((ICACHE_TypeDef *) ICACHE0_NS_BASE)                      /**< ICACHE0_NS base pointer */
#define PRS_NS                  ((PRS_TypeDef *) PRS_NS_BASE)                             /**< PRS_NS base pointer */
#define GPIO_NS                 ((GPIO_TypeDef *) GPIO_NS_BASE)                           /**< GPIO_NS base pointer */
#define LDMA_NS                 ((LDMA_TypeDef *) LDMA_NS_BASE)                           /**< LDMA_NS base pointer */
#define LDMAXBAR_NS             ((LDMAXBAR_TypeDef *) LDMAXBAR_NS_BASE)                   /**< LDMAXBAR_NS base pointer */
#define TIMER0_NS               ((TIMER_TypeDef *) TIMER0_NS_BASE)                        /**< TIMER0_NS base pointer */
#define TIMER1_NS               ((TIMER_TypeDef *) TIMER1_NS_BASE)                        /**< TIMER1_NS base pointer */
#define TIMER2_NS               ((TIMER_TypeDef *) TIMER2_NS_BASE)                        /**< TIMER2_NS base pointer */
#define TIMER3_NS               ((TIMER_TypeDef *) TIMER3_NS_BASE)                        /**< TIMER3_NS base pointer */
#define TIMER4_NS               ((TIMER_TypeDef *) TIMER4_NS_BASE)                        /**< TIMER4_NS base pointer */
#define USART0_NS               ((USART_TypeDef *) USART0_NS_BASE)                        /**< USART0_NS base pointer */
#define USART1_NS               ((USART_TypeDef *) USART1_NS_BASE)                        /**< USART1_NS base pointer */
#define BURTC_NS                ((BURTC_TypeDef *) BURTC_NS_BASE)                         /**< BURTC_NS base pointer */
#define I2C1_NS                 ((I2C_TypeDef *) I2C1_NS_BASE)                            /**< I2C1_NS base pointer */
#define SYSCFG_NS_CFGNS         ((SYSCFG_CFGNS_TypeDef *) SYSCFG_NS_CFGNS_BASE)           /**< SYSCFG_NS_CFGNS base pointer */
#define SYSCFG_NS               ((SYSCFG_TypeDef *) SYSCFG_NS_BASE)                       /**< SYSCFG_NS base pointer */
#define BURAM_NS                ((BURAM_TypeDef *) BURAM_NS_BASE)                         /**< BURAM_NS base pointer */
#define GPCRC_NS                ((GPCRC_TypeDef *) GPCRC_NS_BASE)                         /**< GPCRC_NS base pointer */
#define DCDC_NS                 ((DCDC_TypeDef *) DCDC_NS_BASE)                           /**< DCDC_NS base pointer */
#define PDM_NS                  ((PDM_TypeDef *) PDM_NS_BASE)                             /**< PDM_NS base pointer */
#define SMU_NS                  ((SMU_TypeDef *) SMU_NS_BASE)                             /**< SMU_NS base pointer */
#define SMU_NS_CFGNS            ((SMU_CFGNS_TypeDef *) SMU_NS_CFGNS_BASE)                 /**< SMU_NS_CFGNS base pointer */
#define RTCC_NS                 ((RTCC_TypeDef *) RTCC_NS_BASE)                           /**< RTCC_NS base pointer */
#define LETIMER0_NS             ((LETIMER_TypeDef *) LETIMER0_NS_BASE)                    /**< LETIMER0_NS base pointer */
#define IADC0_NS                ((IADC_TypeDef *) IADC0_NS_BASE)                          /**< IADC0_NS base pointer */
#define I2C0_NS                 ((I2C_TypeDef *) I2C0_NS_BASE)                            /**< I2C0_NS base pointer */
#define WDOG0_NS                ((WDOG_TypeDef *) WDOG0_NS_BASE)                          /**< WDOG0_NS base pointer */
#define AMUXCP0_NS              ((AMUXCP_TypeDef *) AMUXCP0_NS_BASE)                      /**< AMUXCP0_NS base pointer */
#define EUART0_NS               ((EUSART_TypeDef *) EUART0_NS_BASE)                       /**< EUART0_NS base pointer */
#define CRYPTOACC_NS            ((CRYPTOACC_TypeDef *) CRYPTOACC_NS_BASE)                 /**< CRYPTOACC_NS base pointer */
#define CRYPTOACC_NS_RNGCTRL    ((CRYPTOACC_RNGCTRL_TypeDef *) CRYPTOACC_NS_RNGCTRL_BASE) /**< CRYPTOACC_NS_RNGCTRL base pointer */
#define CRYPTOACC_NS_PKCTRL     ((CRYPTOACC_PKCTRL_TypeDef *) CRYPTOACC_NS_PKCTRL_BASE)   /**< CRYPTOACC_NS_PKCTRL base pointer */
#define EMU                     ((EMU_TypeDef *) EMU_BASE)                                /**< EMU base pointer */
#define CMU                     ((CMU_TypeDef *) CMU_BASE)                                /**< CMU base pointer */
#define HFXO0                   ((HFXO_TypeDef *) HFXO0_BASE)                             /**< HFXO0 base pointer */
#define HFRCO0                  ((HFRCO_TypeDef *) HFRCO0_BASE)                           /**< HFRCO0 base pointer */
#define FSRCO                   ((FSRCO_TypeDef *) FSRCO_BASE)                            /**< FSRCO base pointer */
#define DPLL0                   ((DPLL_TypeDef *) DPLL0_BASE)                             /**< DPLL0 base pointer */
#define LFXO                    ((LFXO_TypeDef *) LFXO_BASE)                              /**< LFXO base pointer */
#define LFRCO                   ((LFRCO_TypeDef *) LFRCO_BASE)                            /**< LFRCO base pointer */
#define ULFRCO                  ((ULFRCO_TypeDef *) ULFRCO_BASE)                          /**< ULFRCO base pointer */
#define MSC                     ((MSC_TypeDef *) MSC_BASE)                                /**< MSC base pointer */
#define ICACHE0                 ((ICACHE_TypeDef *) ICACHE0_BASE)                         /**< ICACHE0 base pointer */
#define PRS                     ((PRS_TypeDef *) PRS_BASE)                                /**< PRS base pointer */
#define GPIO                    ((GPIO_TypeDef *) GPIO_BASE)                              /**< GPIO base pointer */
#define LDMA                    ((LDMA_TypeDef *) LDMA_BASE)                              /**< LDMA base pointer */
#define LDMAXBAR                ((LDMAXBAR_TypeDef *) LDMAXBAR_BASE)                      /**< LDMAXBAR base pointer */
#define TIMER0                  ((TIMER_TypeDef *) TIMER0_BASE)                           /**< TIMER0 base pointer */
#define TIMER1                  ((TIMER_TypeDef *) TIMER1_BASE)                           /**< TIMER1 base pointer */
#define TIMER2                  ((TIMER_TypeDef *) TIMER2_BASE)                           /**< TIMER2 base pointer */
#define TIMER3                  ((TIMER_TypeDef *) TIMER3_BASE)                           /**< TIMER3 base pointer */
#define TIMER4                  ((TIMER_TypeDef *) TIMER4_BASE)                           /**< TIMER4 base pointer */
#define USART0                  ((USART_TypeDef *) USART0_BASE)                           /**< USART0 base pointer */
#define USART1                  ((USART_TypeDef *) USART1_BASE)                           /**< USART1 base pointer */
#define BURTC                   ((BURTC_TypeDef *) BURTC_BASE)                            /**< BURTC base pointer */
#define I2C1                    ((I2C_TypeDef *) I2C1_BASE)                               /**< I2C1 base pointer */
#define SYSCFG_CFGNS            ((SYSCFG_CFGNS_TypeDef *) SYSCFG_CFGNS_BASE)              /**< SYSCFG_CFGNS base pointer */
#define SYSCFG                  ((SYSCFG_TypeDef *) SYSCFG_BASE)                          /**< SYSCFG base pointer */
#define BURAM                   ((BURAM_TypeDef *) BURAM_BASE)                            /**< BURAM base pointer */
#define GPCRC                   ((GPCRC_TypeDef *) GPCRC_BASE)                            /**< GPCRC base pointer */
#define DCDC                    ((DCDC_TypeDef *) DCDC_BASE)                              /**< DCDC base pointer */
#define PDM                     ((PDM_TypeDef *) PDM_BASE)                                /**< PDM base pointer */
#define SMU                     ((SMU_TypeDef *) SMU_BASE)                                /**< SMU base pointer */
#define SMU_CFGNS               ((SMU_CFGNS_TypeDef *) SMU_CFGNS_BASE)                    /**< SMU_CFGNS base pointer */
#define RTCC                    ((RTCC_TypeDef *) RTCC_BASE)                              /**< RTCC base pointer */
#define LETIMER0                ((LETIMER_TypeDef *) LETIMER0_BASE)                       /**< LETIMER0 base pointer */
#define IADC0                   ((IADC_TypeDef *) IADC0_BASE)                             /**< IADC0 base pointer */
#define I2C0                    ((I2C_TypeDef *) I2C0_BASE)                               /**< I2C0 base pointer */
#define WDOG0                   ((WDOG_TypeDef *) WDOG0_BASE)                             /**< WDOG0 base pointer */
#define AMUXCP0                 ((AMUXCP_TypeDef *) AMUXCP0_BASE)                         /**< AMUXCP0 base pointer */
#define EUART0                  ((EUSART_TypeDef *) EUART0_BASE)                          /**< EUART0 base pointer */
#define CRYPTOACC               ((CRYPTOACC_TypeDef *) CRYPTOACC_BASE)                    /**< CRYPTOACC base pointer */
#define CRYPTOACC_RNGCTRL       ((CRYPTOACC_RNGCTRL_TypeDef *) CRYPTOACC_RNGCTRL_BASE)    /**< CRYPTOACC_RNGCTRL base pointer */
#define CRYPTOACC_PKCTRL        ((CRYPTOACC_PKCTRL_TypeDef *) CRYPTOACC_PKCTRL_BASE)      /**< CRYPTOACC_PKCTRL base pointer */
#define DEVINFO                 ((DEVINFO_TypeDef *) DEVINFO_BASE)                        /**< DEVINFO base pointer */
/** @} End of group EFM32PG22C200F512IM40_Peripheral_Declaration */

/** @} End of group EFM32PG22C200F512IM40 */
/** @}} End of group Parts */

#ifdef __cplusplus
}
#endif
#endif
