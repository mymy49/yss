////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
	
	error initialize(void);

	error test(void);
	error restart(void);
	error getVersion(char *des);
	error updateApInformation(void);
	uint8_t getApCount(void);
	ApInfo* getApInfo(uint8_t index);
	void clearApInformation(void);
	error setMode(uint8_t mode);
	error enableMultipleConnection(bool en = true);
	error enableDhcp(uint8_t mode, bool en = true);
	error connect(char *ssid, char *passwd);
	error disconnect(void);
	error connectToTcpServer(Ip ip, uint16_t port);
	error close(void);
	error getIp(Ip &ip);
	error getGateway(Ip &ip);
	error getNetmask(Ip &ip);
	error enterTransparentTransmissionMode(bool en = true);
	
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

	virtual error send(void *src, uint32_t size) = 0;
	virtual int16_t getReceivedByte(void) = 0;
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

	threadId mId;
	bool mReadyFlag, mConnectedFlag, mIpFlag, mSocketConnectedFlag, mTransparentTransmissionModeFlag;
	void *mDestination;
	uint32_t mVar;
	uint8_t mApCount, mResult;
	ApInfo *mApInfo[32];

	void (*callbackError)(uint8_t command);
	void (*callbackConnect)(bool connected);

	error waitUntilComplete(uint32_t timeout);
	error waitUntilReadToSendData(uint32_t timeout);

	error sendCommand(const char *data);
	error sendCommand(const char *data, uint32_t value);
	error sendCommand(const char *data, uint32_t value1, uint32_t value2);
	error sendCommand(const char *data, const char *value1, const char *value2);

	void interpret_S(volatile char *src);
	void interpret_plus(volatile char *src);
	void interpret_W(volatile char *src);
	void interpret_C(volatile char *src);
};

#endif

