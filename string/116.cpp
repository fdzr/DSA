#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> a, b;

    for(int i = 0; i < s.length(); ++i) {
        bool condition1 = a.find(s[i]) != a.end() && a[s[i]] != t[i];
        bool condition2 = b.find(t[i]) != b.end() && b[t[i]] != s[i];

        if(condition1 || condition2)
            return false;
        else {
            a[s[i]] = t[i];
            b[t[i]] = s[i];
        }

    }

    return true;
}

int main() {
    string s = "egg", t = "add";
    cout<<boolalpha<<isIsomorphic(s, t);

    return 0;
}