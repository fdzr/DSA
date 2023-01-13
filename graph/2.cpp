#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using um = unordered_map<int, vi>;

void loadGraph(vvi edges, um &graph) {
    for(auto item: edges) {
        graph[item[0]].push_back(item[1]);
        graph[item[1]].push_back(item[0]);
    }
        
}


bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if(source == destination)
        return true;

    bool flag = false;
    um graph;
    loadGraph(edges, graph);
    vi visited(n, 0);
    queue<vi> cola;
    cola.push(graph[source]);
    visited[source] = 1;

    while(!cola.empty()) {
        auto vertices = cola.front();
        cola.pop();

        for(auto vertex: vertices) {
            if(!visited[vertex]) {
                cola.push(graph[vertex]);
                visited[vertex] = 1;
                if(vertex == destination) {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
            break;
    }

    return flag;
}


int main() {
    vvi edges = {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
    int source = 7;
    int destination = 5;
    int n = 10;

    cout<<validPath(n, edges, source, destination);

    return 0;
}