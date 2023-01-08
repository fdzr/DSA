#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
    int index_s = 0;
    int cont = 0;

    if(s == t)
        return true;

    for(int i = 0; i < t.size(); ++i) {
        if(t[i] == s[index_s]) {
            cont++;
            index_s++;
        }
        if(cont == s.size())
            return true;

    }
    return false;
}


int main() {
    string s = "";
    string t = "";
    cout<<isSubsequence(s, t);


    return 0;
}