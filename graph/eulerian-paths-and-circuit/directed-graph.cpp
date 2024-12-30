#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(Graph &G, vector<int> &visited, int source, vector<int> &redStack,
         vector<int> &desc, vector<int> &low, vector<vector<int>> &scc, stack<int> &st,
         int time) {
    visited[source] = 1;
    low[source] = desc[source] = ++time;
    redStack[source] = 1;
    st.push(source);

    for (const auto &v : G[source]) {
        if (visited[v] == 0) {
            DFS(G, visited, v, redStack, desc, low, scc, st, time);
            low[source] = min(low[source], low[v]);
        } else if (redStack[v] == 1) {
            low[source] = min(low[source], desc[v]);
        }
    }

    int w = 0;
    vector<int> components;
    if (desc[source] == low[source]) {
        while (st.top() != source) {
            w = st.top();
            st.pop();
            components.push_back(w);
        }
        w = st.top();
        st.pop();
        components.push_back(w);
        scc.push_back(components);
        redStack[source] = 0;
    }
}

bool isStronglyConnected(Graph &G) {
    vector<int> desc(G.size(), 0);
    vector<int> low(G.size(), 0);
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);
    stack<int> st;
    vector<vector<int>> scc;
    int time = 0;

    int v;
    for (v = 0; v < G.size(); ++v)
        if (G[v].size() > 0) break;

    if (v == G.size()) return false;

    DFS(G, visited, v, redStack, desc, low, scc, st, time);

    return scc.size() == 1;
}

bool isEulerian(Graph &G, const vector<int> &inDegree) {
    if (isStronglyConnected(G) == false) return false;

    for (int i = 0; i < G.size(); ++i)
        if (G[i].size() != inDegree[i]) return false;

    return true;
}

void addEdge(Graph &G, int source, int dest, vector<int> &inDegree) {
    G[source].push_back(dest);
    inDegree[dest]++;
}

int main() {
    Graph G(5);
    vector<int> inDegree(5, 0);
    addEdge(G, 1, 0, inDegree);
    addEdge(G, 0, 2, inDegree);
    addEdge(G, 2, 1, inDegree);
    addEdge(G, 0, 3, inDegree);
    addEdge(G, 3, 4, inDegree);
    addEdge(G, 4, 0, inDegree);

    cout << boolalpha << isEulerian(G, inDegree);

    return 0;
}