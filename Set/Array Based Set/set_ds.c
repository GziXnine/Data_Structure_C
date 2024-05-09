#include "set_ds.h"

/**
 * @brief  Check the status of the set
 *
 * @param  set : pointer to the set structure
 *
 * @retval Return status indicating the current state of the set
 */
static return_status_t setStatus(ArraySet *set)
{
  return ((!set) ?              SET_NULL_POINTER : 
          (set->length == 0) ?  SET_EMPTY : 
                                SET_HAS_SPACE);
}

ArraySet *initialize()
{
  ArraySet *set = (ArraySet *)malloc(sizeof(ArraySet));

  if (NULL != set)
  {
    set->elements = (uint32_t *)malloc(sizeof(uint32_t));
    set->length = ZERO;
  }

  return set;
}

return_status_t contains(ArraySet *set, uint32_t element)
{
  return_status_t retVal = SET_NOK;
  uint8_t index = ZERO_INIT;

  if (NULL != set)
  {
    for (index = ZERO; index < set->length; ++index)
    {
      if (element == set->elements[index])
      {
        retVal = SET_FOUND;
        break;
      }
      else
      {
        retVal = SET_NOT_FOUND;
      }
    }

    if (setStatus(set) == SET_EMPTY)
    {
      retVal = SET_NOT_FOUND;
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

return_status_t add(ArraySet *set, uint32_t element)
{
  return_status_t retVal = SET_NOK;

  if (NULL != set)
  {
    if (contains(set, element) == SET_NOT_FOUND)
    {
      retVal = SET_OK;

      set->elements = (uint32_t *)realloc(set->elements, sizeof(uint32_t) * (set->length + 1));

      if (!(set->elements))
      {
        retVal = SET_ALLOC_FAIL;
      }
      else
      {
        set->elements[(set->length)++] = element;
      }
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeElement(ArraySet *set, uint32_t element)
{
  return_status_t retVal = SET_NOK;
  uint8_t index1 = ZERO_INIT, index2 = ZERO_INIT;
  bool_t flag = ZERO_INIT;

  if (NULL != set)
  {
    retVal = SET_OK;

    for (index1 = ZERO; index1 < set->length; ++index1)
    {
      if (element == set->elements[index1])
      {
        flag = ONE;
        break;
      }
    }

    if (flag)
    {
      for (index2 = index1; index2 < set->length - 1; ++index2)
      {
        set->elements[index2] = set->elements[index2 + 1];
      }
      (set->length)--;
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

uint8_t getSize(ArraySet *set)
{
  if (NULL != set)
  {
    return set->length;
  }

  return ZERO;
}

return_status_t printSet(ArraySet *set)
{
  return_status_t retVal = SET_NOK;
  uint8_t index = ZERO_INIT;

  if (NULL != set)
  {
    retVal = SET_OK;

    for (index = ZERO; index < set->length; ++index)
    {
      printf((index == (set->length - 1)) ? "%d\n" : "%d, ", set->elements[index]);
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

return_status_t destroySet(ArraySet *set)
{
  return_status_t retVal = SET_NOK;

  if (set != NULL)
  {
    free(set->elements);
    set->elements = NULL;
    set->length = ZERO;
    free(set);

    retVal = SET_OK;
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

ArraySet *unionSet(ArraySet *set1, ArraySet *set2)
{
  ArraySet *unionSet;
  uint8_t index = ZERO_INIT;

  if (NULL != set1 && NULL != set2)
  {
    unionSet = initialize();

    for (index = ZERO; index < set1->length; ++index)
    {
      add(unionSet, set1->elements[index]);
    }

    for (index = ZERO; index < set2->length; ++index)
    {
      if (contains(unionSet, set2->elements[index]) != SET_FOUND)
      {
        add(unionSet, set2->elements[index]);
      }
    }
  }
  else
  {
    return NULL;
  }

  return unionSet;
}

ArraySet *intersectSet(ArraySet *set1, ArraySet *set2)
{
  ArraySet *interSect;
  uint8_t index = ZERO_INIT;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) == ZERO)
    {
      return NULL;
    }
    else
    {
      interSect = initialize();

      for (index = ZERO; index < set2->length; ++index)
      {
        if (contains(set1, set2->elements[index]) == SET_FOUND)
        {
          add(interSect, set2->elements[index]);
        }
      }
    }
  }
  else
  {
    return NULL;
  }

  return interSect;
}

ArraySet *differenceSet(ArraySet *set1, ArraySet *set2)
{
  ArraySet *interSect;
  uint8_t index = ZERO_INIT;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) == ZERO)
    {
      return NULL;
    }
    else
    {
      interSect = initialize();

      for (index = ZERO; index < set1->length; ++index)
      {
        if (contains(set2, set1->elements[index]) == SET_NOT_FOUND)
        {
          add(interSect, set1->elements[index]);
        }
      }
    }
  }
  else
  {
    return NULL;
  }

  return interSect;
}

bool_t isEqual(ArraySet *set1, ArraySet *set2)
{
  uint8_t index = ZERO_INIT;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) == getSize(set2))
    {
      for (index = ZERO; index < set2->length; ++index)
      {
        if ((contains(set1, set2->elements[index]) == SET_NOT_FOUND))
        {
          return false;
        }
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return NULL;
  }

  return true;
}

return_status_t clear(ArraySet *set)
{
  return_status_t retVal = SET_NOK;
  uint8_t index = ZERO_INIT;

  if (NULL != set)
  {
    retVal = SET_OK;

    for (index = ZERO; index < set->length; ++index)
    {
      set->elements[index] = ZERO_INIT;
      set->length = ZERO;
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

ArraySet *copySet(ArraySet *set)
{
  ArraySet *newSet = NULL;
  uint8_t index = ZERO_INIT;

  if (NULL != set)
  {
    newSet = initialize();

    for (index = ZERO; index < set->length; ++index)
    {
      add(newSet, set->elements[index]);
    }
  }
  else
  {
    return NULL;
  }

  return newSet;
}

bool_t isSubset(ArraySet *set1, ArraySet *set2)
{
  uint8_t index = ZERO_INIT;

  if (NULL != set1 && NULL != set2)
  {
    for (index = ZERO; index < set1->length; ++index)
    {
      if (contains(set2, set1->elements[index]) == SET_NOT_FOUND)
      {
        return false;
      }
    }
  }
  else
  {
    return NULL;
  }

  return true;
}

ArraySet *complementSet(ArraySet *set, ArraySet *universeSet)
{
  ArraySet *compSet = NULL;
  uint8_t index = ZERO_INIT;

  if (NULL != set && NULL != universeSet)
  {
    compSet = initialize();

    for (index = ZERO; index < set->length; ++index)
    {
      if (contains(universeSet, set->elements[index]) == SET_NOT_FOUND)
      {
        add(compSet, set->elements[index]);
      }
    }
  }
  else
  {
    return NULL;
  }

  return compSet;
}

return_status_t addMultiple(ArraySet *set, uint32_t elements[], uint8_t numElements)
{
  return_status_t retVal = SET_NOK;
  uint8_t index = ZERO_INIT;

  if (NULL != set && elements != NULL)
  {
    retVal = SET_OK;

    for (index = 0; index < numElements; ++index)
    {
      add(set, elements[index]);
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeMultiple(ArraySet *set, uint32_t elements[], uint8_t numElements)
{
  return_status_t retVal = SET_NOK;
  uint8_t index = ZERO_INIT;

  if (NULL != set && elements != NULL)
  {
    retVal = SET_OK;

    for (index = 0; index < numElements; ++index)
    {
      removeElement(set, elements[index]);
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}