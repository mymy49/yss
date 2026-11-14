/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_FIFO__H_
#define YSS_UTIL_FIFO__H_

#include <yss/Mutex.h>
#include <stdint.h>

/**
 * @class Fifo
 * @brief A circular First-In-First-Out (FIFO) byte buffer class with built-in mutex support.
 *        This class provides an efficient ring buffer implementation for asynchronous data
 *        transfers between interrupt service routines (ISRs), DMA channels, and application threads.
 *        It inherits from Mutex so callers can synchronize concurrent access when needed, and
 *        supports both single-byte/block push-pop operations as well as zero-copy buffer
 *        access via getStoredBuffer(), getStoredBufferSize(), getStoredLinearBufferSize(),
 *        and releaseStoredBuffer().
 *        Internally, it allocates (size + 1) bytes to distinguish between full and empty states
 *        without requiring an extra counter variable.
 *
 * @code
 * #include <stdio.h>
 * #include <string.h>
 * #include <yss.h>
 * #include <bsp.h>
 * #include <util/Fifo.h>
 *
 * // Instantiate an 8 KB FIFO buffer (bootloader/App/src/bsp.cpp)
 * Fifo msg(8 * 1024);
 *
 * void thread_handleUartMsg(void);
 *
 * // Producer example: format log strings and push them into the FIFO buffer (bootloader/App/src/main.cpp)
 * int main(void)
 * {
 *     char str[256];
 *     uint32_t len;
 *
 *     initializeYss();
 *     initializeBoard();
 *
 *     thread::add(thread_handleUartMsg, 4 * 1024);
 *
 *     sprintf(str, "\n\rStarts yss OS Bootloader");
 *     len = strlen(str);
 *     msg.push(str, len);
 *
 *     sprintf(str, "\n\r##### Clock Configuration #####\n");
 *     len = strlen(str);
 *     msg.push(str, len);
 *
 *     sprintf(str, "\n\r- HXT\t\t: %u Hz", clock.getHxtFrequency());
 *     len = strlen(str);
 *     msg.push(str, len);
 *
 *     while (1)
 *     {
 *         thread::yield();
 *     }
 * }
 *
 * // Consumer thread example: transmit buffered data over UART0 (bootloader/App/src/main.cpp)
 * void thread_handleUartMsg(void)
 * {
 *     uint8_t *buf;
 *     uint32_t len;
 *
 *     while (1)
 *     {
 *         len = msg.getStoredBufferSize();
 *
 *         if (len > 0)
 *         {
 *             buf = msg.getStoredBuffer();
 *             uart0.lock();
 *             uart0.send(buf, len);
 *             uart0.unlock();
 *             msg.releaseStoredBuffer(len);
 *         }
 *     }
 * }
 * @endcode
 */
class Fifo : public Mutex
{
public:
	/**
	 * @brief Constructs a Fifo object and dynamically allocates the internal circular buffer.
	 * @param[in] size The usable capacity of the FIFO buffer in bytes.
	 * @return None (Constructor).
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning If dynamic memory allocation fails, the internal buffer pointer (mData) will be NULL,
	 *          and subsequent operations may cause a null pointer dereference.
	 * @note Internally allocates (size + 1) bytes so that one slot is reserved to differentiate
	 *       the full state from the empty state (mHead == mTail).
	 * @pre The system heap (L-heap, C-heap, or standard C++ heap) must be initialized prior to calling this constructor.
	 * @post The FIFO buffer is allocated and initialized to an empty state (mHead = 0, mTail = 0).
	 * @deprecated None.
	 */
	Fifo(uint32_t size);

	/**
	 * @brief Destroys the Fifo object and frees the dynamically allocated internal buffer.
	 * @param None.
	 * @return None (Destructor).
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning Do not access or use the FIFO instance from any thread or ISR while or after the destructor is invoked.
	 * @note Automatically selects the deallocation function (lfree, cfree, hfree, or delete[]) matching the configured heap.
	 * @pre No threads or ISRs are actively accessing the FIFO buffer.
	 * @post The dynamically allocated memory pointed to by mData is released back to the heap.
	 * @deprecated None.
	 */
	~Fifo();

	/**
	 * @brief Pushes a block of bytes from the source buffer into the FIFO buffer.
	 * @param[in] src Pointer to the source data buffer to copy from.
	 * @param[in] size Number of bytes to push into the FIFO buffer.
	 * @return None.
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning This function does not check if getFreeBufferSize() >= size. Pushing more bytes than the
	 *          available free space will overwrite unread data and corrupt the tail state.
	 * @note Automatically handles wrap-around at the end of the internal circular buffer using up to two memcpy calls.
	 * @pre src must be a valid non-null pointer, and getFreeBufferSize() must be greater than or equal to size.
	 * @post mHead is advanced by size modulo mSize, and the specified bytes are stored in the FIFO buffer.
	 * @deprecated None.
	 */
	void push(void *src, uint32_t size);

	/**
	 * @brief Pushes a single byte into the FIFO buffer.
	 * @param[in] src The byte value to push into the FIFO buffer.
	 * @return None.
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning Pushing a byte when getFreeBufferSize() is 0 will cause mHead to catch up with mTail,
	 *          making the buffer appear empty and losing all previously stored data.
	 * @note Suitable for lightweight byte-by-byte insertion such as inside an interrupt service routine (ISR).
	 * @pre The FIFO buffer must have at least 1 byte of free space (getFreeBufferSize() >= 1).
	 * @post The byte is written at the current head position and mHead is incremented modulo mSize.
	 * @deprecated None.
	 */
	void push(uint8_t src);

