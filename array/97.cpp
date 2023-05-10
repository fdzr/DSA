//
// Created by fzamora on 10-05-23.
//
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int helper(vi aux, int index) {
    int sum_left = 0;
    int sum_right = 0;
    for(int i = 0; i < index; ++i)
        sum_left += aux[i];
    for(int i = index+1; i < aux.size(); ++i)
        sum_right += aux[i];

    return abs(sum_left - sum_right);
}


vector<int> leftRigthDifference(vector<int> nums) {
    vi ans(nums.size());
    for(int i = 0; i < nums.size(); ++i)
        ans[i] = helper(nums, i);

    return ans;
}

int main() {
    vi nums = {1};
    for(auto elem: leftRigthDifference(nums))
        cout<<elem<<" ";

    return 0;
}