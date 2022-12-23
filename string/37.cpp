#include <bits/stdc++.h>

using namespace std;


int minimumMoves(string s) {
    int cont = 0;
    int i = 0;

    while(i < s.size()) {
        if(s[i] == 'X') {
            cont++;
            i+=3;
            continue;
        }
            
        ++i;
    }

    return cont;
}

int main() {
    string s = "OOXOXOXO";
    cout<<minimumMoves(s);
    

    return 0;
}