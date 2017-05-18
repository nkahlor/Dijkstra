#ifndef UTIL_H
#define UTIL_H
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "graph.h"

typedef struct node_head NODE_HEAD;

template<typename T>
T* buildArray(int arraySize);

NODE_HEAD* readGraphFromFile(FILE* inputFile);

#endif
