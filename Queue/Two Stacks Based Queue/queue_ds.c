#include "queue_ds.h"
#include "stack_ds.h"

queue_status_t queue_init(queue_ds_t *myQueue)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    retVal = QUEUE_OK;

    stack_init(&(myQueue->stack1));
    stack_init(&(myQueue->stack2));
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_count(queue_ds_t *myQueue, uint32_t *QueueCount)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    if (NULL != QueueCount)
    {
      retVal = QUEUE_OK;

      *QueueCount = (uint32_t)(myQueue->stack1.stack_pointer + myQueue->stack2.stack_pointer + (sint32_t)TWO);
    }
    else
    {
      retVal = NULL_POINTERS;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t Enqueue(queue_ds_t *myQueue, uint32_t item_ptr)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue) // O(1)
  {
    if (stack_status(&(myQueue->stack1)) != STACK_FULL) // O(1)
    {
      retVal = QUEUE_OK;

      stack_push(&(myQueue->stack1), item_ptr); // O(1)
    }
    else
    {
      retVal = QUEUE_FULL;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal; // Over All time Complexity of the Enqueue is O(1)
}

queue_status_t Dequeue(queue_ds_t *myQueue, uint32_t *ValueOut)
{
  queue_status_t retVal = QUEUE_NOK;
  uint32_t Value = ZERO_INIT;

  if (NULL != myQueue) // O(1)
  {
    if (NULL != ValueOut) // O(1)
    {
      retVal = QUEUE_OK;

      if (stack_status(&(myQueue->stack2)) == STACK_EMPTY) // O(1)
      {
        while (stack_status(&(myQueue->stack1)) != STACK_EMPTY)
        {
          stack_pop(&(myQueue->stack1), &Value); // O(1)
          stack_push(&(myQueue->stack2), Value); // O(1)
        }                                        // In worst case O(n), n is the number of the element in the queue.
      }

      if (stack_status(&(myQueue->stack2)) != STACK_EMPTY) // O(1)
      {
        stack_pop(&(myQueue->stack2), ValueOut); // O(1)
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
    else
    {
      retVal = NULL_POINTERS;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal; // Over All time Complexity of the Dequeue is O(n) in worst case and O(1) in average case.
}

queue_status_t queue_front(queue_ds_t *myQueue, uint32_t *Value)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    if (NULL != Value)
    {
      if (stack_status(&(myQueue->stack1)) != STACK_EMPTY)
      {
        retVal = QUEUE_OK;

        *Value = myQueue->stack1.Data[ZERO];
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
    else
    {
      retVal = NULL_POINTERS;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}

queue_status_t queue_rear(queue_ds_t *myQueue, uint32_t *Value)
{
  queue_status_t retVal = QUEUE_NOK;

  if (NULL != myQueue)
  {
    if (NULL != Value)
    {
      if (stack_status(&(myQueue->stack1)) != STACK_EMPTY)
      {
        retVal = QUEUE_OK;

        *Value = myQueue->stack1.Data[myQueue->stack1.stack_pointer];
      }
      else
      {
        retVal = QUEUE_EMPTY;
      }
    }
    else
    {
      retVal = NULL_POINTERS;
    }
  }
  else
  {
    retVal = QUEUE_NULL_POINTER;
  }

  return retVal;
}