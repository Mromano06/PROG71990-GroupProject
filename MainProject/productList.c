#include "product.h"
#include "productList.h"
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// product list implementation

// most of this code is resued

void Add(PLISTNODE* list, PRODUCT i) {										
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));				// makes new node and error checks
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	else {																	// makes a copy of the student to point to
		newNode->data = CopyProduct(i);
		newNode->next = *list;

		*list = newNode;
	}
}

// funtion to remove a node
void Remove(PLISTNODE* list, PRODUCT i) {									
	PLISTNODE current = *list;
}

//  prints all nodes in the list
void Display(PLISTNODE list) {												
	PLISTNODE current = list;
	while (current != NULL) {
		PrintProduct(current->data);
		current = current->next;
	}
}

void DestroyList(PLISTNODE* list) {											// be carefull becasue this doesn't actually "destroy" it
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DeleteProduct(current->data);										// delete product isnt real ;)
		current = current->next;
		free(tmp);
	}
}

// these funtions should properly down/upload all data
void PrintListToStream(PLISTNODE list, const char* fileName) {
	PLISTNODE current = list;
	int i = GetListSize(current);
	for (int x = 0; x < i; x ++) {
	while (WriteProductToFile(fileName, &current->data))
		current = current->next;
	}
}

void CreateListFromStream(PLISTNODE list, const char* fileName) {
	PLISTNODE current = list;
	int i = GetListSize(current);											// checks the list size
	for (int x = 0; x < i; x++) {											// makes sure list doesnt become null pointer
		while (ReadProductFromFile(fileName, &current->data))				// (also does same in above function)
			current = current->next;
	}
}

int GetListSize(PLISTNODE* listHead) {										// gets size of the list
	int count = 0;
	PLISTNODE current = listHead;
	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}