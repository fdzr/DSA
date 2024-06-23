#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    set<int> bagNums;
    int duplicatedNum;
    for(auto value: nums) {
        if(bagNums.contains(value)) {
            duplicatedNum = value;
            break;
        } else {
            bagNums.insert(value);
        }
    }

    return duplicatedNum;
}

int main() {
    vector<int> nums = {2,3,4,2,1};
    cout<<findDuplicate(nums);


    return 0;
}