#include <bits/stdc++.h>

using namespace std;

string removeStars(string s) {
    stack<char> st;
    string ans = "";

    for(auto ch: s){
        if(ch == '*') {
            if(!st.empty())
                st.pop();
        }
        else
            st.push(ch);
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {
    string s = "erase*****";
    cout<<removeStars(s);


    return 0;
}