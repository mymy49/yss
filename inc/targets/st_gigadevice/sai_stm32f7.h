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
#ifndef __SAI_STM32F7__H_
#define __SAI_STM32F7__H_

/******************************************************************************/
/*                                                                            */
/*                          Serial Audio Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SAI_GCR register  *******************/
#define SAI_GCR_SYNCIN_Pos         (0U)
#define SAI_GCR_SYNCIN_Msk         (0x3UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000003 */
#define SAI_GCR_SYNCIN             SAI_GCR_SYNCIN_Msk                          /*!<SYNCIN[1:0] bits (Synchronization Inputs)   */
#define SAI_GCR_SYNCIN_0           (0x1UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000001 */
#define SAI_GCR_SYNCIN_1           (0x2UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000002 */

#define SAI_GCR_SYNCOUT_Pos        (4U)
#define SAI_GCR_SYNCOUT_Msk        (0x3UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000030 */
#define SAI_GCR_SYNCOUT            SAI_GCR_SYNCOUT_Msk                         /*!<SYNCOUT[1:0] bits (Synchronization Outputs) */
#define SAI_GCR_SYNCOUT_0          (0x1UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000010 */
#define SAI_GCR_SYNCOUT_1          (0x2UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000020 */

/*******************  Bit definition for SAI_xCR1 register  *******************/
#define SAI_xCR1_MODE_Pos          (0U)
#define SAI_xCR1_MODE_Msk          (0x3UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000003 */
#define SAI_xCR1_MODE              SAI_xCR1_MODE_Msk                           /*!<MODE[1:0] bits (Audio Block Mode)           */
#define SAI_xCR1_MODE_0            (0x1UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000001 */
#define SAI_xCR1_MODE_1            (0x2UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000002 */

#define SAI_xCR1_PRTCFG_Pos        (2U)
#define SAI_xCR1_PRTCFG_Msk        (0x3UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x0000000C */
#define SAI_xCR1_PRTCFG            SAI_xCR1_PRTCFG_Msk                         /*!<PRTCFG[1:0] bits (Protocol Configuration)   */
#define SAI_xCR1_PRTCFG_0          (0x1UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x00000004 */
#define SAI_xCR1_PRTCFG_1          (0x2UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x00000008 */

#define SAI_xCR1_DS_Pos            (5U)
#define SAI_xCR1_DS_Msk            (0x7UL << SAI_xCR1_DS_Pos)                   /*!< 0x000000E0 */
#define SAI_xCR1_DS                SAI_xCR1_DS_Msk                             /*!<DS[1:0] bits (Data Size) */
#define SAI_xCR1_DS_0              (0x1UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000020 */
#define SAI_xCR1_DS_1              (0x2UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000040 */
#define SAI_xCR1_DS_2              (0x4UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000080 */

#define SAI_xCR1_LSBFIRST_Pos      (8U)
#define SAI_xCR1_LSBFIRST_Msk      (0x1UL << SAI_xCR1_LSBFIRST_Pos)             /*!< 0x00000100 */
#define SAI_xCR1_LSBFIRST          SAI_xCR1_LSBFIRST_Msk                       /*!<LSB First Configuration  */
#define SAI_xCR1_CKSTR_Pos         (9U)
#define SAI_xCR1_CKSTR_Msk         (0x1UL << SAI_xCR1_CKSTR_Pos)                /*!< 0x00000200 */
#define SAI_xCR1_CKSTR             SAI_xCR1_CKSTR_Msk                          /*!<ClocK STRobing edge      */

#define SAI_xCR1_SYNCEN_Pos        (10U)
#define SAI_xCR1_SYNCEN_Msk        (0x3UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000C00 */
#define SAI_xCR1_SYNCEN            SAI_xCR1_SYNCEN_Msk                         /*!<SYNCEN[1:0](SYNChronization ENable) */
#define SAI_xCR1_SYNCEN_0          (0x1UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000400 */
#define SAI_xCR1_SYNCEN_1          (0x2UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000800 */

