#include <bits/stdc++.h>

using namespace std;

string interpret(string command) {
    stack<char> st;
    string ans = "";
    for(auto ch: command) {
        if(st.empty()) {
            st.push(ch);
            continue;
        }

        if(st.top() == '(' && ch == ')') {
            st.pop();
            st.push('o');
        }
        else if (st.top() == '(' && ch == 'a') {
            st.pop();
            st.push('a');
        }
        else if (st.top() == 'a' && ch == 'l')
            st.push('l');
        else if(st.top() == 'l' && ch == ')')
            continue;
        else
            st.push(ch);
    }

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {
    string command = "G";
    cout<<interpret(command);

    return 0;
}