#include <bits/stdc++.h>

using namespace std;

using um = unordered_map<int, unordered_set<int>>;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    if(roads.size() == 0)
        return 0;

    um listAdj;
    unordered_map<int, int> inDegree;
    for(auto edge: roads){
        inDegree[edge[0]]++;
        inDegree[edge[1]]++;

        listAdj[edge[0]].insert(edge[1]);
        listAdj[edge[1]].insert(edge[0]);
    }

    int sum = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i+1; j < n; ++j){
            int count = inDegree[i] + inDegree[j];
            int flag = listAdj[i].count(j);
            count -= flag;     

            if(count > sum)
                sum = count;
        }
    }

    return sum;
}

int main() {
    vector<vector<int>> roads = {{2,3},{0,3},{0,4},{4,1}};
    cout<<maximalNetworkRank(8, roads);


    return 0;
}