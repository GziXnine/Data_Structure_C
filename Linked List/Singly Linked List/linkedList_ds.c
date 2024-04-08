#include "linkedList_ds.h"

node_ds_t *Insert_Node_At_Beginning(node_ds_t **List, uint32_t *itemPtr, linkedList_status_t *retVal)
{
  node_ds_t *tempNode = (node_ds_t *)malloc(sizeof(node_ds_t));

  if (!tempNode)
  {
    *retVal = LINKED_LIST_ALLOC_FAIL;
  }
  else
  {
    if (NULL != itemPtr)
    {
      tempNode->NodeData = *itemPtr;

      if (NULL != *List)
      {
        *retVal = LINKED_LIST_OK;

        tempNode->NodeLink = *List;
        *List = tempNode;
      }
      else
      {
        *retVal = LINKED_LIST_NULL_POINTER;

        tempNode->NodeLink = NULL;
        *List = tempNode;
      }
    }
    else
    {
      *retVal = NULL_POINTER;
    }
  }

  return tempNode;
}

linkedList_status_t Insert_Node_At_End(node_ds_t **List, uint32_t *itemPtr)
{
  linkedList_status_t retVal = LINKED_LIST_NOK;
  node_ds_t *tempNode = (node_ds_t *)malloc(sizeof(node_ds_t));
  node_ds_t *lastNode = NULL;

  if (!tempNode)
  {
    retVal = LINKED_LIST_ALLOC_FAIL;
  }
  else
  {
    if (NULL != itemPtr)
    {
      tempNode->NodeData = *itemPtr;
      tempNode->NodeLink = NULL;

      if (NULL != *List)
      {
        retVal = LINKED_LIST_OK;
        lastNode = *List;

        while (lastNode->NodeLink != NULL)
        {
          lastNode = lastNode->NodeLink;
        }
        lastNode->NodeLink = tempNode;
      }
      else
      {
        retVal = LINKED_LIST_EMPTY;

        *List = tempNode;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }

  return retVal;
}

linkedList_status_t Insert_Node_At_Position(node_ds_t *List, uint32_t *itemPtr, uint32_t *Postion)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, L_retVal = ZERO_INIT;
  node_ds_t *tempNode = (node_ds_t *)malloc(sizeof(node_ds_t));
  node_ds_t *nodeListCounter = NULL;
  uint32_t listLength = ZERO_INIT, nodeCounter = 1;

  if (!tempNode)
  {
    retVal = LINKED_LIST_ALLOC_FAIL;
  }
  else
  {
    if (NULL != itemPtr && NULL != Postion)
    {
      if (NULL != List)
      {
        retVal = LINKED_LIST_OK;
        listLength = Get_Length(List, &L_retVal);

        if ((listLength >= *Postion) && (L_retVal == ZERO))
        {
          nodeListCounter = List;

          while (nodeCounter < *Postion - 1)
          {
            nodeCounter++;
            nodeListCounter = nodeListCounter->NodeLink;
          }
          tempNode->NodeData = *itemPtr;
          tempNode->NodeLink = nodeListCounter->NodeLink;
          nodeListCounter->NodeLink = tempNode;
        }
        else
        {
          retVal = INVALID_POSOTION;
        }
      }
      else
      {
        retVal = LINKED_LIST_NULL_POINTER;

        List = tempNode;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }

  return retVal;
}

linkedList_status_t Delete_Node_At_Beginning(node_ds_t **List)
{
  linkedList_status_t L_retVal = LINKED_LIST_NOK, retVal = LINKED_LIST_NOK;
  uint32_t listLength = ZERO_INIT;
  node_ds_t *tempNode = *List;

  if (NULL != *List)
  {
    listLength = Get_Length(*List, &L_retVal);

    if ((listLength >= 1) && (L_retVal == ZERO))
    {
      retVal = LINKED_LIST_OK;

      *List = tempNode->NodeLink;
      tempNode->NodeLink = NULL;
      free(tempNode);
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

linkedList_status_t Delete_Node_At_Position(node_ds_t *List, uint32_t *Postion)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, L_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  node_ds_t *nodeListCounter = NULL;
  node_ds_t *nextNode = NULL;
  uint32_t nodeCounter = 1;

  if (NULL != List)
  {
    if (NULL != Postion)
    {
      listLength = Get_Length(List, &L_retVal);

      if ((listLength >= *Postion) && (L_retVal == ZERO))
      {
        retVal = LINKED_LIST_OK;
        nodeListCounter = nextNode = List;

        while (nodeCounter < *Postion - 1)
        {
          nodeCounter++;
          nodeListCounter = nodeListCounter->NodeLink;
        }
        nextNode = nodeListCounter->NodeLink;
        nodeListCounter->NodeLink = nextNode->NodeLink;
        free(nextNode);
      }
      else if (*Postion > listLength)
      {
        retVal = INVALID_POSOTION;
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

linkedList_status_t Delete_Node_At_End(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, L_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  uint32_t nodeCounter = 1;

  if (NULL != List)
  {
    listLength = Get_Length(List, &L_retVal);

    if ((listLength > 1) && (L_retVal == ZERO))
    {
      retVal = LINKED_LIST_OK;
      node_ds_t *tempNode = List;

      while (nodeCounter < listLength - 1)
      {
        nodeCounter++;
        tempNode = tempNode->NodeLink;
      }
      free(tempNode->NodeLink);
      tempNode->NodeLink = NULL;
    }
    else if (listLength == 1)
    {
      retVal = LINKED_LIST_OK;

      free(List);
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

linkedList_status_t Display_All_Nodes(node_ds_t *List)
{
  linkedList_status_t retVal = LINKED_LIST_NOK, L_retVal = ZERO_INIT;
  uint32_t listLength = ZERO_INIT;
  node_ds_t *tempNode = List;

  if (NULL != List)
  {
    listLength = Get_Length(List, &L_retVal);

    if ((listLength >= 1) && (L_retVal == ZERO))
    {
      retVal = LINKED_LIST_OK;

      while (tempNode != NULL)
      {
        printf("%i -> ", tempNode->NodeData);
        tempNode = tempNode->NodeLink;
      }
      if (NULL == tempNode)
      {
        printf("NULL \n");
      }
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

uint32_t Get_Length(node_ds_t *List, linkedList_status_t *retVal)
{
  uint32_t length = ZERO_INIT;
  node_ds_t *tempNode = List;

  if (NULL != retVal)
  {
    if (NULL != List)
    {
      *retVal = LINKED_LIST_OK;

      while (tempNode != NULL)
      {
        length++;
        tempNode = tempNode->NodeLink;
      }
    }
    else
    {
      *retVal = LINKED_LIST_NULL_POINTER;
    }
  }
  else
  {
    *retVal = NULL_POINTER;
  }

  return length;
}