#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp1, mp2;
    vector<int> ans;

    for(auto a: nums1)
        mp1[a]++;

    for(auto a: nums2)
        mp2[a]++;

    for(auto const& [key, val] : mp1) {
        auto tmp = mp2.find(key);
        auto end = mp2.end(); 
        if(tmp != end) {
            int cant = min(tmp->second, val);
            for(int i =0;i<cant;++i)
                ans.push_back(key);
        }
    }
    return ans;
}


int main() {
    vector<int> v1 = {4,9,5};
    vector<int> v2 = {9,4,9,8,4};

    vector<int> ans = intersect(v1, v2);
    for(auto a: ans)
        cout<<a<<" ";

    return 0;
}