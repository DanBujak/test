/**
 * @file linkedlist.c
 * @brief Linked list implementation
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "linkedlist.h"


/**
 * @Brief Prints the contents
 */
void LL_Print ( struct Node * node )
{
  printf("Printing Linked List:\t\n");

  if ( node == NULL )
  {
    printf("\tList is empty!\r\n");
    return;
  }

  uint16_t counter = 0;
  
  while ( node != NULL)
  {
    printf("\tNode [%d]: %d\r\n", counter++, node->data.x);
    node = node->next;
  }
}


/**
 * @Brief Frees up memory used by LL
 */
int LL_Destroy ( struct Node * head_ref )
{
  struct Node * temp_node;
  uint16_t counter = 0;
  
  while ( head_ref != NULL )
  {
    /* Store head temporarily to have reference to free. Then update head */
    temp_node = head_ref;
    head_ref=head_ref->next;
    free((void*)temp_node);
    counter++;
  }

  return counter;
}


/**
 * @Brief Add an item to the head of the LL
 * @Details Time complexity = O(1)
 */
int LL_Insert_Head ( struct Node ** head_ref, struct nData * data )
{
  /* Allocate node */
  struct Node * temp_node = (struct Node *)malloc(sizeof(struct Node));
  if ( temp_node == NULL )
  {
    return -1;
  }

  /* Populate new node and set to head */
  temp_node->data.x = data->x;
  temp_node->next = *head_ref;

  *head_ref = temp_node;

  return 0;
}

/**
 * @Brief Insert an item in the LL
 * @Detail Time complexity = O(1)
 */
int LL_Insert_Behind ( struct Node * prev_ref, struct nData * data )
{
  /* Make sure we got a valid reference */
  if ( prev_ref == NULL )
  {
    return -1;
  }

  /* Allocate node */
  struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
  if ( new_node == NULL )
  {
    return -1;
  }

  /* Populate new node and insert it in list */
  new_node->data.x = data->x;
  new_node->next = prev_ref->next;

  prev_ref->next = new_node;

  return 0;
}


/**
 * @Brief Add an item to the tail of the LL
 * @Detail Time complexity = O(n)
 */
int LL_Insert_Tail ( struct Node ** head_ref, struct nData * data )
{
  if ( head_ref == NULL || data == NULL )
  {
    return -1;
  }

  /* Allocate & initialize new tail node */
  struct Node * new_tail = (struct Node *)malloc(sizeof(struct Node));  
  if ( new_tail == NULL )
  {
    return -1;
  }
  new_tail->next   = NULL;
  new_tail->data.x = data->x;

  /* Check if list is empty in which case we insert at head */
  if ( *head_ref == NULL )
  {
    *head_ref = new_tail;
  }
  else
  {
    /* Use a temporary pointer to find current tail node */
    struct Node * prev_tail = *head_ref;
    while ( prev_tail->next != NULL )
    {
      prev_tail = prev_tail->next;
    }

    prev_tail->next = new_tail;
  }

  return 0;
}

/**
 * @Brief Insert an item into the list at index N
 */
int LL_Insert_At ( struct Node ** head_ref, uint16_t n, struct nData * data )
{
  if ( *head_ref == NULL || data == NULL )
  {
    return -1;
  }

  if ( n == 0 )
  {
    return -1;
  }

  /* Find the (N-1)th node */
  struct Node * prev_node = *head_ref;
  uint16_t counter = 0;
  while ( prev_node != NULL && prev_node->next != NULL && counter != (n-1) )
  {
    prev_node = prev_node->next;
    counter++;
  }

  /* Check to make sure the list is at least N-1 elements long */
  if ( counter != (n-1) )
  {
    return -1;
  }

  /* Allocate new node, initialize it and insert it after prev_node */
  struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
  memcpy(&new_node->data, data, sizeof(struct nData));
  new_node->next = prev_node->next;
  prev_node->next = new_node;

  return 0;
}


/**
 * @Brief Delete the head of the LL
 */
int LL_Pop_Head ( struct Node ** head_ref, struct nData * result )
{
  /* Check for empty LL */
  if ( *head_ref == NULL || result == NULL )
  {
    return -1;
  }

  /* store previous head to free and update head to point to next node */
  struct Node * previousHead = *head_ref;

  result->x = (*head_ref)->data.x;
  *head_ref = (*head_ref)->next;

  free((void*)previousHead);

  return 0;
}


/**
 * @Brief Find an entry in the LL
 */
struct Node * LL_Get_Node_By_Key ( struct Node * head_ref, struct nData * value )
{
  while ( head_ref != NULL )
  {
    if ( head_ref->data.x == value->x )
    {
      return head_ref;
    }

    head_ref = head_ref->next;
  }

  return NULL;
}


int LL_Get_At ( struct Node * head_ref, uint16_t n, struct nData * value )
{
  if ( head_ref == NULL || value == NULL )
  {
    return -1;
  }

  /* Create node to walk list */
  struct Node * walk = head_ref;
  uint16_t counter = 0;
  while ( walk->next != NULL && counter != n )
  {
    walk = walk->next;
    counter++;
  }

  /* Didn't find the node */
  if ( counter != n )
  {
    return -1;
  }

  memcpy(value, &walk->data, sizeof(struct nData));
}


int LL_Delete_Node ( struct Node ** head_ref, struct Node * target )
{
  struct Node ** indirect_node = head_ref;

  while ( *indirect_node != target )
  {
    indirect_node = &(*indirect_node)->next;
  }

  *indirect_node = target->next;

  free(target);
}

int LL_Reverse ( struct Node ** head_ref )
{
  if ( head_ref == NULL )
  {
    return -1;
  }

  /* Temporary node pointers to track prev, curr, next from perspective
     of original order */
  struct Node * prev_node = NULL;
  struct Node * curr_node = *head_ref;
  struct Node * next_node = NULL;

  while ( curr_node != NULL )
  {
    /* Backup next item in list */
    next_node = curr_node->next;

    /* Current points to previous (reverse) */
    curr_node->next = prev_node;

    /* Update pointers for next iteration */
    prev_node = curr_node;
    curr_node = next_node;
  }

  *head_ref = prev_node;
  return 0;
}

//  Head                     Tail
//[data|*] -> [data|*] -> [data|*]
