#include <bits/stdc++.h>

using namespace std;

int convertToNumber(char c) {
    if(c == 'A')
        return 150;
    if(c == 'K')
        return 145;
    if(c == 'Q')
        return 140;
    if(c == 'J')
        return 135;
    if(c == 'T')
        return 130;

    return c - '0';
}

bool compareCards(const string &card1, const string &card2){
    for(int i = 0; i < card1.size(); ++i) {
        if(card1[i] == card2[i])
            continue;
        else if(convertToNumber(card1[i]) > convertToNumber(card2[i]))
            return true;
        else 
            return false;
    }

    return true;
}



int main() {
    

    return 0;
}