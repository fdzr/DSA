#include <bits/stdc++.h>

using namespace std;


void printArray(int arr[], int n){
    cout<<"[";
    for(int i=0;i<n;++i){
        cout<<arr[i];

        if(i < (n - 1))
            cout<<", ";
        else
            cout<<"]"<<endl;
    }
 }


void reverse(int arr[], int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rearrange(int arr[], int start, int end){
    if(start == end)
        return;

    rearrange(arr, start + 1, end);

    if(arr[start] >= 0){
        reverse(arr, start + 1, end);
        reverse(arr, start, end);
    }
}


int main(){
    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int countNegatives = 0;
    
    for(int i=0; i< n; ++i)
        if(arr[i] < 0)
            countNegatives++;
    
    cout<<"array: ";
    printArray(arr, n);
    rearrange(arr, 0, n-1);

    reverse(arr, countNegatives, n-1);

    cout<<"rearranged array: ";
    printArray(arr, n);
    

    return 0;
}
