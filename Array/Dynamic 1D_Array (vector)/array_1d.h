#ifndef _ARRAY_1D_H_
#define _ARRAY_1D_H_

#include "std_types.h"

// Define the vector structure
typedef struct
{
  uint32_t *data;    // Pointer to the array storing elements
  uint16_t size;     // Number of elements currently in the vector
  uint32_t capacity; // Total capacity of the vector

} Vector;

typedef enum
{
  VECTOR_OK,               /* Array operation performed successfully */
  VECTOR_NOK,              /* Array operation not performed successfully */
  VECTOR_INVALID_POSITION, /* Invalid position provided for the array operation */
  VECTOR_NULL_POINTER,     /* NULL pointer passed to the array operations */
  VECTOR_ALLOC_FAIL,       /* Memory allocation for array failed */
  NULL_POINTER             /* Additional NULL pointer status */

} return_status_t; // Define return status enumeration

/**
 * Initializes a vector with the given initial capacity.
 *
 * @param vec              : Pointer to the vector structure to be initialized.
 * @param capacity : Initial capacity of the vector.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_init(Vector *vec, uint32_t capacity);

/**
 * Appends a value to the end of the vector.
 *
 * @param vec   : Pointer to the vector structure.
 * @param value : Value to be appended.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t push_back(Vector *vec, uint32_t value);

/**
 * Removes the last element from the vector and stores it in the provided variable.
 *
 * @param vec   : Pointer to the vector structure.
 * @param value : Pointer to store the removed value.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t pop_back(Vector *vec, uint32_t *value);

/**
 * Retrieves the value at the specified index in the vector.
 *
 * @param vec   : Pointer to the vector structure.
 * @param index : Index of the value to retrieve.
 * @param data  : Pointer to store the retrieved value.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_at(Vector *vec, uint32_t index, uint32_t *data);

/**
 * Frees memory allocated for the vector.
 *
 * @param vec : Pointer to the vector structure to be freed.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_free(Vector *vec);

/**
 * Retrieves the current size of the vector.
 *
 * @param vec  : Pointer to the vector structure.
 * @param size : Pointer to store the size of the vector.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_size(Vector *vec, uint16_t *size);

/**
 * Retrieves the current capacity of the vector.
 *
 * @param vec       : Pointer to the vector structure.
 * @param capacity  : Pointer to store the capacity of the vector.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_capacity(Vector *vec, uint32_t *capacity);

/**
 * Clears all elements from the vector.
 *
 * @param vec : Pointer to the vector structure.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_clear(Vector *vec);

/**
 * Inserts a value at the specified index in the vector.
 *
 * @param vec    : Pointer to the vector structure.
 * @param index  : Index at which to insert the value.
 * @param value  : Value to be inserted.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_insert(Vector *vec, uint16_t index, uint32_t value);

/*
 * Erases the value at the specified index in the vector.
 *
 * @param vec    : Pointer to the vector structure.
 * @param index  : Index of the value to erase.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t vector_erase(Vector *vec, uint16_t index);

#endif // !_ARRAY_1D_H_