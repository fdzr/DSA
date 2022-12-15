#include <bits/stdc++.h>

using namespace std;

string defangIPaddr(string address) {
    istringstream ss(address);
    string read;
    string ans = "";
    while(getline(ss, read, '.')) {
        ans += (read + "[.]");
    }
    ans.pop_back();
    ans.pop_back();
    ans.pop_back();
    return ans;
}


int main() {
    string address = "1.1.1.1";
    cout<<defangIPaddr(address);

    return 0;
}