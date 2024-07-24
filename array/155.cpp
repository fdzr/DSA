#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int L = 0, R = nums.size() - 1;

    while(L <= R) {
        int mid = L + (R - L) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[mid] < target)
            L = mid + 1;
        else
            R = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout<<search(nums, target);

    return 0;
}