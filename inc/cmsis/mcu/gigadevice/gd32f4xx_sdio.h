/*!
    \file  gd32f4xx_sdio.h
    \brief definitions for the SDIO
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-08-15, V1.0.0, firmware for GD32F4xx
*/

#ifndef GD32F4XX_SDIO_H
#define GD32F4XX_SDIO_H

#include "gd32f4xx.h"

/** 
  * @brief SD host Interface
  */
typedef struct
{
    __IO uint32_t POWER;
    __IO uint32_t CLKCTLR;
    __IO uint32_t PARA;
    __IO uint32_t CMD;
    __I uint32_t RESPCMD;
    __I uint32_t RESP1;
    __I uint32_t RESP2;
    __I uint32_t RESP3;
    __I uint32_t RESP4;
    __IO uint32_t DTTR;
    __IO uint32_t DTLEN;
    __IO uint32_t DTCTLR;
    __I uint32_t DTCNT;
    __I uint32_t STR;
    __IO uint32_t ICR;
    __IO uint32_t IER;
    uint32_t  RESERVED0[2];
    __I uint32_t FIFOCNT;
    uint32_t  RESERVED1[13];
    __IO uint32_t FIFO;
} SDIO_TypeDef;

/* SDIO definitions */
#define SDIO                  ((SDIO_TypeDef *) SDIO_BASE)

/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for SDIO_POWER register  ******************/
#define  SDIO_POWER_PWRSTATE                        ((uint8_t)0x03)               /*!< PWRSTATE[1:0] bits (Power supply control bits) */
#define  SDIO_POWER_PWRSTATE_0                      ((uint8_t)0x01)               /*!< Bit 0 */
#define  SDIO_POWER_PWRSTATE_1                      ((uint8_t)0x02)               /*!< Bit 1 */

/******************  Bit definition for SDIO_CLKCTLR register  *****************/
#define  SDIO_CLKCTLR_DIV                           ((uint16_t)0x00FF)            /*!< Clock divide factor */
#define  SDIO_CLKCTLR_CKEN                          ((uint16_t)0x0100)            /*!< Clock enable bit */
#define  SDIO_CLKCTLR_PWRSAV                        ((uint16_t)0x0200)            /*!< Power saving configuration bit */
#define  SDIO_CLKCTLR_BYPASS                        ((uint16_t)0x0400)            /*!< Clock divider bypass enable bit */

#define  SDIO_CLKCTLR_BUSMODE                       ((uint16_t)0x1800)            /*!< BUSMODE[1:0] bits (Wide bus mode enable bit) */
#define  SDIO_CLKCTLR_BUSMODE_0                     ((uint16_t)0x0800)            /*!< Bit 0 */
#define  SDIO_CLKCTLR_BUSMODE_1                     ((uint16_t)0x1000)            /*!< Bit 1 */

#define  SDIO_CLKCTLR_CKPH                          ((uint16_t)0x2000)            /*!< SDIO_CLK dephasing selection bit */
#define  SDIO_CLKCTLR_HWFL_EN                       ((uint16_t)0x4000)            /*!< HW Flow Control enable */

/*******************  Bit definition for SDIO_PARA register  ******************/
#define  SDIO_PARA_CMDARG                           ((uint32_t)0xFFFFFFFF)        /*!< Command argument */
									       
/*******************  Bit definition for SDIO_CMD register  *******************/
#define  SDIO_CMD_CMDINDEX                          ((uint16_t)0x003F)            /*!< Command Index */

#define  SDIO_CMD_WAITRESP                          ((uint16_t)0x00C0)            /*!< WAITRESP[1:0] bits (Wait for response bits) */
#define  SDIO_CMD_WAITRESP_0                        ((uint16_t)0x0040)            /*!<  Bit 0 */
#define  SDIO_CMD_WAITRESP_1                        ((uint16_t)0x0080)            /*!<  Bit 1 */

