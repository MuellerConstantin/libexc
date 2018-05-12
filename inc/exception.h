/*
 * exception.h
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

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#ifdef _cplusplus

extern "C"
{

#endif

#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>

#define EXC_FILPATH_MAXLEN 64
#define EXC_ERROR_STR "exception:%s:%ld: terminate called after"		\
	" throwing an instance of '%s'\n\twhat: %s\n"

/* definiton of the single macros which should used for exception handling */

#define EXC_DECLARE(TYPE) extern exception_t TYPE
#define EXC_DEFINE(TYPE, NUMBER, MESSAGE) exception_t TYPE = {NUMBER, #TYPE, MESSAGE}

#define EXC_TRY															\
																		\
	{ _exception_table_push();											\
																		\
	if(0 == setjmp(_exception_table_head->jmpbuf))
		
#define EXC_CATCH(EXCEPTION)											\
																		\
	else if(_exception_table_head->exception.number ==					\
		EXCEPTION.number)
			
#define EXC_FINALLY														\
																		\
	else if(0 != _exception_table_head->exception.number)
		
#define EXC_END														    \
																		\
	else 																\
	{																	\
		_exception_dump(_exception_table_head->exception,				\
			__FILE__, __LINE__);										\
																		\
		_exception_table_clear();										\
		exit(EXIT_FAILURE);												\
	}																	\
																		\
	_exception_table_pop(); }
	
#define EXC_THROW(EXCEPTION) _exception_throw(EXCEPTION, __FILE__, __LINE__)

#define EXC_THROWS(EXCEPTION_LIST)

/* structure which define the new exception type */

struct _exception_type
{
	size_t number;			/* unique exception number for identification */
	const char *name;		/* exception type name used for error handling */
	const char *message;	/* exception handling error message */
};

typedef struct _exception_type exception_t;

/* 
 * definition of the internal exception handling table which stores
 * the thrown exception with additional informations like line number
 * and file name
 * 
 */

struct _exception_table
{
	jmp_buf jmpbuf;						/* jump buffer which is used to return to the exception handling breakpoint */
	volatile exception_t exception;		/* stored instance of the thrown exception type */
	
	size_t line;					/* line number in which the exception was thrown */
	char file[EXC_FILPATH_MAXLEN];	/* name of file in which the exception was thrown */
	
	struct _exception_table *next;
};

/* 
 * this instance is the head of the exception handling table
 * and used for internal usage only
 * don't modify it's value otherwise the behvior is undefined
 * 
 */

extern struct _exception_table *_exception_table_head;

void _exception_table_push(void);
void _exception_table_pop(void);
void _exception_table_clear(void);
void _exception_throw(exception_t, const char *, size_t);
void _exception_dump(exception_t, const char *, size_t);

#ifdef _cplusplus

} /* extern "C" */

#endif

#endif /* _EXCEPTION_H */
