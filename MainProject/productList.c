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

void DestroyList(PLISTNODE* list) {							// be careful becasue this doesn't actually "destroy" it
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DeleteProduct(current->data);
		current = current->next;
		free(tmp);
	}
}