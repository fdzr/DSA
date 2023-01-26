//
// Created by fzamora on 25-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using pi = pair<int, int>;
using vpi = vector<pi>;
using um = unordered_map<int, int>;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    um inDegree;
    for(auto connection: roads) {
        inDegree[connection[0]]++;
        inDegree[connection[1]]++;
    }

    vpi In(inDegree.begin(), inDegree.end());
    sort(In.begin(), In.end(), [](pi a, pi b){
        return a.second > b.second;
    });

    vector<int> importance(n);
    for(auto item: In) {
        importance[item.first] = n--;
    }


    int sum = 0;
    for(auto connection: roads)
        sum+= importance[connection[0]] + importance[connection[1]];

    return sum;
}

int main() {
    vector<vector<int>> roads = {{1,2},{0,2},{3,4},{3,5}};
    cout<<maximumImportance(6, roads);

    return 0;
}