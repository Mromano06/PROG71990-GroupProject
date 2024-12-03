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
	strncpy(newProduct.description, Desc, DESCRIPTION_LENGTH - 1);

	return newProduct;
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

void DeleteProduct(PRODUCT* p) {
	// nothing here
}