#include <bits/stdc++.h>

using namespace std;

bool isPrefixString(string s, vector<string>& words) {
    int pos = 0;
    
    for(int i = 0; i < words.size(); ++i) {
        int res = s.find(words[i], pos);
        if(res == string::npos || res != pos)
            return false;

        pos += words[i].size();
        if (pos >= s.size())
            return true;
    }

    if(pos < s.size())
        return false;

    return true;
}

int main() {
    string s = "ccccccccc";
    vector<string> words = {"c","cc"};
    cout<<boolalpha<<isPrefixString(s, words);

    return 0;
}