/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bluetooth/Ble4p0.h>
#include <hal/BleRadio.h>
#include <yss/debug.h>
#include <string.h>
#include <bluetooth/Ble4p0.h>
#include <util/runtime.h>

#pragma GCC optimize("O1")

Ble4p0::Ble4p0()
{
	mStatus = STATUS_ADVERTISING;
	mResponseFlag = false;
	mEmptyPdu[0] = 0x05;
	mEmptyPdu[1] = 0x00;
	mHeartBeatCount = 0;
	mLossCount = 0;
	mEventCounter = 0;
}

error_t Ble4p0::initialize(config_t config)
{
	mDev = &config.dev;
	mConnectingFlag = false;
	mChannel = 37;

	mDev->initializeAsBle();
	mDev->setSpeed(BleRadio::BLE_1MBPS);
	mDev->setBleStack(this);

	mPeriAddr[0] = 0xAA;
	mPeriAddr[1] = 0xBB;
	mPeriAddr[2] = 0xCC;
	mPeriAddr[3] = 0xDD;
	mPeriAddr[4] = 0xEE;
	mPeriAddr[5] = 0xCF;

	uint8_t len = strlen(config.deviceName);
	uint8_t *des = (uint8_t*)mDev->getAdvBuffer();
	uint8_t *src = (uint8_t*)mPeriAddr;

	*des++ = BLE_ADV_PDU_TYPE_SCAN_RSP | 0x40;
	*des++ = len + 8;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;

	*des++ = len + 1;
	*des++ = BLE_GAP_AD_TYPE_COMPLETE_LOCAL_NAME;
	memcpy(des, config.deviceName, len);
	memset(&mFeature, 0, sizeof(mFeature));

	mConfig = &config;

	runThread();

	return error_t::ERROR_NONE;
}

ble_adv_pdu_type_t Ble4p0::parseRxPacketType()
{
	uint8_t *buf = (uint8_t*)mDev->getRxBuffer();

	if(ble_adv_pdu_type_t(buf[0] & 0x0F) == BLE_ADV_PDU_TYPE_SCAN_REQ &&
		buf[1] == 12 &&
		buf[8] == mPeriAddr[0] &&
		buf[9] == mPeriAddr[1] &&
		buf[10] == mPeriAddr[2] &&
		buf[11] == mPeriAddr[3] &&
		buf[12] == mPeriAddr[4] &&
		buf[13] == mPeriAddr[5])
	{
		return BLE_ADV_PDU_TYPE_SCAN_REQ;
	}
	else if(ble_adv_pdu_type_t(buf[0] & 0x0F) == BLE_ADV_PDU_TYPE_CONNECT_IND &&
		buf[1] == 34 &&
		buf[8] == mPeriAddr[0] &&
		buf[9] == mPeriAddr[1] &&
		buf[10] == mPeriAddr[2] &&
		buf[11] == mPeriAddr[3] &&
		buf[12] == mPeriAddr[4] &&
		buf[13] == mPeriAddr[5])
	{
		mStatus = STATUS_PREPARE_CONNECTING;
		return BLE_ADV_PDU_TYPE_CONNECT_IND;
	}
	else
		return BLE_ADV_PDU_TYPE_INVALID;
}

void Ble4p0::parseConnectionInfo()
{
}

void Ble4p0::updateAnchorTime(uint8_t length)
{
	if(mConnectingFlag)
	{
		mLastAnchorPointTime = runtime::getUsec() - ((uint64_t)length + 10) * 8;
	}
	else
		mLastAnchorPointTime = runtime::getUsec();// - ((uint64_t)length + 10);
}

void* Ble4p0::getEmptyPduBuffer()
{
	return mEmptyPdu;
}

void Ble4p0::updateEmptyPduBuffer(uint8_t header)
{
	// 올바른 Stateless SN/NESN 핑퐁 공식:
	// 내 TX의 SN은 상대방이 요구하는 NESN과 같아야 함: (header & 0x04) << 1
	// 내 TX의 NESN은 상대방이 보낸 SN의 반대여야 함: ((header & 0x08) >> 1) ^ 0x04
	mEmptyPdu[0] = ((header & 0x04) << 1) | (((header & 0x08) >> 1) ^ 0x04) | 0x01;
}

bool Ble4p0::isHaveResponseData()
{
	bool flag = mResponseFlag;
	mResponseFlag = false;
	return flag;
}

