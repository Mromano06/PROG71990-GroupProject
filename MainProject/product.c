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
	printf("SKU: %d, NAME: %s, QUANTITY: %d, PRICE: %.2f, DESCRIPTION: %s\n", // print the data of located product
		p.sku, p.name, p.quantity, p.price, p.description);
    }

// reads a product from the file 
// (info held in the file will most likely be held in a list,
// formatting an dprinting will ony be used in the interface/UI)

//TODO figure out why im getting exception here
FILE* openfiletoread(FILE* pfile, char* filename)
{	// creates new file to print to (if needed)

	pfile = fopen(filename, "r");
	if (pfile == NULL) {
		filename = fopen(filename, "w");
		return;
	}
	return pfile;
}

FILE* openfiletowrite(FILE* pfile, char* filename)
{
	pfile = fopen(filename, "w");
	if (pfile == NULL)
	{
		return NULL;
	}
	return pfile;
}

bool closefile(FILE* pfile)
{
	close(pfile);
}

bool ReadProductFromFile(const char* fileName, PRODUCT* currents) {
	PRODUCT temp = {'\0'};
	FILE* pfile = NULL;
	char buff[NAME_LENGTH] = { '\0' };
	pfile = openfiletoread(pfile, fileName);
	char nameofproduct[NAME_LENGTH];
	fgets(buff, NAME_LENGTH, pfile);
	currents->price = atof(buff);
	fgets(buff, NAME_LENGTH, pfile);
	currents->sku = atoi(buff);
	fgets(buff, NAME_LENGTH, pfile);
	currents->quantity = atoi(buff);
	fgets(currents->name, NAME_LENGTH, pfile);
	fgets(currents->description, NAME_LENGTH, pfile);
	currents->name[strcspn(currents->name, "\n")] = 0;
	currents->description[strcspn(currents->description, "\n")] = 0;
	fclose(pfile);
	return true;
}

bool writeproducttofile(const char* filename, PRODUCT* currents)
{
	FILE* pfile = NULL;
	pfile = openfiletowrite(pfile, filename);	
	fprintf(pfile, "%f\n", currents->price);
	fprintf(pfile, "%d\n", currents->sku);
	fprintf(pfile, "%d\n", currents->quantity);
	fprintf(pfile, "%s\n", currents->name);
	fprintf(pfile, "%s\n", currents->description);
	fclose(pfile);
}



//bool WriteProductToFile(const char* fileName, PRODUCT p, FILE* writeFile) {
//	if (!fprintf(writeFile, "%f\n%d\n%d\n%s\n%s\n", p.price, p.sku,			// prints p's data to file
//		p.quantity, p.name, p.description)) {
//		fclose(writeFile);
//		return false;
//	}
//
//	return true;
//}


void DeleteProduct(PRODUCT* p) {
	// livizm is gonna make this work :)
	// i honest to god cannot bother with this

}

bool CompareProduct(PRODUCT lhs, PRODUCT rhs) {
	return (lhs.sku == rhs.sku);
}