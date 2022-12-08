#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    vector<int> ans;
    
    set_intersection(s1.begin(), s1.end(),
                     s2.begin(), s2.end(),
                     back_inserter(ans));


    
    return ans;
}

int main() {
    vector<int> v1 = {1,2,2,1};
    vector<int> v2 = {2,2};

    vector<int> ans = intersection(v1, v2);

    for(auto a: ans)
        cout<<a<<" ";

    return 0;
}