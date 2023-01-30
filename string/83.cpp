//
// Created by fzamora on 30-01-23.
//

#include "bits/stdc++.h"

using namespace std;

int countPrefixes(vector<string>& words, string s) {
    int cont = 0;
    for(auto word: words)
        cont += (s.find(word) == 0)? 1 : 0;

    return cont;
}

int main() {
    vector<string> words = {"a", "a"};
    string s = "aa";
    cout<<countPrefixes(words, s);


    return 0;
}