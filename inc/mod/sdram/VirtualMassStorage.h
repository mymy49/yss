/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_MOD_VIRTUAL_MASS_STORAGE__H_
#define	YSS_MOD_VIRTUAL_MASS_STORAGE__H_

#include <sac/MassStorage.h>
#include <stdint.h>

namespace mod
{
namespace sdram
{
	class VirtualMassStorage : public MassStorage
	{
		bool writeBlock(uint32_t block, void *src);
		bool readBlock(uint32_t block, void *des);
		uint32_t mBlockSize, mNumOfBlock;
		bool mInitFlag;
		int8_t *mMemroy;

	public:
		VirtualMassStorage(void);
		uint32_t getBlockSize(void);
		uint32_t getNumOfBlock(void);
		bool initialize(uint32_t blockSize, uint32_t numOfBlock);
	};
}
}


#endif
