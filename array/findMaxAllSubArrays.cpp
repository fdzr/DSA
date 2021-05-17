#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void findMaxSubArrays(int arr[], int k, int n){
    vector<int> ve;
    for(int i = 0; i < n-k+1; ++i)
        ve.push_back(*max_element(arr + i, arr + i + k));

    for(auto e: ve)
        cout<<e<<" ";
}


int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    findMaxSubArrays(arr, k, n);
    //cout<<*max_element(arr + 3, arr + 5);

    return 0;
}
