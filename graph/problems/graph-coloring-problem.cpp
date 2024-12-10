#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
#define COLOR 3

bool isSafe(Graph &G, vector<int> colors, int v, int color) {
    for (const auto &elem : G[v])
        if (color == colors[elem]) return false;

    return true;
}

bool graphColoringUtil(Graph &G, vector<int> &colors, int v, int index) {
    if (index == G.size()) {
        return true;
    }

    for (int c = 1; c <= COLOR; ++c) {
        if (isSafe(G, colors, v, c)) {
            colors[v] = c;
            if (graphColoringUtil(G, colors, v + 1, index + 1) == true) return true;

            colors[v] = 0;
        }
    }

    return false;
}

bool graphColoring(Graph &G) {
    vector<int> colors(G.size(), 0);

    return graphColoringUtil(G, colors, 0, 0);
}

int main() {
    Graph G(5);
    G[0] = {2, 3};
    G[1] = {3, 4};
    G[2] = {0, 3, 4};
    G[3] = {0, 1, 2, 3};
    G[4] = {1, 2, 3};

    cout << boolalpha << graphColoring(G);

    return 0;
}