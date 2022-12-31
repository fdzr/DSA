#include <bits/stdc++.h>

using namespace std;

string replaceDigits(string s) {
    string ans = s;
    for(int i = 1; i < ans.size(); i+=2)
        ans[i] = static_cast<char>(ans[i-1] + (ans[i] - 48));
    
    return ans;
}

int main() {
    string s = "a1b2c3d4e";
    cout<<replaceDigits(s);

    return 0;
}