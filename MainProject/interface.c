#include "Interface.h"	
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// group members: Matthew Romano, Evan Travis, Liv Greenwood

// welcome menu for the program


void printWelcome() {

	// this is what Evan does instead of error checking
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
}

// seperate function so canadian flag dont print everytime
int printMenu() {
	printf("|-----------------------------------------------------|\n"RESET);
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