//
// Created by fzamora on 02-02-23.
//
#include "bits/stdc++.h"

using namespace std;

int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> us(nums.begin(), nums.end());
    while(us.find(original) != us.end())
        original *= 2;

    return original;
}

int main() {
    vector<int> nums = {2,7,9};
    cout<<findFinalValue(nums, 4);

    return 0;
}