void Ble4p0::updateTxBufferHeader(uint8_t header)
{
	uint8_t *txBuf = (uint8_t*)mDev->getTxBuffer();
	// LLID는 기존 버퍼의 값을 유지하고, SN과 NESN만 최신 수신 헤더를 기반으로 업데이트!
	*txBuf = (*txBuf & 0x03) | ((header & 0x04) << 1) | (((header & 0x08) >> 1) ^ 0x04);
}


uint8_t* Ble4p0::getRxMacAddress()
{
	return &((uint8_t*)mDev->getRxBuffer())[2];
}

uint16_t Ble4p0::getRxCount()
{
	return (uint16_t)((uint8_t*)mDev->getRxBuffer())[1];
}

ble_adv_pdu_type_t Ble4p0::getRxPacketType()
{
	return (ble_adv_pdu_type_t)(*(uint8_t*)mDev->getRxBuffer() & 0x0F);
}

void Ble4p0::resetTxLength(uint8_t initLength)
{
	mTxLen = initLength;
}

void Ble4p0::setTxAdv(ble_adv_pdu_type_t type, bool txAdd, bool rxAdd)
{
	*(uint8_t*)mDev->getTxBuffer() = (uint8_t)type | txAdd << 6 | rxAdd << 7;
}

void Ble4p0::copyTxMacAddress()
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[2];
	uint8_t *src = mPeriAddr;

	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
}

void Ble4p0::appendTxAdvType(ble_gap_ad_type_t type, void* src, uint8_t length)
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[mTxLen + 2];
	*des++ = length + 1;
	*des++ = type;
	memcpy(des, src, length);

	mTxLen += length + 2;
}

void Ble4p0::appendTxData(void* src, uint8_t length)
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[mTxLen + 2];
	memcpy(des, src, length);
	mTxLen += length;
}

void Ble4p0::updatePayloadLength()
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[1];
	*des = mTxLen;	
}

void Ble4p0::setTxAdv(ble_gap_adv_flag_t type1, ble_gap_adv_flag_t type2, ble_gap_adv_flag_t type3, ble_gap_adv_flag_t type4)
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[10];
	*des = (uint8_t)(type1 | type2 | type3 | type4);
}

void Ble4p0::calculateNextChannel()
{
	int32_t index;
	int32_t bit;

	mUnmappedChannel = (mUnmappedChannel + mHopIncrement) % 37;

	index = mUnmappedChannel / 8;
	bit = mUnmappedChannel % 8;
	
	if(mChannelMap[index] & 1 << bit)
	{
		mChannel = mUnmappedChannel;
	}
	else
	{
		int32_t remappingIndex = mUnmappedChannel % mAbleMapCount;
		int32_t count = 0;

		for(int32_t i = 0; i < 37; i++)
		{
			if(mChannelMap[i/8] & (1 << (i % 8)))
			{
				if(count == remappingIndex)
				{
					mChannel = i;
					break;
				}
				count++;
			}
		}	
	}
}

void Ble4p0::calculateNextAnchorPoint()
{
	mAnchorPointTime = mLastAnchorPointTime + (uint64_t)mInterval * 1250;
}

void Ble4p0::handleDataChannelPdu()
{
	uint8_t *rxBuf = (uint8_t*)mDev->getRxBuffer();
	uint8_t currentRxSn = (rxBuf[0] & 0x08) >> 3;

	// 스마트폰이 못 받았다고 판단하여 재전송(Retransmission)한 중복 패킷인 경우, Payload 처리를 무시함!
	if (currentRxSn == mLastRxSn)
		return;
		
	mLastRxSn = currentRxSn;

	switch(rxBuf[0] & 0x03)
	{
	default :
	case 1 : // Empty PDU
		
		break;
	
	case 2 : // Start of an L2CAP message
		debug_printf("L2CAP\n");
		break;

	case 3 : // Control PDU
		handleControlPdu(rxBuf);
		break;
	}
}

