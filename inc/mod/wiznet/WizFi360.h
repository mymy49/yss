/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_WIZNET_WIZFI360__H_
#define YSS_MOD_WIZNET_WIZFI360__H_

#include <yss/error.h>
#include <yss/thread.h>
#include <util/ElapsedTime.h>

class WizFi360 : public Mutex
{
public:
	struct ApInfo
	{
		uint8_t encryptionMethod;
		char ssid[33];
		int8_t rssi;
		uint8_t mac[6];
		uint8_t channel;
		uint8_t wps;
	};

	struct Ip
	{
		uint8_t addr1;
		uint8_t addr2;
		uint8_t addr3;
		uint8_t addr4;
	};

	enum CMD
	{
		TEST = 0,
		RESTART = 1,
		GET_VERSION = 2,
		SET_MODE_CUR = 3,
		EN_MULTI_CONN = 4,
		EN_DHCP_CUR = 5,
		UPDATE_AP_INFO = 6,
		DISCONNECT = 7,
		CONNECT = 8,
		GET_CUR_IP = 9,
		GET_CUR_GATEWAY = 10,
		GET_CUR_NETMASK = 11,
		CONNECT_TCP_SERVER = 12,
		SEND_BUF = 13,
		ENTER_TRANSPARENT_TRANSMISSION_MODE = 14,
		CLOSE = 15,
	};

	enum MODE
	{
		STATION = 1,
		SOFT_AP = 2,
		STATION_SOFT_AP = 3,
	};

	WizFi360(void);

	~WizFi360(void);
	
	error_t test(void);

	error_t restart(void);

	error_t getVersion(char *des);

	error_t updateApInformation(void);

	uint8_t getApCount(void);

	ApInfo* getApInfo(uint8_t index);

	void clearApInformation(void);

	error_t setMode(uint8_t mode);

	error_t enableMultipleConnection(bool en = true);

	error_t enableDhcp(uint8_t mode, bool en = true);

	error_t connect(char *ssid, char *passwd);

	error_t disconnect(void);

	error_t connectToTcpServer(Ip ip, uint16_t port);

	error_t close(void);

	error_t getIp(Ip &ip);

	error_t getGateway(Ip &ip);

	error_t getNetmask(Ip &ip);

	error_t enterTransparentTransmissionMode(bool en = true);
	
	bool isConnected(void);

	bool isGotIp(void);

	bool isSocketConnected(void);

	void setCallbackError(void (*func)(uint8_t));

	void setCallbackConnect(void (*func)(bool));

	void process(void);

protected:
	uint8_t mCommand, mIndex;
	ElapsedTime mTimeout;
	char mDataBuf[64];

	error_t initialize(void);

	virtual error_t send(void *src, uint32_t size) = 0;
	
	virtual int16_t getRxByte(void) = 0;

	virtual void flush(void) = 0;

private:
	enum RESULT
	{
		WORKING = 0,
		TIMEOUT = 1,
		ERROR = 2,
		BUSY = 3,
		COMPLETE = 4,
		FAIL = 5,
		SEND_OK = 6,
	};

	threadId_t mId;
	bool mReadyFlag, mConnectedFlag, mIpFlag, mSocketConnectedFlag, mTransparentTransmissionModeFlag;
	void *mDestination;
	uint32_t mVar;
	uint8_t mApCount, mResult;
	ApInfo *mApInfo[32];

	void (*callbackError)(uint8_t command);
	void (*callbackConnect)(bool connected);

	error_t waitUntilComplete(uint32_t timeout);

	error_t waitUntilReadToSendData(uint32_t timeout);

	error_t sendCommand(const char *data);

	error_t sendCommand(const char *data, uint32_t value);

	error_t sendCommand(const char *data, uint32_t value1, uint32_t value2);

	error_t sendCommand(const char *data, const char *value1, const char *value2);

	void interpret_S(volatile char *src);

	void interpret_plus(volatile char *src);

	void interpret_W(volatile char *src);

	void interpret_C(volatile char *src);
};

#endif

