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

#include <std_ext/stdlib.h>
#include <string.h>

extern "C"
{
	int8_t translateAsciiToDecimal(char ch)
	{
		if('A' <= ch && ch <= 'Z')
		{
			ch -= 'A' - 10;
			return ch;
		}
		else if('a' <= ch && ch <= 'a')
		{
			ch -= 'a' - 10;
			return ch;
		}
		else if('0' <= ch && ch <= '9')
		{
			ch -= '0';
			return ch;
		}
		else
			return -1;
	}

	uint32_t atox(const char *src)
	{
		uint32_t hex = 0;
		uint8_t len = strlen(src);
		int8_t dec;

		switch(len)
		{
		case 8 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x10000000 * dec;
		case 7 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x01000000 * dec;
		case 6 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00100000 * dec;
		case 5 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00010000 * dec;
		case 4 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00001000 * dec;
		case 3 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00000100 * dec;
		case 2 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00000010 * dec;
		case 1 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00000001 * dec;
			break;
		default :
			return 0;
		}

		return hex;
	}
}

