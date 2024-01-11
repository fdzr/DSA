#include <bits/stdc++.h>

using namespace std;


vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == target)
            ans.push_back(i);
    }

    return ans;
}

vector<int> targetIndices_2(vector<int> nums, int target) {
    int cnt = 0, rnk = 0;
    vector<int> ans;

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] < target)
            rnk++;
        if(nums[i] == target)
            cnt++;
    }


    for(int i =0, j = 0; i < cnt; ++i){
        ans.push_back(rnk + j);
        j++;
    }

    return ans;

}



int main() {
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    for(auto e: targetIndices_2(nums, target))
        cout<<e<<" ";

    return 0;
}