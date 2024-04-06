#include "Graph.h"

int main() {

    Graph graph(0); 

    ifstream file("graph.txt"); 

    if (file.is_open()) {
        file >> graph; 
        file.close(); 
    }
    else {
        cerr << "Unable to open file!" << endl;
        return 1;
    };
	
	graph.DFS(0);
    cout << endl;
    graph.printAdjacencyList();
    cout << endl;
    graph.printAdjacencyMatrix();

	return 0;
}