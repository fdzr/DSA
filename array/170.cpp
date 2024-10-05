#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(const auto & elem: nums)
        sum += elem;

    return n*(n+1)/2 - sum;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums);


    return 0;
}