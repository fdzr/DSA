#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Graph = vector<vector<T>>;

void dfs(Graph<int> &G, vector<int> &visited, int source, int dest, int time, int k,
         int &cont) {
    if (source == dest && time == k) {
        ++cont;
        return;
    }

    visited[source] = 1;

    for (const auto &u : G[source]) {
        if (visited[u] == 0 && time < k) {
            dfs(G, visited, u, dest, time + 1, k, cont);
        }
    }

    visited[source] = 0;
}

int solution(Graph<int> &G, int source, int dest, int k) {
    vector<int> visited(G.size(), 0);
    int cont = 0;
    int time = 0;

    dfs(G, visited, source, dest, time, k, cont);

    return cont;
}

void addEdge(Graph<int> &G, int u, int v) { G[u].push_back(v); }

int main() {
    Graph<int> G(8);
    addEdge(G, 0, 1);
    addEdge(G, 0, 6);

    addEdge(G, 1, 2);
    addEdge(G, 1, 5);
    addEdge(G, 1, 6);

    addEdge(G, 2, 3);

    addEdge(G, 3, 4);

    addEdge(G, 5, 2);
    addEdge(G, 5, 3);
    addEdge(G, 5, 4);

    addEdge(G, 6, 5);

    addEdge(G, 7, 1);
    addEdge(G, 7, 6);

    int source = 0, dest = 3, k = 4;

    cout << solution(G, source, dest, k);

    return 0;
}