#include <bits/stdc++.h>

using namespace std;

int balancedStringSplit(string s) {
    int cant_L = 0, cant_R = 0;
    int ans = 0;
    for(auto ch: s) {
        (ch == 'R')? ++cant_R: ++cant_L;
        if(cant_R == cant_L) {
            ans++;
            cant_R = 0;
            cant_L = 0;
        }
    }
    return ans;
}


int main() {
    string s = "RLRRLLRLRL";
    cout<<balancedStringSplit(s);

    return 0;
}