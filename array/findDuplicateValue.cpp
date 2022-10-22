#include <iostream>
#include <unordered_map>

using namespace std;


int findDuplicate(int arr[], int n){
    unordered_map<int, int> um;
    for(int i = 0; i < n; ++i){
        um[arr[i]] ++;
        if(um[arr[i]] > 1)
            return arr[i];
    }

    return -1;
}


int main(){
    int arr[] = {1, 2, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findDuplicate(arr, n);
    return 0;
}
