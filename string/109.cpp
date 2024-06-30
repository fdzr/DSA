#include <bits/stdc++.h>

using namespace std;

int countSeniors(vector<string>& details) {
    int cont = 0;
    for(auto information: details) {
        int age = stoi(information.substr(11, 2));
        if(age > 60)
            cont ++;
    }

    return cont;
}

int main() {
    vector<string> details({"1313579440F2036","2921522980M5644"});
    cout<<countSeniors(details);

    return 0;
}