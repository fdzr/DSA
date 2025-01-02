#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Graph = vector<vector<T>>;

struct edge {
    int w;
    int weight;
    int time;

    bool operator<(const edge &other) const {
        return weight < other.weight;
    }
};

void dijkstra(Graph<edge> &G, int source, int dest, int stops, bool &isAnswer, vector<int> &dist) {
    priority_queue<edge, vector<edge>> q;
    dist[source] = 0;

    q.push({source, 0, 0});

    while (q.size() > 0) {
        auto item = q.top();
        q.pop();

        if (item.w == dest) {
            isAnswer = true;
            return;
        }

        for (const auto &u : G[item.w]) {
            if (dist[u.w] > dist[item.w] + u.weight && item.time <= stops) {
                dist[u.w] = dist[item.w] + u.weight;
                q.push({u.w, dist[u.w], item.time + 1});
            }
        }
    }
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    Graph<edge> G(n);
    vector<int> dist(n, INT_MAX);
    bool isAnswer = false;

    for (const auto &v : flights) {
        G[v[0]].push_back({v[1], v[2], 0});
    }

    dijkstra(G, src, dst, k, isAnswer, dist);

    if (isAnswer)
        return dist[dst];

    return -1;
}

int main() {
    vector<vector<int>> flights = {
        {0, 1, 100}, 
        {0, 2, 100}, 
        {2, 3, 1}, 
        {3, 4, 600}, 
        {1, 4, 602}, 
        {4, 5, 6}, 
        {5, 6, 6}
    };

    int src = 0;
    int dst = 6;
    int k = 3;
    int n = 7;

    int ans = findCheapestPrice(n, flights, src, dst, k);
    cout << ans;

    return 0;
}