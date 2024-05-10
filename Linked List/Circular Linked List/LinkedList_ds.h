#ifndef _LINKEDLIST_DS_H_
#define _LINKEDLIST_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define LINKEDLIST_DEBUG // Enable debug mode for printing additional information

typedef struct listNode
{
  struct listNode *before;
  struct listNode *next;
  uint32_t data;

} listNode_t; // Define node data structure for linked list

typedef struct head
{
  listNode_t *head; // Point to the head of the linked
  uint32_t size;    // Number of elements in the linked list

} node_ds_t;

typedef enum
{
  LINKED_LIST_OK,           // Linked list operation performed successfully
  LINKED_LIST_NOK,          // Linked list operation not performed successfully
  INVALID_POSITION,         // Invalid position provided for the linked list operation
  LINKED_LIST_EMPTY,        // Linked list is empty
  LINKED_LIST_NULL_POINTER, // NULL pointer passed to the linked list operations
  LINKED_LIST_ALLOC_FAIL,   // Memory allocation for linked list failed
  NULL_POINTER              // Additional NULL pointer status

} linkedList_status_t; // Define return status enumeration for linked list operations

/**
 * @brief  Creates an empty linked list.
 *
 * This function creates an empty linked list by initializing the head pointer to NULL.
 *
 * @param  List : Pointer to the structure representing the linked list.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t createList(node_ds_t *List);

/**
 * @brief  Inserts a node after a specified node in the linked list.
 *
 * This function inserts a new node in a specified node in the linked list.
 * It searches for the specified node and inserts the new node in it.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  itemPtr : data to be stored in the new node.
 * @param  Position : position after which the new node will be inserted.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Insert_Node_At_Position(node_ds_t *List, uint32_t itemPtr, uint32_t Postion);

/**
 * @brief  Deletes the node at the specified position in the linked list.
 *
 * This function deletes the node at the specified position in the linked list.
 * It searches for the specified position and removes the corresponding node.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  Position : Position of the node to be deleted.
 * @param  itemPtr : Pointer to store the data of the deleted node.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Delete_Node_At_Position(node_ds_t *List, uint32_t Position, uint32_t *itemPtr);

/**
 * @brief  Displays the data of all nodes in the linked list in ascending order.
 *
 * This function traverses the linked list and prints the data of each node in ascending order.
 *
 * @param  List : Pointer to the structure representing the linked list.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Display_List(node_ds_t *List);

/**
 * @brief  Calculates the length (number of nodes) of the linked list.
 *
 * This function traverses the linked list and counts the number of nodes.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  size : Pointer to a variable where the length of the linked list will be stored.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Get_Length(node_ds_t *List, uint32_t *size);

/**
 * @brief  Destroys the linked list and frees the allocated memory.
 *
 * This function destroys the linked list by freeing the memory allocated for each node.
 *
 * @param  List : Pointer to the structure representing the linked list.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t destroyList(node_ds_t *List);

/**
 * @brief  Retrieves the data at a specified position in the linked list.
 *
 * This function retrieves the data stored at the specified position in the linked list.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  Position : Position of the node whose data is to be retrieved.
 * @param  itemPtr : Pointer to store the retrieved data.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t retrieveList(node_ds_t *List, uint32_t Position, uint32_t *itemPtr);

/**
 * @brief  Replaces the data at a specified position in the linked list.
 *
 * This function replaces the data stored at the specified position in the linked list with a new value.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  Position : Position of the node whose data is to be replaced.
 * @param  itemPtr : New data value to be stored at the specified position.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t replaceList(node_ds_t *List, uint32_t Position, uint32_t itemPtr);

#endif // ! _LINKEDLIST_DS_H_