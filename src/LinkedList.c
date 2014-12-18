#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include "LinkedList.h"

/** Create new list for linkList
 *  input :
 *          *data is a void data type
 *  output  :
 *            return linkList pointer and contain new list
 **/
LinkedList *linkListNew(void *data) {
  LinkedList *link = malloc(sizeof(LinkedList));

  link->next = NULL;
  link->data = data;

  return link;
}

/** Destroy(free) all list in LinkedList
 *  input :
 *          *firstList is the pointer pointing to the first list in LinkedList
 *  output  :
 *            free all malloc memory in LinkedList
 **/
void destroyAllLinkedLists(LinkedList *firstList)  {

  if(firstList->next != NULL)
    destroyAllLinkedLists(firstList->next);

  free(firstList);
}

/** addLinkedList add newList into LinkedList
 *  input :
 *          **listPtr is the pointer pointing to head pointer address
 *          *newList is the pointer pointing to the new created list
 *  output  :
 *            newList should contain in the LinkList->next;
 **/
void addLinkedList(LinkedList **listPtr, LinkedList *newList) {
  LinkedList *head = *listPtr, *tail;
  
  if(head == NULL)  {
    *listPtr  = newList;
    return;
  }
  
  else  {
    tail = head;  
    while(tail->next != NULL) {
      tail = tail->next;
    } 
    tail->next = newList;
  }
}

/** compare(void *dataInCollection, void *data)
 *  input :
 *          *dataInCollection is data in linkedlist
 *          *data is a void type data act as a reference target
 *  output  :
 *           return 1 if dataInCollection == data
 *           return 0 if dataInCollection != data
 **/
int compare(void *dataInCollection, void *data) {
  char *dataInList = (char*)dataInCollection;
  char *target = (char*)data;
  
  assert(dataInList != NULL);
  assert(target != NULL);
  
  if(dataInList == target)
    return 1;
  
  return 0;
}

/** findLinkedList(LinkedList **listPtr, void *data, int(*compare)(void *dataInCollection, void *data))
 *  input :
 *          **listPtr is the pointer pointing to head pointer address
 *          *data is a void type data act as a reference target
 *          int(*compare) is a function pointer used to compare target and dataInCollection
 *  output  :
 *           
 **/
LinkedList *findLinkedList(LinkedList **listPtr, void *data, int(*compare)(void *dataInCollection, void *data)) {
  LinkedList *head = *listPtr, *tail;
  
  if(head == NULL)  {
    return NULL;
  }
  
  assert(head->next != NULL);
  
  tail = head;
  while(tail->data) {
    if(compare(tail->data, data))
      return tail;     
    tail = tail->next;
  };
}