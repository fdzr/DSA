#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void loadGraph(vvi edges, vvi &graph) {
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }


}

int findJudge(int n, vector<vector<int>>& trust) {
    if(trust.size() == 0) {
        if(n == 1)
            return n;
        else
            return -1;
    }

    vvi graph(n+1);
    loadGraph(trust, graph);
    int ans = -1;
    
    for(int i = 1; i < graph.size(); ++i) {
        if(graph[i].size() == 0) {
            ans = i;
        }
    }

    if(ans == -1)
        return -1;

    bool flag = false;

    for(int j = 1; j < graph.size(); ++j) {
        if(j == ans)
            continue;

        if(find(graph[j].begin(), graph[j].end(), ans) == graph[j].end()) {
            flag = true;
            break;
        }
    }
        
    return !flag? ans: -1;
}

int main() {
    vvi trust = {{1,2},{2,3}};
    int n = 3;
    cout<<findJudge(n, trust);


    return 0;
}