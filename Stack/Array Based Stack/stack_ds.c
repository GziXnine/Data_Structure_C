#include "stack_ds.h"

/*
 * @brief  : Check the status of the stack
 * @param  : my_stack => pointer to the stack structure
 * @retval : Return status indicating the current state of the stack
 */
static return_status_t stack_status(stack_ds_t *my_stack)
{
  return ((!my_stack) ? STACK_NULL_POINTER : (my_stack->stack_pointer == STACK_MAX_SIZE - 1) ? STACK_FULL
                                           : (my_stack->stack_pointer == -1)                 ? STACK_EMPTY
                                                                                             : STACK_NOT_FULL);
}

return_status_t stack_init(stack_ds_t *my_stack)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    my_stack->stack_pointer = -1;
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_push(stack_ds_t *my_stack, uint32_t value)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (stack_status(my_stack) == STACK_FULL)
    {
      retVal = STACK_FULL;
    }
    else
    {
      retVal = STACK_OK;

      my_stack->Data[++my_stack->stack_pointer] = value;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if(NULL != value)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *value = my_stack->Data[my_stack->stack_pointer--];
      }
      else
      {
        retVal = STACK_EMPTY;
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

return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (NULL != value)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *value = my_stack->Data[my_stack->stack_pointer];
      }
      else
      {
        retVal = STACK_EMPTY;
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

return_status_t stack_size(stack_ds_t *my_stack, sint32_t *stack_size)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (NULL != stack_size)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *stack_size = my_stack->stack_pointer + 1;
      }
      else
      {
        retVal = STACK_EMPTY;
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

return_status_t stack_display(stack_ds_t *my_stack)
{
  return_status_t retVal = STACK_NOK;
  sint32_t l_counter = ZERO_INIT;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    if (stack_status(my_stack) != STACK_EMPTY)
    {
      printf("Stack value : \n");
      for (l_counter = my_stack->stack_pointer; l_counter >= ZERO; --l_counter)
      {
        #ifdef STACK_DEBUG
          printf("%u  ", my_stack->Data[l_counter]);
        #endif // STACK_DEBUG
      }
      printf("\n");
    }
    else
    {
      retVal = STACK_EMPTY;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}