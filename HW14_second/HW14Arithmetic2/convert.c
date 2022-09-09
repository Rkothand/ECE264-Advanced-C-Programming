// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"
void insertNode(List *arithlist, ListNode *current, char *word);
// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
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
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
bool convert(List *arithlist)
{
  List *operatorStack = malloc(sizeof(List));
  operatorStack->tail = NULL;
  operatorStack->head = NULL;

  ListNode *node = arithlist->head;

  while (node != NULL)
  {
    int optId = isOperator(node->word);
    if (optId != -1)
    {
      char operation[WORDLENGTH];
      sscanf(node->word, "%s", operation);
      if (operatorStack->tail != NULL)
      {

        if (optId == 4)
        {
          int inside = isOperator(operatorStack->tail->word);
          ListNode *current = node->prev;
          while (inside != 3)
          {
            insertNode(arithlist, current, operatorStack->tail->word);
            deleteNode(operatorStack, operatorStack->tail);
            inside = isOperator(operatorStack->tail->word);
            current = current->next;
          }
          //delete ( operator from stack
          deleteNode(operatorStack, operatorStack->tail);

          //delete ) operator from input
          ListNode *next = node->next;
          deleteNode(arithlist, node);
          node = next;
          continue;
        }
        int topOptId = isOperator(operatorStack->tail->word);
        if (topOptId > optId && topOptId != 3)
        {
          ListNode *tnode = node->prev;
          while (topOptId > optId && topOptId != 3 && operatorStack->tail != NULL)
          {
            topOptId = isOperator(operatorStack->tail->word);
            insertNode(arithlist, tnode, operatorStack->tail->word);
            deleteNode(operatorStack, operatorStack->tail);
            tnode = tnode->next;
          }
          addNode(operatorStack, operation);
        }
        else
        {
          addNode(operatorStack, operation);
        }
      }
      else
      {
        addNode(operatorStack, node->word);
      }
      ListNode *next = node->next;
      deleteNode(arithlist, node);
      node = next;
    }
    else
    {
      node = node->next;
    }
  }
  //process operator stack
  node = operatorStack->tail;
  while (node != NULL)
  {
    char word[WORDLENGTH];
    sscanf(node->word, "%s", word);
    addNode(arithlist, word);
    node = node->prev;
  }
  deleteList(operatorStack);
 

  return true;
}
#endif
