#include <bits/stdc++.h>

using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            string cad = s.substr(i, j - i + 1);
            cout << cad << "\n";
        }
    }

    return 1;
}

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leetsc", "leet", "leetsco", "code", "leetcode"};

    minExtraChar(s, dictionary);

    return 0;
}