//
// Created by fzamora on 28-12-22.
//

#include <bits/stdc++.h>

using namespace std;

bool isPermutation(string a, string b) {
    vector<int> v(26);
    for(auto ch: a)
        v[ch - 'a']++;

    for(auto ch: b)
        v[ch - 'a']--;

    return all_of(v.begin(), v.end(), [](auto elem){
        return elem ==0;
    });
}

bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size())
        return false;

    string tmp = "";
    int index = 0;
    bool flag = false;

    while(index <= s2.size() - s1.size()) {
        string cad = s2.substr(index, s1.size());
        if(isPermutation(cad, s1))
           flag = true;

        ++index;
    }
    return flag;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<<checkInclusion(s1, s2);

    return 0;
}