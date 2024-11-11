#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

int prim(const Graph &G)
{
    int V = G.size();               // Number of vertices
    vector<bool> visited(V, false); // Track visited nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int mst_cost = 0; // Minimum Spanning Tree cost

    // Start from vertex 0 (or any arbitrary vertex)
    pq.push({0, 0}); // (weight, vertex)

    while (!pq.empty())
    {
        auto [weight, u] = pq.top(); // Get the edge with the minimum weight
        pq.pop();

        // If the vertex has already been visited, continue
        if (visited[u])
            continue;

        // Mark the current node as visited and add its edge's weight to the total cost
        visited[u] = true;
        mst_cost += weight;

        // Add all edges from the current node to the priority queue
        for (const auto &[v_weight, v] : G[u])
        {
            if (!visited[v])
            { // Only push edges leading to unvisited nodes
                pq.push({v_weight, v});
            }
        }
    }

    // Optional check: if all vertices were not visited, the graph wasn't fully connected.
    for (bool wasVisited : visited)
    {
        if (!wasVisited)
        {
            cerr << "Warning: The graph is not connected, and the MST could be incomplete." << endl;
            return -1; // Or handle it as needed.
        }
    }

    return mst_cost;
}

void addEdge(Graph &G, int u, int v, int w)
{
    G[u].push_back({w, v});
    G[v].push_back({w, u});
}

int main()
{
    Graph G(9);
    addEdge(G, 0, 1, 7);
    addEdge(G, 0, 8, 15);

    addEdge(G, 1, 2, 5);

    addEdge(G, 2, 3, 4);
    addEdge(G, 2, 4, 2);
    addEdge(G, 2, 6, 3);

    addEdge(G, 3, 4, 1);
    addEdge(G, 3, 5, 9);

    addEdge(G, 5, 6, 5);
    addEdge(G, 5, 7, 12);

    addEdge(G, 6, 8, 6);

    addEdge(G, 7, 8, 10);

    int mst_cost = prim(G);
    cout<<mst_cost;

    return 0;
}