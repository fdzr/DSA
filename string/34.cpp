#include <bits/stdc++.h>

using namespace std;

int countPoints(string rings) {
    unordered_map<int, unordered_set<char>> um;
    int cont = 0;

    for(int i = 0; i < rings.size() - 1; i+=2)
        if(isdigit(rings[i+1]))
            um[rings[i + 1] - '0'].insert(rings[i]);
        
    for(auto &[k, items]: um) {
        if(items.size() == 3)
            cont++;

    }
    return cont;
    
}


int main() {
    string s = "G4";
    cout<<countPoints(s);

    return 0;
}