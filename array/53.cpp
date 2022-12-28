//
// Created by fzamora on 28-12-22.
//

#include <bits/stdc++.h>

using namespace std;

bool divideArray(vector<int>& nums) {
    vector<int> ans(501, 0);
    for(auto elem: nums)
        ans[elem]++;

    int cont_pair = 0;
    int cont;
    for(auto elem: ans) {
        if(elem != 0 && elem % 2 != 0)
            return false;
    }
    return true;
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout<<divideArray(nums);

    return 0;
}