#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


void findSmallestAnd2Smallest(int arr[], int n){
    int smallest, second_smallest;
    smallest = second_smallest = INT_MAX;


    for(int i=0; i < n; ++i){
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest)
            second_smallest = arr[i];
    }


    if(smallest != INT_MAX)
        cout<<"The smallest number is: "<<smallest<<endl;
    if(second_smallest != INT_MAX)
        cout<<"The second smallest number is: "<<second_smallest<<endl;
        

}


int main(){
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSmallestAnd2Smallest(arr, n);

    return 0;
}
