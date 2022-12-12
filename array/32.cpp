#include <bits/stdc++.h>

using namespace std;


int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> um;
    int index = 0, cont = 0;
    for(auto elem: nums) {
        auto pos = um.find(k + elem);
        auto neg = um.find(elem + (-1*k));
        if(pos != um.end() || neg != um.end()) {
            if(pos != um.end())
                cont += pos->second;
            if(neg != um.end())
                cont += neg->second;
        }
        um[elem]++;
    }
    return cont;
}


int main() {
    vector<int> nums = {3,2,1,5,4};
    int k = 2;
    cout<<countKDifference(nums, k);

    return 0;
}