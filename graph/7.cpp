//
// Created by fzamora on 18-01-23.
//
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

struct DFU {
    int *parent, *rnk;
    int n;

    DFU(int n) {
        this->n = n;
        rnk = new int[n];
        parent = new int[n];

        for(int i = 0; i < n ; ++i) {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);

        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(rnk[x] > rnk[y])
            parent[y] = x;
        else if(rnk[y] > rnk[x])
            parent[x] = y;
        else {
            parent[x] = y;
            rnk[y]++;
        }

    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<pair<int, pi>> edges;
     int m = points.size();
    for(int i = 0; i < m - 1; ++i) {
        for(int j = i + 1; j < m; ++j ) {
            float distance = abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0]);
            edges.push_back({distance, {i, j}});
        }
    }

    DFU ds(points.size());
    sort(edges.begin(), edges.end());
    int sum = 0;

    for(auto edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            sum += edge.first;

            ds.merge(set_u, set_v);
        }
    }

    return sum;
}

int main() {
    vector<vector<int>> points = {{3,12}, {-2,5},{-4,1}};
    cout<<minCostConnectPoints(points);



    return 0;
}