#include <bits/stdc++.h>

using namespace std;

string makeSmallestPalindrome(string s) {
    string ans = s;
    int n = static_cast<int>(s.size());
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] != s[n-i-1]) {
            char minChar = min(ans[i], ans[n-i-1]);
            ans[i] = minChar;
            ans[n-i-1] = minChar;
        }
    }

    return ans;
}

int main()
{
    string a = "egcfe";
    
    cout<<makeSmallestPalindrome(a);
    return 0;
}