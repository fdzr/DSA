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
        return true;

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
        return false;


    int odd = 1;
    for(int i = 0; i < G.size(); ++i) {
        if(G[i].size() & 1)
            ++odd;
    }

    if(odd > 2)
        return false;

    return (odd)? 1: 2;

}

int main() {


    return 0;
}