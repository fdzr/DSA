//
// Created by fzamora on 05-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using um = unordered_map<char, int>;

bool canConstruct(string ransomNote, string magazine) {
    um freqLetters;
    for(auto ch: ransomNote)
        freqLetters[ch]++;

    for(auto ch: magazine) {
        if(freqLetters.find(ch) != freqLetters.end())
            freqLetters[ch]--;
    }

    for(auto item: freqLetters)
        if(item.second > 0)
            return false;

    return true;
}

int main() {
    string ransomNote = "aa", magazine = "ab";
    cout<<canConstruct(ransomNote, magazine);

    return 0;
}