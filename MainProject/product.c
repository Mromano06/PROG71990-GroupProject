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

	strncpy(newProduct.name, Name, NAME_LENGTH - 1);
	newProduct.name[NAME_LENGTH - 1] = '\0'; // null termination

	strncpy(newProduct.description, Desc, DESCRIPTION_LENGTH - 1);
	newProduct.description[DESCRIPTION_LENGTH - 1] = '\0'; // null termination

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

// prints product
void PrintProduct(PRODUCT p) {		
	printf("sku: %d, name: %s, qauantity: %d, price: %.2f, description: %s\n", // print the data of located product
		p.sku, p.name, p.quantity, p.price, p.description);
    }

// reads a product from the file 
// (info held in the file will most likely be held in a list,
// formatting an dprinting will ony be used in the interface/UI)
//TODO figure out why im getting exception here
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
	if (fscanf(readFile, "%f\n%d\n%d\n%s\n%s\n", &price, &sku,				// reads data from file and saves into sent product
		&quantity, name, desc) == 5) {
		p->price = price;
		p->sku = sku;
		p->quantity = quantity;
		strncpy(p->name, name, NAME_LENGTH);
		strncpy(p->description, desc, DESCRIPTION_LENGTH);
	}
	else{
		return false;
	}
	fclose(readFile);

	return true;
}

// write a product to the file
bool WriteProductToFile(const char* fileName, PRODUCT p, FILE* writeFile) {

	if (!fprintf(writeFile, "%f\n%d\n%d\n%s\n%s\n", p.price, p.sku,			// prints p's data to file
		p.quantity, p.name, p.description)) {
		fclose(writeFile);
		return false;
	}

	return true;
}

void DeleteProduct(PRODUCT p) {																
	// this wont do much right now (or ever)
}