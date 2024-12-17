#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

bool topologicalSort(const Graph &G, vector<int> inDegree, vector<int> &order) {
    queue<int> q;

    for(int i = 0; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        auto v = q.front();
        q.pop();

        order.push_back(v);

        for(const auto& u: G[v]) {
            inDegree[u]--;
            if(inDegree[u] == 0)
                q.push(u);
        }
    }


    return accumulate(inDegree.begin(), inDegree.end(), 0) == 0;
}

void createListAdj(Graph &G, int source, int dest) {
    G[source].push_back(dest);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    Graph G(numCourses);
    vector<int> answer;
    vector<int> inDegree(numCourses, 0);

    for(const auto& item: prerequisites) {
        createListAdj(G, item[1], item[0]);
        inDegree[item[0]]++;
    }

    if(topologicalSort(G, inDegree, answer))
        return answer;

    return {};
}

int main() {
    int numCourses = 2;
    vector<vector<int>> p = {{1, 0}};

    for(const auto& e: findOrder(numCourses, p))
        cout<<e<<" ";


    return 0;
}