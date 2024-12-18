#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool isSafe(const Graph &G, int color, vector<int> colors, int source) {
    for (const auto &v : G[source])
        if (colors[v] == color) return false;

    return true;
}

bool dfs(Graph &G, int source, vector<int> &color, int COLOR) {
    color[source] = COLOR;

    for (const auto &v : G[source]) {
        if (color[v] == 0) {
            if (dfs(G, v, color, -COLOR) == false) return false;
        } else if (color[v] == COLOR)
            return false;
    }

    return true;
}


bool isBipartite(vector<vector<int>> &graph) {
    vector<int> color(graph.size(), 0);
    int COLOR = 1;

    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            if (dfs(graph, i, color, COLOR) == false) return false;
        }
    }

    return true;
}

int main() {
    Graph graph = {{1,2,3}, {0, 2}, {0,1,3}, {0, 2}};    
    // Graph graph = {{4, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 0}};
    cout<< boolalpha << isBipartite(graph);
    
     return 0;
}