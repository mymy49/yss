////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.12.07~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_WIZNET_IETHERNET__H_
#define YSS_MOD_WIZNET_IETHERNET__H_

#include <yss/Mutex.h>

class iEthernet : public Mutex
{
  private:

  protected:
	void writeRegister(unsigned short addr, unsigned char data);
	void writeRegister(unsigned short addr, unsigned short data);
	void writeRegister(unsigned short addr, unsigned int data);

	void readRegister(unsigned short addr, unsigned char &data);
	void readRegister(unsigned short addr, unsigned short &data);
	void readRegister(unsigned short addr, unsigned int &data);

	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned char data);
	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned short data);
	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned int data);

	void readSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned char &data);
	void readSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned short &data);
	void readSocketRegister(unsigned char socketNumber, unsigned short addr, unsigned int &data);

	virtual void readRegister(unsigned short addr, void *des, int len) = 0;
	virtual void writeRegister(unsigned short addr, void *src, int len) = 0;

	virtual void writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len) = 0;
	virtual void readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len) = 0;

  public:
	iEthernet(void);

	virtual bool isWorking(void) = 0;
	virtual unsigned char getSocketLength(void) = 0;
	virtual void setSocketInterruptEn(bool en) = 0;
	virtual void setMacAddress(unsigned char *mac) = 0;
	virtual void getMacAddress(unsigned char *mac) = 0;
	virtual void setGatewayIpAddress(unsigned char *ip) = 0;
	virtual void getGatewayIpAddress(unsigned char *ip) = 0;
	virtual void setSubnetMaskAddress(unsigned char *mask) = 0;
	virtual void getSubnetMaskAddress(unsigned char *mask) = 0;
	virtual void setIpAddress(unsigned char *ip) = 0;
	virtual void getIpAddress(unsigned char *ip) = 0;
};

#endif