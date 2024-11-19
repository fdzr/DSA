#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int prim(Graph G)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(G.size(), 0);
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        auto item = pq.top();
        pq.pop();

        if(visited[item.second] == 1)
            continue;

        visited[item.second] = 1;
        sum += item.first;

        for (int v = 0; v < G[item.second].size(); ++v)
        {
            if (G[item.second][v] != 0 && visited[v] == 0)
            {
                pq.push({G[item.second][v], v});
            }
        }
    }

    return sum;
}

int main()
{
    Graph G(5, vector<int>(5, 0));
    G[0] = {0, 1, 2, 3, 4};
    G[1] = {1, 0, 5, 0, 7};
    G[2] = {2, 5, 0, 6, 0};
    G[3] = {3, 0, 6, 0, 0};
    G[4] = {4, 7, 0, 0, 0};

    cout<<prim(G);

    return 0;
}