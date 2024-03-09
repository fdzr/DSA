#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> initial;
    int i = 0;

    for(auto elem: pushed) {
        if(elem != popped[i]) {
            initial.push(elem);
        }
        else {
            ++i;
            while(!initial.empty() && initial.top() == popped[i]) {
                ++i;
                initial.pop();
            }
        }
    }

    while(!initial.empty() && i < popped.size() && popped[i] == initial.top()) {
        ++i;
        initial.pop();
    }

    return initial.empty();
}


int main() {
    vector<int> pushed {2,1,0}, popped{1,2,0};
    cout<<validateStackSequences(pushed, popped);


    return 0;
}