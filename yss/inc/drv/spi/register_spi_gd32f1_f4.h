////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_SPI_REG__H_
#define YSS_DRV_SPI_REG__H_

/*******************  Bit definition for SPI_CTLR1 register  ********************/
#define  SPI_CTLR1_SCKPH                            ((uint16_t)0x0001)            /*!< Clock Phase */
#define  SPI_CTLR1_SCKPL                            ((uint16_t)0x0002)            /*!< Clock Polarity */
#define  SPI_CTLR1_MSTMODE                          ((uint16_t)0x0004)            /*!< Master Selection */

#define  SPI_CTLR1_PSC                              ((uint16_t)0x0038)            /*!< PSC[2:0] bits (Baud Rate Control) */
#define  SPI_CTLR1_PSC_0                            ((uint16_t)0x0008)            /*!< Bit 0 */
#define  SPI_CTLR1_PSC_1                            ((uint16_t)0x0010)            /*!< Bit 1 */
#define  SPI_CTLR1_PSC_2                            ((uint16_t)0x0020)            /*!< Bit 2 */

#define  SPI_CTLR1_SPIEN                            ((uint16_t)0x0040)            /*!< SPI Enable */
#define  SPI_CTLR1_LF                               ((uint16_t)0x0080)            /*!< Frame Format */
#define  SPI_CTLR1_SWNSS                            ((uint16_t)0x0100)            /*!< Internal slave select */
#define  SPI_CTLR1_SWNSSEN                          ((uint16_t)0x0200)            /*!< Software slave management */
#define  SPI_CTLR1_RO                               ((uint16_t)0x0400)            /*!< Receive only */
#define  SPI_CTLR1_FF16                             ((uint16_t)0x0800)            /*!< Data Frame Format */
#define  SPI_CTLR1_CRCNT                            ((uint16_t)0x1000)            /*!< Transmit CRC next */
#define  SPI_CTLR1_CRCEN                            ((uint16_t)0x2000)            /*!< Hardware CRC calculation enable */
#define  SPI_CTLR1_BDOE                             ((uint16_t)0x4000)            /*!< Output enable in bidirectional mode */
#define  SPI_CTLR1_BDM                              ((uint16_t)0x8000)            /*!< Bidirectional data mode enable */
									       
/*******************  Bit definition for SPI_CTLR2 register  ********************/
#define  SPI_CTLR2_DMARE                            ((uint8_t)0x01)               /*!< Rx Buffer DMA Enable */
#define  SPI_CTLR2_DMATE                            ((uint8_t)0x02)               /*!< Tx Buffer DMA Enable */
#define  SPI_CTLR2_NSSDRV                           ((uint8_t)0x04)               /*!< SS Output Enable */
#define  SPI_CTLR2_ERRIE                            ((uint8_t)0x20)               /*!< Error Interrupt Enable */
#define  SPI_CTLR2_RBNEIE                           ((uint8_t)0x40)               /*!< RX buffer Not Empty Interrupt Enable */
#define  SPI_CTLR2_TBEIE                            ((uint8_t)0x80)               /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_STR register  ********************/
#define  SPI_STR_RBNE                               ((uint8_t)0x01)               /*!< Receive buffer Not Empty */
#define  SPI_STR_TBE                                ((uint8_t)0x02)               /*!< Transmit buffer Empty */
#define  SPI_STR_I2SCH                              ((uint8_t)0x04)               /*!< Channel side */
#define  SPI_STR_TXURE                              ((uint8_t)0x08)               /*!< Underrun flag */
#define  SPI_STR_CRCE                               ((uint8_t)0x10)               /*!< CRC Error flag */
#define  SPI_STR_CONFE                              ((uint8_t)0x20)               /*!< Mode fault */
#define  SPI_STR_RXORE                              ((uint8_t)0x40)               /*!< Overrun flag */
#define  SPI_STR_TRANS                              ((uint8_t)0x80)               /*!< Busy flag */

/********************  Bit definition for SPI_DTR register  ********************/
#define  SPI_DTR_DTR                                ((uint16_t)0xFFFF)            /*!< Data Register */

/*******************  Bit definition for SPI_CRR register  ******************/
#define  SPI_CPR_CPR                                ((uint16_t)0xFFFF)            /*!< CRC polynomial register */

/******************  Bit definition for SPI_RCR register  ******************/
#define  SPI_RCR_RCR                                ((uint16_t)0xFFFF)            /*!< Rx CRC Register */

/******************  Bit definition for SPI_TCR register  ******************/
#define  SPI_TCR_TCR                                ((uint16_t)0xFFFF)            /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCTLR register  *****************/
#define  SPI_I2SCTLR_CHLEN                          ((uint16_t)0x0001)            /*!< Channel length (number of bits per audio channel) */
								          
#define  SPI_I2SCTLR_DTLEN                          ((uint16_t)0x0006)            /*!< DTLEN[1:0] bits (Data length to be transferred) */
#define  SPI_I2SCTLR_DTLEN_0                        ((uint16_t)0x0002)            /*!< Bit 0 */
#define  SPI_I2SCTLR_DTLEN_1                        ((uint16_t)0x0004)            /*!< Bit 1 */

#define  SPI_I2SCTLR_CKPL                           ((uint16_t)0x0008)            /*!< steady state clock polarity */

#define  SPI_I2SCTLR_I2SSTD                         ((uint16_t)0x0030)            /*!< I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCTLR_I2SSTD_0                       ((uint16_t)0x0010)            /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SSTD_1                       ((uint16_t)0x0020)            /*!< Bit 1 */

#define  SPI_I2SCTLR_PCMSM                          ((uint16_t)0x0080)            /*!< PCM frame synchronization */

#define  SPI_I2SCTLR_I2SOM                          ((uint16_t)0x0300)            /*!< I2SOM[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCTLR_I2SOM_0                        ((uint16_t)0x0100)            /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SOM_1                        ((uint16_t)0x0200)            /*!< Bit 1 */
									         
#define  SPI_I2SCTLR_I2SEN                          ((uint16_t)0x0400)            /*!< I2S Enable */
#define  SPI_I2SCTLR_I2SSEL                         ((uint16_t)0x0800)            /*!< I2S mode selection */

/******************  Bit definition for SPI_I2SCKP register  *******************/
#define  SPI_I2SCKP_DIV                             ((uint16_t)0x00FF)            /*!< I2S Linear prescaler */
#define  SPI_I2SCKP_OF                              ((uint16_t)0x0100)            /*!< Odd factor for the prescaler */
#define  SPI_I2SCKP_MCKOE                           ((uint16_t)0x0200)            /*!< Master Clock Output Enable */

// 레지스터 정의
enum
{
	CTLR1 = 0, CTLR2, STR, DTR,
	CPR, RCR, TCR, I2SCTLR,
	I2SCKP
};

#endif