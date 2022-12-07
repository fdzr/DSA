#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int acc = 0;
    vector<int> ans;
    int i = digits.size()-1;
    digits[i] = (digits[i] + 1) % 10;
    acc = (digits[i] == 0)? 1: 0;
    --i;

    while(acc > 0 && i >=0) {
        digits[i] = (digits[i] + 1) % 10;
        acc = (digits[i] == 0)? 1: 0;
        --i;
    }

    if(acc) {
        ans = {1};
        move(digits.begin(), digits.end(), back_inserter(ans));
    }
    else
        ans = digits;

    
    return ans;
}

ostream& operator <<(ostream& out, vector<int> &v) {
    out<<"["<<v[0];
    for(int i=1;i<v.size();++i)
        out<<","<<v[i];

    out<<"]";
    return out;
}


int main() {
    vector<int> vc = {9, 9, 9, 1};
    vector<int> ans = plusOne(vc);
    cout<<ans;


    return 0;
}