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

#include <sac/SerialMemory.h>

namespace sac
{
bool SerialMemory::write(uint32_t addr, uint8_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(uint8_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint8_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, int8_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(int8_t))
	{
		rt = writeBytes(addr, &src, sizeof(int8_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, uint16_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(uint16_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint16_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, int16_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(int16_t))
	{
		rt = writeBytes(addr, &src, sizeof(int16_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, uint32_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(uint32_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint32_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, int32_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(int32_t))
	{
		rt = writeBytes(addr, &src, sizeof(int32_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, float src)
{
	bool rt;

	if (getSize() > addr + sizeof(float))
	{
		rt = writeBytes(addr, &src, sizeof(float));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, double src)
{
	bool rt;

	if (getSize() > addr + sizeof(double))
	{
		rt = writeBytes(addr, &src, sizeof(double));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, uint64_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(uint64_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint64_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(uint32_t addr, int64_t src)
{
	bool rt;

	if (getSize() > addr + sizeof(int64_t))
	{
		rt = writeBytes(addr, &src, sizeof(int64_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, uint8_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(uint8_t))
	{
		rt = readBytes(addr, &des, sizeof(uint8_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, int8_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(int8_t))
	{
		rt = readBytes(addr, &des, sizeof(int8_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, uint16_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(uint16_t))
	{
		rt = readBytes(addr, &des, sizeof(uint16_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, int16_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(int16_t))
	{
		rt = readBytes(addr, &des, sizeof(int16_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, uint32_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(uint32_t))
	{
		rt = readBytes(addr, &des, sizeof(uint32_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, int32_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(int32_t))
	{
		rt = readBytes(addr, &des, sizeof(int32_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, float &des)
{
	bool rt;

	if (getSize() > addr + sizeof(float))
	{
		rt = readBytes(addr, &des, sizeof(float));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, double &des)
{
	bool rt;

	if (getSize() > addr + sizeof(double))
	{
		rt = readBytes(addr, &des, sizeof(double));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, uint64_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(uint64_t))
	{
		rt = readBytes(addr, &des, sizeof(uint64_t));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(uint32_t addr, int64_t &des)
{
	bool rt;

	if (getSize() > addr + sizeof(int64_t))
	{
		rt = readBytes(addr, &des, sizeof(int64_t));
	}
	else
	{
		return false;
	}

	return rt;
}
}