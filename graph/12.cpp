#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

struct DS {
    vi rnk;
    vi parent;
    int n;

    DS(int n_) {
        n = n_;
        rnk.assign(n, 0);
        parent.assign(n, 0);
        n = n;

        for(int i = 0; i < n ; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);

        return parent[u];
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

    int numberOfConnectedComponnets() {
        set<int> conj;
        for(int i =0; i < n; ++i)
            conj.insert(find(parent[i]));

        return conj.size();
    }
};


int makeConnected(int n, vector<vector<int>>& connections) {
    DS ds(n);
    int cont = 0;
    for(auto edge: connections) {
        int set_x = ds.find(edge[0]);
        int set_y = ds.find(edge[1]);
        if(set_x != set_y)
            ds.merge(edge[0], edge[1]);
        else
            cont++;
    }

    int numberConnectedComponents = ds.numberOfConnectedComponnets();
    
    if (numberConnectedComponents == 1)
        return 0;
    if(cont < numberConnectedComponents - 1)
        return -1;

    return min(cont, numberConnectedComponents - 1);
}

using vvi = vector<vector<int>>;

int main() {
    vvi connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout<<makeConnected(6, connections);

    return 0;
}