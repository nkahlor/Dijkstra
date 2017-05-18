#include "main.h"

int main()
{
	running = true;
	while(running)
	{
		printMenu(); // print the menu with switch-case options
		std::cin >> choice;
		branch(choice);
	}
	// Memory Management
	free(mainGraph);
	return 0;
}

void printMenu()
{
	std::cout << "S:\tStop the program\nR:\tRead graph from GRAPHinput.txt\n";
	std::cout << "W:\tWrite graph information\nP s t:\tCompute shortest path from s to t\n";
	std::cout << "Q s t:\tShortest path with heap information\n";
}

void branch(char input)
{
	switch(input)
	{
	case 'S': // ends the program
		running = false;
		break;
	case 'R': // reads in a graph from GRAPHinput.txt
		FILE* inFile; // file containing graph info
		inFile = fopen("GRAPHinput.txt", "r"); // open the file for reading

		if(inFile == NULL)
			std::cout << "File not found\n";
		else
			mainGraph = readGraphFromFile(inFile); // populate the graph from the file

		fclose(inFile);
		break;
	case 'W':
		printGraph(mainGraph);
		break;
	case 'P':
	case 'Q':
		int s, t;
		bool q;

		if(input == 'Q')
			q = true;
		else
			q = false;

		std::cin >> s;
		std::cin >> t;
		// check to make sure indices are within the graph bounds
		if((s <= 0 || t <= 0) || (s > mainGraph->numOfVertices || t > mainGraph->numOfVertices))
			std::cout << "src/dst index out of bounds\n";
		else
		{
			shortestPath = dijkstra(mainGraph, s, t, q);
			for(int i = shortestPath.size() - 1; i >= 0; i--)
				std::cout << shortestPath.at(i) << "->";

			std::cout << t;
			std::cout << std::endl;
		}


		break;
	default:
		std::cout << "Please enter a valid command\n";
		break;
	}
}
