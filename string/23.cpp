#include <bits/stdc++.h>

using namespace std;

//O(n^2)
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


//Time O(n) - Space O(n)
int lengthOfLongestSubstring_2(string s) {
    int ans = 0;
    int i = 0;
    int index = 0;
    unordered_map<char, int> um;

    for(auto ch: s) {
        if(um[ch] > 0) {
            i = um[ch];
        }

        ans = max(ans, index - i + 1);
        um[ch] = index + 1;
        ++index;
    }


    return ans;
}


int main() {
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s);
    cout<<endl;
    cout<<lengthOfLongestSubstring_2(s);

    return 0;
}