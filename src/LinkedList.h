#ifndef LinkedList_H
#define LinkedList_H

#include "Student.h"

typedef struct LinkedList LinkedList;

struct LinkedList {
  LinkedList *next;
  void *data;
};

#define findTargetInList(listPtr, data) findLinkedList(listPtr, data, compare)

LinkedList *linkListNew(void *data);
void addLinkedList(LinkedList **listPtr, LinkedList *newList);
void removeLinkedList(LinkedList **listPtr, LinkedList *listToRemove);
void destroyAllLinkedLists(LinkedList *firstList);
int compare(void *dataInCollection, void *data);
LinkedList *findLinkedList(LinkedList **listPtr, void *data, int(*compare)(void *dataInCollection, void *data));
#endif // LinkedList_H
