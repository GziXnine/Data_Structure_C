#include "LinkedList_ds.h"

/**
 * @brief  Check the status of the linked list
 *
 * @param  List : pointer to the linked list structure
 *
 * @retval Return status indicating the current state of the linked list
 */
static linkedList_status_t linkedList_status(node_ds_t *List)
{
  return ((!List) ?               LINKED_LIST_NULL_POINTER : 
          (List->size == ZERO) ?  LINKED_LIST_EMPTY : 
                                  LINKED_LIST_OK);
}

linkedList_status_t createList(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    List->head = NULL;
    List->size = ZERO;
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Insert_Node_At_Position(node_ds_t *List, uint32_t itemPtr, uint32_t Position)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = NULL, *prepNode = NULL;
  uint32_t listLength = ZERO_INIT, nodeCounter = ZERO_INIT;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    tempNode = (listNode_t *)malloc(sizeof(listNode_t));
    if (!tempNode)
    {
      retVal = LINKED_LIST_ALLOC_FAIL;
    }
    else
    {
      retVal = LINKED_LIST_OK;

      Get_Length(List, &listLength);
      tempNode->data = itemPtr;

      if (Position == 0 || listLength == 0) // Insert at beginning or for empty list
      {
        if (listLength == 0)
        {
          tempNode->next = tempNode;
          tempNode->before = tempNode;
          List->head = tempNode;
        }
        else
        {
          tempNode->next = List->head;
          prepNode = List->head;

          while (prepNode->next != List->head)
          {
            prepNode = prepNode->next;
          }
          tempNode->before = prepNode;
          prepNode->next = tempNode;
          List->head->before = tempNode;
          List->head = tempNode;
        }
      }
      else if (Position >= listLength) // Insert at end
      {
        prepNode = List->head->before;
        tempNode->next = List->head;
        tempNode->before = prepNode;
        prepNode->next = tempNode;
        List->head->before = tempNode;
      }
      else // Insert at specified position
      {
        prepNode = List->head;

        for (nodeCounter = 0; nodeCounter < Position - 1; nodeCounter++)
        {
          prepNode = prepNode->next;
        }
        tempNode->next = prepNode->next;
        tempNode->before = prepNode;
        prepNode->next->before = tempNode;
        prepNode->next = tempNode;
      }
      (List->size)++;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Delete_Node_At_Position(node_ds_t *List, uint32_t Position, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  uint32_t listLength = ZERO_INIT, nodeCounter = ZERO_INIT;
  listNode_t *tempNode = NULL;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = Get_Length(List, &listLength);

        if (Position < listLength)
        {
          retVal = LINKED_LIST_OK;
          tempNode = List->head;

          if (Position == 0)
          { 
            *itemPtr = tempNode->data;

            if (listLength == 1)
            { 
              free(List->head);
              List->head = NULL;
            }
            else
            {
              List->head->next->before = List->head->before;
              List->head->before->next = List->head->next;
              List->head = List->head->next;
              free(tempNode);
            }
          }
          else
          {
            while (nodeCounter < Position)
            {
              tempNode = tempNode->next;
              nodeCounter++;
            }
            *itemPtr = tempNode->data;
            tempNode->before->next = tempNode->next;
            tempNode->next->before = tempNode->before;
            free(tempNode);
          }
          (List->size)--;
        }
        else
        {
          retVal = INVALID_POSITION;
        }
      }
      else
      {
        retVal = LINKED_LIST_EMPTY;
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

linkedList_status_t Display_List(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  listNode_t *tempNode = NULL;

  if (NULL != List)
  {
    l_retVal = Get_Length(List, &listLength);

    if ((listLength >= 1) && (l_retVal == ZERO))
    {
      retVal = LINKED_LIST_OK;

      tempNode = List->head;

      do
      {
        printf("%i -> ", tempNode->data);
        tempNode = tempNode->next;

      } while (tempNode != List->head);

      printf("\n");
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

linkedList_status_t Get_Length(node_ds_t *List, uint32_t *size)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;

  if (NULL != size)
  {
    if (NULL != List)
    {
      retVal = LINKED_LIST_OK;

      *size = List->size;
    }
    else
    {
      retVal = LINKED_LIST_NULL_POINTER;
    }
  }
  else
  {
    retVal = NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t destroyList(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = NULL, *nextNode = NULL;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;
    tempNode = List->head;

    while (tempNode->next != List->head)
    {
      nextNode = tempNode->next;
      free(tempNode);
      tempNode = nextNode;
    }
    free(tempNode);

    List->head = NULL;
    List->size = ZERO;
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t retrieveList(node_ds_t *List, uint32_t Postion, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = List->head;
  uint32_t nodeCounter = 0;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        while (nodeCounter < Postion)
        {
          nodeCounter++;
          tempNode = tempNode->next;
        }
        *itemPtr = tempNode->data;
      }
      else
      {
        retVal = LINKED_LIST_EMPTY;
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

linkedList_status_t replaceList(node_ds_t *List, uint32_t Postion, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = List->head;
  uint32_t nodeCounter = ZERO_INIT;

  if (NULL != List)
  {
    if (linkedList_status(List) != LINKED_LIST_EMPTY)
    {
      retVal = LINKED_LIST_OK;

      while (nodeCounter < Postion)
      {
        nodeCounter++;
        tempNode = tempNode->next;
      }
      tempNode->data = itemPtr;
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