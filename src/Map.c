#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "Map.h"

Map *createMap(int size)  {
  int i;
  
  Map *map = malloc(sizeof(Map));
  map->size = size;
  map->table = malloc(sizeof(LinkedList *) * size);
  
  for(i=0; i<size; i++)
    map->table[i] = NULL;
  
  return map;
}

Map *destroyMap(Map *map) {
  int i;

  if(map != NULL) {
    for(i = 0; i < map->size; i++)
      destroyAllLinkedLists(map->table[i]);
        
    free(map->table);
    free(map);
  }
}

void addMap(Map *map, void *data, int (*hash)(void *data))  {
  int i, hashValue = hash(data);
  LinkedList *head, *listData;
  printf("hashValue %d\n", hashValue);

  listData = linkListNew(data);
  assert(listData != NULL);

  Student *student = (Student*)listData->data;
  assert(student->name != NULL);
  assert(student->age != 0);

  addLinkedList(&map->table[hashValue], listData);
  assert(map->table[hashValue] != NULL);
}