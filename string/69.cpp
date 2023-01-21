#include <bits/stdc++.h>

using namespace std;


int minTimeToType(string word) {
    char prev = 'a';
    int cont = 0;

    for(int i = 0; i < word.size() ; ++i) {
        int indexWordCurrent = (word[i] - 97) - 26;
        int indexWordPrev = (prev - 97) - 26;

        int diff = abs(indexWordCurrent - indexWordPrev);
        cont += (diff > 13)? 26 - diff: diff;
        cont++;
        prev = word[i];

    }

    return cont;
}


int main() {
    string cad = "zjpc";
    cout<<minTimeToType(cad);


    return 0;
}