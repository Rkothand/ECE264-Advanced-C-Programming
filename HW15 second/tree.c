// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

Tree * buildTree(int * inArray, int * postArray, int size)
{
    
  tnode* st;
 
  // Create Set of type Node*
  tnode* s;
 
  // Initialise postIndex with n - 1
  int postIndex =  - 1;
 
  // Initialise root with NULL
  Node* root = NULL;
 
  for (int p = size - 1, i = size - 1; p>=0; )  
  { 
 
    // Initialise node with NULL
    tnode* node = NULL; 
     
    // Run do-while loop
    do
    { 
 
      // Initialise node with
      // new Node(post[p]); 
      node = new Node(postArray[p]); 
 
      // Check is root is 
      // equal to NULL
      if (root == NULL) 
      { 
        root = node; 
      } 
       
      // If size of set 
      // is greater than 0
      if (st.size() > 0)  
      { 
         
        // If st.top() is present in the
        // set s
        if (s.find(st.top()) != s.end()) 
        { 
          s.erase(st.top()); 
          st.top()->left = node; 
          st.pop(); 
        } 
        else
        { 
          st.top()->right = node; 
        } 
      }
       
      st.push(node); 
       
    } while (postArray[p--] != inArray[i] && p >=0); 
 
    node = NULL; 
     
    // If the stack is not empty and
    // st.top()->data is equal to in[i]
    while (st.size() > 0 && i>=0 &&  
           st.top()->data == inArray[i])  
    { 
      node = st.top(); 
       
      // Pop elements from stack
      st.pop(); 
      i--; 
    } 
     
    // if node not equal to NULL
    if (node != NULL)  
    { 
      s.insert(node); 
      st.push(node); 
    } 
  } 
   
  // Return root
  return root;
}
#endif
