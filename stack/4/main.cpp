#include <iostream>
#include <stack>
#include <string>

using namespace std;

char findOppositeChar(char ch) {
    switch (ch) {
        case '[': return ']';
        case ']': return '[';
        case '{': return '}';
        case '}': return '{';
        case '(': return ')';
        case ')': return '(';
    }
    
    return '\0';
}

int main() {
    stack<char> st;
    string cad;

    cin>>cad;

    for (auto ch: cad){
        if (st.empty()) {
            st.push(ch);
            continue;
        }
        
        if(findOppositeChar(st.top()) == ch)
            st.pop();
        else
            st.push(ch);
    }

    string answer = st.empty()? "Balanced": "Not balanced";

    cout<<answer;

    return 0;
}