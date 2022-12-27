#include <bits/stdc++.h>

using namespace std;

bool buddyStrings(string s, string goal) {
    int cont = 0;
    vector<int> tmp;

    if(s.size() != goal.size())
        return false;

    for(int i =0; i < s.size(); ++i) {
        if(s[i] == goal[i])
            cont++;
        else
            tmp.push_back(i);
    }

    if(s.size() == cont + 2){
        return s[tmp[0]] == goal[tmp[1]] && s[tmp[1]] ==goal[tmp[0]];
    }
        

    else if(s.size() == cont) {
        set<int> conjunto(s.begin(), s.end());
        if(conjunto.size() != s.size())
            return true;
    }
    return false;
}


int main() {
    string s = "abacd";
    string goal = "abadb";
    cout<<buddyStrings(s, goal);

    return 0;
}