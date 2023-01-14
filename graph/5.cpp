#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vi inDegree(n);
    vi ans;
    for(auto edge: edges)
        inDegree[edge[1]]++;
    
    for(int i = 0; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0)
            ans.push_back(i);
    }

    return ans;
}

int main() {
    vvi edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    int n = 5;
    for(auto elem: findSmallestSetOfVertices(n, edges))
        cout<<elem<<" ";

    return 0;
}