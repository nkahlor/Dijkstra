# Dijkstra
Implementation of Dijkstra's algorithm using heap and adjacency list: O(E lgV)

Commands for using the program:
   Compile: make
   Run: ./run

I have adopted a procedural approach rather than an object oriented approach in this implementation.

This program runs on a basic command line interface with few options. It will read a graph from a file which must be named
GRAPHinput.txt and construct an adjacency list of vertices, and edge weights. I have included a sample .txt file to
demonstrate formatting.

After reading in the graph, you may display the contents of the graph, or compute a shortest path between any source and 
destination node.

I created a custom heap implementation with optimal running times in all functions. More functions are included in my heap.cpp
and heap.h files than are used in Dijkstra's implementation; this is because I recycled the files from one of my previous
projects.

The util.cpp and util.h files simply contain a few helper functions to improve organization of the code.

graph.cpp and graph.h will contain only a few possible graph functions, most notably the ones used to build the adjacency list
and dijkstra.
