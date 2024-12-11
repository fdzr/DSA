#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int BFS(Graph& G, vector<int>& visited, int source) {
    queue<pair<int, int>> q;
    q.push({source, 0});

    while (!q.empty()) {
        pair<int, int> item = q.front();
        q.pop();
        visited[item.first] = 1;

        if (item.first == G.size() - 1) return item.second;

        for (const auto& v : G[item.first]) {
            if (visited[v] == 0) q.push({v, item.second + 1});
        }
    }

    return 0;
}

Graph getListAdj(int n) {
    Graph G(n);
    for (int i = 0; i < n - 1; ++i) {
        G[i] = {i + 1};
    }

    return G;
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> outputs;
    Graph G = getListAdj(n);

    for (const auto& edge : queries) {
        G[edge[0]].push_back(edge[1]);
        vector<int> visited(G.size(), 0);
        int shortestPath = BFS(G, visited, 0);
        outputs.push_back(shortestPath);
    }

    return outputs;
}

int main() {
    int n = 5;
    Graph queries = {{2, 4}, {0, 2}, {0, 4}};

    for (const auto& e : shortestDistanceAfterQueries(n, queries)) cout << e << " ";

    cout<< "\n";

    queries = {{0,3}, {0, 2}};
    n = 4;
    for (const auto& e : shortestDistanceAfterQueries(n, queries)) cout << e << " ";

    return 0;
}