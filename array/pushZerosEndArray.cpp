#include <iostream>

using namespace std;


void pushZerostoEnd(int arr[], int n){
    int cont = 0;
    for(int i=0; i < n; ++i){
        if(arr[i] != 0){
            arr[cont] = arr[i];
            cont++;
        }
    }

    while(cont < n)
        arr[cont++] = 0;
}


int main(){
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    pushZerostoEnd(arr, n);
    for(auto a: arr)
       cout<<a<<" ";

    return 0;
}
