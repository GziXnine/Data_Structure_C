#include "set_ds.h"

/**
 * @brief  Check the status of the set
 *
 * @param  set : pointer to the set structure
 *
 * @retval Return status indicating the current state of the set
 */
static return_status_t setStatus(Node *set)
{
  return ((!set) ? SET_NULL_POINTER : (set->length == 0) ? SET_EMPTY
                                                         : SET_HAS_SPACE);
}

Node* initialize()
{
    return NULL;
}

return_status_t contains(Node* set, uint32_t element)
{
    Node* current = set;
    while (current != NULL)
    {
        if (current->elements == element)
        {
            return SET_FOUND;
        }
        current = current->next;
    }
    return SET_NOT_FOUND;
}

return_status_t add(Node** set, uint32_t element)
{
    if (contains(*set, element) == SET_FOUND)
    {
        return SET_OK; // Element already exists
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return SET_ALLOC_FAIL;
    }
    newNode->elements = element;
    newNode->next = *set;
    *set = newNode;
    // Increment length
    (*set)->length++;
    
    return SET_OK;
}

return_status_t removeElement(Node** set, uint32_t element)
{
    Node* current = *set;
    Node* prev = NULL;

    while (current != NULL)
    {
        if (current->elements == element)
        {
            if (prev == NULL)
            {
                *set = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            // Decrement length
            (*set)->length--;
            return SET_OK;
        }
        prev = current;
        current = current->next;
    }
    return SET_NOT_FOUND;
}

uint8_t getSize(Node* set)
{
    return set != NULL ? set->length : 0;
}

return_status_t printSet(Node* set)
{
    if (set == NULL)
    {
        return SET_NULL_POINTER;
    }
    Node* current = set;
    while (current != NULL)
    {
        printf("%d ", current->elements);
        current = current->next;
    }
    printf("\n");
    return SET_OK;
}

return_status_t destroySet(Node** set)
{
    if (*set == NULL)
    {
        return SET_NULL_POINTER;
    }
    Node* current = *set;
    Node* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *set = NULL;
    return SET_OK;
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

Node *differenceSet(Node *set1, Node *set2)
{
  Node *interSect;
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

bool_t isEqual(Node *set1, Node *set2)
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

return_status_t clear(Node *set)
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

Node *copySet(Node *set)
{
  Node *newSet = NULL;
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

bool_t isSubset(Node *set1, Node *set2)
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

Node *complementSet(Node *set, Node *universeSet)
{
  Node *compSet = NULL;
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

return_status_t addMultiple(Node *set, uint32_t elements[], uint8_t numElements)
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

return_status_t removeMultiple(Node *set, uint32_t elements[], uint8_t numElements)
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