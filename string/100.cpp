#include<bits/stdc++.h>

using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    int cont = 0;
    string ans="";
    int n = spaces.size();
    for(int i = 0; i < s.size(); ++i){
        if(cont < n && i == spaces[cont]) {
            ans += ' ';
            ans += s[i];
            ++cont;
        } else {
            ans += s[i];
        }
    }

    return ans;
}

using vi = vector<int>;
int main() {
    string s = "LeetcodeHelpsMeLearn";
    vi spaces{8,13,15};

    cout<<addSpaces(s, spaces);

    return 0;
}