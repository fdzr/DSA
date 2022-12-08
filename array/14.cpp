// Boyer Moore majority vote algorithm

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
    int num = 0, count = 0;
    for(auto x: nums) {
        if(count == 0)
            num = x;

        count += (num == x)? 1: -1;
    }

    count = 0;
    for(auto x: nums) {
        if(x == num)
            count++;
    }

    if(count > nums.size()/2)
        return num;

    return -1;
}


int main() {
    vector<int> v = {3,2,3};
    cout<<majorityElement(v);

    return 0;
}

