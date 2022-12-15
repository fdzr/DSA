#include <bits/stdc++.h>

using namespace std;

string sortSentence(string s) {
    vector<string> tmp(10, "-"), aux;
    string ans = "", cad;
    int cont = 0;

    stringstream ss(s);
    
    while(ss>>cad){
        cont++;
        aux.push_back(cad);
    }

    for(auto str: aux) {
        char num = str.back();
        int index = num - 48;
        tmp[index - 1] = str.substr(0,str.size() - 1);
    }

    for(int i = 0; i < cont; ++i) {
        ans.append(tmp[i]);
        ans.append(" ");
    }

    ans.pop_back();

    return ans;
}

int main() {
    string s = "is2 sentence4 This1 a3";
    cout<<sortSentence(s);
 
    

    return 0;
}