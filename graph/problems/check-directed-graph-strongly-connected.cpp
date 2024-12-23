#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void tarjanAlgorthm(const Graph &G, int source, vector<int> &visited, vector<int> &redstack,
                    vector<int> &desc, vector<int> &low, stack<int> &st, int time,
                    vector<vector<int>> &sccs) {
    desc[source] = low[source] = ++time;
    visited[source] = 1;
    redstack[source] = 1;
    st.push(source);

    for (const auto &v : G[source]) {
        if (visited[v] == 0) {
            tarjanAlgorthm(G, v, visited, redstack, desc, low, st, time, sccs);
            low[source] = min(low[v], low[source]);
        } else if (redstack[v] == 1) {
            low[source] = min(low[source], desc[v]);
        }
    }

    int w = 0;
    vector<int> scc;
    if (desc[source] == low[source]) {
        while (st.top() != source) {
            w = st.top();
            st.pop();
            scc.push_back(w);
        }

        w = st.top();
        st.pop();
        scc.push_back(w);
        sccs.push_back(scc);
        redstack[source] = 0;
    }
}

void addEdge(Graph &G, int source, int dest) { G[source].push_back(dest); }

bool isStronglyConnected(const Graph &G) {
    vector<int> visited(G.size(), 0);
    vector<int> redStack(G.size(), 0);
    vector<int> desc(G.size(), 0);
    vector<int> low(G.size(), 0);
    stack<int> st;
    int time = 0;
    vector<vector<int>> sol;

    for (int i = 0; i < G.size(); ++i) {
        if (visited[i] == 0) {
            tarjanAlgorthm(G, i, visited, redStack, desc, low, st, time, sol);
        }
    }

    return sol.size() == 1;
}

int main() {
    Graph G(5);
    addEdge(G, 0, 4);
    addEdge(G, 1, 0);
    addEdge(G, 1, 2);
    addEdge(G, 2, 1);
    addEdge(G, 2, 4);
    addEdge(G, 3, 1);
    addEdge(G, 3, 2);
    addEdge(G, 4, 3);

    cout<< boolalpha << isStronglyConnected(G);

    return 0;
}