#include "heap.h"

HEAP initialize(int n)
{
	HEAP myHeap;
	myHeap.capacity = n;
	myHeap.size = 0;
	myHeap.data = (MY_ELEMENT*)malloc((n+1) * sizeof(MY_ELEMENT));

	if(myHeap.data == NULL)
		std::cout << "Error: could not allocate that much memory\n";

	return myHeap;
}

int parent(int i)
{
	return floor(i / 2);
}
int left(int i)
{
	return (i * 2);
}
int right(int i)
{
	return ((i * 2) + 1);
}

void min_heapify(HEAP &myHeap, int i)
{
	int leftNode = left(i);
	int rightNode = right(i);
	int smallest;

	// compares the keys to determine smallest
	if(leftNode <= myHeap.size && myHeap.data[leftNode].key < myHeap.data[i].key)
		smallest = leftNode;
	else
		smallest = i;

	if(rightNode <= myHeap.size && myHeap.data[rightNode].key < myHeap.data[smallest].key)
		smallest = rightNode;

	if(smallest != i)
	{
		// swap the smallest with i
		std::swap(myHeap.data[smallest], myHeap.data[i]);
		// Recursive call to heapify
		min_heapify(myHeap, smallest);
	}
}

void buildHeap(HEAP &myHeap, MY_ELEMENT* array)
{
	int arrayLength = myHeap.capacity; // length of the array
	myHeap.size = arrayLength;

	// copy contents of element array into my heap
	for(int i = 1; i <= arrayLength; i++)
		myHeap.data[i] = array[i];

	// Build the heap from the array by calling min_heapify

	for(int i = floor(arrayLength / 2); i >= 1; i--)
		min_heapify(myHeap, i);
}

void printHeap(HEAP &myHeap)
{
	// Print out the contents of the heap
	for(int i = 1; i <= myHeap.size; i ++)
	{
		std::cout << myHeap.data[i].vertex << " ";
	}
	std::cout << std::endl;
}

// return -1 if the heap is empty
MY_ELEMENT extract_min(HEAP &myHeap)
{
	MY_ELEMENT min;
	min = myHeap.data[1]; // The minimum is the first element of the heap
	myHeap.data[1] = myHeap.data[myHeap.size];
	myHeap.size--; // decrease the size of the heap by 1
	min_heapify(myHeap, 1); // repair the heap
	return min;
}

void decrease_key(HEAP &myHeap, int element, int key)
{
	myHeap.data[element].key = key; // make the key at the index the key passed in
	myHeap.data[element].vertex = element;

	while(element > 1 && (myHeap.data[parent(element)].key > myHeap.data[element].key || myHeap.data[parent(element)].vertex > myHeap.data[element].vertex)) // fix the order of the heap
	{
		std::swap(myHeap.data[parent(element)], myHeap.data[element]);
		element = parent(element);
	}
}

void min_insert(HEAP &myHeap, int key)
{
	if(myHeap.size < myHeap.capacity)
	{
		myHeap.size++; // increase the size of the heap
		myHeap.data[myHeap.size].key = (int)NULL; // set it to null initially
		decrease_key(myHeap, myHeap.size, key);
	}
	else
		std::cout << "Error: heap at capacity\n";
}

bool isEmpty(HEAP &myHeap)
{
	bool empty;
	if(myHeap.size == 0)
		empty = true;
	else
		empty = false;
	return empty;
}

void testHeap(HEAP &myHeap)
{
	for(int i = floor(myHeap.capacity / 2); i >= 1; i--)
	{
		if(myHeap.data[left(i)].key != 1 && myHeap.data[right(i)].key != 1)
		{
			if(myHeap.data[left(i)].key < myHeap.data[i].key || myHeap.data[left(i)].key < myHeap.data[i].key)
			{
				std::cout <<"left: " << left(i) <<"right: " << right(i) << "\nNot a min Heap" << std::endl;
				break;
			}
			else
			{
				if(i == 1)
					std::cout << "\nCongrats! It's a min heap!" << std::endl;
			}
		}
	}
}
