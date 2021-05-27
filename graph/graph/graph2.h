#include <iostream>
#include <list>
#include <vector>

using namespace std;


#ifndef graph2_H
#define graph2_H


class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, vector<bool> &visited);
    
    public:
        Graph(int V);
        void addEdge(int v, int w);
        int findMother();
};

#endif

