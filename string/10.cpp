#include <bits/stdc++.h>

using namespace std;

string decodeMessage(string key, string message) {
    unordered_map<char, int> um;
    int ascii_letter = 97;
    for(auto ch: key) {
        if(!um[ch] && ch != ' '){
            um[ch] = ascii_letter++;
        }
        
    }
    for(auto &ch: message) {
        if(ch != ' ')
            ch = char(um[ch]);
    }

    return message;
}


int main() {
    string key = "eljuxhpwnyrdgtqkviszcfmabo"; 
    string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    
    cout<<decodeMessage(key, message);

    return 0;
}