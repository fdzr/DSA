#include <bits/stdc++.h>

using namespace std;

using um = unordered_map<int, int>;


int minCostToMoveChips(vector<int>& position) {
    
    um ans;

    for(auto elem: position)
        ans[elem]++;
    
    int odd = 0, even = 0;

    for(auto elem: ans) {
        if(elem.first % 2 == 0)
            even += elem.second;
        else
            odd += elem.second;
    }

    return (even > odd)? odd: even;
}


int main() {
    vector<int> positions = {1};
    cout<<minCostToMoveChips(positions);

    return 0;
}