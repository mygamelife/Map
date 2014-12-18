#include "unity.h"
#include "LinkedList.h"
#include "Map.h"
#include "Student.h"
#include "mock_HashFunction.h"

void setUp(void)  {}

void tearDown(void) {}

/** test linkListNew()
 ** Create a new list for linkedList and return the linkList pointer
 **/
void test_linkListNew_should_add_list_into_LinkedList(void) {
  char *name = "LinkList";
  LinkedList *link = linkListNew(name);

  TEST_ASSERT_NOT_NULL(link);
  char *result = (char*)link->data;
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL_STRING("LinkList", result);

  destroyAllLinkedLists(link);
}

/** test addLinkedList()
 ** Given one created newList should add into LinkedList
 *
 ** result  :
 *
 *                    After Add           ----------
 *     head-> NULL      --->      head-> | newList | -> NULL
 *                                       ----------
 **/
void test_addLinkedList_should_add_created_list_into_LinkedList(void) {
  char *name = "YOYO";
  LinkedList *head = NULL;
  LinkedList *newList = linkListNew(name);

  addLinkedList(&head, newList);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NULL(head->next);
  char *result = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("YOYO", result);
  
  destroyAllLinkedLists(head);
}

/** test addLinkedList()
 ** Given two created newList should add into LinkedList
 *
 ** result  :
 *
 *                    Add first                                   second
 *                      list              ----------              list              ----------     ----------
 *     head-> NULL      --->      head-> |  lsit1  | -> NULL      --->      head-> |  list1  | -> |  list2  | -> NULL
 *                                       ----------                                ----------     ----------
 *
 *                   Add third
 *                     list           ----------     ----------     ----------
 *                     --->  head->  |  list1  | -> |  list2  | -> |  list3  | -> NULL
 *                                   ----------     ----------     ----------
 **/
void test_addLinkedList_should_add_two_created_list_into_LinkedList(void) {
  char *name1 = "IM";
  char *name2 = "JUST";
  char *name3 = "LIST";
  
  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);

  addLinkedList(&head, list1);  
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NULL(head->next);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("IM", result1);
  
  addLinkedList(&head, list2);
  TEST_ASSERT_NOT_NULL(head->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("JUST", result2);
  
  addLinkedList(&head, list3);
  TEST_ASSERT_NOT_NULL(head->next->next);
  TEST_ASSERT_NULL(head->next->next->next);
  char *result3 = (char*)head->next->next->data;
  TEST_ASSERT_EQUAL_STRING("LIST", result3);

  destroyAllLinkedLists(head);
}

void test_compare_given_data1_Sam_data2_Jack_should_return_0(void) {
  void *dataInCollection = "Sam";
  void *data = "Jack";

  TEST_ASSERT_EQUAL(0, compare(dataInCollection, data));
}

void test_compare_given_MONKEY_and_MONKEY_should_return_1(void) {
  void *dataInCollection = "MONKEY";
  void *data = "MONKEY";

  TEST_ASSERT_EQUAL(1, compare(dataInCollection, data));
}

void test_findLinkedList_given_target_fool_should_should_return_LinkedList_contain_fool(void) {
  char *data1 = "Someone";
  char *data2 = "JUST";
  char *data3 = "fool";
  LinkedList *result;
  
  /* Add list into LinkedList */
  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(data1);
  LinkedList *list2 = linkListNew(data2);
  LinkedList *list3 = linkListNew(data3);
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);

  result = findTargetInList(&head, data3);
  TEST_ASSERT_NOT_NULL(result);
  TEST_ASSERT_EQUAL_PTR(list3, result);
  char *resultData = (char*)result->data;
  TEST_ASSERT_EQUAL_STRING(data3, resultData);
  TEST_ASSERT_NULL(result->next);
  
  destroyAllLinkedLists(head);
}

void test_findLinkedList_given_target_food_should_should_return_LinkedList_contain_food(void) {
  char *data1 = "OMG";
  char *data2 = "this";
  char *data3 = "retard";
  char *data4 = "is";
  char *data5 = "so";
  char *data6 = "cool";
  LinkedList *result;
  
  /* Add list into LinkedList */
  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(data1);
  LinkedList *list2 = linkListNew(data2);
  LinkedList *list3 = linkListNew(data3);
  LinkedList *list4 = linkListNew(data4);
  LinkedList *list5 = linkListNew(data5);
  LinkedList *list6 = linkListNew(data6);
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  addLinkedList(&head, list4);
  addLinkedList(&head, list5);
  addLinkedList(&head, list6);

  result = findTargetInList(&head, data4);
  TEST_ASSERT_NOT_NULL(result);
  TEST_ASSERT_EQUAL_PTR(list4, result);
  char *resultData = (char*)result->data;
  TEST_ASSERT_EQUAL_STRING(data4, resultData);
  TEST_ASSERT_NOT_NULL(result->next);
  
  destroyAllLinkedLists(head);
}