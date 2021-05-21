#include "graph1.h"

using namespace std;


void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}


void Graph::DFS(int v){
    visited[v] = true;
    cout<<v<<" ";

    for(auto a=adj[v].begin(); a!=adj[v].end(); ++a)
        if(!visited[*a])
            DFS(*a);
}


void Graph::DFSUtil(int v){
    visited[v] = true;
    cout<<v<<" ";

    for(auto a=adj[v].begin();a!=adj[v].end(); ++a)
        if(!visited[*a])
            DFSUtil(*a);
}

void Graph::DFS1(){
    for(auto a: adj)
        if(visited[a.first] == false)
            DFSUtil(a.first);
}