	/**
	 * @brief Pops and returns a single byte from the FIFO buffer.
	 * @param None.
	 * @return The oldest byte stored in the FIFO buffer, or 0 if the buffer is empty.
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning When the FIFO buffer is empty, this function returns 0, which is indistinguishable from a valid 0x00 data byte.
	 *          Always check getStoredBufferSize() > 0 before calling pop().
	 * @note Advances mTail by 1 byte modulo mSize when the buffer is not empty.
	 * @pre The FIFO buffer should contain at least 1 stored byte (getStoredBufferSize() > 0).
	 * @post If non-empty, mTail is incremented modulo mSize and the stored byte count decreases by 1.
	 * @deprecated None.
	 */
	uint8_t pop();

	/**
	 * @brief Returns the total number of unread bytes currently stored in the FIFO buffer.
	 * @param None.
	 * @return The number of stored bytes (ranging from 0 to the usable capacity).
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning None.
	 * @note Includes both linearly contiguous bytes from mTail and any wrapped-around bytes starting from index 0.
	 * @pre The Fifo object must be properly initialized.
	 * @post The internal state of the FIFO buffer remains unchanged.
	 * @deprecated None.
	 */
	uint32_t getStoredBufferSize();

	/**
	 * @brief Returns the number of contiguous unread bytes available from the current tail pointer without wrapping around.
	 * @param None.
	 * @return The number of contiguous readable bytes starting at getStoredBuffer().
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning If the stored data wraps around the end of the internal array, this value will be smaller than getStoredBufferSize().
	 *          A second read after releaseStoredBuffer() is required to consume the remaining wrapped portion.
	 * @note Ideal for zero-copy DMA transfers or block transmission routines that require a single linear memory address range.
	 * @pre The Fifo object must be properly initialized.
	 * @post The internal state of the FIFO buffer remains unchanged.
	 * @deprecated None.
	 */
	uint32_t getStoredLinearBufferSize();

	/**
	 * @brief Returns the available free space in bytes that can be safely pushed into the FIFO buffer.
	 * @param None.
	 * @return The number of free bytes available for writing (ranging from 0 to the usable capacity).
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning Do not push more bytes than the value returned by this function to avoid buffer overflow.
	 * @note Accounts for the 1-byte guard slot reserved to distinguish between full and empty states.
	 * @pre The Fifo object must be properly initialized.
	 * @post The internal state of the FIFO buffer remains unchanged.
	 * @deprecated None.
	 */
	uint32_t getFreeBufferSize();

	/**
	 * @brief Returns a direct pointer to the oldest unread byte at the current tail position.
	 * @param None.
	 * @return A pointer to the internal buffer at &mData[mTail].
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning Do not read more than getStoredLinearBufferSize() bytes from the returned pointer, as doing so
	 *          will read past the end of the allocated array or beyond valid written data.
	 * @note Used in conjunction with getStoredLinearBufferSize() and releaseStoredBuffer() for zero-copy reading.
	 * @pre The Fifo object must be properly initialized and getStoredLinearBufferSize() should be greater than 0.
	 * @post The internal state of the FIFO buffer remains unchanged until releaseStoredBuffer() is called.
	 * @deprecated None.
	 */
	uint8_t* getStoredBuffer();

	/**
	 * @brief Releases (consumes) a specified number of contiguous bytes from the current tail position.
	 * @param[in] size The number of bytes to release from the linear readable region.
	 * @return None.
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning If size exceeds the current linear stored size (getStoredLinearBufferSize()), the released amount
	 *          is clamped to the linear stored size and does not automatically wrap around past index 0.
	 * @note Call this function after reading or transmitting data obtained via getStoredBuffer().
	 * @pre Data up to size bytes from getStoredBuffer() has been processed by the caller.
	 * @post mTail is advanced by the clamped size (wrapping to 0 if it reaches mSize), freeing those slots for new data.
	 * @deprecated None.
	 */
	void releaseStoredBuffer(uint32_t size);

	/**
	 * @brief Clears the FIFO buffer by resetting both head and tail indices to zero.
	 * @param None.
	 * @return None.
	 * @author Yoon-Ki Hong
	 * @date 2026-11-14
	 * @warning Calling clear() while another thread or ISR is concurrently pushing or popping data without external
	 *          synchronization may result in a race condition.
	 * @note Does not zero out or deallocate the underlying memory array; it only resets mHead and mTail to 0.
	 * @pre The caller should ensure exclusive access (e.g., via Mutex::lock() or disabling interrupts) if concurrent access is possible.
	 * @post The FIFO buffer is empty (mHead == 0, mTail == 0, getStoredBufferSize() == 0).
	 * @deprecated None.
	 */
	void clear();

private:
	volatile uint32_t mHead; ///< Write index pointing to the next free slot in the circular buffer.
	volatile uint32_t mTail; ///< Read index pointing to the oldest unread byte in the circular buffer.
	uint32_t mSize;          ///< Total allocated size of the internal buffer in bytes (usable size + 1).
	uint8_t *mData;          ///< Pointer to the dynamically allocated circular buffer memory.
};

#endif
