/**
  ******************************************************************************
  * @file    stm32f103x6.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F1xx devices.            
  *            
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripherals registers hardware
  *  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SDRAM_STM32_GD32F4_F7__H_
#define __SDRAM_STM32_GD32F4_F7__H_

/******************************************************************************/
/*                                                                            */
/*                          Flexible Memory Controller                        */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for FMC_SDCR1 register  ******************/
#define FMC_SDCR1_NC_Pos           (0U)
#define FMC_SDCR1_NC_Msk           (0x3UL << FMC_SDCR1_NC_Pos)                  /*!< 0x00000003 */
#define FMC_SDCR1_NC               FMC_SDCR1_NC_Msk                            /*!<NC[1:0] bits (Number of column bits) */
#define FMC_SDCR1_NC_0             (0x1UL << FMC_SDCR1_NC_Pos)                  /*!< 0x00000001 */
#define FMC_SDCR1_NC_1             (0x2UL << FMC_SDCR1_NC_Pos)                  /*!< 0x00000002 */
#define FMC_SDCR1_NR_Pos           (2U)
#define FMC_SDCR1_NR_Msk           (0x3UL << FMC_SDCR1_NR_Pos)                  /*!< 0x0000000C */
#define FMC_SDCR1_NR               FMC_SDCR1_NR_Msk                            /*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR1_NR_0             (0x1UL << FMC_SDCR1_NR_Pos)                  /*!< 0x00000004 */
#define FMC_SDCR1_NR_1             (0x2UL << FMC_SDCR1_NR_Pos)                  /*!< 0x00000008 */
#define FMC_SDCR1_MWID_Pos         (4U)
#define FMC_SDCR1_MWID_Msk         (0x3UL << FMC_SDCR1_MWID_Pos)                /*!< 0x00000030 */
#define FMC_SDCR1_MWID             FMC_SDCR1_MWID_Msk                          /*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR1_MWID_0           (0x1UL << FMC_SDCR1_MWID_Pos)                /*!< 0x00000010 */
#define FMC_SDCR1_MWID_1           (0x2UL << FMC_SDCR1_MWID_Pos)                /*!< 0x00000020 */
#define FMC_SDCR1_NB_Pos           (6U)
#define FMC_SDCR1_NB_Msk           (0x1UL << FMC_SDCR1_NB_Pos)                  /*!< 0x00000040 */
#define FMC_SDCR1_NB               FMC_SDCR1_NB_Msk                            /*!<Number of internal bank */
#define FMC_SDCR1_CAS_Pos          (7U)
#define FMC_SDCR1_CAS_Msk          (0x3UL << FMC_SDCR1_CAS_Pos)                 /*!< 0x00000180 */
#define FMC_SDCR1_CAS              FMC_SDCR1_CAS_Msk                           /*!<CAS[1:0] bits (CAS latency) */
#define FMC_SDCR1_CAS_0            (0x1UL << FMC_SDCR1_CAS_Pos)                 /*!< 0x00000080 */
#define FMC_SDCR1_CAS_1            (0x2UL << FMC_SDCR1_CAS_Pos)                 /*!< 0x00000100 */
#define FMC_SDCR1_WP_Pos           (9U)
#define FMC_SDCR1_WP_Msk           (0x1UL << FMC_SDCR1_WP_Pos)                  /*!< 0x00000200 */
#define FMC_SDCR1_WP               FMC_SDCR1_WP_Msk                            /*!<Write protection */
#define FMC_SDCR1_SDCLK_Pos        (10U)
#define FMC_SDCR1_SDCLK_Msk        (0x3UL << FMC_SDCR1_SDCLK_Pos)               /*!< 0x00000C00 */
#define FMC_SDCR1_SDCLK            FMC_SDCR1_SDCLK_Msk                         /*!<SDRAM clock configuration */
#define FMC_SDCR1_SDCLK_0          (0x1UL << FMC_SDCR1_SDCLK_Pos)               /*!< 0x00000400 */
#define FMC_SDCR1_SDCLK_1          (0x2UL << FMC_SDCR1_SDCLK_Pos)               /*!< 0x00000800 */
#define FMC_SDCR1_RBURST_Pos       (12U)
#define FMC_SDCR1_RBURST_Msk       (0x1UL << FMC_SDCR1_RBURST_Pos)              /*!< 0x00001000 */
#define FMC_SDCR1_RBURST           FMC_SDCR1_RBURST_Msk                        /*!<Read burst */
#define FMC_SDCR1_RPIPE_Pos        (13U)
#define FMC_SDCR1_RPIPE_Msk        (0x3UL << FMC_SDCR1_RPIPE_Pos)               /*!< 0x00006000 */
#define FMC_SDCR1_RPIPE            FMC_SDCR1_RPIPE_Msk                         /*!<Write protection */
#define FMC_SDCR1_RPIPE_0          (0x1UL << FMC_SDCR1_RPIPE_Pos)               /*!< 0x00002000 */
#define FMC_SDCR1_RPIPE_1          (0x2UL << FMC_SDCR1_RPIPE_Pos)               /*!< 0x00004000 */

