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
#ifndef __SDMMC_STM32_GD32F1_F4__H_
#define __SDMMC_STM32_GD32F1_F4__H_

/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for SDIO_POWER register  ******************/
#define SDIO_POWER_PWRCTRL_Pos              (0U)                               
#define SDIO_POWER_PWRCTRL_Msk              (0x3UL << SDIO_POWER_PWRCTRL_Pos)   /*!< 0x00000003 */
#define SDIO_POWER_PWRCTRL                  SDIO_POWER_PWRCTRL_Msk             /*!< PWRCTRL[1:0] bits (Power supply control bits) */
#define SDIO_POWER_PWRCTRL_0                (0x1UL << SDIO_POWER_PWRCTRL_Pos)   /*!< 0x01 */
#define SDIO_POWER_PWRCTRL_1                (0x2UL << SDIO_POWER_PWRCTRL_Pos)   /*!< 0x02 */

/******************  Bit definition for SDIO_CLKCR register  ******************/
#define SDIO_CLKCR_CLKDIV_Pos               (0U)                               
#define SDIO_CLKCR_CLKDIV_Msk               (0xFFUL << SDIO_CLKCR_CLKDIV_Pos)   /*!< 0x000000FF */
#define SDIO_CLKCR_CLKDIV                   SDIO_CLKCR_CLKDIV_Msk              /*!< Clock divide factor */
#define SDIO_CLKCR_CLKEN_Pos                (8U)                               
#define SDIO_CLKCR_CLKEN_Msk                (0x1UL << SDIO_CLKCR_CLKEN_Pos)     /*!< 0x00000100 */
#define SDIO_CLKCR_CLKEN                    SDIO_CLKCR_CLKEN_Msk               /*!< Clock enable bit */
#define SDIO_CLKCR_PWRSAV_Pos               (9U)                               
#define SDIO_CLKCR_PWRSAV_Msk               (0x1UL << SDIO_CLKCR_PWRSAV_Pos)    /*!< 0x00000200 */
#define SDIO_CLKCR_PWRSAV                   SDIO_CLKCR_PWRSAV_Msk              /*!< Power saving configuration bit */
#define SDIO_CLKCR_BYPASS_Pos               (10U)                              
#define SDIO_CLKCR_BYPASS_Msk               (0x1UL << SDIO_CLKCR_BYPASS_Pos)    /*!< 0x00000400 */
#define SDIO_CLKCR_BYPASS                   SDIO_CLKCR_BYPASS_Msk              /*!< Clock divider bypass enable bit */

#define SDIO_CLKCR_WIDBUS_Pos               (11U)                              
#define SDIO_CLKCR_WIDBUS_Msk               (0x3UL << SDIO_CLKCR_WIDBUS_Pos)    /*!< 0x00001800 */
#define SDIO_CLKCR_WIDBUS                   SDIO_CLKCR_WIDBUS_Msk              /*!< WIDBUS[1:0] bits (Wide bus mode enable bit) */
#define SDIO_CLKCR_WIDBUS_0                 (0x1UL << SDIO_CLKCR_WIDBUS_Pos)    /*!< 0x0800 */
#define SDIO_CLKCR_WIDBUS_1                 (0x2UL << SDIO_CLKCR_WIDBUS_Pos)    /*!< 0x1000 */

#define SDIO_CLKCR_NEGEDGE_Pos              (13U)                              
#define SDIO_CLKCR_NEGEDGE_Msk              (0x1UL << SDIO_CLKCR_NEGEDGE_Pos)   /*!< 0x00002000 */
#define SDIO_CLKCR_NEGEDGE                  SDIO_CLKCR_NEGEDGE_Msk             /*!< SDIO_CK dephasing selection bit */
#define SDIO_CLKCR_HWFC_EN_Pos              (14U)                              
#define SDIO_CLKCR_HWFC_EN_Msk              (0x1UL << SDIO_CLKCR_HWFC_EN_Pos)   /*!< 0x00004000 */
#define SDIO_CLKCR_HWFC_EN                  SDIO_CLKCR_HWFC_EN_Msk             /*!< HW Flow Control enable */

/*******************  Bit definition for SDIO_ARG register  *******************/
#define SDIO_ARG_CMDARG_Pos                 (0U)                               
#define SDIO_ARG_CMDARG_Msk                 (0xFFFFFFFFUL << SDIO_ARG_CMDARG_Pos) /*!< 0xFFFFFFFF */
#define SDIO_ARG_CMDARG                     SDIO_ARG_CMDARG_Msk                /*!< Command argument */

/*******************  Bit definition for SDIO_CMD register  *******************/
#define SDIO_CMD_CMDINDEX_Pos               (0U)                               
#define SDIO_CMD_CMDINDEX_Msk               (0x3FUL << SDIO_CMD_CMDINDEX_Pos)   /*!< 0x0000003F */
#define SDIO_CMD_CMDINDEX                   SDIO_CMD_CMDINDEX_Msk              /*!< Command Index */

