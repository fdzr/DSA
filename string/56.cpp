//
// Created by fzamora on 29-12-22.
//

#include "bits/stdc++.h"

using namespace std;

int strStr(string haystack, string needle) {
    int index = haystack.find(needle);
    return index;
}


int main() {
    string haystack = "leetcode";
    string needle = "leeto";
    cout<<strStr(haystack, needle);

    return 0;
}