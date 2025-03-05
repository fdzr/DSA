#include <bits/stdc++.h>

using namespace std;

bool check_duplicate_parentheses(const string &cad) {
    stack<char> st;
    int cont = 0;

    for (const char &ch : cad) {
        if (ch == ')' && st.top() == ')') {
            return true;
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main() {
    string arr[] = {"((x+y))+z", "(x+y)", "((x+y)+((z)))"};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        cout << boolalpha << check_duplicate_parentheses(arr[i]) << "\n";
    }

    return 0;
}