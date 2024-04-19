#ifndef _QUEUE_DS_H_
#define _QUEUE_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define QUEUE_DEBUG // Enable debug mode for printing additional information

typedef struct queueNode
{
  uint32_t Data;
  struct queueNode *next;

} queue_node_t; // Define queue data structure

typedef struct
{
  queue_node_t *front;
  queue_node_t *rear;
  uint32_t size;

} queue;

typedef enum
{
  QUEUE_OK,           /* Queue operation performed successfully */
  QUEUE_NOK,          /* Queue operation not performed successfully */
  QUEUE_HAS_SPACE,    /* Queue not full */
  QUEUE_EMPTY,        /* Queue is empty */
  QUEUE_NULL_POINTER, /* NULL pointer passed to the queue operations */
  QUEUE_ALLOC_FAIL,   /* Memory allocation for queue array failed */
  NULL_POINTER        /* Additional NULL pointer status */

} queue_status_t; // Define return status enumeration

/**
 * @brief  Create an empty queue by allocating memory for the head structure and the array
 *
 * @param  my_queue    : Pointer to the queue structure
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_create(queue *my_queue);

/**
 * @brief  Destroy the queue and free allocated memory
 *
 * @param  my_queue   : Pointer to the queue structure
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_clear(queue *my_queue);

/**
 * @brief  Get the current number of elements in the queue
 *
 * @param  my_queue   : Pointer to the queue structure
 * @param  queueCount : Pointer to store the number of elements
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_count(queue *my_queue, uint32_t *queueCount);

/**
 * @brief  Add an item to the rear of the queue
 *
 * This function adds an element to the end of the queue, if there is space available.
 * It updates the rear pointer and the element count accordingly.
 *
 * @param  my_queue   : Pointer to the queue structure
 * @param  item_ptr   : Pointer to the item to be added to the queue
 *
 * @retval Status indicating success or failure
 */
queue_status_t Enqueue(queue *my_queue, void *item_ptr);

/**
 * @brief  Remove and return the item at the front of the queue
 *
 * This function removes and returns the element at the front of the queue, if it's not empty.
 * It updates the front pointer, the element count, and handles wrap-around if needed.
 *
 * @param  my_queue  : Pointer to the queue structure
 * @param  item_ptr  : Pointer to store the item removed from the front of the queue.
 *
 * @retval Pointer to the item at the front of the queue, or NULL if the queue is empty
 */
queue_status_t Dequeue(queue *my_queue, uint32_t *item_ptr);

/**
 * @brief  Get the item at the front of the queue without removing it
 *
 * @param  my_queue   : Pointer to the queue structure
 * @param  itemOut    : Pointer to store the item at the front of the queue
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_front(queue *my_queue, uint32_t *itemOut);

/**
 * @brief  Get the item at the rear of the queue without removing it
 *
 * @param  my_queue   : Pointer to the queue structure
 * @param  itemOut    : Pointer to store the item at the rear of the queue
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_rear(queue *my_queue, uint32_t *itemOut);

/**
 * @brief  Display the elements of the queue
 *
 * @param  my_queue   : Pointer to the queue structure
 *
 * @retval Status indicating success or failure
 */
queue_status_t queue_display(queue *my_queue);

#endif // !_QUEUE_DS_H_