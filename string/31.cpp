#include <bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s) {
    stack<char> st;
    int open_parentheses = 0, close_parentheses = 0;
    string ans = "";

    for(auto ch: s) {
        if((ch == ')' && open_parentheses == 0) || (ch == ')' && open_parentheses == close_parentheses ))
            continue;

        if(ch == ')')
            close_parentheses++;
        else if(ch == '(')
            open_parentheses++;

        st.push(ch);
    }

    if(open_parentheses > close_parentheses) {
        open_parentheses -= close_parentheses;
        close_parentheses = 0; 
    }

    else if(open_parentheses < close_parentheses) {
        close_parentheses -= open_parentheses;
        open_parentheses = 0; 
    }
    else {
        close_parentheses = 0;
        open_parentheses = 0;
    }

    while(!st.empty()) {
        char tmp = st.top();
        st.pop();
        if(tmp == '(') {
            if(open_parentheses > 0) {
                --open_parentheses;
                continue;
            }

        }
        else if(tmp == ')') {
            if(close_parentheses > 0) {
                --close_parentheses;
                continue;
            }
        }
        ans.push_back(tmp);
    }
   
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s = "())()(((";
    cout<<minRemoveToMakeValid(s);

    return 0;
}

