#ifndef _QUEUE_DS_H_
#define _QUEUE_DS_H_

#include "std_types.h" // Include necessary header file for standard data types
#include "stack_ds.h"

typedef struct
{
  stack_ds_t stack1; // stack for enqueue operation
  stack_ds_t stack2; // stack for dequeue operation

} queue_ds_t; // Define queue data structure

typedef enum
{
  QUEUE_OK,           /* Queue operation performed successfully */
  QUEUE_NOK,          /* Queue operation not performed successfully */
  QUEUE_FULL,         /* Queue is full */
  QUEUE_EMPTY,        /* Queue is empty */
  QUEUE_NULL_POINTER, /* NULL pointer passed to the queue operations */
  NULL_POINTERS       /* Additional NULL pointer status */

} queue_status_t; // Define return status enumeration

/**
 * @brief Initializes an empty queue by allocating memory for the head structure and the array.
 *
 * @param myQueue    : Pointer to the queue structure.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t queue_init(queue_ds_t *myQueue);

/**
 * @brief Gets the current number of elements in the queue.
 *
 * @param myQueue    : Pointer to the queue structure.
 * @param QueueCount : Pointer to store the number of elements.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t queue_count(queue_ds_t *myQueue, uint32_t *QueueCount);

/**
 * @brief Adds an item to the rear of the queue.
 *
 * This function adds an element to the end of the queue, if there is space available.
 * It updates the rear pointer and the element count accordingly.
 *
 * @param myQueue    : Pointer to the queue structure.
 * @param item_ptr   : Pointer to the item to be added to the queue.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t Enqueue(queue_ds_t *myQueue, uint32_t item_ptr);

/**
 * @brief Removes and returns the item at the front of the queue.
 *
 * This function removes and returns the element at the front of the queue, if it's not empty.
 * It updates the front pointer, the element count, and handles wrap-around if needed.
 *
 * @param myQueue    : Pointer to the queue structure.
 * @param ValueOut   : Pointer to store the dequeued value.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t Dequeue(queue_ds_t *myQueue, uint32_t *ValueOut);

/**
 * @brief Gets the item at the front of the queue without removing it.
 *
 * @param myQueue    : Pointer to the queue structure.
 * @param Value      : Pointer to store the front value.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t queue_front(queue_ds_t *myQueue, uint32_t *Value);

/**
 * @brief Gets the item at the rear of the queue without removing it.
 *
 * @param myQueue    : Pointer to the queue structure.
 * @param Value      : Pointer to store the rear value.
 *
 * @return queue_status_t indicating success or failure of the operation.
 */
queue_status_t queue_rear(queue_ds_t *myQueue, uint32_t *Value);

#endif // !_QUEUE_DS_H_