#include "stack_ds.h"

/**
 * @brief  Check the status of the stack
 *
 * @param  my_stack : pointer to the stack structure
 *
 * @retval Return status indicating the current state of the stack
 */
static return_status_t stack_status(stack *my_stack)
{
  return ((!my_stack) ?             STACK_NULL_POINTER : 
          (my_stack->top == NULL) ? STACK_EMPTY : 
                                    STACK_HAS_SPACE);
}

return_status_t stack_init(stack *my_stack)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    my_stack->top = NULL;
    my_stack->size = ZERO;
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_push(stack *my_stack, uint32_t value)
{
  return_status_t retVal = STACK_NOK;
  stack_node_t *tempNode = NULL;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    tempNode = (stack_node_t *)calloc(1, sizeof(stack_node_t));

    if (!tempNode)
    {
      retVal = NULL_POINTER;
    }
    else
    {
      tempNode->Data = value;
      tempNode->stack_pointer = my_stack->top;
      my_stack->top = tempNode;
      (my_stack->size)++;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_pop(stack *my_stack, uint32_t *value)
{
  return_status_t retVal = STACK_NOK;
  stack_node_t *tempNode = NULL;

  if (NULL != my_stack)
  {
    if (NULL != value)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *value = my_stack->top->Data;
        tempNode = my_stack->top = my_stack->top->stack_pointer;
        free(tempNode);
        (my_stack->size)--;
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

return_status_t stack_top(stack *my_stack, uint32_t *value)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (NULL != value)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *value = my_stack->top->Data;
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

return_status_t stack_size(stack *my_stack, sint32_t *stack_size)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (NULL != stack_size)
    {
      retVal = STACK_OK;

      if (stack_status(my_stack) != STACK_EMPTY)
      {
        *stack_size = my_stack->size;
      }
      else
      {
        retVal = STACK_EMPTY;

        *stack_size = ZERO;
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

return_status_t stack_display(stack *my_stack)
{
  stack_node_t *tempNode = my_stack->top;
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    if (stack_status(my_stack) != STACK_EMPTY)
    {
      printf("Stack Data : \n");

      while(tempNode != NULL)
      {
        #ifdef STACK_DEBUG
          printf("%u  ", tempNode->Data);
          tempNode = tempNode->stack_pointer;
        #endif // STACK_DEBUG
      }
      printf("\n");
    }
    else
    {
      retVal = STACK_EMPTY;

      printf("Stack is Empty ^_^ \n");
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_clear(stack *my_stack)
{
  return_status_t retVal = STACK_NOK;
  stack_node_t *tempNode = my_stack->top;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    if (stack_status(my_stack) != STACK_EMPTY)
    {
      while(tempNode != NULL)
      {
        tempNode = tempNode->stack_pointer;
        free(my_stack->top);
        my_stack->top = tempNode;
      }
      my_stack->size = ZERO;
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