#define SDIO_CMD_WAITRESP_Pos               (6U)                               
#define SDIO_CMD_WAITRESP_Msk               (0x3UL << SDIO_CMD_WAITRESP_Pos)    /*!< 0x000000C0 */
#define SDIO_CMD_WAITRESP                   SDIO_CMD_WAITRESP_Msk              /*!< WAITRESP[1:0] bits (Wait for response bits) */
#define SDIO_CMD_WAITRESP_0                 (0x1UL << SDIO_CMD_WAITRESP_Pos)    /*!< 0x0040 */
#define SDIO_CMD_WAITRESP_1                 (0x2UL << SDIO_CMD_WAITRESP_Pos)    /*!< 0x0080 */

#define SDIO_CMD_WAITINT_Pos                (8U)                               
#define SDIO_CMD_WAITINT_Msk                (0x1UL << SDIO_CMD_WAITINT_Pos)     /*!< 0x00000100 */
#define SDIO_CMD_WAITINT                    SDIO_CMD_WAITINT_Msk               /*!< CPSM Waits for Interrupt Request */
#define SDIO_CMD_WAITPEND_Pos               (9U)                               
#define SDIO_CMD_WAITPEND_Msk               (0x1UL << SDIO_CMD_WAITPEND_Pos)    /*!< 0x00000200 */
#define SDIO_CMD_WAITPEND                   SDIO_CMD_WAITPEND_Msk              /*!< CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define SDIO_CMD_CPSMEN_Pos                 (10U)                              
#define SDIO_CMD_CPSMEN_Msk                 (0x1UL << SDIO_CMD_CPSMEN_Pos)      /*!< 0x00000400 */
#define SDIO_CMD_CPSMEN                     SDIO_CMD_CPSMEN_Msk                /*!< Command path state machine (CPSM) Enable bit */
#define SDIO_CMD_SDIOSUSPEND_Pos            (11U)                              
#define SDIO_CMD_SDIOSUSPEND_Msk            (0x1UL << SDIO_CMD_SDIOSUSPEND_Pos) /*!< 0x00000800 */
#define SDIO_CMD_SDIOSUSPEND                SDIO_CMD_SDIOSUSPEND_Msk           /*!< SD I/O suspend command */
#define SDIO_CMD_ENCMDCOMPL_Pos             (12U)                              
#define SDIO_CMD_ENCMDCOMPL_Msk             (0x1UL << SDIO_CMD_ENCMDCOMPL_Pos)  /*!< 0x00001000 */
#define SDIO_CMD_ENCMDCOMPL                 SDIO_CMD_ENCMDCOMPL_Msk            /*!< Enable CMD completion */
#define SDIO_CMD_NIEN_Pos                   (13U)                              
#define SDIO_CMD_NIEN_Msk                   (0x1UL << SDIO_CMD_NIEN_Pos)        /*!< 0x00002000 */
#define SDIO_CMD_NIEN                       SDIO_CMD_NIEN_Msk                  /*!< Not Interrupt Enable */
#define SDIO_CMD_CEATACMD_Pos               (14U)                              
#define SDIO_CMD_CEATACMD_Msk               (0x1UL << SDIO_CMD_CEATACMD_Pos)    /*!< 0x00004000 */
#define SDIO_CMD_CEATACMD                   SDIO_CMD_CEATACMD_Msk              /*!< CE-ATA command */

/*****************  Bit definition for SDIO_RESPCMD register  *****************/
#define SDIO_RESPCMD_RESPCMD_Pos            (0U)                               
#define SDIO_RESPCMD_RESPCMD_Msk            (0x3FUL << SDIO_RESPCMD_RESPCMD_Pos) /*!< 0x0000003F */
#define SDIO_RESPCMD_RESPCMD                SDIO_RESPCMD_RESPCMD_Msk           /*!< Response command index */

/******************  Bit definition for SDIO_RESP0 register  ******************/
#define SDIO_RESP0_CARDSTATUS0_Pos          (0U)                               
#define SDIO_RESP0_CARDSTATUS0_Msk          (0xFFFFFFFFUL << SDIO_RESP0_CARDSTATUS0_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP0_CARDSTATUS0              SDIO_RESP0_CARDSTATUS0_Msk         /*!< Card Status */

/******************  Bit definition for SDIO_RESP1 register  ******************/
#define SDIO_RESP1_CARDSTATUS1_Pos          (0U)                               
#define SDIO_RESP1_CARDSTATUS1_Msk          (0xFFFFFFFFUL << SDIO_RESP1_CARDSTATUS1_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP1_CARDSTATUS1              SDIO_RESP1_CARDSTATUS1_Msk         /*!< Card Status */

/******************  Bit definition for SDIO_RESP2 register  ******************/
#define SDIO_RESP2_CARDSTATUS2_Pos          (0U)                               
#define SDIO_RESP2_CARDSTATUS2_Msk          (0xFFFFFFFFUL << SDIO_RESP2_CARDSTATUS2_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP2_CARDSTATUS2              SDIO_RESP2_CARDSTATUS2_Msk         /*!< Card Status */

/******************  Bit definition for SDIO_RESP3 register  ******************/
#define SDIO_RESP3_CARDSTATUS3_Pos          (0U)                               
#define SDIO_RESP3_CARDSTATUS3_Msk          (0xFFFFFFFFUL << SDIO_RESP3_CARDSTATUS3_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP3_CARDSTATUS3              SDIO_RESP3_CARDSTATUS3_Msk         /*!< Card Status */

