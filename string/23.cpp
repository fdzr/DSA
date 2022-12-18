#include <bits/stdc++.h>

using namespace std;


int lengthOfLongestSubstring(string s) {
    int max_ = 0;
    string ans = "";

    for(auto ch: s) {
        int found = ans.find(ch);
        if(found == string::npos) {
            ans.push_back(ch);
        }
        else {
            max_ = max(int(ans.size()), max_);
            ans = ans.substr(found + 1, string::npos);
            ans += ch;
        }
    }
    return max(max_, int(ans.size()));
}


int main() {
    string s = " ";
    cout<<lengthOfLongestSubstring(s);


    return 0;
}