//
// Created by fzamora on 28-12-22.
//

#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b) {
    vector<int> v(26);
    for(auto ch: a)
        v[ch - 'a']++;

    for(auto ch: b)
        v[ch - 'a']--;

    return all_of(v.begin(), v.end(), [](auto elem){
            return elem ==0;
    });
}

vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size())
        return {};

    string tmp = "";
    int index = 0;
    vector<int> ans;

    while(index <= s.size() - p.size()) {
        string cad = s.substr(index, p.size());
        if(isAnagram(cad, p))
            ans.push_back(index);

        ++index;
    }

    return ans;
}


int main() {
    string s = "abab";
    string p = "ab";
    for(auto elem: findAnagrams(s, p))
        cout<<elem<<" ";

    return 0;
}