#include <hal/Ethernet.h>

Ethernet::Ethernet()
{
    mPhysicalLayerAddr = 0;
	mMallocBuffer = nullptr;
	mRxDesc = nullptr;
	mTxDesc = nullptr;
	mRxDescCount = 0;
	mTxDescCount = 0;
}

error_t Ethernet::setPhysicalLayerAddress(uint8_t pa)
{
	if(pa < 32)
	{
		mPhysicalLayerAddr = pa;
		updateConfig();

		return error_t::ERROR_NONE;
	}
	else
		return error_t::OUT_OF_RANGE;
}

error_t Ethernet::malloc()
{
	if (mRxDescCount == 0 || mTxDescCount == 0)
		return error_t::WRONG_CONFIG;

	if (mMallocBuffer)
	{
		delete[] mMallocBuffer;
		mMallocBuffer = nullptr;
	}

	uint32_t descTotalSize = sizeof(DmaDesc) * (mRxDescCount + mTxDescCount);
	uint32_t bufferTotalSize = mMaxBufferSize * (mRxDescCount + mTxDescCount);
	uint32_t totalAllocSize = descTotalSize + bufferTotalSize + 128;

	mMallocBuffer = new uint8_t[totalAllocSize];
	if (mMallocBuffer == nullptr)
		return error_t::MALLOC_FAILED;
	
	uintptr_t addr = (uintptr_t)mMallocBuffer;
	addr = (addr + 0x3F) & ~((uintptr_t)0x3F);

	mRxDesc = (DmaDesc*)addr;
	addr += sizeof(DmaDesc) * mRxDescCount;

	mTxDesc = (DmaDesc*)addr;
	addr += sizeof(DmaDesc) * mTxDescCount;

	addr = (addr + 63) & ~((uintptr_t)63);
	for(uint32_t i = 0; i < mRxDescCount; i++)
	{
		mRxDesc[i].status = (1U << 31);         // OWN = 1 (DMA 소유)
		mRxDesc[i].control = mMaxBufferSize;    // Buffer 1 Size (RBS1)
		mRxDesc[i].buffer1Addr = addr;
		mRxDesc[i].buffer2Addr = 0;
		addr += mMaxBufferSize;
	}
	// 마지막 Rx 디스크립터에 RER (Receive End of Ring, bit 15) 설정
	mRxDesc[mRxDescCount - 1].control |= (1U << 15);

	for (uint32_t i = 0; i < mTxDescCount; i++)
	{
		mTxDesc[i].status = 0;                  // OWN = 0 (CPU 소유)
		mTxDesc[i].control = 0;
		mTxDesc[i].buffer1Addr = addr;
		mTxDesc[i].buffer2Addr = 0;
		addr += mMaxBufferSize;
	}
	// 마지막 Tx 디스크립터에 TER (Transmit End of Ring, bit 21) 설정
	mTxDesc[mTxDescCount - 1].status |= (1U << 21);

	return error_t::ERROR_NONE;
}

