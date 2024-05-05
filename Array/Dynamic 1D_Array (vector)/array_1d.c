#include "array_1d.h"

return_status_t vector_init(Vector *vec, uint32_t capacity)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    vec->data = (uint32_t *)calloc(capacity, sizeof(uint32_t));

    if (NULL == vec->data)
    {
      retVal = VECTOR_ALLOC_FAIL;
    }
    else
    {
      vec->capacity = capacity;
      vec->size = ZERO_INIT;

      retVal = VECTOR_OK;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t push_back(Vector *vec, uint32_t value)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    if (vec->size >= vec->capacity)
    {
      vec->capacity *= 2;
      vec->data = (uint32_t *)realloc(vec->data, vec->capacity * sizeof(uint32_t));

      if (NULL == vec->data)
      {
        retVal = VECTOR_ALLOC_FAIL;

        return retVal;
      }
    }
    retVal = VECTOR_OK;

    vec->data[(vec->size)++] = value;
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t pop_back(Vector *vec, uint32_t *value)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    if (NULL != value)
    {
      retVal = VECTOR_OK;

      *value = vec->data[(vec->size)--];
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_at(Vector *vec, uint32_t index, uint32_t *data)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    if (data != NULL)
    {
      if (vec->size >= index)
      {
        retVal = VECTOR_OK;

        *data = vec->data[index];
      }
      else
      {
        retVal = VECTOR_INVALID_POSITION;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_free(Vector *vec)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    retVal = VECTOR_OK;

    free(vec->data);
    vec->capacity = ZERO;
    vec->size = ZERO;
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_size(Vector *vec, uint16_t *size)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    if (NULL != size)
    {
      retVal = VECTOR_OK;

      *size = vec->size;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_capacity(Vector *vec, uint32_t *capacity)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    if (NULL != capacity)
    {
      retVal = VECTOR_OK;

      *capacity = vec->capacity;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_clear(Vector *vec)
{
  return_status_t retVal = VECTOR_NOK;

  if (NULL != vec)
  {
    retVal = VECTOR_OK;

    vec->size = ZERO;
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_insert(Vector *vec, uint16_t index, uint32_t value)
{
  return_status_t retVal = VECTOR_NOK;
  uint16_t index_1 = ZERO_INIT;

  if (NULL != vec)
  {
    if (index >= vec->size)
    {
      retVal = VECTOR_INVALID_POSITION;
    }
    else
    {
      if (vec->size >= vec->capacity)
      {
        vec->capacity *= 2;
        vec->data = (uint32_t *)realloc(vec->data, vec->capacity * sizeof(uint32_t));

        if (NULL == vec->data)
        {
          retVal = VECTOR_ALLOC_FAIL;

          return retVal;
        }
      }

      for (index_1 = vec->size; index_1 > index; --index_1)
      {
        vec->data[index_1] = vec->data[index_1 - ONE];
      }
      vec->data[index] = value;
      ++(vec->size);

      retVal = VECTOR_OK;
    }
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}

return_status_t vector_erase(Vector *vec, uint16_t index)
{
  return_status_t retVal = VECTOR_NOK;
  uint16_t index_1 = ZERO_INIT;

  if (NULL != vec)
  {
    if (index >= vec->size)
    {
      retVal = VECTOR_INVALID_POSITION;
    }
    else
    {
      for (index_1 = index; index_1 < vec->size - ONE; ++index_1)
      {
        vec->data[index_1] = vec->data[index_1 + ONE];
      }
      --(vec->size);

      retVal = VECTOR_OK;
    } 
  }
  else
  {
    retVal = VECTOR_NULL_POINTER;
  }

  return retVal;
}