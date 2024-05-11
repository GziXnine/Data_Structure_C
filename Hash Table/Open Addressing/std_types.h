#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO_INIT  0
#define ZERO       0
#define ONE        1

/*_______________________________________________________________*/

  // Unsigned integer types
  typedef unsigned char      uint8_t;
  typedef unsigned short     uint16_t;
  typedef unsigned int       uint32_t;
  typedef unsigned long long uint64_t;

  // Signed integer types
  typedef signed char        sint8_t;
  typedef signed short       sint16_t;
  typedef signed int         sint32_t;
  typedef signed long long   sint64_t;

  // Floating-point types
  typedef float              float32_t;
  typedef double             float64_t;

  // Boolean types
  typedef char               bool_t;

/*_______________________________________________________________*/

#endif // !_STD_TYPES_H_