#include <bits/stdc++.h>

using namespace std;

char mapping(int cod) {
    switch (cod) {
    case 1:
        return 'a';
    case 2:
        return 'b';
    case 3:
        return 'c';
    case 4:
        return 'd';
    case 5:
        return 'e';
    case 6:
        return 'f';
    case 7:
        return 'g';
    case 8:
        return 'h';
    case 9:
        return 'i';
    case 10:
        return 'j';
    case 11:
        return 'k';
    case 12:
        return 'l';
    case 13:
        return 'm';
    case 14:
        return 'n';
    case 15:
        return 'o';
    case 16:
        return 'p';
    case 17:
        return 'q';
    case 18:
        return 'r';
    case 19:
        return 's';
    case 20:
        return 't';
    case 21:
        return 'u';
    case 22:
        return 'v';
    case 23:
        return 'w';
    case 24:
        return 'x';
    case 25:
        return 'y';
    case 26:
        return 'z';
    default:
        break;
    }

    return static_cast<char>(cod);
}

string freqAlphabets(string s) {
    string ans = "", tmp = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '#') {
            tmp += s[i-2];
            tmp += s[i-1];
            s[i] = mapping(stoi(tmp));
            s[i-2] = '-';
            s[i-1] = '-';
            tmp.clear();
        }
    }

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '-')
            continue;
        if(isdigit(s[i]))
            ans += mapping(s[i] - 48);
        else
            ans.push_back(s[i]);
    }
        
    cout<<s<<endl;
    return ans;
}


int main() {
    string s = "1326#123"; //aczabc
    cout<<freqAlphabets(s);

    return 0;
}