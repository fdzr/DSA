//
// Created by fzamora on 17-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using vi = vector<int>;

vector<int> minSubsequence(vector<int>& nums) {
    vi ans;
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int sumRange = 0;

    for(int i = 0; i < nums.size(); ++i) {
        if(sumRange + nums[i] <= sum - nums[i]) {
            ans.push_back(nums[i]);
            sumRange += nums[i];
            sum -= nums[i];
        }
        else {
            ans.push_back(nums[i]);
            break;
        }
    }
    return ans;
}

int main() {
    vi nums = {1,1,1,1,2};
    for(auto elem: minSubsequence(nums))
        cout<<elem<<" ";

    return 0;
}