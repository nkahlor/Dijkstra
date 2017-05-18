// Code which represents a weighted, directed graph
// This graph is based off a 1 index
#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include "util.h"
#include "heap.h"
// Structs
// a linked list of nodes
struct graph_nodes{
	int id; // numerical id of connected node
	int weight; // weight from previous node
	struct graph_nodes *next; // the next node in the list
} typedef NODE;

struct node_head{
	NODE* head;
	int index;
	int numOfVertices;
	int numOfEdges;
}typedef NODE_HEAD;

// Functions
NODE_HEAD* initializeGraph(int numOfVertices, int numOfEdges); // returns an adjacency array of null pointers
NODE* buildNewNode(int id, int weight); // build a new node with the paramater as the id, ->next is null
void addEdge(NODE_HEAD* array, int i, int j, int weight); // add a vertex to a list, i->j or (i, j)

void printGraph(NODE_HEAD* graph);
HEAP initializeSingleSource(NODE_HEAD* graph, int src); // returns a heap with initial distance "infinity" for all besides src node
void relax(MY_ELEMENT u, MY_ELEMENT v, int weight);
std::vector<int> dijkstra(NODE_HEAD* graph, int src, int dst, bool q);

#endif
