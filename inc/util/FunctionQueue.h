/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FQ__H_
#define YSS_FQ__H_

#include <yss/scheduler.h>
#include <yss/error.h>

/**
 * @file FunctionQueue.h
 * @brief Function Queue helper class header file.
 */

/**
 * @class FunctionQueue
 * @brief Thread-safe queue to register and execute functions sequentially.
 *
 * @details
 * This class schedules registered function pointers to execute sequentially within a dedicated worker thread.
 * Functions can be registered using add(). Execution starts when start() is called and halts on stop().
 * If any registered function returns a value other than error_t::ERROR_NONE, execution halts and the registered
 * error handler callback is triggered.
 */
class FunctionQueue : public Mutex
{
  public:
	/**
	 * @brief Constructor for FunctionQueue.
	 *
	 * @param[in] depth Maximum number of function pointers that can be queued.
	 * @param[in] stackSize Stack size allocated to the execution worker thread (default is 2048 bytes).
	 */
	FunctionQueue(uint16_t depth, int32_t  stackSize = 2048);
	
	/**
	 * @brief Destructor for FunctionQueue.
	 */
	~FunctionQueue(void);
	
	/**
	 * @brief Enqueues a function to be executed sequentially.
	 *
	 * @param[in] func Pointer to the function to execute. Takes a pointer to the parent FunctionQueue and a void* parameter.
	 * @param[in] var Optional generic parameter passed to the function (default is 0).
	 */
	void add(error_t (*func)(FunctionQueue *, void *), void *var = 0);
	
	/**
	 * @brief Enqueues a function without generic arguments to be executed sequentially.
	 *
	 * @param[in] func Pointer to the function to execute. Takes a pointer to the parent FunctionQueue.
	 */
	void add(error_t (*func)(FunctionQueue *));
	
	/**
	 * @brief Starts execution of the function queue thread.
	 * @note Registered functions will not begin executing until this method is called.
	 *
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t start(void);
	
	/**
	 * @brief Stops execution of the function queue.
	 * @details Terminates the currently running thread immediately and clears all pending functions in the queue.
	 */
	void stop(void);

	/**
	 * @brief Clears all pending functions in the queue.
	 * @note The currently executing function is allowed to complete.
	 */
	void clear(void);

	/**
	 * @brief Checks if the function queue has completed executing all tasks.
	 *
	 * @return bool True if all tasks are complete (idle), false if tasks are currently executing.
	 */
	bool isComplete(void);

	/**
	 * @brief Registers a callback function to handle task errors.
	 * @details Executed if any queued function returns an error code other than error_t::ERROR_NONE.
	 *
	 * @param[in] callback Pointer to the error handler callback function.
	 */
	void setCallbackErrorHandler(void (*callback)(FunctionQueue *fq, error_t errorCode));

	// Internal system functions. Do not call from user application.
	error_t task(void);
	void callErrorHandler(error_t errorCode);

private :
	error_t (**mTaskFunc)(FunctionQueue *task, void *var);
	void **mVariable;
	int32_t mThreadId;
	int32_t mStackSize;
	error_t mError;
	uint16_t mTaskMaxSize, mTaskHead, mTaskTail;
	bool mBusyFlag, mProcessingFlag;
	Mutex mMutex;
	void (*mCallbackErrorHandler)(FunctionQueue *fq, error_t errorCode);
};

#endif