#define SAI_xCR1_MONO_Pos          (12U)
#define SAI_xCR1_MONO_Msk          (0x1UL << SAI_xCR1_MONO_Pos)                 /*!< 0x00001000 */
#define SAI_xCR1_MONO              SAI_xCR1_MONO_Msk                           /*!<Mono mode                  */
#define SAI_xCR1_OUTDRIV_Pos       (13U)
#define SAI_xCR1_OUTDRIV_Msk       (0x1UL << SAI_xCR1_OUTDRIV_Pos)              /*!< 0x00002000 */
#define SAI_xCR1_OUTDRIV           SAI_xCR1_OUTDRIV_Msk                        /*!<Output Drive               */
#define SAI_xCR1_SAIEN_Pos         (16U)
#define SAI_xCR1_SAIEN_Msk         (0x1UL << SAI_xCR1_SAIEN_Pos)                /*!< 0x00010000 */
#define SAI_xCR1_SAIEN             SAI_xCR1_SAIEN_Msk                          /*!<Audio Block enable         */
#define SAI_xCR1_DMAEN_Pos         (17U)
#define SAI_xCR1_DMAEN_Msk         (0x1UL << SAI_xCR1_DMAEN_Pos)                /*!< 0x00020000 */
#define SAI_xCR1_DMAEN             SAI_xCR1_DMAEN_Msk                          /*!<DMA enable                 */
#define SAI_xCR1_NODIV_Pos         (19U)
#define SAI_xCR1_NODIV_Msk         (0x1UL << SAI_xCR1_NODIV_Pos)                /*!< 0x00080000 */
#define SAI_xCR1_NODIV             SAI_xCR1_NODIV_Msk                          /*!<No Divider Configuration   */

#define SAI_xCR1_MCKDIV_Pos        (20U)
#define SAI_xCR1_MCKDIV_Msk        (0xFUL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00F00000 */
#define SAI_xCR1_MCKDIV            SAI_xCR1_MCKDIV_Msk                         /*!<MCKDIV[3:0] (Master ClocK Divider)  */
#define SAI_xCR1_MCKDIV_0          (0x1UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00100000 */
#define SAI_xCR1_MCKDIV_1          (0x2UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00200000 */
#define SAI_xCR1_MCKDIV_2          (0x4UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00400000 */
#define SAI_xCR1_MCKDIV_3          (0x8UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00800000 */

/*******************  Bit definition for SAI_xCR2 register  *******************/
#define SAI_xCR2_FTH_Pos           (0U)
#define SAI_xCR2_FTH_Msk           (0x7UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000007 */
#define SAI_xCR2_FTH               SAI_xCR2_FTH_Msk                            /*!<FTH[2:0](Fifo THreshold)  */
#define SAI_xCR2_FTH_0             (0x1UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000001 */
#define SAI_xCR2_FTH_1             (0x2UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000002 */
#define SAI_xCR2_FTH_2             (0x4UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000004 */

#define SAI_xCR2_FFLUSH_Pos        (3U)
#define SAI_xCR2_FFLUSH_Msk        (0x1UL << SAI_xCR2_FFLUSH_Pos)               /*!< 0x00000008 */
#define SAI_xCR2_FFLUSH            SAI_xCR2_FFLUSH_Msk                         /*!<Fifo FLUSH                       */
#define SAI_xCR2_TRIS_Pos          (4U)
#define SAI_xCR2_TRIS_Msk          (0x1UL << SAI_xCR2_TRIS_Pos)                 /*!< 0x00000010 */
#define SAI_xCR2_TRIS              SAI_xCR2_TRIS_Msk                           /*!<TRIState Management on data line */
#define SAI_xCR2_MUTE_Pos          (5U)
#define SAI_xCR2_MUTE_Msk          (0x1UL << SAI_xCR2_MUTE_Pos)                 /*!< 0x00000020 */
#define SAI_xCR2_MUTE              SAI_xCR2_MUTE_Msk                           /*!<Mute mode                        */
#define SAI_xCR2_MUTEVAL_Pos       (6U)
#define SAI_xCR2_MUTEVAL_Msk       (0x1UL << SAI_xCR2_MUTEVAL_Pos)              /*!< 0x00000040 */
#define SAI_xCR2_MUTEVAL           SAI_xCR2_MUTEVAL_Msk                        /*!<Muate value                      */

