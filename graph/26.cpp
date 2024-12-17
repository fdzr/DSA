#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool topologicalSort(const Graph &G, vector<int> &inDegree) {
    queue<int> q;

    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (const auto &u : G[v]) {
            inDegree[u]--;
            if (inDegree[u] == 0) q.push(u);
        }
    }

    return accumulate(inDegree.begin(), inDegree.end(), 0) == 0;
}

void createListAdj(Graph &G, int source, int dest) { G[source].push_back(dest); }

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    Graph G(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (const auto &edge : prerequisites) {
        createListAdj(G, edge[1], edge[0]);
        inDegree[edge[0]]++;
    }

    return topologicalSort(G, inDegree);
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequesites = {{1, 0}, {0, 1}};

    cout << boolalpha << canFinish(numCourses, prerequesites);

    return 0;
}