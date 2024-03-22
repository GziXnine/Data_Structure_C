#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ZERO_INIT  0
#define ZERO       0

#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define CPU_TYPE (CPU_TYPE_64)

/*_______________________________________________________________*/
#if (CPU_TYPE == CPU_TYPE_64)

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

  // Character types
  typedef char               char_t;

  // Boolean type
  typedef _Bool              bool_t;

#elif (CPU_TYPE == CPU_TYPE_32)

  // Unsigned integer types
  typedef unsigned char      uint8_t;
  typedef unsigned short     uint16_t;
  typedef unsigned long      uint32_t;
  typedef unsigned long long uint64_t;

  // Signed integer types
  typedef signed char        sint8_t;
  typedef signed short       sint16_t;
  typedef signed long        sint32_t;
  typedef signed long long   sint64_t;

  // Floating-point types
  typedef float              float32_t;
  typedef double             float64_t;

  // Character types
  typedef char               char_t;

  // Boolean type
  typedef _Bool              bool_t;

#elif (CPU_TYPE == CPU_TYPE_16)

  // Unsigned integer types
  typedef unsigned char      uint8_t;
  typedef unsigned short     uint16_t;
  typedef unsigned long      uint32_t;
  typedef unsigned long long uint64_t;

  // Signed integer types
  typedef signed char        sint8_t;
  typedef signed short       sint16_t;
  typedef signed long        sint32_t;
  typedef signed long long   sint64_t;

  // Floating-point types
  typedef float              float32_t;
  typedef double             float64_t;

  // Character types
  typedef char               char_t;

  // Boolean type
  typedef _Bool              bool_t;

#elif (CPU_TYPE == CPU_TYPE_8)

  // Unsigned integer types
  typedef unsigned char      uint8_t;
  typedef unsigned short     uint16_t;
  typedef unsigned long      uint32_t;

  // Signed integer types
  typedef signed char        sint8_t;
  typedef signed short       sint16_t;
  typedef signed long        sint32_t;

  // Floating-point types
  typedef float              float32_t;

  // Character types
  typedef char               char_t;

  // Boolean type
  typedef _Bool              bool_t;

#endif
/*_______________________________________________________________*/

#endif // !_STD_TYPES_H_