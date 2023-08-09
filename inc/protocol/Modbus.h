////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_COMM_MODBUS__H_
#define YSS_MOD_COMM_MODBUS__H_

#include <yss/instance.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class Modbus : private Mutex
{
  private:
	Uart *mPeri;
	void (*setRx)(void);
	void (*setTx)(void);
	int16_t *mRcvBuf;
	int16_t *mMemory;
	void (*rcvHandler)(uint16_t addr, int16_t data);
	int32_t  mThreadId;
	uint16_t mMemoryDepth, mRcvBufSize;
	uint8_t mId, mCrcHi, mCrcLo;
	bool mSendFlag, mReceiveFlag;

	void calculateCrc(uint8_t byte);
	void calculateCrc(void *src, uint16_t size);
	void resetCrc(void);
	void responseReadInputRegister(uint16_t addr, uint16_t size);
	void responseWriteSingleRegister(uint16_t addr);
	void responseWriteMultiRegister(uint16_t addr, uint16_t size);

  public:
	struct Config
	{
		Uart &peri;
		uint32_t threadStacksize;
		void (*setRx)(void);
		void (*setTx)(void);
		void (*receiveHandler)(uint16_t addr, int16_t data);
	};

	Modbus(uint16_t rcvBufSize, uint16_t memoryDepth);
	bool initialize(Config config);
	void process(void);
	void setId(uint8_t id);
	void setData(uint16_t addr, int16_t data);
	int16_t getData(uint16_t addr);
	bool isReceived(void);
	bool isSent(void);
};

#endif

#endif