/******************  Bit definition for SDIO_RESP4 register  ******************/
#define SDIO_RESP4_CARDSTATUS4_Pos          (0U)                               
#define SDIO_RESP4_CARDSTATUS4_Msk          (0xFFFFFFFFUL << SDIO_RESP4_CARDSTATUS4_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP4_CARDSTATUS4              SDIO_RESP4_CARDSTATUS4_Msk         /*!< Card Status */

/******************  Bit definition for SDIO_DTIMER register  *****************/
#define SDIO_DTIMER_DATATIME_Pos            (0U)                               
#define SDIO_DTIMER_DATATIME_Msk            (0xFFFFFFFFUL << SDIO_DTIMER_DATATIME_Pos) /*!< 0xFFFFFFFF */
#define SDIO_DTIMER_DATATIME                SDIO_DTIMER_DATATIME_Msk           /*!< Data timeout period. */

/******************  Bit definition for SDIO_DLEN register  *******************/
#define SDIO_DLEN_DATALENGTH_Pos            (0U)                               
#define SDIO_DLEN_DATALENGTH_Msk            (0x1FFFFFFUL << SDIO_DLEN_DATALENGTH_Pos) /*!< 0x01FFFFFF */
#define SDIO_DLEN_DATALENGTH                SDIO_DLEN_DATALENGTH_Msk           /*!< Data length value */

/******************  Bit definition for SDIO_DCTRL register  ******************/
#define SDIO_DCTRL_DTEN_Pos                 (0U)                               
#define SDIO_DCTRL_DTEN_Msk                 (0x1UL << SDIO_DCTRL_DTEN_Pos)      /*!< 0x00000001 */
#define SDIO_DCTRL_DTEN                     SDIO_DCTRL_DTEN_Msk                /*!< Data transfer enabled bit */
#define SDIO_DCTRL_DTDIR_Pos                (1U)                               
#define SDIO_DCTRL_DTDIR_Msk                (0x1UL << SDIO_DCTRL_DTDIR_Pos)     /*!< 0x00000002 */
#define SDIO_DCTRL_DTDIR                    SDIO_DCTRL_DTDIR_Msk               /*!< Data transfer direction selection */
#define SDIO_DCTRL_DTMODE_Pos               (2U)                               
#define SDIO_DCTRL_DTMODE_Msk               (0x1UL << SDIO_DCTRL_DTMODE_Pos)    /*!< 0x00000004 */
#define SDIO_DCTRL_DTMODE                   SDIO_DCTRL_DTMODE_Msk              /*!< Data transfer mode selection */
#define SDIO_DCTRL_DMAEN_Pos                (3U)                               
#define SDIO_DCTRL_DMAEN_Msk                (0x1UL << SDIO_DCTRL_DMAEN_Pos)     /*!< 0x00000008 */
#define SDIO_DCTRL_DMAEN                    SDIO_DCTRL_DMAEN_Msk               /*!< DMA enabled bit */

#define SDIO_DCTRL_DBLOCKSIZE_Pos           (4U)                               
#define SDIO_DCTRL_DBLOCKSIZE_Msk           (0xFUL << SDIO_DCTRL_DBLOCKSIZE_Pos) /*!< 0x000000F0 */
#define SDIO_DCTRL_DBLOCKSIZE               SDIO_DCTRL_DBLOCKSIZE_Msk          /*!< DBLOCKSIZE[3:0] bits (Data block size) */
#define SDIO_DCTRL_DBLOCKSIZE_0             (0x1UL << SDIO_DCTRL_DBLOCKSIZE_Pos) /*!< 0x0010 */
#define SDIO_DCTRL_DBLOCKSIZE_1             (0x2UL << SDIO_DCTRL_DBLOCKSIZE_Pos) /*!< 0x0020 */
#define SDIO_DCTRL_DBLOCKSIZE_2             (0x4UL << SDIO_DCTRL_DBLOCKSIZE_Pos) /*!< 0x0040 */
#define SDIO_DCTRL_DBLOCKSIZE_3             (0x8UL << SDIO_DCTRL_DBLOCKSIZE_Pos) /*!< 0x0080 */

#define SDIO_DCTRL_RWSTART_Pos              (8U)                               
#define SDIO_DCTRL_RWSTART_Msk              (0x1UL << SDIO_DCTRL_RWSTART_Pos)   /*!< 0x00000100 */
#define SDIO_DCTRL_RWSTART                  SDIO_DCTRL_RWSTART_Msk             /*!< Read wait start */
#define SDIO_DCTRL_RWSTOP_Pos               (9U)                               
#define SDIO_DCTRL_RWSTOP_Msk               (0x1UL << SDIO_DCTRL_RWSTOP_Pos)    /*!< 0x00000200 */
#define SDIO_DCTRL_RWSTOP                   SDIO_DCTRL_RWSTOP_Msk              /*!< Read wait stop */
#define SDIO_DCTRL_RWMOD_Pos                (10U)                              
#define SDIO_DCTRL_RWMOD_Msk                (0x1UL << SDIO_DCTRL_RWMOD_Pos)     /*!< 0x00000400 */
#define SDIO_DCTRL_RWMOD                    SDIO_DCTRL_RWMOD_Msk               /*!< Read wait mode */
#define SDIO_DCTRL_SDIOEN_Pos               (11U)                              
#define SDIO_DCTRL_SDIOEN_Msk               (0x1UL << SDIO_DCTRL_SDIOEN_Pos)    /*!< 0x00000800 */
#define SDIO_DCTRL_SDIOEN                   SDIO_DCTRL_SDIOEN_Msk              /*!< SD I/O enable functions */

