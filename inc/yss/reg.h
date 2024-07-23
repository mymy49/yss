/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef REG__H_
#define REG__H_

#define setBitData(des, bit, shift) \
	if (bit)                       \
		des |= 1 << shift;         \
	else                           \
		des &= ~(1 << shift)

#define getBitData(src, shift) ((src >> (shift)) & 0x1)

#define setFieldData(des, mask, data, shift) des = (des & ~(mask)) | (((data) << (shift)) & (mask))
#define getFieldData(src, mask, shift) ((src & mask) >> shift)

#define setTwoFieldData(des, mask1, data1, shift1, mask2, data2, shift2) des = (des & ~(mask1 | mask2)) | ((data1 << shift1 & mask1) | (data2 << shift2 & mask2))
#define setThreeFieldData(des, mask1, data1, shift1, mask2, data2, shift2, mask3, data3, shift3) des = (des & ~((mask1)|(mask2)|(mask3))) | (((data1) << (shift1) | (data2) << (shift2) | (data3) << (shift3)) & ((mask1)|(mask2)|(mask3)))

#endif