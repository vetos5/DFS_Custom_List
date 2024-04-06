#pragma once
#include "List.h"
#include <vector>
#include <iostream>

using std::cout;
using std::vector;
using std::endl;

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


    void DFS(int startVertex) const {
        vector<bool> visited(numVertices, false); 
        LinkedList<int> stack;

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

};
