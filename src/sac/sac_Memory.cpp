/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/Memory.h>

error_t Memory::write(uint32_t addr, uint8_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint8_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint8_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, int8_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(int8_t))
	{
		rt = writeBytes(addr, &src, sizeof(int8_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, uint16_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint16_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint16_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, int16_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(int16_t))
	{
		rt = writeBytes(addr, &src, sizeof(int16_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, uint32_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint32_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint32_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, int32_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(int32_t))
	{
		rt = writeBytes(addr, &src, sizeof(int32_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, float src)
{
	error_t rt;

	if (getSize() > addr + sizeof(float))
	{
		rt = writeBytes(addr, &src, sizeof(float));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, double src)
{
	error_t rt;

	if (getSize() > addr + sizeof(double))
	{
		rt = writeBytes(addr, &src, sizeof(double));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, uint64_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint64_t))
	{
		rt = writeBytes(addr, &src, sizeof(uint64_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::write(uint32_t addr, int64_t src)
{
	error_t rt;

	if (getSize() > addr + sizeof(int64_t))
	{
		rt = writeBytes(addr, &src, sizeof(int64_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, uint8_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint8_t))
	{
		rt = readBytes(addr, &des, sizeof(uint8_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, int8_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(int8_t))
	{
		rt = readBytes(addr, &des, sizeof(int8_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, uint16_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint16_t))
	{
		rt = readBytes(addr, &des, sizeof(uint16_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, int16_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(int16_t))
	{
		rt = readBytes(addr, &des, sizeof(int16_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, uint32_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint32_t))
	{
		rt = readBytes(addr, &des, sizeof(uint32_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;
	}

	return rt;
}

error_t Memory::read(uint32_t addr, int32_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(int32_t))
	{
		rt = readBytes(addr, &des, sizeof(int32_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;

	}

	return rt;
}

error_t Memory::read(uint32_t addr, float &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(float))
	{
		rt = readBytes(addr, &des, sizeof(float));
	}
	else
	{
		return error_t::OUT_OF_RANGE;

	}

	return rt;
}

error_t Memory::read(uint32_t addr, double &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(double))
	{
		rt = readBytes(addr, &des, sizeof(double));
	}
	else
	{
		return error_t::OUT_OF_RANGE;

	}

	return rt;
}

error_t Memory::read(uint32_t addr, uint64_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(uint64_t))
	{
		rt = readBytes(addr, &des, sizeof(uint64_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;

	}

	return rt;
}

error_t Memory::read(uint32_t addr, int64_t &des)
{
	error_t rt;

	if (getSize() > addr + sizeof(int64_t))
	{
		rt = readBytes(addr, &des, sizeof(int64_t));
	}
	else
	{
		return error_t::OUT_OF_RANGE;

	}

	return rt;
}
