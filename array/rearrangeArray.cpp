#include <iostream>

using namespace std;


void fixArray(int arr[], int n){
    int i = 0;

    while(i < n){
        if(arr[i] >= 0 && arr[i] != i){
            int tmp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = tmp;
        }
        else
            i++;
    }
}


int main(){
    int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    fixArray(arr, n);

    for(auto a: arr)
        cout<<a<<" ";

    return 0;
}