/******************  Bit definition for SDIO_DCOUNT register  *****************/
#define SDIO_DCOUNT_DATACOUNT_Pos           (0U)                               
#define SDIO_DCOUNT_DATACOUNT_Msk           (0x1FFFFFFUL << SDIO_DCOUNT_DATACOUNT_Pos) /*!< 0x01FFFFFF */
#define SDIO_DCOUNT_DATACOUNT               SDIO_DCOUNT_DATACOUNT_Msk          /*!< Data count value */

/******************  Bit definition for SDIO_STA register  ********************/
#define SDIO_STA_CCRCFAIL_Pos               (0U)                               
#define SDIO_STA_CCRCFAIL_Msk               (0x1UL << SDIO_STA_CCRCFAIL_Pos)    /*!< 0x00000001 */
#define SDIO_STA_CCRCFAIL                   SDIO_STA_CCRCFAIL_Msk              /*!< Command response received (CRC check failed) */
#define SDIO_STA_DCRCFAIL_Pos               (1U)                               
#define SDIO_STA_DCRCFAIL_Msk               (0x1UL << SDIO_STA_DCRCFAIL_Pos)    /*!< 0x00000002 */
#define SDIO_STA_DCRCFAIL                   SDIO_STA_DCRCFAIL_Msk              /*!< Data block sent/received (CRC check failed) */
#define SDIO_STA_CTIMEOUT_Pos               (2U)                               
#define SDIO_STA_CTIMEOUT_Msk               (0x1UL << SDIO_STA_CTIMEOUT_Pos)    /*!< 0x00000004 */
#define SDIO_STA_CTIMEOUT                   SDIO_STA_CTIMEOUT_Msk              /*!< Command response timeout */
#define SDIO_STA_DTIMEOUT_Pos               (3U)                               
#define SDIO_STA_DTIMEOUT_Msk               (0x1UL << SDIO_STA_DTIMEOUT_Pos)    /*!< 0x00000008 */
#define SDIO_STA_DTIMEOUT                   SDIO_STA_DTIMEOUT_Msk              /*!< Data timeout */
#define SDIO_STA_TXUNDERR_Pos               (4U)                               
#define SDIO_STA_TXUNDERR_Msk               (0x1UL << SDIO_STA_TXUNDERR_Pos)    /*!< 0x00000010 */
#define SDIO_STA_TXUNDERR                   SDIO_STA_TXUNDERR_Msk              /*!< Transmit FIFO underrun error */
#define SDIO_STA_RXOVERR_Pos                (5U)                               
#define SDIO_STA_RXOVERR_Msk                (0x1UL << SDIO_STA_RXOVERR_Pos)     /*!< 0x00000020 */
#define SDIO_STA_RXOVERR                    SDIO_STA_RXOVERR_Msk               /*!< Received FIFO overrun error */
#define SDIO_STA_CMDREND_Pos                (6U)                               
#define SDIO_STA_CMDREND_Msk                (0x1UL << SDIO_STA_CMDREND_Pos)     /*!< 0x00000040 */
#define SDIO_STA_CMDREND                    SDIO_STA_CMDREND_Msk               /*!< Command response received (CRC check passed) */
#define SDIO_STA_CMDSENT_Pos                (7U)                               
#define SDIO_STA_CMDSENT_Msk                (0x1UL << SDIO_STA_CMDSENT_Pos)     /*!< 0x00000080 */
#define SDIO_STA_CMDSENT                    SDIO_STA_CMDSENT_Msk               /*!< Command sent (no response required) */
#define SDIO_STA_DATAEND_Pos                (8U)                               
#define SDIO_STA_DATAEND_Msk                (0x1UL << SDIO_STA_DATAEND_Pos)     /*!< 0x00000100 */
#define SDIO_STA_DATAEND                    SDIO_STA_DATAEND_Msk               /*!< Data end (data counter, SDIDCOUNT, is zero) */
#define SDIO_STA_STBITERR_Pos               (9U)                               
#define SDIO_STA_STBITERR_Msk               (0x1UL << SDIO_STA_STBITERR_Pos)    /*!< 0x00000200 */
#define SDIO_STA_STBITERR                   SDIO_STA_STBITERR_Msk              /*!< Start bit not detected on all data signals in wide bus mode */
#define SDIO_STA_DBCKEND_Pos                (10U)                              
#define SDIO_STA_DBCKEND_Msk                (0x1UL << SDIO_STA_DBCKEND_Pos)     /*!< 0x00000400 */
#define SDIO_STA_DBCKEND                    SDIO_STA_DBCKEND_Msk               /*!< Data block sent/received (CRC check passed) */
#define SDIO_STA_CMDACT_Pos                 (11U)                              
#define SDIO_STA_CMDACT_Msk                 (0x1UL << SDIO_STA_CMDACT_Pos)      /*!< 0x00000800 */
#define SDIO_STA_CMDACT                     SDIO_STA_CMDACT_Msk                /*!< Command transfer in progress */
#define SDIO_STA_TXACT_Pos                  (12U)                              
#define SDIO_STA_TXACT_Msk                  (0x1UL << SDIO_STA_TXACT_Pos)       /*!< 0x00001000 */
#define SDIO_STA_TXACT                      SDIO_STA_TXACT_Msk                 /*!< Data transmit in progress */
#define SDIO_STA_RXACT_Pos                  (13U)                              
#define SDIO_STA_RXACT_Msk                  (0x1UL << SDIO_STA_RXACT_Pos)       /*!< 0x00002000 */
#define SDIO_STA_RXACT                      SDIO_STA_RXACT_Msk                 /*!< Data receive in progress */
#define SDIO_STA_TXFIFOHE_Pos               (14U)                              
#define SDIO_STA_TXFIFOHE_Msk               (0x1UL << SDIO_STA_TXFIFOHE_Pos)    /*!< 0x00004000 */
#define SDIO_STA_TXFIFOHE                   SDIO_STA_TXFIFOHE_Msk              /*!< Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define SDIO_STA_RXFIFOHF_Pos               (15U)                              
#define SDIO_STA_RXFIFOHF_Msk               (0x1UL << SDIO_STA_RXFIFOHF_Pos)    /*!< 0x00008000 */
#define SDIO_STA_RXFIFOHF                   SDIO_STA_RXFIFOHF_Msk              /*!< Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define SDIO_STA_TXFIFOF_Pos                (16U)                              
#define SDIO_STA_TXFIFOF_Msk                (0x1UL << SDIO_STA_TXFIFOF_Pos)     /*!< 0x00010000 */
#define SDIO_STA_TXFIFOF                    SDIO_STA_TXFIFOF_Msk               /*!< Transmit FIFO full */
#define SDIO_STA_RXFIFOF_Pos                (17U)                              
#define SDIO_STA_RXFIFOF_Msk                (0x1UL << SDIO_STA_RXFIFOF_Pos)     /*!< 0x00020000 */
#define SDIO_STA_RXFIFOF                    SDIO_STA_RXFIFOF_Msk               /*!< Receive FIFO full */
#define SDIO_STA_TXFIFOE_Pos                (18U)                              
#define SDIO_STA_TXFIFOE_Msk                (0x1UL << SDIO_STA_TXFIFOE_Pos)     /*!< 0x00040000 */
#define SDIO_STA_TXFIFOE                    SDIO_STA_TXFIFOE_Msk               /*!< Transmit FIFO empty */
#define SDIO_STA_RXFIFOE_Pos                (19U)                              
#define SDIO_STA_RXFIFOE_Msk                (0x1UL << SDIO_STA_RXFIFOE_Pos)     /*!< 0x00080000 */
#define SDIO_STA_RXFIFOE                    SDIO_STA_RXFIFOE_Msk               /*!< Receive FIFO empty */
#define SDIO_STA_TXDAVL_Pos                 (20U)                              
#define SDIO_STA_TXDAVL_Msk                 (0x1UL << SDIO_STA_TXDAVL_Pos)      /*!< 0x00100000 */
#define SDIO_STA_TXDAVL                     SDIO_STA_TXDAVL_Msk                /*!< Data available in transmit FIFO */
#define SDIO_STA_RXDAVL_Pos                 (21U)                              
#define SDIO_STA_RXDAVL_Msk                 (0x1UL << SDIO_STA_RXDAVL_Pos)      /*!< 0x00200000 */
#define SDIO_STA_RXDAVL                     SDIO_STA_RXDAVL_Msk                /*!< Data available in receive FIFO */
#define SDIO_STA_SDIOIT_Pos                 (22U)                              
#define SDIO_STA_SDIOIT_Msk                 (0x1UL << SDIO_STA_SDIOIT_Pos)      /*!< 0x00400000 */
#define SDIO_STA_SDIOIT                     SDIO_STA_SDIOIT_Msk                /*!< SDIO interrupt received */
#define SDIO_STA_CEATAEND_Pos               (23U)                              
#define SDIO_STA_CEATAEND_Msk               (0x1UL << SDIO_STA_CEATAEND_Pos)    /*!< 0x00800000 */
#define SDIO_STA_CEATAEND                   SDIO_STA_CEATAEND_Msk              /*!< CE-ATA command completion signal received for CMD61 */

