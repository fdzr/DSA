#include <bits/stdc++.h>

using namespace std;

string toLowerCase(string s) {
    for(auto &ch: s) {
        ch = tolower(ch);
    }
    return s;
}


int main() {
    string s = "Hello";
    cout<<toLowerCase(s);

    return 0;
}