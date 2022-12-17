#include <bits/stdc++.h>

using namespace std;

int aux(int n, vector<int>& startPos, string s) {
    int ans = 0;
    vector<int> pos = startPos;
    for(auto ch: s) {
        if(ch == 'R') {
            if(pos[1] + 1 < n){
                ans++;
                pos[1]++;
            }
            else
                break;
        }
        if(ch == 'L') {
            if(pos[1] - 1 >= 0){
                ans++;
                pos[1]--;
            }
            else
                break;
        }
        if(ch == 'U') {
            if(pos[0] - 1 >= 0){
                ans++;
                pos[0]--;
            }
            else
                break;
        }
        if(ch == 'D') {
            if(pos[0] + 1 < n){
                ans++;
                pos[0]++;
            }
            else
                break;
        }
    }
    return ans;
}


vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    vector<int> ans(s.size(), 0);
    for(int i =0; i < ans.size() ; ++i)
        ans[i] += aux(n, startPos, s.substr(i, string::npos));

    return ans;
}



int main() {
    int n = 1;
    vector<int> startPos = {0, 0};
    string s = "LRUD";
    vector<int> ans = executeInstructions(n, startPos, s);
    
    for(auto e: ans)
        cout<<e<<" ";

    return 0;
}