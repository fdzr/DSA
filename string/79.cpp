#include <bits/stdc++.h>

using namespace std;


int maximumValue(vector<string>& strs) {
    int max = -1;
    for(auto cad: strs) {
        auto ptr = find_if(cad.begin(), cad.end(), [](char c){
            return isalpha(c);
        });

        if(ptr != cad.end()) {
            if(int(cad.size()) > max)
                max = cad.size();
        }
        else {
            if(int num = stoi(cad); num > max)
                max = num;
        }
    }

    return max;
}


int main() {
    vector<string> cad = {"alic3","bob","3","4","00000"};
    cout<<maximumValue(cad);

    return 0;
}