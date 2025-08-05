/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/ToneGenerator.h>
#include <math.h>

ToneGenerator::ToneGenerator(I2s &obj, uint32_t bufferDepth)
{
	mDev = &obj;
	mBufferDepth = bufferDepth;
	mPcmBuffer = nullptr;
	mSampleRate = 0;
	mMolecule = 0;
	mTargetFrequency = 1000;
	mLastTargetFrequency = 0;
}

ToneGenerator::~ToneGenerator(void)
{
	if(mPcmBuffer)
		delete mPcmBuffer;
}

void ToneGenerator::initialize(void)
{
	uint32_t size = mDev->getChannelFrameSize();
	mSampleRate = mDev->getLrclkFrequency();
	mPcmBuffer = new uint8_t[mBufferDepth * size * 2];

	runThread();
}

void ToneGenerator::thread(void)
{
	uint32_t count;
	int16_t *buf1;
	int32_t *buf2;
	uint32_t size = 0;

	while(mPcmBuffer == nullptr)
		thread::yield();
	
	size = mDev->getChannelFrameSize();
	mDev->transfer(mPcmBuffer, mBufferDepth * 2);
	checkTargetFrequency();
	mMolecule = 0;
	
	switch(size)
	{
	case 2 :
		while(1)
		{
			count = mDev->getTxCount() & 0xFFFFFFFE;
			if(count > 0)
			{
				buf1 = (int16_t*)mDev->getCurrentBuffer();

				for(uint32_t i = 0; i < count; i+= 2)
				{
					buf1[i] = sin((2.f*M_PI)*((float)mMolecule/(float)mDenominator)) * 32767;
					buf1[i+1] = buf1[i];
					mMolecule++;
					if(mMolecule >= mDenominator)
					{
						mMolecule = 0;
						checkTargetFrequency();
					}
				}

				mDev->releaseBuffer(count);
			}
			thread::yield();
		}
		break;

	case 3 :
		while(1)
		{
			count = mDev->getTxCount() & 0xFFFFFFFE;
			if(count > 0)
			{
				buf2 = (int32_t*)mDev->getCurrentBuffer();

				for(uint32_t i = 0; i < count; i+= 2)
				{
					buf2[i] = sin((2.f*M_PI)*((float)mMolecule/(float)mDenominator)) * 16777215.f;
					buf2[i+1] = buf2[i];
					mMolecule++;
					if(mMolecule >= mDenominator)
					{
						mMolecule = 0;
						checkTargetFrequency();
					}
				}

				mDev->releaseBuffer(count);
			}
			thread::yield();
		}
		break;

	case 4 :
		while(1)
		{
			count = mDev->getTxCount() & 0xFFFFFFFE;
			if(count > 0)
			{
				buf2 = (int32_t*)mDev->getCurrentBuffer();

				for(uint32_t i = 0; i < count; i+= 2)
				{
					buf2[i] = sin((2.f*M_PI)*((float)mMolecule/(float)mDenominator)) * 2147483647.f;
					buf2[i+1] = buf2[i];
					mMolecule++;
					if(mMolecule >= mDenominator)
					{
						mMolecule = 0;
						checkTargetFrequency();
					}
				}

				mDev->releaseBuffer(count);
			}
			thread::yield();
		}
		break;
	}
}

void ToneGenerator::setTargetFrequency(float freq)
{
	mTargetFrequency = freq;
}

void ToneGenerator::checkTargetFrequency(void)
{
	if(mTargetFrequency != mLastTargetFrequency)
	{
		mDenominator = (float)mSampleRate / mTargetFrequency;
		mLastTargetFrequency = mTargetFrequency;
	}
}
