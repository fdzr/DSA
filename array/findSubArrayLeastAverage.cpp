#include <iostream>

using namespace std;

void findMinAvgSubarray(int arr[], int k, int n){
    int res_index = 0;
    int curr_sum = 0;

    for(int i=0;i<k;++i)
        curr_sum += arr[i];

    int min_sum = curr_sum;

    for(int i=k;i<n;++i){
        curr_sum += arr[i] - arr[i - k];
        if(curr_sum < min_sum){
            min_sum = curr_sum;
            res_index = i - k + 1;
        }
    }
    cout<<"Subarray between ["<<res_index<<", "<<res_index + k - 1<<"] has\
   minimun average";
}

int main(){
    int arr[] = {3, 7, 90, 20, 10, 50, 40};
    int k =3;
    int n = sizeof(arr) / sizeof(arr[0]);
    findMinAvgSubarray(arr, k, n);
    return 0;
}
