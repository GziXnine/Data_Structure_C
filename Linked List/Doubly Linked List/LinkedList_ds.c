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

linkedList_status_t Insert_Node_At_Beginning(node_ds_t *List, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = (listNode_t *)malloc(sizeof(listNode_t));

  if (!tempNode)
  {
    retVal = LINKED_LIST_ALLOC_FAIL;
  }
  else
  {
    if (NULL != List)
    {
      retVal = LINKED_LIST_OK;

      tempNode->data = itemPtr;
      tempNode->before = NULL;

      if (linkedList_status(List) == LINKED_LIST_EMPTY)
      {
        tempNode->next = NULL;
      }
      else
      {
        tempNode->next = List->head;
        List->head->before = tempNode;
      }
      List->head = tempNode;
      (List->size)++;
    }
    else
    {
      retVal = LINKED_LIST_NULL_POINTER;
    }
  }

  return retVal;
}

linkedList_status_t Insert_Node_At_End(node_ds_t *List, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = (listNode_t *)malloc(sizeof(listNode_t));
  listNode_t *lastNode = List->head;

  if (!tempNode)
  {
    retVal = LINKED_LIST_ALLOC_FAIL;
  }
  else
  {
    if (NULL != List)
    {
      retVal = LINKED_LIST_OK;

      tempNode->data = itemPtr;
      tempNode->next = NULL;

      if (linkedList_status(List) == LINKED_LIST_EMPTY)
      {
        tempNode->before = NULL;
        List->head = tempNode;
      }
      else
      {
        while (lastNode->next != NULL)
        {
          lastNode = lastNode->next;
        }
        lastNode->next = tempNode;
        tempNode->before = lastNode;
      }
      (List->size)++;
    }
    else
    {
      retVal = LINKED_LIST_NULL_POINTER;
    }
  }

  return retVal;
}

linkedList_status_t Insert_Node_At_Position(node_ds_t *List, uint32_t itemPtr, uint32_t Postion)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  listNode_t *tempNode = NULL, *nodeListCounter = NULL;
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
      tempNode->data = itemPtr;

      if (linkedList_status(List) == LINKED_LIST_EMPTY)
      {
        tempNode->before = NULL;
        tempNode->next = NULL;
        List->head = tempNode;
      }
      else
      {
        l_retVal = Get_Length(List, &listLength);

        if ((listLength > Postion) && (l_retVal == ZERO))
        {
          nodeListCounter = List->head;

          while (nodeCounter < Postion - 1)
          {
            nodeCounter++;
            nodeListCounter = nodeListCounter->next;
          }
          tempNode->next = nodeListCounter->next;
          tempNode->before = nodeListCounter;
          nodeListCounter->next->before = tempNode;
          nodeListCounter->next = tempNode;
        }
        else
        {
          retVal = INVALID_POSITION;
        }
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

linkedList_status_t Delete_Node_At_Beginning(node_ds_t *List, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  node_ds_t *tempNode = NULL;
  uint32_t listLength = ZERO_INIT;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        l_retVal = Get_Length(List, &listLength);

        if ((listLength == 1) && (l_retVal == ZERO))
        {
          free(List->head);
          List->head = NULL;
        }
        else
        {
          tempNode = List;
          *itemPtr = tempNode->head->data;
          List->head = tempNode->head->next;
          free(tempNode->head);
          List->head->before = NULL;
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
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Delete_Node_At_Position(node_ds_t *List, uint32_t Postion, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT, nodeCounter = ZERO_INIT;
  listNode_t *tempNode = NULL, *prevNode = NULL;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        l_retVal = Get_Length(List, &listLength);

        if ((listLength == 1) && (l_retVal == ZERO))
        {
          free(List->head);
          List->head = NULL;

          (List->size)--;
        }
        else if ((listLength > Postion) && (l_retVal == ZERO))
        {
          tempNode = (listNode_t *)List->head;

          while (nodeCounter < Postion)
          {
            nodeCounter++;
            prevNode = tempNode;
            tempNode = tempNode->next;
          }
          *itemPtr = tempNode->data;

          if (prevNode != NULL)
          {
            prevNode->next = tempNode->next;
          }
          else
          {
            List->head = tempNode->next;
          }
          tempNode->next->before = prevNode;
          free(tempNode);

          (List->size)--;
        }
        else if (listLength <= Postion)
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

linkedList_status_t Delete_Node_At_End(node_ds_t *List, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  listNode_t *tempNode = NULL;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        l_retVal = Get_Length(List, &listLength);

        if ((listLength == 1) && (l_retVal == ZERO))
        {
          free(List->head);
          List->head = NULL;
        }
        else
        {
          tempNode = (listNode_t *)List->head;

          while (tempNode->next != NULL)
          {
            tempNode = tempNode->next;
          }
          tempNode->before->next = NULL;
          *itemPtr = tempNode->data;
          free(tempNode);
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
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = LINKED_LIST_NULL_POINTER;
  }

  return retVal;
}

linkedList_status_t Display_Ascending_Order(node_ds_t *List)
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

      for (tempNode = List->head; tempNode != NULL; tempNode = tempNode->next)
      {
#ifdef LINKEDLIST_DEBUG
        printf("%i -> ", tempNode->data);
#endif // LINKEDLIST_DEBUG
      }
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

linkedList_status_t Display_Descending_Order(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, l_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  listNode_t *tempNode = List->head;

  if (NULL != List)
  {
    l_retVal = Get_Length(List, &listLength);

    if ((listLength >= 1) && (l_retVal == ZERO))
    {
      retVal = LINKED_LIST_OK;

      while (tempNode->next != NULL)
      {
        tempNode = tempNode->next;
      }

      while (tempNode != NULL)
      {
#ifdef LINKEDLIST_DEBUG
        printf(" <- %i", tempNode->data);
        tempNode = tempNode->before;
#endif // LINKEDLIST_DEBUG
      }
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
  listNode_t *tempNode = NULL;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    while (List->head != NULL)
    {
      tempNode = List->head->next;
      free(List->head);
      List->head = tempNode;
    }
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
  listNode_t *tempNode = (listNode_t *)List;
  uint32_t nodeCounter = 0;

  if (NULL != List)
  {
    if (NULL != itemPtr)
    {
      if (linkedList_status(List) != LINKED_LIST_EMPTY)
      {
        retVal = LINKED_LIST_OK;

        while (nodeCounter <= Postion)
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
  listNode_t *tempNode = (listNode_t *)List;
  uint32_t nodeCounter = 0;

  if (NULL != List)
  {
    if (linkedList_status(List) != LINKED_LIST_EMPTY)
    {
      retVal = LINKED_LIST_OK;

      while (nodeCounter <= Postion)
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