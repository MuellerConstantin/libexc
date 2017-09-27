/*
 * exception.c
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

#include <exception.h>
#include <stdlib.h>
#include <string.h>
#include <excdefs.h>

/*
 * these functions and variables shouldn't used directly instead
 * use the defined macros in the header file "exception.h"
 * 
 */

struct _exception_table *_exception_table_head = NULL;

void _exception_table_push(void)
{
	struct _exception_table *node = NULL;
	
	if(NULL == (node = (struct _exception_table *)
		malloc(sizeof(struct _exception_table))))
	{
		EXC_THROW(bad_throw);
	}
	else
	{
		node->next = NULL;
	}
	
	if(NULL == _exception_table_head)
	{
		_exception_table_head = node;
	}
	else
	{
		node->next = _exception_table_head;
		_exception_table_head = node;
	}
}

void _exception_table_pop(void)
{
	if(NULL != _exception_table_head)
	{
		struct _exception_table *node = NULL;
		
		if(NULL == _exception_table_head->next)
		{
			node = _exception_table_head;
			_exception_table_head = NULL;
		}
		else
		{
			node = _exception_table_head;
			_exception_table_head = _exception_table_head->next;
		}
		
		free(node);
		node = NULL;
	}
}

void _exception_table_clear(void)
{
	struct _exception_table *node = _exception_table_head;
	struct _exception_table *next = node;
  
	while(NULL != node)
	{
		next = node->next;
		
		free(node);
		node = NULL;
		node = next;
	}
}

void _exception_throw(exception_t exception, const char *file, size_t line)
{
	if(NULL == _exception_table_head)
	{
		_exception_dump(exception, file, line);
		exit(EXIT_FAILURE);
	}
	else
	{
		_exception_table_head->exception = exception;
		_exception_table_head->line = line;
		strncpy(_exception_table_head->file, file, EXC_FILPATH_MAXLEN);
		
		longjmp(_exception_table_head->jmpbuf, _exception_table_head->exception.number);
	}
}

void _exception_dump(exception_t exception, const char *file, size_t line)
{
	fprintf(stderr, EXC_ERROR_STR, file, line, exception.name, exception.message);
}
