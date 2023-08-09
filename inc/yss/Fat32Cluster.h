////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
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
		uint32_t start, cluster, next, tableIndex;
		uint8_t sectorIndex;
	};


private:
	uint32_t mFatTableBuffer[128], mFatLength;
	uint32_t mRoot, mFatSector, mFatBackupSector, mLastReadFatTable, mSectorSize, mDataStartSector;
	uint8_t mSectorPerCluster;
	sac::MassStorage *mStorage;
	bool mUpdateFlag;
	Address mAddress, mBackupAddress;

	error readFat(uint32_t cluster);
	uint32_t calculateNextCluster(void);

public:

	Fat32Cluster(void);
	void initialize(sac::MassStorage *storage, uint32_t fatSector, uint32_t fatBackup, uint32_t sectorSize, uint8_t sectorPerCluster);
	error save(void);
	error moveToNextCluster(void);
	error increaseDataSectorIndex(void);
	error append(bool clear = true);
	error setRootCluster(uint32_t cluster);
	uint32_t getRootCluster(void);
	error setCluster(uint32_t cluster);
	uint32_t getStartCluster(void);
	uint32_t getCurrentCluster(void);
	uint32_t getNextCluster(void);
	error readDataSector(void* des);
	error writeDataSector(void* des);
	error moveToRoot(void);
	error moveToStart(void);
	error moveTo(uint32_t cluster);
	uint32_t getSectorSize(void);
	uint32_t allocate(bool clear = true);
	void backup(void);
	void restore(void);
};

#endif
