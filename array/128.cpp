#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(const pair<char, int> &a, const pair<char, int> &b) const {
        if(a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }

};


string frequencySort(string s) {
    map<char, int> freq;
    set<pair<char, int>, cmp> pairFreq;
    string ans = "";

    for(auto c: s)
        freq[c]++;

    pairFreq.insert(freq.begin(), freq.end());

    for(auto item: pairFreq) {
        string tmp(item.second, item.first);
        ans += tmp;
    }

    return ans;
}

int main() {
    string cad = "Aabb";
    frequencySort(cad);

    return 0;
}