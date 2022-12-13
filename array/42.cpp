#include <bits/stdc++.h>

using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    map<int, int> m;
    for(auto elem: nums)
        m[elem]++;
    
    vector<pair<int, int>> tmp;
    vector<int> ans;
    for(auto item: m)
        tmp.push_back(item);

    sort(tmp.begin(), tmp.end(), [](auto a, auto b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    });

    for(auto item: tmp) {
        vector<int> aux (item.second, item.first);
        ans.insert(ans.end(), aux.begin(), aux.end());
    }

    return ans;
}

int main() {
    vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};
    for(auto e: frequencySort(nums))
        cout<<e<<" ";

    return 0;
}