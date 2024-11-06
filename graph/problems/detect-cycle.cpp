// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool BFS(Graph &G, vector<int> &visited, int source)
{
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (visited[v] == 1)
            return true;

        visited[v] = 1;

        for (const auto &vertex : G[v])
        {
            if (visited[vertex] == 0)
                q.push(vertex);
        }
    }

    return false;
}

bool BFSDisconnected(Graph &G)
{
    vector<int> visited(G.size(), 0);

    for (int i = 0; i < G.size(); ++i)
    {
        if (visited[i] == 0 && BFS(G, visited, i))
            return true;
    }

    return false;
}

int main()
{
    Graph G(5);
    G[0] = {1};
    G[1] = {0, 2, 3};
    G[2] = {1, 3, 4};
    G[3] = {1, 2};
    G[4] = {2};

    cout<<boolalpha<<BFSDisconnected(G);

    return 0;
}