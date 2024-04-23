#include "binarySearchTree.h"

/**
 * @brief Performs an inorder traversal recursively on a binary tree.
 *
 * This function performs an inorder traversal recursively on a binary tree, visiting the left subtree,
 * then the current node, and finally the right subtree.
 *
 * @param current Pointer to the current node in the binary tree.
 * @param Pvisit Pointer to the function that processes or visits each node during traversal.
 */
static void InorderRec(treeNode *current, void (*Pvisit)(uint32_t))
{
  if (current != NULL && Pvisit != NULL)
  {
    InorderRec(current->left, Pvisit);
    (*Pvisit)(current->data);
    InorderRec(current->right, Pvisit);
  }
}

/**
 * @brief Performs a preorder traversal recursively on a binary tree.
 *
 * This function performs a preorder traversal recursively on a binary tree, visiting the current node,
 * then the left subtree, and finally the right subtree.
 *
 * @param current Pointer to the current node in the binary tree.
 * @param Pvisit Pointer to the function that processes or visits each node during traversal.
 */
static void PreorderRec(treeNode *current, void (*Pvisit)(uint32_t))
{
  if (current != NULL && Pvisit != NULL)
  {
    (*Pvisit)(current->data);
    PreorderRec(current->left, Pvisit);
    PreorderRec(current->right, Pvisit);
  }
}

/**
 * @brief Performs a postorder traversal recursively on a binary tree.
 *
 * This function performs a postorder traversal recursively on a binary tree, visiting the left subtree,
 * then the right subtree, and finally the current node.
 *
 * @param current Pointer to the current node in the binary tree.
 * @param Pvisit Pointer to the function that processes or visits each node during traversal.
 */
static void PostorderRec(treeNode *current, void (*Pvisit)(uint32_t))
{
  if (current != NULL && Pvisit != NULL)
  {
    PostorderRec(current->left, Pvisit);
    PostorderRec(current->right, Pvisit);
    (*Pvisit)(current->data);
  }
}

/**
 * @brief Recursively destroys a binary tree.
 *
 * This function recursively destroys a binary tree by freeing memory allocated for each node.
 *
 * @param myTree Pointer to the current node in the binary tree.
 */
static void destroyTreeRecAux(Trees *myTree)
{
  if (*myTree != NULL)
  {
    destroyTreeRecAux(&(*myTree)->left);
    destroyTreeRecAux(&(*myTree)->right);
    free(*myTree);
  }
}

/**
 * @brief Calculates the depth of a binary tree starting from the given node.
 *
 * This function calculates the depth of the binary tree rooted at the given node.
 *
 * @param node Pointer to the root node of the binary tree.
 *
 * @return The depth of the binary tree.
 */
static uint32_t calculateDepth(treeNode *node) 
{
  uint32_t leftDepth = ZERO_INIT, rightDepth = ZERO_INIT;
  if (node != NULL) 
  {
    leftDepth = calculateDepth(node->left);
    rightDepth = calculateDepth(node->right);

    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
  } 
  else 
  {
    return ZERO;
  }
}

