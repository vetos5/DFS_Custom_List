#include "Graph.h"

int main() {

	Graph G1(6);

	G1.addEdge(0, 1);
	G1.addEdge(0, 2);
	G1.addEdge(1, 3);
	G1.addEdge(1, 4);
	G1.addEdge(1, 5);
	G1.addEdge(2, 4);
	

	cout << "DFS result: " << endl;
	G1.DFS(0);

	return 0;
}