#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void printTopologicalOrder(vector<int> order) {
    for (const auto &elem : order)
        cout << elem << " ";

    cout << "\n";
}

bool DFS(const Graph &G, int src, vector<int> &visited, vector<int> &redStack, vector<int> &order) {
    visited[src] = 1;
    redStack[src] = 1;

    for (const auto &u : G[src]) {
        if (visited[u] == 0 && DFS(G, u, visited, redStack, order))
            return true;
        else if (redStack[u] == 1)
            return true;
    }

    order.push_back(src);
    redStack[src] = 0;
    return false;
}

void topologicalSorting(Graph &G) {
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);
    vector<int> order;

    bool hasCycles = false;

    for (int v = 0; v < G.size(); ++v) {
        if (visited[v] == 0) {
            hasCycles = DFS(G, v, visited, redStack, order);
            if (hasCycles) {
                cout << "the graph contains cyles ...";
                return;
            }
        }
    }

    printTopologicalOrder(order);
}

void addEdge(Graph &G, int src, int dest) {
    G[src].push_back(dest);
}

int main() {
    Graph G(8);
    
    addEdge(G, 0, 6);

    addEdge(G, 1, 2);
    addEdge(G, 1, 4);
    addEdge(G, 1, 6);

    addEdge(G, 3, 0);
    addEdge(G, 3, 4);

    addEdge(G, 5, 1);

    addEdge(G, 7, 0);
    addEdge(G, 7, 1);

    topologicalSorting(G);



    return 0;
}