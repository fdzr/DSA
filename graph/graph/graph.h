#include <iostream>
#include <list>

using namespace std;

#ifndef graph_H
#define graph_H


class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int v);
        void addEdge(int v, int w);
        void BFS(int s);
};

#endif

