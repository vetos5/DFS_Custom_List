#pragma once
#include "List.h"
#include <vector>
#include <iostream>
#include <fstream>

class Graph {
private:
    int numVertices;
    vector<LinkedList<int>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    LinkedList<bool> visited;
    LinkedList<int> stack;

    void addEdge(int startVertex, int dest) {
        adjList[startVertex].push_back(dest);
    }

    friend istream& operator>>(istream& in, Graph& graph) {
        int numVertices, numEdges;
        in >> numVertices >> numEdges; 

        graph = Graph(numVertices);

        for (int i = 0; i < numEdges; ++i) {
            int src, dest;
            in >> src >> dest;
            graph.addEdge(src, dest);
        }

        return in;
    }

    void DFS(int startVertex) const {
        vector<bool> visited(numVertices, false); 
        LinkedList<int> stack;

        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        visited[startVertex] = true;
        stack.push_back(startVertex);


        while (!stack.empty()) {
            int currentVertex = stack.getTail()->data;
            stack.pop_back();


            cout << currentVertex << " ";

            ListNode<int>* current = adjList[currentVertex].getHead();
            while (current) {
                int adjVertex = current->data;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    stack.push_back(adjVertex);
                }
                current = current->next;
            }
        }

        cout << endl;
    }

    void printAdjacencyList() {
        int numVertices = adjList.size();

        cout << "Graph represented as adjacency list:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << i << ": ";
            for (int j = 0; j < adjList[i].size(); ++j) {
                cout << adjList[i][j];
                if (j < adjList[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    void printAdjacencyMatrix() {
        int numVertices = adjList.size();

        cout << "Graph represented as adjacency matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                bool isConnected = false;
                for (int k = 0; k < adjList[i].size(); ++k) {
                    if (adjList[i][k] == j) {
                        isConnected = true;
                        break;
                    }
                }
                cout << (isConnected ? "1 " : "0 ");
            }
            cout << endl;
        }
    }
};
