#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

//template<typename T>
bool compare(const pair<int, int> &l, const pair<int, int> &r){
    if(l.second != r.second)
        return l.second > r.second;

    return l.first > r.first;
}

struct compare_1{
    template<typename T>
    bool operator()(const T &l, const T &r){
        if(l.second != r.second)
            return l.second > r.second;

        return l.first > r.first;
    }
};

struct compare_2{
    template<typename T>
    bool operator()(const T &l, const T &r){
        if(l.second != r.second)
            return l.second < r.second;

        return l.first < r.first;
    }
};

void print_N_mostFrequent(int arr[], int n, int k){
    unordered_map<int, int> um;
    for(int i = 0; i < n; ++i)
        um[arr[i]]++;

    // first method
    vector<pi> v(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);

    cout<<"numbers with most frequencies"<<endl;
    for(int i=0;i<k;++i)
        cout<<v[i].first<<" ";
}

void print_N_mostFrequent_2(int arr[], int n, int k){
    unordered_map<int, int> um;
    for(int i = 0; i < n; ++i)
        um[arr[i]]++;

    set<pi, compare_1> us(um.begin(), um.end());

    auto it = us.begin();

    for(int i=0;i<k;++i)
        cout<<(it++)->first<<" ";
}

void print_N_mostFrequent_3(int arr[], int n, int k){
    unordered_map<int, int> um;
    for(int i = 0; i < n; ++i)
        um[arr[i]]++;

    priority_queue<pi, vector<pi>, compare_2> pq(um.begin(),
            um.end());

    for(int i=0;i<k;++i){
        cout<<pq.top().first<<" ";
        pq.pop();
    }
}

int main(){
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k =2;
    print_N_mostFrequent(arr, n, k);
    cout<<endl;

    print_N_mostFrequent_2(arr, n, k);
    cout<<endl;

    print_N_mostFrequent_3(arr, n, k);
    return 0;
}
