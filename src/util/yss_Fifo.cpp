/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <util/Fifo.h>
#include <std_ext/string.h>
#include <yss/scheduler.h>

/**
 * @details Initializes the FIFO indices (`mHead` and `mTail`) to 0 and sets the internal buffer size
 *          `mSize` to `size + 1` so that one byte slot is always kept open to distinguish between a full
 *          buffer and an empty buffer. Memory is then dynamically allocated from the configured heap
 *          (`lmalloc` for L-heap, `cmalloc` for C-heap, or standard `new uint8_t[]`).
 * @see Fifo::~Fifo()
 * @todo None.
 * @bug None.
 */
Fifo::Fifo(uint32_t size)
{
	// Initialize data pointer and read/write indices to zero
	mData = 0;
	mHead = 0;
	mTail = 0;

	// Allocate 1 extra byte to prevent full vs. empty ambiguity (mHead == mTail)
	mSize = size + 1;

	// Free existing buffer if any, then allocate memory from the configured heap
	if (mData)
#if (YSS_L_HEAP_USE == true)
		lfree(mData);
	mData = (uint8_t *)lmalloc(mSize);
#elif (YSS_C_HEAP_USE == true)
		cfree(mData);
	mData = (uint8_t *)cmalloc(mSize);
#else
		delete mData;
	mData = new uint8_t[mSize];
#endif
}

/**
 * @details Releases the dynamically allocated circular buffer memory (`mData`) back to the appropriate
 *          heap (`lfree`, `cfree`, `hfree`, or `delete[]`) depending on the compile-time heap configuration.
 * @see Fifo::Fifo(uint32_t size)
 * @todo None.
 * @bug None.
 */
Fifo::~Fifo(void)
{
	// Deallocate the internal buffer using the matching heap deallocator
#if (YSS_L_HEAP_USE == true)
	if (mData)
		lfree(mData);
#elif (YSS_C_HEAP_USE == true)
	if (mData)
		cfree(mData);
#elif (YSS_H_HEAP_USE == true)
	if (mData)
		hfree(mData);
#else
	delete[] mData;
#endif
}

/**
 * @details Copies `size` bytes from the source buffer `src` into the circular buffer starting at `mHead`.
 *          If the data to be written extends past the end of the physical buffer (`mSize`), the copy is split
 *          into contiguous linear chunks using `memcpy`, wrapping `mHead` back to 0 when the end of the
 *          internal array is reached.
 * @see Fifo::push(uint8_t src)
 * @see Fifo::getFreeBufferSize()
 * @todo Consider checking `getFreeBufferSize()` or returning the actual number of bytes written to prevent overwrite when full.
 * @bug If `size` exceeds `getFreeBufferSize()`, `mHead` can overtake `mTail` or stall if `mHead == mTail` while `size > 0`.
 */
void Fifo::push(void *src, uint32_t size)
{
	uint32_t freeSize;
	int8_t *cSrc = (int8_t*)src;

	// Loop until all requested bytes have been copied into the circular buffer
	while(size)
	{
		// Calculate the contiguous space available from mHead to the end of the array (or up to mTail)
		if (mTail <= mHead)
			freeSize = mSize - mHead;
		else
			freeSize = mTail - mHead;

		// Clamp the chunk size to the remaining number of bytes to push
		if(freeSize > size)
			freeSize = size;

		// Copy the contiguous chunk and advance the head pointer and source pointer
		if(freeSize)
		{
			memcpy(&mData[mHead], cSrc, freeSize);
			mHead += freeSize;
			cSrc += freeSize;

			// Wrap mHead around to the beginning of the buffer if it reaches the end
			if(mHead >= mSize)
				mHead = 0;

			// Decrement the remaining byte count
			size -= freeSize;
		}
	}
}

/**
 * @details Writes a single byte `src` into the circular buffer at the current `mHead` index and increments `mHead`.
 *          If `mHead` reaches `mSize`, it wraps around to 0.
 * @see Fifo::push(void *src, uint32_t size)
 * @see Fifo::pop()
 * @todo None.
 * @bug None.
 */
void Fifo::push(uint8_t src)
{
	// Store the byte at the current head position and advance the head index
	mData[mHead++] = src;

	// Wrap around to the start of the buffer if the end of the array is reached
	if (mHead >= mSize)
		mHead = 0;
}

/**
 * @details Reads and removes a single byte from the current `mTail` position if the buffer is not empty
 *          (`mTail != mHead`). Increments `mTail` and wraps it around to 0 when it reaches `mSize`.
 *          Returns 0 if the buffer is empty.
 * @see Fifo::push(uint8_t src)
 * @see Fifo::getStoredBufferSize()
 * @todo None.
 * @bug None.
 */
