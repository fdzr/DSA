#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool DFS(const Graph &G, vector<int> &visited, vector<int> &redStack, int source) {
    visited[source] = 1;
    redStack[source] = 1;

    for (const auto &u : G[source]) {
        if (visited[u] == 0 && DFS(G, visited, redStack, u))
            return true;
        else if (redStack[u] == 1)
            return true;
    }

    redStack[source] = 0;
    return false;
}

bool graphDisconnected(const Graph &G) {
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);

    for (int v = 0; v < G.size(); ++v) {
        if (visited[v] == 0 && DFS(G, visited, redStack, v))
            return true;
    }

    return false;
}

void addEdge(Graph &G, int src, int dest) {
    G[src].push_back(dest);
}

int main() {
    Graph G(4);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 2);
    addEdge(G, 2, 0);
    addEdge(G, 2, 3);

    cout << boolalpha << "has Cycle?: "<<graphDisconnected(G);

    return 0;
}