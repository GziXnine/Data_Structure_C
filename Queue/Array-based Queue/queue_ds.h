#ifndef _QUEUE_DS_H_
#define _QUEUE_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

typedef struct
{
  void **queueArray;     /* Pointer to the array that holds queue elements (allocated in heap) */
  uint32_t elementCount; /* Number of elements currently in the queue */
  uint32_t queueMaxSize; /* Maximum capacity of the queue */
  sint32_t queueFront;   /* Index of the front element in the queue */
  sint32_t queueRear;    /* Index of the rear element in the queue */

} queue_ds_t; // Define queue data structure

typedef enum
{
  QUEUE_OK,               /* Queue operation performed successfully */
  QUEUE_NOK,              /* Queue operation not performed successfully */
  QUEUE_FULL,             /* Queue is full */
  QUEUE_HAS_SPACE,        /* Queue not full */
  QUEUE_EMPTY,            /* Queue is empty */
  QUEUE_NULL_POINTER,     /* NULL pointer passed to the queue operations */
  QUEUE_ALLOC_FAIL,       /* Memory allocation for queue array failed */
  NULL_POINTER            /* Additional NULL pointer status */

} queue_status_t; // Define return status enumeration

/**
 * @brief  Create an empty queue by allocating memory for the head structure and the array
 * 
 * @param  maxSize    : Maximum number of elements in the queue
 * @param  ret_status : Status returned while performing this operation
 * 
 * @retval Pointer to the allocated queue in the heap
 */
queue_ds_t *queue_create(uint32_t maxSize, queue_status_t *ret_status);

/**
 * @brief  Destroy the queue and free allocated memory
 * 
 * @param  myQueue      : Pointer to the queue structure
 * @param  ret_status   : Pointer to a variable where the status of the operation will be stored
 * 
 * @retval NULL         : Indicates successful destruction of the queue
 */
queue_ds_t *queue_destroy(queue_ds_t *myQueue, queue_status_t *ret_status);

/**
 * @brief  Get the current number of elements in the queue
 * 
 * @param  myQueue   : Pointer to the queue structure
 * @param  QueueCount : Pointer to store the number of elements
 * 
 * @retval Status indicating success or failure
 */
queue_status_t queue_count(queue_ds_t *myQueue, uint32_t *QueueCount);

/**
 * @brief  Add an item to the rear of the queue
 * 
 * This function adds an element to the end of the queue, if there is space available.
 * It updates the rear pointer and the element count accordingly.
 *
 * @param  myQueue : Pointer to the queue structure
 * @param  item_ptr   : Pointer to the item to be added to the queue
 * 
 * @retval Status indicating success or failure
 */
queue_status_t Enqueue(queue_ds_t *myQueue, void *item_ptr);

/**
 * @brief  Remove and return the item at the front of the queue
 *
 * This function removes and returns the element at the front of the queue, if it's not empty.
 * It updates the front pointer, the element count, and handles wrap-around if needed.
 *
 * @param  myQueue  : Pointer to the queue structure
 * @param  ret_status : Status returned while performing this operation
 * 
 * @retval Pointer to the item at the front of the queue, or NULL if the queue is empty
 */
void *Dequeue(queue_ds_t *myQueue, queue_status_t *ret_status);

/**
 * @brief  Get the item at the front of the queue without removing it
 * 
 * @param  myQueue  : Pointer to the queue structure
 * @param  ret_status : Status returned while performing this operation
 * 
 * @retval Pointer to the item at the front of the queue, or NULL if the queue is empty
 */
void *queue_front(queue_ds_t *myQueue, queue_status_t *ret_status);

/**
 * @brief  Get the item at the rear of the queue without removing it
 * 
 * @param  myQueue  : Pointer to the queue structure
 * @param  ret_status : Status returned while performing this operation
 * 
 * @retval Pointer to the item at the rear of the queue, or NULL if the queue is empty
 */
void *queue_rear(queue_ds_t *myQueue, queue_status_t *ret_status);

#endif // !_QUEUE_DS_H_