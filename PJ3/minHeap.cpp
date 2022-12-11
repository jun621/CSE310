#include "minHeap.h"

#include <stdlib.h>


// get parent index in heap array
int getParentIndex(int arg) {
	return (arg - 1) / 2;
}

// get left child index in heap array
int getLeftIndex(int arg) {
	return (2 * arg) + 1;
}


// get right child index in heap array.
int getRightIndex(int arg) {
	return (2 * arg) + 2;
}


// swap elements are positions pos1 and pos2 in heap.
void swapVerticesInMinHeap(struct MinHeap* minHeap, int pos1, int pos2) {
	Vertex *firstVertex = minHeap->array[pos1];
	Vertex *secondVertex = minHeap->array[pos2];
	minHeap->arrayIndex[firstVertex->vertex] = pos2;
	minHeap->arrayIndex[secondVertex->vertex] = pos1;

	struct Vertex* tempVertex = minHeap->array[pos1];
	minHeap->array[pos1] = minHeap->array[pos2];
	minHeap->array[pos2] = tempVertex;
}


// decrease value in index nodeId of heap array to updatedDistance.
void decreaseMinHeapKey(int nodeId, double updatedDistance, struct MinHeap* h) {
	int index = h->arrayIndex[nodeId];
	h->array[index]->distValue = updatedDistance;
	if (index <= 0)
		return;
	while (h->array[getParentIndex(index)]->distValue > h->array[index]->distValue) {
		swapVerticesInMinHeap(h, index, getParentIndex(index));
		index = getParentIndex(index);
		if (index <= 0)
			break;
	}
}


// extract and remove node with minimum value from the heap.
pVertex extractMinNodeFromHeap(struct MinHeap* h) {
	if (h->nodesCount == 0) {
		return NULL;
	} else {
		pVertex moveNode = h->array[h->nodesCount - 1];
		pVertex result = h->array[0];

		h->array[0] = h->array[h->nodesCount - 1];

		h->arrayIndex[moveNode->vertex] = 0;

		h->nodesCount = h->nodesCount - 1;
		minHeapifyDownwards(h, 0);

		return result;
	}
}


// run downward min heapify.
void minHeapifyDownwards(struct MinHeap* minHeap, int index) {
	int minIndex = index;

	if (getLeftIndex(index) < minHeap->nodesCount
			&& minHeap->array[getLeftIndex(index)]->distValue
					< minHeap->array[minIndex]->distValue)
		minIndex = getLeftIndex(index);

	if (getRightIndex(index) < minHeap->nodesCount
			&& minHeap->array[getRightIndex(index)]->distValue
					< minHeap->array[minIndex]->distValue)
		minIndex = getRightIndex(index);

	if (minIndex != index) {
		swapVerticesInMinHeap(minHeap, minIndex, index);
		minHeapifyDownwards(minHeap, minIndex);
	}
}

// create a new heap node
pVertex createHeapNode(int nodeIndex, double distanceArg) {
	pVertex minHeapNode = (pVertex) malloc(sizeof(struct Vertex));
	minHeapNode->distValue = distanceArg;
	minHeapNode->vertex = nodeIndex;
	return minHeapNode;
}

// create a min heap.
struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->array = (struct Vertex**) malloc(
				capacity * sizeof(struct Vertex*));
	minHeap->nodesCount = 0;
	minHeap->maxCount = capacity;
	minHeap->arrayIndex = (int *) malloc(capacity * sizeof(int));
	return minHeap;
}



