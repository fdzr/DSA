#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    int max_1 = INT_MIN, max_2 = INT_MIN;

    for(auto elem: nums) {
        if(elem >= max_1) {
            max_2 = max_1;
            max_1 = elem;
        }
        if( elem >= max_2 && elem < max_1)
            max_2 = elem;
    }

    return (max_1 - 1) * (max_2 - 1);
}



int main() {
    vector<int> nums = {3,7};
    cout<<maxProduct(nums);


    return 0;
}