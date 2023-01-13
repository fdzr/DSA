#include <bits/stdc++.h>

using namespace std;

    using vi = vector<int>;
    using vvi = vector<vi>;
    using um = unordered_map<int, int>;

    int findCenter(vector<vector<int>>& edges) {
        um inDegree, outDegree;

        for(auto edge: edges) {
            outDegree[edge[0]]++;
            outDegree[edge[1]]++;
            inDegree[edge[1]]++;
            inDegree[edge[0]]++;
        }

        int n = inDegree.size();
        int ans;
        for(auto & [key, value]: inDegree) {
            if(value == n-1) {
                ans = key;
                break;
            }
        }

        return ans;
    }

int main() {
    vvi edges = {{1,2},{5,1},{1,3},{1,4}};
    cout<<findCenter(edges);

    return 0;
}