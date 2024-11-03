#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/bipartite-graph/

using namespace std;

#define ENDL printf("\n")

using Graph = vector<vector<int>>;

bool BFS(Graph G, vector<int> &colored, int source)
{
    colored[source] = 1;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int j = 0; j < G[v].size(); ++j)
        {
            if (colored[G[v][j]] == -1)
            {
                q.push(G[v][j]);
                colored[G[v][j]] = abs(colored[v] - 1);
            }
            else
            {
                if (colored[G[v][j]] == colored[v])
                    return false;
            }
        }
    }

    return true;
}

bool BFSDisconnected(const Graph &G)
{
    vector<int> colored(G.size(), -1);
    bool answer;

    for (int i = 0; i < G.size(); ++i)
    {
        if (colored[i] == -1)
        {
            answer = BFS(G, colored, i);
            if (answer == false)
                return false;
        }
    }

    return true;
}

bool DFS(const Graph &G, vector<int> &colored, int source)
{
    for (int i = 0; i < G[source].size(); ++i)
    {
        if (colored[G[source][i]] == -1)
        {
            colored[G[source][i]] = abs(colored[source] - 1);
            DFS(G, colored, G[source][i]);
        }
        else
        {
            if (colored[G[source][i]] == colored[source])
                return false;
        }
    }

    return true;
}

bool DFSDisconnected(const Graph &G)
{
    vector<int> colored(G.size(), -1);
    bool answer;

    for (int i = 0; i < G.size(); ++i)
    {
        if (colored[i] == -1)
        {
            colored[i] = 1;
            answer = DFS(G, colored, i);
            if (answer == false)
                return false;
        }
    }

    return true;
}

void addEdge(Graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    Graph G(4);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);

    cout << boolalpha << BFSDisconnected(G);
    ENDL;
    cout << boolalpha << DFSDisconnected(G);

    ENDL;

    G.clear();

    G.resize(4);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);

    cout << boolalpha << BFSDisconnected(G);
    ENDL;
    cout << boolalpha << BFSDisconnected(G);
    ENDL;


    return 0;
}