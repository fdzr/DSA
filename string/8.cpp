#include <bits/stdc++.h>

using namespace std;


vector<string> cellsInRange(string s) {
    char initial = s[0];
    char end = s[3];
    int row_initial = int(s[1]);
    int row_end = int(s[4]);
    vector<string> ans;
    string tmp = "";

    for(char col = initial; col <= end; ++col)
        for(int row = row_initial; row <= row_end; ++row) {
            tmp.push_back(col);
            tmp.push_back(static_cast<char>(row));
            ans.push_back(tmp);
            tmp.clear();
        }
    
    return ans;
}


int main() {
    string s = "A1:F1";
    for(auto str: cellsInRange(s))
        cout<<str<<" ";
    return 0;
}