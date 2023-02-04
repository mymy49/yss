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

#ifndef YSS_SAC_SERIAL_MEMORY__H_
#define YSS_SAC_SERIAL_MEMORY__H_

#include <stdint.h>

namespace sac
{
class SerialMemory
{
  protected:
	virtual uint32_t getSize(void) = 0;

  public:
	virtual bool writeBytes(uint32_t addr, void *src, uint32_t size) = 0;
	virtual bool readBytes(uint32_t addr, void *des, uint32_t size) = 0;

	bool write(uint32_t addr, uint8_t src);
	bool write(uint32_t addr, int8_t src);
	bool write(uint32_t addr, uint16_t src);
	bool write(uint32_t addr, int16_t src);
	bool write(uint32_t addr, uint32_t src);
	bool write(uint32_t addr, int32_t src);
	bool write(uint32_t addr, float src);
	bool write(uint32_t addr, double src);
	bool write(uint32_t addr, uint64_t src);
	bool write(uint32_t addr, int64_t src);

	bool read(uint32_t addr, uint8_t &des);
	bool read(uint32_t addr, int8_t &des);
	bool read(uint32_t addr, uint16_t &des);
	bool read(uint32_t addr, int16_t &des);
	bool read(uint32_t addr, uint32_t &des);
	bool read(uint32_t addr, int32_t &des);
	bool read(uint32_t addr, float &des);
	bool read(uint32_t addr, double &des);
	bool read(uint32_t addr, uint64_t &des);
	bool read(uint32_t addr, int64_t &des);
};
}

#endif