uint8_t Fifo::pop(void)
{
	// Check if there is unread data in the FIFO buffer
	if(mTail != mHead)
	{
		// Read the oldest byte at mTail and increment the tail index
		uint8_t ch = mData[mTail++];

		// Wrap around to index 0 if mTail reaches the end of the buffer array
		if (mTail >= mSize)
			mTail = 0;

		return ch;
	}
	else
		// Return 0 when the FIFO buffer is empty
		return 0;
}

/**
 * @details Computes the total number of unread bytes currently stored in the circular buffer.
 *          When `mTail <= mHead`, the stored data is contiguous and equals `mHead - mTail`.
 *          When `mTail > mHead`, the stored data wraps around the end of the buffer and equals
 *          `mSize - (mTail - mHead)`.
 * @see Fifo::getStoredLinearBufferSize()
 * @see Fifo::getFreeBufferSize()
 * @todo None.
 * @bug None.
 */
uint32_t Fifo::getStoredBufferSize(void)
{
	// If head has not wrapped behind tail, return the direct difference
	if (mTail <= mHead)
		return mHead - mTail;
	else
		// If head has wrapped around, sum the tail-to-end and start-to-head regions
		return mSize - (mTail - mHead);
}

/**
 * @details Computes the number of contiguous bytes that can be read linearly starting from `&mData[mTail]`
 *          without crossing the end of the internal array (`mSize`). If the stored data wraps around,
 *          only the segment from `mTail` to `mSize` is counted.
 * @see Fifo::getStoredBuffer()
 * @see Fifo::releaseStoredBuffer(uint32_t size)
 * @todo None.
 * @bug None.
 */
uint32_t Fifo::getStoredLinearBufferSize(void)
{
	// If data does not wrap around, all stored bytes are linearly contiguous
	if(mTail <= mHead)	
		return mHead - mTail;
	else 
		// If data wraps around, return only the contiguous bytes from mTail to the end of the array
		return mSize - mTail;
}

/**
 * @details Returns the memory address of the oldest unread byte (`&mData[mTail]`) so the caller can
 *          read up to `getStoredLinearBufferSize()` contiguous bytes directly without copying to an
 *          intermediate buffer.
 * @see Fifo::getStoredLinearBufferSize()
 * @see Fifo::releaseStoredBuffer(uint32_t size)
 * @todo None.
 * @bug None.
 */
uint8_t* Fifo::getStoredBuffer()
{
	// Return the pointer to the current tail element in the circular buffer
	return &mData[mTail];
}

/**
 * @details Advances `mTail` by up to `size` bytes within the current linear stored segment after the caller
 *          has finished reading data from `getStoredBuffer()`. Clamps `size` to the maximum contiguous
 *          bytes available in the current linear segment (`mHead - mTail` when `mTail < mHead`, or
 *          `mSize - mTail` when `mTail > mHead`), and wraps `mTail` to 0 if it reaches `mSize`.
 * @see Fifo::getStoredBuffer()
 * @see Fifo::getStoredLinearBufferSize()
 * @todo None.
 * @bug None.
 */
void Fifo::releaseStoredBuffer(uint32_t size)
{
	uint32_t buf;

	// When stored data is contiguous between mTail and mHead
	if(mTail < mHead)
	{
		buf = mHead - mTail;
		// Clamp release size to the available stored bytes
		if(size > buf)
			size = buf;
	}
	// When stored data wraps around the end of the internal buffer
	else if(mTail > mHead)
	{
		buf = mSize - mTail;
		// Clamp release size to the linear segment up to the end of the buffer
		if(size > buf)
			size = buf;
	}
	else
		// Buffer is empty; nothing to release
		size = 0;

	// Advance the tail index by the released byte count
	mTail += size;

	// Wrap tail index around to 0 if it reaches the end of the internal array
	if(mTail >= mSize)
		mTail = 0;
}

/**
 * @details Computes the number of free bytes available for writing into the circular buffer.
 *          Subtracts 1 from the total unallocated slots to preserve the guard byte that prevents
 *          `mHead` from becoming equal to `mTail` when the buffer is full.
 * @see Fifo::getStoredBufferSize()
 * @see Fifo::push(void *src, uint32_t size)
 * @todo None.
 * @bug None.
 */
uint32_t Fifo::getFreeBufferSize(void)
{
	// If head is at or ahead of tail, available space is (usable capacity - stored bytes)
	if (mTail <= mHead)
		return (mSize - 1) - (mHead - mTail);
	else
		// If head wrapped behind tail, available space is the gap between head and tail minus 1 guard byte
		return (mTail - mHead) - 1;
}

/**
 * @details Resets both `mTail` and `mHead` indices to 0, effectively discarding all stored data
 *          and restoring the FIFO buffer to its initial empty state.
 * @see Fifo::getStoredBufferSize()
 * @todo None.
 * @bug None.
 */
void Fifo::clear(void)
{
	// Reset both tail and head indices to empty the buffer
	mTail = mHead = 0;
}