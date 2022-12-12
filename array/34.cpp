#include <bits/stdc++.h>

using namespace std;


vector<int> aux(string cad) {
    vector<int> v(26, 0);
    for(auto a: cad)
        v[a - 'a'] = 1;
    
    return v;
    
}


int countConsistentStrings(string allowed, vector<string>& words) {
    int cont = 0;
    
    vector<int> target = aux(allowed);
    for(auto word: words) {
        int cont_char = 0;
        for(auto ch: word) {
            cont_char += target[ch - 'a'];
        }
        cont += (cont_char == word.size());
    }
    return cont;
}


int main() {
    string allowed = "abc";
    vector<string> words = {"a","b","c","ab","ac","bc","abc"};
    cout<<countConsistentStrings(allowed, words);

    return 0;
}