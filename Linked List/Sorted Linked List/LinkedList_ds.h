#ifndef _LINKEDLIST_DS_H_
#define _LINKEDLIST_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

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
  LINKED_LIST_OK,           // Operation performed successfully
  LINKED_LIST_NOK,          // Operation not performed successfully
  INVALID_POSITION,         // Invalid position provided for the operation
  LINKED_LIST_EMPTY,        // Linked list is empty
  LINKED_LIST_NULL_POINTER, // NULL pointer passed to the operations
  LINKED_LIST_ALLOC_FAIL,   // Memory allocation for the linked list failed
  ITEM_NOT_FOUND,           // Item not found in the linked list
  NULL_POINTER              // Additional status for a NULL pointer

} linkedList_status_t; // Return status enumeration for linked list operations

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
 * @brief  Inserts a node with sorted data in the linked list.
 *
 * This function inserts a new node with sorted data into the linked list.
 * It maintains the sorted order of the list by finding the appropriate position for insertion.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  itemPtr : Data to be stored in the new node.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Insert_Sorted(node_ds_t *List, uint32_t itemPtr);

/**
 * @brief  Deletes the node with specified data from the linked list.
 *
 * This function deletes the node containing the specified data from the linked list.
 * It searches for the node with the specified data and removes it from the list.
 *
 * @param  List : Pointer to the structure representing the linked list.
 * @param  itemPtr : Data of the node to be deleted.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Delete_Node_By_Value(node_ds_t *List, uint32_t itemPtr);

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

#endif // ! _LINKEDLIST_DS_H_