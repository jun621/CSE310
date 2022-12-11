#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct Vertex {
	int vertex;
	double distValue;
} Vertex;

typedef Vertex *pVertex;
//pVertex *V;

struct MinHeap {
	int nodesCount;
	int maxCount;
	struct Vertex **array;
	int *arrayIndex;
};



int getParentIndex(int arg);

int getLeftIndex(int arg);

int getRightIndex(int arg);

void swapVerticesInMinHeap(struct MinHeap* minHeap, int pos1, int pos2);

void decreaseMinHeapKey(int nodeId, double updatedDistance, struct MinHeap* h);

pVertex extractMinNodeFromHeap(struct MinHeap* h);

void minHeapifyDownwards(struct MinHeap* minHeap, int index);

pVertex createHeapNode(int nodeIndex, double distanceArg);

struct MinHeap* createMinHeap(int capacity);

#endif
