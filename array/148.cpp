#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int r = n - 1;
    int l = 0;
    int mid = 0;
    
    for(; mid <= r; ) {
        if(nums[mid] == 0) {
            swap(nums[l], nums[mid]);
            ++l, ++mid;
        } else if(nums[mid] == 2) {
            swap(nums[mid], nums[r]);
            --r;
        } else
            ++mid;
    }
}

int main() {
    vector<int> nums{2, 0, 1, 2, 0, 1, 0};
    sortColors(nums);

    for(auto e: nums)
        cout<<e<<" ";

    return 0;
}