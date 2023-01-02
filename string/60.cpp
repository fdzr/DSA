#include <bits/stdc++.h>

using namespace std;

bool validate(string token){
    int index = token.find_first_of('-');
    int index_l = token.find_last_of('-');
    if(index != index_l)
        return false;
    if(index == 0 || index == token.size() - 1)
        return false;
    if(index != string::npos) {
        if(!isalpha(token[index-1]) || !isalpha(token[index+1]))
            return false;
    }
        

    bool containDigit = any_of(token.begin(),token.end(), ::isdigit);
    if(containDigit)
        return false;

    int ex = token.find_first_of('!');
    int exl = token.find_last_of('!');
    if(ex != exl)
        return false;

    if(exl != string::npos && exl != token.size() - 1)
        return false;

    int comma = token.find_first_of(',');
    int comma_l = token.find_last_of(',');
    if(comma != comma_l)
        return false;
    if(comma != string::npos && comma != token.size() - 1)
        return false;

    int point = token.find_first_of('.');
    int point_l = token.find_last_of('.');
    if(point != point_l)
        return false;
    if(point != string::npos && point != token.size() - 1)
        return false;

    return true;
}

int countValidWords(string sentence) {
    stringstream ss(sentence);
    string token;
    int cont = 0;

    while(ss>>token) {
        cont += validate(token)? 1 : 0;
    }

    return cont;
}


int main() {
    string s = "alice and  bob are playing stone-game10";
    cout<<countValidWords(s);

    return 0;
}