#define SAI_xCR2_MUTECNT_Pos       (7U)
#define SAI_xCR2_MUTECNT_Msk       (0x3FUL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00001F80 */
#define SAI_xCR2_MUTECNT           SAI_xCR2_MUTECNT_Msk                        /*!<MUTECNT[5:0] (MUTE counter) */
#define SAI_xCR2_MUTECNT_0         (0x01UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000080 */
#define SAI_xCR2_MUTECNT_1         (0x02UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000100 */
#define SAI_xCR2_MUTECNT_2         (0x04UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000200 */
#define SAI_xCR2_MUTECNT_3         (0x08UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000400 */
#define SAI_xCR2_MUTECNT_4         (0x10UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000800 */
#define SAI_xCR2_MUTECNT_5         (0x20UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00001000 */

#define SAI_xCR2_CPL_Pos           (13U)
#define SAI_xCR2_CPL_Msk           (0x1UL << SAI_xCR2_CPL_Pos)                  /*!< 0x00002000 */
#define SAI_xCR2_CPL               SAI_xCR2_CPL_Msk                            /*!< Complement Bit             */

#define SAI_xCR2_COMP_Pos          (14U)
#define SAI_xCR2_COMP_Msk          (0x3UL << SAI_xCR2_COMP_Pos)                 /*!< 0x0000C000 */
#define SAI_xCR2_COMP              SAI_xCR2_COMP_Msk                           /*!<COMP[1:0] (Companding mode) */
#define SAI_xCR2_COMP_0            (0x1UL << SAI_xCR2_COMP_Pos)                 /*!< 0x00004000 */
#define SAI_xCR2_COMP_1            (0x2UL << SAI_xCR2_COMP_Pos)                 /*!< 0x00008000 */

/******************  Bit definition for SAI_xFRCR register  *******************/
#define SAI_xFRCR_FRL_Pos          (0U)
#define SAI_xFRCR_FRL_Msk          (0xFFUL << SAI_xFRCR_FRL_Pos)                /*!< 0x000000FF */
#define SAI_xFRCR_FRL              SAI_xFRCR_FRL_Msk                           /*!<FRL[7:0](Frame length)  */
#define SAI_xFRCR_FRL_0            (0x01UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000001 */
#define SAI_xFRCR_FRL_1            (0x02UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000002 */
#define SAI_xFRCR_FRL_2            (0x04UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000004 */
#define SAI_xFRCR_FRL_3            (0x08UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000008 */
#define SAI_xFRCR_FRL_4            (0x10UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000010 */
#define SAI_xFRCR_FRL_5            (0x20UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000020 */
#define SAI_xFRCR_FRL_6            (0x40UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000040 */
#define SAI_xFRCR_FRL_7            (0x80UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000080 */

#define SAI_xFRCR_FSALL_Pos        (8U)
#define SAI_xFRCR_FSALL_Msk        (0x7FUL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00007F00 */
#define SAI_xFRCR_FSALL            SAI_xFRCR_FSALL_Msk                         /*!<FRL[6:0] (Frame synchronization active level length)  */
#define SAI_xFRCR_FSALL_0          (0x01UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000100 */
#define SAI_xFRCR_FSALL_1          (0x02UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000200 */
#define SAI_xFRCR_FSALL_2          (0x04UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000400 */
#define SAI_xFRCR_FSALL_3          (0x08UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000800 */
#define SAI_xFRCR_FSALL_4          (0x10UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00001000 */
#define SAI_xFRCR_FSALL_5          (0x20UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00002000 */
#define SAI_xFRCR_FSALL_6          (0x40UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00004000 */

#define SAI_xFRCR_FSDEF_Pos        (16U)
#define SAI_xFRCR_FSDEF_Msk        (0x1UL << SAI_xFRCR_FSDEF_Pos)               /*!< 0x00010000 */
#define SAI_xFRCR_FSDEF            SAI_xFRCR_FSDEF_Msk                         /*!<Frame Synchronization Definition  */
#define SAI_xFRCR_FSPOL_Pos        (17U)
#define SAI_xFRCR_FSPOL_Msk        (0x1UL << SAI_xFRCR_FSPOL_Pos)               /*!< 0x00020000 */
#define SAI_xFRCR_FSPOL            SAI_xFRCR_FSPOL_Msk                         /*!<Frame Synchronization POLarity    */
#define SAI_xFRCR_FSOFF_Pos        (18U)
#define SAI_xFRCR_FSOFF_Msk        (0x1UL << SAI_xFRCR_FSOFF_Pos)               /*!< 0x00040000 */
#define SAI_xFRCR_FSOFF            SAI_xFRCR_FSOFF_Msk                         /*!<Frame Synchronization OFFset      */

