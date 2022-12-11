EXEC = PJ3
CC = g++
CFLAGS = -c -Wall
$(EXEC) :main.o Stack.o Util.o minHeap.o Graph.o
	g++ -o $(EXEC) main.o Stack.o Util.o minHeap.o Graph.o
main.o :main.cpp Graph.h Stack.h minHeap.h Util.h
	$(CC) $(CFLAGS) main.cpp
Stack.o :Stack.cpp Stack.h
	$(CC) $(CFLAGS) Stack.cpp
Util.o :Util.h Util.cpp
	$(CC) $(CFLAGS) Util.cpp
minHeap.o :minHeap.h minHeap.cpp
	$(CC) $(CFLAGS) minHeap.cpp
Graph.o :Graph.h Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

