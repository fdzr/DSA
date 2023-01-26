#include <bits/stdc++.h>

using namespace std;


bool checkString(string s) {
    if(s.find('b') == string::npos)
        return true;
    if(s.find('a') == string::npos)
        return true;

    int index_a = s.find_last_of('a');
    int index_b = s.find_first_of('b');

    return index_a < index_b;
}

int main() {    
    string s = "aaa";
    cout<<checkString(s);

    return 0;
}