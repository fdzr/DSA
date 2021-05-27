#include <iostream>
#include <vector>
#include <algorithm>
#include "graph2.h"

using namespace std;

Graph::Graph(int v): V{v}, adj{new list<int>[v]}{}

void Graph::DFSUtil(int v, vector<bool> &visited){
    visited[v] = true;
    
    for(auto ptr=adj[v].begin(); ptr!=adj[v].end(); ++ptr)
        if(!visited[*ptr])
            DFSUtil(*ptr, visited);
}


void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}


int Graph::findMother(){
    vector<bool> visited(V, false);

    int v = 0;
    for(int i=0;i<V; ++i){
        if(visited[i] == false){
            DFSUtil(i, visited);
            v = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFSUtil(v, visited);
    for(int i = 0;i < V; ++i)
        if(visited[i]==false)
            return -1;

    return v;
}


