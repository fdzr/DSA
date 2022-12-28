//
// Created by fzamora on 28-12-22.
//

#include "bits/stdc++.h"

using namespace std;

void helper(string s, string t, vector<int> &v) {
    for(auto ch: s)
        v[ch - 'a']++;

    for(auto ch: t)
        v[ch - 'a']--;
}

bool isAnagram(string s, string t) {
    vector<int> ans(26);
    helper(s, t, ans);

    for(auto elem: ans) {
        if(elem != 0)
            return false;
    }
    return true;
}

int main() {
    string s = "rat";
    string t = "car";
    cout<<isAnagram(s, t);

    return 0;
}