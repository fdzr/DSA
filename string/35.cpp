#include <bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s) {
    stack<char> st, clean;
    bool open = false, out = false;
    int cont_open = 0, cont_close = 0;
    int cont = 0;
    string ans = "", tmp ="";

    for(auto ch: s) {
         if(ch == '(') {
            if(st.empty()){
                st.push(ch);
                open = true;
                cont_open++;
                continue;
            }
            else if(st.top() == '(') {
                if(open && !out) {
                    st.pop();
                    cont_open--;
                    open = false;
                    out = true;
                    cont++;
                }
                    st.push(ch);
                    cont_open++;
            }
            else {
                st.push(ch);
                open = true;
                cont_open++;
            }
        }
        else {
            cont_close++;
            if(cont_close == cont_open + 1){
                while(!st.empty()) {
                    tmp += st.top();
                    st.pop();
                }

                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                st = clean;
                tmp = "";
                cont_open = 0;
                cont_close = 0;
                cont = 0;
                open = false;
                out = false;
                continue;
            }

            if(!out && st.top() == '('){
                st.pop();
                continue;
            }
                

            st.push(ch);
        }
    }

    

    
    return ans;
}

int main() {
    string s = "(()())(())(()(()))";
    cout<<removeOuterParentheses(s);

    return 0;
}