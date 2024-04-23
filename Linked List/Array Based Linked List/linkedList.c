#include "linkedList.h"

/**
 * @brief Check the status of the linked list
 *
 * This function checks the status of the linked list based on its size.
 *
 * @param List Pointer to the linked list structure.
 *
 * @retval linkedList_status_t Return status indicating the current state of the linked list.
 */
static linkedList_status_t linkedList_status(listNode_t *List)
{
  return ((!List) ?                   LINKED_LIST_NULL_POINTER : 
          (List->size == MAX_SIZE) ?  LINKED_LIST_FULL : 
          (List->size == ZERO) ?      LINKED_LIST_EMPTY : 
                                      LINKED_LIST_HAS_SPACE);
}

linkedList_status_t createList(listNode_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    List->size = ZERO;
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t destroyList(listNode_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    List->size = ZERO;
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Insert_Node_At_Position(listNode_t *List, uint32_t itemPtr, uint32_t Position)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  uint32_t counter;

  if (NULL != List)
  {
    if (linkedList_status(List) != LINKED_LIST_FULL)
    {
      if (Position <= List->size) // Check if position is within bounds
      {
        retVal = LINKED_LIST_OK;

        // Shift elements to make room for the new node
        for (counter = List->size; counter > Position; counter--)
        {
          List->data[counter] = List->data[counter - 1];
        }

        List->data[Position] = itemPtr;
        (List->size)++;
      }
      else
      {
        retVal = INVALID_POSITION;
      }
    }
    else
    {
      retVal = LINKED_LIST_FULL;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Delete_Node_At_Position(listNode_t *List, uint32_t *PtrOut, uint32_t Position)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  uint32_t counter = ZERO_INIT;

  if (NULL != List)
  {
    if (linkedList_status(List) != LINKED_LIST_EMPTY)
    {
      retVal = LINKED_LIST_OK;
      *PtrOut = List->data[Position];

      for (counter = Position + 1; counter <= List->size - 1; counter++)
      {
        List->data[counter - 1] = List->data[counter];
      }

      (List->size)--;
    }
    else
    {
      retVal = LINKED_LIST_EMPTY;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Display_All_Nodes(listNode_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  uint32_t counter = ZERO;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    for (counter = 0; counter < List->size; ++counter)
    {
      printf("%u -> ", List->data[counter]);
    }
    printf("\n");
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Get_Length(listNode_t *List, uint32_t *lenght)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    if (NULL != lenght)
    {
      retVal = LINKED_LIST_OK;

      *lenght = List->size;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t retrieveList(listNode_t *List, uint32_t Position, uint32_t *PtrOut)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    if (NULL != PtrOut)
    {
      if (Position <= List->size)
      {
        if (linkedList_status(List) != LINKED_LIST_EMPTY)
        {
          retVal = LINKED_LIST_OK;

          *PtrOut = List->data[Position];
        }
        else
        {
          retVal = LINKED_LIST_EMPTY;
        }
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
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t replaceList(listNode_t *List, uint32_t Position, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    if (Position <= List->size)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        List->data[Position] = itemPtr;
      }
      else
      {
        retVal = LINKED_LIST_EMPTY;
      }
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}