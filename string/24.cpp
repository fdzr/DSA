#include <bits/stdc++.h>

using namespace std;


string aux(string s) {
    string ans = "";
    int index = 0;

    while(s[index] == '0')
        ++index;

    if(index == s.size())
        return "0";

    if (index > 0)
        return s.substr(index, string::npos);

    return s;
}


int myAtoi(string s) {
    if(s.empty())
        return 0;

    string ans = "";
    int index = 0;
    string range = "2147483647";

    while(isspace(s[index]))
        ++index;

    if(s[index] == '+' || s[index] == '-') {
        if(index - 1 >= 0 && s[index - 1] == '0')
            return 0;

    }

    if((s[index] == '-' || s[index] == '+') || isdigit(s[index])) {
        if(index + 1 >= s.size() && (s[index] == '-' || s[index] == '+'))
            return 0;

        if((s[index] == '-' || s[index] == '+') && !isdigit(s[index + 1]))
            return 0;

        bool negative = false;
        if(s[index] == '-') {
            negative = true;
            index++;   
        }
        if(s[index] == '+') {
            negative = false;
            index++;
        }
        
        while(isdigit(s[index]))
           ans += s[index++];

        ans = aux(ans);

        if(ans.size() > range.size()) {
            return (negative)? INT_MIN: INT_MAX;
        }
    
        long long int res = stoll(ans);
    
        if(res > INT_MAX ) {
            return (negative)? INT_MIN: INT_MAX;
        }
        
        return (negative)? -1 * res: res;

    }
    else
        return 0;
}


int main () {
    string s = "0  123";
    cout<<myAtoi(s);
    

    return 0;
}