#define  SDIO_CMD_WAITINT                           ((uint16_t)0x0100)            /*!< CPSM Waits for Interrupt Request */
#define  SDIO_CMD_WAITPD                            ((uint16_t)0x0200)            /*!< CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define  SDIO_CMD_CSMEN                             ((uint16_t)0x0400)            /*!< Command state machine (CSM) Enable bit */
#define  SDIO_CMD_SDIOSUSPEND                       ((uint16_t)0x0800)            /*!< SD I/O suspend command */
#define  SDIO_CMD_ENCMDC                            ((uint16_t)0x1000)            /*!< Enable CMD completion */
#define  SDIO_CMD_NIEN                              ((uint16_t)0x2000)            /*!< Not Interrupt Enable */
#define  SDIO_CMD_ATACMD                            ((uint16_t)0x4000)            /*!< CE-ATA command */

/*****************  Bit definition for SDIO_RESPCMD register  *****************/
#define  SDIO_RESPCMD_RESPCMD                       ((uint8_t)0x3F)               /*!< Response command index */

/******************  Bit definition for SDIO_RESP1 register  ******************/
#define  SDIO_RESP1_CARDSTATE1                      ((uint32_t)0xFFFFFFFF)        /*!< Card State */

/******************  Bit definition for SDIO_RESP2 register  ******************/
#define  SDIO_RESP2_CARDSTATE2                      ((uint32_t)0xFFFFFFFF)        /*!< Card State */

/******************  Bit definition for SDIO_RESP3 register  ******************/
#define  SDIO_RESP3_CARDSTATE3                      ((uint32_t)0xFFFFFFFF)        /*!< Card State */

/******************  Bit definition for SDIO_RESP4 register  ******************/
#define  SDIO_RESP4_CARDSTATE4                      ((uint32_t)0xFFFFFFFF)        /*!< Card State */

/******************  Bit definition for SDIO_DTTR register  *******************/
#define  SDIO_DTTR_DTTIME                           ((uint32_t)0xFFFFFFFF)        /*!< Data timeout period. */

/******************  Bit definition for SDIO_DTLEN register  ******************/
#define  SDIO_DTLEN_DTLEN                           ((uint32_t)0x01FFFFFF)        /*!< Data length value */

/******************  Bit definition for SDIO_DTCTLR register  *****************/
#define  SDIO_DTCTLR_DTTEN                          ((uint16_t)0x0001)            /*!< Data transfer enabled bit */
#define  SDIO_DTCTLR_DTTDIR                         ((uint16_t)0x0002)            /*!< Data transfer direction selection */
#define  SDIO_DTCTLR_DTTMODE                        ((uint16_t)0x0004)            /*!< Data transfer mode selection */
#define  SDIO_DTCTLR_DMAEN                          ((uint16_t)0x0008)            /*!< DMA enabled bit */
									        
#define  SDIO_DTCTLR_DTBLKSIZE                      ((uint16_t)0x00F0)            /*!< DTBLKSIZE[3:0] bits (Data block size) */
#define  SDIO_DTCTLR_DTBLKSIZE_0                    ((uint16_t)0x0010)            /*!< Bit 0 */
#define  SDIO_DTCTLR_DTBLKSIZE_1                    ((uint16_t)0x0020)            /*!< Bit 1 */
#define  SDIO_DTCTLR_DTBLKSIZE_2                    ((uint16_t)0x0040)            /*!< Bit 2 */
#define  SDIO_DTCTLR_DTBLKSIZE_3                    ((uint16_t)0x0080)            /*!< Bit 3 */

#define  SDIO_DTCTLR_RWSTART                        ((uint16_t)0x0100)            /*!< Read wait start */
#define  SDIO_DTCTLR_RWSTOP                         ((uint16_t)0x0200)            /*!< Read wait stop */
#define  SDIO_DTCTLR_RWMODE                         ((uint16_t)0x0400)            /*!< Read wait mode */
#define  SDIO_DTCTLR_SDIOEN                         ((uint16_t)0x0800)            /*!< SD I/O enable functions */

/******************  Bit definition for SDIO_DTCNT register  ******************/
#define  SDIO_DTCNT_DTCNT                           ((uint32_t)0x01FFFFFF)        /*!< Data count value */

