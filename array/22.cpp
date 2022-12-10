#include <bits/stdc++.h>

using namespace std;

int aux(string sentence) {
    string word;
    istringstream ss(sentence);
    int cont = 0;
    while(ss >> word)
        cont++;

    return cont;
}


int mostWordsFound(vector<string>& sentences) {
    int maxWords = 0;
    for(auto sentence: sentences)
        maxWords = max(maxWords, aux(sentence));

    return maxWords;
}


int main() {
    vector<string> vc = {"please wait",
                         "continue to fight",
                         "continue to win"};
    cout<<mostWordsFound(vc);

    return 0;
}