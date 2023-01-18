//
// Created by fzamora on 18-01-23.
//
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

struct DS {
    int *parent, *rnk;
    int n;
    DS(int n) {
        parent = new int[n];
        rnk = new int[n];

        for(int i = 0; i < n; ++i) {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if(x != y) {
            if(rnk[x] > rnk[y]) {
                parent[y] = x;
            }
            else if(rnk[x] < rnk[y])
                parent[x] = y;
            else {
                parent[x] = y;
                rnk[y]++;
            }
        }
    }

    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);

        return parent[u];
    }
};

int findMax(vvi edges) {
    int maxElement = INT_MIN;
    for(auto edge: edges) {
        int max_ = *max_element(edge.begin(), edge.end());
        if(max_ > maxElement)
            maxElement = max_;
    }

    return maxElement;
}


vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    vvi ans;
    int n = findMax(edges);
    DS ds(n + 1);

    for(auto edge: edges) {
        int set_u = ds.find(edge[0]);
        int set_v = ds.find(edge[1]);

        if(set_u != set_v) {
            ds.merge(set_u, set_v);
        }
        else {
            ans.push_back(edge);
        }
    }
    return *ans.rbegin();
}


int main() {
    vvi edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    for(auto item: findRedundantConnection(edges))
        cout<<item<<" ";

    return 0;
}