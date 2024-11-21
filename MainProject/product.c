#define _CRT_SECURE_NO_WARNINGS

#include "product.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// group4 - 71990f24 - group project

// Product implementation

PRODUCT CreateProduct(float Price, int Sku, int Quantity, char Name[], char Desc[]) {			// add this to a linked list
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

	switch (inputNum)																			// checks for what you want to change
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

// prints product
void PrintProduct(PRODUCT p) {		
	printf("");											// this is all yours liv make it super fancy
}

void DeleteProduct(PRODUCT p) {																
	// this wont do much right now (or ever)
}