#include <bits/stdc++.h>

using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string cad_1 = "", cad_2 = "";

    for(auto str: word1)
        cad_1+=str;

    for(auto str: word2)
        cad_2+=str;

    return cad_1 == cad_2;
}

int main() {
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};

    cout<<arrayStringsAreEqual(word1, word2);

    return 0;
}