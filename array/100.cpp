#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/left-and-right-sum-differences/description/

using vi = vector<int>;
vector<int> leftRigthDifference(vector<int>& nums) {
    vi leftSum(nums.size()), rightSum(nums.size());

    int sumPreffix = 0;
    for(int i {1}; i < nums.size() - 1; ++i) {
        sumPreffix += nums[i];
        rightSum[i - 1] = sumPreffix;
    }

    return rightSum;
}


int main() {
    vi nums = {10,4,8,3};
    for(auto e: leftRigthDifference(nums))
        cout<<e<<" ";

    

    return 0;
}