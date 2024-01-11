#include <bits/stdc++.h>

using namespace std;


int scoreOfParentheses(string s) {
    int cont = 0, aux = 0;
    bool flag = false;
    stack<pair<char, pair<string, int>>> st;

    for(auto ch: s) {
        if(ch == '(') {
            if(!st.empty() && st.top().first == '(' && st.top().second.first == ""){
                st.top().second.first = "mul";
                st.top().second.second = 2;
            }
            
            if(flag){
                st.push({'$', {"", 0}});
                flag = false;
            }
            
            st.push({ch, {"", 0}});
                
            continue;
        }
        if (ch == ')') {
            if(st.top().second.second == 0) {
                st.pop();
                st.push({'+', {"sum", 1}});
            }
            else if (st.top().first == '+') {
                flag = true;
                continue;
            }
                
        }
    }

    while(!st.empty()) {
        if(st.top().first == '+')
            cont++;
        else if (st.top().first == '$') {
            cont += aux;
            aux = cont;
            cont = 0;
        }
        else
            cont *= 2;

        st.pop();

    }

    return cont + aux;
}


int main() {
    string s = "((())())";
    cout<<scoreOfParentheses(s);

    return 0;
}