#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

// group4 - 71990f24 - group project

// product linked list interface

typedef struct productListNode {
	PRODUCT data;
	struct productListnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, PRODUCT i);

void Remove(PLISTNODE* list);

void Display(PLISTNODE list);

void DestroyList(PLISTNODE* list);

bool SearchProductMenu(PLISTNODE list); 

bool SearchRangeOfProducts(PLISTNODE list); 

bool SearchSingleProduct(PLISTNODE list); 

void DisplayAll(PLISTNODE list); 

void PrintListToStream(PLISTNODE list, const char* fileName);

void CreateListFromStream(PLISTNODE list, const char* fileName);

int GetListSize(PLISTNODE listHead);

void FindProductToUpdate(PLISTNODE list);

bool writeproductstofile(const char* filename, PLISTNODE* node);

bool readproductsfromfile(const char* filename, PLISTNODE* node);