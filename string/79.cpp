#include <bits/stdc++.h>

using namespace std;


int maximumValue(vector<string>& strs) {
    int max_ = -1;
    for(auto cad: strs) {
        auto ptr = find_if(cad.begin(), cad.end(), [](char c){
            return isalpha(c);
        });

        if(ptr != cad.end())
            max_ = max(max_, int(cad.size()));
        
        else 
            max_ = max(max_, stoi(cad));
    }

    return max_;
}


int main() {
    vector<string> cad = {"alic3","bob","3","4","00000"};
    cout<<maximumValue(cad);

    return 0;
}