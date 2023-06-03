#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    string word;
    for(auto ch: s) {
        if(isdigit(ch))
            word.push_back(ch);
        if(isalpha(ch))
            word.push_back(tolower(ch));
    }
    cout<<word<<endl;
    int n = word.size();
    for(int i = 0; i < n / 2; ++i) {
        if(word[i] != word[n - i - 1])
            return false;
    }

    return true;
}

int main () {
    string s = " ";
    cout<<isPalindrome(s);

    return 0;
}
