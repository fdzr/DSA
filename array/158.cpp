//
// Created by fzamora on 23-07-24.
//

#include<bits/stdc++.h>

using namespace std;

vector<string> split(string &s) {
    stringstream formatter(s);
    string cad;
    vector<string> splittedString;

    while(formatter >> cad) {
        splittedString.emplace_back(cad);
    }

    return splittedString;
}

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> um_1;
    unordered_map<string, char> um_2;
    vector<string> words = split(s);

    if(words.size() != pattern.size())
        return false;

    for(int i = 0; i < pattern.size(); ++i) {
        bool condition_1 = um_1.contains(pattern[i]) && um_1[pattern[i]] != words[i];
        bool condition_2 = um_2.contains(words[i]) && um_2[words[i]] != pattern[i];
        if(condition_1 || condition_2) {
            return false;
        } else {
            um_1[pattern[i]] = words[i];
            um_2[words[i]] = pattern[i];
        }
    }

    return true;
}

int main() {
    string s = "dog dog dog dog";
    string pattern = "abba";

    cout<<boolalpha<<wordPattern(pattern, s);

    return 0;
}
