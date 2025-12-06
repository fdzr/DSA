#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    int cont = 0, start = 50;

    while (getline(input, line)) {
        int dial = stoi(line.substr(1));

        if (line[0] == 'R') {
            start = (start + dial) % 100;
        } else {
            start = (start - dial + 100) % 100;
        }

        if (start == 0) {
            ++cont;
        }
    }

    printf("%d", cont);

    return 0;
}