#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using Graph = vector<vector<pi>>;

void printDest(vector<int> &dest, int source) {
    for (int i = 0; i < dest.size(); ++i) {
        if (i == source)
            continue;

        cout << "(" << source << ", " << i << ") = ";
        (dest[i] == INT_MAX) ? cout << "INF" << "\n" : cout << dest[i] << "\n";
    }
}

vector<int> topologicalSort(Graph &G, vector<int> &inDegree) {
    queue<int> q;
    vector<int> order;

    for (int i = 0; i < inDegree.size(); ++i)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v);

        for (const auto &edge : G[v]) {
            --inDegree[edge.first];
            if (inDegree[edge.first] == 0)
                q.push(edge.first);
        }
    }

    return order;
}

void shortestPathDAG(Graph &G, int source, vector<int> &inDegree) {
    vector<int> order = topologicalSort(G, inDegree);
    vector<int> dest(G.size(), INT_MAX);
    dest[source] = 0;

    for (int i = 0; i < order.size(); ++i) {
        for(const auto &edge: G[order[i]]) {
            if(dest[edge.first] > dest[order[i]] + edge.second)
                dest[edge.first] = dest[order[i]] + edge.second;
        }
    }

    printDest(dest, source);
}

void addEdge(Graph &G, int src, int dest, int w, vector<int> &inDegree) {
    G[src].push_back({dest, w});
    ++inDegree[dest];
}

int main() {
    Graph G(8);
    vector<int> inDegree(8, 0);

    addEdge(G, 0, 6, 2, inDegree);

    addEdge(G, 1, 2, -4, inDegree);
    addEdge(G, 1, 4, 1, inDegree);
    addEdge(G, 1, 6, 8, inDegree);

    addEdge(G, 3, 0, 3, inDegree);
    addEdge(G, 3, 4, 5, inDegree);

    addEdge(G, 5, 1, 2, inDegree);

    addEdge(G, 7, 0, 6, inDegree);
    addEdge(G, 7, 1, -1, inDegree);
    addEdge(G, 7, 3, 4, inDegree);
    addEdge(G, 7, 5, -4, inDegree);

    shortestPathDAG(G, 7, inDegree);

    return 0;
}