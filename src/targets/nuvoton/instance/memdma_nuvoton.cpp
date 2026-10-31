/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file memdma_nuvoton.cpp
 * @brief DMA-based memory operations initialization for Nuvoton target.
 */

#include <yss.h>
#include <config.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY) || defined(__MA35H0_FAMILY)

#include <std_ext/string.h>

#if defined(__MA35H0_FAMILY)
/*---------------------------------------------------------------------------------------------------------*/
/*  Operation Mode Constant Definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_OP_STOP        0x00000000UL            /*!<DMA Stop Mode  \hideinitializer */
#define PDMA_OP_BASIC       0x00000001UL            /*!<DMA Basic Mode  \hideinitializer */
#define PDMA_OP_SCATTER     0x00000002UL            /*!<DMA Scatter-gather Mode  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Data Width Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_WIDTH_8        0x00000000UL            /*!<DMA Transfer Width 8-bit  \hideinitializer */
#define PDMA_WIDTH_16       0x00001000UL            /*!<DMA Transfer Width 16-bit  \hideinitializer */
#define PDMA_WIDTH_32       0x00002000UL            /*!<DMA Transfer Width 32-bit  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Address Attribute Constant Definitions                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_SAR_INC        0x00000000UL            /*!<DMA SAR increment  \hideinitializer */
#define PDMA_SAR_FIX        0x00000300UL            /*!<DMA SAR fix address  \hideinitializer */
#define PDMA_DAR_INC        0x00000000UL            /*!<DMA DAR increment  \hideinitializer */
#define PDMA_DAR_FIX        0x00000C00UL            /*!<DMA DAR fix address  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Burst Mode Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_REQ_SINGLE     0x00000004UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_REQ_BURST      0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

