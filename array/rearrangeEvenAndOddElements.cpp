#include <iostream>

using namespace std;


void rearrange(int arr[], int n){
    for(int i=1; i<n; ++i){
        if(i % 2 == 0){
            if(arr[i]>=arr[i-1])
                swap(arr[i], arr[i-1]);
        }
        else{
            if(arr[i]<arr[i-1])
                swap(arr[i], arr[i-1]);
        }
    }
}


int main(){
    int n = 5;
    int arr[] = { 1, 3, 2, 2, 5 };
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
