#include <iostream>
#include <climits>

using namespace std;


void find2thLargestNumber(int arr[], int n){
    int first, second;
    first = second = INT_MIN;

    for(int i=0;i<n;++i){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
    
        else if(arr[i] > second && first != arr[i])
            second = arr[i];
    }
    
    if(second != INT_MIN)
        cout<<"The second largest number is "<<second;
    else
        cout<<"There is no such number";

}

int main(){
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    find2thLargestNumber(arr, n);

    return 0;
}
