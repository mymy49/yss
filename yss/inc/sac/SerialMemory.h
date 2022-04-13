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

#ifndef YSS_SAC_SERIAL_MEMORY__H_
#define YSS_SAC_SERIAL_MEMORY__H_

namespace sac
{
class SerialMemory
{
  protected:
	virtual unsigned long getSize(void) = 0;

  public:
	virtual bool writeBytes(unsigned int addr, void *src, unsigned long size) = 0;
	virtual bool readBytes(unsigned int addr, void *des, unsigned long size) = 0;

	bool write(unsigned int addr, unsigned char src);
	bool write(unsigned int addr, signed char src);
	bool write(unsigned int addr, unsigned short src);
	bool write(unsigned int addr, signed short src);
	bool write(unsigned int addr, unsigned int src);
	bool write(unsigned int addr, signed int src);
	bool write(unsigned int addr, unsigned long src);
	bool write(unsigned int addr, signed long src);
	bool write(unsigned int addr, float src);
	bool write(unsigned int addr, double src);
	bool write(unsigned int addr, unsigned long long src);
	bool write(unsigned int addr, signed long long src);

	bool read(unsigned int addr, unsigned char &des);
	bool read(unsigned int addr, signed char &des);
	bool read(unsigned int addr, unsigned short &des);
	bool read(unsigned int addr, signed short &des);
	bool read(unsigned int addr, unsigned int &des);
	bool read(unsigned int addr, signed int &des);
	bool read(unsigned int addr, unsigned long &des);
	bool read(unsigned int addr, signed long &des);
	bool read(unsigned int addr, float &des);
	bool read(unsigned int addr, double &des);
	bool read(unsigned int addr, unsigned long long &des);
	bool read(unsigned int addr, signed long long &des);
};
}

#endif