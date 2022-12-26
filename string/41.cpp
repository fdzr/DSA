#include <bits/stdc++.h>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> um;
    vector<pair<string, int>> ans;

    for(auto str: words)
        um[str]++;

    copy(um.begin(), um.end(), back_inserter(ans));
    sort(ans.begin(), ans.end(), [](auto a, auto b){
        if(a.second == b.second)
            return strcmp(a.first.c_str(), b.first.c_str()) < 0;

        return a.second > b.second;
    });

    vector<string> tmp;
    transform(ans.begin(), ans.begin() + k, back_inserter(tmp), [](auto item){
        return item.first;
    });

    return tmp;
}


int main() {
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;
    for(auto str: topKFrequent(words, k))
        cout<< str<<" ";
    // if("i" > "love")
    //     cout<<"yes"<<endl;
    // else if ("love" > "i")
    //     cout<< "no";

    return 0;
}