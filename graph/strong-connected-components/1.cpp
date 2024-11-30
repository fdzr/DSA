#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool DFS(const Graph &G, int src, int dest, vector<int> &visited) {
    visited[src] = 1;

    if (src == dest) return true;

    for (const auto u : G[src]) {
        if (visited[u] == 0 && DFS(G, u, dest, visited)) return true;
    }

    return false;
}

bool isPath(const Graph &G, int u, int v) {
    vector<int> visited(G.size(), 0);
    return DFS(G, u, v, visited);
}

vector<vector<int>> getSCC(Graph &G) {
    vector<int> scc;
    vector<int> isSCC(G.size(), 0);
    vector<vector<int>> answer;

    for (int v = 0; v < G.size(); ++v) {
        if (isSCC[v] == 1) continue;

        scc.push_back(v);
        isSCC[v] = 1;

        for (int u = v + 1; u != G.size(); ++u) {
            if (isSCC[u] == 0 && isPath(G, u, v) && isPath(G, v, u)) {
                scc.push_back(u);
                isSCC[u] = 1;
            }
        }

        answer.push_back(scc);
        scc.clear();
    }

    return answer;
}

int main() {
    Graph G(5);
    G[0] = {{2, 3}};
    G[1] = {{0}};
    G[2] = {{1}};
    G[3] = {{4}};

    for (const auto &scc : getSCC(G)) {
        for (const auto &v : scc) cout << v << " ";

        cout << "\n";
    }

    return 0;
}