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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_FILE__H_
#define YSS_FILE__H_

#include <sac/FileSystem.h>

class File
{
public:
	enum
	{
		WRITE_ONLY = 0,
		READ_ONLY,
	};

	File(FileSystem &fileSystem);

	File(FileSystem *fileSystem);

	error_t initialize(void);

	error_t open(const char *fileName, uint8_t mode);

	error_t open(int32_t  cluster, uint8_t mode);

	error_t setPath(uint32_t cluster);

	uint32_t read(void *des, uint32_t size);

	uint32_t write(void *src, uint32_t size);

	uint32_t getSize(void);

	error_t moveToStart(void);

	error_t moveToEnd(void);

	error_t moveTo(uint32_t position);

	error_t makeFile(const char *fileName);

	error_t close(void);

private:
	FileSystem *mFileSystem;
	bool mOpenFlag;
	uint8_t *mBuffer, mOpenMode;
	uint32_t mFileSize, mBufferCount;

	bool checkFileName(const char *fileName);

	bool bringOneName(char *des, const char **src);

	error_t enterDirectory(const char *name);

	error_t findFile(const char *name);
};

#endif