//
// Created by fzamora on 18-05-23.
//

#include "bits/stdc++.h"

using namespace std;

int minPairSum(vector<int>& nums) {
    int answer = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n / 2; ++i) {
        cout<<"["<<nums[i]<<","<<nums[n-i-1]<<"]"<<endl;
        answer = max(answer, nums[i] + nums[n - i - 1]);
    }

    return answer;
}

int main() {
    vector<int> nums = {3,5,2, 3};
    cout<<minPairSum(nums);

    return 0;
}