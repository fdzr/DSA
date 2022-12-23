#include <bits/stdc++.h>

using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
    int cont = 0;
    for(auto p: patterns) {
        if(word.find(p) != string::npos)
            cont++;
    }

    return cont;
}

int main() {
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    cout<<numOfStrings(patterns, word);


    return 0;
}