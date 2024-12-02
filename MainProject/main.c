#include <stdio.h>

#include "Interface.h"
#include "product.h"
#include "productList.h"

// group4 - 71990f24 - group project

// group members: Matthew Romano, Evan Travis, Liv Greenwood

// Main implementation for group project

int main(void) {

	/*
	add a new product X											 [X] [ ]
	delete an existing product X (deletion ain't really a thing) [ ] [ ]
	update an existing product  X								 [X] [ ]
	display single product										 [X] [ ]
	display range product										 [X] [ ]
	display all product											 [X] [ ]
	search for product											 [X] [X]
	Exit														 [ ] [ ]
	*/

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		float price = 0.0;
		int sku = 0;
		int quantity = 0;
		char name[NAME_LENGTH] = { 0 };
		char description[DESCRIPTION_LENGTH] = { 0 };

		PLISTNODE p = NULL;

		int inputNum = printMenu();

		switch (inputNum) {				// checks for what you want to change

		case 5: { // Add new product

			printf("Enter your products information (sku, name, quantity, price): ");
			scanf_s("%d, %s, %d, %f", &sku, name, &quantity, &price);

			printf("Enter the description of this product (Max 100 char): ");
			scanf_s("%99s", description); // use 99c to only accept 99/100 char from user

			CreateProduct(price, sku, quantity, name, description);

			break;
		}
		case 4: { // Update product
			UpdateProduct(p);
			break;
		}
		case 3: { // Search products (includes display 1 and display range)
			SearchProductMenu(p);
			break;
		}
		case 2: { // Delete product

			break;
		}
		case 1: { // Display all products
			DisplayAll(p);  
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
}

void printWelcome() {

	printf("\n"); // CANADA, HECK YEAH
	printf(RED "               [------"RESET"---------"RED"------]\n"RESET);
	printf(RED "               [||||||"RESET"  _/ \\_  "RED"||||||]\n"RESET);
	printf(RED "               [||||||"RESET"__\\   /__"RED"||||||]\n"RESET);
	printf(RED "               [||||||"RESET"\\___ ___/"RED"||||||]\n"RESET);
	printf(RED "               [||||||"RESET"    |    "RED"||||||]\n"RESET);
	printf(RED "               [------"RESET"---------"RED"------]\n"RESET);
	 
	printf("\n");
	printf("              [-----------------------]\n");
	printf("              [       Welcome to      ]\n");
	printf("              [     "CYAN"InvaManager.ca"RESET"    ]\n");
	printf("|-----------------------------------------------------|\n"RESET);
}

int printMenu() {
	printf("| 5. Add new product       4. Update existing product |\n");
	printf("| 3. Search products       2. Delete existing product |\n");
	printf("| 1. Display all products  0. Exit program            |\n");
	printf("|-----------------------------------------------------|\n");

	int menuChoice = 0;

	printf("Enter option: "); // fixed shapeChoice input so that it can function with numbers > 7
	if (scanf_s("%d", &menuChoice) != 1) {
		printf("Invaild option");
		return 0;
	}
	return menuChoice;
}