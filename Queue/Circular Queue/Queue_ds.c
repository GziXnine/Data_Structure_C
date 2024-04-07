#include "queue_ds.h"

/**
 * @brief  Get the current status of the queue (empty, full, or neither)
 *
 * @param  myQueue   : Pointer to the queue structure
 *
 * @retval Status indicating the current status of the queue
 */
static queue_status_t queue_status(queue_ds_t *myQueue)
{
  return ((NULL == myQueue) ?                                QUEUE_NULL_POINTER : 
          (myQueue->elementCount == myQueue->queueMaxSize) ? QUEUE_FULL : 
          (myQueue->elementCount == ZERO) ?                  QUEUE_EMPTY : 
                                                             QUEUE_HAS_SPACE);
}

queue_ds_t *queue_create(uint32_t maxSize, queue_status_t *ret_status)
{
  queue_ds_t *queuePtr = NULL; // pointer

  if (NULL != ret_status)
  {
    *ret_status = QUEUE_OK;

    queuePtr = (queue_ds_t *)malloc(sizeof(queue_ds_t));

    if (!queuePtr)
    {
      *ret_status = NULL_POINTER;
    }
    else
    {
      queuePtr->queueArray = (void **)calloc(queuePtr->queueMaxSize, sizeof(void *));

      if (!(queuePtr->queueArray))
      {
        free(queuePtr);
        queuePtr = NULL;
        *ret_status = QUEUE_ALLOC_FAIL;
      }
      else
      {
        *ret_status = QUEUE_OK;

        queuePtr->queueMaxSize = maxSize;
        queuePtr->elementCount = 0;
        queuePtr->queueFront = -1;
        queuePtr->queueRear = -1;
      }
    }
  }
  else
  {
    *ret_status = NULL_POINTER;
  }

  return queuePtr;
}

queue_ds_t *queue_destroy(queue_ds_t *myQueue, queue_status_t *ret_status)
{
  if (NULL != myQueue)
  {
    free(myQueue->queueArray);
    free(myQueue);

    *ret_status = QUEUE_OK;
  }
  else
  {
    *ret_status = QUEUE_NULL_POINTER;
  }

  return NULL;
}

queue_status_t queue_count(queue_ds_t *myQueue, uint32_t *QueueCount)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    if (NULL != QueueCount)
    {
      retVal = QUEUE_OK;

      *QueueCount = myQueue->elementCount;
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

queue_status_t Enqueue(queue_ds_t *myQueue, void *item_ptr)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    if (NULL != item_ptr)
    {
      if (queue_status(myQueue) != QUEUE_FULL)
      {
        retVal = QUEUE_OK;

        (myQueue->queueRear)++;

        if ((myQueue->queueRear) == (sint32_t)(myQueue->queueMaxSize))
        {
          myQueue->queueRear = 0;
        }
        myQueue->queueArray[myQueue->queueRear] = item_ptr;

        if ((myQueue->elementCount) == 0)
        {
          (myQueue->elementCount) = 1;
          (myQueue->queueFront) = 0;
        }
        else
        {
          (myQueue->elementCount)++;
        }
      }
      else
      {
        retVal = QUEUE_FULL;
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

void *Dequeue(queue_ds_t *myQueue, queue_status_t *ret_status)
{
  void *PtrOut = NULL;

  if (NULL != myQueue)
  {
    if (queue_status(myQueue) != QUEUE_EMPTY)
    {
      *ret_status = QUEUE_OK;

      PtrOut = myQueue->queueArray[myQueue->queueFront];
      (myQueue->queueFront)++;

      if ((myQueue->queueFront) == (sint32_t)(myQueue->queueMaxSize))
      {
        myQueue->queueFront = 0;
      }

      if (myQueue->elementCount == 1)
      {
        myQueue->queueFront = -1;
        myQueue->queueRear = -1;
      }
      else
      {
        (myQueue->elementCount)--;
      }
    }
    else
    {
      *ret_status = QUEUE_EMPTY;
    }
  }
  else
  {
    *ret_status = QUEUE_NULL_POINTER;
  }

  return PtrOut;
}

void *queue_front(queue_ds_t *myQueue, queue_status_t *ret_status)
{
  void *PtrOut = NULL;

  if (NULL != myQueue)
  {
    if (queue_status(myQueue) != QUEUE_EMPTY)
    {
      *ret_status = QUEUE_OK;

      PtrOut = myQueue->queueArray[myQueue->queueFront];
    }
    else
    {
      *ret_status = QUEUE_EMPTY;
    }
  }
  else
  {
    *ret_status = QUEUE_NULL_POINTER;
  }

  return PtrOut;
}

void *queue_rear(queue_ds_t *myQueue, queue_status_t *ret_status)
{
  void *PtrOut = NULL;

  if (NULL != myQueue)
  {
    if (queue_status(myQueue) != QUEUE_EMPTY)
    {
      *ret_status = QUEUE_OK;

      PtrOut = myQueue->queueArray[myQueue->queueRear];
    }
    else
    {
      *ret_status = QUEUE_EMPTY;
    }
  }
  else
  {
    *ret_status = QUEUE_NULL_POINTER;
  }

  return PtrOut;
}