/******************  Bit definition for FMC_SDCR2 register  ******************/
#define FMC_SDCR2_NC_Pos           (0U)
#define FMC_SDCR2_NC_Msk           (0x3UL << FMC_SDCR2_NC_Pos)                  /*!< 0x00000003 */
#define FMC_SDCR2_NC               FMC_SDCR2_NC_Msk                            /*!<NC[1:0] bits (Number of column bits) */
#define FMC_SDCR2_NC_0             (0x1UL << FMC_SDCR2_NC_Pos)                  /*!< 0x00000001 */
#define FMC_SDCR2_NC_1             (0x2UL << FMC_SDCR2_NC_Pos)                  /*!< 0x00000002 */
#define FMC_SDCR2_NR_Pos           (2U)
#define FMC_SDCR2_NR_Msk           (0x3UL << FMC_SDCR2_NR_Pos)                  /*!< 0x0000000C */
#define FMC_SDCR2_NR               FMC_SDCR2_NR_Msk                            /*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR2_NR_0             (0x1UL << FMC_SDCR2_NR_Pos)                  /*!< 0x00000004 */
#define FMC_SDCR2_NR_1             (0x2UL << FMC_SDCR2_NR_Pos)                  /*!< 0x00000008 */
#define FMC_SDCR2_MWID_Pos         (4U)
#define FMC_SDCR2_MWID_Msk         (0x3UL << FMC_SDCR2_MWID_Pos)                /*!< 0x00000030 */
#define FMC_SDCR2_MWID             FMC_SDCR2_MWID_Msk                          /*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR2_MWID_0           (0x1UL << FMC_SDCR2_MWID_Pos)                /*!< 0x00000010 */
#define FMC_SDCR2_MWID_1           (0x2UL << FMC_SDCR2_MWID_Pos)                /*!< 0x00000020 */
#define FMC_SDCR2_NB_Pos           (6U)
#define FMC_SDCR2_NB_Msk           (0x1UL << FMC_SDCR2_NB_Pos)                  /*!< 0x00000040 */
#define FMC_SDCR2_NB               FMC_SDCR2_NB_Msk                            /*!<Number of internal bank */
#define FMC_SDCR2_CAS_Pos          (7U)
#define FMC_SDCR2_CAS_Msk          (0x3UL << FMC_SDCR2_CAS_Pos)                 /*!< 0x00000180 */
#define FMC_SDCR2_CAS              FMC_SDCR2_CAS_Msk                           /*!<CAS[1:0] bits (CAS latency) */
#define FMC_SDCR2_CAS_0            (0x1UL << FMC_SDCR2_CAS_Pos)                 /*!< 0x00000080 */
#define FMC_SDCR2_CAS_1            (0x2UL << FMC_SDCR2_CAS_Pos)                 /*!< 0x00000100 */
#define FMC_SDCR2_WP_Pos           (9U)
#define FMC_SDCR2_WP_Msk           (0x1UL << FMC_SDCR2_WP_Pos)                  /*!< 0x00000200 */
#define FMC_SDCR2_WP               FMC_SDCR2_WP_Msk                            /*!<Write protection */
#define FMC_SDCR2_SDCLK_Pos        (10U)
#define FMC_SDCR2_SDCLK_Msk        (0x3UL << FMC_SDCR2_SDCLK_Pos)               /*!< 0x00000C00 */
#define FMC_SDCR2_SDCLK            FMC_SDCR2_SDCLK_Msk                         /*!<SDCLK[1:0] (SDRAM clock configuration) */
#define FMC_SDCR2_SDCLK_0          (0x1UL << FMC_SDCR2_SDCLK_Pos)               /*!< 0x00000400 */
#define FMC_SDCR2_SDCLK_1          (0x2UL << FMC_SDCR2_SDCLK_Pos)               /*!< 0x00000800 */
#define FMC_SDCR2_RBURST_Pos       (12U)
#define FMC_SDCR2_RBURST_Msk       (0x1UL << FMC_SDCR2_RBURST_Pos)              /*!< 0x00001000 */
#define FMC_SDCR2_RBURST           FMC_SDCR2_RBURST_Msk                        /*!<Read burst */
#define FMC_SDCR2_RPIPE_Pos        (13U)
#define FMC_SDCR2_RPIPE_Msk        (0x3UL << FMC_SDCR2_RPIPE_Pos)               /*!< 0x00006000 */
#define FMC_SDCR2_RPIPE            FMC_SDCR2_RPIPE_Msk                         /*!<RPIPE[1:0](Read pipe) */
#define FMC_SDCR2_RPIPE_0          (0x1UL << FMC_SDCR2_RPIPE_Pos)               /*!< 0x00002000 */
#define FMC_SDCR2_RPIPE_1          (0x2UL << FMC_SDCR2_RPIPE_Pos)               /*!< 0x00004000 */

