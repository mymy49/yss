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

#ifndef YSS_DRV_UART__REG__H_
#define YSS_DRV_UART__REG__H_

/*******************  Bit definition for USART_STR register  *******************/
#define  USART_STR_PE                               ((uint16_t)0x0001)            /*!< Parity Error */
#define  USART_STR_FE                               ((uint16_t)0x0002)            /*!< Framing Error */
#define  USART_STR_NE                               ((uint16_t)0x0004)            /*!< Noise Error Flag */
#define  USART_STR_ORE                              ((uint16_t)0x0008)            /*!< OverRun Error */
#define  USART_STR_IDLEF                            ((uint16_t)0x0010)            /*!< IDLE Line Detected Flag*/
#define  USART_STR_RBNE                             ((uint16_t)0x0020)            /*!< Read Data Buffer Not Empty */
#define  USART_STR_TC                               ((uint16_t)0x0040)            /*!< Transmission Complete */
#define  USART_STR_TBE                              ((uint16_t)0x0080)            /*!< Transmit Data Buffer Empty */
#define  USART_STR_LBDF                             ((uint16_t)0x0100)            /*!< LIN Break Detected Flag */
#define  USART_STR_CTSF                             ((uint16_t)0x0200)            /*!< CTS Flag */

/*******************  Bit definition for USART_DR register  *******************/
#define  USART_DR_DR                                ((uint16_t)0x01FF)            /*!< Data value */

/*******************  Bit definition for USART_BRR register *******************/
#define  USART_BRR_BRRF                             ((uint16_t)0x000F)            /*!< Fraction of USARTDIV */
#define  USART_BRR_BRRM                             ((uint16_t)0xFFF0)            /*!< Mantissa of USARTDIV */

/*******************  Bit definition for USART_CTLR1 register  *******************/
#define  USART_CTLR1_SBKCMD                         ((uint16_t)0x0001)            /*!< Send Break Command */
#define  USART_CTLR1_RWU                            ((uint16_t)0x0002)            /*!< Receiver Wakeup */
#define  USART_CTLR1_REN                            ((uint16_t)0x0004)            /*!< Receiver Enable */
#define  USART_CTLR1_TEN                            ((uint16_t)0x0008)            /*!< Transmitter Enable */
#define  USART_CTLR1_IDIE                           ((uint16_t)0x0010)            /*!< IDLE Interrupt Enable */
#define  USART_CTLR1_RBNEIE                         ((uint16_t)0x0020)            /*!< RBNE Interrupt Enable */
#define  USART_CTLR1_TCIE                           ((uint16_t)0x0040)            /*!< Transmission Complete Interrupt Enable */
#define  USART_CTLR1_TBEIE                          ((uint16_t)0x0080)            /*!< TBE Interrupt Enable */
#define  USART_CTLR1_PEIE                           ((uint16_t)0x0100)            /*!< PE Interrupt Enable */
#define  USART_CTLR1_PM                             ((uint16_t)0x0200)            /*!< Parity Selection */
#define  USART_CTLR1_PCEN                           ((uint16_t)0x0400)            /*!< Parity Control Enable */
#define  USART_CTLR1_WM                             ((uint16_t)0x0800)            /*!< Wakeup method */
#define  USART_CTLR1_WL                             ((uint16_t)0x1000)            /*!< Word Length */
#define  USART_CTLR1_UEN                            ((uint16_t)0x2000)            /*!< USART Enable */
#define  USART_CTLR1_OVER8                          ((uint16_t)0x8000)            /*!< USART Oversmapling 8-bits */??????

/******************  Bit definition for USART_CTLR2 register  *******************/
#define  USART_CTLR2_ADD                            ((uint16_t)0x000F)            /*!< Address of the USART node */
#define  USART_CTLR2_LBDL                           ((uint16_t)0x0020)            /*!< LIN Break Detection Length */
#define  USART_CTLR2_LBDIE                          ((uint16_t)0x0040)            /*!< LIN Break Detection Interrupt Enable */
#define  USART_CTLR2_LBCP                           ((uint16_t)0x0100)            /*!< Last Bit Clock pulse */
#define  USART_CTLR2_CPH                            ((uint16_t)0x0200)            /*!< Clock Phase */
#define  USART_CTLR2_CPL                            ((uint16_t)0x0400)            /*!< Clock Polarity */
#define  USART_CTLR2_CKEN                           ((uint16_t)0x0800)            /*!< Clock Enable */

#define  USART_CTLR2_STB                            ((uint16_t)0x3000)            /*!< STOP[1:0] bits (STOP bits) */
#define  USART_CTLR2_STB_0                          ((uint16_t)0x1000)            /*!< Bit 0 */
#define  USART_CTLR2_STB_1                          ((uint16_t)0x2000)            /*!< Bit 1 */
									        
#define  USART_CTLR2_LMEN                           ((uint16_t)0x4000)            /*!< LIN Mode Enable */

/******************  Bit definition for USART_CTLR3 register  *******************/
#define  USART_CTLR3_ERIE                           ((uint16_t)0x0001)            /*!< Error Interrupt Enable */
#define  USART_CTLR3_IREN                           ((uint16_t)0x0002)            /*!< IrDA Mode Enable */
#define  USART_CTLR3_IRLP                           ((uint16_t)0x0004)            /*!< IrDA Low-Power */
#define  USART_CTLR3_HDEN                           ((uint16_t)0x0008)            /*!< Half-Duplex Enable */
#define  USART_CTLR3_NACK                           ((uint16_t)0x0010)            /*!< Smartcard NACK Enable */
#define  USART_CTLR3_SCEN                           ((uint16_t)0x0020)            /*!< Smartcard Mode Enable */
#define  USART_CTLR3_DENR                           ((uint16_t)0x0040)            /*!< DMA Enable For Receiver */
#define  USART_CTLR3_DENT                           ((uint16_t)0x0080)            /*!< DMA Enable For Transmitter */
#define  USART_CTLR3_RTSEN                          ((uint16_t)0x0100)            /*!< RTS Enable */
#define  USART_CTLR3_CTSEN                          ((uint16_t)0x0200)            /*!< CTS Enable */
#define  USART_CTLR3_CTSIE                          ((uint16_t)0x0400)            /*!< CTS Interrupt Enable */
#define  USART_CTLR3_ONEBIT                         ((uint16_t)0x0800)            /*!< One Bit method */?????

/******************  Bit definition for USART_GTPR register  ******************/
#define  USART_GTPR_PSC                             ((uint16_t)0x00FF)            /*!< PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_PSC_0                           ((uint16_t)0x0001)            /*!< Bit 0 */
#define  USART_GTPR_PSC_1                           ((uint16_t)0x0002)            /*!< Bit 1 */
#define  USART_GTPR_PSC_2                           ((uint16_t)0x0004)            /*!< Bit 2 */
#define  USART_GTPR_PSC_3                           ((uint16_t)0x0008)            /*!< Bit 3 */
#define  USART_GTPR_PSC_4                           ((uint16_t)0x0010)            /*!< Bit 4 */
#define  USART_GTPR_PSC_5                           ((uint16_t)0x0020)            /*!< Bit 5 */
#define  USART_GTPR_PSC_6                           ((uint16_t)0x0040)            /*!< Bit 6 */
#define  USART_GTPR_PSC_7                           ((uint16_t)0x0080)            /*!< Bit 7 */

#define  USART_GTPR_GT                              ((uint16_t)0xFF00)            /*!< Guard time value */

// 레지스터 정의


#endif
