#include <bits/stdc++.h>

using namespace std;

string removeDigit(string number, char digit) {
    string ans = "";
    
    for(int i = 0; i < number.size(); ++i) {
        if(number[i] == digit) {
            string temp = number.substr(0, i) + number.substr(i+1);
            ans = max(ans, temp);
        }
    }

    return ans;
}

int main() {
    string number = "887685";
    char digit = '8';
    cout<<removeDigit(number, digit);



    return 0;
}