/******************  Bit definition for FMC_SDTR1 register  ******************/
#define FMC_SDTR1_TMRD_Pos         (0U)
#define FMC_SDTR1_TMRD_Msk         (0xFUL << FMC_SDTR1_TMRD_Pos)                /*!< 0x0000000F */
#define FMC_SDTR1_TMRD             FMC_SDTR1_TMRD_Msk                          /*!<TMRD[3:0] bits (Load mode register to active) */
#define FMC_SDTR1_TMRD_0           (0x1UL << FMC_SDTR1_TMRD_Pos)                /*!< 0x00000001 */
#define FMC_SDTR1_TMRD_1           (0x2UL << FMC_SDTR1_TMRD_Pos)                /*!< 0x00000002 */
#define FMC_SDTR1_TMRD_2           (0x4UL << FMC_SDTR1_TMRD_Pos)                /*!< 0x00000004 */
#define FMC_SDTR1_TMRD_3           (0x8UL << FMC_SDTR1_TMRD_Pos)                /*!< 0x00000008 */
#define FMC_SDTR1_TXSR_Pos         (4U)
#define FMC_SDTR1_TXSR_Msk         (0xFUL << FMC_SDTR1_TXSR_Pos)                /*!< 0x000000F0 */
#define FMC_SDTR1_TXSR             FMC_SDTR1_TXSR_Msk                          /*!<TXSR[3:0] bits (Exit self refresh) */
#define FMC_SDTR1_TXSR_0           (0x1UL << FMC_SDTR1_TXSR_Pos)                /*!< 0x00000010 */
#define FMC_SDTR1_TXSR_1           (0x2UL << FMC_SDTR1_TXSR_Pos)                /*!< 0x00000020 */
#define FMC_SDTR1_TXSR_2           (0x4UL << FMC_SDTR1_TXSR_Pos)                /*!< 0x00000040 */
#define FMC_SDTR1_TXSR_3           (0x8UL << FMC_SDTR1_TXSR_Pos)                /*!< 0x00000080 */
#define FMC_SDTR1_TRAS_Pos         (8U)
#define FMC_SDTR1_TRAS_Msk         (0xFUL << FMC_SDTR1_TRAS_Pos)                /*!< 0x00000F00 */
#define FMC_SDTR1_TRAS             FMC_SDTR1_TRAS_Msk                          /*!<TRAS[3:0] bits (Self refresh time) */
#define FMC_SDTR1_TRAS_0           (0x1UL << FMC_SDTR1_TRAS_Pos)                /*!< 0x00000100 */
#define FMC_SDTR1_TRAS_1           (0x2UL << FMC_SDTR1_TRAS_Pos)                /*!< 0x00000200 */
#define FMC_SDTR1_TRAS_2           (0x4UL << FMC_SDTR1_TRAS_Pos)                /*!< 0x00000400 */
#define FMC_SDTR1_TRAS_3           (0x8UL << FMC_SDTR1_TRAS_Pos)                /*!< 0x00000800 */
#define FMC_SDTR1_TRC_Pos          (12U)
#define FMC_SDTR1_TRC_Msk          (0xFUL << FMC_SDTR1_TRC_Pos)                 /*!< 0x0000F000 */
#define FMC_SDTR1_TRC              FMC_SDTR1_TRC_Msk                           /*!<TRC[2:0] bits (Row cycle delay) */
#define FMC_SDTR1_TRC_0            (0x1UL << FMC_SDTR1_TRC_Pos)                 /*!< 0x00001000 */
#define FMC_SDTR1_TRC_1            (0x2UL << FMC_SDTR1_TRC_Pos)                 /*!< 0x00002000 */
#define FMC_SDTR1_TRC_2            (0x4UL << FMC_SDTR1_TRC_Pos)                 /*!< 0x00004000 */
#define FMC_SDTR1_TWR_Pos          (16U)
#define FMC_SDTR1_TWR_Msk          (0xFUL << FMC_SDTR1_TWR_Pos)                 /*!< 0x000F0000 */
#define FMC_SDTR1_TWR              FMC_SDTR1_TWR_Msk                           /*!<TRC[2:0] bits (Write recovery delay) */
#define FMC_SDTR1_TWR_0            (0x1UL << FMC_SDTR1_TWR_Pos)                 /*!< 0x00010000 */
#define FMC_SDTR1_TWR_1            (0x2UL << FMC_SDTR1_TWR_Pos)                 /*!< 0x00020000 */
#define FMC_SDTR1_TWR_2            (0x4UL << FMC_SDTR1_TWR_Pos)                 /*!< 0x00040000 */
#define FMC_SDTR1_TRP_Pos          (20U)
#define FMC_SDTR1_TRP_Msk          (0xFUL << FMC_SDTR1_TRP_Pos)                 /*!< 0x00F00000 */
#define FMC_SDTR1_TRP              FMC_SDTR1_TRP_Msk                           /*!<TRP[2:0] bits (Row precharge delay) */
#define FMC_SDTR1_TRP_0            (0x1UL << FMC_SDTR1_TRP_Pos)                 /*!< 0x00100000 */
#define FMC_SDTR1_TRP_1            (0x2UL << FMC_SDTR1_TRP_Pos)                 /*!< 0x00200000 */
#define FMC_SDTR1_TRP_2            (0x4UL << FMC_SDTR1_TRP_Pos)                 /*!< 0x00400000 */
#define FMC_SDTR1_TRCD_Pos         (24U)
#define FMC_SDTR1_TRCD_Msk         (0xFUL << FMC_SDTR1_TRCD_Pos)                /*!< 0x0F000000 */
#define FMC_SDTR1_TRCD             FMC_SDTR1_TRCD_Msk                          /*!<TRP[2:0] bits (Row to column delay) */
#define FMC_SDTR1_TRCD_0           (0x1UL << FMC_SDTR1_TRCD_Pos)                /*!< 0x01000000 */
#define FMC_SDTR1_TRCD_1           (0x2UL << FMC_SDTR1_TRCD_Pos)                /*!< 0x02000000 */
#define FMC_SDTR1_TRCD_2           (0x4UL << FMC_SDTR1_TRCD_Pos)                /*!< 0x04000000 */

