#include <bits/stdc++.h>

using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    int cont = 0;
    for(auto ch: s) {
        if(!st.empty()) {
            if(st.top() == '(' && ch == ')') {
                st.pop();
                continue;
            }
            st.push(ch);
        }
        else
            st.push(ch);
    }

    while(!st.empty()) {
        cont++;
        st.pop();
    }

    return cont;
}


int main() {
    string s = ")";
    cout<<minAddToMakeValid(s);

    return 0;
}