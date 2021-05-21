#include <iostream>
#include <map>
#include <list>

using namespace std;


#ifndef graph1_H
#define graph1_H


class Graph{
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;

        void addEdge(int v, int w);
        void DFS(int v);
        void DFSUtil(int v);
        void DFS1();
};

#endif
