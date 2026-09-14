/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_BLUETOOTH_BLE4p0__H_
#define YSS_BLUETOOTH_BLE4p0__H_

#include <yss/error.h>
#include <yss/Thread.h>
#include "types.h"

class BleRadio;

class Ble4p0 : private Thread
{
public :
	enum speed_t
	{
		BLE_1MBPS,
		BLE_2MBPS
	};

	enum type_t
	{
		TYPE_CONNECTABLE,
		TYPE_NON_CONNECTABLE,
	};

	struct config_t
	{
		BleRadio &dev;
		type_t deviceType;
		const char *deviceName;
		const ll_version_ind_t *llVersionInd;
	};

	enum status_t
	{
		STATUS_ADVERTISING,
		STATUS_WAIT_FIRST_ANCHOR_POINT,
		STATUS_CONNECTED,
		STATUS_FINDING_MAIN,
		STATUS_ENTER_TO_ADVERTISING,
	};

#pragma pack(push, 1)
	struct llData_t
	{
	    uint32_t accessAddress;
	    uint8_t  crcInit[3];
	    uint8_t  windowSize;
	    uint16_t windowOffset;
	    uint16_t interval;
	    uint16_t latency;
	    uint16_t timeout;
	    uint8_t  channelMap[5];
	    uint8_t  hopAndSca;
	};
#pragma pack(pop)

	Ble4p0();

	error_t initialize(config_t config);

	ble_adv_pdu_type_t parseRxPacketType();

	void parseConnectionInfo();

	void updateAnchorTime(uint8_t length);

	void* getEmptyPduBuffer();

	void updateEmptyPduBuffer(uint8_t header);

	bool isHaveResponseData();
	void updateTxBufferHeader(uint8_t header);

protected :
	uint8_t* getRxMacAddress();
	
	uint16_t getRxCount();

	error_t setTxCount(uint8_t count);

	ble_adv_pdu_type_t getRxPacketType();

	uint8_t getRxAdvCount();

	uint8_t getRxAdvType();

	void copyTxMacAddress();

	void resetTxLength(uint8_t initLength);

	void setTxAdv(ble_adv_pdu_type_t type, bool txAdd, bool RxAdd);

	void appendTxAdvType(ble_gap_ad_type_t type, void* src, uint8_t length);

	void appendTxData(void* src, uint8_t length);

	void updatePayloadLength();

	void setTxAdv(ble_gap_adv_flag_t type1, ble_gap_adv_flag_t type2 = (ble_gap_adv_flag_t)0, ble_gap_adv_flag_t type3 = (ble_gap_adv_flag_t)0, ble_gap_adv_flag_t type4 = (ble_gap_adv_flag_t)0);

	void calculateNextChannel();

	void calculateNextAnchorPoint();

	void handleDataChannelPdu();

	void handleControlPdu(uint8_t *rxBuf);

	void setTxDataChannelPduHeader(uint8_t rxHeader, bool ack);

private :
	BleRadio *mDev;
	uint8_t mPeriAddr[6];
	uint8_t mCentralAddr[6];
	uint8_t mTxLen;
	type_t mType;
	const char *mDeviceName;
	bool mConnectingFlag;
	llData_t mLinkLayerData;
	int32_t mChannel, mHopIncrement, mAbleMapCount;
	int32_t mUnmappedChannel;
	uint64_t mAnchorPointTime;
	uint64_t mLastAnchorPointTime, mDelay, mTime;
	status_t mStatus;
	uint8_t mEmptyPdu[2] __attribute__((aligned(4)));
	bool mResponseFlag;
	uint32_t mHeartBeatCount, mLossCount;
	ble_ll_feature_pdu_t mFeature;
	uint8_t mLastRxSn;
	config_t *mConfig;

	void thread() override;
};

#endif

