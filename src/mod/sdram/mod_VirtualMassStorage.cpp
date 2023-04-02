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

