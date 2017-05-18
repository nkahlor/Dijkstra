#include "util.h"

template<typename T>
T* buildArray(int arraySize)
{
	T* array;
	if((array = (T*) malloc(sizeof(T) * arraySize)) == NULL)
		std::cout << "Array sizing error\n";
	return array;
}

NODE_HEAD* readGraphFromFile(FILE* inputFile)
{
	// eventual return value...
	NODE_HEAD* fileGraph;

	// necessary local variables
	int vertices; // total vertices in the graph
	int numOfEdges; // number of edges in the graph
	int u, v; // node id's
	int weight; // weight of a particular edge
	bool firstLine = true;

	// file reading loop
	while(!feof(inputFile)) // while we aren't at the end of the file...
	{
		if(firstLine) // on the first line, obtain the size of the graph via num of vertices
		{
			fscanf(inputFile, "%d%d", &vertices, &numOfEdges); // fscanf ftw

			fileGraph = initializeGraph(vertices, numOfEdges); 		// initialize the graph
			firstLine = false; // first line is done, move to adding nodes
		}
		else // for every line besides the first, gather info for that vertex
		{
			fscanf(inputFile, "%d%d%d", &u, &v, &weight);
			addEdge(fileGraph, u, v, weight); // add the edge to the graph!
			// reset the values
			u = 0;
			v = 0;
			weight = 0;
		}
	}
	return fileGraph; // return the graph created
}
