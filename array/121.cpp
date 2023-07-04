#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    stringstream cad(s);
    string input;
    string answer = "";
    while(cad>>input) {
        answer = input + " " + answer;
    }

    answer.pop_back();

    return answer;
}

int main() {
    string s = "a good   example";
    cout<<reverseWords(s);

    return 0;
}