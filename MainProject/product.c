#define _CRT_SECURE_NO_WARNINGS

#include "product.h"
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
	printf("Enter 1 to edit price\nEnter 2 to edit sku\nEnter 3 to edit quantity\n");
	printf("Enter 4 to edit the products name\nEnter 5 to edit the products description");
	printf("\nEnter 0 To cancel\nEnter selection: ");
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

	if (!fprintf(writeFile, "%f %d %d %s %s", p->price, p->sku,				// prints p's data to file
		p->quantity, p->name, p->description))
		return false;


	return true;
}

void PrintProduct(PRODUCT p) {		
	printf("");															// this is all yours liv make it super fancy
}

void DeleteProduct(PRODUCT p) {																
	// this wont do much right now (or ever)
}