////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2022. yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2022.01.15 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/Fat32Cluster.h>
#include <yss/error.h>
#include <string.h>
#include <__cross_studio_io.h>

error Fat32Cluster::readFat(unsigned int cluster)
{
	mLastReadFatTable = cluster / 128;
	mCurrentIndex = cluster % 128;
	error result;
	result = save();
	if(result != Error::NONE)
		return result;

	mStorage->lock();
	result = mStorage->read(mFatSector + mLastReadFatTable, mFatTableBuffer);
	mStorage->unlock();

	return result;
}

unsigned int Fat32Cluster::calculateNextCluster(void)
{
	return mFatTableBuffer[mCurrentIndex] & 0x0FFFFFFF;
}

Fat32Cluster::Fat32Cluster(void)
{
	mStorage = 0;
	mHome = mCurrent = 0;
	mFatSector = 0;
	mFatBackupSector = 0;
	mNext = 0;
	mFatLength = 0;
	mDataSectorIndex = 0;
	mUpdateFlag = false;
}

void Fat32Cluster::init(sac::MassStorage *storage, unsigned int fatSector, unsigned int fatBackup, unsigned int sectorSize, unsigned char sectorPerCluster)
{
	mStorage = storage;
	mFatSector = fatSector;
	mFatBackupSector = fatBackup;
	mNext = 0;
	mFatLength = fatBackup - fatSector;
	mSectorPerCluster = sectorPerCluster;
	mSectorSize = sectorSize;
	mDataStartSector = fatBackup + mFatLength;
	mUpdateFlag = false;
}

error Fat32Cluster::moveToHome(void)
{
	unsigned int next;
	error result = Error::NONE;
	mDataSectorIndex = 0;

	if(mCurrent == mHome)
		goto skip;

	save();
	mCurrent = mHome;

	result = readFat(mCurrent);
	if(result != Error::NONE)
		return result;

skip:
	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	
	mNext = next;
	return result;
}

error Fat32Cluster::readDataSector(void* des)
{
	error result;

	mStorage->lock();
	result = mStorage->read(mDataStartSector + (mCurrent - 2) * mSectorPerCluster + mDataSectorIndex++, des);
	if(mDataSectorIndex >= mSectorPerCluster)
	{
		mDataSectorIndex = 0;
		result = moveToNextCluster();
		if(result != Error::NONE)
			return result;
	}
	mStorage->unlock();

	return result;
}

error Fat32Cluster::setCluster(unsigned int cluster)
{
	mHome = cluster;
	return moveToHome();
}

unsigned int Fat32Cluster::getCluster(void)
{
	return mHome;
}

error Fat32Cluster::moveToNextCluster(void)
{
	error result;
	unsigned int next;

	if(mNext == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	else if(mNext < 2 || mNext > 0x0FFFFFEF)
		return Error::NO_DATA;
	
	result = readFat(mNext);
	if(result != Error::NONE)
		return result;

	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	
	mCurrent = mNext;
	mNext = next;
	return result;
}

error Fat32Cluster::save(void)
{
	error result = Error::NONE;

	if(mUpdateFlag)
	{
		mStorage->lock();
		mUpdateFlag = false;
		result = mStorage->write(mFatSector + mLastReadFatTable, mFatTableBuffer);
		result = mStorage->write(mFatBackupSector + mLastReadFatTable, mFatTableBuffer);
		mStorage->unlock();
	}

	return result;
}

error Fat32Cluster::append(void)
{
	unsigned int fatTable = mLastReadFatTable, current;
	error result;
	bool overFlowFlag = false;

	if(mNext == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	
	do
	{
		for(unsigned int i=0;i<128;i++)
		{
			if(mFatTableBuffer[i] & 0x0FFFFFFF == 0)
			{
				current = fatTable * 128 + i;

				// 마지막 클러스터에 발견한 클러스터 번지 추가
				if(fatTable != mLastReadFatTable) // 섹터가 다른 경우
				{
					mStorage->lock();
					result = mStorage->read(mFatSector + mLastReadFatTable, mFatTableBuffer);
					mStorage->unlock();
					if(result != Error::NONE)
						return result;

					mFatTableBuffer[mCurrentIndex] = current;
					mUpdateFlag = true;
					result = save();
					if(result != Error::NONE)
						return result;

					mStorage->lock();
					result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
					mStorage->unlock();
				}
				else // 섹터가 같은 경우
					mFatTableBuffer[mCurrentIndex] = current;
				
				// 할당 완료
				mCurrentIndex = i;
				mCurrent = current;
				mLastReadFatTable = fatTable;
				mFatTableBuffer[i] = 0x0FFFFFFF;
				mUpdateFlag = true;
			}
		}
		
		fatTable++;
		if(overFlowFlag == false)
		{
			if(fatTable >= mFatLength)
			{
				overFlowFlag = true;
				fatTable = 0;
			}
		}
		else
		{
			if(fatTable == mLastReadFatTable)
				return Error::NO_FREE_DATA;
		}

		result = save();
		if(result != Error::NONE)
			return result;

		mStorage->lock();
		result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
		mStorage->unlock();
		
		if(result != Error::NONE)
			return result;

	}while(1);
}

unsigned int Fat32Cluster::getSectorSize(void)
{
	return mSectorSize;
}

