#include <bits/stdc++.h>

using namespace std;

int partitionString(string s) {
    int cont = 0;
    set<int> lookup;
    for(auto ch: s) {
        if(lookup.find(ch) == lookup.end()) {
            lookup.insert(ch);
        }
        else {
            cont++;
            lookup.clear();
            lookup.insert(ch);
        }

    }
    int add = (lookup.size() > 0)? 1 : 0;
    return cont + add;
}

int main() {
    string s = "ssssss";
    cout<<partitionString(s);

    return 0;
}