/*******************  Bit definition for SDIO_ICR register  *******************/
#define SDIO_ICR_CCRCFAILC_Pos              (0U)                               
#define SDIO_ICR_CCRCFAILC_Msk              (0x1UL << SDIO_ICR_CCRCFAILC_Pos)   /*!< 0x00000001 */
#define SDIO_ICR_CCRCFAILC                  SDIO_ICR_CCRCFAILC_Msk             /*!< CCRCFAIL flag clear bit */
#define SDIO_ICR_DCRCFAILC_Pos              (1U)                               
#define SDIO_ICR_DCRCFAILC_Msk              (0x1UL << SDIO_ICR_DCRCFAILC_Pos)   /*!< 0x00000002 */
#define SDIO_ICR_DCRCFAILC                  SDIO_ICR_DCRCFAILC_Msk             /*!< DCRCFAIL flag clear bit */
#define SDIO_ICR_CTIMEOUTC_Pos              (2U)                               
#define SDIO_ICR_CTIMEOUTC_Msk              (0x1UL << SDIO_ICR_CTIMEOUTC_Pos)   /*!< 0x00000004 */
#define SDIO_ICR_CTIMEOUTC                  SDIO_ICR_CTIMEOUTC_Msk             /*!< CTIMEOUT flag clear bit */
#define SDIO_ICR_DTIMEOUTC_Pos              (3U)                               
#define SDIO_ICR_DTIMEOUTC_Msk              (0x1UL << SDIO_ICR_DTIMEOUTC_Pos)   /*!< 0x00000008 */
#define SDIO_ICR_DTIMEOUTC                  SDIO_ICR_DTIMEOUTC_Msk             /*!< DTIMEOUT flag clear bit */
#define SDIO_ICR_TXUNDERRC_Pos              (4U)                               
#define SDIO_ICR_TXUNDERRC_Msk              (0x1UL << SDIO_ICR_TXUNDERRC_Pos)   /*!< 0x00000010 */
#define SDIO_ICR_TXUNDERRC                  SDIO_ICR_TXUNDERRC_Msk             /*!< TXUNDERR flag clear bit */
#define SDIO_ICR_RXOVERRC_Pos               (5U)                               
#define SDIO_ICR_RXOVERRC_Msk               (0x1UL << SDIO_ICR_RXOVERRC_Pos)    /*!< 0x00000020 */
#define SDIO_ICR_RXOVERRC                   SDIO_ICR_RXOVERRC_Msk              /*!< RXOVERR flag clear bit */
#define SDIO_ICR_CMDRENDC_Pos               (6U)                               
#define SDIO_ICR_CMDRENDC_Msk               (0x1UL << SDIO_ICR_CMDRENDC_Pos)    /*!< 0x00000040 */
#define SDIO_ICR_CMDRENDC                   SDIO_ICR_CMDRENDC_Msk              /*!< CMDREND flag clear bit */
#define SDIO_ICR_CMDSENTC_Pos               (7U)                               
#define SDIO_ICR_CMDSENTC_Msk               (0x1UL << SDIO_ICR_CMDSENTC_Pos)    /*!< 0x00000080 */
#define SDIO_ICR_CMDSENTC                   SDIO_ICR_CMDSENTC_Msk              /*!< CMDSENT flag clear bit */
#define SDIO_ICR_DATAENDC_Pos               (8U)                               
#define SDIO_ICR_DATAENDC_Msk               (0x1UL << SDIO_ICR_DATAENDC_Pos)    /*!< 0x00000100 */
#define SDIO_ICR_DATAENDC                   SDIO_ICR_DATAENDC_Msk              /*!< DATAEND flag clear bit */
#define SDIO_ICR_STBITERRC_Pos              (9U)                               
#define SDIO_ICR_STBITERRC_Msk              (0x1UL << SDIO_ICR_STBITERRC_Pos)   /*!< 0x00000200 */
#define SDIO_ICR_STBITERRC                  SDIO_ICR_STBITERRC_Msk             /*!< STBITERR flag clear bit */
#define SDIO_ICR_DBCKENDC_Pos               (10U)                              
#define SDIO_ICR_DBCKENDC_Msk               (0x1UL << SDIO_ICR_DBCKENDC_Pos)    /*!< 0x00000400 */
#define SDIO_ICR_DBCKENDC                   SDIO_ICR_DBCKENDC_Msk              /*!< DBCKEND flag clear bit */
#define SDIO_ICR_SDIOITC_Pos                (22U)                              
#define SDIO_ICR_SDIOITC_Msk                (0x1UL << SDIO_ICR_SDIOITC_Pos)     /*!< 0x00400000 */
#define SDIO_ICR_SDIOITC                    SDIO_ICR_SDIOITC_Msk               /*!< SDIOIT flag clear bit */
#define SDIO_ICR_CEATAENDC_Pos              (23U)                              
#define SDIO_ICR_CEATAENDC_Msk              (0x1UL << SDIO_ICR_CEATAENDC_Pos)   /*!< 0x00800000 */
#define SDIO_ICR_CEATAENDC                  SDIO_ICR_CEATAENDC_Msk             /*!< CEATAEND flag clear bit */

