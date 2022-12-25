#include <bits/stdc++.h>

using namespace std;

int repeatedNTimes(vector<int>& nums) {
    int cont = 0;
    int i;
    unordered_map<int, int> um;

    for(i = 0; i < nums.size(); ++i) {
        if(um.find(nums[i]) != um.end())
            break;
        um[nums[i]]++;
    }

    return nums[i];
    
}

int main(){
    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout<<repeatedNTimes(nums);

    return 0;
}