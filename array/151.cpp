//
// Created by fzamora on 01-07-24.
//

#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int arr[32] = {0};

    for(int value: nums) {
        for(int i = 0; i < 32; ++i) {
            arr[i] += (value >> i) & 1;
        }
    }
    int num = 0;
    for(int i = 0; i < 32; ++i ) {
        if(arr[i] % 3 != 0) {
            num |= (1 << i);
        }
    }

    return num;
}

int main() {
    vector<int> nums = {2,2,2,1};
    cout<<singleNumber(nums);



    return 0;
}

