#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

struct MY_ELEMENT{
	unsigned int key; // represents distance
	int vertex;
}typedef MY_ELEMENT;

struct HEAP{
	int size;
	int capacity;
	MY_ELEMENT* data;
}typedef HEAP;

// Functions
HEAP initialize(int n);

int parent(int i);
int left(int i);
int right(int i);

void min_heapify(HEAP &myHeap, int i);
void printHeap(HEAP &myHeap);
void buildHeap(HEAP &myHeap, MY_ELEMENT* array);
MY_ELEMENT extract_min(HEAP &myHeap);
void decrease_key(HEAP &myHeap, int key, int i);
void min_insert(HEAP &myHeap, int element);
bool isEmpty(HEAP &myHeap);
void testHeap(HEAP &myHeap);

#endif
