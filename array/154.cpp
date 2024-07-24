//
// Created by fzamora on 04-07-24.
//
#include <bits/stdc++.h>

using namespace std;

int secondHighest(string s) {
    unordered_set<int> digits;

    for(const char ch: s) {
        if(isdigit(ch))
            digits.insert(ch - '0');
    }

    if (digits.size() == 1 || digits.size() == 0)
        return -1;

    int min_1 = -1, min_2 = -1;

    for(auto it: digits) {
        if(it > min_1) {
            min_2 = min_1;
            min_1 = it;
        }
        else if(it > min_2 && it != min_1)
            min_2 = it;

    }

    return min_2;

}

int main() {
    string s = "xyz";
    cout<<secondHighest(s);

    return 0;
}