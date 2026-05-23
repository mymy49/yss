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

NuvotonCanFd::NuvotonCanFd(const Drv::setup_t drvSetup, const setup_t setup) : CanFd(drvSetup)
{
	mDev = setup.dev;
	mRxFifo0 = nullptr;
	mTxFifo = nullptr;
	mStdFilter = nullptr;
	mRxBuffer = nullptr;
}

error_t NuvotonCanFd::initialize(config_t config)
{
	NuvotonCanFd::malloc_t malloc = 
	{
		0,	//uint8_t stdFilterCount;
		0,	//uint8_t extFilterCount;
		64,	//uint8_t rxFifoCount0;
		0,	//uint8_t rxFifoCount1;
		8,	//uint8_t rxBufferCount;
		1,	//uint8_t txEventFifo;
		1,	//uint8_t txFifoCount;
		1	//uint8_t txBufferCount;
	};
	
	if(malloc.stdFilterCount > 128 || malloc.extFilterCount > 64 || malloc.rxFifoCount0 > 64 || malloc.rxFifoCount1 > 64 || malloc.txEventFifo > 32 || (malloc.txFifoCount + malloc.txBufferCount) > 32)
		return error_t::OVERSIZE;

	uint32_t addr = 0;

	mDev->CCCR = CANFD_CCCR_INIT_Msk;
	mDev->CCCR |= CANFD_CCCR_CCE_Msk;

	setBitData(mDev->CCCR, config.fdOperaiton, CANFD_CCCR_FDOE_Pos);

	mDev->TXESC = 0x07;
	setThreeFieldsData(mDev->RXESC,	CANFD_RXESC_F0DS_Msk, 0x7, CANFD_RXESC_F0DS_Pos, 
									CANFD_RXESC_F1DS_Msk, 0x7, CANFD_RXESC_F1DS_Pos, 
									CANFD_RXESC_RBDS_Msk, 0x7, CANFD_RXESC_RBDS_Pos);

	setFourFieldsData(mDev->DBTP,	CANFD_DBTP_DBRP_Msk, config.dbrp, CANFD_DBTP_DBRP_Pos, 
									CANFD_DBTP_DTSEG1_Msk, config.dtseg1, CANFD_DBTP_DTSEG1_Pos, 
									CANFD_DBTP_DTSEG2_Msk, config.dtseg2, CANFD_DBTP_DTSEG2_Pos, 
									CANFD_DBTP_DSJW_Msk, config.dsjw, CANFD_DBTP_DSJW_Pos);

	setFourFieldsData(mDev->NBTP,	CANFD_NBTP_NBRP_Msk, config.nbrp, CANFD_NBTP_NBRP_Pos, 
									CANFD_NBTP_NTSEG1_Msk, config.ntseg1, CANFD_NBTP_NTSEG1_Pos, 
									CANFD_NBTP_NTSEG2_Msk, config.ntseg2, CANFD_NBTP_NTSEG2_Pos, 
									CANFD_NBTP_NSJW_Msk, config.nsjw, CANFD_NBTP_NSJW_Pos);
	
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

	mStdFilter = (stdFilter_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->SIDFC,	CANFD_SIDFC_LSS_Msk, malloc.stdFilterCount, CANFD_SIDFC_LSS_Pos, 
									CANFD_SIDFC_FLSSA_Msk, addr, CANFD_SIDFC_FLSSA_Pos) ;

	addr += malloc.stdFilterCount;
	mExtFilter = (extFilter_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->XIDFC,	CANFD_XIDFC_LSE_Msk, malloc.extFilterCount, CANFD_XIDFC_LSE_Pos, 
									CANFD_XIDFC_FLESA_Msk, addr, CANFD_XIDFC_FLESA_Pos) ;

	addr += 2 * malloc.extFilterCount;
	
	mRxFifo0 = (rxBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setTwoFieldsData(mDev->RXF0C,	CANFD_RXF0C_F0S_Msk, malloc.rxFifoCount0, CANFD_RXF0C_F0S_Pos, 
									CANFD_RXF0C_F0SA_Msk, addr, CANFD_RXF0C_F0SA_Pos) ;

	addr += 18 * malloc.rxFifoCount0;

	setTwoFieldsData(mDev->RXF1C,	CANFD_RXF1C_F1S_Msk, malloc.rxFifoCount1, CANFD_RXF1C_F1S_Pos, 
									CANFD_RXF1C_F1SA_Msk, addr, CANFD_RXF1C_F1SA_Pos) ;

	addr += 18 * malloc.rxFifoCount1;
	
	mRxBuffer = (rxBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setFieldData(mDev->RXBC, CANFD_RXBC_RBSA_Msk, addr, CANFD_RXBC_RBSA_Pos);
	
	addr += 18 * malloc.rxBufferCount;

	setTwoFieldsData(mDev->TXEFC,	CANFD_TXEFC_EFS_Msk, malloc.txEventFifo, CANFD_TXEFC_EFS_Pos, 
									CANFD_TXEFC_EFSA_Msk, addr, CANFD_TXEFC_EFSA_Pos) ;
	
	addr += 2 * malloc.txEventFifo;
	
	mTxFifo = (txBuffer_t*)((uint32_t)mDev + 0x200 + (addr << 2));
	setThreeFieldsData(mDev->TXBC,	CANFD_TXBC_TFQS_Msk, malloc.txFifoCount, CANFD_TXBC_TFQS_Pos, 
									CANFD_TXBC_NDTB_Msk, malloc.txBufferCount, CANFD_TXBC_NDTB_Pos,
									CANFD_TXBC_TBSA_Msk, addr, CANFD_TXBC_TBSA_Pos) ;
	
	addr += 18 * (malloc.txFifoCount + malloc.txBufferCount);

	if(addr >= 1536)
		return error_t::OVERSIZE;

	mDev->CCCR &= ~(CANFD_CCCR_INIT_Msk | CANFD_CCCR_CCE_Msk);

	return error_t::ERROR_NONE;
}

void NuvotonCanFd::sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc)
{
	txBuffer_t txb = {0, };
	
	txb.id = (id & 0x7FF) << 18;
	txb.dlc = dlc;
	if(dlc > 8)
		dlc = 8;

	memcpy(txb.data, src, dlc);

	*mTxFifo = txb;
	mDev->TXBAR = 1;

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

	return clk / (tq * (1 + bs1 + bs2));
}

float NuvotonCanFd::getSamplePoint(void)
{
	uint32_t bs1 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG1_Msk, CANFD_NBTP_NTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->NBTP, CANFD_NBTP_NTSEG2_Msk, CANFD_NBTP_NTSEG2_Pos) + 1;

	return (float)(1 + bs1) / (float)(1 + bs1 + bs2);
}

uint32_t NuvotonCanFd::getDataBuadrate(void)
{
	uint32_t clk = getClockFrequency();
	uint32_t tq = getFieldData(mDev->DBTP, CANFD_DBTP_DBRP_Msk, CANFD_DBTP_DBRP_Pos) + 1;
	uint32_t bs1 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG1_Msk, CANFD_DBTP_DTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG2_Msk, CANFD_DBTP_DTSEG2_Pos) + 1;

	return clk / (tq * (1 + bs1 + bs2));
}

float NuvotonCanFd::getDataSamplePoint(void)
{
	uint32_t bs1 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG1_Msk, CANFD_DBTP_DTSEG1_Pos) + 1;
	uint32_t bs2 = getFieldData(mDev->DBTP, CANFD_DBTP_DTSEG2_Msk, CANFD_DBTP_DTSEG2_Pos) + 1;
	
	return (float)(1 + bs1) / (float)(1 + bs1 + bs2);
}

#endif