/******************  Bit definition for FMC_SDTR2 register  ******************/
#define FMC_SDTR2_TMRD_Pos         (0U)
#define FMC_SDTR2_TMRD_Msk         (0xFUL << FMC_SDTR2_TMRD_Pos)                /*!< 0x0000000F */
#define FMC_SDTR2_TMRD             FMC_SDTR2_TMRD_Msk                          /*!<TMRD[3:0] bits (Load mode register to active) */
#define FMC_SDTR2_TMRD_0           (0x1UL << FMC_SDTR2_TMRD_Pos)                /*!< 0x00000001 */
#define FMC_SDTR2_TMRD_1           (0x2UL << FMC_SDTR2_TMRD_Pos)                /*!< 0x00000002 */
#define FMC_SDTR2_TMRD_2           (0x4UL << FMC_SDTR2_TMRD_Pos)                /*!< 0x00000004 */
#define FMC_SDTR2_TMRD_3           (0x8UL << FMC_SDTR2_TMRD_Pos)                /*!< 0x00000008 */
#define FMC_SDTR2_TXSR_Pos         (4U)
#define FMC_SDTR2_TXSR_Msk         (0xFUL << FMC_SDTR2_TXSR_Pos)                /*!< 0x000000F0 */
#define FMC_SDTR2_TXSR             FMC_SDTR2_TXSR_Msk                          /*!<TXSR[3:0] bits (Exit self refresh) */
#define FMC_SDTR2_TXSR_0           (0x1UL << FMC_SDTR2_TXSR_Pos)                /*!< 0x00000010 */
#define FMC_SDTR2_TXSR_1           (0x2UL << FMC_SDTR2_TXSR_Pos)                /*!< 0x00000020 */
#define FMC_SDTR2_TXSR_2           (0x4UL << FMC_SDTR2_TXSR_Pos)                /*!< 0x00000040 */
#define FMC_SDTR2_TXSR_3           (0x8UL << FMC_SDTR2_TXSR_Pos)                /*!< 0x00000080 */
#define FMC_SDTR2_TRAS_Pos         (8U)
#define FMC_SDTR2_TRAS_Msk         (0xFUL << FMC_SDTR2_TRAS_Pos)                /*!< 0x00000F00 */
#define FMC_SDTR2_TRAS             FMC_SDTR2_TRAS_Msk                          /*!<TRAS[3:0] bits (Self refresh time) */
#define FMC_SDTR2_TRAS_0           (0x1UL << FMC_SDTR2_TRAS_Pos)                /*!< 0x00000100 */
#define FMC_SDTR2_TRAS_1           (0x2UL << FMC_SDTR2_TRAS_Pos)                /*!< 0x00000200 */
#define FMC_SDTR2_TRAS_2           (0x4UL << FMC_SDTR2_TRAS_Pos)                /*!< 0x00000400 */
#define FMC_SDTR2_TRAS_3           (0x8UL << FMC_SDTR2_TRAS_Pos)                /*!< 0x00000800 */
#define FMC_SDTR2_TRC_Pos          (12U)
#define FMC_SDTR2_TRC_Msk          (0xFUL << FMC_SDTR2_TRC_Pos)                 /*!< 0x0000F000 */
#define FMC_SDTR2_TRC              FMC_SDTR2_TRC_Msk                           /*!<TRC[2:0] bits (Row cycle delay) */
#define FMC_SDTR2_TRC_0            (0x1UL << FMC_SDTR2_TRC_Pos)                 /*!< 0x00001000 */
#define FMC_SDTR2_TRC_1            (0x2UL << FMC_SDTR2_TRC_Pos)                 /*!< 0x00002000 */
#define FMC_SDTR2_TRC_2            (0x4UL << FMC_SDTR2_TRC_Pos)                 /*!< 0x00004000 */
#define FMC_SDTR2_TWR_Pos          (16U)
#define FMC_SDTR2_TWR_Msk          (0xFUL << FMC_SDTR2_TWR_Pos)                 /*!< 0x000F0000 */
#define FMC_SDTR2_TWR              FMC_SDTR2_TWR_Msk                           /*!<TRC[2:0] bits (Write recovery delay) */
#define FMC_SDTR2_TWR_0            (0x1UL << FMC_SDTR2_TWR_Pos)                 /*!< 0x00010000 */
#define FMC_SDTR2_TWR_1            (0x2UL << FMC_SDTR2_TWR_Pos)                 /*!< 0x00020000 */
#define FMC_SDTR2_TWR_2            (0x4UL << FMC_SDTR2_TWR_Pos)                 /*!< 0x00040000 */
#define FMC_SDTR2_TRP_Pos          (20U)
#define FMC_SDTR2_TRP_Msk          (0xFUL << FMC_SDTR2_TRP_Pos)                 /*!< 0x00F00000 */
#define FMC_SDTR2_TRP              FMC_SDTR2_TRP_Msk                           /*!<TRP[2:0] bits (Row precharge delay) */
#define FMC_SDTR2_TRP_0            (0x1UL << FMC_SDTR2_TRP_Pos)                 /*!< 0x00100000 */
#define FMC_SDTR2_TRP_1            (0x2UL << FMC_SDTR2_TRP_Pos)                 /*!< 0x00200000 */
#define FMC_SDTR2_TRP_2            (0x4UL << FMC_SDTR2_TRP_Pos)                 /*!< 0x00400000 */
#define FMC_SDTR2_TRCD_Pos         (24U)
#define FMC_SDTR2_TRCD_Msk         (0xFUL << FMC_SDTR2_TRCD_Pos)                /*!< 0x0F000000 */
#define FMC_SDTR2_TRCD             FMC_SDTR2_TRCD_Msk                          /*!<TRP[2:0] bits (Row to column delay) */
#define FMC_SDTR2_TRCD_0           (0x1UL << FMC_SDTR2_TRCD_Pos)                /*!< 0x01000000 */
#define FMC_SDTR2_TRCD_1           (0x2UL << FMC_SDTR2_TRCD_Pos)                /*!< 0x02000000 */
#define FMC_SDTR2_TRCD_2           (0x4UL << FMC_SDTR2_TRCD_Pos)                /*!< 0x04000000 */

