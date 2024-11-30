#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void APUtil(Graph &G, int u, vector<int> &visited, vector<int> &disc, vector<int> &low,
            int &time, int parent, vector<int> &isAP) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (auto v : G[u]) {
        if (visited[v] == 0) {
            ++children;
            APUtil(G, v, visited, disc, low, time, u, isAP);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) isAP[u] = 1;

        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent == -1 && children > 1) isAP[u] = 1;
}

void AP(Graph &G, int V) {
    vector<int> desc(V, 0);
    vector<int> low(V, 0);
    vector<int> visited(V, 0);
    vector<int> isAP(V, 0);
    int time = 0;
    int parent = -1;

    for (int i = 0; i < V; ++i) {
        if (visited[i] == 0) APUtil(G, i, visited, desc, low, time, parent, isAP);
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

    return 0;
}