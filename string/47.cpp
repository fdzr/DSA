//
// Created by fzamora on 27-12-22.
//

#include "bits/stdc++.h"

using namespace std;


bool areOccurrencesEqual(string s) {
    vector<int> ans(26, 0);
    for(auto ch: s)
        ans[ch - 'a']++;

    bool flag = false;
    int cant;
    for(auto elem: ans){
        if(flag && elem !=0) {
            if(elem != cant)
                return false;
        }
        if(elem != 0 && !flag) {
            cant = elem;
            flag = true;
        }
    }
    return true;
}

int main() {
    string s = "aaabb";
    cout<<areOccurrencesEqual(s);

    return 0;
}