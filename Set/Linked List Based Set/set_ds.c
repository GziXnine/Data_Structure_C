#include "set_ds.h"

return_status_t contains(Node *set, uint32_t element)
{
  return_status_t retVal = SET_NOT_FOUND;
  Node *current = set;

  while (current != NULL)
  {
    if (current->elements == element)
    {
      retVal = SET_FOUND;
    }
    current = current->next;
  }

  return retVal;
}

return_status_t add(Node **set, uint32_t element)
{
  return_status_t retVal = SET_NOK;
  Node *current = NULL, *new_node = NULL;

  if (set != NULL)
  {
    retVal = SET_NOK;

    current = *set;
    while (current != NULL)
    {
      if (current->elements == element)
      {
        retVal = SET_FOUND;
        return retVal;
      }
      current = current->next;
    }

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
      retVal = SET_NOK;
      return retVal;
    }
    new_node->elements = element;
    new_node->next = NULL;

    if (*set == NULL)
    {
      *set = new_node;
      retVal = SET_OK;
      return retVal;
    }

    current = *set;
    while (current->next != NULL)
    {
      current = current->next;
    }

    current->next = new_node;
    retVal = SET_OK;
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeElement(Node **set, uint32_t element)
{
  return_status_t retVal = SET_NOK;
  Node *current = *set, *prev = NULL;

  if (*set != NULL)
  {
    retVal = SET_OK;

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
      }
      prev = current;
      current = current->next;
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

uint32_t getSize(Node *set)
{
  if (set == NULL)
  {
    return 0;
  }

  uint32_t count = 0;
  Node *current = set;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

return_status_t printSet(Node *set)
{
  if (set == NULL)
  {
    printf("Set is empty.\n");
    return SET_EMPTY;
  }

  Node *current = set;

  while (current != NULL)
  {
    printf("%d", current->elements);
    if (current->next != NULL)
    {
      printf(", ");
    }
    current = current->next;
  }
  printf(".\n");

  return SET_OK;
}

return_status_t destroySet(Node **set)
{
  return_status_t retVal = SET_NOK;

  if (*set != NULL)
  {
    retVal = SET_OK;

    Node *current = *set;
    Node *next;

    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }

    *set = NULL; // This line has no effect, as set is a local variable.
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}

Node *unionSet(Node *set1, Node *set2)
{
  Node *unionSet = NULL, *current = NULL;

  if (NULL != set1 && NULL != set2)
  {
    current = set1;
    while (current != NULL)
    {
      add(&unionSet, current->elements);
      current = current->next;
    }

    current = set2;
    while (current != NULL)
    {
      if (contains(unionSet, current->elements) != SET_FOUND)
      {
        add(&unionSet, current->elements);
      }
      current = current->next;
    }
  }
  else
  {
    return NULL;
  }

  return unionSet;
}

Node *intersectSet(Node *set1, Node *set2)
{
  Node *interSect = NULL, *current = NULL;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) != 0)
    {
      current = set2;
      while (current != NULL)
      {
        if (contains(set1, current->elements) == SET_FOUND)
        {
          add(&interSect, current->elements);
        }
        current = current->next;
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
  Node *interSect = NULL, *current = NULL;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) != 0)
    {
      current = set1;
      while (current != NULL)
      {
        if (contains(set2, current->elements) == SET_NOT_FOUND)
        {
          add(&interSect, current->elements);
        }
        current = current->next;
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
  Node *current = NULL;

  if (NULL != set1 && NULL != set2)
  {
    if (getSize(set1) == getSize(set2))
    {
      current = set2;
      while (current != NULL)
      {
        if ((contains(set1, current->elements) == SET_NOT_FOUND))
        {
          return false;
        }
        current = current->next;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

  return true;
}

return_status_t clear(Node *set)
{
  return_status_t retVal = SET_NOK;
  Node *current = NULL;

  if (NULL != set)
  {
    retVal = SET_OK;

    current = set;
    while (current != NULL)
    {
      current->elements = ZERO_INIT;
      current = current->next;
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
  Node *newSet = NULL, *current = NULL;

  if (NULL != set)
  {
    current = set;
    while (current != NULL)
    {
      add(&newSet, current->elements);
      current = current->next;
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
  Node *current = NULL;

  if (NULL != set1 && NULL != set2)
  {
    current = set1;
    while (current != NULL)
    {
      if (contains(set2, current->elements) == SET_NOT_FOUND)
      {
        return false;
      }
      current = current->next;
    }
  }
  else
  {
    return false;
  }

  return true;
}

Node *complementSet(Node *set, Node *universeSet)
{
  Node *compSet = NULL, *current = NULL;

  if (NULL != set && NULL != universeSet)
  {
    current = set;
    while (current != NULL)
    {
      if (contains(universeSet, current->elements) == SET_NOT_FOUND)
      {
        add(&compSet, current->elements);
      }
      current = current->next;
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
      add(&set, elements[index]);
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
      removeElement(&set, elements[index]);
    }
  }
  else
  {
    retVal = SET_NULL_POINTER;
  }

  return retVal;
}