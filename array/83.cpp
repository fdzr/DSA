#include <bits/stdc++.h>

using namespace std;

int helper(int num) {
    int sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int differenceOfSum(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int sumDigits = 0;
    for(auto elem: nums)
        sumDigits += helper(elem);

    return abs(sum - sumDigits);
}

int main() {
    vector<int> nums = {1,2, 3,4};
    cout<<differenceOfSum(nums);

    return 0;
}