/******************  Bit definition for FMC_SDCMR register  ******************/
#define FMC_SDCMR_MODE_Pos         (0U)
#define FMC_SDCMR_MODE_Msk         (0x7UL << FMC_SDCMR_MODE_Pos)                /*!< 0x00000007 */
#define FMC_SDCMR_MODE             FMC_SDCMR_MODE_Msk                          /*!<MODE[2:0] bits (Command mode) */
#define FMC_SDCMR_MODE_0           (0x1UL << FMC_SDCMR_MODE_Pos)                /*!< 0x00000001 */
#define FMC_SDCMR_MODE_1           (0x2UL << FMC_SDCMR_MODE_Pos)                /*!< 0x00000002 */
#define FMC_SDCMR_MODE_2           (0x4UL << FMC_SDCMR_MODE_Pos)                /*!< 0x00000004 */
#define FMC_SDCMR_CTB2_Pos         (3U)
#define FMC_SDCMR_CTB2_Msk         (0x1UL << FMC_SDCMR_CTB2_Pos)                /*!< 0x00000008 */
#define FMC_SDCMR_CTB2             FMC_SDCMR_CTB2_Msk                          /*!<Command target 2 */
#define FMC_SDCMR_CTB1_Pos         (4U)
#define FMC_SDCMR_CTB1_Msk         (0x1UL << FMC_SDCMR_CTB1_Pos)                /*!< 0x00000010 */
#define FMC_SDCMR_CTB1             FMC_SDCMR_CTB1_Msk                          /*!<Command target 1 */
#define FMC_SDCMR_NRFS_Pos         (5U)
#define FMC_SDCMR_NRFS_Msk         (0xFUL << FMC_SDCMR_NRFS_Pos)                /*!< 0x000001E0 */
#define FMC_SDCMR_NRFS             FMC_SDCMR_NRFS_Msk                          /*!<NRFS[3:0] bits (Number of auto-refresh) */
#define FMC_SDCMR_NRFS_0           (0x1UL << FMC_SDCMR_NRFS_Pos)                /*!< 0x00000020 */
#define FMC_SDCMR_NRFS_1           (0x2UL << FMC_SDCMR_NRFS_Pos)                /*!< 0x00000040 */
#define FMC_SDCMR_NRFS_2           (0x4UL << FMC_SDCMR_NRFS_Pos)                /*!< 0x00000080 */
#define FMC_SDCMR_NRFS_3           (0x8UL << FMC_SDCMR_NRFS_Pos)                /*!< 0x00000100 */
#define FMC_SDCMR_MRD_Pos          (9U)
#define FMC_SDCMR_MRD_Msk          (0x1FFFUL << FMC_SDCMR_MRD_Pos)              /*!< 0x003FFE00 */
#define FMC_SDCMR_MRD              FMC_SDCMR_MRD_Msk                           /*!<MRD[12:0] bits (Mode register definition) */

