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

#ifndef YSS_MOD_WIZNET_IETHERNET__H_
#define YSS_MOD_WIZNET_IETHERNET__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class WiznetSocket;

class iEthernet : public Mutex
{
  private:
	void (*mCallbackLinkup)(bool linkup);
	int mThreadIdLinkup;

  protected:
	WiznetSocket *mSocket[4];

	virtual void readRegister(unsigned short addr, void *des, int len) = 0;
	virtual void writeRegister(unsigned short addr, void *src, int len) = 0;

	virtual void writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len) = 0;
	virtual void readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len) = 0;

  public:
	struct IpConfig
	{
		unsigned char macAddress[6];
		unsigned char gatewayAddress[4];
		unsigned char subnetMask[4];
		unsigned char ipAddress[4];
	};
	
	iEthernet(void);
	~iEthernet(void);
	
	void setCallbackLinkup(void (*callback)(bool), unsigned int stackSize);
	void process(void);
	
	virtual error setIpConfig(const IpConfig &config) = 0;
	virtual bool isLinkup(void) = 0;
	virtual bool command(unsigned char socketNumber, unsigned char command) = 0;
	virtual error sendSocketData(unsigned char socketNumber, void *src, unsigned short count) = 0;
	virtual error receiveSocketData(unsigned char socketNumber, void *des, unsigned short count) = 0;
	virtual unsigned short getTxFreeBufferSize(unsigned char socketNumber) = 0;
	virtual unsigned short getRxReceivedSize(unsigned char socketNumber) = 0;
	virtual bool setSocketInterruptEnable(unsigned char socketNumber, bool enable) = 0;
	virtual void setSocket(unsigned char socketNumber, WiznetSocket &socket) = 0;
	virtual bool isWorking(void) = 0;
	virtual unsigned char getSocketLength(void) = 0;
	virtual void setSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip) = 0;
	virtual bool setSocketMode(unsigned char socketNumber, unsigned char protocol, unsigned char flag) = 0;
	virtual void setSocketPort(unsigned char socketNumber, unsigned short port) = 0;
	virtual void setSocketDestinationPort(unsigned char socketNumber, unsigned short port) = 0;
	virtual unsigned char getSocketCommand(unsigned char socketNumber) = 0;
	virtual unsigned char getSocketStatus(unsigned char socketNumber) = 0;
};

#endif
