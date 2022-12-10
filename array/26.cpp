#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0;i < nums.size(); i+=2) {
        vector<int> tmp(nums[i],nums[i+1]);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    return ans;
        
}


int main() {
    vector<int> vc = {1,2,3,4}, ans;
    ans = decompressRLElist(vc);
    cout<<ans;

    return 0;
}