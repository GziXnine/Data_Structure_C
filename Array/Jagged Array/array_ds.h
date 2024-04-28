#ifndef _ARRAY_DS_H_
#define _ARRAY_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

typedef struct JaggedArray 
{
  uint32_t **rows; // Array of pointers to integer arrays
  uint32_t *sizes; // Array to store the size of each row
  uint32_t rowNum; // Number of rows in the jagged array

} array_node_t;

typedef enum
{
  ARRAY_OK,               /* Array operation performed successfully */
  ARRAY_NOK,              /* Array operation not performed successfully */
  INVALID_POSITION,       /* Invalid position provided for the array operation */
  ARRAY_NULL_POINTER,     /* NULL pointer passed to the array operations */
  ARRAY_ALLOC_FAIL,       /* Memory allocation for array failed */
  NULL_POINTER            /* Additional NULL pointer status */

} return_status_t;        // Define return status enumeration

/**
 * Initializes a jagged array with the given number of rows.
 *
 * @param Array   : Pointer to the pointer to the array structure to be initialized.
 * @param rowNum  : Number of rows in the jagged array.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t arrayInit(array_node_t **Array, uint16_t rowNum);

/**
 * Sets the size of a specific row in the jagged array.
 *
 * @param Array     : Pointer to the array structure.
 * @param rowIndex  : Index of the row for which size is to be set.
 * @param rowSize   : Size of the row.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t setRowSize(array_node_t *Array, uint16_t rowIndex, uint16_t rowSize);

/**
 * Sets a value at a specific position in the jagged array.
 *
 * @param Array   : Pointer to the array structure.
 * @param row     : Row index.
 * @param col     : Column index.
 * @param Value   : Value to be set.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t setValue(array_node_t *Array, uint16_t row, uint16_t col, uint32_t Value);

/**
 * Retrieves a value from a specific position in the jagged array.
 *
 * @param Array   : Pointer to the array structure.
 * @param row     : Row index.
 * @param col     : Column index.
 * @param Value   : Pointer to store the retrieved value.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getValue(array_node_t *Array, uint16_t row, uint16_t col, uint32_t *Value);

/**
 * Frees memory allocated for the jagged array.
 *
 * @param Array   : Pointer to the array structure to be freed.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t freeJaggedArray(array_node_t *Array);

/**
 * Prints the jagged array.
 *
 * @param Array   : Pointer to the array structure to be printed.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t printJaggedArray(array_node_t *Array);

#endif // !_ARRAY_DS_H_