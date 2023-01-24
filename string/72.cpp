//
// Created by fzamora on 24-01-23.
//

#include "bits/stdc++.h"

using namespace std;

using um = unordered_map<char, int>;

int longestPalindrome(string s) {
    um ans;
    int max_odd = 0;
    bool flag = false;
    int cont = 0;
    for(auto ch: s)
        ans[ch]++;

    for(auto item: ans)
        if(item.second % 2 == 0)
            cont += item.second;

    for(auto item: ans) {
        if(item.second % 2 == 1 && item.second > max_odd)
            max_odd = item.second;
    }

    return cont + max_odd;
}


int main() {
    string s = "bb";
    cout<<longestPalindrome(s);

    return 0;
}