/******************  Bit definition for SDIO_STR register  ********************/
#define  SDIO_STR_CCRCFAIL                          ((uint32_t)0x00000001)        /*!< Command response received (CRC check failed) */
#define  SDIO_STR_DTCRCFAIL                         ((uint32_t)0x00000002)        /*!< Data block sent/received (CRC check failed) */
#define  SDIO_STR_CMDTMOUT                          ((uint32_t)0x00000004)        /*!< Command response timeout */
#define  SDIO_STR_DTTMOUT                           ((uint32_t)0x00000008)        /*!< Data timeout */
#define  SDIO_STR_TXURE                             ((uint32_t)0x00000010)        /*!< Transmit FIFO underrun error */
#define  SDIO_STR_RXORE                             ((uint32_t)0x00000020)        /*!< Received FIFO overrun error */
#define  SDIO_STR_CMDREND                           ((uint32_t)0x00000040)        /*!< Command response received (CRC check passed) */
#define  SDIO_STR_CMDSENT                           ((uint32_t)0x00000080)        /*!< Command sent (no response required) */
#define  SDIO_STR_DTEND                             ((uint32_t)0x00000100)        /*!< Data end (data counter, SDIDCOUNT, is zero) */
#define  SDIO_STR_STBITE                            ((uint32_t)0x00000200)        /*!< Start bit not detected on all data signals in wide bus mode */
#define  SDIO_STR_DTBLKEND                          ((uint32_t)0x00000400)        /*!< Data block sent/received (CRC check passed) */
#define  SDIO_STR_CMDRUN                            ((uint32_t)0x00000800)        /*!< Command transfer in progress */
#define  SDIO_STR_TXRUN                             ((uint32_t)0x00001000)        /*!< Data transmit in progress */
#define  SDIO_STR_RXRUN                             ((uint32_t)0x00002000)        /*!< Data receive in progress */
#define  SDIO_STR_TXFIFOHE                          ((uint32_t)0x00004000)        /*!< Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define  SDIO_STR_RXFIFOHF                          ((uint32_t)0x00008000)        /*!< Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define  SDIO_STR_TXFIFOF                           ((uint32_t)0x00010000)        /*!< Transmit FIFO full */
#define  SDIO_STR_RXFIFOF                           ((uint32_t)0x00020000)        /*!< Receive FIFO full */
#define  SDIO_STR_TXFIFOE                           ((uint32_t)0x00040000)        /*!< Transmit FIFO empty */
#define  SDIO_STR_RXFIFOE                           ((uint32_t)0x00080000)        /*!< Receive FIFO empty */
#define  SDIO_STR_TXDTVAL                           ((uint32_t)0x00100000)        /*!< Data available in transmit FIFO */
#define  SDIO_STR_RXDTVAL                           ((uint32_t)0x00200000)        /*!< Data available in receive FIFO */
#define  SDIO_STR_SDIOINT                           ((uint32_t)0x00400000)        /*!< SDIO interrupt received */
#define  SDIO_STR_ATAEND                            ((uint32_t)0x00800000)        /*!< CE-ATA command completion signal received for CMD61 */

/*******************  Bit definition for SDIO_INTCR register  *****************/
#define  SDIO_INTCR_CCRCFAILC                       ((uint32_t)0x00000001)        /*!< CCRCFAIL flag clear bit */
#define  SDIO_INTCR_DTCRCFAILC                      ((uint32_t)0x00000002)        /*!< DTCRCFAIL flag clear bit */
#define  SDIO_INTCR_CMDTMOUTC                       ((uint32_t)0x00000004)        /*!< CMDTMOUT flag clear bit */
#define  SDIO_INTCR_DTTMOUTC                        ((uint32_t)0x00000008)        /*!< DTTMOUT flag clear bit */
#define  SDIO_INTCR_TXUREC                          ((uint32_t)0x00000010)        /*!< TXURE flag clear bit */
#define  SDIO_INTCR_RXOREC                          ((uint32_t)0x00000020)        /*!< RXORE flag clear bit */
#define  SDIO_INTCR_CMDRENDC                        ((uint32_t)0x00000040)        /*!< CMDREND flag clear bit */
#define  SDIO_INTCR_CMDSENTC                        ((uint32_t)0x00000080)        /*!< CMDSENT flag clear bit */
#define  SDIO_INTCR_DTENDC                          ((uint32_t)0x00000100)        /*!< DTEND flag clear bit */
#define  SDIO_INTCR_STBITEC                         ((uint32_t)0x00000200)        /*!< STBITE flag clear bit */
#define  SDIO_INTCR_DTBLKENDC                       ((uint32_t)0x00000400)        /*!< DTBLKEND flag clear bit */
#define  SDIO_INTCR_SDIOINTC                        ((uint32_t)0x00400000)        /*!< SDIOINT flag clear bit */
#define  SDIO_INTCR_ATAENDC                         ((uint32_t)0x00800000)        /*!< ATAEND flag clear bit */

