#include <bits/stdc++.h>


using namespace std;


void reverseString(vector<char>& s) {
    size_t len = s.size();
    for(int i = 0; i <  len / 2; ++i)
        swap(s[i], s[len - i - 1]);

}



int main() {
    vector<char> s = {'H','a','n','n','a','h'};
    reverseString(s);

    for(auto ch: s)
        cout<<ch<<" ";



    return 0;
}