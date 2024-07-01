#include <bits/stdc++.h>

using namespace std;

string clearDigits(string s) {
    while(true) {
        auto pos = find_if(s.begin(), s.end(), [](char ch){
            return isdigit(ch);
        });

        if(pos == s.end())
            break;

        s.erase(pos);

        if(pos != s.begin())
            s.erase(--pos);
    }

    return s;
}

int main() {
    string s = "cb343456";
    cout<<clearDigits(s);

    return 0;
}