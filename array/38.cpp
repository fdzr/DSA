#include <bits/stdc++.h>

using namespace std;

int countPairs(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> um;
    int cont = 0;
    for(int i =0; i < nums.size(); ++i) {
        int elem = nums[i];
        auto ptr = um.find(elem);
        if(ptr != um.end()) {
            for(auto index: ptr->second)
                cont += !((i * index ) % k)? 1: 0;
        }
        um[elem].push_back(i);

    }
    return cont;
}


int main() {
    vector<int> nums {5,5,9,2,5,5,9,2,2,5,5,6,2,2,5,2,5,4,3};
    int k = 7;

    cout<<countPairs(nums, k);

    return 0;
}