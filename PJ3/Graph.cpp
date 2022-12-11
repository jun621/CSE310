#include "Graph.h"

#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <sstream>
#include <float.h>
#include "Util.h"


// read graph from a file
Graph* readFile(int ADT, const char * filePath, bool isUndirected) {
	string line;
	ifstream fileStream(filePath);

	if (fileStream.fail()) {
		cout << "Graph Input file does not exist: " << filePath << endl;
		return NULL;
	}

	getline(fileStream, line);
	vector<string> sp = splitString(line);
	string s1 = sp.at(0);
	int n = stoi(sp.at(0));
	int m = stoi(sp.at(1));
	struct Graph* g = createGraph(n);

	for (int i = 0; i < m; i++) {
		getline(fileStream, line);
		sp = splitString(line);
		//int a = stoi(sp.at(0));
		int b = stoi(sp.at(1));
		int c = stoi(sp.at(2));
		double weight = stod(sp.at(3));
		addGraphEdge( b - 1, c - 1, weight, isUndirected, g);
	}

	fileStream.close();
	return g;
}

// split a string and return vector/list.
vector<string> splitString(string arg) {
	stringstream test(arg);
	string part;
	vector<string> ret;

	while (std::getline(test, part, ' ')) {
		if (part.length() > 0) {
			ret.push_back(part);
		}
	}
	return ret;
}

// create a new node.
struct Node* createNewNode(int destIndex, double edgeWeight) {
	struct Node* newNodeVar = (struct Node*) malloc(sizeof(struct Node));
	newNodeVar->v = destIndex;
	newNodeVar->w = edgeWeight;
	newNodeVar->next = NULL;

	return newNodeVar;
}

// create a new graph with given nodesCount
struct Graph* createGraph(int nodesCount) {
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->nodesCount = nodesCount;

	graph->adjacencyList = (struct adjlist*) malloc(nodesCount * sizeof(struct adjlist));
	graph->prev = (int*) malloc(nodesCount * sizeof(int));
	graph->dist = (double*) malloc(nodesCount * sizeof(double));

	for (int i = 0; i < nodesCount; ++i) {
		graph->adjacencyList[i].head = NULL;
		graph->prev[i] = -1;
		graph->dist[i] = DBL_MAX;
	}

	return graph;
}

// adds an edge to graph with input sourceId, destinationId and weight.
void addGraphEdge(int sourceInd, int destinationInd, double weight,
		bool isUndirected, struct Graph* graph) {
	struct Node* nd = createNewNode(destinationInd, weight);
	nd->next = graph->adjacencyList[sourceInd].head;
	graph->adjacencyList[sourceInd].head = nd;

	if (isUndirected) {
		nd = createNewNode(sourceInd, weight);
		nd->next = graph->adjacencyList[destinationInd].head;
		graph->adjacencyList[destinationInd].head = nd;
	}
}

// run Dijkstra's algorithm
void runDijkstrasAlgo(struct Graph* g, int index) {
	struct MinHeap* hp = createMinHeap(g->nodesCount);

	for (int i = 0; i < g->nodesCount; i++) {
		g->dist[i] = DBL_MAX;
		hp->arrayIndex[i] = i;
		hp->array[i] = createHeapNode(i, g->dist[i]);
	}
	hp->nodesCount = g->nodesCount;

	// mark distance of source node as zero
	g->dist[index] = 0;
	decreaseMinHeapKey(index, g->dist[index], hp);

	// run until all the nodes in heap are visited
	while (hp->nodesCount != 0) {
		// find node with minimum distance
		struct Vertex* currentNode = extractMinNodeFromHeap(hp);

		int currentIndex = currentNode->vertex;

		// udpate distance of nighbouring nodes
		struct Node* adjNode = g->adjacencyList[currentIndex].head;
		while (adjNode != NULL) {
			int adjDest = adjNode->v;

			if ((g->dist[currentIndex] < DBL_MAX)
					&& (hp->arrayIndex[adjDest] < hp->nodesCount)
					&& ((g->dist[currentIndex] + adjNode->w) < g->dist[adjDest])) {
				g->dist[adjDest] = g->dist[currentIndex] + adjNode->w;
				g->prev[adjDest] = currentIndex;

				decreaseMinHeapKey(adjDest, g->dist[adjDest], hp);
			}

			adjNode = adjNode->next;
		}
	}

}

