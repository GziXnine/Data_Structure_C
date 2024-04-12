#ifndef _LINKEDLIST_DS_H_
#define _LINKEDLIST_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

typedef struct Node
{
  uint32_t NodeData;     // Data stored in the node
  struct Node *NodeLink; // Pointer to the next node in the linked list

} node_ds_t; // Define node data structure for linked list

typedef enum
{
  LINKED_LIST_OK,           // Linked list operation performed successfully
  LINKED_LIST_NOK,          // Linked list operation not performed successfully
  INVALID_POSOTION,         // Linked list not full
  LINKED_LIST_EMPTY,        // Linked list is empty
  LINKED_LIST_NULL_POINTER, // NULL pointer passed to the linked list operations
  LINKED_LIST_ALLOC_FAIL,   // Memory allocation for linked list failed
  NULL_POINTER              // Additional NULL pointer status

} linkedList_status_t; // Define return status enumeration for linked list operations

/**
 * @brief  Insert a node at the beginning of the linked list
 *
 * This function inserts a new node at the beginning of the linked list.
 * It updates the head pointer to point to the newly inserted node.
 *
 * @param  List : Pointer to the pointer of the head of the linked list
 * @param  itemPtr : Pointer to the data to be stored in the new node
 * @param  retVal : Pointer to a variable where the status of the operation will be stored
 *
 * @retval Pointer to the newly inserted node
 */
node_ds_t *Insert_Node_At_Beginning(node_ds_t **List, uint32_t *itemPtr, linkedList_status_t *retVal);

/**
 * @brief  Insert a node at the end of the linked list
 *
 * This function inserts a new node at the end of the linked list.
 * It traverses the list to find the last node and appends the new node to it.
 *
 * @param  List : Pointer to the pointer of the head of the linked list
 * @param  itemPtr : Pointer to the data to be stored in the new node
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Insert_Node_At_End(node_ds_t **List, uint32_t *itemPtr);

/**
 * @brief  Insert a node after a specified node in the linked list
 *
 * This function inserts a new node after a specified node in the linked list.
 * It searches for the specified node and inserts the new node after it.
 *
 * @param  List : Pointer to the head of the linked list
 * @param  itemPtr : Pointer to the data to be stored in the new node
 * @param  Position : Pointer to the position after which the new node will be inserted
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Insert_Node_At_Position(node_ds_t *List, uint32_t *itemPtr, uint32_t *Position);

/**
 * @brief  Delete a node from the beginning of the linked list
 *
 * This function deletes the first node from the linked list.
 * It updates the head pointer to point to the next node.
 *
 * @param  List : Pointer to the pointer of the head of the linked list
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Delete_Node_At_Beginning(node_ds_t **List);

/**
 * @brief  Delete a specified node from the linked list
 *
 * This function deletes a specified node from the linked list.
 * It searches for the specified node and removes it from the list.
 *
 * @param  List : Pointer to the head of the linked list
 * @param  itemPtr : Pointer to the data to be deleted
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Delete_Node_At_Position(node_ds_t *List, uint32_t *itemPtr);

/**
 * @brief  Delete a node from the end of the linked list
 *
 * This function deletes the last node from the linked list.
 * It updates the link of the second-to-last node to NULL.
 *
 * @param  List : Pointer to the head of the linked list
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Delete_Node_At_End(node_ds_t *List);

/**
 * @brief  Display all nodes in the linked list
 *
 * This function displays the data of all nodes in the linked list.
 * It traverses the list and prints the data of each node.
 *
 * @param  List : Pointer to the head of the linked list
 *
 * @retval Status indicating success or failure
 */
linkedList_status_t Display_All_Nodes(node_ds_t *List);

/**
 * @brief  Get the length (number of nodes) of the linked list
 *
 * This function calculates the length of the linked list.
 * It traverses the list and counts the number of nodes.
 *
 * @param  List : Pointer to the head of the linked list
 * @param  retVal : Pointer to a variable where the status of the operation will be stored
 *
 * @retval Number of nodes in the linked list
 */
uint32_t Get_Length(node_ds_t *List, linkedList_status_t *retVal);

#endif // ! _LINKEDLIST_DS_H_