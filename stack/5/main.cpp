#include <iostream>
#include <stack>

using namespace std;

void invertStack(stack<int> &input, int item) {
    if (input.empty()) {
        input.push(item);
        return;
    }
        
    int val = input.top();
    input.pop();
    invertStack(input, item);
    input.push(val);
}

void invert(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int item = st.top();
    st.pop();
    invert(st);
    invertStack(st, item);
}

void print(stack<int> st) {
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {
    stack<int> st({1,2,3,4,5});
    print(st);
    
    invert(st);
    print(st);

    return 0;
}