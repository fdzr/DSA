#include <bits/stdc++.h>

using namespace std;


int prefixCount(vector<string>& words, string pref) {
    int cont = 0;
    for(auto str: words) {
        if(str.find(pref) == 0)
            cont++;
    }
    return cont;
}


int main() {
    vector<string> words = {"pay","attention","practice","attend"};
    cout<<prefixCount(words, "at");

    return 0;
}