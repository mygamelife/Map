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
  if(firstList != NULL) {
    if(firstList->next != NULL)
      destroyAllLinkedLists(firstList->next);
    free(firstList);
  }
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
    assert(*listPtr == NULL);
    assert(newList != NULL);
    // Student *student = (Student*)newList->data;
    // printf("student->data %s\n", student->name);
    // printf("student->age %d\n", student->age);
    *listPtr = newList;
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

  return !strcmp(dataInList, target);
}

/** findLinkedList(LinkedList **listPtr, void *data, int(*compare)(void *dataInCollection, void *data))
 *  input :
 *          **listPtr is the pointer pointing to head pointer address
 *          *data is a void type data act as a reference target
 *          int(*compare) is a function pointer used to compare target and dataInCollection
 *  output  :
 *           return LinkedList if target is found
 *           return NULL if target is not found
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

/** findLinkedList(LinkedList **listPtr, void *data, int(*compare)(void *dataInCollection, void *data))
 *  input :
 *          **listPtr is the pointer pointing to head pointer address
 *          *listToRemove is the list that need to be remove
 *  output  :
 *            remove the listToRemove into LinkedList
 **/
void removeLinkedList(LinkedList **listPtr, LinkedList *listToRemove) {
  LinkedList *head = *listPtr, *tempPtr;

  if(head == NULL)
    return;

  else  {
    while(head->next) {
      if(head->next->data == listToRemove->data)  {
        tempPtr = head->next;
        head->next = head->next->next;
        free(tempPtr);
        return;
      }
      head = head->next;
    }
  }
}