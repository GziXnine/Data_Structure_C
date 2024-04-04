#ifndef _STACK_DS_H_
#define _STACK_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define STACK_MAX_SIZE 100 // Define maximum size for the stack
#define STACK_DEBUG        // Enable debug mode for printing additional information

/*! Stack data structure */
typedef struct
{
  uint32_t Data[STACK_MAX_SIZE];  // Array to hold stack elements
  sint32_t stack_pointer;        // Index pointing to the top of the stack

} stack_ds_t; // Define stack data structure

typedef enum
{
  STACK_OK,               /* Stack operation performed successfully */
  STACK_NOK,              /* Stack operation not performed successfully */
  STACK_FULL,             /* Stack is full */
  STACK_HAS_SPACE,        /* Stack not full */
  STACK_EMPTY,            /* Stack is empty */
  STACK_NULL_POINTER,     /* NULL pointer passed to the stack operations */
  NULL_POINTER            /* Additional NULL pointer status */

} return_status_t;        // Define return status enumeration


/**
 * @brief  Initialize a new stack with the given capacity
 * 
 * @param  my_stack : pointer to the stack structure to be initialized
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_init(stack_ds_t *my_stack);

/**
 * @brief  Push an element onto the stack
 * 
 * @param  my_stack : pointer to the stack structure
 * @param  value    : value to be pushed onto the stack
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value);

/**
 * @brief  Pop an element from the stack
 * 
 * @param  my_stack : pointer to the stack structure
 * @param  value    : pointer to store the popped value
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value);

/**
 * @brief  Get the top element of the stack without removing it
 * 
 * @param  my_stack : pointer to the stack structure
 * @param  value    : pointer to store the top value
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value);

/**
 * @brief  Get the current size of the stack
 * 
 * @param  my_stack   : pointer to the stack structure
 * @param  stack_size : pointer to store the size of the stack
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_size(stack_ds_t *my_stack, sint32_t *stack_size);

/**
 * @brief  Display the elements of the stack
 * 
 * @param  my_stack : pointer to the stack structure
 * 
 * @retval Return status indicating success or failure
 */
return_status_t stack_display(stack_ds_t *my_stack);

#endif // !_STACK_DS_H_
