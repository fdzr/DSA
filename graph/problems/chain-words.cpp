#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
using vi = vector<int>;
using SCC = Graph;

pair<Graph, vi> createGraph(const vector<string> &words) {
    Graph g(26);
    vector<int> inDegree(26, 0);
    for (int i = 0; i < words.size(); ++i) {
        string str = words[i];
        g[str[0] - 'a'].push_back(str[str.size() - 1] - 'a');
        inDegree[str[str.size() - 1] - 'a']++;
    }

    return {g, inDegree};
}

void DFS(Graph &G, vi &visited, int source, vi &low, vi &desc, vi &redStack,
         stack<int> &st, SCC &scc, int time) {
    visited[source] = 1;
    redStack[source] = 1;
    st.push(source);
    low[source] = desc[source] = ++time;

    for (const auto &v : G[source]) {
        if (visited[v] == 0) {
            DFS(G, visited, v, low, desc, redStack, st, scc, time);
            low[source] = min(low[source], low[v]);
        } else if (redStack[v] == 1) {
            low[source] = min(low[source], desc[v]);
        }
    }

    int w = 0;
    vector<int> components;
    if (low[source] == desc[source]) {
        while (st.top() != source) {
            w = st.top();
            st.pop();
            components.push_back(w);
        }

        w = st.top();
        st.pop();
        components.push_back(w);
        redStack[source] = 0;
        scc.push_back(components);
    }
}

bool isStronglyConnected(Graph &G) {
    vi visited(G.size(), 0);
    vi redStack(G.size(), 0);
    vi low(G.size(), 0);
    vi desc(G.size(), 0);
    stack<int> st;
    SCC scc;
    int time = 0;

    int v;
    for (v = 0; v < G.size(); ++v) {
        if (G[v].size() > 0) break;
    }

    if (v == G.size()) return false;

    DFS(G, visited, v, low, desc, redStack, st, scc, time);

    for (int i = 0; i < visited.size(); ++i) {
        if (G[i].size() > 0 && visited[i] == 0) return false;
    }

    return scc.size() == 1;
}

bool isEulerian(const vector<string> &words) {
    pair<Graph, vi> items = createGraph(words);

    if (isStronglyConnected(items.first) == false) return false;

    for (int i = 0; i < items.first.size(); ++i) {
        if (items.first[i].size() != items.second[i]) return false;
    }

    return true;
}

int main() {
    vector<string> words = {"for", "geek", "rig", "kaf"};

    cout << boolalpha << isEulerian(words) << "\n";

    words = {"aab", "bac", "aaa", "cda"};
    bool answer = isEulerian(words);

    cout << boolalpha << answer << "\n";

    words = {"ijk", "kji", "abc", "cba"};
    answer = isEulerian(words);

    cout << boolalpha << answer << "\n";

    words = {"aaa", "bbb"};
    cout<< boolalpha << isEulerian(words)<<"\n";

    return 0;
}