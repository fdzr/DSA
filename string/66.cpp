#include <bits/stdc++.h>

using namespace std;

int maximum69Number (int num) {
    string cad = to_string(num);
    for(auto &c : cad){
        if(c == '6') {
            c = '9';
            break;
        }
    }
    return stoi(cad);
}

int main() {
    int num = 6969;
    cout<<maximum69Number(num);

}