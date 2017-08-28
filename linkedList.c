#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

LinkedList* createList(Item* originItem) {
	LinkedList* list = malloc(sizeof(LinkedList));
	list->originItem = originItem;

	return list;
}

void freeList(LinkedList* list) {
	Item* currentItem = list->originItem;
	Item* tempItem;

	while (currentItem != NULL) {
		tempItem = currentItem;
		currentItem = currentItem->nextItem;
		free(tempItem);
	}

	free(list);
}

void printList(LinkedList* list) {
	int index = 0;
	Item* currentItem = list->originItem;

	for (index = 0; currentItem->nextItem != NULL; index++) {
		printf("(%i, %s) -> ", index, currentItem->data);
		currentItem = currentItem->nextItem;
	}

	printf("(%i, %s)\n", index, currentItem->data);
}

Item* createItem(char* data) {
	Item* item = malloc(sizeof(Item));

	item->nextItem = NULL;
	item->data = data;

	return item;
}

Item* getFinalItem(LinkedList* list) {
	Item* currentItem = list->originItem;

	while (currentItem->nextItem != NULL) {
		currentItem = currentItem->nextItem;
	}

	return currentItem;
}

void addItem(LinkedList* list, Item* newItem) {
	Item* finalItem = getFinalItem(list);
	finalItem->nextItem = newItem;
}

int delItem(LinkedList* list, char* data) {
	int matched = 0;
	Item* currentItem = list->originItem;
	Item* cursor = currentItem;

	while (currentItem != NULL) {
		if (currentItem->data == data)  {
			matched = 1;
			break;
		}
		currentItem = currentItem->nextItem;
	}

	if (matched == 0) {
		return 1;
	} else if (currentItem == list->originItem) {
		list->originItem = currentItem->nextItem;

		free(currentItem);
		return 0;
	} else if (currentItem == getFinalItem(list)) {
		while (cursor->nextItem != getFinalItem(list)) {
			cursor = cursor->nextItem;
		}

		cursor->nextItem = NULL;

		free(currentItem);
		return 0;
	} else {
		while (cursor->nextItem != currentItem) {
			cursor = cursor->nextItem;
		}

		cursor->nextItem = currentItem->nextItem;

		free(currentItem);
		return 0;
	}
}

void printItem(Item* item) {
	printf("%s\n", item->data);
}