/* Legacy define */
#define  SAI_xFRCR_FSPO                      SAI_xFRCR_FSPOL

/******************  Bit definition for SAI_xSLOTR register  *******************/
#define SAI_xSLOTR_FBOFF_Pos       (0U)
#define SAI_xSLOTR_FBOFF_Msk       (0x1FUL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x0000001F */
#define SAI_xSLOTR_FBOFF           SAI_xSLOTR_FBOFF_Msk                        /*!<FRL[4:0](First Bit Offset)  */
#define SAI_xSLOTR_FBOFF_0         (0x01UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000001 */
#define SAI_xSLOTR_FBOFF_1         (0x02UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000002 */
#define SAI_xSLOTR_FBOFF_2         (0x04UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000004 */
#define SAI_xSLOTR_FBOFF_3         (0x08UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000008 */
#define SAI_xSLOTR_FBOFF_4         (0x10UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000010 */

#define SAI_xSLOTR_SLOTSZ_Pos      (6U)
#define SAI_xSLOTR_SLOTSZ_Msk      (0x3UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x000000C0 */
#define SAI_xSLOTR_SLOTSZ          SAI_xSLOTR_SLOTSZ_Msk                       /*!<SLOTSZ[1:0] (Slot size)  */
#define SAI_xSLOTR_SLOTSZ_0        (0x1UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x00000040 */
#define SAI_xSLOTR_SLOTSZ_1        (0x2UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x00000080 */

#define SAI_xSLOTR_NBSLOT_Pos      (8U)
#define SAI_xSLOTR_NBSLOT_Msk      (0xFUL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000F00 */
#define SAI_xSLOTR_NBSLOT          SAI_xSLOTR_NBSLOT_Msk                       /*!<NBSLOT[3:0] (Number of Slot in audio Frame)  */
#define SAI_xSLOTR_NBSLOT_0        (0x1UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000100 */
#define SAI_xSLOTR_NBSLOT_1        (0x2UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000200 */
#define SAI_xSLOTR_NBSLOT_2        (0x4UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000400 */
#define SAI_xSLOTR_NBSLOT_3        (0x8UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000800 */

#define SAI_xSLOTR_SLOTEN_Pos      (16U)
#define SAI_xSLOTR_SLOTEN_Msk      (0xFFFFUL << SAI_xSLOTR_SLOTEN_Pos)          /*!< 0xFFFF0000 */
#define SAI_xSLOTR_SLOTEN          SAI_xSLOTR_SLOTEN_Msk                       /*!<SLOTEN[15:0] (Slot Enable)  */

/*******************  Bit definition for SAI_xIMR register  *******************/
#define SAI_xIMR_OVRUDRIE_Pos      (0U)
#define SAI_xIMR_OVRUDRIE_Msk      (0x1UL << SAI_xIMR_OVRUDRIE_Pos)             /*!< 0x00000001 */
#define SAI_xIMR_OVRUDRIE          SAI_xIMR_OVRUDRIE_Msk                       /*!<Overrun underrun interrupt enable                              */
#define SAI_xIMR_MUTEDETIE_Pos     (1U)
#define SAI_xIMR_MUTEDETIE_Msk     (0x1UL << SAI_xIMR_MUTEDETIE_Pos)            /*!< 0x00000002 */
#define SAI_xIMR_MUTEDETIE         SAI_xIMR_MUTEDETIE_Msk                      /*!<Mute detection interrupt enable                                */
#define SAI_xIMR_WCKCFGIE_Pos      (2U)
#define SAI_xIMR_WCKCFGIE_Msk      (0x1UL << SAI_xIMR_WCKCFGIE_Pos)             /*!< 0x00000004 */
#define SAI_xIMR_WCKCFGIE          SAI_xIMR_WCKCFGIE_Msk                       /*!<Wrong Clock Configuration interrupt enable                     */
#define SAI_xIMR_FREQIE_Pos        (3U)
#define SAI_xIMR_FREQIE_Msk        (0x1UL << SAI_xIMR_FREQIE_Pos)               /*!< 0x00000008 */
#define SAI_xIMR_FREQIE            SAI_xIMR_FREQIE_Msk                         /*!<FIFO request interrupt enable                                  */
#define SAI_xIMR_CNRDYIE_Pos       (4U)
#define SAI_xIMR_CNRDYIE_Msk       (0x1UL << SAI_xIMR_CNRDYIE_Pos)              /*!< 0x00000010 */
#define SAI_xIMR_CNRDYIE           SAI_xIMR_CNRDYIE_Msk                        /*!<Codec not ready interrupt enable                               */
#define SAI_xIMR_AFSDETIE_Pos      (5U)
#define SAI_xIMR_AFSDETIE_Msk      (0x1UL << SAI_xIMR_AFSDETIE_Pos)             /*!< 0x00000020 */
#define SAI_xIMR_AFSDETIE          SAI_xIMR_AFSDETIE_Msk                       /*!<Anticipated frame synchronization detection interrupt enable   */
#define SAI_xIMR_LFSDETIE_Pos      (6U)
#define SAI_xIMR_LFSDETIE_Msk      (0x1UL << SAI_xIMR_LFSDETIE_Pos)             /*!< 0x00000040 */
#define SAI_xIMR_LFSDETIE          SAI_xIMR_LFSDETIE_Msk                       /*!<Late frame synchronization detection interrupt enable          */

