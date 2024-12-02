#define _CRT_SECURE_NO_WARNINGS

#include "product.h"
#include "productList.h"
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// product list implementation
// (most of this code is resued)

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

void DestroyList(PLISTNODE* list) {											// be careful becasue this doesn't actually "destroy" it
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DeleteProduct(current->data);										// delete product isnt real ;)
		current = current->next;
		free(tmp);
	}
}

bool SearchProductMenu(PLISTNODE list) {

	bool continueSearch = true;
	while (continueSearch) {
		int searchType = 0;

		printf("|-----------------------------|\n");
		printf("| 2. Search single item       |\n");
		printf("| 1. Search range of items    |\n");
		printf("| 0. Return to previous menu  |\n");
		printf("|-----------------------------|\n");

		printf("Enter option: ");
		if (scanf("%d", &searchType) != 1 || searchType > 2 || searchType < 0) {
			printf("Invaild option");
			return 0;
		}

		switch (searchType)
		{
		case 2: // search 1 item
			SearchSingleProduct(list); //TODO: i dunno what to run though this func yet (same with the search range)

			break;
		case 1:	// search range of items
			SearchRangeOfProducts(list);

			break;
		case 0: // return to previous menu
			searchType = false;
			break;
		default:
			printf("\nInvalid Input");
			break;
		}
	}
}

bool SearchSingleProduct(PLISTNODE list) {
	int sku = 0;
	char name[NAME_LENGTH] = { '\0' };
	PLISTNODE current = list;

	printf("Enter products sku and name (sku name): ");
	if (scanf("%d %s", &sku, name) != 2) {
		perror("Invalid input");
	}
	// current = head; // TODO - matty daddy got it baby
	while (current != NULL) {

		if (current->data.sku == sku && current->data.name == name) {
			printf("Product found: \n");
			PrintProduct(current->data);
		}

		else
			current = current->next; // continue to the next product
	}
}

bool SearchRangeOfProducts(PLISTNODE list) {
	int skuStart, skuEnd = 0;			// create variables for the start and end of the range
	char nameStart[NAME_LENGTH] = { '\0' },
		nameEnd[NAME_LENGTH] = { '\0' };

	int skuTemp1 = 0;
	int skuTemp2 = 0;			// create variables for the users sku inputs to verify start and end
	char nameTemp1[NAME_LENGTH] = { '\0' },
		nameTemp2[NAME_LENGTH] = { '\0' };
	PLISTNODE current = list;

	// current = head; // TODO

	bool start = false, end = false;

	printf("Enter range you would like to search, by products skus and names (sku1 name1, sku2 name2): ");
	if (scanf("%d %s, %d %s", &skuTemp1, nameTemp1, &skuTemp2, nameTemp2) != 4) {
		printf("Invalid input");
		return false;
	}

	if (skuTemp1 < skuTemp2) { // set the lower sku to the start (if we end up sorting by highest to lowest reverse this)
		skuStart = skuTemp1;
		strncpy(nameStart, nameTemp1, NAME_LENGTH);
	}
	else {
		skuStart = skuTemp2;
		strncpy(nameStart, nameTemp2, NAME_LENGTH);
	}

	while (current != NULL) {

		if (current->data.sku == skuStart && current->data.name == nameStart) // find the start product first
			start = true;
		if (current->data.sku == skuEnd && current->data.name == nameEnd)
			end = true;

		else
			current = current->next; // continue to the next product
	}

	if (start && end) {// if both the start product and end product are found then continue 
		// current = head; // TODO: create a pointer in place of head that points to the start of the listnodes 
		// might work now
		current = list;
		while (current != NULL && current->data.sku != skuStart) { // loop through the nodes till we find the one that has our sku 
			current = current->next;							   // this makes current land on this start product
		}
		while (current != NULL && current->data.sku <= skuEnd) {
			PrintProduct(current->data);
			current = current->next;
		}
		return true;
	}

	return false;
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

void FindProductToUpdate(PLISTNODE list) {
	//	UpdateProduct
}