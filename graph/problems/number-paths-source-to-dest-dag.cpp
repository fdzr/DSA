#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool topologicalSorting(Graph &G, vector<int> &visited, vector<int> &redStack, int source, stack<int> &ts) {
    visited[source] = 1;
    redStack[source] = 1;

    for (int i = 0; i < G[source].size(); ++i) {
        if (visited[G[source][i]] == 0 && topologicalSorting(G, visited, redStack, G[source][i], ts) == true)
            return true;
        else if (redStack[G[source][i]] == 1)
            return true;
    }

    redStack[source] = 0;
    ts.push(source);
    return false;
}

int numberPathSourceDestDAG(Graph &G, int source, int dest) {
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);
    stack<int> ts;
    vector<int> numberWays(G.size(), 0);
    numberWays[source] = 1;

    for (int v = 0; v < G.size(); ++v) {
        if (visited[v] == 0) {
            bool validTopologicalSorting = topologicalSorting(G, visited, redStack, v, ts);

            if (validTopologicalSorting) {
                cout<< "cycle detected ...";
                return -1;
            }
        }
    }

    while (!ts.empty()) {
        int v = ts.top();
        ts.pop();

        for (int i = 0; i < G[v].size(); ++i) {
            numberWays[G[v][i]] += numberWays[v];
        }
    }

    return numberWays[dest];
}

void addEdge(Graph &G, int src, int dest) {
    G[src].push_back(dest);
}

int main() {
    // Graph G(8);

    // addEdge(G, 0, 6);

    // addEdge(G, 1, 2);
    // addEdge(G, 1, 4);
    // addEdge(G, 1, 6);

    // addEdge(G, 3, 0);
    // addEdge(G, 3, 4);

    // addEdge(G, 5, 1);

    // addEdge(G, 7, 0);
    // addEdge(G, 7, 1);
    // addEdge(G, 7, 3);
    // addEdge(G, 7, 5);

    // cout<<numberPathSourceDestDAG(G, 7, 2);

    Graph G(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 3);
    addEdge(G, 0, 4);


    addEdge(G, 2, 3);

    addEdge(G, 3, 4);

    cout<< numberPathSourceDestDAG(G, 0, 4);


    return 0;
}