/********************  Bit definition for SAI_xSR register  *******************/
#define SAI_xSR_OVRUDR_Pos         (0U)
#define SAI_xSR_OVRUDR_Msk         (0x1UL << SAI_xSR_OVRUDR_Pos)                /*!< 0x00000001 */
#define SAI_xSR_OVRUDR             SAI_xSR_OVRUDR_Msk                          /*!<Overrun underrun                               */
#define SAI_xSR_MUTEDET_Pos        (1U)
#define SAI_xSR_MUTEDET_Msk        (0x1UL << SAI_xSR_MUTEDET_Pos)               /*!< 0x00000002 */
#define SAI_xSR_MUTEDET            SAI_xSR_MUTEDET_Msk                         /*!<Mute detection                                 */
#define SAI_xSR_WCKCFG_Pos         (2U)
#define SAI_xSR_WCKCFG_Msk         (0x1UL << SAI_xSR_WCKCFG_Pos)                /*!< 0x00000004 */
#define SAI_xSR_WCKCFG             SAI_xSR_WCKCFG_Msk                          /*!<Wrong Clock Configuration                      */
#define SAI_xSR_FREQ_Pos           (3U)
#define SAI_xSR_FREQ_Msk           (0x1UL << SAI_xSR_FREQ_Pos)                  /*!< 0x00000008 */
#define SAI_xSR_FREQ               SAI_xSR_FREQ_Msk                            /*!<FIFO request                                   */
#define SAI_xSR_CNRDY_Pos          (4U)
#define SAI_xSR_CNRDY_Msk          (0x1UL << SAI_xSR_CNRDY_Pos)                 /*!< 0x00000010 */
#define SAI_xSR_CNRDY              SAI_xSR_CNRDY_Msk                           /*!<Codec not ready                                */
#define SAI_xSR_AFSDET_Pos         (5U)
#define SAI_xSR_AFSDET_Msk         (0x1UL << SAI_xSR_AFSDET_Pos)                /*!< 0x00000020 */
#define SAI_xSR_AFSDET             SAI_xSR_AFSDET_Msk                          /*!<Anticipated frame synchronization detection    */
#define SAI_xSR_LFSDET_Pos         (6U)
#define SAI_xSR_LFSDET_Msk         (0x1UL << SAI_xSR_LFSDET_Pos)                /*!< 0x00000040 */
#define SAI_xSR_LFSDET             SAI_xSR_LFSDET_Msk                          /*!<Late frame synchronization detection           */

#define SAI_xSR_FLVL_Pos           (16U)
#define SAI_xSR_FLVL_Msk           (0x7UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00070000 */
#define SAI_xSR_FLVL               SAI_xSR_FLVL_Msk                            /*!<FLVL[2:0] (FIFO Level Threshold)               */
#define SAI_xSR_FLVL_0             (0x1UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00010000 */
#define SAI_xSR_FLVL_1             (0x2UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00020000 */
#define SAI_xSR_FLVL_2             (0x4UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00040000 */

