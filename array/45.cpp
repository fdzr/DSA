#include <bits/stdc++.h>

using namespace std;

bool isPalindromic(string word) {
    int n = word.size();

    for(int i = 0; i < n/2; ++i)
        if(word[i] != word[n - i - 1])
            return false;

    return true;
}


string firstPalindrome(vector<string>& words) {
    for(auto word: words)
        if(isPalindromic(word))
            return word;

    return "";
}


int main() {
    vector<string> words = {"def","ghi"};
    cout<<firstPalindrome(words);


    return 0;
}