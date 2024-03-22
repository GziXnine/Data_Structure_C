#include "Stack_ds.h"

stack_ds_t *stackPtr = NULL;
void *itemPtr = NULL;
stack_status_t retVal = STACK_NOK;
uint32_t stackSize = ZERO_INIT, stackCount = ZERO_INIT;

int main()
{
  uint32_t var1 = 10;
  float32_t var2 = 13.3f;
  char_t var3 = 'A';
  stackSize = 3;

  stackPtr = stack_create(stackSize, &retVal);
  if (retVal == STACK_OK)
  {
    printf("Stack initialized successfully\n");

    retVal = stack_push(stackPtr, &var1);
    if (retVal == STACK_OK)
    {
      printf("Pushed value '%u' onto the stack\n", var1);
    }
    else if(retVal == STACK_FULL)
    {
      printf("Failed to push value '%u' onto the stack\n", var1);
    }

    retVal = stack_push(stackPtr, &var2);
    if (retVal == STACK_OK)
    {
      printf("Pushed value '%0.2f' onto the stack\n", var2);
    }
    else if(retVal == STACK_FULL)
    {
      printf("Failed to push value '%0.2f' onto the stack\n", var2);
    }

    retVal = stack_push(stackPtr, &var3);
    if (retVal == STACK_OK)
    {
      printf("Pushed value '%c' onto the stack\n", var3);
    }
    else if(retVal == STACK_FULL)
    {
      printf("Failed to push value '%c' onto the stack\n", var3);
    }

    retVal = stack_count(stackPtr, &stackCount);
    if (retVal == STACK_OK)
    {
      printf("size of stack is %u\n", stackCount);
    }

    itemPtr = stack_top(stackPtr, &retVal);
    if (retVal == STACK_OK)
    {
      printf("Top value in stack (%c) \n", *(char_t *)itemPtr);
    }
    else if(retVal == STACK_EMPTY)
    {
      printf("Failed to display value from the stack\n");
    }

    itemPtr = stack_pop(stackPtr, &retVal);
    if (retVal == STACK_OK)
    {
      printf("Popped value from stack (%c) \n", *(char_t *)itemPtr);
    }
    else if(retVal == STACK_EMPTY)
    {
      printf("Failed to display value from the stack\n");
    }

    itemPtr = stack_pop(stackPtr, &retVal);
    if (retVal == STACK_OK)
    {
      printf("Popped value from stack (%0.2f) \n", *(float32_t *)itemPtr);
    }
    else if(retVal == STACK_EMPTY)
    {
      printf("Failed to display value from the stack\n");
    }

    retVal = stack_count(stackPtr, &stackCount);
    if (retVal == STACK_OK)
    {
      printf("size of stack is %u\n", stackCount);
    }

    itemPtr = stack_pop(stackPtr, &retVal);
    if (retVal == STACK_OK)
    {
      printf("Popped value from stack (%u) \n", *(uint32_t *)itemPtr);
    }
    else if(retVal == STACK_EMPTY)
    {
      printf("Failed to display value from the stack\n");
    }

    retVal = stack_count(stackPtr, &stackCount);
    if (retVal == STACK_OK)
    {
      printf("size of stack is %u\n", stackCount);
    }
  }
  else
  {
    printf("Failed to initialize the stack\n");
  }

  stackPtr = stack_distroy(stackPtr, &retVal);
  if (retVal == STACK_OK)
  {
    printf("Stack distroied correctly\n");
  }
  else
  {
    printf("can't destroyed stack\n");
  }

  return 0;
}