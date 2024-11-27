#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using Graph = vector<vector<pi>>;

void printDest(const vector<int> &dest, int source) {
    for (int i = 0; i < dest.size(); ++i) {
        if (i == source)
            continue;

        cout << "(" << source << ", " << i << ") = ";

        (dest[i] == INT_MIN) ? cout << "INF" : cout << dest[i];
        cout << "\n";
    }
}

void topologicalSorting(Graph &G, vector<int> &visited, int source, stack<int> &ts) {
    visited[source] = 1;

    for (const auto &edge : G[source])
        if (visited[edge.first] == 0)
            topologicalSorting(G, visited, edge.first, ts);

    ts.push(source);
}

void longestPath(Graph &G, int source) {
    vector<int> visited(G.size(), 0);
    stack<int> ts;
    vector<int> dest(G.size(), INT_MIN);
    dest[source] = 0;

    for (int v = 0; v < G.size(); ++v) {
        if (visited[v] == 0)
            topologicalSorting(G, visited, v, ts);
    }

    while (!ts.empty()) {
        int v = ts.top();
        ts.pop();

        for (const auto &edge : G[v]) {
            if (dest[edge.first] < dest[v] + edge.second)
                dest[edge.first] = dest[v] + edge.second;
        }
    }

    printDest(dest, source);
}

void addEdge(Graph &G, int src, int dest, int w) {
    G[src].push_back({dest, w});
}

int main() {
    Graph G(8);

    addEdge(G, 0, 6, 2);

    addEdge(G, 1, 2, -4);
    addEdge(G, 1, 4, 1);
    addEdge(G, 1, 6, 8);

    addEdge(G, 3, 0, 3);
    addEdge(G, 3, 4, 5);

    addEdge(G, 5, 1, 2);

    addEdge(G, 7, 0, 6);
    addEdge(G, 7, 1, -1);
    addEdge(G, 7, 3, 4);
    addEdge(G, 7, 5, -4);

    longestPath(G, 7);

    return 0;
}