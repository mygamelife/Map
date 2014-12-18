#include "unity.h"
#include "Map.h"
#include "LinkedList.h"
#include "Student.h"
#include "mock_HashFunction.h"

void setUp(void)  {}

void tearDown(void) {}

void test_createMap_should_return_a_map(void) {
  Map *map = createMap(10);

  TEST_ASSERT_NOT_NULL(map);
  TEST_ASSERT_EQUAL(10, map->size);
  TEST_ASSERT_NOT_NULL(map->table);
}

void test_addMap_given_ali_should_add_in_slot_4(void)  {
  Student ali = {.name = "ali", .age = 10};
  Map *map = createMap(10);

  hash_ExpectAndReturn((void *)&ali, 2);

  addMap(map, (void*)&ali, hash);
  LinkedList *firstList = map->table[2];
  printf("*firstList %p\n", &(*firstList));
  TEST_ASSERT_NOT_NULL(firstList);
  TEST_ASSERT_EQUAL_PTR(&ali, (Student *)(firstList->data));

  destroyMap(map);
}