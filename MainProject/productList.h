#pragma once
#include "product.h"

// group4 - 71990f24 - group project
// product linked list interface

typedef struct productListNode {
	PRODUCT data;
	struct productListnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, PRODUCT i);

void Remove(PLISTNODE* list, PRODUCT i);

void Display(PLISTNODE list);

void DestroyList(PLISTNODE* list);

bool SearchProductMenu(PLISTNODE list); //     [X]

bool SearchRangeOfProducts(PLISTNODE list); // [X]

bool SearchSingleProduct(PLISTNODE list); //   [X]

void DisplayAll(PLISTNODE list); // [ ]

