#include <bits/stdc++.h>

using namespace std;


int maximumCount(vector<int>& nums) {
    int pos = 0;
    int neg = 0;
    for(auto num: nums) {
        if(num > 0)
            pos++;
        if(num < 0)
            neg++;
    }
    return max(pos, neg);
}

int main() {
    vector<int> nums = {-2,-1,-1,1,2,3};
    cout<<maximumCount(nums);


    return 0;
}