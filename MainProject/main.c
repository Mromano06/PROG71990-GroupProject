#include "product.h"
#include "productList.h"
#include <stdio.h>
#include <stdlib.h>

// group4 - 71990f24 - group project

// group members: Matthew Romano, Evan Travis, Liv Greenwood

// Main implementation for group project

int main(void) {

	FILE* originalFile;														// made temp files to create them
	FILE* newFile;
	const char* originalFileName = "flightData.txt";						// saved the file names as const chars
	const char* newFileName = "flightDataUpdated.txt";

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


	return 0;
}