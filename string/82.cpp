//
// Created by fzamora on 30-01-23.
//
#include "bits/stdc++.h"

using namespace std;

string reversePrefix(string word, char ch) {
    int index = word.find(ch);
    if(index == string::npos)
        return word;

    reverse(word.begin(), word.begin() + index + 1);
    return word;
}

int main() {
    string s = "abcdefghijk";
    cout<<reversePrefix(s, 'd');

    return 0;
}