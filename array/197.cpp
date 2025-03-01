#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int L = 0, R = 1;

    while(R < nums.size()) {
        if(nums[L] != 0) {
            ++L;
            R = L + 1;
            continue;
        }
        if(nums[R] != 0) {
            swap(nums[L], nums[R]);
            ++L;
            ++R;
        } else {
            ++R;
        }
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    for(const int &e: nums) printf("%d ", e);


    return 0;
}