#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(Graph &G, int source, vector<int> &visited, vector<int> &desc, vector<int> &low,
         stack<int> &st, vector<int> &redStack, int &time) {
    visited[source] = 1;
    redStack[source] = 1;
    st.push(source);
    desc[source] = low[source] = ++time;

    for (const auto &v : G[source]) {
        if (visited[v] == 0) {
            DFS(G, v, visited, desc, low, st, redStack, time);
            low[source] = min(low[v], low[source]);
        } else if (redStack[v] == 1) {
            low[source] = min(low[source], desc[v]);
        }
    }

    int w = 0;
    if (low[source] == desc[source]) {
        while (st.top() != source) {
            w = st.top();
            st.pop();
            cout << w << " ";
            redStack[w] = 0;
        }

        w = st.top();
        st.pop();
        cout << w << "\n";
        redStack[w] = 0;
    }
}

void SCC(Graph &G) {
    vector<int> desc(G.size(), 0);
    vector<int> low(G.size(), 0);
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);
    stack<int> st;
    int time = 0;

    for (int i = 0; i < G.size(); ++i)
        if (visited[i] == 0) DFS(G, i, visited, desc, low, st, redStack, time);
}

void addEdge(Graph &G, int src, int dest) { G[src].push_back(dest); }

int main() {
    Graph G(10);

    addEdge(G, 0, 1);

    addEdge(G, 1, 2);
    addEdge(G, 1, 3);

    addEdge(G, 2, 0);

    addEdge(G, 3, 4);

    addEdge(G, 4, 5);

    addEdge(G, 5, 4);

    addEdge(G, 6, 4);
    addEdge(G, 6, 7);

    addEdge(G, 7, 5);
    addEdge(G, 7, 9);

    addEdge(G, 8, 6);
    addEdge(G, 8, 7);

    addEdge(G, 9, 8);

    SCC(G);

    return 0;
}