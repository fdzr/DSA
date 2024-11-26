#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using Graph = vector<vector<pi>>;

void printDest(const vector<int> &);

int dikjstra(Graph &G, int source) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    vector<int> dest(G.size(), INT_MAX);
    dest[source] = 0;

    int minTime = INT_MAX;
    int ways[G.size()] = {0};
    ways[source] = 1;

    while (!pq.empty()) {
        auto we = pq.top();
        pq.pop();

        for (const auto &u : G[we.second]) {
            if (dest[u.second] > dest[we.second] + u.first) {
                dest[u.second] = dest[we.second] + u.first;
                pq.push({dest[u.second], u.second});
                ways[u.second] = ways[we.second];
                
            } else if (dest[u.second] == dest[we.second] + u.first)
                ways[u.second] += ways[we.second];
        }
    }

    printDest(dest);

    return ways[G.size() - 1];
}

void printDest(const vector<int> &dest) {
    for (int i = 0; i < dest.size(); ++i)
        cout << i << ": " << dest[i] << "\n";

    cout<< "\n";
}

void addEdge(Graph &G, int u, int v, int w) {
    G[u].push_back({w, v});
    G[v].push_back({w, u});
}

int main() {
    Graph G(7);
    addEdge(G, 0, 1, 2);
    addEdge(G, 0, 4, 5);
    addEdge(G, 0, 6, 7);

    addEdge(G, 1, 2, 3);
    addEdge(G, 1, 3, 3);

    addEdge(G, 2, 5, 1);

    addEdge(G, 3, 5, 1);
    addEdge(G, 3, 6, 3);

    addEdge(G, 4, 6, 2);

    addEdge(G, 5, 6, 1);

    cout<< dikjstra(G, 0);

    return 0;
}