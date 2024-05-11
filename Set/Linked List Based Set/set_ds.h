#ifndef _SET_DS_H_
#define _SET_DS_H_

#include "std_types.h"

typedef struct Node
{
  uint32_t elements;
  struct Node *next;

} Node;

typedef enum
{
  SET_OK,           /**< Operation performed successfully */
  SET_NOK,          /**< Operation not performed successfully */
  SET_FULL,         /**< Set is full */
  SET_HAS_SPACE,    /**< Set has space for more elements */
  SET_EMPTY,        /**< Set is empty */
  SET_FOUND,        /**< Element found in the set */
  SET_NOT_FOUND,    /**< Element not found in the set */
  SET_NULL_POINTER, /**< NULL pointer passed to the operations */
  SET_ALLOC_FAIL,   /**< Memory allocation for set failed */
  NULL_POINTER      /**< Additional status for a NULL pointer */

} return_status_t; /**< Return status enumeration for set operations */

/**
 * @brief  Initialize an empty set.
 *
 * Allocates memory for the set and initializes it to empty.
 *
 * @return Pointer to the initialized set.
 */
Node *initialize();

/**
 * @brief  Check if the set contains a specific element.
 *
 * @param  set : Pointer to the set structure.
 * @param  element : The element to search for in the set.
 *
 * @return Status indicating whether the element is found or not.
 */
return_status_t contains(Node *set, uint32_t element);

/**
 * @brief  Add an element to the set.
 *
 * @param  set : Pointer to the set structure.
 * @param  element : The element to add to the set.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t add(Node **set, uint32_t element);

/**
 * @brief  Remove an element from the set.
 *
 * @param  set : Pointer to the set structure.
 * @param  element : The element to remove from the set.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t removeElement(Node **set, uint32_t element);

/**
 * @brief  Get the size of the set.
 *
 * @param  set : Pointer to the set structure.
 *
 * @return The size of the set.
 */
uint32_t getSize(Node *set);

/**
 * @brief  Print the elements of the set.
 *
 * @param  set : Pointer to the set structure.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t printSet(Node *set);

/**
 * @brief  Destroy the set and free allocated memory.
 *
 * @param  set : Pointer to the set structure.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t destroySet(Node **set);

/**
 * @brief  Check if two sets are equal.
 *
 * @param  set1 : Pointer to the first set.
 * @param  set2 : Pointer to the second set.
 *
 * @return true if the sets are equal, false otherwise.
 */
bool_t isEqual(Node *set1, Node *set2);

/**
 * @brief  Get the union of two sets.
 *
 * @param  set1 : Pointer to the first set.
 * @param  set2 : Pointer to the second set.
 *
 * @return Pointer to the union set.
 */
Node *unionSet(Node *set1, Node *set2);

/**
 * @brief  Get the intersection of two sets.
 *
 * @param  set1 : Pointer to the first set.
 * @param  set2 : Pointer to the second set.
 *
 * @return Pointer to the intersection set.
 */
Node *intersectSet(Node *set1, Node *set2);

/**
 * @brief  Get the set difference between two sets.
 *
 * @param  set1 : Pointer to the first set.
 * @param  set2 : Pointer to the second set.
 *
 * @return Pointer to the set difference.
 */
Node *differenceSet(Node *set1, Node *set2);

/**
 * @brief  Clear all elements from the set.
 *
 * @param  set : Pointer to the set structure.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t clear(Node *set);

/**
 * @brief  Create a copy of the set.
 *
 * @param  set : Pointer to the set structure.
 *
 * @return Pointer to the copied set.
 */
Node *copySet(Node *set);

/**
 * @brief  Check if a set is a subset of another set.
 *
 * @param  set1 : Pointer to the first set.
 * @param  set2 : Pointer to the second set.
 *
 * @return true if set1 is a subset of set2, false otherwise.
 */
bool_t isSubset(Node *set1, Node *set2);

/**
 * @brief  Get the complement of a set with respect to a universe set.
 *
 * @param  set : Pointer to the set structure.
 * @param  universeSet : Pointer to the universe set.
 *
 * @return Pointer to the complement set.
 */
Node *complementSet(Node *set, Node *universeSet);

/**
 * @brief  Add multiple elements to the set.
 *
 * @param  set : Pointer to the set structure.
 * @param  elements : Array of elements to add.
 * @param  numElements : Number of elements to add.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t addMultiple(Node *set, uint32_t elements[], uint8_t numElements);

/**
 * @brief  Remove multiple elements from the set.
 *
 * @param  set : Pointer to the set structure.
 * @param  elements : Array of elements to remove.
 * @param  numElements : Number of elements to remove.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t removeMultiple(Node *set, uint32_t elements[], uint8_t numElements);

#endif // _SET_DS_H_