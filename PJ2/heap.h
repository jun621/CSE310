
#ifndef HEAP_H
#define HEAP_H


#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

typedef struct ELEMENT
{
	int key;
	int maxHeap;
	int minHeap;

}element;

typedef struct HEAP
{
	int capacity;/* capacity of the (max heap)/(min heap)/(double-ended heap ) */
	int size ; /* current size of the heap */
	ELEMENT **A; /* array of pointers to ELEMENT */
	ELEMENT **a;  /* array of pointers to ELEMENT */

}HEAP;

class MaxHeap
{
public:
	element extractMax(HEAP *);
	void maxHeapify(HEAP *, int i);
	void buildHeap(HEAP *);
	void IncreaseKey(HEAP *, int, int);
	void Insertion(HEAP *, int);
	void DecreaseKey(HEAP *, int, int);
	void Delete(HEAP *, int);
};

class MinHeap
{
public:
	element extractMin(HEAP *);
	void minHeapify(HEAP *, int i);
	void buildHeap(HEAP *);
	void DecreaseKey(HEAP *, int, int);
	void Insertion(HEAP *, int);
	void IncreaseKey(HEAP *, int, int);
	void Delete(HEAP *, int);
};

#endif