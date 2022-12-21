#include <bits/stdc++.h>

using namespace std;


int minSwaps(string s) {
    int open_bracket = 0, close_bracket = 0;
    for(auto ch: s) {
        if(ch == ']') {
            if(open_bracket > 0){
                --open_bracket;
            }
            else
                ++close_bracket;
        }
        else
            ++open_bracket;
    }

    if(open_bracket % 2)
        return (open_bracket / 2) + 1;

    return open_bracket / 2;
}


int main() {
    string s = "]]][[[][";
    cout<<minSwaps(s);
    // cout<<(5/2);

    return 0;
}