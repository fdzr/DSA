#include <bits/stdc++.h>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = 0;
    for(auto acc: accounts) {
        int money  = reduce(acc.begin(), acc.end());
        maxWealth = max(maxWealth, money);
    }

    return maxWealth;
        
}

int main() {
    vector<vector<int>> vc = {{2,8,7},
                              {7,1,3},
                              {1,9,5}};
    cout<<maximumWealth(vc);
    return 0;
}