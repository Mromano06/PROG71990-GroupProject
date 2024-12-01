#pragma once

// group4 - 71990f24 - group project

// product list header file

typedef struct productListNode {
	PRODUCT data;
	struct productListnode* next;
} LISTNODE, * PLISTNODE;

void Add(PLISTNODE* list, PRODUCT i);

void Remove(PLISTNODE* list, PRODUCT i);

void Display(PLISTNODE list);

void DestroyList(PLISTNODE* list);

void PrintListToStream(PLISTNODE list, const char* fileName);

void CreateListFromStream(PLISTNODE list, const char* fileName);