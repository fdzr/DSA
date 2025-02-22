#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using listAdj = vector<vector<pi>>;

struct edge {
    int u;
    int v;
    int w;

    bool operator>(const edge& lhr) const { return w < lhr.w; };
};

void dijkstra(const listAdj& graph, int k, vector<int>& dist) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    pq.push({0, k, 0});

    while (pq.size() > 0) {
        auto edge = pq.top();
        pq.pop();

        for (int i = 0; i < graph[edge.v].size(); ++i) {
            if (dist[graph[edge.v][i].first] > dist[edge.v] + graph[edge.v][i].second) {
                dist[graph[edge.v][i].first] = dist[edge.v] + graph[edge.v][i].second;
                pq.push({edge.v, graph[edge.v][i].first, dist[graph[edge.v][i].first]});
            }
        }
    }
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    listAdj graph(n);
    vector<int> dist(n, INT_MAX);
    dist[k - 1] = 0;
    for (int i = 0; i < times.size(); ++i) {
        graph[times[i][0] - 1].push_back(make_pair(times[i][1] - 1, times[i][2]));
    }

    dijkstra(graph, k - 1, dist);

    // for (int i = 0; i < dist.size(); ++i) {
    //     cout << dist[i] << "\n";
    // }

    int time = *max_element(dist.begin(), dist.end());

    return (time == INT_MAX) ? -1 : time;
}

int main() {
    // vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    vector<vector<int>> times = {{1, 2, 1}};
    int n = 2;
    int k = 2;
    cout<< networkDelayTime(times, n, k);

    return 0;
}