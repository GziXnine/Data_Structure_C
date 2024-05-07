#include "array_2d.h"

return_status_t matrix_init(Matrix *matrix, uint16_t rows, uint16_t cols)
{
  return_status_t retVal = MATRIX_NOK;
  sint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (!matrix)
  {
    retVal = MATRIX_NULL_POINTER;
  }
  else
  {
    retVal = MATRIX_OK;

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (uint32_t **)calloc(matrix->rows, sizeof(uint32_t *));

    if (!matrix->data)
    {
      retVal = MATRIX_ALLOC_FAIL;
    }
    else
    {
      for (index_1 = ZERO; index_1 < matrix->rows; ++index_1)
      {
        matrix->data[index_1] = (uint32_t *)calloc(matrix->cols, sizeof(uint32_t));

        if (!matrix->data[index_1])
        {
          retVal = MATRIX_ALLOC_FAIL;

          for (index_2 = index_1 - ONE; index_2 >= ZERO; --index_2)
          {
            free(matrix->data[index_2]);
          }
          free(matrix->data);
        }
      }
    }
  }

  return retVal;
}

return_status_t matrix_at(Matrix *matrix, uint16_t row, uint16_t col, uint32_t *value)
{
  return_status_t retVal = MATRIX_NOK;

  if (NULL != matrix)
  {
    if (NULL != value)
    {
      retVal = MATRIX_OK;

      *value = matrix->data[row][col];
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_set(Matrix *matrix, uint16_t row, uint16_t col, uint32_t value)
{
  return_status_t retVal = MATRIX_NOK;

  if (NULL != matrix)
  {
    retVal = MATRIX_OK;

    matrix->data[row][col] = value;
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_free(Matrix *matrix)
{
  return_status_t retVal = MATRIX_NOK;
  uint16_t index_1 = ZERO_INIT;

  if (matrix != NULL)
  {
    for (index_1 = ZERO; index_1 < matrix->rows; ++index_1)
    {
      free(matrix->data[index_1]);
    }
    free(matrix->data);

    retVal = MATRIX_OK;
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_rows(Matrix *matrix, uint16_t *rows)
{
  return_status_t retVal = MATRIX_NOK;

  if (matrix != NULL)
  {
    if (NULL != rows)
    {
      retVal = MATRIX_OK;

      *rows = matrix->rows;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_cols(Matrix *matrix, uint16_t *cols)
{
  return_status_t retVal = MATRIX_NOK;

  if (matrix != NULL)
  {
    if (NULL != cols)
    {
      retVal = MATRIX_OK;

      *cols = matrix->cols;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_transpose(Matrix *matrix)
{
  return_status_t retVal = MATRIX_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;
  Matrix tempNode;

  if (matrix != NULL)
  {
    matrix_init(&tempNode, matrix->cols, matrix->rows);

    //tempNode = matrix;

    for (index_1 = ZERO; index_1 < matrix->rows; ++index_1)
    {
      for (index_2 = ZERO; index_2 < matrix->cols; ++index_2)
      {
        tempNode.data[index_2][index_1] = matrix->data[index_1][index_2];
      }
    }
    matrix_copy(&tempNode, matrix);
    matrix_free(&tempNode);

    retVal = MATRIX_OK;
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}

return_status_t matrix_copy(Matrix *src, Matrix *dest)
{
  return_status_t retVal = MATRIX_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (src != NULL && dest != NULL)
  {
    if ((dest->cols >= src->cols) && (dest->rows >= src->rows))
    {
      for (index_1 = ZERO; index_1 < src->rows; ++index_1)
      {
        for (index_2 = ZERO; index_2 < src->cols; ++index_2)
        {
          dest->data[index_1][index_2] = src->data[index_1][index_2];
        }
      }

      retVal = MATRIX_OK;
    }
    else
    {
      retVal = MATRIX_INVALID_POSITION;
    }
  }
  else
  {
    retVal = MATRIX_NULL_POINTER;
  }

  return retVal;
}