//
// Created by fzamora on 05-01-23.
//
#include "bits/stdc++.h"

using namespace std;

int lengthOfLastWord(string s) {
    stringstream ss(s);
    string token;

    while(ss>>token) {}
    return token.size();
}

int main() {
    string s = "   fly me   to   the moon  ";
    lengthOfLastWord(s);

    return 0;
}