# libexc
> A small and portable ANSI-C exception library

## Overview

Originally this library emerged in the context of a school project with the goal to extend
the core C programming language with a lightweight and portable exception handling framework.
The result of this idea was this small and portable fully ANSI-C implemented library. Because of
this project was for education and learning purpose originally, it has not the claim to be fully
operational and usable. Based on this please note that this library should not be used in other
projects unless it is intended to be an education project or for learning reasons.

## Usage

This library provides a basic set of keywords (= *macros*) you are probably already
used for exception handling (definition: [exception.h](inc/exception.h)):

- `EXC_TRY`
- `EXC_CATCH`
- `EXC_DEFAULT`
- `EXC_FINALLY`
- `EXC_THROW`
- `EXC_DECLARE`
- `EXC_DEFINE`

The exception handling with this library is much like in any other high level language like C++ too. Every exception
handling block must begin with an `EXC_TRY` and end with an `EXC_FINALLY`. The keywords `EXC_CATCH` and `EXC_DEFAULT`
are used to catch and handle thrown exceptions, while `EXC_CATCH` catchs only exceptions of a specific type `EXC_DEFAULT`
catchs exceptions of any type. To throw an exception use the macro `EXC_THROW`.

```c
#include <exception.h>

...

int fn(void)
{
  EXC_TRY
  {
    ...
    
    EXC_THROW(exception);
    
    ...
  }
  EXC_CATCH(exception)
  {
    ...
  }
  EXC_DEFAULT
  {
    ...
  }
  EXC_FINALLY
  
  return 0;
}

...
```

There are some standart and system dependend exceptions defined in the header file [excdefs.h](inc/excdefs.h).
If you probably want to define custom exceptions use the macros `EXC_DECLARE` and `EXC_DEFINE`.

```c
...

EXC_DECLARE(my_exception);
EXC_DEFINE(my_exception, my_exception_number, "my_exception_error_message");

...
```

For more informations about usage or implementation of the single macros view the header files [exception.h](inc/exception.h)
and [excdefs.h](inc/excdefs.h).

## Multithreading

Attention, this library is not designed to work with multiple threads and so it is **not thread-safe**. If you
using this library with multiple threads the behavior is undefined!

## Portability

This library is fully implemented in ANSI-C and should compile in any ANSI-C compiler. Because of this library
don't use any external libraries there are no special dependencies and it should be possible to port this library
to any platform with an ANSI-C supported compiler.

## License

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
 * 
This program is distributed in the hope that it will be useful,
but **WITHOUT ANY WARRANTY**; without even the implied warranty of
**MERCHANTABILITY** or **FITNESS FOR A PARTICULAR PURPOSE**.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.

[GNU General Public License](http://www.gnu.org/licenses/gpl.html) or [LICENSE](LICENSE) for
more details.

### Forbidden

**Hold Liable**: Software is provided without warranty and the software
author/license owner cannot be held liable for damages.
