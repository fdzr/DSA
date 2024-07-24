#include <bits/stdc++.h>

using namespace std;

string applyBackspace(string cadena) {
    stack<char> op;

    for(char const & ch: cadena) {
        if(isalpha(ch))
            op.push(ch);
        else if(ch == '#' && !op.empty())
            op.pop();
    }

    string temp = "";
    while(!op.empty()) {
        temp += op.top();
        op.pop();
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

bool backspaceCompare(string s, string t) {
    return applyBackspace(s) == applyBackspace(t);
}

int main() {
    string s = "a#c", t = "b";
    cout<<boolalpha;
    cout<<backspaceCompare(s, t);

    return 0;
}