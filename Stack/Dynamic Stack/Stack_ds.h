#ifndef _STACK_ARRAY_DS_H_
#define _STACK_ARRAY_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

typedef struct
{
  void **StackArray;     /* points to the array that allocated in the heap */
  uint32_t ElementCount; /* Has a actual number of elements in the stack */
  uint32_t stackMaxSize; /* Has the maximum number of elements in the stack */
  sint32_t StackTop;     /* Has the index of the top element in the stack */

} stack_ds_t; // Define stack data structure

typedef enum
{
  STACK_OK,               /* Stack operation performed successfully */
  STACK_NOK,              /* Stack operation not performed successfully */
  STACK_FULL,             /* Stack is full */
  STACK_NOT_FULL,         /* Stack not full */
  STACK_EMPTY,            /* Stack is empty */
  STACK_NULL_POINTER,     /* NULL pointer passed to the stack operations */
  NULL_POINTER            /* Additional NULL pointer status */

} stack_status_t; // Define return status enumeration

/*
  * @brief  : Create an empty stack by allocating memory for the head structure and the array
  * @param  : (maxSize) Maximum number of elements in the stack
  * @param  : (ret_status) Status returned while performing this operation
  * @retval : Pointer to the allocated stack in the heap
*/
stack_ds_t *stack_create(uint32_t maxSize, stack_status_t *ret_status);

/*
  * @brief  : Destroy the stack and free allocated memory
  * @param  : (stack_obj) Pointer to the stack structure
  * @param  : (ret_status) Status returned while performing this operation
  * @retval : NULL if successful, otherwise pointer to the stack object
*/
stack_ds_t *stack_distroy(stack_ds_t *myStack, stack_status_t *ret_status);

/*
  * @brief  : Get the current number of elements in the stack
  * @param  : (stack_obj) Pointer to the stack structure
  * @param  : (stack_count) Pointer to store the number of elements
  * @retval : Status indicating success or failure
*/
stack_status_t stack_count(stack_ds_t *myStack, uint32_t *stack_count);

/*
  * @brief  : Push an item onto the stack
  * @param  : (stack_obj) Pointer to the stack structure
  * @param  : (itemPtr) Pointer to the item to be pushed onto the stack
  * @retval : Status indicating success or failure
*/
stack_status_t stack_push(stack_ds_t *myStack, void *itemPtr);

/*
  * @brief  : Pop an item from the stack
  * @param  : (stack_obj) Pointer to the stack structure
  * @param  : (ret_status) Status returned while performing this operation
  * @retval : Pointer to the popped item, or NULL if the stack is empty
*/
void *stack_pop(stack_ds_t *myStack, stack_status_t *ret_status);

/*
  * @brief  : Get the top item of the stack without removing it
  * @param  : (stack_obj) Pointer to the stack structure
  * @param  : (ret_status) Status returned while performing this operation
  * @retval : Pointer to the top item, or NULL if the stack is empty
*/
void *stack_top(stack_ds_t *myStack, stack_status_t *ret_status);

#endif // !_STACK_ARRAY_DS_H_