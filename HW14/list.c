// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char *filename, List *arithlist)
{

  // use fopen to open the file for read
  // return false if fopen fails
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL)
  {
    return false;
  }
  else
  {
    if (arithlist == NULL)
    {
      return false;
    }
    char buff[100];
    char record[WORDLENGTH + 4];

    while (fgets(buff, sizeof buff, fptr) != NULL)
    {
      // process line here
      char filter[] = "%11s";
      sscanf(buff, filter, &record);
      if (strlen(record) > WORDLENGTH - 2)
      {
        deleteList(arithlist);
        return false;
      }

      addNode(arithlist, record);
    }
  }

  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list
void deleteList(List *arithlist)
{
  if (arithlist == NULL)
    return;
  ListNode *node = arithlist->head;
  while (node != NULL)
  {
    ListNode *temp = node;
    node = node->next;
    free(temp);
  }
}
#endif

#ifdef TEST_ADDNODE

void insertNode(List *arithlist, ListNode *current, char *gword)
{
  char word[WORDLENGTH];
  sscanf(gword, "%s", word);
  if (current == NULL)
    return;
  if (current->next == NULL)
  {
    ListNode *node = malloc(sizeof(ListNode));
    strcpy(node->word, word);
    strcat(node->word, "\n");
    current->next = node;
    node->prev = current;
    node->next = NULL;
    arithlist->tail = node;
  }
  else
  {
    ListNode *node = malloc(sizeof(ListNode));
    strcpy(node->word, word);
    strcat(node->word, "\n");
    node->next = current->next;
    node->prev = current;
    if (current->next != NULL)
    {
      current->next->prev = node;
    }

    current->next = node;
  }
}
// Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List *arithlist, char *word)
{
  if (arithlist == NULL)
    return;

  ListNode *node = malloc(sizeof(ListNode));
  strcpy(node->word, word);
  strcat(node->word, "\n");

  if (arithlist->head == NULL)
  {
    arithlist->head = node;
    node->prev = NULL;
  }
  else
  {
    arithlist->tail->next = node;
    node->prev = arithlist->tail;
  }
  arithlist->tail = node;
  node->next = NULL;
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
//
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List *arithlist, ListNode *ln)
{
  if (arithlist == NULL)
    return false;
  if (arithlist->head == NULL && arithlist->tail == NULL)
    return false;
  ListNode *node = arithlist->head;
  while (node != NULL)
  {
    if (node == ln)
    {
      if (node == arithlist->head)
      {
        if (arithlist->tail == arithlist->head)
        {
          arithlist->tail = NULL;
        }
        arithlist->head = node->next;
        if (node->next != NULL)
        {
          node->next->prev = NULL;
        }
      }
      else
      {
        node->prev->next = node->next;
        if (node->next != NULL)
        {
          node->next->prev = node->prev;
        }
        else
        {
          arithlist->tail = node->prev;
        }
      }

      free(node);

      return true;
    }
    else
    {
      node = node->next;
    }
  }
  return false;
}
#endif
