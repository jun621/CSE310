
#include <stdio.h>
#include <iostream>
#include "heap.h"

using namespace std;


////////////////////////////////////////////////

// Max Heap Constructors 

////////////////////////////////////////////////
element MaxHeap::extractMax(HEAP* harr)
{
	element max = *harr->A[0];

	harr->A[0] = harr->A[harr->size - 1];
	harr->A[0]->maxHeap = 0;
	harr->size--;
	maxHeapify(harr, 0);
	return max;
}
void MaxHeap::maxHeapify(HEAP* harr, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;


	if (left < harr->size && harr->A[left]->key > harr->A[i]->key)
	{
		largest = left;
	}
	else
	{
		largest = i;
	}

	if (right < harr->size && harr->A[right]->key > harr->A[largest]->key)
	{
		largest = right;
	}
	if (largest != i)
	{
		harr->A[i]->maxHeap = largest;
		harr->A[largest]->maxHeap = i;
		swap(harr->A[i], harr->A[largest]);

		maxHeapify(harr, largest);
	}
}
void MaxHeap::buildHeap(HEAP* harr)
{
	int n = (harr->size - 2) / 2;
	for (int i = n; i >= 0; i--)
	{
		maxHeapify(harr, i);
	}
}
void MaxHeap::IncreaseKey(HEAP* harr, int pos, int newkey)
{
	harr->A[pos]->key = newkey;
	int parent = (pos - 1) / 2;
	while (pos > 0 && harr->A[parent]->key < harr->A[pos]->key)
	{
		harr->A[pos]->maxHeap = parent;
		harr->A[parent]->maxHeap = pos;
		swap(harr->A[pos], harr->A[parent]);

		pos = parent;
		parent = (pos - 1) / 2;
	}
}
void MaxHeap::Insertion(HEAP* harr, int newkey)
{
	harr->size++;
	int i = harr->size - 1;
	ELEMENT *e = new ELEMENT();

	e->maxHeap = i;
	harr->A[i] = e;
	IncreaseKey(harr, i, newkey);
}
void MaxHeap::Delete(HEAP* harr, int pos)
{
	if (pos < harr->size && pos >= 0)
	{

		harr->A[pos] = harr->A[harr->size - 1];
		harr->A[pos]->maxHeap = pos;
		harr->size--;
		int parent = (pos - 1) / 2;

		if (pos > 0 && pos< harr->size && harr->A[pos]->key > harr->A[parent]->key)
		{
			while (pos > 0 && harr->A[pos]->key > harr->A[parent]->key)
			{
				harr->A[pos]->maxHeap = parent;
				harr->A[parent]->maxHeap = pos;
				swap(harr->A[pos], harr->A[parent]);

				pos = parent;
				parent = (pos - 1) / 2;
			}
		}
		else
		{
			maxHeapify(harr, pos);
		}
	}
}
void MaxHeap::DecreaseKey(HEAP* harr, int pos, int newKey)
{
	if (pos<harr->size && harr->A[pos]->key>newKey)
	{
		harr->A[pos]->key = newKey;
		maxHeapify(harr, pos);
	}
}

//////////////////////////////////////////////////////


//      Min Heap Constructors


/////////////////////////////////////////////////////

element MinHeap::extractMin(HEAP* Harr)
{
	element min = *Harr->a[0];
	Harr->a[0] = Harr->a[Harr->size - 1];
	Harr->a[0]->minHeap = 0;
	Harr->size--;
	minHeapify(Harr, 0);
	return min;
}
void MinHeap::minHeapify(HEAP* Harr, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int smallest = i;


	if (left < Harr->size && Harr->a[left]->key < Harr->a[i]->key)
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right < Harr->size && Harr->a[right]->key < Harr->a[smallest]->key)
	{
		smallest = right;
	}
	if (smallest != i)
	{
		Harr->a[i]->minHeap = smallest;
		Harr->a[smallest]->minHeap = i;
		swap(Harr->a[i], Harr->a[smallest]);

		minHeapify(Harr, smallest);
	}
}
void MinHeap::buildHeap(HEAP* Harr)
{
	int b = (Harr->size - 2) / 2;
	for (int i = b; i >= 0; i--)
	{
		minHeapify(Harr, i);
	}
}
void MinHeap::DecreaseKey(HEAP* Harr, int pos, int key)
{
	Harr->a[pos]->key = key;
	int parent = (pos - 1) / 2;
	while (pos > 0 && Harr->a[parent]->key > Harr->a[pos]->key)
	{
		Harr->a[pos]->minHeap = parent;
		Harr->a[parent]->minHeap = pos;
		swap(Harr->a[pos], Harr->a[parent]);

		pos = parent;
		parent = (pos - 1) / 2;
	}
}
void MinHeap::Insertion(HEAP* Harr, int key)
{
	Harr->size++;
	int i = Harr->size - 1;
	ELEMENT *e = new ELEMENT();

	e->minHeap = i;
	Harr->a[i] = e;
	DecreaseKey(Harr, i, key);
}
void MinHeap::Delete(HEAP* Harr, int pos)
{
	if (pos < Harr->size and pos >= 0)
	{

		Harr->a[pos] = Harr->a[Harr->size - 1];
		Harr->a[pos]->minHeap = pos;
		Harr->size--;

		if (pos > 0 && pos < Harr->size && Harr->a[pos]->key < Harr->a[(pos - 1) / 2]->key)
		{
			while (pos > 0 && Harr->a[pos]->key < Harr->a[(pos - 1) / 2]->key)
			{
				Harr->a[pos]->minHeap = (pos - 1) / 2;
				Harr->a[(pos - 1) / 2]->minHeap = pos;
				swap(Harr->a[pos], Harr->a[(pos - 1) / 2]);

				pos = (pos - 1) / 2;
			}
		}
		else
		{
			minHeapify(Harr, pos);
		}
	}
}
void MinHeap::IncreaseKey(HEAP* Harr, int pos, int newKey)
{
	if (pos < Harr->size  && Harr->a[pos]->key < newKey)
	{
		Harr->a[pos]->key = newKey;
		minHeapify(Harr, pos);
	}
}














