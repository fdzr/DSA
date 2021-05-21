#include "graph.h"

Graph::Graph(int v): V{v}, adj{new list<int>[v]} {} 

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
 }



void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i=0;i<V;++i)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()){
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(auto i=adj[s].begin();i!=adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

