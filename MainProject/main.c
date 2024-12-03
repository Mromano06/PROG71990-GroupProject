#define _CRT_SECURE_NO_WARNINGS

#include "Interface.h"			// this capitol makes me so mad :( - Matt
#include "product.h"
#include "productList.h"
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// group members: Matthew Romano, Evan Travis, Liv Greenwood

// Main implementation for group project

int main(void) {
	PLISTNODE productList = NULL;
	FILE* originalFile;														// made temp files to create them
	FILE* newFile;
	const char* originalFileName = "ProductInfo.txt";						// saved the file names as const chars
	const char* newFileName = "ProductInfoUpdated.txt";
	bool continueProgram = true;

	newFile = fopen(newFileName, "w");										// creates and adds new files
	if (newFile == NULL) {													// (also error checks)
		fprintf(stderr, "system was unable to create file\n");
		exit(EXIT_FAILURE);
	}
	// creates new file to print to (if needed)
	originalFile = fopen(originalFileName, "r");
	if (originalFile == NULL) {
		originalFile = fopen(originalFileName, "w");
	}

	fclose(originalFile);
	fclose(newFile);

	CreateListFromStream(productList, originalFileName);

	printWelcome();
	while (continueProgram) {

		float price = 0.0;
		int sku = 0;
		int quantity = 0;
		char name[NAME_LENGTH] = { '\0'};
		char description[DESCRIPTION_LENGTH] = { '\0'};
		int inputNum = printMenu();

		switch (inputNum) {				// checks for what you want to change

		case 5: { // Add new product

			printf("Enter your products information (sku name quantity price description): ");
			scanf("%d, %[^,], %d, %f, %[^\n]", &sku, name, &quantity, &price, description);
			// %[^,] and %[^\n] mean everything is read there till that symbol is found

			PRODUCT product = CreateProduct(price, sku, quantity, name, description);

			printf("Product created: \n");
			printf("SKU: %d  Name: %s  Quantity: %d  Price: %.2f  Description: %s\n\n",
				product.sku, product.name, product.quantity, product.price, product.description);

			break;
		}
		case 4: { // Update product //TODO find what product to edit
			UpdateProduct(productList);
			break;
		}
		case 3: { // Search products (includes display 1 and display range)
			SearchProductMenu(productList);
			break;
		}
		case 2: { // Delete product
			break;
		}
		case 1: { // Display all products
			DisplayAll(productList);
			break;
		}
		case 0: { // Exit
			continueProgram = false;
			break;
		}
		default: {
			printf("\nInvalid Input");
			continueProgram = false;
		}

			   return true;
		}
	}

	PrintListToStream(productList, newFileName);
}