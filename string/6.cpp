#include <bits/stdc++.h>

using namespace std;


int numJewelsInStones(string jewels, string stones) {
    int cont = 0;
    unordered_map<char, int> um;
    for(auto a: jewels)
        um[a] = 0;

    for(auto e: stones)
        if(um.find(e) != um.end())
            um[e]++;
    
    for(auto item: um)
        cont += item.second;

    return cont;
}


int main() {
    string jewels = "z", stone = "ZZ";
    cout<<numJewelsInStones(jewels, stone);

    return 0;
}