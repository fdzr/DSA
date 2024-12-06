#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void bridgeUtil(Graph &G, vector<int> &visited, int source, vector<int> &disc,
                vector<int> &low, int parent, int &time) {
    visited[source] = 1;
    low[source] = disc[source] = ++time;

    for (const auto &v : G[source]) {
        if (v == parent)
            continue;
        else if (visited[v] == 1) {
            low[source] = min(low[source], disc[v]);
        } else {
            bridgeUtil(G, visited, v, disc, low, source, time);
            low[source] = min(low[source], low[v]);

            if (low[v] > disc[source]) cout << source << " " << v << "\n";
        }
    }
}

void bridge(Graph &G) {
    vector<int> visited(G.size(), 0);
    vector<int> disc(G.size(), 0);
    vector<int> low(G.size(), 0);
    int time = 0;
    int parent = -1;

    for (int i = 0; i < G.size(); ++i) {
        if (visited[i] == 0) bridgeUtil(G, visited, i, disc, low, parent, time);
    }
}

void addEdge(Graph &G, int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    Graph G(7);

    addEdge(G, 0, 1);
    addEdge(G, 0, 2);

    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 1, 6);

    addEdge(G, 3, 5);

    addEdge(G, 4, 5);

    bridge(G);

    return 0;
}