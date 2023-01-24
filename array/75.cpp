//
// Created by fzamora on 24-01-23.
//
#include "bits/stdc++.h"

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int cont_5 = 0;
    int cont_10 = 0;
    int cont_20 = 0;

    for(auto elem: bills) {
        if(elem == 5)
            cont_5++;
        if(elem == 10) {
            if(cont_5 == 0)
                return false;
            cont_5--;
            cont_10++;
        }
        if(elem == 20) {
            if(cont_10 >= 1 && cont_5 >= 1) {
                cont_10--;
                cont_5--;
                cont_20++;
            }
            else if(cont_5 >= 3)
                cont_5 -= 3;
            else
                return false;
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5,5,10,10,20};
    cout<<lemonadeChange(bills);

    return 0;
}