#define PDMA_BURST_128      0x00000000UL            /*!<DMA Burst 128 Transfers  \hideinitializer */
#define PDMA_BURST_64       0x00000010UL            /*!<DMA Burst 64 Transfers  \hideinitializer */
#define PDMA_BURST_32       0x00000020UL            /*!<DMA Burst 32 Transfers  \hideinitializer */
#define PDMA_BURST_16       0x00000030UL            /*!<DMA Burst 16 Transfers  \hideinitializer */
#define PDMA_BURST_8        0x00000040UL            /*!<DMA Burst 8 Transfers  \hideinitializer */
#define PDMA_BURST_4        0x00000050UL            /*!<DMA Burst 4 Transfers  \hideinitializer */
#define PDMA_BURST_2        0x00000060UL            /*!<DMA Burst 2 Transfers  \hideinitializer */
#define PDMA_BURST_1        0x00000070UL            /*!<DMA Burst 1 Transfers  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Table Interrupt Disable Constant Definitions                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_TBINTDIS_ENABLE  (0x0UL<<PDMA_DSCT_CTL_TBINTDIS_Pos)  /*!<DMA Table Interrupt Enabled   \hideinitializer */
#define PDMA_TBINTDIS_DISABLE (0x1UL<<PDMA_DSCT_CTL_TBINTDIS_Pos)  /*!<DMA Table Interrupt Disabled  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Peripheral Transfer Mode Constant Definitions                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_MEM                0UL /*!<DMA Connect to Memory \hideinitializer */
#define PDMA_UART0_TX           4UL /*!<DMA Connect to UART0_TX \hideinitializer */
#define PDMA_UART0_RX           5UL /*!<DMA Connect to UART0_RX \hideinitializer */
#define PDMA_UART1_TX           6UL /*!<DMA Connect to UART1_TX \hideinitializer */
#define PDMA_UART1_RX           7UL /*!<DMA Connect to UART1_RX \hideinitializer */
#define PDMA_UART2_TX           8UL /*!<DMA Connect to UART2_TX \hideinitializer */
#define PDMA_UART2_RX           9UL /*!<DMA Connect to UART2_RX \hideinitializer */
#define PDMA_UART3_TX           10UL /*!<DMA Connect to UART3_TX \hideinitializer */
#define PDMA_UART3_RX           11UL /*!<DMA Connect to UART3_RX \hideinitializer */
#define PDMA_UART4_TX           12UL /*!<DMA Connect to UART4_TX \hideinitializer */
#define PDMA_UART4_RX           13UL /*!<DMA Connect to UART4_RX \hideinitializer */
#define PDMA_UART5_TX           14UL /*!<DMA Connect to UART5_TX \hideinitializer */
#define PDMA_UART5_RX           15UL /*!<DMA Connect to UART5_RX \hideinitializer */
#define PDMA_UART6_TX           16UL /*!<DMA Connect to UART6_TX \hideinitializer */
#define PDMA_UART6_RX           17UL /*!<DMA Connect to UART6_RX \hideinitializer */
#define PDMA_UART7_TX           18UL /*!<DMA Connect to UART7_TX \hideinitializer */
#define PDMA_UART7_RX           19UL /*!<DMA Connect to UART7_RX \hideinitializer */
#define PDMA_UART8_TX           20UL /*!<DMA Connect to UART8_TX \hideinitializer */
#define PDMA_UART8_RX           21UL /*!<DMA Connect to UART8_RX \hideinitializer */
#define PDMA_UART9_TX           22UL /*!<DMA Connect to UART9_TX \hideinitializer */
#define PDMA_UART9_RX           23UL /*!<DMA Connect to UART9_RX \hideinitializer */
#define PDMA_UART10_TX          24UL /*!<DMA Connect to UART10_TX \hideinitializer */
#define PDMA_UART10_RX          25UL /*!<DMA Connect to UART10_RX \hideinitializer */
#define PDMA_UART11_TX          26UL /*!<DMA Connect to UART11_TX \hideinitializer */
#define PDMA_UART11_RX          27UL /*!<DMA Connect to UART11_RX \hideinitializer */
#define PDMA_UART12_TX          28UL /*!<DMA Connect to UART12_TX \hideinitializer */
#define PDMA_UART12_RX          29UL /*!<DMA Connect to UART12_RX \hideinitializer */
#define PDMA_UART13_TX          30UL /*!<DMA Connect to UART13_TX \hideinitializer */
#define PDMA_UART13_RX          31UL /*!<DMA Connect to UART13_RX \hideinitializer */
#define PDMA_UART14_TX          32UL /*!<DMA Connect to UART14_TX \hideinitializer */
#define PDMA_UART14_RX          33UL /*!<DMA Connect to UART14_RX \hideinitializer */
#define PDMA_UART15_TX          34UL /*!<DMA Connect to UART15_TX \hideinitializer */
#define PDMA_UART15_RX          35UL /*!<DMA Connect to UART15_RX \hideinitializer */
#define PDMA_UART16_TX          36UL /*!<DMA Connect to UART16_TX \hideinitializer */
#define PDMA_UART16_RX          37UL /*!<DMA Connect to UART16_RX \hideinitializer */
#define PDMA_QSPI0_TX           54UL /*!<DMA Connect to QSPI0_TX \hideinitializer */
#define PDMA_QSPI0_RX           55UL /*!<DMA Connect to QSPI0_RX \hideinitializer */
#define PDMA_QSPI1_TX           56UL /*!<DMA Connect to QSPI1_TX \hideinitializer */
#define PDMA_QSPI1_RX           57UL /*!<DMA Connect to QSPI1_RX \hideinitializer */
#define PDMA_SPI0_TX            60UL /*!<DMA Connect to SPI0_TX \hideinitializer */
#define PDMA_SPI0_RX            61UL /*!<DMA Connect to SPI0_RX \hideinitializer */
#define PDMA_SPI1_TX            62UL /*!<DMA Connect to SPI1_TX \hideinitializer */
#define PDMA_SPI1_RX            63UL /*!<DMA Connect to SPI1_RX \hideinitializer */
#define PDMA_SPI2_TX            64UL /*!<DMA Connect to SPI2_TX \hideinitializer */
#define PDMA_SPI2_RX            65UL /*!<DMA Connect to SPI2_RX \hideinitializer */
#define PDMA_SPI3_TX            66UL /*!<DMA Connect to SPI3_TX \hideinitializer */
#define PDMA_SPI3_RX            67UL /*!<DMA Connect to SPI3_RX \hideinitializer */
#define PDMA_I2C0_TX            70UL /*!<DMA Connect to I2C0_TX \hideinitializer */
#define PDMA_I2C0_RX            71UL /*!<DMA Connect to I2C0_RX \hideinitializer */
#define PDMA_I2C1_TX            72UL /*!<DMA Connect to I2C1_TX \hideinitializer */
#define PDMA_I2C1_RX            73UL /*!<DMA Connect to I2C1_RX \hideinitializer */
#define PDMA_I2C2_TX            74UL /*!<DMA Connect to I2C2_TX \hideinitializer */
#define PDMA_I2C2_RX            75UL /*!<DMA Connect to I2C2_RX \hideinitializer */
#define PDMA_I2C3_TX            76UL /*!<DMA Connect to I2C3_TX \hideinitializer */
#define PDMA_I2C3_RX            77UL /*!<DMA Connect to I2C3_RX \hideinitializer */
#define PDMA_I2C4_TX            78UL /*!<DMA Connect to I2C4_TX \hideinitializer */
#define PDMA_I2C4_RX            79UL /*!<DMA Connect to I2C4_RX \hideinitializer */
#define PDMA_I2C5_TX            80UL /*!<DMA Connect to I2C5_TX \hideinitializer */
#define PDMA_I2C5_RX            81UL /*!<DMA Connect to I2C5_RX \hideinitializer */
#define PDMA_I2S0_TX            86UL /*!<DMA Connect to I2S0_TX \hideinitializer */
#define PDMA_I2S0_RX            87UL /*!<DMA Connect to I2S0_RX \hideinitializer */
#define PDMA_I2S1_TX            88UL /*!<DMA Connect to I2S1_TX \hideinitializer */
#define PDMA_I2S1_RX            89UL /*!<DMA Connect to I2S1_RX \hideinitializer */
#define PDMA_TMR0               94UL /*!<DMA Connect to TMR0 \hideinitializer */
#define PDMA_TMR1               95UL /*!<DMA Connect to TMR1 \hideinitializer */
#define PDMA_TMR2               96UL /*!<DMA Connect to TMR2 \hideinitializer */
#define PDMA_TMR3               97UL /*!<DMA Connect to TMR3 \hideinitializer */
#define PDMA_TMR4               98UL /*!<DMA Connect to TMR4 \hideinitializer */
#define PDMA_TMR5               99UL /*!<DMA Connect to TMR5 \hideinitializer */
#define PDMA_TMR6               100UL /*!<DMA Connect to TMR6 \hideinitializer */
#define PDMA_TMR7               101UL /*!<DMA Connect to TMR7 \hideinitializer */
#define PDMA_TMR8               102UL /*!<DMA Connect to TMR8 \hideinitializer */
#define PDMA_TMR9               103UL /*!<DMA Connect to TMR9 \hideinitializer */
#define PDMA_TMR10              104UL /*!<DMA Connect to TMR10 \hideinitializer */
#define PDMA_TMR11              105UL /*!<DMA Connect to TMR11 \hideinitializer */
#define PDMA_EPWM0_P1_RX        110UL /*!<DMA Connect to EPWM0_P1_RX \hideinitializer */
#define PDMA_EPWM0_P2_RX        111UL /*!<DMA Connect to EPWM0_P2_RX \hideinitializer */
#define PDMA_EPWM0_P3_RX        112UL /*!<DMA Connect to EPWM0_P3_RX \hideinitializer */
#define PDMA_EPWM1_P1_RX        113UL /*!<DMA Connect to EPWM1_P1_RX \hideinitializer */
#define PDMA_EPWM1_P2_RX        114UL /*!<DMA Connect to EPWM1_P2_RX \hideinitializer */
#define PDMA_EPWM1_P3_RX        115UL /*!<DMA Connect to EPWM1_P3_RX \hideinitializer */
#define PDMA_EPWM2_P1_RX        116UL /*!<DMA Connect to EPWM2_P1_RX \hideinitializer */
#define PDMA_EPWM2_P2_RX        117UL /*!<DMA Connect to EPWM2_P2_RX \hideinitializer */
#define PDMA_EPWM2_P3_RX        118UL /*!<DMA Connect to EPWM2_P3_RX \hideinitializer */
#define PDMA_EPWM0_CH0_TX       122UL /*!<DMA Connect to EPWM0_CH0_TX \hideinitializer */
#define PDMA_EPWM0_CH1_TX       123UL /*!<DMA Connect to EPWM0_CH1_TX \hideinitializer */
#define PDMA_EPWM0_CH2_TX       124UL /*!<DMA Connect to EPWM0_CH2_TX \hideinitializer */
#define PDMA_EPWM0_CH3_TX       125UL /*!<DMA Connect to EPWM0_CH3_TX \hideinitializer */
#define PDMA_EPWM0_CH4_TX       126UL /*!<DMA Connect to EPWM0_CH4_TX \hideinitializer */
#define PDMA_EPWM0_CH5_TX       127UL /*!<DMA Connect to EPWM0_CH5_TX \hideinitializer */
#define PDMA_EPWM1_CH0_TX       128UL /*!<DMA Connect to EPWM1_CH0_TX \hideinitializer */
#define PDMA_EPWM1_CH1_TX       129UL /*!<DMA Connect to EPWM1_CH1_TX \hideinitializer */
#define PDMA_EPWM1_CH2_TX       130UL /*!<DMA Connect to EPWM1_CH2_TX \hideinitializer */
#define PDMA_EPWM1_CH3_TX       131UL /*!<DMA Connect to EPWM1_CH3_TX \hideinitializer */
#define PDMA_EPWM1_CH4_TX       132UL /*!<DMA Connect to EPWM1_CH4_TX \hideinitializer */
#define PDMA_EPWM1_CH5_TX       133UL /*!<DMA Connect to EPWM1_CH5_TX \hideinitializer */
#define PDMA_EPWM2_CH0_TX       134UL /*!<DMA Connect to EPWM2_CH0_TX \hideinitializer */
#define PDMA_EPWM2_CH1_TX       135UL /*!<DMA Connect to EPWM2_CH1_TX \hideinitializer */
#define PDMA_EPWM2_CH2_TX       136UL /*!<DMA Connect to EPWM2_CH2_TX \hideinitializer */
#define PDMA_EPWM2_CH3_TX       137UL /*!<DMA Connect to EPWM2_CH3_TX \hideinitializer */
#define PDMA_EPWM2_CH4_TX       138UL /*!<DMA Connect to EPWM2_CH4_TX \hideinitializer */
#define PDMA_EPWM2_CH5_TX       139UL /*!<DMA Connect to EPWM2_CH5_TX \hideinitializer */
#endif

Dma *gDma;

void initializeDmaCopy(void)
{
	gDma = yss::allocateDma();
	gDma->setSource(PDMA_MEM);
}

void memcpyd(void* des, void* src, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_8 |
		PDMA_SAR_INC |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		src					// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsetd(void* des, uint8_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_8 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsethwd(void* des, uint16_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_16 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsetwd(void* des, uint32_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_32 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

#endif