/******************  Bit definition for SAI_xCLRFR register  ******************/
#define SAI_xCLRFR_COVRUDR_Pos     (0U)
#define SAI_xCLRFR_COVRUDR_Msk     (0x1UL << SAI_xCLRFR_COVRUDR_Pos)            /*!< 0x00000001 */
#define SAI_xCLRFR_COVRUDR         SAI_xCLRFR_COVRUDR_Msk                      /*!<Clear Overrun underrun                               */
#define SAI_xCLRFR_CMUTEDET_Pos    (1U)
#define SAI_xCLRFR_CMUTEDET_Msk    (0x1UL << SAI_xCLRFR_CMUTEDET_Pos)           /*!< 0x00000002 */
#define SAI_xCLRFR_CMUTEDET        SAI_xCLRFR_CMUTEDET_Msk                     /*!<Clear Mute detection                                 */
#define SAI_xCLRFR_CWCKCFG_Pos     (2U)
#define SAI_xCLRFR_CWCKCFG_Msk     (0x1UL << SAI_xCLRFR_CWCKCFG_Pos)            /*!< 0x00000004 */
#define SAI_xCLRFR_CWCKCFG         SAI_xCLRFR_CWCKCFG_Msk                      /*!<Clear Wrong Clock Configuration                      */
#define SAI_xCLRFR_CFREQ_Pos       (3U)
#define SAI_xCLRFR_CFREQ_Msk       (0x1UL << SAI_xCLRFR_CFREQ_Pos)              /*!< 0x00000008 */
#define SAI_xCLRFR_CFREQ           SAI_xCLRFR_CFREQ_Msk                        /*!<Clear FIFO request                                   */
#define SAI_xCLRFR_CCNRDY_Pos      (4U)
#define SAI_xCLRFR_CCNRDY_Msk      (0x1UL << SAI_xCLRFR_CCNRDY_Pos)             /*!< 0x00000010 */
#define SAI_xCLRFR_CCNRDY          SAI_xCLRFR_CCNRDY_Msk                       /*!<Clear Codec not ready                                */
#define SAI_xCLRFR_CAFSDET_Pos     (5U)
#define SAI_xCLRFR_CAFSDET_Msk     (0x1UL << SAI_xCLRFR_CAFSDET_Pos)            /*!< 0x00000020 */
#define SAI_xCLRFR_CAFSDET         SAI_xCLRFR_CAFSDET_Msk                      /*!<Clear Anticipated frame synchronization detection    */
#define SAI_xCLRFR_CLFSDET_Pos     (6U)
#define SAI_xCLRFR_CLFSDET_Msk     (0x1UL << SAI_xCLRFR_CLFSDET_Pos)            /*!< 0x00000040 */
#define SAI_xCLRFR_CLFSDET         SAI_xCLRFR_CLFSDET_Msk                      /*!<Clear Late frame synchronization detection           */

/******************  Bit definition for SAI_xDR register  *********************/
#define SAI_xDR_DATA_Pos           (0U)
#define SAI_xDR_DATA_Msk           (0xFFFFFFFFUL << SAI_xDR_DATA_Pos)           /*!< 0xFFFFFFFF */
#define SAI_xDR_DATA               SAI_xDR_DATA_Msk

typedef struct
{
  __IO uint32_t GCR;      /*!< SAI global configuration register,        Address offset: 0x00 */
} SAI_TypeDef;

typedef struct
{
  __IO uint32_t CR1;      /*!< SAI block x configuration register 1,     Address offset: 0x04 */
  __IO uint32_t CR2;      /*!< SAI block x configuration register 2,     Address offset: 0x08 */
  __IO uint32_t FRCR;     /*!< SAI block x frame configuration register, Address offset: 0x0C */
  __IO uint32_t SLOTR;    /*!< SAI block x slot register,                Address offset: 0x10 */
  __IO uint32_t IMR;      /*!< SAI block x interrupt mask register,      Address offset: 0x14 */
  __IO uint32_t SR;       /*!< SAI block x status register,              Address offset: 0x18 */
  __IO uint32_t CLRFR;    /*!< SAI block x clear flag register,          Address offset: 0x1C */
  __IO uint32_t DR;       /*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;

// 레지스터 목록
enum SAI_REG
{
	GCR = 0
};

enum SAI_BLOCK_REG
{
	CR1 = 0,		CR2,			FRCR,			SLOTR,			IMR,
	SR,				CLRFR,			DR
};

#endif

