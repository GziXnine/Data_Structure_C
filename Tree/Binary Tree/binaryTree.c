#include "binaryTree.h"

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
 * @brief Deletes a node from the binary tree.
 *
 * This function deletes a specified node from the binary tree and adjusts the tree structure accordingly.
 *
 * @param myTree Pointer to the binary tree.
 */
static void DeleteNodeTree(Trees *myTree)
{
  treeNode *temp = *myTree;
  Trees *minNode = &((*myTree)->right);

  if (!(*myTree)->left)
  {
    *myTree = (*myTree)->right;
    free(temp);
  }
  else if (!(*myTree)->right)
  {
    *myTree = (*myTree)->left;
    free(temp);
  }
  else
  {
    while ((*minNode)->left)
    {
      minNode = &((*minNode)->left);
    }
    (*myTree)->data = (*minNode)->data;
    
    DeleteNodeTree(minNode);
  }
}

return_status_t createTree(tree *myTree)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    retVal = BINARY_TREE_OK;

    myTree->root = NULL;
    myTree->size = ZERO;
    myTree->depth = ZERO;
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t destroyTree(tree *myTree)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (NULL != myTree)
  {
    destroyTreeRecAux(&myTree->root);
    myTree->depth = ZERO;
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

      *Depth = myTree->depth;
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

return_status_t insertNode(tree *myTree, uint32_t newNode)
{
  return_status_t retVal = BINARY_TREE_NOK;
  uint32_t Pdepth = ZERO_INIT;

  if (myTree != NULL)
  {
    retVal = BINARY_TREE_OK;
    Trees *currNode = &myTree->root;

    while (*currNode)
    {
      if (newNode < (*currNode)->data)
      {
        currNode = &((*currNode)->left);
      }
      else
      {
        currNode = &((*currNode)->right);
      }
      Pdepth++;
    }

    *currNode = (treeNode *)malloc(sizeof(treeNode));
    if (*currNode)
    {
      (*currNode)->left = NULL;
      (*currNode)->right = NULL;
      (*currNode)->data = newNode;

      if (myTree->depth < Pdepth)
      {
        myTree->depth = Pdepth;
      }
      (myTree->size)++;
    }
    else
    {
      retVal = BINARY_TREE_ALLOC_FAIL;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t findItemTree(tree *myTree, uint32_t Element, uint32_t *checkElement)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (myTree != NULL)
  {
    if (checkElement != NULL)
    {
      treeNode *tempNode = myTree->root;

      while (tempNode)
      {
        if (Element == tempNode->data)
        {
          *checkElement = tempNode->data;

          retVal = FOUNDED_ELEMENT;
          break;
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
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = BINARY_TREE_NULL_POINTER;
  }

  return retVal;
}

return_status_t deleteNode(tree *myTree, uint32_t deletedValue, uint32_t *ptrOut)
{
  return_status_t retVal = BINARY_TREE_NOK;

  if (myTree != NULL)
  {
    if (ptrOut)
    {
      treeNode **currNode = &myTree->root;

      while (*currNode && deletedValue != (*currNode)->data)
      {
        if (deletedValue < (*currNode)->data)
        {
          currNode = &((*currNode)->left);
        }
        else
        {
          currNode = &((*currNode)->right);
        }
      }

      if (*currNode)
      {
        *ptrOut = (*currNode)->data;
        DeleteNodeTree(currNode);
        (myTree->size)--;

        retVal = FOUNDED_ELEMENT;
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