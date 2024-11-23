#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void topologicalSort(const Graph &G, vector<int> &inDegree) {
    vector<int> S;
    vector<int> L;

    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0)
            S.push_back(i);
    }

    while (!S.empty()) {
        int u = S.back();
        S.pop_back();

        for (const auto &v : G[u]) {
            --inDegree[v];

            if(inDegree[v] == 0)
                S.push_back(v);
        }
    }
}

void addEdge(Graph &G, int src, int dest, vector<int> &inDegree) {
    G[src].push_back(dest);
    inDegree[dest]++;
}

int main() {
    return 0;
}