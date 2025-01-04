#include <bits/stdc++.h>

using namespace std;

bool aux(const unordered_set<string> &dict, string s, int start,
         unordered_map<int, bool> &memo) {
    if (start >= s.size()) {
        return true;
    }

    if (memo.count(start)) return memo[start];

    string substring;
    for (int i = start; i < s.size(); ++i) {
        substring.push_back(s[i]);
        if (dict.contains(substring) && aux(dict, s, i + 1, memo)) {
            return memo[start] = true;
        }
    }

    return memo[start] = false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    return false;
}

int main() {
    string s = "aaaaaab";

    unordered_set<string> dict = {"a",         "aa",        "aaa",     "aaaa",
                                  "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                                  "aaaaaaaaa", "aaaaaaaaaa"};
    unordered_map<int, bool> memo;

    cout << boolalpha << aux(dict, s, 0, memo) << "\n";

    return 0;
}