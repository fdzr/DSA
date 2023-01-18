//
// Created by fzamora on 18-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using vvi = vector<vector<int>>;

void DFS(int v, vvi isConnected, vector<bool> &visited) {
    visited[v] = true;
    for(int i = 0; i < isConnected[v].size(); ++i) {
        if(isConnected[v][i] == 1 && !visited[i])
            DFS(i, isConnected, visited);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int cont = 0;
    vector<bool> visited(isConnected.size());

    for(int i = 0; i < isConnected.size(); ++i) {
        if(!visited[i]) {
            DFS(i, isConnected, visited);
            cont++;
        }
    }

    return cont;
}

int main() {
    vvi edges = {{1}};
    cout<<findCircleNum(edges);

    return 0;
}