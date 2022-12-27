//
// Created by fzamora on 27-12-22.
//

#include <bits/stdc++.h>

using namespace std;

char repeatedCharacter(string s) {
    int ans = 0;
    char res;
    for(auto ch: s){
        if(ans & (1<<(ch-96))) {
            res = ch;
            break;
        }
        ans |= (1<<(ch-96));
    }
    return res;
}


int main() {
    string s = "abccbaacz";
    cout<<repeatedCharacter(s);

    return 0;
}