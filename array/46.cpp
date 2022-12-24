#include <bits/stdc++.h>

using namespace std;


int minOperations(vector<int>& nums) {
    int cont = 0;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] <= nums[i - 1]) {
            cont += (nums[i - 1] - nums[i] + 1);
            nums[i] += nums[i - 1] - nums[i] + 1;
        }


    }
    return cont;
}


int main() {
    vector<int> nums = {8};
    cout<<minOperations(nums);


    return 0;
}