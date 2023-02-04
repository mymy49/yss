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

#ifndef YSS_MOD_WIZNET_IETHERNET__H_
#define YSS_MOD_WIZNET_IETHERNET__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class WiznetSocket;

class iEthernet : public Mutex
{
  private:
	void (*mCallbackLinkup)(bool linkup);
	int32_t  mThreadIdLinkup;

  protected:
	WiznetSocket *mSocket[4];

	virtual void readRegister(uint16_t addr, void *des, int32_t  len) = 0;
	virtual void writeRegister(uint16_t addr, void *src, int32_t  len) = 0;

	virtual void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len) = 0;
	virtual void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len) = 0;

  public:
	struct IpConfig
	{
		uint8_t macAddress[6];
		uint8_t gatewayAddress[4];
		uint8_t subnetMask[4];
		uint8_t ipAddress[4];
	};
	
	iEthernet(void);
	~iEthernet(void);
	
	void setCallbackLinkup(void (*callback)(bool), uint32_t stackSize);
	void process(void);
	
	virtual error setIpConfig(const IpConfig &config) = 0;
	virtual bool isLinkup(void) = 0;
	virtual bool command(uint8_t socketNumber, uint8_t command) = 0;
	virtual error sendSocketData(uint8_t socketNumber, void *src, uint16_t count) = 0;
	virtual error receiveSocketData(uint8_t socketNumber, void *des, uint16_t count) = 0;
	virtual uint16_t getTxFreeBufferSize(uint8_t socketNumber) = 0;
	virtual uint16_t getRxReceivedSize(uint8_t socketNumber) = 0;
	virtual bool setSocketInterruptEnable(uint8_t socketNumber, bool enable) = 0;
	virtual void setSocket(uint8_t socketNumber, WiznetSocket &socket) = 0;
	virtual bool isWorking(void) = 0;
	virtual uint8_t getSocketLength(void) = 0;
	virtual void setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip) = 0;
	virtual bool setSocketMode(uint8_t socketNumber, uint8_t protocol, uint8_t flag) = 0;
	virtual void setSocketPort(uint8_t socketNumber, uint16_t port) = 0;
	virtual void setSocketDestinationPort(uint8_t socketNumber, uint16_t port) = 0;
	virtual uint8_t getSocketCommand(uint8_t socketNumber) = 0;
	virtual uint8_t getSocketStatus(uint8_t socketNumber) = 0;
};

#endif
