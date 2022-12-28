//
// Created by fzamora on 28-12-22.
//

#include <bits/stdc++.h>

using namespace std;

void helper(vector<int> nums, unordered_map<int, int> &um) {
    unordered_set<int> s(nums.begin(), nums.end());
    for(auto elem: s)
        um[elem]++;
}

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    unordered_map<int, int> um;
    vector<int> ans;

    helper(nums1, um);
    helper(nums2, um);
    helper(nums3, um);

    for(auto & [k, v]: um)
        if(v >= 2)
            ans.push_back(k);

    return ans;
}

int main() {
    vector<int> nums1 = {1,2,2}, nums2 = {4,3,3}, nums3 = {5};
    for(auto elem: twoOutOfThree(nums1, nums2, nums3))
        cout<<elem<<" ";
    return 0;
}