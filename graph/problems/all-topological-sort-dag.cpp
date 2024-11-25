#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void allTopologicalSort(Graph &G, vector<int> &visited, vector<int> &inDegree, vector<int> &order) {
    bool completeExecution = true;

    for (int v = 0; v < G.size(); ++v) {
        if (visited[v] == 0 && inDegree[v] == 0) {
            visited[v] = 1;
            order.push_back(v);

            for (const auto &u : G[v]) {
                --inDegree[u];
            }

            allTopologicalSort(G, visited, inDegree, order);

            visited[v] = 0;
            order.pop_back();
            for (const auto &u : G[v]) {
                ++inDegree[u];
            }

            completeExecution = false;
        }
    }

    if (completeExecution) {
        for (const auto &elem : order)
            cout << elem << " ";

        cout << "\n";
    }
}

void topologicalUtil(Graph &G, vector<int> &inDegree) {
    vector<int> visited(G.size(), 0);
    vector<int> order;

    allTopologicalSort(G, visited, inDegree, order);
}

void addEdge(Graph &G, int src, int dest, vector<int> &inDegree) {
    G[src].push_back(dest);
    ++inDegree[dest];
}

int main() {
    Graph G(6);
    vector<int> inDegree(6, 0);

    addEdge(G, 5, 2, inDegree);
    addEdge(G, 5, 0, inDegree);
    addEdge(G, 4, 0, inDegree);
    addEdge(G, 4, 1, inDegree);
    addEdge(G, 2, 3, inDegree);
    addEdge(G, 3, 1, inDegree);

    topologicalUtil(G, inDegree);


    return 0;
}
