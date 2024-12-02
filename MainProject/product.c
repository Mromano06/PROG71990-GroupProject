#define _CRT_SECURE_NO_WARNINGS

#include "product.h"
#include "productList.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// Product implementation

PRODUCT CreateProduct(float Price, int Sku, int Quantity, char Name[], char Desc[]) {
	PRODUCT newProduct;

	newProduct.price = Price;
	newProduct.sku = Sku;
	newProduct.quantity = Quantity;
	strncpy(newProduct.name, Name, NAME_LENGTH);
	strncpy(newProduct.description, Desc, DESCRIPTION_LENGTH);

	return newProduct;
}

// allows the user to update the selected kind of data
bool UpdateProduct(PRODUCT* p) {
	int inputNum = 0;
	printf("1. Edit price\n2. Edit sku\n3. Edit quantity\n"
		   "4. Edit the products name\n5. Edit the products description"
		   "\n0. Cancel\nEnter selection: ");
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
		p->price = tempPrice;
		break;
	case 2:
		printf("\nEnter new sku: ");
		int tempSku = 0;
		scanf_s("%d", &tempSku);
		p->sku = tempSku;
		break;
	case 3:
		printf("\nEnter new quantity: ");
		int tempQuantity = 0;
		scanf_s("%d", &tempQuantity);
		p->quantity = tempQuantity;
		break;
	case 4:
		printf("\nEnter new name: ");
		char tempName[NAME_LENGTH] = { '\0' };
		scanf_s("%s", tempName, NAME_LENGTH);
		strncpy(p->name, tempName, NAME_LENGTH);
		break;
	case 5:
		printf("\nEnter new description: ");
		char tempDescription[DESCRIPTION_LENGTH] = { '\0' };
		scanf_s("%s", tempDescription, DESCRIPTION_LENGTH);
		strncpy(p->description, tempDescription, DESCRIPTION_LENGTH);
		break;
	default:
		printf("\nInvalid Input");
		return false;
	}

	return true;
}

// makes an exact copy of the product
PRODUCT CopyProduct(PRODUCT p) {
	return CreateProduct(p.price, p.sku,													
		p.quantity,p.name, p.description);
}

void DisplayAll(PLISTNODE list) { // function to display all products
	PLISTNODE current = list;

	printf("\nAll Products:\n");
	while (current != NULL) {
		printf("sku: %d, name: %s, auantity: %d, price: %.2f, description: %s\n", // print the data of current
			current->data.sku, current->data.name,
			current->data.quantity, current->data.price,
			current->data.description);
		
		current = current->next; // continue to the next product
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
	// current = head; // TODO
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

// prints product
void PrintProduct(PRODUCT p) {		
	printf("sku: %d, name: %s, auantity: %d, price: %.2f, description: %s\n", // print the data of located product
		p.sku, p.name, p.quantity, p.price, p.description);
    }

// reads a product from the file 
// (info held in the file will most likely be held in a list,
// formatting an dprinting will ony be used in the interface/UI)
bool ReadProductFromFile(const char* fileName, PRODUCT* p) {
	FILE* readFile;
	readFile= fopen(fileName, "r");															
	if (readFile == NULL) {
		perror("Error opening original file");
		exit(EXIT_FAILURE);
	}

	float price = 0;													// temp variables for saving the product
	int sku = 0, quantity = 0;
	char name[NAME_LENGTH] = { '\0' },
		desc[DESCRIPTION_LENGTH] = { '\0' };

	// float Price, int Sku, int Quantity, char Name[], char Desc[]
	if (fscanf(readFile, "%f %d %d %s %s", &price, &sku,				// reads data from file and saves into sent product
		&quantity, name, desc) == 5) {	
		p->price = price;
		p->sku = sku;
		p->quantity = quantity;
		strncpy(p->name, name, NAME_LENGTH);
		strncpy(p->description, desc, DESCRIPTION_LENGTH);
	}
	else
		return false;


	return true;
}

// write a product to the file
bool WriteProductToFile(const char* fileName, PRODUCT* p) {
	FILE* writeFile;
	writeFile = fopen(fileName, "w");
	if (writeFile == NULL) {
		perror("Error opening original file");
		exit(EXIT_FAILURE);
	}

	if (!fprintf(writeFile, "%f %d %d %s %s", p->price, p->sku,			// prints p's data to file
		p->quantity, p->name, p->description))
		return false;


	return true;
}

void DeleteProduct(PRODUCT p) {																
	// this wont do much right now (or ever)
}