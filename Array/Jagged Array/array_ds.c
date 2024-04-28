#include "array_ds.h"

return_status_t arrayInit(array_node_t **Array, uint16_t rowNum)
{
  return_status_t retVal = ARRAY_NOK;
  array_node_t *tempNode = NULL;

  tempNode = (array_node_t *)malloc(sizeof(array_node_t));

  if (!tempNode)
  {
    retVal = ARRAY_ALLOC_FAIL;
  }
  else
  {
    retVal = ARRAY_OK;

    tempNode->rowNum = rowNum;
    tempNode->rows = (uint32_t **)calloc(rowNum, sizeof(uint32_t *));
    tempNode->sizes = (uint32_t *)calloc(rowNum, sizeof(uint32_t));
    *Array = tempNode;
  }

  return retVal;
}

return_status_t setRowSize(array_node_t *Array, uint16_t rowIndex, uint16_t rowSize)
{
  return_status_t retVal = ARRAY_NOK;

  if (NULL != Array)
  {
    retVal = ARRAY_OK;

    Array->sizes[rowIndex] = rowSize;
    Array->rows[rowIndex] = (uint32_t *)calloc(rowSize, sizeof(uint32_t));
  }
  else
  {
    retVal = ARRAY_NULL_POINTER;
  }

  return retVal;
}

return_status_t setValue(array_node_t *Array, uint16_t row, uint16_t col, uint32_t Value)
{
  return_status_t retVal = ARRAY_NOK;

  if (NULL != Array)
  {
    if (row < (Array->rowNum) && col < (Array->sizes[row]))
    {
      retVal = ARRAY_OK;

      Array->rows[row][col] = Value;
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = ARRAY_NULL_POINTER;
  }

  return retVal;
}

return_status_t getValue(array_node_t *Array, uint16_t row, uint16_t col, uint32_t *Value)
{
  return_status_t retVal = ARRAY_NOK;

  if (NULL != Array)
  {
    if (NULL != Value)
    {
      if (row < (Array->rowNum) && col < (Array->sizes[row]))
      {
        retVal = ARRAY_OK;

        *Value = Array->rows[row][col];
      }
      else
      {
        retVal = INVALID_POSITION;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = ARRAY_NULL_POINTER;
  }

  return retVal;
}

return_status_t freeJaggedArray(array_node_t *Array)
{
  return_status_t retVal = ARRAY_NOK;
  uint16_t index_1 = ZERO_INIT;

  if (NULL != Array)
  {
    retVal = ARRAY_OK;

    for (index_1 = ZERO; index_1 < (Array->rowNum); ++index_1)
    {
      free(Array->rows[index_1]);
    }

    free(Array->rows);
    free(Array->sizes);
    free(Array);
  }
  else
  {
    retVal = ARRAY_NULL_POINTER;
  }

  return retVal;
}

return_status_t printJaggedArray(array_node_t *Array)
{
  return_status_t retVal = ARRAY_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;
  uint32_t Value = ZERO;

  if (NULL != Array)
  {
    retVal = ARRAY_OK;

    for (index_1 = ZERO; index_1 < Array->rowNum; ++index_1)
    {
      for (index_2 = ZERO; index_2 < Array->sizes[index_1]; ++index_2)
      {
        retVal = getValue(Array, index_1, index_2, &Value);
        printf(" %u ", Value);
      }
      printf("\n");
    }
  }
  else
  {
    retVal = ARRAY_NULL_POINTER;
  }

  return retVal;
}