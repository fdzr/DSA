#include <bits/stdc++.h>

using namespace std;


vector<int> minOperations(string boxes) {
    vector<int> ans(boxes.size(), 0);
    int op = 0;
    int cont = 0;
    for(int i = 0; i < boxes.size(); ++i) {
        if(boxes[i] == '1') {
            if(cont > 0) {
                ans[i] += cont*i - op;
            }
            cont++;
            op +=i;
        }
        else {
            ans[i] += cont*i - op;
        }
    }

    cont = 0, op = 0;        
    for(int i = boxes.size() - 1; i >= 0 ; --i) {
        if(boxes[i] == '1') {
            if(cont > 0) {
                ans[i] += abs(cont*i - op);
            }
            cont++;
            op +=i;
        }
        else {
            ans[i] += abs(cont*i - op);
        }


    }
    return ans;
}


int main() {
    string boxes = "110";
    vector<int> ans = minOperations(boxes);
    for(auto e: ans)
        cout<<e<<" ";


    return 0;
}