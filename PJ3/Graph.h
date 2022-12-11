#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

#include "minHeap.h"

//#include "stack.h"

using namespace std;

typedef struct Node {
	//int u;
	int v;
	double w;
	Node *next;
	Node *head;
} Node;
typedef Node *pnode;

typedef struct Graph {
	struct adjlist *adjacencyList;
	int nodesCount;
	int *prev;
	double * dist;
} Graph;

struct adjlist {
	struct Node *head;
};

Graph* readFile(int ADT, const char * filePath, bool isUndirected);
void runDijkstrasAlgo(struct Graph* graph, int src);
vector<string> splitString(string arg);

void addGraphEdge(int src, int dest, double weight,
		bool isUndirected, struct Graph* graph);

struct Graph* createGraph(int V) ;

//typedef Vertex Element;
//typedef Element *pELEMENT;


#endif
