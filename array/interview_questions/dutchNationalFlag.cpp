#include <iostream>

using namespace std;

void dutchNationalFlag(int arr[], int end){
    int pivot = 1;
    int mid = 0, start = 0;
    while(mid <= end){
        if(arr[mid] < pivot){
            swap(arr[start], arr[mid]);
            ++mid, ++start;
            }
        else if (arr[mid] > pivot){
            swap(arr[mid], arr[end]);
            --end;
            }
        else
            ++mid;
    }
}

int main(){
    int arr[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    dutchNationalFlag(arr, n-1);

    for(auto a: arr)
        cout<<a<<" ";

    return 0;
}