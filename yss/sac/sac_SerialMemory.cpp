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

#include <sac/SerialMemory.h>

namespace sac
{
bool SerialMemory::write(unsigned int addr, unsigned char src)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned char))
	{
		rt = writeBytes(addr, &src, sizeof(unsigned char));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, signed char src)
{
	bool rt;

	if (getSize() > addr + sizeof(signed char))
	{
		rt = writeBytes(addr, &src, sizeof(signed char));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, unsigned short src)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned short))
	{
		rt = writeBytes(addr, &src, sizeof(unsigned short));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, signed short src)
{
	bool rt;

	if (getSize() > addr + sizeof(signed short))
	{
		rt = writeBytes(addr, &src, sizeof(signed short));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, unsigned int src)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned int))
	{
		rt = writeBytes(addr, &src, sizeof(unsigned int));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, signed int src)
{
	bool rt;

	if (getSize() > addr + sizeof(signed int))
	{
		rt = writeBytes(addr, &src, sizeof(signed int));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, unsigned long src)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned long))
	{
		rt = writeBytes(addr, &src, sizeof(unsigned long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, signed long src)
{
	bool rt;

	if (getSize() > addr + sizeof(signed long))
	{
		rt = writeBytes(addr, &src, sizeof(signed long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, float src)
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

bool SerialMemory::write(unsigned int addr, double src)
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

bool SerialMemory::write(unsigned int addr, unsigned long long src)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned long long))
	{
		rt = writeBytes(addr, &src, sizeof(unsigned long long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::write(unsigned int addr, signed long long src)
{
	bool rt;

	if (getSize() > addr + sizeof(signed long long))
	{
		rt = writeBytes(addr, &src, sizeof(signed long long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, unsigned char &des)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned char))
	{
		rt = readBytes(addr, &des, sizeof(unsigned char));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, signed char &des)
{
	bool rt;

	if (getSize() > addr + sizeof(signed char))
	{
		rt = readBytes(addr, &des, sizeof(signed char));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, unsigned short &des)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned short))
	{
		rt = readBytes(addr, &des, sizeof(unsigned short));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, signed short &des)
{
	bool rt;

	if (getSize() > addr + sizeof(signed short))
	{
		rt = readBytes(addr, &des, sizeof(signed short));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, unsigned int &des)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned int))
	{
		rt = readBytes(addr, &des, sizeof(unsigned int));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, signed int &des)
{
	bool rt;

	if (getSize() > addr + sizeof(signed int))
	{
		rt = readBytes(addr, &des, sizeof(signed int));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, unsigned long &des)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned long))
	{
		rt = readBytes(addr, &des, sizeof(unsigned long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, signed long &des)
{
	bool rt;

	if (getSize() > addr + sizeof(signed long))
	{
		rt = readBytes(addr, &des, sizeof(signed long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, float &des)
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

bool SerialMemory::read(unsigned int addr, double &des)
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

bool SerialMemory::read(unsigned int addr, unsigned long long &des)
{
	bool rt;

	if (getSize() > addr + sizeof(unsigned long long))
	{
		rt = readBytes(addr, &des, sizeof(unsigned long long));
	}
	else
	{
		return false;
	}

	return rt;
}

bool SerialMemory::read(unsigned int addr, signed long long &des)
{
	bool rt;

	if (getSize() > addr + sizeof(signed long long))
	{
		rt = readBytes(addr, &des, sizeof(signed long long));
	}
	else
	{
		return false;
	}

	return rt;
}
}