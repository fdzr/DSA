#include<bits/stdc++.h>

using namespace std;


string removeOccurrences(string s, string part) {
    int index = s.find(part); 
    while(index != string::npos) {
        s.erase(index, part.size());
        index = s.find(part); 
    }


    return s;
}


int main() {
    string s = "axxxxyyyyb";
    string part = "xy";
    cout<<removeOccurrences(s, part);

    return 0;
}