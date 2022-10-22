#include <iostream>
#include <unordered_map>

using namespace std;


void findPair(int arr[], int n, int sum){
    unordered_map<int, int> mp;
    
    for(int i=0; i < n; ++i){
        if(mp.find(sum - arr[i]) != mp.end()){
            cout<<"["<<arr[i]<<", "<<arr[mp[sum-arr[i]]]<<"]"<<endl;
        }
        else
            mp[arr[i]] = i;
    }
}


int main(){
    int arr[] = { 8, 7, 2, 5, 3, 1 };
    int sum = 10;
 
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findPair(arr, n, sum);

    return 0;
}
