#include <bits/stdc++.h>

using namespace std;

bool checkBalancedExpression(const string& cad) {
    stack<char> st;

    for (const char& ch : cad) {
        if (!st.empty() && st.top() == '[' && ch == ']') {
            st.pop();
            continue;
        } else if (!st.empty() && st.top() == '(' && ch == ')') {
            st.pop();
            continue;
        } else if (!st.empty() && st.top() == '{' && ch == '}') {
            st.pop();
            continue;
        }

        st.push(ch);
    }

    return st.empty();
}

int main() {

    string cad = "{[{}{}]}[()]";
    cout << boolalpha << checkBalancedExpression(cad) << "\n";

    cad = "{()}[)";
    cout << boolalpha << checkBalancedExpression(cad);


    return 0;
}