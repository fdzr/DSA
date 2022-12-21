#include <bits/stdc++.h>

using namespace std;


int scoreOfParentheses(string s) {
    int cont = 0;
    int open_parentheses = 0;
    int close_parentheses = 0;
    int acc = 0;
    bool nested = false;

    for(auto ch: s) {
        if(ch == '(')
            open_parentheses++;

        if(ch == ')') {
            if(open_parentheses == 1)
                cont++;
                
            open_parentheses--;
        }
            

        


    }

    return cont;
}


int main() {
    string s = "()()()";
    cout<<scoreOfParentheses(s);

    return 0;
}