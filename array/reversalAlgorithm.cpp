#include <iostream>

using namespace std;

void reverse(int arr[], int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(int arr[], int d, int n){
    /*
     * d position to rotate the array to the left
     * n number of elements in the array
     * */
    reverse(arr, 0, n - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, d - 1);
}



int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    rotate(arr, 3, sizeof(arr) / sizeof(arr[0]) );


    for(int i: arr)
        cout<<i<<" ";

    return 0;
}
