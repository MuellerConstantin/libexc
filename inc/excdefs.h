/*
 * excdefs.h
 * 
 * Copyright 2017 0x1C1B
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef _EXCDEFS_H
#define _EXCDEFS_H

#ifdef __cplusplus

extern "C"
{

#endif

#include <exception.h>

/* 
 * standart exception numbers which should be unique
 * custom user defined exception should hold a number
 * bigger than EXC_NUM_USER_DEFINED for guarantee unique
 * identifiers
 * 
 */

enum _exception_numbers
{
	EXC_NUM_NONE,
	EXC_NUM_OUT_OF_MEMORY,
	EXC_NUM_INVALID_POINTER,
	EXC_NUM_BAD_THROW,
	EXC_NUM_BAD_CAST,
	EXC_NUM_OUT_OF_RANGE,
	EXC_NUM_LOGIC_ERROR,
	EXC_NUM_USER_DEFINED
};

EXC_DECLARE(out_of_memory);
EXC_DECLARE(invalid_pointer);
EXC_DECLARE(bad_throw);
EXC_DECLARE(out_of_range);
EXC_DECLARE(logic_error);

#ifdef __cplusplus

} /* extern "C" */

#endif

#endif /* _EXCDEFS_H */
