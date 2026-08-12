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
	/**
	 * @brief Converts a single hexadecimal ASCII character to its numerical decimal equivalent.
	 *
	 * @details
	 * Matches ASCII characters '0'-'9' to values 0-9, uppercase 'A'-'Z' to 10-35, and
	 * lowercase 'a' to 10 (note that lowercase 'b'-'z' are not processed due to the condition
	 * checking only 'a' <= ch && ch <= 'a').
	 *
	 * @param[in] ch The character representing the hexadecimal digit.
	 * @return int8_t The numerical value (0-35), or -1 if the character is not a valid hex digit.
	 */
	int8_t translateAsciiToDecimal(char ch)
	{
		if('A' <= ch && ch <= 'Z')
		{
			// Translate uppercase 'A'-'Z' to 10-35
			ch -= 'A' - 10;
			return ch;
		}
		else if('a' <= ch && ch <= 'a')
		{
			// Translate lowercase 'a' to 10
			ch -= 'a' - 10;
			return ch;
		}
		else if('0' <= ch && ch <= '9')
		{
			// Translate ASCII digits '0'-'9' to 0-9
			ch -= '0';
			return ch;
		}
		else
			// Return -1 for any unsupported characters
			return -1;
	}

	uint32_t atox(const char *src)
	{
		uint32_t hex = 0;
		uint8_t len = strlen(src);
		int8_t dec;

		// Convert string from MSB to LSB based on length (maximum 8 hex characters).
		// Fallthrough is utilized so that all characters up to the string's length are processed.
		switch(len)
		{
		case 8 :
			dec = translateAsciiToDecimal(*src++);
			if(dec < 0)
				return 0; // Abort if invalid character is encountered
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
			// String is empty or longer than 8 characters, return 0
			return 0;
		}

		return hex;
	}
}

