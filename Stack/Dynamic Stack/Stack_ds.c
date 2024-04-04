#include "Stack_ds.h"

/**
 * @brief  Check the status of the stack
 * 
 * @param  myStack Pointer to the stack structure
 * 
 * @retval Return status indicating the current state of the stack
 */
static stack_status_t stack_status(stack_ds_t *myStack)
{
  return ((NULL == myStack)?                                STACK_NULL_POINTER : 
          (myStack->ElementCount == myStack->stackMaxSize)? STACK_FULL :
          (myStack->ElementCount == 0)?                     STACK_EMPTY :
                                                            STACK_HAS_SPACE);
}

stack_ds_t *stack_create(uint32_t maxSize, stack_status_t *ret_status)
{
  stack_ds_t *stackPtr = NULL; // Pointer
  
  if(NULL != ret_status)
  {
    *ret_status = STACK_OK;

    stackPtr = (stack_ds_t *)calloc(1, sizeof(stack_ds_t));

    if(!stackPtr)
    {
      *ret_status = NULL_POINTER;
    }
    else
    {
      stackPtr->ElementCount = 0;
      stackPtr->stackMaxSize = maxSize;
      stackPtr->StackTop = -1;
      stackPtr->StackArray = (void **)calloc(stackPtr->stackMaxSize, sizeof(void *));

      if(!(stackPtr->StackArray))
      {
        free(stackPtr);
        stackPtr = NULL;
        *ret_status = STACK_ALLOC_FAIL;
      }
      else
      {
        *ret_status = STACK_OK;
      }
    }
  }
  else
  {
    *ret_status = NULL_POINTER;
  }

  return stackPtr;
}

stack_ds_t *stack_distroy(stack_ds_t *myStack, stack_status_t *ret_status)
{
  if(NULL != myStack)
  {
    if(NULL != ret_status)
    {
      free(myStack->StackArray);
      free(myStack);

      *ret_status = STACK_OK;
    }
    else
    {
      *ret_status = NULL_POINTER;
    }
  }
  else
  {
    *ret_status = STACK_NULL_POINTER;
  }

  return NULL;
}

stack_status_t stack_count(stack_ds_t *myStack, uint32_t *stack_count)
{
  stack_status_t retVal = STACK_NOK;

  if(NULL != myStack)
  {
    if(NULL != stack_count)
    {
      retVal = STACK_OK;

      *stack_count = myStack->ElementCount;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

stack_status_t stack_push(stack_ds_t *myStack, void *itemPtr)
{
  stack_status_t retVal = STACK_NOK;

  if(NULL != myStack)
  {
    if(NULL != itemPtr)
    {
      if(stack_status(myStack) != STACK_FULL)
      {
        retVal = STACK_OK;

        (myStack->StackTop)++;
        myStack->StackArray[myStack->StackTop] = itemPtr;
        (myStack->ElementCount)++;
      }
      else
      {
        retVal = STACK_FULL;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

void *stack_pop(stack_ds_t *myStack, stack_status_t *ret_status)
{
  void *PtrOut = NULL;

  if(NULL != myStack)
  {
    if(NULL != ret_status)
    {
      if(stack_status(myStack) != STACK_EMPTY)
      {
        *ret_status = STACK_OK;

        PtrOut = myStack->StackArray[myStack->StackTop];
        (myStack->ElementCount)--;
        (myStack->StackTop)--;
      }
      else
      {
        *ret_status = STACK_EMPTY;
      }
    }
    else
    {
      *ret_status = NULL_POINTER;
    }
  }
  else
  {
    *ret_status = STACK_NULL_POINTER;
  }

  return PtrOut;
}

void *stack_top(stack_ds_t *myStack, stack_status_t *ret_status)
{
  void *PtrOut = NULL;

  if(NULL != myStack)
  {
    if(NULL != ret_status)
    {
      if(stack_status(myStack) != STACK_EMPTY)
      {
        *ret_status = STACK_OK;

        PtrOut = myStack->StackArray[myStack->StackTop];
      }
      else
      {
        *ret_status = STACK_EMPTY;
      }
    }
    else
    {
      *ret_status = NULL_POINTER;
    }
  }
  else
  {
    *ret_status = STACK_NULL_POINTER;
  }

  return PtrOut;
}