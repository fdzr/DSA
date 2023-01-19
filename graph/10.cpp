//
// Created by fzamora on 19-01-23.
//
#include <bits/stdc++.h>

using namespace std;


using vpi = vector<pair<int, int>>;
using vvpi = vector<vpi>;
using vvi = vector<vector<int>>;


void loadEdges(const vvi& edges, vvpi &adjList) {
    for(auto edge: edges) {
        adjList[edge[0]].push_back({edge[1], 1});
        adjList[edge[1]].push_back({edge[0], 0});
    }
}

void DFS(vvpi graph, int vertex, vector<bool> &visited, int &cont) {
    visited[vertex] = true;

    for(auto item: graph[vertex]) {
        if(!visited[item.first]) {
            cont += item.second;
            DFS(graph, item.first, visited, cont);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    int cont = 0;
    vector<bool> visited(n);
    vvpi graph(n);
    loadEdges(connections, graph);

    DFS(graph, 0, visited, cont);

    return cont;
}

int main() {
    vvi connections = {{1,0},{1,2},{3,2},{3,4}};
    int n = 5;
    cout<<minReorder(n, connections);

    return 0;
}