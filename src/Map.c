#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "Map.h"

Map *createMap(int size)  {
  Map *map = malloc(sizeof(Map));
  map->size = size;
  map->table = malloc(sizeof(LinkedList *) * size);
  return map;
}

Map *destroyMap(Map *map)  {
  int i;

  if(map != NULL) {
    for(i = 0; i < map->size; i++)  {
      destroyAllLinkedLists(map->table[i]);
    }
  }
  free(map->table);
  free(map);
}

void addMap(Map *map, void *data, int (*hash)(void *data))  {
  int i, hashValue = hash(data);
  
  // LinkedList *head = map->table[hashValue];
  // printf("&map->table[hashValue] %p\n", &(map->table)[hashValue]);
  // printf("&head %p\n", &head);
  addLinkedList(&map->table[hashValue], linkListNew(data));
  // printf("*head %p\n", &(*head));
  // map->table[hashValue] = &head;
  // (*map->table)[hashValue].data = linkListNew(data);
  // if((*map->table)[hashValue]= NULL)
    // printf("HI\n");
}