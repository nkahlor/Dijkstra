#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include "graph.h"
#include "heap.h"
#include "util.h"

// variables
char choice;
bool running;
NODE_HEAD* mainGraph; // adjacency list for main function
std::ifstream instream;
NODE* iterator;
NODE* pathIterator;
std::vector<int> shortestPath;
// functions
void printMenu();
void branch(char input);
void readGraph();

#endif
