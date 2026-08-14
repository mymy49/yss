/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M46x_SUBFAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonCanFd.h>
#include <yss/scheduler.h>
#include <yss/reg.h>
#include <yss/debug.h>
#include <util/Timeout.h>
#include <string.h>
#include <__debug_stdio.h>

/**
 * @file drv_canfd_nuvoton.cpp
 * @brief CAN FD target-specific driver source file for Nuvoton.
 */

NuvotonCanFd::NuvotonCanFd(const Drv::setup_t drvSetup, const setup_t setup) : CanFd(drvSetup)
{
	// Store references to registers and buffer pointers.
	mDev = setup.dev;
	mRxFifo0 = nullptr;
	mTxFifo = nullptr;
	mStdFilter = nullptr;
	mRxBuffer = nullptr;
}

error_t NuvotonCanFd::initialize(config_t config)
{
	stdFilter_t stdFilter;

	// Predefined RAM allocation sizes for CAN FD buffers.
	NuvotonCanFd::malloc_t malloc = 
	{
		1,	//uint8_t stdFilterCount;
		1,	//uint8_t extFilterCount;
		64,	//uint8_t rxFifoCount0;
		0,	//uint8_t rxFifoCount1;
		8,	//uint8_t rxBufferCount;
		1,	//uint8_t txEventFifo;
		1,	//uint8_t txFifoCount;
		1	//uint8_t txBufferCount;
	};
	
	// Validate total allocated sizes are within limits.
	if(malloc.stdFilterCount > 128 || malloc.extFilterCount > 64 || malloc.rxFifoCount0 > 64 || malloc.rxFifoCount1 > 64 || malloc.txEventFifo > 32 || (malloc.txFifoCount + malloc.txBufferCount) > 32)
		return error_t::OVERSIZE;

	uint32_t addr = 0;

	// Enter Initialization mode (INIT) and unlock protected registers (CCE).
	mDev->CCCR = CANFD_CCCR_INIT_Msk;
	mDev->CCCR |= CANFD_CCCR_CCE_Msk;

	// Set FD mode operation.
	setBitData(mDev->CCCR, config.fdOperaiton, CANFD_CCCR_FDOE_Pos);

	// Configure Tx/Rx Buffer element payload sizes (64 bytes maximum).
	mDev->TXESC = 0x07;
	setThreeFieldsData(mDev->RXESC,	CANFD_RXESC_F0DS_Msk, 0x7, CANFD_RXESC_F0DS_Pos, 
									CANFD_RXESC_F1DS_Msk, 0x7, CANFD_RXESC_F1DS_Pos, 
									CANFD_RXESC_RBDS_Msk, 0x7, CANFD_RXESC_RBDS_Pos);

	// Configure Data bit timing prescaler, segment lengths, and synchronization jump width.
	setFourFieldsData(mDev->DBTP,	CANFD_DBTP_DBRP_Msk, config.dbrp, CANFD_DBTP_DBRP_Pos, 
									CANFD_DBTP_DTSEG1_Msk, config.dtseg1, CANFD_DBTP_DTSEG1_Pos, 
									CANFD_DBTP_DTSEG2_Msk, config.dtseg2, CANFD_DBTP_DTSEG2_Pos, 
									CANFD_DBTP_DSJW_Msk, config.dsjw, CANFD_DBTP_DSJW_Pos);

	// Configure Nominal bit timing parameters.
	setFourFieldsData(mDev->NBTP,	CANFD_NBTP_NBRP_Msk, config.nbrp, CANFD_NBTP_NBRP_Pos, 
									CANFD_NBTP_NTSEG1_Msk, config.ntseg1, CANFD_NBTP_NTSEG1_Pos, 
									CANFD_NBTP_NTSEG2_Msk, config.ntseg2, CANFD_NBTP_NTSEG2_Pos, 
									CANFD_NBTP_NSJW_Msk, config.nsjw, CANFD_NBTP_NSJW_Pos);
	
	// Configure optional loopback or silent testing modes.
	if(config.enableLoopback || config.enableSilent)
	{
		setBitData(mDev->CCCR, true, CANFD_CCCR_TEST_Pos);
		
		if(config.enableSilent)
			setFieldData(mDev->TEST, CANFD_TEST_TX_Msk, 3, CANFD_TEST_TX_Pos);
		else
			setFieldData(mDev->TEST, CANFD_TEST_TX_Msk, 0, CANFD_TEST_TX_Pos);

		setBitData(mDev->TEST, config.enableLoopback, CANFD_TEST_LBCK_Pos);
	}
	else 
		setBitData(mDev->CCCR, false, CANFD_CCCR_TEST_Pos);

	// Calculate and assign message RAM offsets for standard filters.
	mStdFilter = (stdFilter_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->SIDFC,	CANFD_SIDFC_LSS_Msk, malloc.stdFilterCount, CANFD_SIDFC_LSS_Pos, 
									CANFD_SIDFC_FLSSA_Msk, addr, CANFD_SIDFC_FLSSA_Pos) ;

	stdFilter.sfid1 = 0x000;
	stdFilter.sfid2 = 0x000;
	stdFilter.sft = 0x3;
	stdFilter.sfec = 1;
	stdFilter.rsv = 0;
	*mStdFilter = stdFilter;

	// Calculate and assign message RAM offsets for extended filters.
	addr += malloc.stdFilterCount;
	mExtFilter = (extFilter_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->XIDFC,	CANFD_XIDFC_LSE_Msk, malloc.extFilterCount, CANFD_XIDFC_LSE_Pos, 
									CANFD_XIDFC_FLESA_Msk, addr, CANFD_XIDFC_FLESA_Pos) ;

	// Calculate and assign offsets for RxFIFO 0.
	addr += 2 * malloc.extFilterCount;
	mRxFifo0 = (rxBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->RXF0C,	CANFD_RXF0C_F0S_Msk, malloc.rxFifoCount0, CANFD_RXF0C_F0S_Pos, 
									CANFD_RXF0C_F0SA_Msk, addr, CANFD_RXF0C_F0SA_Pos) ;

	// Calculate and assign offsets for RxFIFO 1.
	addr += 18 * malloc.rxFifoCount0;
	setTwoFieldsData(mDev->RXF1C,	CANFD_RXF1C_F1S_Msk, malloc.rxFifoCount1, CANFD_RXF1C_F1S_Pos, 
									CANFD_RXF1C_F1SA_Msk, addr, CANFD_RXF1C_F1SA_Pos) ;

	// Calculate and assign offsets for dedicated Rx buffer.
	addr += 18 * malloc.rxFifoCount1;
	mRxBuffer = (rxBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setFieldData(mDev->RXBC, CANFD_RXBC_RBSA_Msk, addr, CANFD_RXBC_RBSA_Pos);
	
	// Calculate and assign offsets for Tx Event FIFO.
	addr += 18 * malloc.rxBufferCount;
	setTwoFieldsData(mDev->TXEFC,	CANFD_TXEFC_EFS_Msk, malloc.txEventFifo, CANFD_TXEFC_EFS_Pos, 
									CANFD_TXEFC_EFSA_Msk, addr, CANFD_TXEFC_EFSA_Pos) ;
	
	// Calculate and assign offsets for TxFIFO.
	addr += 2 * malloc.txEventFifo;
	mTxFifo = (txBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setThreeFieldsData(mDev->TXBC,	CANFD_TXBC_TFQS_Msk, malloc.txFifoCount, CANFD_TXBC_TFQS_Pos, 
									CANFD_TXBC_NDTB_Msk, malloc.txBufferCount, CANFD_TXBC_NDTB_Pos,
									CANFD_TXBC_TBSA_Msk, addr, CANFD_TXBC_TBSA_Pos) ;
	
	addr += 18 * (malloc.txFifoCount + malloc.txBufferCount);

	// Verify allocated RAM offsets do not exceed available CAN FD SRAM capacity.
	if(addr >= 1536)
		return error_t::OVERSIZE;

	// Exit initialization mode to start CAN FD normal operation.
	mDev->CCCR &= ~(CANFD_CCCR_INIT_Msk | CANFD_CCCR_CCE_Msk);

	return error_t::ERROR_NONE;
}

void NuvotonCanFd::sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc)
{
	txBuffer_t txb = {0, };
	
	// Shift standard ID to correct bit position.
	txb.id = (id & 0x7FF) << 18;
	txb.dlc = dlc;
	if(dlc > 8)
		dlc = 8;

	memcpy(txb.data, src, dlc);

	// Copy to transmission FIFO buffer.
	*mTxFifo = txb;
	mDev->TXBAR = 1;

	// Poll wait until transmission is verified by TXBTO register status.
	while(mDev->TXBTO == 0)
		thread::yield();
}

void NuvotonCanFd::sendXtdCanMessage(uint32_t id, uint8_t *src, uint8_t dlc)
{
	txBuffer_t txb = {0, };
	
	txb.id = id & 0x1FFFFFFF;
	txb.dlc = dlc;
	txb.xtd = true;
	if(dlc > 8)
		dlc = 8;

	memcpy(txb.data, src, dlc);

	*mTxFifo = txb;
	mDev->TXBAR = 1;

	while(mDev->TXBTO == 0)
		thread::yield();
}

void NuvotonCanFd::sendStdCanfdMessage(uint16_t id, uint8_t *src, dlc_t dlc, bool brs)
{
	txBuffer_t txb = {0, };
	
	txb.id = (id & 0x7FF) << 18;
	txb.brs = brs;
	txb.dlc = dlc;
	txb.fdf = true;

	memcpy(txb.data, src, mDlcTable[dlc]);

	*mTxFifo = txb;
	mDev->TXBAR = 1;

	while(mDev->TXBTO == 0)
		thread::yield();
}

void NuvotonCanFd::sendXtdCanfdMessage(uint32_t id, uint8_t *src, dlc_t dlc, bool brs)
{
	txBuffer_t txb = {0, };
	
	txb.id = id & 0x1FFFFFFF;
	txb.brs = brs;
	txb.dlc = dlc;
	txb.fdf = true;
	txb.xtd = true;

	memcpy(txb.data, src, mDlcTable[dlc]);

	*mTxFifo = txb;
	mDev->TXBAR = 1;

	while(mDev->TXBTO == 0)
		thread::yield();
}

bool NuvotonCanFd::isNewRxMessage(void)
{
	// Query FIFO fill level to verify new message arrival.
	return getFieldData(mDev->RXF0S, CANFD_RXF0S_F0FL_Msk, CANFD_RXF0S_F0FL_Pos) > 0;
}

canMsg_t NuvotonCanFd::getNewRxCanMessage(void)
{
	canMsg_t msg;
	uint32_t getIndex = getFieldData(mDev->RXF0S, CANFD_RXF0S_F0GI_Msk, CANFD_RXF0S_F0GI_Pos);
	rxBuffer_t rxb = mRxFifo0[getIndex];
		
	msg.xtd = rxb.xtd;
	msg.dlc = rxb.dlc;
	if(msg.dlc > 8)
		msg.dlc = 8;

	memcpy(msg.data, rxb.data, msg.dlc);
	
	if(msg.xtd)
		msg.id = rxb.id;
	else
		msg.id = rxb.id >> 18;

	// Acknowledge read index to release the entry in hardware FIFO.
	mDev->RXF0A = getIndex;
	return msg; 
}

canfdMsg_t NuvotonCanFd::getNewRxCanfdMessage(void)
{
	canfdMsg_t msg;
	uint32_t getIndex = getFieldData(mDev->RXF0S, CANFD_RXF0S_F0GI_Msk, CANFD_RXF0S_F0GI_Pos);
	rxBuffer_t rxb = mRxFifo0[getIndex];
		
	msg.xtd = rxb.xtd;
	msg.dlc = (dlc_t)rxb.dlc;
	msg.fdf = rxb.fdf;

	memcpy(msg.data, rxb.data, mDlcTable[msg.dlc]);
	
	if(msg.xtd)
		msg.id = rxb.id;
	else
		msg.id = rxb.id >> 18;

	// Acknowledge read index to release the entry in hardware FIFO.
	mDev->RXF0A = getIndex;
	return msg; 
}

void NuvotonCanFd::isr0(void)
{
}

uint32_t NuvotonCanFd::getBaudrate(void)
{
	uint32_t clk = getClockFrequency();
	uint32_t tq = getFieldData(mDev->NBTP, CANFD_NBTP_NBRP_Msk, CANFD_NBTP_NBRP_Pos) + 1;
	uint32_t bs1 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG1_Msk, CANFD_NBTP_NTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG2_Msk, CANFD_NBTP_NTSEG2_Pos) + 1;

	// Return nominal baudrate based on clock prescaler and seg values.
	return clk / (tq * (1 + bs1 + bs2));
}

