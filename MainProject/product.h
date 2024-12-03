#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// group4 - prog71990f24 - group project

// header file for product struct

#define DESCRIPTION_LENGTH						100
#define NAME_LENGTH								25

// sku, name, description, quantity, price
typedef struct product {
	float price;
	int sku;
	int quantity;
	char name[NAME_LENGTH];
	char description[DESCRIPTION_LENGTH];
} PRODUCT;

PRODUCT CreateProduct(float price, int sku, int quantity, char name[], char desc[]);

PRODUCT CopyProduct(PRODUCT p);

bool UpdateProduct(PRODUCT* p);

void PrintProduct(PRODUCT p); 

bool ReadProductFromFile(const char* fileName, PRODUCT p, FILE* readFile);

bool WriteProductToFile(const char* fileName, PRODUCT p, FILE* writeFile);

bool CompareProduct(PRODUCT lhs, PRODUCT rhs);

void DeleteProduct(PRODUCT p);