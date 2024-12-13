#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

void DFS(Matrix<int> &G, vector<int> &visited, int source, int k, int time, int &cont,
         int dest) {
    if (time == k && source == dest) {
        ++cont;
        return;
    }

    visited[source] = 1;

    for (int v = 0; v < G[source].size(); ++v) {
        if (visited[v] == 0 && G[source][v] == 1)
            DFS(G, visited, v, k, time + 1, cont, dest);
    }

    visited[source] = 0;
}

int possibleWalks(Matrix<int> &G, int k, int source, int dest) {
    vector<int> visited(G.size(), 0);
    int time = 0;
    int cont = 0;

    DFS(G, visited, source, k, time, cont, dest);

    return cont;
}

int main() {
    Matrix<int> G = {{0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};

    cout << possibleWalks(G, 2, 0, 3);

    return 0;
}