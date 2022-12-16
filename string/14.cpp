#include <bits/stdc++.h>

using namespace std;

int countAsterisks(string s) {
    bool open = false;
    int cont = 0;

    for(auto ch: s) {
        if(ch == '|' && !open)
            open = true;
        else if(ch == '*' && !open)
            cont++;
        else if (ch == '|' && open)
            open = false;
    }
    return cont;
}


int main() {
    string s = "iamprogrammer";
    cout<<countAsterisks(s);

    return 0;
}