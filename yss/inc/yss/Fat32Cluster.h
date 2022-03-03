////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_FAT32_CLUSTER__H_
#define YSS_FAT32_CLUSTER__H_

#include <yss/error.h>
#include <sac/FileSystem.h>

class Fat32Cluster
{

public:
	struct Address
	{
		unsigned int start, cluster, next, tableIndex;
		unsigned char sectorIndex;
	};


private:
	unsigned int mFatTableBuffer[128], mFatLength;
	unsigned int mRoot, mFatSector, mFatBackupSector, mLastReadFatTable, mSectorSize, mDataStartSector;
	unsigned char mSectorPerCluster;
	sac::MassStorage *mStorage;
	bool mUpdateFlag;
	Address mAddress, mBackupAddress;

	error readFat(unsigned int cluster);
	unsigned int calculateNextCluster(void);

public:

	Fat32Cluster(void);
	void init(sac::MassStorage *storage, unsigned int fatSector, unsigned int fatBackup, unsigned int sectorSize, unsigned char sectorPerCluster);
	error save(void);
	error moveToNextCluster(void);
	error increaseDataSectorIndex(void);
	error append(bool clear = true);
	error setRootCluster(unsigned int cluster);
	unsigned int getRootCluster(void);
	error setCluster(unsigned int cluster);
	unsigned int getStartCluster(void);
	unsigned int getCurrentCluster(void);
	error readDataSector(void* des);
	error writeDataSector(void* des);
	error moveToRoot(void);
	error moveToStart(void);
	error moveTo(unsigned int cluster);
	unsigned int getSectorSize(void);
	unsigned int allocate(bool clear = true);
	void backup(void);
	void restore(void);
};

#endif
