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

#ifndef YSS_FILE_SYSTEM__H_
#define YSS_FILE_SYSTEM__H_

#include <sac/MassStorage.h>
#include <yss/error.h>
#include <stdint.h>

namespace sac
{
	class FileSystem
	{
	protected :

		uint8_t *mSectorBuffer;
		sac::MassStorage *mStorage;
		uint32_t mNumOfSector, mFirstSector;
		uint8_t mPartitionType;
		bool mAbleFlag;
		
		FileSystem(sac::MassStorage &storage);
		~FileSystem(void);
		error checkMbr(void);
		
		int32_t  translateUtf16ToUtf8(void *utf16);
		int32_t  countUtf8Char(void *utf8);

	public :
		virtual error initialize(void) = 0;
		virtual int32_t getDirectoryCount(void) = 0;
		virtual int32_t getFileCount(void) = 0;
		virtual error moveToRootDirectory(void) = 0;
		virtual error moveToStart(void) = 0;
		virtual error moveToCluster(uint32_t cluster) = 0;
		virtual error moveToNextFile(void) = 0;
		virtual error getName(void* des, uint32_t size) = 0;
		virtual error moveToNextDirectory(void) = 0;
		virtual bool isDirectory(void) = 0;
		virtual bool isFile(void) = 0;
		virtual bool isHaveNextCluster(void) = 0;
		virtual bool compareName(const char *utfName) = 0;
		virtual error enterDirectory(void) = 0;
		virtual error returnDirectory(void) = 0;
		virtual error makeDirectory(const char*name) = 0;
		virtual error makeFile(const char *name) = 0;
		virtual error open(void) = 0;
		virtual error read(void *des) = 0;
		virtual error write(void *src) = 0;
		virtual uint32_t getFileSize(void) = 0;
		virtual error moveToNextSector(void) = 0;
		virtual error close(uint32_t fileSize) = 0;
		virtual error close(void) = 0;
		virtual uint32_t getCurrentDirectoryCluster(void) = 0;
		virtual error moveToFileStart(void) = 0;

		void* getSectorBuffer(void);
	};
}

#endif
