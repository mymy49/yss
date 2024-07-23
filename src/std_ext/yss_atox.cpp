/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
			[[fallthrough]];
		case 7 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x01000000 * dec;
			[[fallthrough]];
		case 6 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00100000 * dec;
			[[fallthrough]];
		case 5 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00010000 * dec;
			[[fallthrough]];
		case 4 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00001000 * dec;
			[[fallthrough]];
		case 3 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00000100 * dec;
			[[fallthrough]];
		case 2 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0;
			hex += 0x00000010 * dec;
			[[fallthrough]];
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

