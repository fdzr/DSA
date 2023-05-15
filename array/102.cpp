#include <bits/stdc++.h>

using namespace std;

int maximizeSum(vector<int>& nums, int k) {
    int largestNumber = -1;
    int sum = 0;

    for(auto elem: nums) {
        if(elem > largestNumber)
            largestNumber = elem;
    }

    sum +=largestNumber;

    while(--k) {
        sum += largestNumber + 1;
        largestNumber++;
    }

    return sum;
}

int main() {
    vector<int> nums = {5,5,5};
    int k = 2;

    cout<<maximizeSum(nums, k);

    return 0;
}