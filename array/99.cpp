#include <bits/stdc++.h>

// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

using namespace std;

bool canBeIncreasing(vector<int>& nums) {
    vector<int> indexes;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] <= nums[i - 1]) {
            indexes.push_back(i - 1);
            i += 2;
        }
    }

    if(indexes.empty())
        return true;
    if(indexes.size() > 1)
        return false;
    else {
        int index = indexes.back();
        if(index + 1 == nums.size()) {
            return true;
        }
        else {
            if(nums[index - 1] < nums[index + 1])
                return true;
            else
                return false;
        }
    }
}

int main() {
    vector<int> nums = {1,1,1};
    cout<< canBeIncreasing(nums);

    return 0;
}