/******************  Bit definition for SDIO_MASK register  *******************/
#define SDIO_MASK_CCRCFAILIE_Pos            (0U)                               
#define SDIO_MASK_CCRCFAILIE_Msk            (0x1UL << SDIO_MASK_CCRCFAILIE_Pos) /*!< 0x00000001 */
#define SDIO_MASK_CCRCFAILIE                SDIO_MASK_CCRCFAILIE_Msk           /*!< Command CRC Fail Interrupt Enable */
#define SDIO_MASK_DCRCFAILIE_Pos            (1U)                               
#define SDIO_MASK_DCRCFAILIE_Msk            (0x1UL << SDIO_MASK_DCRCFAILIE_Pos) /*!< 0x00000002 */
#define SDIO_MASK_DCRCFAILIE                SDIO_MASK_DCRCFAILIE_Msk           /*!< Data CRC Fail Interrupt Enable */
#define SDIO_MASK_CTIMEOUTIE_Pos            (2U)                               
#define SDIO_MASK_CTIMEOUTIE_Msk            (0x1UL << SDIO_MASK_CTIMEOUTIE_Pos) /*!< 0x00000004 */
#define SDIO_MASK_CTIMEOUTIE                SDIO_MASK_CTIMEOUTIE_Msk           /*!< Command TimeOut Interrupt Enable */
#define SDIO_MASK_DTIMEOUTIE_Pos            (3U)                               
#define SDIO_MASK_DTIMEOUTIE_Msk            (0x1UL << SDIO_MASK_DTIMEOUTIE_Pos) /*!< 0x00000008 */
#define SDIO_MASK_DTIMEOUTIE                SDIO_MASK_DTIMEOUTIE_Msk           /*!< Data TimeOut Interrupt Enable */
#define SDIO_MASK_TXUNDERRIE_Pos            (4U)                               
#define SDIO_MASK_TXUNDERRIE_Msk            (0x1UL << SDIO_MASK_TXUNDERRIE_Pos) /*!< 0x00000010 */
#define SDIO_MASK_TXUNDERRIE                SDIO_MASK_TXUNDERRIE_Msk           /*!< Tx FIFO UnderRun Error Interrupt Enable */
#define SDIO_MASK_RXOVERRIE_Pos             (5U)                               
#define SDIO_MASK_RXOVERRIE_Msk             (0x1UL << SDIO_MASK_RXOVERRIE_Pos)  /*!< 0x00000020 */
#define SDIO_MASK_RXOVERRIE                 SDIO_MASK_RXOVERRIE_Msk            /*!< Rx FIFO OverRun Error Interrupt Enable */
#define SDIO_MASK_CMDRENDIE_Pos             (6U)                               
#define SDIO_MASK_CMDRENDIE_Msk             (0x1UL << SDIO_MASK_CMDRENDIE_Pos)  /*!< 0x00000040 */
#define SDIO_MASK_CMDRENDIE                 SDIO_MASK_CMDRENDIE_Msk            /*!< Command Response Received Interrupt Enable */
#define SDIO_MASK_CMDSENTIE_Pos             (7U)                               
#define SDIO_MASK_CMDSENTIE_Msk             (0x1UL << SDIO_MASK_CMDSENTIE_Pos)  /*!< 0x00000080 */
#define SDIO_MASK_CMDSENTIE                 SDIO_MASK_CMDSENTIE_Msk            /*!< Command Sent Interrupt Enable */
#define SDIO_MASK_DATAENDIE_Pos             (8U)                               
#define SDIO_MASK_DATAENDIE_Msk             (0x1UL << SDIO_MASK_DATAENDIE_Pos)  /*!< 0x00000100 */
#define SDIO_MASK_DATAENDIE                 SDIO_MASK_DATAENDIE_Msk            /*!< Data End Interrupt Enable */
#define SDIO_MASK_STBITERRIE_Pos            (9U)                               
#define SDIO_MASK_STBITERRIE_Msk            (0x1UL << SDIO_MASK_STBITERRIE_Pos) /*!< 0x00000200 */
#define SDIO_MASK_STBITERRIE                SDIO_MASK_STBITERRIE_Msk           /*!< Start Bit Error Interrupt Enable */
#define SDIO_MASK_DBCKENDIE_Pos             (10U)                              
#define SDIO_MASK_DBCKENDIE_Msk             (0x1UL << SDIO_MASK_DBCKENDIE_Pos)  /*!< 0x00000400 */
#define SDIO_MASK_DBCKENDIE                 SDIO_MASK_DBCKENDIE_Msk            /*!< Data Block End Interrupt Enable */
#define SDIO_MASK_CMDACTIE_Pos              (11U)                              
#define SDIO_MASK_CMDACTIE_Msk              (0x1UL << SDIO_MASK_CMDACTIE_Pos)   /*!< 0x00000800 */
#define SDIO_MASK_CMDACTIE                  SDIO_MASK_CMDACTIE_Msk             /*!< Command Acting Interrupt Enable */
#define SDIO_MASK_TXACTIE_Pos               (12U)                              
#define SDIO_MASK_TXACTIE_Msk               (0x1UL << SDIO_MASK_TXACTIE_Pos)    /*!< 0x00001000 */
#define SDIO_MASK_TXACTIE                   SDIO_MASK_TXACTIE_Msk              /*!< Data Transmit Acting Interrupt Enable */
#define SDIO_MASK_RXACTIE_Pos               (13U)                              
#define SDIO_MASK_RXACTIE_Msk               (0x1UL << SDIO_MASK_RXACTIE_Pos)    /*!< 0x00002000 */
#define SDIO_MASK_RXACTIE                   SDIO_MASK_RXACTIE_Msk              /*!< Data receive acting interrupt enabled */
#define SDIO_MASK_TXFIFOHEIE_Pos            (14U)                              
#define SDIO_MASK_TXFIFOHEIE_Msk            (0x1UL << SDIO_MASK_TXFIFOHEIE_Pos) /*!< 0x00004000 */
#define SDIO_MASK_TXFIFOHEIE                SDIO_MASK_TXFIFOHEIE_Msk           /*!< Tx FIFO Half Empty interrupt Enable */
#define SDIO_MASK_RXFIFOHFIE_Pos            (15U)                              
#define SDIO_MASK_RXFIFOHFIE_Msk            (0x1UL << SDIO_MASK_RXFIFOHFIE_Pos) /*!< 0x00008000 */
#define SDIO_MASK_RXFIFOHFIE                SDIO_MASK_RXFIFOHFIE_Msk           /*!< Rx FIFO Half Full interrupt Enable */
#define SDIO_MASK_TXFIFOFIE_Pos             (16U)                              
#define SDIO_MASK_TXFIFOFIE_Msk             (0x1UL << SDIO_MASK_TXFIFOFIE_Pos)  /*!< 0x00010000 */
#define SDIO_MASK_TXFIFOFIE                 SDIO_MASK_TXFIFOFIE_Msk            /*!< Tx FIFO Full interrupt Enable */
#define SDIO_MASK_RXFIFOFIE_Pos             (17U)                              
#define SDIO_MASK_RXFIFOFIE_Msk             (0x1UL << SDIO_MASK_RXFIFOFIE_Pos)  /*!< 0x00020000 */
#define SDIO_MASK_RXFIFOFIE                 SDIO_MASK_RXFIFOFIE_Msk            /*!< Rx FIFO Full interrupt Enable */
#define SDIO_MASK_TXFIFOEIE_Pos             (18U)                              
#define SDIO_MASK_TXFIFOEIE_Msk             (0x1UL << SDIO_MASK_TXFIFOEIE_Pos)  /*!< 0x00040000 */
#define SDIO_MASK_TXFIFOEIE                 SDIO_MASK_TXFIFOEIE_Msk            /*!< Tx FIFO Empty interrupt Enable */
#define SDIO_MASK_RXFIFOEIE_Pos             (19U)                              
#define SDIO_MASK_RXFIFOEIE_Msk             (0x1UL << SDIO_MASK_RXFIFOEIE_Pos)  /*!< 0x00080000 */
#define SDIO_MASK_RXFIFOEIE                 SDIO_MASK_RXFIFOEIE_Msk            /*!< Rx FIFO Empty interrupt Enable */
#define SDIO_MASK_TXDAVLIE_Pos              (20U)                              
#define SDIO_MASK_TXDAVLIE_Msk              (0x1UL << SDIO_MASK_TXDAVLIE_Pos)   /*!< 0x00100000 */
#define SDIO_MASK_TXDAVLIE                  SDIO_MASK_TXDAVLIE_Msk             /*!< Data available in Tx FIFO interrupt Enable */
#define SDIO_MASK_RXDAVLIE_Pos              (21U)                              
#define SDIO_MASK_RXDAVLIE_Msk              (0x1UL << SDIO_MASK_RXDAVLIE_Pos)   /*!< 0x00200000 */
#define SDIO_MASK_RXDAVLIE                  SDIO_MASK_RXDAVLIE_Msk             /*!< Data available in Rx FIFO interrupt Enable */
#define SDIO_MASK_SDIOITIE_Pos              (22U)                              
#define SDIO_MASK_SDIOITIE_Msk              (0x1UL << SDIO_MASK_SDIOITIE_Pos)   /*!< 0x00400000 */
#define SDIO_MASK_SDIOITIE                  SDIO_MASK_SDIOITIE_Msk             /*!< SDIO Mode Interrupt Received interrupt Enable */
#define SDIO_MASK_CEATAENDIE_Pos            (23U)                              
#define SDIO_MASK_CEATAENDIE_Msk            (0x1UL << SDIO_MASK_CEATAENDIE_Pos) /*!< 0x00800000 */
#define SDIO_MASK_CEATAENDIE                SDIO_MASK_CEATAENDIE_Msk           /*!< CE-ATA command completion signal received Interrupt Enable */