void Ble4p0::handleControlPdu(uint8_t *rxBuf)
{
	uint8_t len, opcode;
	uint8_t *buf;

	debug_printf("OPCODE = %d\n", rxBuf[2]);

	switch(rxBuf[2])
	{
	default :
		break;
	
	case LL_CONNECTION_UPDATE_IND :
		buf = &((uint8_t*)mDev->getRxBuffer())[3];
		mConnectionUpdatingInterval = ((ble_ll_conn_update_ind_t*)buf)->interval;
		mConnectionUpdatingWindowSize = ((ble_ll_conn_update_ind_t*)buf)->window_size;
		mConnectionUpdatingWindowOffset = ((ble_ll_conn_update_ind_t*)buf)->window_offset;
		mInstant = ((ble_ll_conn_update_ind_t*)buf)->instant;
		mConnectionUpdatingLatency = ((ble_ll_conn_update_ind_t*)buf)->latency;
		mConnectionUpdatingTimeout = ((ble_ll_conn_update_ind_t*)buf)->timeout;
		mStatus  = STATUS_CONNECTION_UPDATE;
		break;

	case LL_FEATURE_REQ :
		resetTxLength(0);
		setTxDataChannelPduHeader(rxBuf[0], true); // 필수!
		opcode = LL_FEATURE_RSP;
		appendTxData(&opcode, 1);
		appendTxData(&mFeature, sizeof(ble_ll_feature_pdu_t));
		updatePayloadLength();
		mResponseFlag = true;
		break;

	case LL_VERSION_IND :
	{
		resetTxLength(0);
		setTxDataChannelPduHeader(rxBuf[0], true);
		opcode = LL_VERSION_IND;
		appendTxData(&opcode, 1);
		appendTxData((void*)mConfig->llVersionInd, sizeof(ll_version_ind_t));
		updatePayloadLength();
		mResponseFlag = true;
	}
	break;

	case LL_LENGTH_REQ : // LL_LENGTH_REQ (0x14)
		// 스마트폰이 최대 전송 길이를 물어봄! 기본값(27바이트)으로 응답합니다.
		resetTxLength(0);
		setTxDataChannelPduHeader(rxBuf[0], true); // 필수: TX 버퍼의 헤더(LLID 등) 세팅
		
		opcode = LL_LENGTH_RSP; // Opcode 0x15 = LL_LENGTH_RSP
		appendTxData(&opcode, 1);
		opcode = 27; // MaxRxOctets (기본 27)
		appendTxData(&opcode, 1);
		opcode = 0;
		appendTxData(&opcode, 1);
		opcode = 0x48; // MaxRxTime (기본 328us = 0x0148) 하위 바이트
		appendTxData(&opcode, 1);
		opcode = 0x01; // 상위 바이트
		appendTxData(&opcode, 1);
		opcode = 27; // MaxTxOctets 
		appendTxData(&opcode, 1);
		opcode = 0;
		appendTxData(&opcode, 1);
		opcode = 0x48; // MaxTxTime
		appendTxData(&opcode, 1);
		opcode = 0x01;
		appendTxData(&opcode, 1);
		updatePayloadLength();
		mResponseFlag = true;
		break;
		
	}	
}

void Ble4p0::setTxDataChannelPduHeader(uint8_t rxHeader, bool ack)
{
	uint8_t *txBuf = (uint8_t*)mDev->getTxBuffer();

	if(ack)
	{
		// Empty PDU와 동일한 완벽한 상태 추적 공식 적용!
		*txBuf = (rxHeader & 0x03) | ((rxHeader & 0x04) << 1) | (((rxHeader & 0x08) >> 1) ^ 0x04);
	}
	else
	{
		*txBuf = (rxHeader & 0x03);
	}
}

uint8_t Ble4p0::getRxAdvCount()
{
	return ((uint8_t*)mDev->getRxBuffer())[8];
}

uint8_t Ble4p0::getRxAdvType()
{
	return ((uint8_t*)mDev->getRxBuffer())[9];
}

