#include <bits/stdc++.h>

using namespace std;

int minPartitions(string n) {
    char max = '0';
    for(auto ch: n) {
        if(ch > max)
            max = ch;
    }

    return max - 48;
}


int main() {
    string n = "27346209830709182346";
    cout<<minPartitions(n);

    return 0;
}