/*****************  Bit definition for SDIO_FIFOCNT register  *****************/
#define SDIO_FIFOCNT_FIFOCOUNT_Pos          (0U)                               
#define SDIO_FIFOCNT_FIFOCOUNT_Msk          (0xFFFFFFUL << SDIO_FIFOCNT_FIFOCOUNT_Pos) /*!< 0x00FFFFFF */
#define SDIO_FIFOCNT_FIFOCOUNT              SDIO_FIFOCNT_FIFOCOUNT_Msk         /*!< Remaining number of words to be written to or read from the FIFO */

/******************  Bit definition for SDIO_FIFO register  *******************/
#define SDIO_FIFO_FIFODATA_Pos              (0U)                               
#define SDIO_FIFO_FIFODATA_Msk              (0xFFFFFFFFUL << SDIO_FIFO_FIFODATA_Pos) /*!< 0xFFFFFFFF */
#define SDIO_FIFO_FIFODATA                  SDIO_FIFO_FIFODATA_Msk             /*!< Receive and transmit FIFO data */

// 레지스터 목록
namespace SDMMC_REG
{
enum
{
	POWER = 0, CLKCR, ARG, CMD,
	RESPCMD, RESP1, RESP2, RESP3,
	RESP4, DTIMER, DLEN, DCTRL,
	DCOUNT, STA, ICR, MASK,
	FIFOCNT = 18,
	FIFO = 32
};
}
#endif

