#include "unity.h"
#include "Map.h"
#include "LinkedList.h"
#include "Student.h"
#include "mock_HashFunction.h"
#include <assert.h>

void setUp(void)  {}

void tearDown(void) {}

void test_createMap_should_return_a_map(void) {
  Map *map = createMap(10);

  TEST_ASSERT_NOT_NULL(map);
  TEST_ASSERT_EQUAL(10, map->size);
  TEST_ASSERT_NOT_NULL(map->table);
}

void test_addMap_given_ali_should_add_in_slot_2(void)  {
  Student ali = {.name = "ali", .age = 10};
  Map *map = createMap(10);

  hash_ExpectAndReturn((void *)&ali, 2);
  addMap(map, (void*)&ali, hash);
  
  LinkedList *mapList = map->table[2];

  TEST_ASSERT_NOT_NULL(mapList);
  Student *student = (Student*)(mapList->data);
  TEST_ASSERT_EQUAL_PTR(&ali, student);

  destroyMap(map);
}

void test_addMap_given_arLong_and_Nami_should_add_in_slot_4_and_slot_8(void)  {
  Student arLong = {.name = "arLong", .age = 22};
  Student Nami = {.name = "Nami", .age = 16};
  Map *map = createMap(10);

  hash_ExpectAndReturn((void*)&arLong, 4);
  addMap(map, (void*)&arLong, hash);
  
  LinkedList *mapList4 = map->table[4];
  
  TEST_ASSERT_NOT_NULL(mapList4);
  Student *student4 = (Student*)(mapList4->data);
  TEST_ASSERT_EQUAL_PTR(&arLong, student4);
  
  hash_ExpectAndReturn((void*)&Nami, 8);
  addMap(map, (void*)&Nami, hash);
  
  LinkedList *mapList8 = map->table[8];

  TEST_ASSERT_NOT_NULL(mapList8);
  Student *student8 = (Student*)(mapList8->data);
  TEST_ASSERT_EQUAL_PTR(&Nami, student8);

  destroyMap(map);
}