#include <iostream>
#include <unordered_map>

using namespace std;


void findMaxLengthSubArray(int arr[], int n, int S){
    int target = 0;
    int ending_index = -1;
    int len_subarray = 0;
    unordered_map<int, int> um;

    for(int i = 0; i < n; ++i){
        target += arr[i];

        if(um.find(target) == um.end())
            um[target] = i;
        
        if(um.find(target - S) != um.end() && len_subarray < i - um[target - S]){
            len_subarray = i - um[target - S];
            ending_index = i;
        }
    }
    cout<<ending_index - len_subarray + 1<<" "<<ending_index;
}

int main(){
    int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int S = 8;
    int n = sizeof(arr) / sizeof(arr[0]);
    findMaxLengthSubArray(arr, n, S);

    return 0;
}