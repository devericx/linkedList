#include <stdio.h>
#include "linkedList.h"

int main(int argc, char** argv) {
	Item* originItem = createItem("Hello world!");
	LinkedList* list = createList(originItem);

	addItem(list, createItem("Bye world!"));
	addItem(list, createItem("Hello world, again!"));

	printList(list);

	printf("Deleting last item ...\n");
	delItem(list, "Hello world, again!");

	printList(list);

	printf("Adding another item ...\n");
	addItem(list, createItem("Another item!"));

	printList(list);

	printf("Deleting middle item ...\n");
	delItem(list, "Bye world!");

	printList(list);

	printf("Freeing list ...\n");
	freeList(list);

	return 0;
}