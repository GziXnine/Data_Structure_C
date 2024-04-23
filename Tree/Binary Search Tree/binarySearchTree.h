#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "std_types.h" // Include necessary header file for standard data types

typedef struct treeNode
{
  struct treeNode *left;  /**< Pointer to the left child node */
  struct treeNode *right; /**< Pointer to the right child node */
  uint32_t data;          /**< Data stored in the node */

} treeNode;

typedef treeNode *Trees; /**< Array of pointers to nodes, used as a pool for creating new nodes */

typedef struct tree
{
  treeNode *root; /**< Pointer to the root node of the tree */
  uint32_t size;  /**< Number of nodes in the tree */

} tree;

typedef enum
{
  BINARY_TREE_OK,           /* Binary Tree operation performed successfully */
  BINARY_TREE_NOK,          /* Binary Tree operation not performed successfully */
  BINARY_TREE_EMPTY,        /* Binary Tree is empty */
  BINARY_TREE_NULL_POINTER, /* NULL pointer passed to the Binary Tree operations */
  BINARY_TREE_ALLOC_FAIL,   /* Memory allocation for binary tree failed */
  NULL_POINTER,             /* Additional NULL pointer status */
  FOUNDED_ELEMENT,          /* Element found in the binary tree */
  NOT_FOUND_ELEMENT         /* Element not found in the binary tree */

} return_status_t; // Define return status enumeration

/**
 * @brief Creates a new binary tree.
 *
 * This function creates a new binary tree and initializes it with an empty root node.
 *
 * @param myTree The binary tree to be created.
 *
 * @retval BINARY_TREE_OK if the tree is successfully created.
 * @retval BINARY_TREE_NOK if the tree creation fails.
 */
return_status_t createBST(tree *myTree);

/**
 * @brief Destroys an existing binary tree.
 *
 * This function destroys an existing binary tree and deallocates all its nodes and memory.
 *
 * @param myTree The binary tree to be destroyed.
 *
 * @retval BINARY_TREE_OK if the tree is successfully destroyed.
 * @retval BINARY_TREE_NOK if the tree destruction fails.
 */
return_status_t destroyBST(tree *myTree);

/**
 * @brief Gets the size of the binary tree.
 *
 * This function calculates the number of nodes in the binary tree.
 *
 * @param myTree The binary tree for which to calculate the size.
 * @param Size Pointer to store the size of the tree.
 *
 * @retval BINARY_TREE_OK if the size is successfully calculated.
 * @retval BINARY_TREE_NULL_POINTER if the size pointer is NULL.
 */
return_status_t treeSize(tree *myTree, uint32_t *Size);

/**
 * @brief Gets the depth of the binary tree.
 *
 * This function calculates the maximum depth of the binary tree.
 *
 * @param myTree The binary tree for which to calculate the depth.
 * @param Depth Pointer to store the depth of the tree.
 *
 * @retval BINARY_TREE_OK if the depth is successfully calculated.
 * @retval BINARY_TREE_NULL_POINTER if the depth pointer is NULL.
 */
return_status_t treeDepth(tree *myTree, uint32_t *Depth);

/**
 * @brief Performs a preorder traversal of the binary tree.
 *
 * This function traverses the binary tree in preorder (root, left, right) manner
 * and applies the visit function to each node's data.
 *
 * @param current The current node in the traversal (initially the root).
 * @param visit Pointer to the function to be applied to each node's data.
 *
 * @retval BINARY_TREE_OK if the traversal is successful.
 * @retval BINARY_TREE_NULL_POINTER if the visit pointer is NULL.
 */
return_status_t Preorder(tree *current, void (*visit)(uint32_t));

/**
 * @brief Performs a postorder traversal of the binary tree.
 *
 * This function traverses the binary tree in postorder (left, right, root) manner
 * and applies the visit function to each node's data.
 *
 * @param current The current node in the traversal (initially the root).
 * @param visit Pointer to the function to be applied to each node's data.
 *
 * @retval BINARY_TREE_OK if the traversal is successful.
 * @retval BINARY_TREE_NULL_POINTER if the visit pointer is NULL.
 */
return_status_t Postorder(tree *current, void (*visit)(uint32_t));

/**
 * @brief Performs an inorder traversal of the binary tree.
 *
 * This function traverses the binary tree in inorder (left, root, right) manner
 * and applies the visit function to each node's data.
 *
 * @param current The current node in the traversal (initially the root).
 * @param visit Pointer to the function to be applied to each node's data.
 *
 * @retval BINARY_TREE_OK if the traversal is successful.
 * @retval BINARY_TREE_NULL_POINTER if the visit pointer is NULL.
 */
return_status_t Inorder(tree *current, void (*visit)(uint32_t));

/**
 * @brief Inserts a new node into the binary tree.
 *
 * This function inserts a new node with the given data into the binary tree
 * at the appropriate position based on the binary search tree property.
 *
 * @param myTree The binary tree in which to insert the node.
 * @param newNode Pointer to the new node to be inserted.
 * @param insertedNode Pointer to store the inserted node.
 *
 * @retval BINARY_TREE_OK if the node is successfully inserted.
 * @retval BINARY_TREE_NULL_POINTER if the newNode or insertedNode pointers are NULL.
 */
return_status_t insertBSTNode(tree *myTree, uint32_t newNode);

/**
 * @brief Deletes a node from the binary tree.
 *
 * This function deletes the given node from the binary tree
 * while maintaining the binary search tree property.
 *
 * @param myTree The binary tree from which to delete the node.
 * @param z Pointer to the node to be deleted.
 * @param deletedNode Pointer to store the deleted node.
 *
 * @retval BINARY_TREE_OK if the node is successfully deleted.
 * @retval BINARY_TREE_NULL_POINTER if the z or deletedNode pointers are NULL.
 */
return_status_t deleteBSTNode(tree *myTree, uint32_t deletedValue, uint32_t *ptrOut);

/**
 * @brief Finds an element in the binary tree.
 * 
 * This function searches for a specified element in the binary tree and returns the result
 * indicating whether the element is found or not.
 * 
 * @param myTree Pointer to the binary tree.
 * @param Element The element to search for in the binary tree.
 * @param checkElement Pointer to store the found element if it exists.
 * 
 * @retval BINARY_TREE_OK if the operation is successful.
 * @retval BINARY_TREE_NOK if the operation is unsuccessful.
 */
return_status_t findBSTItem(tree *myTree, uint32_t Element, uint32_t *checkElement);

#endif // !_BINARY_SEARCH_TREE_H_