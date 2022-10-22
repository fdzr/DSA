#include <iostream>
#include <climits>

using namespace std;

void findMinimumSubArray(int arr[], int n, int k) {
    int min_sum = 0;
    int end_index = k-1;
    for (int i = 0; i < k; ++i)
        min_sum += arr[i];

    int current_sum = min_sum;

    for (int i = k; i < n; ++i ) {
        current_sum += (arr[i] - arr[i - k]);
        if (current_sum < min_sum) {
            min_sum = current_sum;
            end_index = i;
        }
    }

    cout<<"("<<end_index-k + 1<<","<<end_index<<")";

}


int main() {
    int arr[] = {10, 4, 2, 5, 6, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMinimumSubArray(arr, n, 3);


    return 0;
}