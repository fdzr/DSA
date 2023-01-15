#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vector<int> diStringMatch(string s) {
    vi ans(s.size() + 1);
    int d = s.size();
    int iz = 0;

    for(int i = 0; i < s.size(); ++i) {
        if(i + 1 == s.size()) {
            if(s[i] == 'I') {
                ans[i] = iz;
                ans[i+1] = d;
            }
            else {
                ans[i] = d;
                ans[i+1] = iz;
            }
            break;
        }
        if(s[i] == 'I') {
            ans[i] = iz;
            iz++;
        }
        else {
            ans[i] = d;
            d--;
        }

    }

    return ans;
}

int main() {
    string s = "IDIDI";
    for(auto elem: diStringMatch(s))
        cout<<elem<<" ";

    return 0;
}