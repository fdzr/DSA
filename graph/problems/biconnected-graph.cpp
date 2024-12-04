#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool DFS(Graph &G, int source, vector<int> &visited, vector<int> &desc, vector<int> &low,
         int parent, int &time) {
    visited[source] = 1;
    low[source] = desc[source] = ++time;
    int children = 0;

    for (const auto &v : G[source]) {
        ++children;
        if (visited[v] == 0) {
            if (DFS(G, v, visited, desc, low, source, time)) return true;

            low[source] = min(low[source], low[v]);

            if (parent != -1 && low[v] >= desc[source]) {
                return true;
            }

            if (parent == -1 && children > 1) {
                return true;
            }

        } else if (v != parent) {
            low[source] = min(low[source], desc[v]);
        }
    }

    return false;
}

bool isBiconnected(Graph &G) {
    vector<int> visited(G.size(), 0);
    vector<int> desc(G.size(), 0);
    vector<int> low(G.size(), 0);
    int time = 0;
    int parent = -1;

    if (DFS(G, 0, visited, desc, low, parent, time)) return false;

    if (accumulate(visited.begin(), visited.end(), 0) != G.size()) return false;

    return true;
}

int main() {
    Graph G(5);
    G[0] = {1, 2, 3};
    G[1] = {0, 2};
    G[2] = {0, 1};
    G[3] = {0, 4};
    G[4] = {3};

    cout << boolalpha << isBiconnected(G);

    G.clear();
    G.resize(3);

    G[0] = {1, 2};
    G[1] = {0, 2};
    G[2] = {0, 1};
    cout << boolalpha << "\n" << isBiconnected(G);

    return 0;
}