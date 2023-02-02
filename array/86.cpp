//
// Created by fzamora on 02-02-23.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> st1, st2;
    vector<int> ans1, ans2;
    for(auto elem: nums1) st1[elem]++;
    for(auto elem: nums2) st2[elem]++;

    for(auto elem: st1) {
        if(st2.find(elem.first) == st2.end())
            ans1.push_back(elem.first);
    }

    for(auto elem: st2) {
        if(st1.find(elem.first) == st1.end())
            ans2.push_back(elem.first);
    }

    return {ans1, ans2};
}

int main() {
    vector<int> nums1 = {1,2,3,3};
    vector<int> nums2 = {1,1,2,2};

    for(auto v: findDifference(nums1, nums2)) {
        for(auto elem: v)
            cout<<elem<<" ";
        cout<<endl;
    }


    return 0;
}