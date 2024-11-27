#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(Graph &G, vector<int> &visited, int source, int removed) {
    visited[source] = 1;

    for (const auto &elem : G[source]) {
        if (visited[elem] == 0 && elem != removed)
            DFS(G, visited, elem, removed);
    }
}

void numberArticulationPoints(Graph &G) {
    

    for (int i = 0; i < G.size(); ++i) {
        int connectedComponenets = 0;
        vector<int> visited(G.size(), 0);

        for (int j = 0; j < G.size(); ++j) {
            if (i != j) {
                if (visited[j] == 0) {
                    connectedComponenets += 1;
                    DFS(G, visited, j, i);
                }
            }
        }

        if (connectedComponenets > 1)
            cout << i << " articulation point" << "\n";
    }
}

void addEdge(Graph &G, int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    Graph G(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    
    addEdge(G, 1, 2);

    addEdge(G, 2, 3);
    addEdge(G, 3, 4);

    numberArticulationPoints(G);

    return 0;
}