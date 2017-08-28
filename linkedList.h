#ifndef linkedList_H
#define linkedList_H

typedef struct _Item {
	struct _Item* nextItem;
	char* data;
} Item;

typedef struct LinkedList {
	Item* originItem;
} LinkedList;

LinkedList* createList(Item* originItem);

void freeList(LinkedList* list);

void printList(LinkedList* list);

Item* createItem(char* data);

Item* getFinalItem(LinkedList* list);

void addItem(LinkedList* list, Item* newItem);

int delItem(LinkedList* list, char* data);

void printItem(Item* item);

#endif