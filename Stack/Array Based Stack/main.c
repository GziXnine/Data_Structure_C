#include "stack_ds.h"

stack_ds_t myStack;
return_status_t retVal = STACK_NOK;
uint32_t value = ZERO_INIT, poppedValue = ZERO_INIT, toppedValue = ZERO_INIT;
sint32_t stackSize = ZERO_INIT;

int main()
{
  // Initialize the stack
  retVal = stack_init(&myStack);
  if (retVal == STACK_OK)
  {
    printf("Stack initialized successfully\n");

    // Push some values onto the stack
    value = 10;
    retVal = stack_push(&myStack, value);
    if (retVal == STACK_OK)
    {
      printf("Pushed value %u onto the stack\n", value);
    }
    else
    {
      printf("Failed to push value %u onto the stack\n", value);
    }

    // Push some values onto the stack
    value = 59;
    retVal = stack_push(&myStack, value);
    if (retVal == STACK_OK)
    {
      printf("Pushed value %u onto the stack\n", value);
    }
    else
    {
      printf("Failed to push value %u onto the stack\n", value);
    }

    // Push some values onto the stack
    value = 12;
    retVal = stack_push(&myStack, value);
    if (retVal == STACK_OK)
    {
      printf("Pushed value %u onto the stack\n", value);
    }
    else
    {
      printf("Failed to push value %u onto the stack\n", value);
    }

    // Display the stack
    retVal = stack_display(&myStack);
    if (retVal == STACK_OK)
    {
      printf("Displayed stack successfully\n");
    }
    else
    {
      printf("Failed to display stack\n");
    }

    // Pop a value from the stack
    retVal = stack_pop(&myStack, &poppedValue);
    if (retVal == STACK_OK)
    {
      printf("Popped value from the stack: %u\n", poppedValue);
    }
    else
    {
      printf("Failed to pop value from the stack\n");
    }

    // Display the stack after popping
    retVal = stack_display(&myStack);
    if (retVal == STACK_OK)
    {
      printf("Displayed stack after popping successfully\n");
    }
    else
    {
      printf("Failed to display stack after popping\n");
    }

    // Get the top value of the stack
    retVal = stack_top(&myStack, &toppedValue);
    if (retVal == STACK_OK)
    {
      printf("Top value of the stack: %u\n", toppedValue);
    }
    else
    {
      printf("Failed to get top value of the stack\n");
    }

    // Get the size of the stack
    retVal = stack_size(&myStack, &stackSize);
    if (retVal == STACK_OK)
    {
      printf("Size of the stack: %d\n", stackSize);
    }
    else
    {
      printf("Failed to get size of the stack\n");
    }
  }
  else
  {
    printf("Failed to initialize the stack\n");
  }
  
  return 0;
}