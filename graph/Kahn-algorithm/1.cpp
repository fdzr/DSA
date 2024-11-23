#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void topologicalSort(const Graph &G, vector<int> &inDegree) {
    queue<int> S;
    vector<int> L;

    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0)
            S.push(i);
    }

    while (!S.empty()) {
        int u = S.front();
        S.pop();

        L.push_back(u);

        for (const auto &v : G[u]) {
            --inDegree[v];

            if (inDegree[v] == 0)
                S.push(v);
        }
    }

    for (const auto &elem : L)
        cout << elem << " ";

    cout<<"\n";
}

bool hasCycle(const vector<int> &inDegree) {
    return accumulate(inDegree.begin(), inDegree.end(), 0) != 0;
}

void addEdge(Graph &G, int src, int dest, vector<int> &inDegree) {
    G[src].push_back(dest);
    inDegree[dest]++;
}

int main() {
    Graph G(8);
    vector<int> inDegree(8, 0);

    addEdge(G, 0, 6, inDegree);

    addEdge(G, 1, 2, inDegree);
    addEdge(G, 1, 4, inDegree);
    addEdge(G, 1, 6, inDegree);

    addEdge(G, 3, 0, inDegree);
    addEdge(G, 3, 4, inDegree);

    addEdge(G, 5, 1, inDegree);

    addEdge(G, 7, 0, inDegree);
    addEdge(G, 7, 1, inDegree);

    topologicalSort(G, inDegree);

    cout << boolalpha << "has Cycle?: " << hasCycle(inDegree);

    return 0;
}