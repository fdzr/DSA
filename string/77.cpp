#include <bits/stdc++.h>

using namespace std;


int percentageLetter(string s, char letter) {
    int cont = 0;
    for(auto ch: s)
        if(ch == letter)
            cont++;

    return static_cast<int>(100 * float(cont) / s.size());
}


int main() {
    string s = "vmvvvvvzrvvpvdvvvvyfvdvvvvpkvvbvvkvvfkvvvkvbvvnvvomvzvvvdvvvkvvvvvvvvvlvcvilaqvvhoevvlmvhvkvtgwfvvzy";
    cout<<percentageLetter(s, 'v');

    return 0;
}