/******************  Bit definition for FMC_SDRTR register  ******************/
#define FMC_SDRTR_CRE_Pos          (0U)
#define FMC_SDRTR_CRE_Msk          (0x1UL << FMC_SDRTR_CRE_Pos)                 /*!< 0x00000001 */
#define FMC_SDRTR_CRE              FMC_SDRTR_CRE_Msk                           /*!<Clear refresh error flag */
#define FMC_SDRTR_COUNT_Pos        (1U)
#define FMC_SDRTR_COUNT_Msk        (0x1FFFUL << FMC_SDRTR_COUNT_Pos)            /*!< 0x00003FFE */
#define FMC_SDRTR_COUNT            FMC_SDRTR_COUNT_Msk                         /*!<COUNT[12:0] bits (Refresh timer count) */
#define FMC_SDRTR_REIE_Pos         (14U)
#define FMC_SDRTR_REIE_Msk         (0x1UL << FMC_SDRTR_REIE_Pos)                /*!< 0x00004000 */
#define FMC_SDRTR_REIE             FMC_SDRTR_REIE_Msk                          /*!<RES interupt enable */

/******************  Bit definition for FMC_SDSR register  ******************/
#define FMC_SDSR_RE_Pos            (0U)
#define FMC_SDSR_RE_Msk            (0x1UL << FMC_SDSR_RE_Pos)                   /*!< 0x00000001 */
#define FMC_SDSR_RE                FMC_SDSR_RE_Msk                             /*!<Refresh error flag */
#define FMC_SDSR_MODES1_Pos        (1U)
#define FMC_SDSR_MODES1_Msk        (0x3UL << FMC_SDSR_MODES1_Pos)               /*!< 0x00000006 */
#define FMC_SDSR_MODES1            FMC_SDSR_MODES1_Msk                         /*!<MODES1[1:0]bits (Status mode for bank 1) */
#define FMC_SDSR_MODES1_0          (0x1UL << FMC_SDSR_MODES1_Pos)               /*!< 0x00000002 */
#define FMC_SDSR_MODES1_1          (0x2UL << FMC_SDSR_MODES1_Pos)               /*!< 0x00000004 */
#define FMC_SDSR_MODES2_Pos        (3U)
#define FMC_SDSR_MODES2_Msk        (0x3UL << FMC_SDSR_MODES2_Pos)               /*!< 0x00000018 */
#define FMC_SDSR_MODES2            FMC_SDSR_MODES2_Msk                         /*!<MODES2[1:0]bits (Status mode for bank 2) */
#define FMC_SDSR_MODES2_0          (0x1UL << FMC_SDSR_MODES2_Pos)               /*!< 0x00000008 */
#define FMC_SDSR_MODES2_1          (0x2UL << FMC_SDSR_MODES2_Pos)               /*!< 0x00000010 */
#define FMC_SDSR_BUSY_Pos          (5U)
#define FMC_SDSR_BUSY_Msk          (0x1UL << FMC_SDSR_BUSY_Pos)                 /*!< 0x00000020 */
#define FMC_SDSR_BUSY              FMC_SDSR_BUSY_Msk                           /*!<Busy status */

// 레지스터 목록
namespace SDRAM_REG
{
enum
{
//	SDCR0 = 80, SDCR1, SDTR0, SDTR1, SDCMR, SDRTR, SDSR
	SDCR0 = 0, SDCR1, SDTR0, SDTR1, SDCMR, SDRTR, SDSR
};
}

#endif

