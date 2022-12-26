#include <bits/stdc++.h>

using namespace std;


vector<int> aux(vector<int> v) {
    vector<int> tmp;
    for(int i =0; i < v.size(); ++i)
        if(v[i] > 0){
            for(int j = 0; j < v[i]; ++j)
                tmp.push_back(i);
        }
            

    return tmp;
}


bool checkIfCanBreak(string s1, string s2) {
    vector<int> v1(26, 0), v2(26, 0);
    for(auto ch: s1){
        v1[ch - 'a']++;
    }

    for(auto ch: s2){
        v2[ch - 'a']++;
    }

    vector<int> res1, res2;
    res1 = aux(v1), 
    res2 = aux(v2);

    bool flag_1 = true, flag_2 = true;

    for(int i = res1.size()-1;i >= 0 ; --i) {
        if(res2[i] < res1[i]) {
            flag_1 = false;
        }
        if(res1[i] < res2[i]) {
            flag_2 = false;
        }
    }
    return flag_1 || flag_2;

}


int main() {
    string s1 = "abe", s2 = "acd";
    cout<<checkIfCanBreak(s1, s2);

    return 0;
}