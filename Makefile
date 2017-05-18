#!/bin/bash
#file name: Makefile
CC = g++
CFLAGS = -Wall -std=c++11
DEPS = heap.cpp main.cpp graph.cpp util.cpp 
OBJ = heap.o main.o graph.o util.o 

#compile stage
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

#link stage -- prog = name of executable. You can change this.
run.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#target for cleaning -- remove object and executable files
clean:
	rm *.o
	rm run.exe

