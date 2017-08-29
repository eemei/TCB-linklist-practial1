#include "unity.h"
#include "LinkedList.h"
#include "CreateListElement.h"
#include "addList.h"
#include <stdio.h>
#include <malloc.h>

void setUp(void) {}

void tearDown(void) {}


void test_createLinkList (void){
	printf ("testing LinkList had been created:\n");
	struct LinkedList *link;
	link = createLinkedList();
	TEST_ASSERT_EQUAL (NULL, link->head);
	TEST_ASSERT_EQUAL (NULL, link->tail);
	TEST_ASSERT ( link);	
}

void test_createlistelement (void){
	printf ("testing list element had been created\n");
	struct ListElement *element;
	element = createListElement (7);
	TEST_ASSERT_EQUAL (7, element->value);
	TEST_ASSERT_EQUAL (0, element->next);
	
}

void test_linklist_able_add_on_element (void){
	printf ("testing link list can add 1 element\n");
	struct ListElement *element;
	struct LinkedList *link;
	element = createListElement (1);
	link = createLinkedList ();
	addList (element, link);
}	
	
void test_linklist_able_add_3_on_element (void){
	printf ("testing link list can add 3 element\n");
	struct ListElement *element;
	struct LinkedList *link;
	link = createLinkedList ();
	element = createListElement (1);
	addList (element, link);
	element = createListElement (3);
	addList (element, link);
	element = createListElement (9);
	addList (element, link);

}	
	
void test_linklist_able_add_5_on_element (void){
	printf ("testing link list can add 5 element\n");
	struct ListElement *element;
	struct LinkedList *link;
	link = createLinkedList ();
	element = createListElement (1);
	addList (element, link);
	element = createListElement (2);
	addList (element, link);
	element = createListElement (4);
	addList (element, link);
	element = createListElement (6);
	addList (element, link);
	element = createListElement (8);
	addList (element, link);

}	

