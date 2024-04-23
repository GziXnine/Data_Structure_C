#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "std_types.h" // Include necessary header file for standard data types

#define MAX_SIZE 100 // Define maximum size for the stack

typedef struct listNode
{
  uint32_t data[MAX_SIZE];
  uint32_t size; // Number of elements in the linked list

} listNode_t; // Define node data structure for linked list

typedef enum
{
  LINKED_LIST_OK,           // Linked list operation performed successfully
  LINKED_LIST_NOK,          // Linked list operation not performed successfully
  INVALID_POSITION,         // Invalid position provided for the linked list operation
  LINKED_LIST_FULL,         // Linked list is already at its maximum capacity
  LINKED_LIST_EMPTY,        // Linked list is empty
  LINKED_LIST_HAS_SPACE,    // Linked list has space available
  LINKED_LIST_NULL_POINTER, // NULL pointer passed to the linked list operations
  NULL_POINTER              // Additional NULL pointer status

} linkedList_status_t; // Define return status enumeration for linked list operations

/**
 * @brief Creates a new linked list.
 *
 * This function creates a new linked list and initializes it with empty data.
 *
 * @param List Pointer to the linked list to be created.
 *
 * @retval LINKED_LIST_OK if the list is successfully created.
 * @retval LINKED_LIST_NULL_POINTER if the List pointer is NULL.
 */
linkedList_status_t createList(listNode_t *List);

/**
 * @brief Destroys an existing linked list.
 *
 * This function destroys an existing linked list and deallocates its memory.
 *
 * @param List Pointer to the linked list to be destroyed.
 *
 * @retval LINKED_LIST_OK if the list is successfully destroyed.
 * @retval LINKED_LIST_NULL_POINTER if the List pointer is NULL.
 */
linkedList_status_t destroyList(listNode_t *List);

/**
 * @brief Inserts a node after a specified position in the linked list.
 *
 * This function inserts a new node with the given data after the specified position in the linked list.
 *
 * @param List Pointer to the head of the linked list.
 * @param itemPtr Data to be stored in the new node.
 * @param Position Position after which the new node will be inserted.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Insert_Node_At_Position(listNode_t *List, uint32_t itemPtr, uint32_t Position);

/**
 * @brief Deletes a node at a specified position from the linked list.
 *
 * This function deletes the node at the specified position from the linked list.
 *
 * @param List Pointer to the head of the linked list.
 * @param PtrOut Pointer to store the data of the deleted node.
 * @param Position Position of the node to be deleted.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Delete_Node_At_Position(listNode_t *List, uint32_t *PtrOut, uint32_t Position);

/**
 * @brief Displays all nodes in the linked list.
 *
 * This function displays the data of all nodes in the linked list.
 *
 * @param List Pointer to the head of the linked list.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Display_All_Nodes(listNode_t *List);

/**
 * @brief Gets the length (number of nodes) of the linked list.
 *
 * This function calculates the length of the linked list.
 *
 * @param List Pointer to the head of the linked list.
 * @param lenght Pointer to a variable where the length of the list will be stored.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t Get_Length(listNode_t *List, uint32_t *lenght);

/**
 * @brief Retrieves the data at a specified position in the linked list.
 *
 * This function retrieves the data stored at the specified position in the linked list.
 *
 * @param List Pointer to the structure representing the linked list.
 * @param Position Position of the node whose data is to be retrieved.
 * @param PtrOut Pointer to store the retrieved data.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t retrieveList(listNode_t *List, uint32_t Position, uint32_t *PtrOut);

/**
 * @brief Replaces the data at a specified position in the linked list.
 *
 * This function replaces the data stored at the specified position in the linked list with a new value.
 *
 * @param List Pointer to the structure representing the linked list.
 * @param Position Position of the node whose data is to be replaced.
 * @param itemPtr New data value to be stored at the specified position.
 *
 * @retval Status indicating success or failure.
 */
linkedList_status_t replaceList(listNode_t *List, uint32_t Position, uint32_t itemPtr);

#endif // !_LINKEDLIST_H_