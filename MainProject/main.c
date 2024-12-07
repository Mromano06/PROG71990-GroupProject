#define _CRT_SECURE_NO_WARNINGS

#include "Interface.h"			// this capital makes me so mad :( - Matt
#include "product.h"
#include "productList.h"
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// group members: Matthew Romano, Evan Travis, Liv Greenwood

// Main implementation for group project

int main(void) {
	PRODUCT productmain;
	PRODUCT* product = &productmain;
	// made temp product
	LISTNODE mainlist = { '\0' };
	PLISTNODE productList = NULL;		// made a temp list
	FILE* originalFile;														// made temp files to create them
	FILE* newFile;
	const char* originalFileName = "ProductInfo.txt";						// saved the file names as const chars
	const char* newFileName = "ProductInfoUpdated.txt";
	bool continueProgram = true;

	
	readproductsfromfile(originalFileName, &productList);

	// giving expetion anytime its ran
	//CreateListFromStream(productList, originalFileName);
	//Add(&productList, CreateProduct(1234, 11111, 12, "matt", "mmmmmmmmmm"));
	//Add(&productList, CreateProduct(1214, 13311, 122, "Mnee", "e21sdafw"));
	printWelcome();
	while (continueProgram) {

		float price = 0.0;
		int sku = 0;
		int quantity = 0;
		char name[NAME_LENGTH] = { '\0' };
		char description[DESCRIPTION_LENGTH] = { '\0' };
		int inputNum = printMenu();

		switch (inputNum) {				// checks for what you want to change
			// this makes a product but doesnt save it to a list
		case 5: { // Add new product
			printf("Enter your products information (SKU, NAME, QUANTITY, PRICE, DESCRIPTION): ");
			scanf("%d, %[^,], %d, %f, %[^\n]", &sku, name, &quantity, &price, description);
			// %[^,] and %[^\n] mean everything is read there till that symbol is found\
	
			*product = CreateProduct(price, sku, quantity, name, description);
			Add(&productList, *product);

			printf("Product created: \n");
			printf("SKU: %d  NAME: %s  QUANTITY: %d  PRICE: %.2f  DESCRIPTION: %s\n\n",
					product->sku, product->name, product->quantity, product->price, product->description);

			/*
			Add(&productList, CreateProduct(1234, 1, 12, "matt", "mmmmmmmmmm")); // for testing
			Add(&productList, CreateProduct(1234, 2, 12, "joe", "mmmmmmmmmm")); // for testing
			Add(&productList, CreateProduct(1234, 3, 12, "john", "mmmmmmmmmm")); // for testing
			Add(&productList, CreateProduct(1234, 5, 12, "evan", "mmmmmmmmmm")); // for testing
			*/

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
			Remove(productList); 
			break;
		}
		case 1: { // Display all products
			DisplayAll(productList);
			break;
		}
		case 0: { // Exit
			if (productList->data.name == NULL)
			{
				continueProgram = false;
			}
			else
			{
				writeproductstofile(originalFileName, productList);
				continueProgram = false;
			}
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