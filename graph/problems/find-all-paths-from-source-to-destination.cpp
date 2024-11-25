#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(const Graph &G, int source, int dest, vector<int> &visited, int &cont) {
    visited[source] = 1;

    for (const auto &u : G[source]) {
        if (visited[u] == 0) {
            if (u == dest) {
                ++cont;
            }
            DFS(G, u, dest, visited, cont);
        }
    }

    visited[source] = 0;
}

void DFSUtil(Graph &G) {
    vector<int> visited(G.size(), 0);
    int cont = 0;

    DFS(G, 0, 4, visited, cont);

    cout << cont;
}

void addEdge(Graph &G, int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    Graph G(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 3);
    addEdge(G, 0, 4);

    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);

    addEdge(G, 2, 3);

    DFSUtil(G);

    return 0;
}