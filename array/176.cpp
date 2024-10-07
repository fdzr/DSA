#include <bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int R = nums.size() - 1;
    int L = 0;

    while(L <= R) {
        if(nums[L] % 2 == 0) {
            ++L;
            continue;
        }
        if(nums[R] % 2) {
            --R;
            continue;
        }

        swap(nums[L], nums[R]);
        ++L, --R;
    }
    

    return nums;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    sortArrayByParity(nums);
    for(const auto &elem: nums)
        cout<< elem<< " ";

    return 0;
}