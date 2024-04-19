#include "queue_ds.h"

/**
 * @brief  Get the current status of the queue (empty, full, or neither)
 *
 * @param  my_queue   : Pointer to the queue structure
 *
 * @retval Status indicating the current status of the queue
 */
static queue_status_t queue_status(queue *my_queue)
{
  return ((NULL == my_queue) ?  QUEUE_NULL_POINTER : 
          (!my_queue->rear) ?   QUEUE_EMPTY : 
                                QUEUE_HAS_SPACE);
}

queue_status_t queue_create(queue *my_queue)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != my_queue)
  {
    retVal = QUEUE_OK;

    my_queue->front = NULL;
    my_queue->rear = NULL;
    my_queue->size = ZERO;
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_clear(queue *my_queue)
{
  queue_status_t retVal = QUEUE_NOK;
  queue_node_t *tempNode = NULL;

  if (NULL != my_queue)
  {
    retVal = QUEUE_OK;

    while (my_queue->front != NULL)
    {
      tempNode = my_queue->front;
      my_queue->front = my_queue->front->next;
      free(tempNode);
    }
    my_queue->rear = NULL;
    my_queue->size = ZERO;
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_count(queue *my_queue, uint32_t *QueueCount)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != my_queue)
  {
    if (NULL != QueueCount)
    {
      retVal = QUEUE_OK;

      *QueueCount = my_queue->size;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t Enqueue(queue *my_queue, void *item_ptr)
{
  queue_status_t retVal = QUEUE_NOK;
  queue_node_t *tempNode = NULL;

  if (NULL != my_queue)
  {
    if (NULL != item_ptr)
    {
      retVal = QUEUE_OK;

      tempNode = (queue_node_t *)malloc(sizeof(queue_node_t));

      if (!tempNode)
      {
        retVal = QUEUE_ALLOC_FAIL;
      }
      else
      {
        tempNode->Data = *(uint32_t *)item_ptr;
        tempNode->next = NULL;

        if (!my_queue->rear)
        {
          // If queue is empty, both front and rear should point to the new node
          my_queue->front = tempNode;
        }
        else
        {
          // If queue is not empty, just update rear pointer
          my_queue->rear->next = tempNode;
        }
        my_queue->rear = tempNode;
        (my_queue->size)++;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t Dequeue(queue *my_queue, uint32_t *item_ptr)
{
  queue_status_t retVal = QUEUE_NOK;
  queue_node_t *tempNode = NULL;

  if (NULL != my_queue)
  {
    if (NULL != item_ptr)
    {
      if (queue_status(my_queue) != QUEUE_EMPTY)
      {
        retVal = QUEUE_OK;

        tempNode = my_queue->front;
        *item_ptr = tempNode->Data;
        my_queue->front = tempNode->next;
        free(tempNode);

        if (!my_queue->front)
        {
          my_queue->rear = NULL;
        }
        (my_queue->size)--;
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_front(queue *my_queue, uint32_t *itemOut)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != my_queue)
  {
    if (!itemOut)
    {
      retVal = NULL_POINTER;
    }
    else
    {
      if (queue_status(my_queue) != QUEUE_EMPTY)
      {
        retVal = QUEUE_OK;

        *itemOut = my_queue->front->Data;
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_rear(queue *my_queue, uint32_t *itemOut)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != my_queue)
  {
    if (!itemOut)
    {
      retVal = NULL_POINTER;
    }
    else
    {
      if (queue_status(my_queue) != QUEUE_EMPTY)
      {
        retVal = QUEUE_OK;

        *itemOut = my_queue->rear->Data;
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_display(queue *my_queue)
{
  queue_node_t *tempNode = NULL;
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != my_queue)
  {
    retVal = QUEUE_OK;

    if (queue_status(my_queue) != QUEUE_EMPTY)
    {
      printf("Queue Data : \n");

      for (tempNode = my_queue->front; tempNode != NULL; tempNode = tempNode->next)
      {
#ifdef QUEUE_DEBUG
        printf("%u  ", tempNode->Data);
#endif // QUEUE_DEBUG
      }
      printf("\n");
    }
    else
    {
      retVal = QUEUE_EMPTY;

      printf("Queue is Empty ^_^ \n");
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}