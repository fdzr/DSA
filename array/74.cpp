//
// Created by fzamora on 24-01-23.
//
#include <bits/stdc++.h>

using namespace std;

int fillCups(vector<int>& amount) {
    int cont = 0;
    sort(amount.begin(), amount.end(), greater<int>());
    while (true) {
        if(amount[0] == 0 || amount[1] == 0 || amount[2] == 0) {
            cont += max(amount[0], max(amount[1], amount[2]));
            break;
        }

        amount[0] -= 1;
        amount[2] -= 1;
        cont++;
        if( amount[0] == 0 || amount[2] == 0) {
            cont += max(amount[0], max(amount[1], amount[2]));
            break;
        }

        amount[0] -= 1;
        amount[1] -= 1;
        cont++;
        if( amount[0] == 0 || amount[1] == 0){
            cont += max(amount[0], max(amount[1], amount[2]));
            break;
        }

        amount[1] -= 1;
        amount[2] -= 1;
        cont++;
        if( amount[1] == 0 || amount[2] == 0){
            cont += max(amount[0], max(amount[1], amount[2]));
            break;
        }
    }
    return cont;
}

int main() {
    vector<int> amount = {1,2,3};
    cout<<fillCups(amount);

    return 0;
}