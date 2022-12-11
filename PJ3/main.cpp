# include <iostream>
#include <stdio.h>
#include "Graph.h"
#include "Stack.h"
#include "minHeap.h"
#include <fstream>
#include <string.h>
#include "minHeap.h"
#include <dirent.h>
#include <float.h>
#include <iomanip>

using namespace std;

void Usage();


// return a list of strings in a file.
vector<string> readAllLines(const char * filePath) {
	string line;
	ifstream fileStream(filePath);
	vector<string> list;
	while (getline(fileStream, line)) {
		if (line.length() > 0)
			list.push_back(line);
	}
	return list;
}



int main(int argc, char * argv[]) {
	

	if (argc != 3) {

		Usage();
		exit(1);
	}
	int ADT = -1;
	if (strcmp(argv[1], "Directed") == 0)
		ADT = 1;
	else if (strcmp(argv[1], "Undirected") == 0)
		ADT = 2;
	else {
		printf("%s\n", argv[1]);
		Usage();
		exit(1);
	}

	bool isUndirected = (ADT == 2);
	Graph * g = readFile(ADT, argv[2], isUndirected);

	if (g == NULL) {
		exit(1);
	}


	int dijSource = -1;

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	while (1) {
		char word[500];

		scanf("%s", word);

		if (strcmp(word, "Stop") == 0) {
			exit(1);

		} else if (strcmp(word, "SinglePair") == 0) {
			int source;
			int destination;
			scanf("%d\n", &source);
			scanf("%d\n", &destination);
			source--;
			destination--;
			runDijkstrasAlgo(g, source);
			dijSource = source;
		} else if (strcmp(word, "SingleSource") == 0) {
			int source;
			scanf("%d", &source);
			source--;
			runDijkstrasAlgo(g, source);
			dijSource = source;
		} else if (strcmp(word, "PrintPath") == 0) {
			int s;
			int t;
			scanf("%d\n", &s);
			scanf("%d\n", &t);
			s--;
			t--;
			if (dijSource == s) {
				double dist = g->dist[t];
				if (dist == DBL_MAX) {
					cout << "There is no path from " << (s + 1) << " to "
							<< (t + 1) << "." << endl;
				} else {
					int curr = t;
					StackNode* root = NULL;

					while (curr != s) {
						pushToStack(&root, curr);
						curr = g->prev[curr];
					}
					pushToStack(&root, s);
					cout << "The shortest path from " << (s + 1) << " to "
							<< (t + 1) << " is:" << endl;
					bool isFirst = true;
					while (!isStackEmpty(root)) {
						int nd = popFromStack(&root);
						double dist = g->dist[nd];
						if (!isFirst)
							cout << "-->";
						cout << "[" << (nd + 1) << ":";
						cout.width(8);
						
						cout << std::fixed << std::setprecision(2) << std::right
								<< dist;
					

						cout << "]";
						
						isFirst = false;

					}
					cout << "." << endl;
				}
			}

		} else if (strcmp(word, "PrintLength") == 0) {
			int s;
			int t;
			scanf("%d\n", &s);
			scanf("%d\n", &t);
			s--;
			t--;
			if (dijSource == s) {
				double dist = g->dist[t];
				if (dist == DBL_MAX) {
					cout << "There is no path from " << (s + 1) << " to "
							<< (t + 1) << "." << endl;
				} else {

					cout << "The length of the shortest path from " << (s + 1)
							<< " to " << (t + 1) << " is:";
					cout.width(9);
					cout << std::fixed << std::setprecision(2) << std::right
							<< dist;
					cout << endl;
				}
			}

		} else if (strcmp(word, "PrintADJ") == 0) {
			for (int i = 0; i < g->nodesCount; i++) {
				cout << "ADJ[" << (i + 1) << "]:";
				struct Node* curr = g->adjacencyList[i].head;
				while (curr != NULL) {
					cout << "-->[" << (i + 1) << " " << (curr->v + 1) << ": "
							<< curr->w << "]";
					curr = curr->next;
				}
				cout << endl;
			}
		} else {
			printf("Invalid command.");
		}

	}

}

void Usage() {

	printf("Usage: ./PJ3 <GraphType> <InputFile>");

}
