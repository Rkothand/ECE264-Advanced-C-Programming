// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree *newTree(void)
{
  Tree *t = malloc(sizeof(Tree));
  t->root = NULL;
  return t;
}

void deleteTreeNode(TreeNode *tr)
{
  if (tr == NULL)
  {
    return;
  }
  deleteTreeNode(tr->left);
  deleteTreeNode(tr->right);
  free(tr);
}

void freeTree(Tree *tr)
{
  if (tr == NULL)
  {
    // nothing to delete
    return;
  }
  deleteTreeNode(tr->root);
  free(tr);
}

// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE

int search(int arr[], int strt, int end, int value)
{
  int i;
  for (i = strt; i <= end; i++)
  {
    if (arr[i] == value)
      break;
  }
  return i;
}

/* Helper function that allocates a new node */
TreeNode *newNode(int data)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->value = data;
  node->left = node->right = NULL;
  return (node);
}
TreeNode *buildUtil(int in[], int post[], int inStrt, int inEnd, int *pIndex)
{
  // Base case
  if (inStrt > inEnd)
    return NULL;

  /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
  TreeNode *node = newNode(post[*pIndex]);
  (*pIndex)--;

  /* If this node has no children then return */
  if (inStrt == inEnd)
    return node;

  /* Else find the index of this node in Inorder
       traversal */
  int iIndex = search(in, inStrt, inEnd, node->value);

  /* Using index in Inorder traversal, construct left and
       right subtress */
  node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
  node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

  return node;
}
Tree *buildTree(int *inArray, int *postArray, int size)
{
  int pIndex = size - 1;
  TreeNode *root = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
  Tree *treeRoot = malloc(sizeof(Tree));
  treeRoot->root = root;
  return treeRoot;
}
#endif

#ifdef TEST_PRINTPATH
void printPathUtil(TreeNode *node, int val)
{

  if (node->left != NULL)
  {

    printPathUtil(node->left, val);
  }
  else if (node->right != NULL && node->value < val)
  {

    printPathUtil(node->right, val);
  }
  if (node != NULL)
  {
    printf("%d\n", node->value);
  }
}

void printPath(Tree *tr, int val)
{
  if (tr == NULL)
  {
    printf("No path found");
    return;
  }
  printPathUtil(tr->root, val);
}

#endif
