/*
 * example.c
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

#include <stdio.h>
#include <stdlib.h>

#include <exception.h>
#include <excdefs.h>

void fn(int);

int main(int argc, char **argv)
{
	EXC_DEFINE(my_exception, EXC_NUM_USER_DEFINED + 1, "my exception was thrown");
	
	EXC_TRY
	{
		fn(-1);
	}
	EXC_CATCH(logic_error)
	{
		printf("exception was thrown: logic_error\n");
	}
	EXC_FINALLY
	{
		printf("exception was thrown: unknown\n");
	}
	EXC_END
	
	EXC_THROW(my_exception);
	
	return EXIT_SUCCESS;
}

void fn(int value) EXC_THROWS(logic_error)
{
	if(0 > value)
	{
		EXC_THROW(logic_error);
	}
	else
	{
		printf("value: %d\n", value);
	}
}