return_status_t createBST(tree *myTree)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    retVal = BINARY_TREE_OK;

    myTree->root = NULL;
    myTree->size = ZERO;
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t destroyBST(tree *myTree)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    destroyTreeRecAux(&myTree->root);
    myTree->size = ZERO;
    myTree->root = NULL;

    retVal = BINARY_TREE_OK;
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t treeSize(tree *myTree, uint32_t *Size)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    if (NULL != Size)
    {
      retVal = BINARY_TREE_OK;

      *Size = myTree->size;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t treeDepth(tree *myTree, uint32_t *Depth)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    if (NULL != Depth)
    {
      retVal = BINARY_TREE_OK;

      *Depth = calculateDepth(myTree->root);
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t Preorder(tree *current, void (*Pvisit)(uint32_t))
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != current)
  {
    if (NULL != Pvisit)
    {
      PreorderRec(current->root, Pvisit);

      retVal = BINARY_TREE_OK;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t Postorder(tree *current, void (*Pvisit)(uint32_t))
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != current)
  {
    if (NULL != Pvisit)
    {
      PostorderRec(current->root, Pvisit);

      retVal = BINARY_TREE_OK;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t Inorder(tree *current, void (*Pvisit)(uint32_t))
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != current)
  {
    if (NULL != Pvisit)
    {
      InorderRec(current->root, Pvisit);

      retVal = BINARY_TREE_OK;
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t findBSTItem(tree *myTree, uint32_t Element, uint32_t *checkElement)
{
  return_status_t retVal = BINARY_TREE_NOK;
  treeNode *tempNode = myTree->root;

  if (NULL != myTree)
  {
    if (NULL != checkElement)
    {
      if (myTree->root != NULL)
      {
        while (tempNode)
        {
          if (Element == tempNode->data)
          {
            retVal = FOUNDED_ELEMENT;
            *checkElement = tempNode->data;
            break; // Break the loop once the element is found
          }
          else if (Element < tempNode->data)
          {
            tempNode = tempNode->left;
          }
          else
          {
            tempNode = tempNode->right;
          }
        }

        if (!tempNode)
        {
          retVal = NOT_FOUND_ELEMENT;
        }
      }
      else
      {
        retVal = BINARY_TREE_EMPTY;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t insertBSTNode(tree *myTree, uint32_t newNode)
{
  return_status_t retVal = BINARY_TREE_NOK;
  treeNode *tempNode = NULL, *currNode = myTree->root, *prevNode = NULL;

  if (myTree != NULL)
  {
    tempNode = (treeNode *)malloc(sizeof(treeNode));
    if (!tempNode)
    {
      retVal = BINARY_TREE_ALLOC_FAIL;
    }
    else
    {
      tempNode->left = NULL;
      tempNode->right = NULL;
      tempNode->data = newNode;

      if (myTree->root == NULL)
      {
        retVal = BINARY_TREE_OK;

        myTree->root = tempNode;
        (myTree->size)++;

        return retVal; // Exit early after inserting the first node
      }

      while (currNode != NULL)
      {
        prevNode = currNode;

        if (newNode < currNode->data)
        {
          currNode = currNode->left;
        }
        else
        {
          currNode = currNode->right;
        }
      }

      if (newNode < prevNode->data)
      {
        prevNode->left = tempNode;
      }
      else
      {
        prevNode->right = tempNode;
      }

      (myTree->size)++;
      retVal = BINARY_TREE_OK;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t deleteBSTNode(tree *myTree, uint32_t deletedValue, uint32_t *ptrOut)
{
  return_status_t retVal = BINARY_TREE_NOK;
  treeNode *tempNode = myTree->root, *prevNode = NULL, *successor = NULL;

  if (myTree != NULL)
  {
    if (NULL != ptrOut)
    {
      while (tempNode != NULL && (deletedValue != tempNode->data))
      {
        prevNode = tempNode;
        if (deletedValue < tempNode->data)
        {
          tempNode = tempNode->left;
        }
        else
        {
          tempNode = tempNode->right;
        }
      }

      if (tempNode != NULL)
      {
        retVal = FOUNDED_ELEMENT;
        *ptrOut = tempNode->data;

        if (tempNode->left == NULL)
        {
          if (prevNode == NULL)
          {
            myTree->root = tempNode->right;
          }
          else if (tempNode == prevNode->left)
          {
            prevNode->left = tempNode->right;
          }
          else
          {
            prevNode->right = tempNode->right;
          }
          free(tempNode);
        }
        else if (tempNode->right == NULL)
        {
          if (prevNode == NULL)
          {
            myTree->root = tempNode->left;
          }
          else if (tempNode == prevNode->left)
          {
            prevNode->left = tempNode->left;
          }
          else
          {
            prevNode->right = tempNode->left;
          }
          free(tempNode);
        }
        else
        {
          successor = tempNode->right;
          prevNode = tempNode;

          while (successor->left != NULL)
          {
            prevNode = successor;
            successor = successor->left;
          }
          tempNode->data = successor->data;

          if (tempNode == prevNode->left)
          {
            prevNode->left = successor->right;
          }
          else
          {
            prevNode->right = successor->right;
          }
          free(successor);
        }
        (myTree->size)--;
      }
      else
      {
        retVal = NOT_FOUND_ELEMENT;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}