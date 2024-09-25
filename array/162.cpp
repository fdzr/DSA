#include <bits/stdc++.h>

using namespace std;


int search(vector<int>& nums, int target) {
    int L = 0, R = nums.size() - 1;

    while(L <= R) {
        int M = L + (R - L) / 2;

        if(nums[M] == target)
            return M;

        if(nums[L] <= nums[M]) {
            if(target >= nums[L] && target <= nums[M])
                R = M - 1;
            else
                L = M + 1;
        } else {
            if(target >= nums[M] && target <= nums[R])
                L = M + 1;
            else
                R = M - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1};
    int target = 0;
    cout<<search(nums, target);

    return 0;
}