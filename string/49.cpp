#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    string ans = "";
    while(i < word1.size() || j < word2.size()) {
        if(i < word1.size()) {
            ans.push_back(word1[i]);
            ++i;
        }
        if(j < word2.size()) {
            ans.push_back(word2[j]);
            ++j;
        }
    }
    return ans;
}


int main() {
    string word1 = "abcd";
    string word2 = "pq";
    cout<<mergeAlternately(word1, word2);

    return 0;
}
