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

linkedList_status_t Insert_Sorted(node_ds_t *List, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = NULL, *newNode = NULL;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    newNode = (listNode_t *)malloc(sizeof(listNode_t));
    if (!newNode)
    {
      retVal = LINKED_LIST_ALLOC_FAIL;
    }
    else
    {
      retVal = LINKED_LIST_OK;

      newNode->data = itemPtr;

      // If the list is empty or the new node data is less than the head data
      if (List->size == 0 || itemPtr < List->head->data)
      {
        newNode->next = List->head;
        if (List->size == 0)
        {
          newNode->before = newNode;
          List->head = newNode;
        }
        else
        {
          newNode->before = List->head->before;
          List->head->before->next = newNode;
          List->head->before = newNode;
          List->head = newNode;
        }
      }
      else
      {
        tempNode = List->head;

        while (tempNode->next != List->head && tempNode->next->data < itemPtr)
        {
          tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        newNode->before = tempNode;
        tempNode->next->before = newNode;
        tempNode->next = newNode;
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

linkedList_status_t Delete_Node_By_Value(node_ds_t *List, uint32_t itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  listNode_t *tempNode = NULL;

  if (NULL != List)
  {
    retVal = LINKED_LIST_OK;

    if (List->size == 0) // Empty list
    {
      retVal = LINKED_LIST_EMPTY;
    }
    else if (List->size == 1) // Only one node in the list
    {
      if (List->head->data == itemPtr)
      {
        free(List->head);
        List->head = NULL;
        List->size = 0;
      }
      else
      {
        retVal = ITEM_NOT_FOUND;
      }
    }
    else // Multiple nodes in the list
    {
      tempNode = List->head;

      do
      {
        if (tempNode->data == itemPtr)
        {
          if (tempNode == List->head) // Node to delete is the head
          {
            List->head->before->next = List->head->next;
            List->head->next->before = List->head->before;
            List->head = List->head->next;
            free(tempNode);
          }
          else // Node to delete is not the head
          {
            tempNode->before->next = tempNode->next;
            tempNode->next->before = tempNode->before;
            free(tempNode);
          }

          (List->size)--;
          retVal = LINKED_LIST_OK;
          break;
        }

        tempNode = tempNode->next;
      } while (tempNode != List->head);

      if (tempNode == List->head) // Reached back to the head without finding the item
      {
        retVal = ITEM_NOT_FOUND;
      }
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