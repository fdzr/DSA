#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(Graph &G, vector<int> &visited, int source) {
    visited[source] = 1;

    for(const auto& v: G[source]) {
        if(visited[v] == 0)
            DFS(G, visited, v);
    }
}

bool isConnected(Graph &G) {
    int v;
    for(v = 0; v < G.size(); ++v) {
        if(G[v].size() > 0)
            break;
    }

    if (v == G.size())
        return false;

    vector<int> visited(G.size(), 0);

    DFS(G, visited, v);

    for(int i = 0; i < visited.size(); ++i) {
        if(G[i].size() > 0 && visited[i] == 0)
            return false;
    }

    return true;
}

int isEulerian(Graph &G) {
    if(isConnected(G) == false)
        return 0;


    int odd = 0;
    for(int i = 0; i < G.size(); ++i) {
        if(G[i].size() & 1)
            ++odd;
    }

    if(odd > 2)
        return 0;

    return (odd)? 1: 2;

}

void addEdge(Graph &G, int v, int w) {
    G[v].push_back(w);
    G[w].push_back(v);
}

void test(Graph &G) {
    int answer = isEulerian(G);
    if(answer ==0 )
        cout<<"no Eulerian..."<<"\n";
    else if(answer == 1)
        cout<<"Eulerian Path..."<<"\n";
    else
        cout<<"Eulerian circuit..."<<"\n";
}

int main() {
    Graph G(5);
    addEdge(G, 1, 0);
    addEdge(G, 0, 2);
    addEdge(G, 2, 1);
    addEdge(G, 0, 3);
    addEdge(G, 3, 4);
    test(G);

    G.clear();
    G.resize(5);

    addEdge(G, 1, 0);
    addEdge(G, 0, 2);
    addEdge(G, 2, 1);
    addEdge(G, 0, 3);
    addEdge(G, 3, 4);
    addEdge(G, 4, 0);
    test(G);

    G.clear();
    G.resize(5);

    addEdge(G, 1, 0);
    addEdge(G, 0, 2);
    addEdge(G, 2, 1);
    addEdge(G, 0, 3);
    addEdge(G, 3, 4);
    addEdge(G, 1, 3);
    test(G);

    return 0;
}