void Ble4p0::thread()
{
	uint8_t advFlag, retryCnt = 0;
	uint8_t *buf;
	ble_ll_conn_req_data_t *lld;
	uint32_t crcInit;

	mStatus = STATUS_ENTER_TO_ADVERTISING;

	while(1)
	{
		switch(mStatus)
		{
		case STATUS_ENTER_TO_ADVERTISING :
			mDev->setAdvLinkParameters();
			resetTxLength(6);

			if(mType == TYPE_CONNECTABLE)
				setTxAdv(BLE_ADV_PDU_TYPE_ADV_IND, true, false);
			else
				setTxAdv(BLE_ADV_PDU_TYPE_ADV_NONCONN_IND, true, false);

			copyTxMacAddress();

			advFlag = BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE | BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED;
			appendTxAdvType(BLE_GAP_AD_TYPE_FLAGS, &advFlag, 1);
			updatePayloadLength();

			mConnectingFlag = false;
			mStatus = STATUS_ADVERTISING;
			break;

		case STATUS_ADVERTISING :
			thread::delay(10);

			if(37 > mChannel || mChannel > 39)
				mChannel = 37;

			mDev->setChannel(mChannel++); 
			mDev->transmitAdv(2000);
			break;

		case STATUS_PREPARE_CONNECTING :
			buf = (uint8_t*)mDev->getRxBuffer();
			lld = (ble_ll_conn_req_data_t*)&buf[14]; 
			crcInit = (uint32_t)lld->crc_init[2] << 16 | (uint32_t)lld->crc_init[1] << 8 | (uint32_t)lld->crc_init[0];
			mDev->setConnectionLinkParameters(lld->access_address, crcInit);
			mHopIncrement = lld->hop_and_sca & 0x1F;

			mChannelMap[0] = lld->channel_map[0];
			mChannelMap[1] = lld->channel_map[1];
			mChannelMap[2] = lld->channel_map[2];
			mChannelMap[3] = lld->channel_map[3];
			mChannelMap[4] = lld->channel_map[4];

			mInterval = lld->interval;
			mWindowSize = lld->window_size;
			mLatency = lld->latency;
			mTimeout = lld->timeout;

			for(int32_t i = 0; i < 37;i++)
			{
				if(mChannelMap[i/8] & (1 << (i % 8)))
					mAbleMapCount++;
			}

			mAnchorPointTime = mLastAnchorPointTime + ((uint64_t)lld->window_offset + 1) * 1250;

			mCentralAddr[0] = buf[2];
			mCentralAddr[1] = buf[3];
			mCentralAddr[2] = buf[4];
			mCentralAddr[3] = buf[5];
			mCentralAddr[4] = buf[6];
			mCentralAddr[5] = buf[7];

			mChannel = 0;
			mUnmappedChannel = 0;
			mAbleMapCount = 0;
			mHeartBeatCount = 0;
			mLossCount = 0;
			mEventCounter = 0;

			mStatus  = STATUS_WAIT_FIRST_ANCHOR_POINT;
			retryCnt = 6;
			mConnectingFlag = true;
			mLastRxSn = 0xFF;
			break;

		case STATUS_WAIT_FIRST_ANCHOR_POINT :
			calculateNextChannel();
			mDev->setChannel(mChannel); 
			thread::delayUs(mAnchorPointTime - runtime::getUsec() - 1000);

			if(mDev->receive((uint32_t)mWindowSize * 1250 + 1000) == error_t::ERROR_NONE)
			{
				mHeartBeatCount++;
				mStatus = STATUS_CONNECTED;
				handleDataChannelPdu();
			}
			else
			{
				mLossCount++;
				mLastAnchorPointTime = mAnchorPointTime;

				if(retryCnt > 0)
					retryCnt--;
				else
					mStatus = STATUS_ENTER_TO_ADVERTISING;
			}
			calculateNextAnchorPoint();
			mEventCounter++;
			break;

		case STATUS_CONNECTION_UPDATE :
			calculateNextChannel();
			mDev->setChannel(mChannel);
			thread::delayUs(mAnchorPointTime - runtime::getUsec() - 1000);
			
			if(mDev->receive(3000) == error_t::ERROR_NONE)
			{
				mHeartBeatCount++;
				handleDataChannelPdu();
			}
			else
			{
				mLossCount++;
				mLastAnchorPointTime = mAnchorPointTime;

				if(retryCnt > 0)
					retryCnt--;
				else
					mStatus = STATUS_ENTER_TO_ADVERTISING;
			}
			calculateNextAnchorPoint();

			mEventCounter++;
			if(mInstant == mEventCounter)
			{
				mAnchorPointTime = mLastAnchorPointTime + ((uint64_t)mConnectionUpdatingWindowOffset + mInterval) * 1250;
				mInterval = mConnectionUpdatingInterval;
				mWindowSize = mConnectionUpdatingWindowSize;
				mLatency = mConnectionUpdatingLatency;
				mTimeout = mConnectionUpdatingTimeout;
				mStatus = STATUS_WAIT_FIRST_ANCHOR_POINT;
			}
			break;

		case STATUS_CONNECTED :
			calculateNextChannel();
			mDev->setChannel(mChannel); 
			thread::delayUs(mAnchorPointTime - runtime::getUsec() - 1000);

			if(mDev->receive(3000) == error_t::ERROR_NONE)
			{
				mHeartBeatCount++;
				retryCnt = 20;
				handleDataChannelPdu();
			}
			else
			{
				mLossCount++;
				mLastAnchorPointTime = mAnchorPointTime;

				if(retryCnt > 0)
				{
					retryCnt--;
				}
				else
				{
					mStatus = STATUS_ENTER_TO_ADVERTISING;
				}
			}
			calculateNextAnchorPoint();
			mEventCounter++;
			break;

		default :
			mConnectingFlag = false;
			mStatus = STATUS_ENTER_TO_ADVERTISING;
			break;
		}
	}
}

