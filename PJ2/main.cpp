
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <climits>
#include "util.h"
#include "heap.h"

using namespace std;

void Error()
{
	fprintf(stderr, "Usage: ./PJ2 DataStructure Capacity\n");
	fprintf(stderr, "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}\n");
	fprintf(stderr, "       Capacity must be a positive integer\n");
	exit(1);
}


int main(int argc, char* argv[])
{


	if (argc != 3)
	{
		Error();
	}

	int ADT, capacity;
	capacity = stoi(argv[2]);
	bool heapcreate = false;

	if (strcmp(argv[1], "MaxHeap") == 0)
		ADT = 1;
	else if (strcmp(argv[1], "MinHeap") == 0)
		ADT = 2;
	else if (strcmp(argv[1], "DoubleHeap") == 0)
		ADT = 3;
	else
	{
		Error();
	}

	capacity = stoi(argv[2]);
	if (capacity < 1)
	{
		Error();
	}


	HEAP *heap = new HEAP();
	heap->capacity = capacity;

	MaxHeap *max = new MaxHeap();
	MinHeap *min = new MinHeap();


	if (ADT == 1)
	{

		heap->A = (ELEMENT **)malloc(capacity * (sizeof(ELEMENT*)));
	}
	if (ADT == 2)
	{
		heap->a = (ELEMENT **)malloc(capacity * (sizeof(ELEMENT*)));
	}
	if (ADT == 3)
	{
		heap->A = (ELEMENT **)malloc(capacity * (sizeof(ELEMENT*)));
		heap->a = (ELEMENT **)malloc(capacity * (sizeof(ELEMENT*)));
	}

	char word[50];
	int value;
	int pos;

	while (1)
	{
		scanf("%s", word);



		if (strcmp(word, "Stop") == 0)
		{
			exit(1);
		}

		else if (strcmp(word, "Print") == 0)
		{
			printf("capacity=%d, size=%d\n", heap->capacity, heap->size);
			if (heap->size > 0)
			{
				if (ADT == 1)
				{
					cout << "MaxHeap:";
					for (int i = 0; i < heap->size - 1; i++)
					{
						cout << " " << heap->A[i]->key << ",";


					}
					cout << " " << heap->A[heap->size - 1]->key;


					printf("\n");
				}
				if (ADT == 2)
				{
					cout << "MinHeap:";
					for (int i = 0; i < heap->size - 1; i++)
					{
						cout << " " << heap->a[i]->key << ",";

					}
					cout << " " << heap->a[heap->size - 1]->key;


					printf("\n");
				}
				if (ADT == 3)
				{
					cout << "MaxHeap:";
					for (int i = 0; i < heap->size - 1; i++)
					{
						cout << " " << heap->A[i]->key << ",";

					}
					cout << " " << heap->A[heap->size - 1]->key;


					printf("\n");

					printf("MinHeap:");
					for (int i = 0; i < heap->size - 1; i++)
					{
						cout << " " << heap->a[i]->key << ",";

					}
					cout << " " << heap->a[heap->size - 1]->key;


					printf("\n");
				}
			}
			continue;
		}

		else if (strcmp(word, "Read") == 0)
		{
			ifstream inputFile;
			inputFile.open("HEAPifile.txt");
			if (inputFile.fail())
			{
				fprintf(stderr, "Error: Cannot open file HEAPifile.txt\n");
				continue;
			}
			int n;
			inputFile >> n;
			heap->size = n;
			if (n <= 0 || n > capacity)
			{
				if (ADT == 1)
				{
					fprintf(stderr, "Error: Cannot allocate memory for max heap array\n");
					inputFile.close();

				}
				if (ADT == 2)
				{
					fprintf(stderr, "Error: Cannot allocate memory for min heap array\n");
					inputFile.close();

				}
				if (ADT == 3)
				{
					fprintf(stderr, "Error: Cannot allocate memory for heap\n");
					inputFile.close();

				}


			}
			else
			{
				if (ADT == 1)
				{
					for (int i = 0; i < n; i++)
					{
						ELEMENT *num = new ELEMENT();
						inputFile >> num->key;
						num->maxHeap = i;
						heap->A[i] = num;
					}
					max->buildHeap(heap);

				}
				else if (ADT == 2)
				{
					for (int i = 0; i < n; i++)
					{
						ELEMENT *num = new ELEMENT();
						inputFile >> num->key;
						num->minHeap = i;
						heap->a[i] = num;
					}
					min->buildHeap(heap);
				}
				else if (ADT == 3)
				{
					for (int i = 0; i < n; i++)
					{
						ELEMENT *num = new ELEMENT();
						inputFile >> num->key;
						num->maxHeap = i;
						num->minHeap = i;
						heap->A[i] = num;
						heap->a[i] = num;
					}
					max->buildHeap(heap);
					min->buildHeap(heap);
				}
			}
			inputFile.close();
		}

		else if (strcmp(word, "Write") == 0)
		{
			ofstream writefile("HEAPofile.txt");
			if (writefile.fail())
			{
				fprintf(stderr, "Error: Cannot open file HEAPofile.txt\n");
				continue;
			}
			if (ADT == 1)
			{
				writefile << "capacity=" << heap->capacity << ", size=" << heap->size << endl;
				writefile << "MaxHeap:";
				for (int i = 0; i < heap->size - 1; i++)
				{
					writefile << " " << heap->A[i]->key << ",";
				}
				writefile << " " << heap->A[heap->size - 1]->key;
				writefile << endl;
			}
			if (ADT == 2)
			{
				writefile << "capacity=" << heap->capacity << ", size=" << heap->size << endl;
				writefile << "MinHeap:";
				for (int i = 0; i < heap->size - 1; i++)
				{
					writefile << " " << heap->a[i]->key << ",";
				}
				writefile << " " << heap->a[heap->size - 1]->key;
				writefile << endl;
			}
			if (ADT == 3)
			{
				writefile << "capacity=" << heap->capacity << ", size=" << heap->size << endl;
				writefile << "MaxHeap:";
				for (int i = 0; i < heap->size - 1; i++)
				{
					writefile << " " << heap->A[i]->key << ",";
				}
				writefile << " " << heap->A[heap->size - 1]->key;
				writefile << endl;
				writefile << "MinHeap:";
				for (int i = 0; i < heap->size - 1; i++)
				{
					writefile << " " << heap->a[i]->key << ",";
				}
				writefile << " " << heap->a[heap->size - 1]->key;
				writefile << endl;
			}
			writefile.close();
		}

		else if (strcmp(word, "Insert") == 0)
		{
			scanf("%d", &value);
			if (heap->capacity == heap->size)
			{
				fprintf(stderr, "Error: Insertion to a null/full heap\n");

			}
			else
			{
				ELEMENT *num = new ELEMENT();
				num->key = value;

				if (ADT == 1)
				{
					max->Insertion(heap, value);
				}
				if (ADT == 2)
				{
					min->Insertion(heap, value);
				}
				else if (ADT == 3)
				{
					max->Insertion(heap, value);
					heap->size--;
					min->Insertion(heap, value);
				}
			}
		}

		else if (strcmp(word, "ExtractMax") == 0)
		{
			if (ADT == 2 || heap->size == 0)
			{
				fprintf(stderr, "Error: ExtractMax in a min heap or a null/empty heap\n");

			}
			else if (ADT == 1)
			{
				element Key = max->extractMax(heap);
				fprintf(stdout, "ExtractMax: %d\n", Key);
			}
			else if (ADT == 3)
			{
				element Key = max->extractMax(heap);
				fprintf(stdout, "ExtractMax: %d\n", Key);
				heap->size++;
				pos = Key.minHeap;
				min->Delete(heap, pos);
			}
		}

		else if (strcmp(word, "ExtractMin") == 0)
		{
			if (ADT == 1 || heap->size == 0)
			{
				fprintf(stderr, "Error: ExtractMin in a max heap or a null/empty heap\n");

			}
			else if (ADT == 2)
			{
				element Key = min->extractMin(heap);
				fprintf(stdout, "ExtractMin: %d\n", Key);
			}
			else if (ADT == 3)
			{
				element Key = min->extractMin(heap);
				fprintf(stdout, "ExtractMin: %d\n", Key);
				heap->size++;
				pos = Key.maxHeap;
				max->Delete(heap, pos);
			}
		}

		else if (strcmp(word, "IncreaseKey") == 0)
		{

			scanf("%d", &pos);
			scanf("%d", &value);
			if (ADT == 2 || heap->size == 0)
			{
				fprintf(stderr, "Error: IncreaseKey in a min heap or a null/empty heap\n");
				continue;
			}
			if (pos >= heap->size || heap->A[pos]->key >= value)
			{
				fprintf(stderr, "Error: Invalid position or newKey in IncreaseKey\n");
				continue;
			}

			if (ADT == 1)
			{
				max->IncreaseKey(heap, pos, value);
			}
			if (ADT == 3)
			{
				element e = *heap->A[pos];
				max->IncreaseKey(heap, pos, value);
				min->IncreaseKey(heap, pos, value);
			}
		}

		else if (strcmp(word, "DecreaseKey") == 0)
		{
			scanf("%d", &pos);
			scanf("%d", &value);
			if (ADT == 1 || heap->size == 0)
			{
				fprintf(stderr, "Error: DecreaseKey in a max heap or a null/empty heap\n");
				continue;
			}
			if (pos >= heap->size || heap->a[pos]->key <= value)
			{
				fprintf(stderr, "Error: Invalid position or newKey in DecreaseKey\n");
				continue;
			}
			if (ADT == 2)
			{
				min->DecreaseKey(heap, pos, value);
			}
			if (ADT == 3)
			{
				element e = *heap->a[pos];
				min->DecreaseKey(heap, pos, value);
				max->DecreaseKey(heap, pos, value);
			}

		}
		else
		{
			fprintf(stderr, "Error: Invalid command\n");


		}
	}

}