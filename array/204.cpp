#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
    int L = 0, R = nums.size() - 1;

    while (L < R) {
        int M = L + (R - L) / 2;

        if (nums[M] > nums[R]) {
            L = M + 1;
        } else {
            R = M;
        }
    }

    return nums[L];
}

int main() {
    vector<int> nums = {2, 1};
    int answer = findMin(nums);
    printf("%d", answer);

    return 0;
}