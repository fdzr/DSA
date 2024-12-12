#include <bits/stdc++.h>

using namespace std;

string createString(vector<pair<int, char>> freq, string s) {
    string res = "";

    while (res.size() < s.size()) {
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i].first > 0 && (res.empty() || freq[i].second != res.back())) {
                res += freq[i].second;
                --freq[i].first;

                break;
            }
        }

        sort(freq.begin(), freq.end(),
             [](const auto& a, const auto& b) { return a.first > b.first; });
    }

    return res;
}

string reorganizeString(string s) {
    vector<pair<int, char>> freq(26, {0, '0'});

    if (adjacent_find(s.begin(), s.end()) == s.end()) return s;

    for (const auto& ch : s) {
        freq[ch - 97].first++;
        freq[ch - 97].second = ch;
    }

    sort(freq.begin(), freq.end(),
         [](const auto& a, const auto& b) { return a.first > b.first; });

    int maxQuantity = freq[0].first;
    for (int i = 1; i < freq.size(); ++i) {
        maxQuantity -= freq[i].first;
    }

    if (maxQuantity > 1) return "";

    return createString(freq, s);
}

int main() {
    string b = reorganizeString("aab");
    cout << b;

    return 0;
}