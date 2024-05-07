#ifndef _ARRAY_2D_H_
#define _ARRAY_2D_H_

#include "std_types.h"

// Define the matrix structure
typedef struct
{
  uint32_t **data; // Pointer to the array storing elements
  uint16_t rows;   // Number of rows in the matrix
  uint16_t cols;   // Number of columns in the matrix

} Matrix;

typedef enum
{
  MATRIX_OK,               /* Array operation performed successfully */
  MATRIX_NOK,              /* Array operation not performed successfully */
  MATRIX_INVALID_POSITION, /* Invalid position provided for the array operation */
  MATRIX_NULL_POINTER,     /* NULL pointer passed to the array operations */
  MATRIX_ALLOC_FAIL,       /* Memory allocation for array failed */
  NULL_POINTER             /* Additional NULL pointer status */

} return_status_t;         // Define return status enumeration

/**
 * Initializes a matrix with the given number of rows and columns.
 *
 * @param mat       : Pointer to the matrix structure to be initialized.
 * @param rows      : Number of rows in the matrix.
 * @param cols      : Number of columns in the matrix.
 *
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_init(Matrix *matrix, uint16_t rows, uint16_t cols);

/**
 * Retrieves the value at the specified row and column in the matrix.
 *
 * @param mat       : Pointer to the matrix structure.
 * @param row       : Row index of the value to retrieve.
 * @param col       : Column index of the value to retrieve.
 * @param value     : Pointer to store the retrieved value.
 *
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_at(Matrix *matrix, uint16_t row, uint16_t col, uint32_t *value);

/**
 * Sets the value at the specified row and column in the matrix.
 *
 * @param mat       : Pointer to the matrix structure.
 * @param row       : Row index where the value is to be set.
 * @param col       : Column index where the value is to be set.
 * @param value     : Value to set.
 *
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_set(Matrix *matrix, uint16_t row, uint16_t col, uint32_t value);

/**
 * Frees memory allocated for the matrix.
 *
 * @param mat       : Pointer to the matrix structure to be freed.
 *
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_free(Matrix *matrix);

/**
 * Retrieves the number of rows in the matrix.
 *
 * @param mat       : Pointer to the matrix structure.
 * @param rows      : Pointer to store the number of rows.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_rows(Matrix *matrix, uint16_t *rows);

/**
 * Retrieves the number of columns in the matrix.
 *
 * @param mat       : Pointer to the matrix structure.
 * @param cols      : Pointer to store the number of columns.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_cols(Matrix *matrix, uint16_t *cols);

/**
 * Transposes the matrix (swaps rows and columns).
 *
 * @param mat       : Pointer to the matrix structure.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_transpose(Matrix *matrix);

/**
 * Copies the contents of one matrix to another.
 *
 * @param src       : Pointer to the source matrix.
 * @param dest      : Pointer to the destination matrix.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t matrix_copy(Matrix *src, Matrix *dest);

#endif // !_ARRAY_2D_H_