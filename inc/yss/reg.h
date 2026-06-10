/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file reg.h
 * @brief Register field helper macros for bit and mask operations.
 */

#ifndef REG__H_
#define REG__H_

/**
 * @brief Set or clear a single bit in a destination value.
 *
 * @param des Destination value to modify.
 * @param bit Boolean value that controls the bit state.
 * @param shift Bit position to update.
 */
#define setBitData(des, bit, shift) \
	if (bit)                       \
		des |= 1 << shift;         \
	else                           \
		des &= ~(1 << shift)

/**
 * @brief Read a single bit from a source value.
 *
 * @param src Source value to read from.
 * @param shift Bit position to return.
 * @return Extracted bit value (0 or 1).
 */
#define getBitData(src, shift) ((src >> (shift)) & 0x1)

/**
 * @brief Set a field in a destination value using a mask.
 *
 * @param des Destination value to modify.
 * @param mask Field mask.
 * @param data Field data to insert.
 * @param shift Bit position of the field.
 */
#define setFieldData(des, mask, data, shift) des = (des & ~(mask)) | (((data) << (shift)) & (mask))

/**
 * @brief Read a field from a source value using a mask.
 *
 * @param src Source value to read from.
 * @param mask Field mask.
 * @param shift Bit position of the field.
 * @return Extracted field data.
 */
#define getFieldData(src, mask, shift) ((src & mask) >> shift)

/**
 * @brief Set two fields in a destination value using masks.
 *
 * @param des Destination value to modify.
 * @param mask1 First field mask.
 * @param data1 First field data.
 * @param shift1 First field bit position.
 * @param mask2 Second field mask.
 * @param data2 Second field data.
 * @param shift2 Second field bit position.
 */
#define setTwoFieldsData(des, mask1, data1, shift1, mask2, data2, shift2) des = (des & ~(mask1 | mask2)) | ((data1 << shift1 & mask1) | (data2 << shift2 & mask2))

/**
 * @brief Set three fields in a destination value using masks.
 *
 * @param des Destination value to modify.
 * @param mask1 First field mask.
 * @param data1 First field data.
 * @param shift1 First field bit position.
 * @param mask2 Second field mask.
 * @param data2 Second field data.
 * @param shift2 Second field bit position.
 * @param mask3 Third field mask.
 * @param data3 Third field data.
 * @param shift3 Third field bit position.
 */
#define setThreeFieldsData(des, mask1, data1, shift1, mask2, data2, shift2, mask3, data3, shift3) des = (des & ~((mask1)|(mask2)|(mask3))) | (((data1) << (shift1) | (data2) << (shift2) | (data3) << (shift3)) & ((mask1)|(mask2)|(mask3)))

/**
 * @brief Set four fields in a destination value using masks.
 *
 * @param des Destination value to modify.
 * @param mask1 First field mask.
 * @param data1 First field data.
 * @param shift1 First field bit position.
 * @param mask2 Second field mask.
 * @param data2 Second field data.
 * @param shift2 Second field bit position.
 * @param mask3 Third field mask.
 * @param data3 Third field data.
 * @param shift3 Third field bit position.
 * @param mask4 Fourth field mask.
 * @param data4 Fourth field data.
 * @param shift4 Fourth field bit position.
 */
#define setFourFieldsData(des, mask1, data1, shift1, mask2, data2, shift2, mask3, data3, shift3, mask4, data4, shift4) des = (des & ~((mask1)|(mask2)|(mask3)|(mask4))) | (((data1) << (shift1) | (data2) << (shift2) | (data3) << (shift3) | (data4) << (shift4)) & ((mask1)|(mask2)|(mask3)|(mask4)))

#endif