/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/thread.h>
#include <std_ext/malloc.h>
#include <mod/sdram/VirtualMassStorage.h>

namespace mod
{
namespace sdram
{
	VirtualMassStorage::VirtualMassStorage(void)
	{
		mInitFlag = false;
		mBlockSize = 0;
		mNumOfBlock = 0;
	}

	bool VirtualMassStorage::initialize(uint32_t blockSize, uint32_t numOfBlock) 
	{
		uint32_t size = blockSize * numOfBlock;

//		mMemroy = (int8_t*)lmalloc(size);
		mMemroy = new int8_t[size];
		if(mMemroy)
		{
			mBlockSize = blockSize;
			mNumOfBlock = numOfBlock;
			mInitFlag = true;
			return true;
		}
		else
		{
			mInitFlag = false;
			return false;
		}
	}

	bool VirtualMassStorage::writeBlock(uint32_t block, void *src)
	{
		if(mInitFlag == false)
			return false;
		if(block >= mNumOfBlock)
			return false;
		
		int8_t *des = &mMemroy[mBlockSize * block];
		int8_t *cSrc = (int8_t*)src;
		for(uint32_t i=0;i<mBlockSize;i++)
			*des++ = *cSrc++;

		return true;
	}

	bool VirtualMassStorage::readBlock(uint32_t block, void *des)
	{
		if(mInitFlag == false)
			return false;
		if(block >= mNumOfBlock)
			return false;

		int8_t *cDes = (int8_t*)des;
		int8_t *src = &mMemroy[mBlockSize * block];
		for(uint32_t i=0;i<mBlockSize;i++)
			*cDes++ = *src++;

		return true;
	}

	uint32_t VirtualMassStorage::getBlockSize(void)
	{
		return mBlockSize;
	}

	uint32_t VirtualMassStorage::getNumOfBlock(void)
	{
		return mNumOfBlock;
	}
}
}

