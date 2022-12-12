#include <bits/stdc++.h>

using namespace std;


vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<string, int>> people;
    vector<string> ans;
    for(int i =0; i < names.size(); ++i)
        people.push_back({names[i], heights[i]});

    sort(people.begin(), people.end(), [] (auto a, auto b){
        return a.second > b.second;
    });


    transform(people.begin(), people.end(), back_inserter(ans), 
                [] (pair<string, int> a){
                    return a.first;
                });

    return ans;
}



int main() {
    vector<string> names = {"Alice","Bob","Bob"};
    vector<int> heights = {155,185,150};
    vector<string> ans = sortPeople(names, heights);
    for(auto a: ans)
        cout<<a<<" ";

    return 0;
}