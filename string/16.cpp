#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    string ans = "";
    stringstream ss(s);
    string cad;

    while(ss>>cad) {
        reverse(cad.begin(), cad.end());
        ans.append(cad);
        ans.append(" ");
    }
    ans.pop_back();
    return ans;
}


int main() {
    string s = "Let's take LeetCode contest";
    cout<<reverseWords(s);


    return 0;
}