/******************  Bit definition for SDIO_IER register  ********************/
#define  SDIO_IER_CCRCFAILIE                        ((uint32_t)0x00000001)        /*!< Command CRC Fail Interrupt Enable */
#define  SDIO_IER_DTCRCFAILIE                       ((uint32_t)0x00000002)        /*!< Data CRC Fail Interrupt Enable */
#define  SDIO_IER_CMDTMOUTIE                        ((uint32_t)0x00000004)        /*!< Command TimeOut Interrupt Enable */
#define  SDIO_IER_DTTMOUTIE                         ((uint32_t)0x00000008)        /*!< Data TimeOut Interrupt Enable */
#define  SDIO_IER_TXUREIE                           ((uint32_t)0x00000010)        /*!< Tx FIFO UnderRun Error Interrupt Enable */
#define  SDIO_IER_RXOREIE                           ((uint32_t)0x00000020)        /*!< Rx FIFO OverRun Error Interrupt Enable */
#define  SDIO_IER_CMDRENDIE                         ((uint32_t)0x00000040)        /*!< Command Response Received Interrupt Enable */
#define  SDIO_IER_CMDSENTIE                         ((uint32_t)0x00000080)        /*!< Command Sent Interrupt Enable */
#define  SDIO_IER_DTENDIE                           ((uint32_t)0x00000100)        /*!< Data End Interrupt Enable */
#define  SDIO_IER_STBITEIE                          ((uint32_t)0x00000200)        /*!< Start Bit Error Interrupt Enable */
#define  SDIO_IER_DTBLKENDIE                        ((uint32_t)0x00000400)        /*!< Data Block End Interrupt Enable */
#define  SDIO_IER_CMDRUNIE                          ((uint32_t)0x00000800)        /*!< Command Acting Interrupt Enable */
#define  SDIO_IER_TXRUNIE                           ((uint32_t)0x00001000)        /*!< Data Transmit Acting Interrupt Enable */
#define  SDIO_IER_RXRUNIE                           ((uint32_t)0x00002000)        /*!< Data receive acting interrupt enabled */
#define  SDIO_IER_TXFIFOHEIE                        ((uint32_t)0x00004000)        /*!< Tx FIFO Half Empty interrupt Enable */
#define  SDIO_IER_RXFIFOHFIE                        ((uint32_t)0x00008000)        /*!< Rx FIFO Half Full interrupt Enable */
#define  SDIO_IER_TXFIFOFIE                         ((uint32_t)0x00010000)        /*!< Tx FIFO Full interrupt Enable */
#define  SDIO_IER_RXFIFOFIE                         ((uint32_t)0x00020000)        /*!< Rx FIFO Full interrupt Enable */
#define  SDIO_IER_TXFIFOEIE                         ((uint32_t)0x00040000)        /*!< Tx FIFO Empty interrupt Enable */
#define  SDIO_IER_RXFIFOEIE                         ((uint32_t)0x00080000)        /*!< Rx FIFO Empty interrupt Enable */
#define  SDIO_IER_TXDTVALIE                         ((uint32_t)0x00100000)        /*!< Data available in Tx FIFO interrupt Enable */
#define  SDIO_IER_RXDTVALIE                         ((uint32_t)0x00200000)        /*!< Data available in Rx FIFO interrupt Enable */
#define  SDIO_IER_SDIOINTIE                         ((uint32_t)0x00400000)        /*!< SDIO Mode Interrupt Received interrupt Enable */
#define  SDIO_IER_ATAENDIE                          ((uint32_t)0x00800000)        /*!< CE-ATA command completion signal received Interrupt Enable */

/*****************  Bit definition for SDIO_FIFOCNT register  *****************/
#define  SDIO_FIFOCNT_FIFOCNT                       ((uint32_t)0x00FFFFFF)        /*!< Remaining number of words to be written to or read from the FIFO */

/******************  Bit definition for SDIO_FIFO register  *******************/
#define  SDIO_FIFO_FIFODT                           ((uint32_t)0xFFFFFFFF)        /*!< Receive and transmit FIFO data */

#endif /* GD32F4XX_SDIO_H */
