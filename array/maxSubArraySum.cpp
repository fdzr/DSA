#include<iostream>
#include<climits>

using namespace std;

int maxSubArraySum(int arr[], int size){
    int max=0;
    int max_current = INT_MIN;

    for(int i=0; i < size; ++i){
        if(arr[i] <= max + arr[i])
            max += arr[i];
        else
            max = arr[i];

        if(max > max_current)
            max_current = max;
    }

    return max_current;
}


int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = maxSubArraySum(arr, n);
    cout<<"Maximum contiguous sum is "<<res;


    return 0;
}
