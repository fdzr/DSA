//
// Created by fzamora on 27-12-22.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> um;

    for(auto str: strs) {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        um[tmp].push_back(str);
    }

    for(auto &[k, v]: um)
        ans.push_back(v);

    return ans;
}


int main() {
    vector<string> strs = {"a"};
    for(auto vec: groupAnagrams(strs)) {
        for(auto elem: vec) {
            cout<<elem<<" ";
        }
        cout<<endl;
    }

    return 0;
}