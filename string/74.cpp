#include <bits/stdc++.h>

using namespace std;

bool halvesAreAlike(string s) {
    unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
    int cont1Half = 0, cont2Half = 0;
    for(auto ch: s.substr(0, s.size()/2))
        if(vowels.count(ch) != 0)
            cont1Half++;

    for(auto ch: s.substr(s.size()/2))
        if(vowels.count(ch) != 0)
            cont2Half++;

    return cont1Half == cont2Half;
}

int main() {
    string s = "au";
    cout<<halvesAreAlike(s);

    return 0;
}