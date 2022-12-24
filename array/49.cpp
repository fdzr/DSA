#include <bits/stdc++.h>

using namespace std;


int arrayPairSum(vector<int>& nums) {
    int cont = 0;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 1; i+=2) {
        cont += min(nums[i], nums[i+1]);

    }
    return cont;
}


int main() {
    vector<int> nums = {6,2,6,5,-5,-4};
    cout<<arrayPairSum(nums);

    return 0;
}