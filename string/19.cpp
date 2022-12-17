#include <bits/stdc++.h>

using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int cont = 0;
    int index = 0;
    int cont_p = 0;
    int cont_m = 0;
    int cont_g = 0;
    string aux = "";

    for (auto str: garbage) {
        string tmp = str;
        bool flag_g = false;
        bool flag_p = false;
        bool flag_m = false;
        if(str.find('P') == string::npos && index >= 1) {
            cont_p += travel[index - 1];
        }
        if(str.find('M') == string::npos && index >= 1) {
            cont_m += travel[index - 1];
        }
        if(str.find('G') == string::npos && index >= 1) {
            cont_g += travel[index - 1];
        }

        for(auto ch: str) {
            if(ch == 'P') {
                cont++;

                if(index >=1 && !flag_p ) {
                    cont += travel[index - 1];
                    cont += cont_p;
                    cont_p = 0;
                    flag_p = true;
                }
            }

            if(ch == 'M') {
                cont++;

                if(index >=1 && !flag_m ) {
                    cont += travel[index - 1];
                    cont += cont_m;
                    cont_m = 0;
                    flag_m = true;
                }
            }

            if(ch == 'G') {
                cont++;

                if(index >=1 && !flag_g ) {
                    cont += travel[index - 1];
                    cont += cont_g;
                    cont_g = 0;
                    flag_g = true;
                }
            }
        }

        ++index;
        aux = str;
    }

    return cont;
}

int main() {
    vector<string> garbage = {"MMM","PGM","GP"};
    vector<int> travel = {3, 10};
    
    cout<<garbageCollection(garbage, travel);
    
    return 0;
}