float NuvotonCanFd::getSamplePoint(void)
{
	uint32_t bs1 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG1_Msk, CANFD_NBTP_NTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG2_Msk, CANFD_NBTP_NTSEG2_Pos) + 1;

	// Calculate and return nominal sample point percentage.
	return (float)(1 + bs1) / (float)(1 + bs1 + bs2);
}

uint32_t NuvotonCanFd::getDataBuadrate(void)
{
	uint32_t clk = getClockFrequency();
	uint32_t tq = getFieldData(mDev->DBTP, CANFD_DBTP_DBRP_Msk, CANFD_DBTP_DBRP_Pos) + 1;
	uint32_t bs1 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG1_Msk, CANFD_DBTP_DTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG2_Msk, CANFD_DBTP_DTSEG2_Pos) + 1;

	// Return data phase baudrate based on DBTP settings.
	return clk / (tq * (1 + bs1 + bs2));
}

float NuvotonCanFd::getDataSamplePoint(void)
{
	uint32_t bs1 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG1_Msk, CANFD_DBTP_DTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG2_Msk, CANFD_DBTP_DTSEG2_Pos) + 1;
	
	// Calculate and return data phase sample point percentage.
	return (float)(1 + bs1) / (float)(1 + bs1 + bs2);
}

#endif


