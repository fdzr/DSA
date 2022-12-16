#include <bits/stdc++.h>

using namespace std;


int maxDepth(string s) {
    stack<char> st;
    int maxCount = 0;
    int max_deep = 0;
    for(auto ch: s) {
        if(ch == ')') {
            if(maxCount > max_deep)
                max_deep = maxCount;

            maxCount--;
            while(st.top() != '(')
                st.pop();

            st.pop();            
        }
        else if(ch == '(') {
            maxCount++;
            st.push(ch);
            continue;   
        }
        else if(!st.empty() && st.top() == '+')
            continue;
        else
            st.push('+');
    }

    return max_deep;
}


int main() {
    string s = "(1)+1*(1*(2+(3*(4))))";
    cout<<maxDepth("1");

    return 0;
}