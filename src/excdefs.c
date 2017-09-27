/*
 * excdefs.c
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

#include <excdefs.h>

EXC_DEFINE(out_of_memory, EXC_NUM_OUT_OF_MEMORY, "The requested storage couldn't be provided");
EXC_DEFINE(invalid_pointer, EXC_NUM_INVALID_POINTER, "The submitted pointer is invalid");
EXC_DEFINE(bad_throw, EXC_NUM_BAD_THROW, "A fault appeared while thrown the exception");
EXC_DEFINE(out_of_range, EXC_NUM_OUT_OF_RANGE, "The given position is outside of the memory area");
EXC_DEFINE(logic_error, EXC_NUM_LOGIC_ERROR, "A logical fault has appeared during the runtime");
