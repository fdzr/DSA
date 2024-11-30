#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void APUtil(Graph &G, int u, vector<int> &visited, vector<int> &ids, vector<int> &low,
            int &id, int parent, vector<int> &isAP) {
    int children = 0;
    visited[u] = 1;
    ids[u] = low[u] = ++id;

    for (auto v : G[u]) {
        if (visited[v] == 0) {
            ++children;
            APUtil(G, v, visited, ids, low, id, u, isAP);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= ids[u]) isAP[u] = 1;

        } else if (v != parent) {
            low[u] = min(low[u], ids[v]);
        }
    }

    if (parent == -1 && children > 1) isAP[u] = 1;
}

void AP(Graph &G, int V) {
    vector<int> ids(V, 0);
    vector<int> low(V, 0);
    vector<int> visited(V, 0);
    vector<int> isAP(V, 0);
    int id = 0;
    int parent = -1;

    for (int i = 0; i < V; ++i) {
        if (visited[i] == 0) APUtil(G, i, visited, ids, low, id, parent, isAP);
    }

    for (int u = 0; u < V; ++u)
        if (isAP[u] == 1) cout << u << " ";
}

void addEdge(Graph &G, int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    Graph G(5);
    addEdge(G, 1, 0);
    addEdge(G, 0, 2);
    addEdge(G, 2, 1);
    addEdge(G, 0, 3);
    addEdge(G, 3, 4);

    AP(G, 5);
    printf("\n");

    G.clear();
    G.resize(7);
    addEdge(G, 0, 1);
    addEdge(G, 1, 2);
    addEdge(G, 2, 0);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 1, 6);
    addEdge(G, 3, 5);
    addEdge(G, 4, 5);
    AP(G, 7);

    return 0;
}