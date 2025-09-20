#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

struct hashType {
    int operator()(const pair<int, int> &pi) const {
        return hash<int>()(pi.first) ^ hash<int>()(pi.second << 1);
    }
};

void dfs(const vector<vector<int>> &graph, int v, vector<int> &visited,
         vector<int> &components) {
    visited[v] = 1;
    components.push_back(v);

    for (int i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) dfs(graph, graph[v][i], visited, components);
    }
}

int countEdges(const vector<int> &components, const vector<vector<int>> &graph) {
    int n = 0;
    unordered_set<pair<int, int>, hashType> us;
    for (const auto u : components) {
        for (const auto &v : graph[u]) {
            if (!us.contains(make_pair(u, v)) && !us.contains(make_pair(v, u))) {
                us.insert(make_pair(u, v));
                ++n;
            }
        }
    }

    return n;
}

bool isComplete(const int &numberVertex, const int &n) {
    return numberVertex * (numberVertex - 1) / 2 == n;
}

Graph buildGraph(const vvi &edges, int n) {
    Graph graph(n);

    for (const auto &u : edges) {
        graph[u[0]].push_back(u[1]);
        graph[u[1]].push_back(u[0]);
    }

    return graph;
}

int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<int> visited(n, 0);

    Graph graph = buildGraph(edges, n);

    int cont = 0;

    for (int v = 0; v < n; ++v) {
        if (visited[v] == 0) {
            vector<int> components;
            components.reserve(n);
            dfs(graph, v, visited, components);
            cont += isComplete(components.size(), countEdges(components, graph));
        }
    }

    return cont;
}

int main() {
    vector<vector<int>> edges;
    int n = 1;

    printf("%d", countCompleteComponents(n, edges));

    return 0;
}