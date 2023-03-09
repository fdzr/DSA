#include <bits/stdc++.h>

// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vi> um;
    vvi ans;
    for(int i = 0; i < groupSizes.size(); ++i)
        um[groupSizes[i]].push_back(i);

    for(auto [sizeGroup, group]: um) {
        if(sizeGroup == group.size())
            ans.push_back(group);
        else {
            int cant = group.size() / sizeGroup;
            auto start = group.begin();
            while(cant--) {
                ans.push_back(vi(start, start + sizeGroup));
                start += sizeGroup;
            }
        }
    }

    return ans;
}

int main() {
    vi groupSizes = {2,1,3,3,3,2};
    for(auto rows: groupThePeople(groupSizes)) {
        for(auto elem: rows)
            cout<<elem<<" ";
        cout<<endl;
    }

    return 0;
}