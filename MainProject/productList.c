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

void DisplayAll(PLISTNODE list) { // function to display all products
	PLISTNODE current = list;

	printf("\nAll Products:\n");
	while (current != NULL) {
		printf("sku: %d, name: %s, qauantity: %d, price: %.2f, description: %s\n", // print the data of current
			current->data.sku, current->data.name,
			current->data.quantity, current->data.price,
			current->data.description);

		current = current->next; // continue to the next product
	}

	printf("\n");
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

//TODO make this actually return to the main menu
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
			SearchSingleProduct(list);

			break;
		case 1:	// search range of items
			SearchRangeOfProducts(list);

			break;
		case 0: // return to previous menu
			continueSearch = false;
			break;
		default:
			printf("\nInvalid Input");
			break;
		}
	}
}

bool SearchSingleProduct(PLISTNODE list) {
	int sku = 0;
	PLISTNODE current = list;

	printf("Enter products sku: ");
	if (scanf("%d", &sku) != 1) {
		perror("Invalid input");
	}

	while (current != NULL) {

		if (current->data.sku == sku) {
			printf("Product found: \n");
			PrintProduct(current->data);
			printf("\n");
			return true;
		}

		else
			current = current->next; // continue to the next product
	}
	printf("Product NOT found\n");

	return false;
}

bool SearchRangeOfProducts(PLISTNODE list) {
	int skuStart = 0, skuEnd = 0;			// create variables for the start and end of the range
	int skuTemp1 = 0, skuTemp2 = 0;			// create variables for the users sku inputs to verify start and end
	
	PLISTNODE current = list;

	// current = head; // TODO

	bool start = false, end = false;

	printf("Enter range you would like to search, by products sku's (sku sku): ");
	if (scanf("%d %d", &skuTemp1, &skuTemp2) != 2) {
		printf("Invalid input");
		return false;
	}

	if (skuTemp1 < skuTemp2) { // set the lower sku to the start (if we end up sorting by highest to lowest reverse this)
		skuStart = skuTemp1;
		skuEnd = skuTemp2;
	}
	else {
		skuStart = skuTemp2;
		skuEnd = skuTemp1;
	}

	while (current != NULL) {

		if (current->data.sku == skuStart) // find the start product first
			start = true;
		if (current->data.sku == skuEnd)
			end = true;
		
		current = current->next; // continue to the next product
	}

	if (start && end) {// if both the start product and end product are found then continue 
		current = list;

		while (current != NULL) {
			if (current->data.sku >= skuStart && current->data.sku <= skuEnd)
				PrintProduct(current->data);
		
				current = current->next;
		}
		
		printf("\n");
		return true;
	} 

	printf("1 or more products not found");
	return false;
}

// these funtions should properly down/upload all data
void PrintListToStream(PLISTNODE list, const char* fileName) {
	FILE* writeFile;
	writeFile = fopen(fileName, "w");
	if (writeFile == NULL) {
		perror("Error opening original file");
		exit(EXIT_FAILURE);
	}
	PLISTNODE current = list;
	while (current != NULL) {
		if (!WriteProductToFile(fileName, current->data, writeFile)) {}
			break;
		current = current->next;
	}

	fclose(writeFile);
}

void CreateListFromStream(PLISTNODE list, const char* fileName) {
	PLISTNODE current = list;
	do {
		if (!ReadProductFromFile(fileName, &current->data))
			break;
		current = current->next;
	} while (current != NULL);
}

int GetListSize(PLISTNODE listHead) {										// gets size of the list
	int count = 0;
	PLISTNODE current = listHead;
	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

void FindProductToUpdate(PLISTNODE list) {
	int sku = 0;
	char name[NAME_LENGTH] = { '\0' };
	PLISTNODE current = list;

	printf("Enter products sku and name (sku name): ");
	if (scanf("%d %s", &sku, name) != 2) {
		perror("Invalid input");
	}

	while (current != NULL) {

		if (current->data.sku == sku && current->data.name == name) {
			printf("Product found\n");
			UpdateProduct(&current->data);
		}

		else
			current = current->next; // continue to the next product
	}
}

// allows the user to update the selected kind of data
bool UpdateProduct(PLISTNODE list) {
	int inputNum = 0;
	int skuInput = 0;
	PLISTNODE current = list;

	SearchSingleProduct(list);

	printf("|--------------------|\n");
	printf("| 1. Edit price      |\n");
	printf("| 2. Edit sku        |\n");
	printf("| 3. Edit quantity   |\n");
	printf("| 4. Edit name       |\n");
	printf("| 5. Edit description|\n");
	printf("| 0. Cancel          |\n");
	printf("|--------------------|\n");

	printf("Enter selection: ");
	scanf_s("%d", &inputNum);

	// checks for what you want to change
	// user can input any specific part of the product to edit
	switch (inputNum)
	{
	case 0:
		return false;
	case 1:
		printf("\nEnter new price: ");
		float tempPrice = 0;
		scanf_s("%f", &tempPrice);
		current->data.price = tempPrice;
		break;
	case 2:
		printf("\nEnter new sku: ");
		int tempSku = 0;
		scanf_s("%d", &tempSku);
		current->data.sku = tempSku;
		break;
	case 3:
		printf("\nEnter new quantity: ");
		int tempQuantity = 0;
		scanf_s("%d", &tempQuantity);
		current->data.quantity = tempQuantity;
		break;
	case 4:
		printf("\nEnter new name: ");
		char tempName[NAME_LENGTH] = { '\0' };
		scanf_s("%s", tempName, NAME_LENGTH);
		strncpy(current->data.name, tempName, NAME_LENGTH);
		break;
	case 5:
		printf("\nEnter new description: ");
		char tempDescription[DESCRIPTION_LENGTH] = { '\0' };
		scanf_s("%s", tempDescription, DESCRIPTION_LENGTH);
		strncpy(current->data.description, tempDescription, DESCRIPTION_LENGTH);
		break;
	default:
		printf("\nInvalid Input");
		return false;
	}

	return true;
}
