//
// Created by fzamora on 30-12-22.
//

#include "bits/stdc++.h"

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


void DFS(vvi graph, int vertex, vi &nodesReached, vvi &ans) {
    if(vertex == graph.size() - 1) {
        ans.push_back(nodesReached);
        return;
    }
    else{
        for(auto v: graph[vertex]) {
            nodesReached.push_back(v);
            DFS(graph, v, nodesReached, ans);
            nodesReached.pop_back();
        }
    }
}


vvi allPathsSourceTarget(vvi& graph) {
    vvi ans;
    vi nodesReached;
    nodesReached.push_back(0);
    DFS(graph, 0, nodesReached, ans);

    for(auto answers: ans) {
        for(auto elem: answers)
            cout<<elem<<" ";
        cout<<endl;
    }

    return ans;
}


int main() {
    vvi graph = {{1,2},{3},{3},{}};
    allPathsSourceTarget(graph);

    return 0;
}