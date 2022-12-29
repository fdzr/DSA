//
// Created by fzamora on 29-12-22.
//

#include "bits/stdc++.h"

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(auto ch: s) {
        if(!st.empty() && ch == ')' && st.top() == '(')
            st.pop();
        else if(!st.empty() && ch == ']' && st.top() == '[')
            st.pop();
        else if(!st.empty() && ch == '}' && st.top() == '{')
            st.pop();
        else
            st.push(ch);
    }
    return st.size() == 0;
}

int main() {
    string s = "(){}[]]";
    cout<<isValid(s);

    return 0;
}