// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char *word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind++)
  {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
    {
      return ind;
    }
  }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE

// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List *arithlist)
{
  if (arithlist == NULL)
  {
    return true;
  }
  if ((arithlist->head) == NULL)
  {
    return true;
  }

  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true

  // if more than one node left, return false

  // if the remaining node is an operator, return false

  // if everything is OK, return true

  ListNode *node = arithlist->head;
  
  while (node != NULL)
  {

    if (isOperator(node->word) != -1)
    {
      int opr1;
      int opr2;
      
      ListNode *node1 = NULL;
      ListNode *node2 = node->prev;
      if (node2 != NULL)
      {
        node1 = node2->prev;
      }
      if (node1 != NULL && node2 != NULL)
      {

        sscanf(node1->word, "%d", &opr1);
        sscanf(node2->word, "%d", &opr2);
        char buff[WORDLENGTH];
        int value;
        ListNode *tmpNode;

        switch (node->word[0])
        {
        case '+':
          value = opr1 + opr2;
          tmpNode = node->next;
          deleteNode(arithlist, node);
          deleteNode(arithlist, node2);
          node = tmpNode;
          sprintf(buff, "%d", value);
          strcpy(node1->word, buff);
          strcat(node1->word, "\n");
          break;

        case '-':
          value = opr1 - opr2;
          tmpNode = node->next;
          deleteNode(arithlist, node);
          deleteNode(arithlist, node2);
          node = tmpNode;
          sprintf(buff, "%d", value);
          strcpy(node1->word, buff);
          strcat(node1->word, "\n");
          break;
        case '*':
          value = opr1 * opr2;
          tmpNode = node->next;
          deleteNode(arithlist, node);
          deleteNode(arithlist, node2);
          sprintf(buff, "%d", value);
          strcpy(node1->word, buff);
          strcat(node1->word, "\n");
          break;

        default:
          break;
        }
      }
      else
      {
        return false;
      }
    }
    else
    {
      node = node->next;
    }
  }
  if (arithlist->head != arithlist->tail)
  {
    return false;
  }

  return true;
}
#endif
