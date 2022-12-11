#include "Util.h"


// print array in output
void printArr(int dist[], int n) {
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i + 1, dist[i]);
}




