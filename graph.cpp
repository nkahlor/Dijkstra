#include "graph.h"

// make head of linked list and attach it to an array index of size v
NODE_HEAD* initializeGraph(int numOfVertices, int numOfEdges)
{
	NODE_HEAD* array = (NODE_HEAD*) malloc(sizeof(NODE_HEAD) * (numOfVertices + 1)); // PLUS ONE BEACUSE OF 1 BASED INDEX
	if(array == NULL)
		std::cout << "Error in initializeGraph\n";
	array->numOfVertices = numOfVertices;
	array->numOfEdges = numOfEdges;

	for(int i = 1; i <= numOfVertices; i++)
	{
		array[i].head = NULL; // initialize each head to null, for empty list
		array[i].index = i; // set the index of the node
	}

	return array;
}

// create an empty node
NODE* buildNewNode(int id, int weight)
{
	NODE* newNode = new NODE;
	newNode->id = id; 		// set the id to the parameter
	newNode->weight = weight; // set the weight from node i to j
	newNode->next = NULL; // initially null pointer
	return newNode;
}

// add an edge to the beginning of a directed graph
void addEdge(NODE_HEAD* array, int i, int j, int weight)
{
	// makes sure both indices are within the bounds of the graph
	if((i <= array->numOfVertices && j <= array->numOfVertices) && (i > 0 && j > 0))
	{
		NODE* newNode = buildNewNode(j, weight); // create a node for j
		newNode->next = array[i].head; // link to the next element in the list
		array[i].head = newNode; // attach the new node to the head of i
	}
}

void printGraph(NODE_HEAD* graph)
{
	std::cout << "Vertices: " << graph->numOfVertices <<" Edges: " <<  graph->numOfEdges << "\n";
	for(int i = 1; i <= graph->numOfVertices; i ++)
	{
		std::cout << graph[i].index << ": ";
		if(graph[i].head != NULL)
		{
			NODE* iterator = graph[i].head; // the iterator is the head of the graph at index i
			while(iterator)
			{
				std::cout << "(" << iterator->id << ", " << iterator->weight << ")";
				iterator = iterator->next;
			}
			std::cout << std::endl;
		}
	}
	std::cout << "\n\n";
}

HEAP initializeSingleSource(NODE_HEAD* graph, int src)
{
	int V = graph->numOfVertices;	// vertices in the graph (+1 for 1 indexed offset)
	HEAP priorityQ = initialize(V); // initialize my heap
	MY_ELEMENT* distances = (MY_ELEMENT*) malloc((V+1) * sizeof(MY_ELEMENT));

	for(int i = 1; i <= V; i++) // initialize all distances to "infinity", and vertex id's
	{
		distances[i].key = INT_MAX;
		distances[i].vertex = i;
	}
	distances[src].key = 0; // the distance at the source is 0 units from itself
	buildHeap(priorityQ, distances); // build a heap of the distances

	// Memory Management
	free(distances);

	return priorityQ;
}

std::vector<int> dijkstra(NODE_HEAD* graph, int src, int dst, bool q)
{
	int V = graph->numOfVertices; // number of vertices
	std::vector<int> solution;
	int* path = (int*)malloc(sizeof(int) * (V+1));
	for(int i = 1; i <= V; i ++)
		path[i] = -1; // initialize to -1

	MY_ELEMENT* array = (MY_ELEMENT*)malloc((V+1) * sizeof(MY_ELEMENT));
	MY_ELEMENT u, v; // elements used to judge node distances
	HEAP distanceQ = initializeSingleSource(graph, src); // a priority Q represented as a min heap containing distances

	// initialize the array to match the heap
	for(int i = 1; i <= V; i++)
	{
		array[i].key = INT_MAX;
		array[i].vertex = i;
	}
	array[src].key = 0;

	NODE* iterator = NULL;
	// while there are elements left in the heap
	while(!isEmpty(distanceQ))
	{
		u = extract_min(distanceQ); // take the element with lowest distance (initially source node)
		if((u.vertex == dst) && q) // extra credit portion
			printHeap(distanceQ);

		// establish an iterator for my adjacency list
		iterator = graph[u.vertex].head;
		// access each neighbor of u and perform relaxation
		while(iterator != NULL)
		{
			// v is a type of MY_ELEMENT
			// to access the proper element, we need the vertex ID from the adjacency list
			// then we need to access the proper element from the array
			v = array[iterator->id];
			if(v.key > u.key + iterator->weight)
			{
				decrease_key(distanceQ, v.vertex, u.key + iterator->weight); // update the heap
				array[v.vertex].key = u.key + iterator->weight; // update the parallel array
				path[v.vertex] = u.vertex; // point v to u
			}
			iterator = iterator->next;
		}
	}

	int index = dst;
	if(array[dst].key == INT_MAX)
		std::cout << "No such path\n";
	else
		std::cout << "Distance: " << array[dst].key << std::endl;

	while(path[index] != -1)
	{
		solution.push_back(path[index]);
		index = path[index];
	}

	// Memory Management
	free(distanceQ.data);
	free(array);
	free(path);

	return solution;
}
